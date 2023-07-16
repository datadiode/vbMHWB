// vbWB.cpp : Implementation of CvbWB

#include "stdafx.h"
#include "VbMHWB.h"
#include "vbWB.h"
#include "ProtocolCF.h"
//#include "UrlHist.h"

////////////////////////////////////////////
//typedefs, macros, functions, and consts
////////////////////////////////////////////

///////////////////////////////////////////////
//APP
typedef PassthroughAPP::CMetaFactory<PassthroughAPP::CComClassFactoryProtocol,
	WBPassthru> MetaFactory;

////////////////////////////////////////////////
//Windows hooks structure, vars and callbacks
typedef struct WBHOOKDATA 
{ 
    int nType;
	HWND hwndTarget;
	BOOL bHookInstalled;
	UINT uiHookMsgID;
    HOOKPROC hkprc;
    HHOOK hhook;
} WBHOOKDATA; 

#define NUMHOOKS 11

static WBHOOKDATA wbhookdata[NUMHOOKS];
static LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam);
static LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
static LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
static LRESULT CALLBACK CallWndProc(int nCode, WPARAM wParam, LPARAM lParam);
static LRESULT CALLBACK CBTProc(int nCode, WPARAM wParam, LPARAM lParam);
static LRESULT CALLBACK GetMsgProc(int nCode, WPARAM wParam, LPARAM lParam);
static LRESULT CALLBACK MessageProc(int nCode, WPARAM wParam, LPARAM lParam);
static LRESULT CALLBACK LowLevelMouseProc(int nCode, WPARAM wParam, LPARAM lParam);
static LRESULT CALLBACK ForegroundIdleProc(int nCode, WPARAM wParam, LPARAM lParam);
static LRESULT CALLBACK CallWndRetProc(int nCode, WPARAM wParam, LPARAM lParam);
static LRESULT CALLBACK SysMsgProc(int nCode, WPARAM wParam, LPARAM lParam);

static int nCode_CBTProc; //(CBTProc)
static int nCode_MessageProc; //(MessageProc)
static int nCode_SysMsgProc; //(SysMsgProc)

#define H_CALLWNDPROC		0 //CallWndProc
#define H_CBT				1 //CBTProc
#define H_GETMESSAGE		2 //GetMsgProc
#define H_KEYBOARD			3 //KeyboardProc
#define H_MOUSE				4 //MouseProc
#define H_MSGFILTER			5 //MessageProc
#define H_KEYBOARD_LL		6 //LowLevelKeyboardProc 
#define H_MOUSE_LL			7 //LowLevelMouseProc
#define H_FOREGROUNDIDLE	8 //ForegroundIdleProc
#define H_CALLWNDPROCRET	9 //CallWndRetProc
#define H_SYSMSGFILTER		10 //SysMsgProc

//Define Hook msgs
//Guids generated using sdk GuidGen util
#define UWM_MOUSE_HOOKPROC_MSG _T("UWM_MOUSE-{A89C6106-B837-4ce9-A1D2-B55B833272D2}")
#define UWM_KEYBOARD_HOOKPROC_MSG _T("UWM_KEYBOARD-{DD6BA45D-0A52-442b-A58D-75273C3C1E0D}")
#define UWM_LOWLEVELKEYBOARD_HOOKPROC_MSG _T("UWM_LOWLEVELKEYBOARD-{636CD093-89D0-46da-98D8-A756B190033A}")
#define UWM_CALLWND_HOOKPROC_MSG _T("UWM_CALLWND-{6CF01631-BF0B-4479-B86A-198C63285B5E}")
#define UWM_CBT_HOOKPROC_MSG _T("UWM_CBT-{AD48A334-EE9C-4ef9-AFE4-0EB2483DE790}")
#define UWM_GETMSG_HOOKPROC_MSG _T("UWM_GETMSG-{2EEFC149-231C-4636-B24F-1788CA63AE0A}")
#define UWM_MESSAGE_HOOKPROC_MSG _T("UWM_MESSAGE-{9508F07B-50F9-4d19-B6C2-99FE5F7E99C1}")
#define UWM_LOWLEVELMOUSE_HOOKPROC_MSG _T("UWM_LOWLEVELMOUSE-{DF69AA88-8F7E-44ac-A1B3-3CED59C77E39}")
#define UWM_FORGROUNDIDLE_HOOKPROC_MSG _T("UWM_FORGROUNDIDLE-{88E3AE4F-103F-4549-B24F-8964C6335706}")
#define UWM_CALLWNDRET_HOOKPROC_MSG _T("UWM_CALLWNDRET-{6C5FD4ED-B340-4563-9F74-908F8E292635}")
#define UWM_SYSMSG_HOOKPROC_MSG _T("UWM_SYSMSG-{13480F7E-5357-4eb3-979C-94CB6BE2B106}")

//////////////////////////////////////////////////////////

//Do not want to import shlobj.h
//Used in WBDropTarget to handle drop
typedef struct _WBNETRESOURCE { 
	DWORD dwScope;
	DWORD dwType;
	DWORD dwDisplayType;
	DWORD dwUsage;
	LPTSTR lpLocalName;
	LPTSTR lpRemoteName; //contains a null-terminated string identifying the network resource
	LPTSTR lpComment;
	LPTSTR lpProvider;
} WBNETRESOURCE;

// format of CF_NETRESOURCE
typedef struct _WBNRESARRAY {
    UINT cItems;
    WBNETRESOURCE nr[1];
} WBNRESARRAY;

typedef struct _WBFILEDESCRIPTORA {
    DWORD dwFlags;

    CLSID clsid;
    SIZEL sizel;
    POINTL pointl;

    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    TCHAR   cFileName[ MAX_PATH ];
} WBFILEDESCRIPTORA;

// format of CF_FILEGROUPDESCRIPTOR
//
typedef struct _WBFILEGROUPDESCRIPTORA {
     UINT cItems;
     WBFILEDESCRIPTORA fgd[1];
} WBFILEGROUPDESCRIPTORA;

//Error msg send to client from all over the place
//Replaced with m_StrErr_WBNOTFOUND
//const TCHAR WB_NOT_FOUND[] = _T("Unable to find browser in collection."); 

const LPCTSTR vbCrLf				= _T("\r\n");
const LPCTSTR IE_SERVER_CLASSNAME	= _T("Internet Explorer_Server");
const LPCTSTR STR_CL_HTML_FORMAT	= _T("HTML Format");
const LPCTSTR STR_CL_RT_FORMAT		= _T("Rich Text Format");
const LPCTSTR STR_CL_FDG_FORMAT		= _T("FileGroupDescriptor");
const LPCTSTR STR_CL_FC_FORMAT		= _T("FileContents");
const LPCTSTR STR_CL_URL_FORMAT		= _T("UniformResourceLocator");
const LPCTSTR STR_CL_NR_FORMAT		= _T("Net Resource");
const LPOLESTR oBindCtxBSCBObjectParam = L"_BSCB_Holder_";

//IBindStatusCallbackHolder is derived from IBindStatusCallback and has no 
//methods above and beyond IBindStatusCallback
//79EAC9CC-BAF9-11CE-8C82-00AA004BA90B
//DEFINE_GUID(IID_IBindStatusCallbackHolder,
//	0x79EAC9CC ,
//	0xBAF9, 0x11CE,
//	0x8c, 0x82,
//	0x00, 0xaa, 0x00, 0x4b, 0xa9, 0x0b);

//D2BC4C84-3F72-4a52-A604-7BCBF3982CBB
DEFINE_GUID(IID_INewWindowManager,
	0xD2BC4C84,
	0x3F72, 0x4a52,
	0xA6, 0x04,
	0x7B, 0xCB, 0xF3, 0x98, 0x2C, 0xBB);

//988934A4-064B-11D3-BB80-00104B35E7F9
DEFINE_GUID(IID_IDownloadManager,
	0x988934a4,
	0x064b, 0x11d3,
	0xbb, 0x80,
	0x00, 0x10, 0x4b, 0x35, 0xe7, 0xf9);
#define SID_SDownloadManager IID_IDownloadManager

//3050f5fc-98b5-11cf-bb82-00aa00bdce0b
DEFINE_GUID(IID_IHTMLOMWindowServices,
	0x3050f5fc,
	0x98b5, 0x11cf,
	0xbb, 0x82,
	0x00, 0xaa, 0x00, 0xbd, 0xce, 0x0b);
#define SID_SHTMLOMWindowServices  IID_IHTMLOMWindowServices

BOOL VARIANTBOOLTOBOOL(VARIANT_BOOL x) { return (x == VARIANT_TRUE) ? TRUE : FALSE; }
bool VARIANTBOOLTObool(VARIANT_BOOL x) { return (x == VARIANT_TRUE) ? true : false; }

//To invoke default Find dialog as per KB 815716
//{ED016940-BD5B-11CF-BA4E-00C04FD70816}
static CLSID const WB_CGI_IWebBrowser          = { 0xED016940 , 0xBD5B, 0x11CF, {
	0xBA,0x4E,0x00,0xC0,0x4F,0xD7,0x08,0x16 } };

//For displaying Certificate Dialogs for valid HTTPS sites
#define SHDVID_SSLSTATUS 33

//Same as DISPID_NEWWINDOW3, renamed so as not to cause conflicts
#define DISPID_NEWWINDOW_WB3           273

#define NO_FILE ((DWORD)-1)
#define DW_ZERO ((DWORD)0)
#define Alert(x) { ::MessageBox(GetDesktopWindow(), x, x, MB_OK);} // return E_NOTIMPL; }
//Simple assert which works compiled or not
//Silent exit - Uncomment for debugging
#define Assert(x) if(!x) {return E_FAIL;} //::MessageBox(NULL, _T("ERROR!"), _T("Error"),MB_OK | MB_ICONSTOP); return E_FAIL;}
//#define FreeBSTR(x) if(x) {::SysFreeString(x);}

//To help with debugging, please don't forget to change the path
//and file name, file will be created if it does not exists, but path will not
int vbLog(LPCTSTR szData,LPCTSTR szHeader, LPCTSTR szFileName = _T("C:\\Mike\\HsbTlb\\DL\\vbMHWB\\logs\\log.txt"));
int vbLogBSTR(BSTR szData,LPCTSTR szHeader, LPCTSTR szFileName = _T("C:\\Mike\\HsbTlb\\DL\\vbMHWB\\logs\\log.txt"));
//To clear BSTR before setting it's value
void ClearBSTRPtr(BSTR& bstrText);
//Error is a method of CComCoClass
//return Error(_bstr_t(m_sErrorDescription).copy(), IID_IObj, hr);

//To save image of WB as Bitmap
//Taken from MSDN examples
PBITMAPINFO CreateBitmapInfoStruct(HWND hwnd, HBITMAP hBmp);
BOOL CreateBMPFile(HWND hwnd, LPTSTR pszFile, PBITMAPINFO pbi, HBITMAP hBMP, HDC hDC);

//Extras
HBITMAP CaptureDesktop();
HBITMAP CaptureForegroundWindow(BOOL bClientAreaOnly = FALSE);
HBITMAP CaptureWindow(HWND hwnd, BOOL bClientAreaOnly = FALSE);

//Stream helpers
HRESULT StreamResetPointer (LPSTREAM lpStream);
//lpulSize includes terminating NULL
HRESULT StreamStringSize(LPSTREAM lpStream, ULONG* lpulSize);
HRESULT StreamStringCopy (LPSTREAM lpStream, LPCTSTR lpString);
HRESULT StreamStringCat (LPSTREAM lpStream, LPCTSTR lpString);
HRESULT StreamStringRead (LPSTREAM lpStream, LPTSTR lpszReceiver, ULONG* lpulSizeReceiver);
HRESULT StreamStringRead2 (LPSTREAM lpStream, LPTSTR lpszReceiver, ULONG ulSizeReceiver);

LPCTSTR DecodeHtml(LPCTSTR s_In);

HRESULT Delete_DesktopRunMRU(void);
HRESULT Delete_DesktopRecentDocsHistory(void);

HRESULT Delete_IEAddressBarTypedURLs(void);
HRESULT Delete_IEHistory(BOOL bDeleteHistory = TRUE, BOOL bDeleteHistoryIndex = FALSE);
HRESULT Delete_IECache(BOOL bDeleteCache = TRUE, BOOL bDeleteCacheIndex = FALSE);
HRESULT Delete_IECookies(BOOL bDeleteCookies = TRUE, BOOL bDeleteCookiesIndex = FALSE);
/////////////////////////////////////////////////////////////////////////////
// CvbWB
/////////////////////////////////////////////////////////////////////////////

STDMETHODIMP CvbWB::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IvbWB,
	};
	for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i], riid))
			return S_OK;
	}
	return S_FALSE;
}

void CvbWB::InitInternalHookStructures()
{
	nCode_CBTProc = 0;
	nCode_MessageProc = 0;
	nCode_SysMsgProc = 0;
	wbhookdata[H_CALLWNDPROC].bHookInstalled = FALSE;
	wbhookdata[H_CALLWNDPROC].hhook = NULL;
	wbhookdata[H_CALLWNDPROC].hkprc = (HOOKPROC)CallWndProc;
	wbhookdata[H_CALLWNDPROC].hwndTarget = NULL;
	wbhookdata[H_CALLWNDPROC].nType = WH_CALLWNDPROC;
	wbhookdata[H_CALLWNDPROC].uiHookMsgID = ::RegisterWindowMessage(UWM_MOUSE_HOOKPROC_MSG);

	wbhookdata[H_CBT].bHookInstalled = FALSE;
	wbhookdata[H_CBT].hhook = NULL;
	wbhookdata[H_CBT].hkprc = (HOOKPROC)CBTProc;
	wbhookdata[H_CBT].hwndTarget = NULL;
	wbhookdata[H_CBT].nType = WH_CBT;
	wbhookdata[H_CBT].uiHookMsgID = ::RegisterWindowMessage(UWM_CBT_HOOKPROC_MSG);

	wbhookdata[H_GETMESSAGE].bHookInstalled = FALSE;
	wbhookdata[H_GETMESSAGE].hhook = NULL;
	wbhookdata[H_GETMESSAGE].hkprc = (HOOKPROC)GetMsgProc;
	wbhookdata[H_GETMESSAGE].hwndTarget = NULL;
	wbhookdata[H_GETMESSAGE].nType = WH_GETMESSAGE;
	wbhookdata[H_GETMESSAGE].uiHookMsgID = ::RegisterWindowMessage(UWM_GETMSG_HOOKPROC_MSG);

	wbhookdata[H_KEYBOARD].bHookInstalled = FALSE;
	wbhookdata[H_KEYBOARD].hhook = NULL;
	wbhookdata[H_KEYBOARD].hkprc = (HOOKPROC)KeyboardProc;
	wbhookdata[H_KEYBOARD].hwndTarget = NULL;
	wbhookdata[H_KEYBOARD].nType = WH_KEYBOARD;
	wbhookdata[H_KEYBOARD].uiHookMsgID = ::RegisterWindowMessage(UWM_KEYBOARD_HOOKPROC_MSG);

	wbhookdata[H_MOUSE].bHookInstalled = FALSE;
	wbhookdata[H_MOUSE].hhook = NULL;
	wbhookdata[H_MOUSE].hkprc = (HOOKPROC)MouseProc;
	wbhookdata[H_MOUSE].hwndTarget = NULL;
	wbhookdata[H_MOUSE].nType = WH_MOUSE;
	wbhookdata[H_MOUSE].uiHookMsgID = ::RegisterWindowMessage(UWM_MOUSE_HOOKPROC_MSG);

	wbhookdata[H_MSGFILTER].bHookInstalled = FALSE;
	wbhookdata[H_MSGFILTER].hhook = NULL;
	wbhookdata[H_MSGFILTER].hkprc = (HOOKPROC)MessageProc;
	wbhookdata[H_MSGFILTER].hwndTarget = NULL;
	wbhookdata[H_MSGFILTER].nType = WH_MSGFILTER;
	wbhookdata[H_MSGFILTER].uiHookMsgID = ::RegisterWindowMessage(UWM_MESSAGE_HOOKPROC_MSG);

	wbhookdata[H_KEYBOARD_LL].bHookInstalled = FALSE;
	wbhookdata[H_KEYBOARD_LL].hhook = NULL;
	wbhookdata[H_KEYBOARD_LL].hkprc = (HOOKPROC)LowLevelKeyboardProc;
	wbhookdata[H_KEYBOARD_LL].hwndTarget = NULL;
	wbhookdata[H_KEYBOARD_LL].nType = WH_KEYBOARD_LL;
	wbhookdata[H_KEYBOARD_LL].uiHookMsgID = ::RegisterWindowMessage(UWM_LOWLEVELKEYBOARD_HOOKPROC_MSG);

	wbhookdata[H_MOUSE_LL].bHookInstalled = FALSE;
	wbhookdata[H_MOUSE_LL].hhook = NULL;
	wbhookdata[H_MOUSE_LL].hkprc = (HOOKPROC)LowLevelMouseProc;
	wbhookdata[H_MOUSE_LL].hwndTarget = NULL;
	wbhookdata[H_MOUSE_LL].nType = WH_MOUSE_LL;
	wbhookdata[H_MOUSE_LL].uiHookMsgID = ::RegisterWindowMessage(UWM_LOWLEVELMOUSE_HOOKPROC_MSG);

	wbhookdata[H_FOREGROUNDIDLE].bHookInstalled = FALSE;
	wbhookdata[H_FOREGROUNDIDLE].hhook = NULL;
	wbhookdata[H_FOREGROUNDIDLE].hkprc = (HOOKPROC)ForegroundIdleProc;
	wbhookdata[H_FOREGROUNDIDLE].hwndTarget = NULL;
	wbhookdata[H_FOREGROUNDIDLE].nType = WH_FOREGROUNDIDLE;
	wbhookdata[H_FOREGROUNDIDLE].uiHookMsgID = ::RegisterWindowMessage(UWM_FORGROUNDIDLE_HOOKPROC_MSG);

	wbhookdata[H_CALLWNDPROCRET].bHookInstalled = FALSE;
	wbhookdata[H_CALLWNDPROCRET].hhook = NULL;
	wbhookdata[H_CALLWNDPROCRET].hkprc = (HOOKPROC)CallWndRetProc;
	wbhookdata[H_CALLWNDPROCRET].hwndTarget = NULL;
	wbhookdata[H_CALLWNDPROCRET].nType = WH_CALLWNDPROCRET;
	wbhookdata[H_CALLWNDPROCRET].uiHookMsgID = ::RegisterWindowMessage(UWM_CALLWNDRET_HOOKPROC_MSG);

	wbhookdata[H_SYSMSGFILTER].bHookInstalled = FALSE;
	wbhookdata[H_SYSMSGFILTER].hhook = NULL;
	wbhookdata[H_SYSMSGFILTER].hkprc = (HOOKPROC)SysMsgProc;
	wbhookdata[H_SYSMSGFILTER].hwndTarget = NULL;
	wbhookdata[H_SYSMSGFILTER].nType = WH_SYSMSGFILTER;
	wbhookdata[H_SYSMSGFILTER].uiHookMsgID = ::RegisterWindowMessage(UWM_SYSMSG_HOOKPROC_MSG);
}

////////////////////////////////////
//Construstor and Destructor
////////////////////////////////////

CvbWB::CvbWB()
{
	m_bWindowOnly = TRUE;

	m_wbuid					= 0;
	m_dluid					= 0;

	//Allow text selection + No 3D border + Flat scrollbars DOCHOSTUIFLAG_NO3DOUTERBORDER | 
	m_HostUiFlags			= DOCHOSTUIFLAG_NO3DBORDER | DOCHOSTUIFLAG_FLAT_SCROLLBAR; //(DWORD)0;
	m_HostDbClickAction		= DOCHOSTUIDBLCLK_DEFAULT; //(DWORD)0;
	m_HostDlFlag			= DLCTL_DLIMAGES | DLCTL_VIDEOS | DLCTL_BGSOUNDS; //(DWORD)0;
	m_dwCtxMnuAction		= 0;

	m_StartupURL			= L""; //L"about:blank";
	m_bUseIEDownloader		= VARIANT_FALSE; //Always use our own download ifaces
	m_bSilent				= VARIANT_FALSE; //Display all dialogs + msgs
	m_bOffLine				= VARIANT_FALSE; //Offline mode
	//Default. Object is not registered as a drop target.
	//We handle dragdrop internally via WBDropTarget
	m_bRegisterAsDropTarget = VARIANT_FALSE;
	m_bUseInternalDragDrop = VARIANT_TRUE;
	//Default. Object is not registered as a top-level browser.
	m_bRegisterAsBrowser	= VARIANT_FALSE;  //Able to resolve urls
	m_bSourceOnDocComplete  = VARIANT_FALSE;  //Just fire DocumentComplete
	
	strScheme				= L"";
	m_nScheme				= 0; //INTERNET_SCHEME_DEFAULT
	strHostName				= L"";
	strUserName				= L"";
	strPassword				= L"";
	strUrlPath				= L"";
	strExtraInfo			= L"";
	strFullURL				= L"";
	strFileName				= L"";
	strFileExtension		= L"";
	Port					= 0;
	m_TextZoomVal			= -1; //Will be set first call to PageTextSize property
	//This value is set during calls to SetFocusW and PlaceWBOnTop
	//and is used in OnSetFocus method to pass focus to any WB with Zorder 0
	m_wbcurid				= 0;

	//Supported drag drop formats
	m_CF_HTML = RegisterClipboardFormat(STR_CL_HTML_FORMAT);
	m_CF_RTF = RegisterClipboardFormat(STR_CL_RT_FORMAT);
	//The Shell Clipboard formats, with the exception of CF_HDROP, are not predefined.
	//Each format you want to use must be registered by calling RegisterClipboardFormat.
	m_CF_FILEGROUPDESCRIPTORA = RegisterClipboardFormat(STR_CL_FDG_FORMAT);
	m_CF_FILECONTENTS = RegisterClipboardFormat(STR_CL_FC_FORMAT);
	m_CF_URL = RegisterClipboardFormat(STR_CL_URL_FORMAT);	
	m_CF_NETRESOURCE = RegisterClipboardFormat(STR_CL_NR_FORMAT);

	m_StrErr_WBNOTFOUND = (UINT)IDS_WB_NOT_FOUND;

	InitInternalHookStructures();

	//Add this instance to our global ptrs
	LPVOID thisPtr = reinterpret_cast<LPVOID>(this);
	//Just in case
	if(gCtrlInstances.Find(thisPtr) == -1)
		gCtrlInstances.Add(thisPtr);
}

CvbWB::~CvbWB()
{
	//Remove our instance
	//Otherwise, we will crash
	//Attempting to access a deleted object via an invalid ptr
	if(gCtrlInstances.GetSize() > 0)
	{
		LPVOID thisPtr = reinterpret_cast<LPVOID>(this);
		int i = gCtrlInstances.Find(thisPtr);
		if( i > -1)
		{
			gCtrlInstances[i] = NULL;
			gCtrlInstances.RemoveAt(i);
		}
	}

	//Unhook?
	if(wbhookdata[H_CALLWNDPROC].hhook)
		UnhookWindowsHookEx(wbhookdata[H_CALLWNDPROC].hhook);
	if(wbhookdata[H_CBT].hhook)
		UnhookWindowsHookEx(wbhookdata[H_CBT].hhook);
	if(wbhookdata[H_GETMESSAGE].hhook)
		UnhookWindowsHookEx(wbhookdata[H_GETMESSAGE].hhook);
	if(wbhookdata[H_KEYBOARD].hhook)
		UnhookWindowsHookEx(wbhookdata[H_KEYBOARD].hhook);
	if(wbhookdata[H_MOUSE].hhook)
		UnhookWindowsHookEx(wbhookdata[H_MOUSE].hhook);
	if(wbhookdata[H_MSGFILTER].hhook)
		UnhookWindowsHookEx(wbhookdata[H_MSGFILTER].hhook);
	if(wbhookdata[H_KEYBOARD_LL].hhook)
		UnhookWindowsHookEx(wbhookdata[H_KEYBOARD_LL].hhook);
	if(wbhookdata[H_MOUSE_LL].hhook)
		UnhookWindowsHookEx(wbhookdata[H_MOUSE_LL].hhook);
	if(wbhookdata[H_FOREGROUNDIDLE].hhook)
		UnhookWindowsHookEx(wbhookdata[H_FOREGROUNDIDLE].hhook);
	if(wbhookdata[H_CALLWNDPROCRET].hhook)
		UnhookWindowsHookEx(wbhookdata[H_CALLWNDPROCRET].hhook);
	if(wbhookdata[H_SYSMSGFILTER].hhook)
		UnhookWindowsHookEx(wbhookdata[H_SYSMSGFILTER].hhook);

	nCode_CBTProc = 0;
	nCode_MessageProc = 0;
	nCode_SysMsgProc = 0;

	m_wbcurid = 0;
	/* Clean up */
	int iSize = m_arrWB.GetSize();
	if(iSize > 0)
	{
		for(int i = 0; i < iSize; i++)
		{
			if ((m_arrWB[i]) && (m_arrWB[i]->pWebBrowser) )
			{
				//Stop browser
				m_arrWB[i]->pWebBrowser->Stop();
				//Release interfaces
				HRESULT hr = m_arrWB[i]->StopWB();

				//Delete object
				if ((SUCCEEDED(hr)) && (m_arrWB[i]->m_dwRefCount == 1) )
					delete m_arrWB[i];
//				else
//					m_arrWB[i]->Release();
//				else
//				{
//					TCHAR printbuf[80];
//					wsprintf(printbuf,_T("Reference count should be one. Current ref count is %d. Most likely will cause a GPF."),(long)m_arrWB[i]->m_dwRefCount);
//					::MessageBox(GetDesktopWindow(),printbuf,_T("Ref Count"),MB_OK);
//					//This will definitely cause a GPF
//					//delete m_arrWB[i];
//				}
				//Set to NULL
				m_arrWB[i] = NULL;
			}
		}
		m_arrWB.RemoveAll();
	}

	iSize = m_AutoCompleters.GetSize();
	if(iSize > 0)
	{
		for(int i = 0; i < iSize ; i++)
		{
			if(m_AutoCompleters[i])
				m_AutoCompleters[i]->Unbind();
			m_AutoCompleters[i] = NULL;
		}
		m_AutoCompleters.RemoveAll();
	}

}

//Called from OnStopBinding of WBBSCBFileDL class
BOOL CvbWB::RemoveBSCBFromDLArr(short uID)
{
	int iSize = m_arrDL.GetSize();
	if(iSize > 0)
	{
		for(int i = 0; i < iSize ; i++)
		{
			if( (m_arrDL[i]) && (m_arrDL[i]->m_Uid == uID) )
			{
				//vbLog(_T("RemoveBSCBFromDLArr."),_T("WBBSCBFileDL::~WBBSCBFileDL"));
				m_arrDL[i] = NULL;
				m_arrDL.RemoveAt(i);
				return TRUE;
			}
		}
	}
	return FALSE;
}

bool CvbWB::InIDE()
{
	BOOL m_bUserMode = TRUE;
	HRESULT hRet = GetAmbientUserMode(m_bUserMode);
	if (FAILED(hRet) || m_bUserMode) //Run mode.
		return false;
	else
		return true; //IDE - Design mode
}

HRESULT CvbWB::OnDraw(ATL_DRAWINFO& di)
{
	//Only display info if in design mode else just a plain window with hwnd + ,...
	RECT& rc = *(RECT*)di.prcBounds;
	Rectangle(di.hdcDraw, rc.left, rc.top, rc.right, rc.bottom);
	if (InIDE() == true)
	{
		//SetTextAlign(di.hdcDraw, TA_CENTER|TA_BASELINE);
		SetTextAlign(di.hdcDraw, TA_LEFT|TA_BASELINE);

		//Simple buffer
		CTmpBuffer buff(100);
		int x = 5;
		int y = 15;
		
		buff = (UINT)IDS_PROJNAME;
		buff.AppendResStr((UINT)IDS_CUR_VERSION);
		buff.AppendResStr((UINT)IDS_CTL_DESIGNMODE);
		MoveToEx(di.hdcDraw, x, y, (LPPOINT) NULL);
		TextOut(di.hdcDraw, x, y, buff, buff.GetBufferTextLen());

		y += 20;
		buff = (UINT)IDS_AUTHORNAME;
		MoveToEx(di.hdcDraw, x, y, (LPPOINT) NULL);
		TextOut(di.hdcDraw, x, y, buff, buff.GetBufferTextLen());

		y += 20;
		buff = (UINT)IDS_AUTHORCONTACTINFO;
		MoveToEx(di.hdcDraw, x, y, (LPPOINT) NULL);
		TextOut(di.hdcDraw, x, y, buff, buff.GetBufferTextLen());

		y += 20;
		buff = (UINT)IDS_HOMEPAGE;
		MoveToEx(di.hdcDraw, x, y, (LPPOINT) NULL);
		TextOut(di.hdcDraw, x, y, buff, buff.GetBufferTextLen());

		y += 20;
		buff = (UINT)IDS_HWND;
		buff.Appendlong((long)m_hWnd);
		MoveToEx(di.hdcDraw, x, y, (LPPOINT) NULL);
		TextOut(di.hdcDraw, x, y, buff, buff.GetBufferTextLen());
		
		y += 20;
		buff = (UINT)IDS_THREADID;
		buff.Appendlong((long)GetCurrentThreadId());
		MoveToEx(di.hdcDraw, x, y, (LPPOINT) NULL);
		TextOut(di.hdcDraw, x, y, buff, buff.GetBufferTextLen());
		
		y += 20;
		buff = (UINT)IDS_INST_HANDLE;
		buff.Appendlong((long)_Module.GetModuleInstance());
		MoveToEx(di.hdcDraw, x, y, (LPPOINT) NULL);
		TextOut(di.hdcDraw, x, y, buff, buff.GetBufferTextLen());
//
		y += 20;
		CTmpBuffer buff1(MAX_PATH);
		buff = (UINT)IDS_MODULE_PATH;
		int len = GetModuleFileName(GetModuleHandle(NULL), &buff1 , MAX_PATH);
		if(len > 0)
		{
			buff += buff1;
		}
		else
			buff += _T(" ");
		MoveToEx(di.hdcDraw, x, y, (LPPOINT) NULL);
		TextOut(di.hdcDraw, x, y, buff, buff.GetBufferTextLen());
	}

	return S_OK;
}

//LRESULT CvbWB::OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled)
//{
//	if (InIDE() == false) //App running then create a new browser
//	{
//		short itmpid;
//		AddBrowser(&itmpid);
//	}
//	//Set our global pointer for firing events
//	return 0;
//}

//Added for MFC to allow this control to process TranslateAccelerator
BOOL CvbWB::PreTranslateMessage(MSG* pMsg)
{
	return ProcessWBAccelKeys(pMsg);
}

STDMETHODIMP CvbWB::TranslateAccelerator(MSG *pMsg)
{
	return ProcessWBAccelKeys(pMsg);
}

LRESULT CvbWB::OnSize(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled)
{
	ResizeWBs();
	return 0;
}

LRESULT CvbWB::OnEraseBkgnd(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	// To prevent flicker do not erase the background
	return TRUE; //0;
}

LRESULT CvbWB::OnSetFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	//Call default implementation
	LRESULT lRes = CComControl<CvbWB>::OnSetFocus(uMsg, wParam, lParam, bHandled);
	//Any WB to SetFocus?
	int i = FindWB(m_wbcurid);
	if ( i > -1 )
	{
		m_arrWB[i]->SetFocusDoc();
	}
	return lRes;
}

BOOL CvbWB::FindWBHost(HWND hIEServer, IWB **ppHost)
{
	BOOL bret = FALSE;
	if(ppHost == NULL)
		return E_INVALIDARG;
	int iSize = m_arrWB.GetSize();
	if(iSize == 0)
		return bret;

	for(int i = 0; i < iSize ; i++)
	{
		if(m_arrWB[i]->GetIEServerHwnd() == hIEServer)
		{
			bret = TRUE;
			*ppHost = m_arrWB[i]; //->m_thisID;
			break;
		}
	}
	return bret;
}

int CvbWB::FindWB(short nID)
{
	int iSize = m_arrWB.GetSize();
	if( (nID < 1) || (iSize == 0) )
		return -1;
	for(int i = 0; i < iSize ; i++)
	{
		if(m_arrWB[i]->m_thisID == nID)
			return i;
	}
	return -1;
}

void  CvbWB::SetGlobalFlags(WB_FLAGS lCase, VARIANT_BOOL newVal)
{
	//Loop through all browsers and set their flags
	for(int i = 0; i < m_arrWB.GetSize() ; i++)
    {
		switch (lCase)
		{
			case WB_FLAGS_Silen:
				{
					if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
					{
						m_arrWB[i]->pWebBrowser->put_Silent(newVal);
					}
				}
				break;
			case WB_FLAGS_Offline:
				{
					if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
					{
						m_arrWB[i]->pWebBrowser->put_Offline(newVal);
					}
				}
				break;
			case WB_FLAGS_UseIEDefaultDownloader:
				{
					if (m_arrWB[i])
					{
						m_arrWB[i]->m_useieforfiledl = VARIANTBOOLTObool(newVal); //== VARIANT_TRUE) ? true : false;
					}
				}
				break;
			case WB_FLAGS_RegisterAsBrowser:
				{
					if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
					{
						m_arrWB[i]->pWebBrowser->put_RegisterAsBrowser(newVal);
					}
				}
				break;
			case WB_FLAGS_RegisterAsDropTraget_IE:
				{
					if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
					{
						m_arrWB[i]->pWebBrowser->put_RegisterAsDropTarget(newVal);
					}
				}
				break;
			case WB_FLAGS_RegisterAsDropTraget_Internal:
				{
					if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
					{
						//Using our own IdropTarget implementation
						m_arrWB[i]->m_bAllowDragDrop = VARIANTBOOLTObool(newVal);
					}
				}
				break;
			case WB_FLAGS_SendSourceOnDocComplete:
				{
					if (m_arrWB[i] && m_arrWB[i]->m_pWBEventDispatch)
					{
						m_arrWB[i]->m_pWBEventDispatch->m_bSendSourceOnDocComplete = VARIANTBOOLTObool(newVal);
					}
				}
				break;
		} //End switch
	} //End for
}

void  CvbWB::SetGlobalFlags(WB_FLAGS lCase, DWORD newVal)
{
	//Loop through all browsers and set their flags
	for(int i = 0; i < m_arrWB.GetSize() ; i++)
    {
		switch (lCase)
		{
			case WB_FLAGS_CtxMnu:
				if(m_arrWB[i] && m_arrWB[i]->m_pWBDocHostUIHandler)
					m_arrWB[i]->m_pWBDocHostUIHandler->m_ContextMenuAction = (long)newVal;
				break;
			case WB_FLAGS_DL:
				if(m_arrWB[i] && m_arrWB[i]->pWebBrowser && m_arrWB[i]->m_pWBEventDispatch)
				{
					m_arrWB[i]->m_pWBEventDispatch->m_dwDLControl = newVal;
					//Signal change of DL property
					//so MSHTML call our Invoke method in WBEventDispatch
					//Otherwise refreshing the page will have no effect
					//MSHTML does not know of new flags set by us
					CComPtr<IOleControl> pOleObj;
					HRESULT hr = m_arrWB[i]->pWebBrowser->QueryInterface(IID_IOleControl, (void**) &pOleObj);
					if(SUCCEEDED(hr) && pOleObj) 
						pOleObj->OnAmbientPropertyChange(DISPID_AMBIENT_DLCONTROL);
				}
				break;
			case WB_FLAGS_UI:
				if(m_arrWB[i] && m_arrWB[i]->m_pWBDocHostUIHandler)
					m_arrWB[i]->m_pWBDocHostUIHandler->m_dwDocHostUIFlags = newVal;
				break;
			case WB_FLAGS_DblClk:
				if(m_arrWB[i] && m_arrWB[i]->m_pWBDocHostUIHandler)
					m_arrWB[i]->m_pWBDocHostUIHandler->m_dwDocHostUIDblClk = newVal;
				break;
			case WB_FLAGS_PageZoom:
				if(m_arrWB[i] && m_arrWB[i]->pWebBrowser)
				{
					VARIANT vaZoomFactor;					// input arguments
					VariantInit(&vaZoomFactor);
					V_VT(&vaZoomFactor) = VT_I4;
					V_I4(&vaZoomFactor) = (long)newVal;
					m_arrWB[i]->pWebBrowser->ExecWB(OLECMDID_ZOOM, 
									OLECMDEXECOPT_DONTPROMPTUSER, &vaZoomFactor, NULL);
					VariantClear(&vaZoomFactor);
				}
				break;
		}
	}

}

STDMETHODIMP CvbWB::get_Count(short *pVal)
{
	*pVal = (short)m_arrWB.GetSize();
	return S_OK;
}

STDMETHODIMP CvbWB::RemoveBrowser(short wbUIDToRemove)
{
	HRESULT hret = S_OK;

	if (wbUIDToRemove > 0)
	{
		//Get the IWB and release
		int i = FindWB(wbUIDToRemove);
		if ( i > -1 )
		{
			if(m_wbcurid == wbUIDToRemove)
				m_wbcurid = 0;
			if ((m_arrWB[i]) && (m_arrWB[i]->pWebBrowser) )
			{
				//Stop browser
				m_arrWB[i]->pWebBrowser->Stop();
				//Disconnect from object
				HRESULT hr = m_arrWB[i]->StopWB();

				if (FAILED(hr))
				{
					m_StrErr_Tmp = (UINT)IDS_UNABLETO_REMOVEWB;
					return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION);
				}

				//Check ref count
				//If bigger than one then it means a part of MSHTML is still
				//holding a ref to one of our class, deleting it, most likely
				//will cause a GPF
				if (m_arrWB[i]->m_dwRefCount == 1)
					delete m_arrWB[i];
				else
					m_arrWB[i]->Release(); //Hopefully, it will be deleted if released

//May cause VB to crash at times
//				else
//				{
//					m_arrWB[i] = NULL;
//					m_arrWB.RemoveAt(i);
//					TCHAR printbuf[80];
//					wsprintf(printbuf,_T("Reference count should be one. Current ref count is %d."),m_arrWB[i]->m_dwRefCount);
//					::MessageBox(GetDesktopWindow(),printbuf,_T("Ref Count"),MB_OK);
//					return AtlReportError(CLSID_vbWB, printbuf,IID_IvbWB,DISP_E_EXCEPTION);
//				}				
				m_arrWB[i] = NULL;
				m_arrWB.RemoveAt(i);
			}
			else
			{
				m_StrErr_Tmp = (UINT)IDS_WBHOST_NOT_FOUND;
				return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION);
			}
		}
		else
		{
			return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND ,IID_IvbWB,DISP_E_EXCEPTION);
		}
	}
	return hret;
}

STDMETHODIMP CvbWB::Refresh(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 )
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser) 
			m_arrWB[i]->pWebBrowser->Refresh();
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND ,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::Stop(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 )
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
			m_arrWB[i]->pWebBrowser->Stop();
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);

	return S_OK;
}

STDMETHODIMP CvbWB::GoBack(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser) 
			m_arrWB[i]->pWebBrowser->GoBack();
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);

	return S_OK;
}

STDMETHODIMP CvbWB::GoForward(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser) 
			m_arrWB[i]->pWebBrowser->GoForward();
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);

	return S_OK;
}

STDMETHODIMP CvbWB::GoHome(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser) 
			m_arrWB[i]->pWebBrowser->GoHome();
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::NavigateSimple(short wbUID, BSTR URL)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser) 
		{
			m_arrWB[i]->pWebBrowser->Navigate(URL,NULL,NULL,NULL,NULL);
		}
		else
			return AtlReportError(CLSID_vbWB, "Unable to find host or browser object.",IID_IvbWB,DISP_E_EXCEPTION);
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::get_WebBrowser(short wbUID, LPDISPATCH *pVal)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			//*pVal = m_arrWB[i]->pWebBrowser;
			m_arrWB[i]->pWebBrowser->QueryInterface(IID_IDispatch, 
				reinterpret_cast<void **>(pVal));
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::get_LocationURL(short wbUID, BSTR *pURL)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			ClearBSTRPtr(*pURL);
			m_arrWB[i]->pWebBrowser->get_LocationURL(pURL);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::get_Offline(short wbUID, VARIANT_BOOL *pVal)
{
	//Just return global flag
	if(wbUID <= 0)
	{
		*pVal = m_bOffLine;
		return S_OK;
	}
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			//VARIANT_BOOL bresult; &bresult
			m_arrWB[i]->pWebBrowser->get_Offline(pVal);
			//*pVal = bresult;
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::put_Offline(short wbUID, VARIANT_BOOL newVal)
{
	if(wbUID <= 0)
	{
		m_bOffLine = newVal;
		SetGlobalFlags(WB_FLAGS_Offline,m_bOffLine);
		return S_OK;
	}
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			m_arrWB[i]->pWebBrowser->put_Offline(newVal);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::ReadyState(short wbUID, READYSTATE *plReadyState)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			//READYSTATE plstate;
			m_arrWB[i]->pWebBrowser->get_ReadyState(plReadyState);
			//*plReadyState = plstate;
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::GoSearch(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			m_arrWB[i]->pWebBrowser->GoSearch();
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::Refresh2(short wbUID, VARIANT *level)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser) 
			m_arrWB[i]->pWebBrowser->Refresh2(level);
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::get_Busy(short wbUID, VARIANT_BOOL *pVal)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			m_arrWB[i]->pWebBrowser->get_Busy(pVal);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::get_RegisterAsBrowser(short wbUID, VARIANT_BOOL *pVal)
{
	//Just return global flag
	if(wbUID <= 0)
	{
		*pVal = m_bRegisterAsBrowser;
		return S_OK;
	}
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			m_arrWB[i]->pWebBrowser->get_RegisterAsBrowser(pVal);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::put_RegisterAsBrowser(short wbUID, VARIANT_BOOL newVal)
{
	if(wbUID <= 0)
	{
		m_bRegisterAsBrowser = newVal;
		SetGlobalFlags(WB_FLAGS_RegisterAsBrowser,m_bRegisterAsBrowser);
		return S_OK;
	}
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			m_arrWB[i]->pWebBrowser->put_RegisterAsBrowser(newVal);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::get_RegisterAsDropTarget(short wbUID,VARIANT_BOOL bUseIEDefault, VARIANT_BOOL *pVal)
{
	//Just return global flag
	if(wbUID <= 0)
	{
		*pVal = m_bRegisterAsDropTarget;
		return S_OK;
	}
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			if(bUseIEDefault == VARIANT_TRUE)
			{
				m_arrWB[i]->pWebBrowser->get_RegisterAsDropTarget(pVal);
			}
			else
			{
				*pVal = (m_arrWB[i]->m_bAllowDragDrop) ? VARIANT_TRUE : VARIANT_FALSE;
			}
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

//If you don't want drag-and-drop support in your application,
//you can call RegisterAsDropTarget,
//passing in VARIANT_FALSE (default), to prevent any drag-and-drop operations
//on your WebBrowser Control instance.
//Set bUseIEDefault to VARIANT_TRUE to recieve OnWBDrag/Drop events
STDMETHODIMP CvbWB::put_RegisterAsDropTarget(short wbUID,VARIANT_BOOL bUseIEDefault, VARIANT_BOOL newVal)
{
	if(wbUID <= 0)
	{
		//Take note of global flag
		m_bRegisterAsDropTarget = newVal;
		if(bUseIEDefault == VARIANT_TRUE)
		{
			m_bUseInternalDragDrop = VARIANT_FALSE;
			SetGlobalFlags(WB_FLAGS_RegisterAsDropTraget_IE,newVal);
		}
		else
		{
			m_bUseInternalDragDrop = VARIANT_TRUE;
			SetGlobalFlags(WB_FLAGS_RegisterAsDropTraget_Internal,newVal);
		}
		return S_OK;
	}
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			if(bUseIEDefault == VARIANT_TRUE)
			{
				m_arrWB[i]->pWebBrowser->put_RegisterAsDropTarget(newVal);
			}
			else
			{
				//Using our IdropTarget implementation
				m_arrWB[i]->m_bAllowDragDrop = VARIANTBOOLTObool(newVal);
			}
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::get_Silent(short wbUID, VARIANT_BOOL *pVal)
{
	//Just return global flag
	if(wbUID <= 0)
	{
		*pVal = m_bSilent;
		return S_OK;
	}
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			m_arrWB[i]->pWebBrowser->get_Silent(pVal);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::put_Silent(short wbUID, VARIANT_BOOL newVal)
{
	if(wbUID <= 0)
	{
		m_bSilent = newVal;
		SetGlobalFlags(WB_FLAGS_Silen,m_bSilent);
		return S_OK;
	}
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			m_arrWB[i]->pWebBrowser->put_Silent(newVal);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::get_LocationName(short wbUID, BSTR *pVal)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			ClearBSTRPtr(*pVal);
			m_arrWB[i]->pWebBrowser->get_LocationName(pVal);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

/////////////////////////////////////////////////////////
///////OleCommandTarget->Exec
///////For the first param pass one of CGID_ flags, or null for default

STDMETHODIMP CvbWB::SelectAll(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pOleCommandTarget)
		{
			//pguidCmdGroup [unique][in] Pointer to unique identifier of the command group;
			//can be NULL to specify the standard group. 
			m_arrWB[i]->pOleCommandTarget->Exec(NULL,OLECMDID_SELECTALL,OLECMDEXECOPT_DODEFAULT,NULL,NULL);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::Paste(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pOleCommandTarget)
		{ 
			m_arrWB[i]->pOleCommandTarget->Exec(NULL,OLECMDID_PASTE,OLECMDEXECOPT_DODEFAULT,NULL,NULL);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::Copy(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pOleCommandTarget)
		{ 
			m_arrWB[i]->pOleCommandTarget->Exec(NULL,OLECMDID_COPY,OLECMDEXECOPT_DODEFAULT,NULL,NULL);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::Cut(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pOleCommandTarget)
		{ 
			m_arrWB[i]->pOleCommandTarget->Exec(NULL,OLECMDID_CUT,OLECMDEXECOPT_DODEFAULT,NULL,NULL);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::Undo(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pOleCommandTarget)
		{ 
			m_arrWB[i]->pOleCommandTarget->Exec(NULL,OLECMDID_UNDO,OLECMDEXECOPT_DODEFAULT,NULL,NULL);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::Redo(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pOleCommandTarget)
		{ 
			m_arrWB[i]->pOleCommandTarget->Exec(NULL,OLECMDID_REDO,OLECMDEXECOPT_DODEFAULT,NULL,NULL);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::ClearSelection(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pOleCommandTarget)
		{ 
			m_arrWB[i]->pOleCommandTarget->Exec(NULL,OLECMDID_CLEARSELECTION,OLECMDEXECOPT_DODEFAULT,NULL,NULL);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::Delete(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pOleCommandTarget)
		{ 
			m_arrWB[i]->pOleCommandTarget->Exec(NULL,OLECMDID_DELETE,OLECMDEXECOPT_DODEFAULT,NULL,NULL);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::Find(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		HRESULT hr = S_OK;
		if (!m_arrWB[i]->pOleCommandTarget)
			hr = m_arrWB[i]->pUnknown->QueryInterface(IID_IOleCommandTarget, 
					reinterpret_cast<void **>(&m_arrWB[i]->pOleCommandTarget));

		if( (SUCCEEDED(hr)) && (m_arrWB[i]->pOleCommandTarget) )
			hr = m_arrWB[i]->pOleCommandTarget->Exec(&WB_CGI_IWebBrowser,
									WB_MiscCommandTarget_Find ,
									OLECMDEXECOPT_DODEFAULT,NULL,NULL);
/*
		else
			return AtlReportError(CLSID_vbWB, _T("No Command Target Found."),IID_IvbWB,DISP_E_EXCEPTION);

		switch (hr)
		{
		case E_FAIL:
				return AtlReportError(CLSID_vbWB, _T("E_FAIL"),IID_IvbWB,DISP_E_EXCEPTION);
			break;
		case E_UNEXPECTED:
				return AtlReportError(CLSID_vbWB, _T("E_UNEXPECTED"),IID_IvbWB,DISP_E_EXCEPTION);
			break;
		case OLECMDERR_E_UNKNOWNGROUP:
				return AtlReportError(CLSID_vbWB, _T("EOLECMDERR_E_UNKNOWNGROUP"),IID_IvbWB,DISP_E_EXCEPTION);
			break;
		case OLECMDERR_E_NOTSUPPORTED: //returns
				return AtlReportError(CLSID_vbWB, _T("OLECMDERR_E_NOTSUPPORTED"),IID_IvbWB,DISP_E_EXCEPTION);
			break;
		case OLECMDERR_E_DISABLED:
				return AtlReportError(CLSID_vbWB, _T("OLECMDERR_E_DISABLED"),IID_IvbWB,DISP_E_EXCEPTION);
			break;
		case OLECMDERR_E_NOHELP:
				return AtlReportError(CLSID_vbWB, _T("OLECMDERR_E_NOHELP"),IID_IvbWB,DISP_E_EXCEPTION);
			break;
		case OLECMDERR_E_CANCELED:
				return AtlReportError(CLSID_vbWB, _T("OLECMDERR_E_CANCELED"),IID_IvbWB,DISP_E_EXCEPTION);
			break;
		default:
			break;
		}
*/
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::PasteSpecial(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pOleCommandTarget)
		{
			m_arrWB[i]->pOleCommandTarget->Exec(NULL,OLECMDID_PASTESPECIAL,OLECMDEXECOPT_DODEFAULT,NULL,NULL);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::Spell(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pOleCommandTarget)
		{
			m_arrWB[i]->pOleCommandTarget->Exec(NULL,OLECMDID_SPELL,OLECMDEXECOPT_DODEFAULT,NULL,NULL);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::Properties(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pOleCommandTarget)
		{ 
			m_arrWB[i]->pOleCommandTarget->Exec(NULL,OLECMDID_PROPERTIES,OLECMDEXECOPT_DODEFAULT,NULL,NULL);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::NewWindow(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pOleCommandTarget)
		{ 
			m_arrWB[i]->pOleCommandTarget->Exec(NULL,OLECMDID_NEW,OLECMDEXECOPT_DODEFAULT,NULL,NULL);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::FileOpen(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		//m_arrWB[i]->InvokeShellDocObjCommand(ID_IE_FILE_OPEN);
		HRESULT hr = S_OK;
		if (!m_arrWB[i]->pOleCommandTarget)
			hr = m_arrWB[i]->pUnknown->QueryInterface(IID_IOleCommandTarget, 
					reinterpret_cast<void **>(&m_arrWB[i]->pOleCommandTarget));

		if( (SUCCEEDED(hr)) && (m_arrWB[i]->pOleCommandTarget) )
		{
			//Calling either way produces no errors, yet no open dialog either???
			//Anyone finds a solution to this, will appreciate it if send to me.
			hr = m_arrWB[i]->pOleCommandTarget->Exec(NULL,
								OLECMDID_OPEN,OLECMDEXECOPT_PROMPTUSER,NULL,NULL);
			//IDM_xxxx are defined in mshtmcid.h file
			//hr = m_arrWB[i]->pOleCommandTarget->Exec(&CGID_MSHTML,
			//					IDM_OPEN,OLECMDEXECOPT_PROMPTUSER,NULL,NULL);
		}
/*
		else
			return AtlReportError(CLSID_vbWB, _T("No Command Target Found."),IID_IvbWB,DISP_E_EXCEPTION);

		switch (hr)
		{
		case E_FAIL:
				return AtlReportError(CLSID_vbWB, _T("Error E_FAIL"),IID_IvbWB,DISP_E_EXCEPTION);
			break;
		case E_UNEXPECTED:
				return AtlReportError(CLSID_vbWB, _T("Error E_UNEXPECTED"),IID_IvbWB,DISP_E_EXCEPTION);
			break;
		case OLECMDERR_E_UNKNOWNGROUP:
				return AtlReportError(CLSID_vbWB, _T("Error OLECMDERR_E_UNKNOWNGROUP"),IID_IvbWB,DISP_E_EXCEPTION);
			break;
		case OLECMDERR_E_NOTSUPPORTED: //returns
				return AtlReportError(CLSID_vbWB, _T("Error OLECMDERR_E_NOTSUPPORTED"),IID_IvbWB,DISP_E_EXCEPTION);
			break;
		case OLECMDERR_E_DISABLED:
				return AtlReportError(CLSID_vbWB, _T("Error OLECMDERR_E_DISABLED"),IID_IvbWB,DISP_E_EXCEPTION);
			break;
		case OLECMDERR_E_NOHELP:
				return AtlReportError(CLSID_vbWB, _T("Error OLECMDERR_E_NOHELP"),IID_IvbWB,DISP_E_EXCEPTION);
			break;
		case OLECMDERR_E_CANCELED:
				return AtlReportError(CLSID_vbWB, _T("Error OLECMDERR_E_CANCELED"),IID_IvbWB,DISP_E_EXCEPTION);
			break;
		default:
			break;
		}
*/
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::Save(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pOleCommandTarget)
		{
			//m_arrWB[i]->InvokeShellDocObjCommand(ID_IE_FILE_SAVE);
			m_arrWB[i]->pOleCommandTarget->Exec(NULL,OLECMDID_SAVE,
							OLECMDEXECOPT_PROMPTUSER,NULL,NULL);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::SaveAs(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i]) // && m_arrWB[i]->pOleCommandTarget)
		{
			m_arrWB[i]->InvokeShellDocObjCommand(ID_IE_FILE_SAVEAS);
			//m_arrWB[i]->pOleCommandTarget->Exec(NULL,OLECMDID_SAVEAS,OLECMDEXECOPT_DODEFAULT,NULL,NULL);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::Print(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pOleCommandTarget)
		{ 
			m_arrWB[i]->pOleCommandTarget->Exec(NULL,OLECMDID_PRINT,OLECMDEXECOPT_DODEFAULT,NULL,NULL);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::PrintPreview(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pOleCommandTarget)
		{ 
			m_arrWB[i]->pOleCommandTarget->Exec(NULL,OLECMDID_PRINTPREVIEW,OLECMDEXECOPT_DODEFAULT,NULL,NULL);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::PageSetup(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pOleCommandTarget)
		{ 
			m_arrWB[i]->pOleCommandTarget->Exec(NULL,OLECMDID_PAGESETUP,OLECMDEXECOPT_DODEFAULT,NULL,NULL);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::Print2(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pOleCommandTarget)
		{ 
			m_arrWB[i]->pOleCommandTarget->Exec(NULL,OLECMDID_PRINT2,OLECMDEXECOPT_DODEFAULT,NULL,NULL);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::PrintPreview2(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pOleCommandTarget)
		{ 
			m_arrWB[i]->pOleCommandTarget->Exec(NULL,OLECMDID_PRINTPREVIEW2,OLECMDEXECOPT_DODEFAULT,NULL,NULL);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::get_HWNDShellDocObjectView(short wbUID, long *pVal)
{
	int i = FindWB(wbUID);
	if ( i > -1 )
	{
		if (m_arrWB[i])
			*pVal = (long) m_arrWB[i]->GetShellDocObjHwnd();
	}
	else
		*pVal = -1;
	return S_OK;
}

STDMETHODIMP CvbWB::get_HWNDInternetExplorerServer(short wbUID, long *pVal)
{
	int i = FindWB(wbUID);
	if ( i > -1 )
	{
		if (m_arrWB[i])
			*pVal = (long) m_arrWB[i]->GetIEServerHwnd();
	}
	else
		*pVal = -1;
	return S_OK;
}

STDMETHODIMP CvbWB::ViewSource(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i]) //m_arrWB[i]->pOleCommandTarget)
		{
			//m_arrWB[i]->pOleCommandTarget->Exec(&WB_CGI_IWebBrowser,
			//						WB_MiscCommandTarget_ViewSource ,
			//						OLECMDEXECOPT_DODEFAULT,NULL,NULL);
			m_arrWB[i]->InvokeIEServerCommand(ID_IE_CONTEXTMENU_VIEWSOURCE);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::AddToFavorites(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i])
		{ 
			m_arrWB[i]->InvokeIEServerCommand(ID_IE_CONTEXTMENU_ADDFAV);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}


STDMETHODIMP CvbWB::SetFocusW(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i])
		{
			m_wbcurid = wbUID;
			m_arrWB[i]->SetFocusDoc();
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::PlaceWBOnTop(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i])
		{
			m_wbcurid = wbUID;
			m_arrWB[i]->BringWbToTop();
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::get_HWNDMainWnd(long *pVal)
{
	*pVal =  (long)m_hWnd;
	return S_OK;
}

//Finds out if any of the wb's have focus
//And returns the wbUID
STDMETHODIMP CvbWB::AnyDocHasFocus(short *wbUID)
{
	//Initially
	*wbUID = -1;
	HWND focusWin = GetFocus();


	TCHAR pszClassName[MAX_PATH+1];
	::GetClassName(focusWin, pszClassName, MAX_PATH);
	if (lstrcmp(pszClassName, IE_SERVER_CLASSNAME) != 0)
	{
		while ((focusWin = ::GetParent(focusWin)) != 0)
		{
			::GetClassName(focusWin, pszClassName, MAX_PATH);
			if (lstrcmp(pszClassName, IE_SERVER_CLASSNAME) == 0)
			{
				break;
			}
		}
	}

	for(int i = 0; i < m_arrWB.GetSize() ; i++)
	{
		if(m_arrWB[i]->GetIEServerHwnd() == focusWin)
		{
			*wbUID = (short)i;
			break;
		}
	}
	return S_OK;
}

STDMETHODIMP CvbWB::ExecWB(short wbUID,long cmdID, long cmdExecOpt, VARIANT *pvaIn, VARIANT *pvaOut)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pOleCommandTarget)
		{ 
			HRESULT hr = m_arrWB[i]->pOleCommandTarget->Exec(NULL,cmdID,cmdExecOpt,pvaIn,pvaOut);
			if (FAILED(hr))
			{
				m_StrErr_Tmp = (UINT)IDS_EXECWB_FAILED;
				return AtlReportError(CLSID_vbWB, m_StrErr_Tmp, IID_IvbWB,DISP_E_EXCEPTION);
			}
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::QueryStatusWB(short wbUID, long cmdID, long *pcmdf)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pOleCommandTarget)
		{
			//OLECMD olcm;
			//OLECMDTEXT olcmt;
			OLECMDF ultmp; //= OLECMDF_SUPPORTED;

			//olcm.cmdID = (ULONG)cmdID; //OLECMDID enumeration ULONG
			//olcm.cmdf = ultmp; //OLECMDF enumeration DWORD.

			//return m_arrWB[i]->pOleCommandTarget->QueryStatus(NULL,1,olcm,NULL);
			HRESULT hr = m_arrWB[i]->pWebBrowser->QueryStatusWB((OLECMDID)cmdID,&ultmp);
			if (SUCCEEDED(hr))
			{
				*pcmdf = (long)ultmp;
				return S_OK;
			}
			else
			{
				m_StrErr_Tmp = (UINT)IDS_QSWB_FAILED;
				return AtlReportError(CLSID_vbWB, m_StrErr_Tmp,IID_IvbWB,DISP_E_EXCEPTION);
			}
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);

	return S_OK;
}

STDMETHODIMP CvbWB::get_StartupURL(BSTR *pVal)
{
	ClearBSTRPtr(*pVal);
	*pVal = m_StartupURL.Copy();
	return S_OK;
}

STDMETHODIMP CvbWB::put_StartupURL(BSTR newVal)
{
	m_StartupURL.Empty();
	m_StartupURL = newVal;
	return S_OK;
}

STDMETHODIMP CvbWB::get_UseIEDefaultFileDownload(short wbUID, VARIANT_BOOL *pVal)
{
	//Just return global flag
	if(wbUID <= 0)
	{
		*pVal = m_bUseIEDownloader;
		return S_OK;
	}
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i])
		{ 
			if(m_arrWB[i]->m_useieforfiledl == true)
				*pVal = VARIANT_TRUE;
			else
				*pVal = VARIANT_FALSE;
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::put_UseIEDefaultFileDownload(short wbUID, VARIANT_BOOL newVal)
{
	if(wbUID <= 0)
	{
		m_bUseIEDownloader = newVal;
		SetGlobalFlags(WB_FLAGS_UseIEDefaultDownloader,m_bUseIEDownloader);
		return S_OK;
	}
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i])
		{
			if(newVal == VARIANT_TRUE)
			{
				m_arrWB[i]->m_useieforfiledl = true;
			}
			else
			{
				m_arrWB[i]->m_useieforfiledl = false;
			}
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::get_HWNDShellEmbedding(short wbUID, long *pVal)
{
	int i = FindWB(wbUID);
	if ( i > -1 )
	{
		if (m_arrWB[i])
		{
			*pVal = (long) m_arrWB[i]->GetShellEmbedding();
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}


STDMETHODIMP CvbWB::get_FramesCount(short wbUID, long *pVal)
{
	int i = FindWB(wbUID);
	if ( i > -1 )
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			CComPtr<IDispatch> spDisp;
			//Get the browser dispatch using get_Document
			HRESULT hr = m_arrWB[i]->pWebBrowser->get_Document(&spDisp);
			if(FAILED(hr) || !spDisp)
			{
				m_StrErr_Tmp = (UINT)IDS_NO_DOCDISPATCH;
				return AtlReportError(CLSID_vbWB, m_StrErr_Tmp, IID_IvbWB,DISP_E_EXCEPTION);
			}
			
			CComQIPtr<IHTMLDocument2> spDoc( spDisp );
			if(!spDoc)
			{
				m_StrErr_Tmp = (UINT)IDS_NO_DOCOBJECT;
				return AtlReportError(CLSID_vbWB, m_StrErr_Tmp, IID_IvbWB,DISP_E_EXCEPTION);
			}
			
			*pVal = m_arrWB[i]->FramesCount(spDoc);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::get_WBVisible(short wbUID, VARIANT_BOOL *pVal)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i])
		{
			if(m_arrWB[i]->m_visible == true)
				*pVal = VARIANT_TRUE;
			else
				*pVal = VARIANT_FALSE;
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::put_WBVisible(short wbUID, VARIANT_BOOL newVal)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i])
		{
			//Does not work
			//m_arrWB[i]->pWebBrowser->put_Visible(newVal);
			//Using COM method
			if (newVal == VARIANT_TRUE)
				m_arrWB[i]->SetVisible(true);
			else
				m_arrWB[i]->SetVisible(false);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::get_Application(short wbUID, LPDISPATCH *pVal)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			m_arrWB[i]->pWebBrowser->get_Application(pVal);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::get_Document(short wbUID, LPDISPATCH *pVal)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			m_arrWB[i]->pWebBrowser->get_Document(pVal);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::get_ActiveElementObj(short wbUID, LPDISPATCH *pVal)
{
	HRESULT hret = S_FALSE;
	int i = FindWB(wbUID);
	if ( i > -1 )
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			CComPtr<IDispatch> spDisp;
			
			//Get the document dispatch
			m_arrWB[i]->pWebBrowser->get_Document(&spDisp);
			if(!spDisp) goto ReturnError; //return hret;
			
			//Query for HtmlDocument2
			CComQIPtr<IHTMLDocument2> spDoc( spDisp );
			if(!spDoc) goto ReturnError; //return hret;
			
			//Get the active element
			CComPtr<IHTMLElement> spElementHit;
			spDoc->get_activeElement(&spElementHit);
			if(!spElementHit) goto ReturnError; //return hret;
			
			//See if we can query the active element for IWebBrowser2 interface
			//indicating that this is a frame
			CComQIPtr<IWebBrowser2> spFrame( spElementHit );
			/*
				FROM				GETS
				============		===================
				IWebBrowser2		IDispatch(get_Document)
				IDispatch			IHTMLDocument2(QueryInterface)
				IHTMLDocument2		IHTMLElement(get_activeElement)
				IHTMLElement		IWebBrowser2(QueryInterface)

				Continues till IWebBrowser2 is NULL, no more FRAME
				So the IHtmlElement we end up with is an actual element
				Causion:
				A tagname of FRAMESET is same as body for none frame sites
			*/
			while( spFrame )
			{
				spDisp.Release();
				spFrame->get_Document(&spDisp);
				spDoc = spDisp;
				spElementHit.Release();
				spDoc->get_activeElement(&spElementHit);
				//Query for IWebBrowser2
				spFrame = spElementHit;
			}
			if(!spElementHit) goto ReturnError; //return hret;
			//*pVal = spElementHit;
			CComQIPtr<IDispatch> spRetDisp( spElementHit );
			if(!spRetDisp) goto ReturnError; //return hret;
			spRetDisp.CopyTo(pVal);
			
			hret = S_OK;
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return hret;

ReturnError:
	m_StrErr_Tmp = (UINT)IDS_NO_ACTIVEELEM;
	return AtlReportError(CLSID_vbWB, m_StrErr_Tmp, IID_IvbWB,DISP_E_EXCEPTION);
}

STDMETHODIMP CvbWB::get_ActiveDocumentObj(short wbUID, LPDISPATCH *pVal)
{
	HRESULT hret = S_FALSE;
	int i = FindWB(wbUID);
	if ( i > -1 )
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			CComPtr<IDispatch> spDisp;
			
			//Get the document dispatch
			m_arrWB[i]->pWebBrowser->get_Document(&spDisp);
			if(!spDisp) goto ReturnError; //return hret;
			
			//Query for HtmlDocument2
			CComQIPtr<IHTMLDocument2> spDoc( spDisp );
			if(!spDoc) goto ReturnError; //return hret;
			
			//Get the active element
			CComPtr<IHTMLElement> spElementHit;
			spDoc->get_activeElement(&spElementHit);
			if(!spElementHit) goto ReturnError; //return hret;
			
			//See if we can query the active element for IWebBrowser2 interface
			//indicating that this is a frame
			CComQIPtr<IWebBrowser2> spFrame( spElementHit );
			while( spFrame )
			{
				spDisp.Release();
				//Get document dispatch
				spFrame->get_Document(&spDisp);
				spDoc = spDisp;
				spElementHit.Release();
				spDoc->get_activeElement(&spElementHit);
				//Query for IWebBrowser2
				spFrame = spElementHit;
			}
			if(!spDisp) goto ReturnError; //return hret;
			spDisp.CopyTo(pVal);
			hret = S_OK;
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return hret;

ReturnError:
	m_StrErr_Tmp = (UINT)IDS_NO_ACTIVEELEM;
	return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION);
}

STDMETHODIMP CvbWB::Navigate2(short wbUID, VARIANT *URL, VARIANT *Flags, VARIANT *TargetFrameName, VARIANT *PostData, VARIANT *Headers)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			m_arrWB[i]->pWebBrowser->Navigate2(URL,Flags,TargetFrameName,PostData,Headers);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::Navigate(short wbUID, BSTR URL, VARIANT *Flags, VARIANT *TargetFrameName, VARIANT *PostData, VARIANT *Headers)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			m_arrWB[i]->pWebBrowser->Navigate(URL,Flags,TargetFrameName,PostData,Headers);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

//bBringToFront default False
STDMETHODIMP CvbWB::AddBrowser(short *wbUID, VARIANT_BOOL bBringToFront)
{
	//Incease unique id
	m_wbuid++;
	IWB *newiwb = new IWB(this);
	if (newiwb != NULL)
	{
		newiwb->m_thisID = m_wbuid;
		newiwb->m_hwndParent = m_hWnd;

		m_arrWB.Add(newiwb);
		//Use the global flags to create browser
		HRESULT hr = newiwb->StartWB(m_HostUiFlags,
											m_HostDbClickAction,
											m_HostDlFlag,
											m_dwCtxMnuAction,
											m_wbuid, 
											m_bRegisterAsDropTarget, //Allow dragdrop 
											m_bUseInternalDragDrop,  //Use internal mechanism
											m_bSourceOnDocComplete,
											m_StartupURL);
		if (FAILED(hr))
		{
			m_StrErr_Tmp = (UINT)IDS_WB_CREATE_FAILED;
			return AtlReportError(CLSID_vbWB, m_StrErr_Tmp, IID_IvbWB,DISP_E_EXCEPTION);
		}
		if(VARIANTBOOLTOBOOL(bBringToFront))
			newiwb->BringWbToTop();
	}
	else
	{
		m_StrErr_Tmp = (UINT)IDS_HOST_CREATE_FAILED;
		return AtlReportError(CLSID_vbWB, m_StrErr_Tmp, IID_IvbWB,DISP_E_EXCEPTION);
	}

	//Send back the ID for this browser
	*wbUID = m_wbuid;
	return S_OK;
}

HRESULT CvbWB::ProcessWBAccelKeys(MSG *pMsg)
{
		if ( (pMsg->message >= WM_KEYFIRST) &&
			(pMsg->message <= WM_KEYLAST) )
		{
			HWND focusWin = GetFocus();
			bool FoundWB = false;
			int i = 0;

			/*
			//Aug 04 2005
			//dosuryu, fix for loss of tab key when focus is on a <SELECT> tag
			//It is caused due to return value of the GetFocus function which is a child window.
			//Spy++ Tree view
			//+ Shell DocObject View
			//  + Internet Explorer_Server
			//    + Internet Explorer_TridentCmboBx  <- Return value of GetFocus function
			*/
			TCHAR pszClassName[MAX_PATH+1];
			::GetClassName(focusWin, pszClassName, MAX_PATH);
			if (lstrcmp(pszClassName, IE_SERVER_CLASSNAME) != 0)
			{
				while ((focusWin = ::GetParent(focusWin)) != 0)
				{
					::GetClassName(focusWin, pszClassName, MAX_PATH);
					if (lstrcmp(pszClassName, IE_SERVER_CLASSNAME) == 0)
					{
						break;
					}
				}
			}

			if(focusWin)
			{
				//Do any of our WBs have focus
				for(i = 0; i < m_arrWB.GetSize() ; i++)
				{
					if(focusWin == m_arrWB[i]->GetIEServerHwnd())
					{
						FoundWB = true;
						break;
					}
				}
				
				if ( FoundWB == true )
				{
					//if(m_arrWB[i]->spOleObj) 
					//{
					//	m_arrWB[i]->spOleObj->DoVerb(OLEIVERB_UIACTIVATE, NULL,
					//		m_arrWB[i]->m_pWBClientSite, 0,
					//		m_hWnd, &m_arrWB[i]->rWindowPos);
					//}

					// Call TranslateAccelerator on the in-place active
					// object so that the accelerator will be passed to the 
					// hosted WebBrowser control.  This also forces tabbing to 
					// work correctly in edit boxes.
					CComQIPtr<IOleInPlaceActiveObject,
						   &IID_IOleInPlaceActiveObject> spInPlaceActiveObject(m_arrWB[i]->pWebBrowser);
					if(spInPlaceActiveObject)
					{
						return spInPlaceActiveObject->TranslateAccelerator(pMsg);
					}
				}
			}
			//
			//Refer to KB article 187644 - need default handling
			//
			if((VK_TAB == pMsg->wParam) || (VK_RETURN == pMsg->wParam))
			{
				CComQIPtr<IOleControlSite,&IID_IOleControlSite> 
						spCtrlSite(m_spClientSite);
					if(spCtrlSite)
					{
						DWORD dwKeyMod = 0;
						if (::GetKeyState(VK_SHIFT) < 0)
							dwKeyMod += 1;	// KEYMOD_SHIFT
						if (::GetKeyState(VK_CONTROL) < 0)
							dwKeyMod += 2;	// KEYMOD_CONTROL
						if (::GetKeyState(VK_MENU) < 0)
							dwKeyMod += 4;	// KEYMOD_ALT
						return spCtrlSite->TranslateAccelerator (pMsg, dwKeyMod);
					}
			}
		}
//		return IOleInPlaceActiveObjectImpl<CvbWB>::TranslateAccelerator(pMsg);
		return S_FALSE; //1 not handled
}


STDMETHODIMP CvbWB::GetControlInfo(CONTROLINFO *pCI)
{
	if(!pCI)
	{
		return E_POINTER;
	}
	pCI->hAccel   = NULL;
	pCI->cAccel   = 0;
//CTRLINFO_EATS_RETURN = 1
//When the control has the focus, it will process the Return key.
//CTRLINFO_EATS_ESCAPE = 2
//When the control has the focus, it will process the Escape key.

//When the control has the focus, the dialog box containing 
//the control cannot use the Return or Escape keys as mnemonics
//for the default and cancel buttons.

	pCI->dwFlags  = CTRLINFO_EATS_RETURN | CTRLINFO_EATS_ESCAPE;
	return S_OK;
}


void CvbWB::ResizeWBs()
{
 	if(m_arrWB.GetSize() > 0)
 	{
 		//Fill in the container
 		RECT rWPos;
 		GetClientRect(&rWPos);
 		rWPos.right -= rWPos.left; //W
 		rWPos.bottom -= rWPos.top; //H
 		rWPos.left = 0;
 		rWPos.top = 0;
 		//Resize all IWBs
 		for (int i = 0; i < m_arrWB.GetSize(); i++)
 	    {
 			if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
 			{
 				m_arrWB[i]->SetLocation(&rWPos);
 			}
 		}
 	}
}

STDMETHODIMP CvbWB::get_ObjectWB(short wbUID, LPDISPATCH *pVal)
{
	int i = FindWB(wbUID);
	HRESULT hret = S_OK;
	if ( i > -1 )
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			hret = m_arrWB[i]->pUnknown->QueryInterface(IID_IDispatch,(void**)pVal);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return hret;
}

STDMETHODIMP CvbWB::get_ContextMenuAction(short wbUID, long *pVal)
{
	//Just return global flag
	if(wbUID <= 0)
	{
		*pVal = (long)m_dwCtxMnuAction;
		return S_OK;
	}
	//Search and return the specific wb flag
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i])
		{
			*pVal = m_arrWB[i]->m_pWBDocHostUIHandler->m_ContextMenuAction;
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	
	return S_OK;
}

STDMETHODIMP CvbWB::put_ContextMenuAction(short wbUID, long newVal)
{
	if( newVal >= 0 && newVal <= 2)
	{
		if(wbUID <= 0)
		{
			m_dwCtxMnuAction = (DWORD)newVal;
			SetGlobalFlags(WB_FLAGS_CtxMnu ,m_dwCtxMnuAction);
			return S_OK;
		}
		int i = FindWB(wbUID);
		if ( i > -1 ) 
		{
			if (m_arrWB[i])
			{
				m_arrWB[i]->m_pWBDocHostUIHandler->m_ContextMenuAction = newVal;
			}
		}
		else
			return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);

	}
	else
	{
		m_StrErr_Tmp = (UINT)IDS_ACCEL_PROP_ERR;
		return AtlReportError(CLSID_vbWB, m_StrErr_Tmp, IID_IvbWB,DISP_E_EXCEPTION);
	}
	return S_OK;
}

STDMETHODIMP CvbWB::get_DocumentDownloadControlFlags(short wbUID, long *pVal)
{
	if(wbUID <= 0)
	{
		*pVal = (long)m_HostDlFlag;
		return S_OK;
	}
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i])
		{
			*pVal = (long)m_arrWB[i]->m_pWBEventDispatch->m_dwDLControl;
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	
	return S_OK;
}

STDMETHODIMP CvbWB::put_DocumentDownloadControlFlags(short wbUID, long newVal)
{
		if(wbUID <= 0)
		{
			m_HostDlFlag = (DWORD)newVal;
			SetGlobalFlags(WB_FLAGS_DL,m_HostDlFlag);
			return S_OK;
		}
		int i = FindWB(wbUID);
		if ( i > -1 ) 
		{
			if (m_arrWB[i])
			{
				m_arrWB[i]->m_pWBEventDispatch->m_dwDLControl = (DWORD) newVal;
			}
		}
		else
			return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);

	return S_OK;
}

STDMETHODIMP CvbWB::get_DocumentHostUiFlags(short wbUID, long *pVal)
{
	if(wbUID <= 0)
	{
		*pVal = (long)m_HostUiFlags;
		return S_OK;
	}
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i])
		{
			*pVal = (long) m_arrWB[i]->m_pWBDocHostUIHandler->m_dwDocHostUIFlags;
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	
	return S_OK;
}

STDMETHODIMP CvbWB::put_DocumentHostUiFlags(short wbUID, long newVal)
{
	if(wbUID <= 0)
	{
		m_HostUiFlags = (DWORD)newVal;
		SetGlobalFlags(WB_FLAGS_UI,m_HostUiFlags);
		return S_OK;
	}
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i])
		{
			m_arrWB[i]->m_pWBDocHostUIHandler->m_dwDocHostUIFlags = (DWORD) newVal;
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);

	return S_OK;
}

STDMETHODIMP CvbWB::get_DocumentHostUiDoubleClickAction(short wbUID, long *pVal)
{
	if(wbUID <= 0)
	{
		*pVal = (long)m_HostDbClickAction;
		return S_OK;
	}
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i])
		{
			*pVal = (long) m_arrWB[i]->m_pWBDocHostUIHandler->m_dwDocHostUIDblClk;
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	
	return S_OK;
}

STDMETHODIMP CvbWB::put_DocumentHostUiDoubleClickAction(short wbUID, long newVal)
{
	if( newVal >= 0 && newVal <= 2)
	{
		if(wbUID <= 0)
		{
			m_HostDbClickAction = (DWORD)newVal;
			SetGlobalFlags(WB_FLAGS_DblClk,m_HostDbClickAction);
			return S_OK;
		}
		int i = FindWB(wbUID);
		if ( i > -1 ) 
		{
			if (m_arrWB[i])
			{
				m_arrWB[i]->m_pWBDocHostUIHandler->m_dwDocHostUIDblClk = (DWORD) newVal;
			}
		}
		else
			return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);

	}
	else
	{
		m_StrErr_Tmp = (UINT)IDS_PROP_VALUE_ERR;
		return AtlReportError(CLSID_vbWB, m_StrErr_Tmp, IID_IvbWB,DISP_E_EXCEPTION);
	}
	return S_OK;
}

STDMETHODIMP CvbWB::FindTextSimple(short wbUID,BSTR TextToFind,VARIANT_BOOL bDownward,VARIANT_BOOL bMatchWholeWord,VARIANT_BOOL bMatchCase,VARIANT_BOOL bScrollIntoView, VARIANT_BOOL *FindMatch)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			if (m_arrWB[i]->DocFindText(TextToFind, bDownward,bMatchWholeWord, bMatchCase, bScrollIntoView) == false)
			{
				*FindMatch = VARIANT_FALSE;
			}
			else
				*FindMatch = VARIANT_TRUE;
		}
		else
		{
			m_StrErr_Tmp = (UINT)IDS_NO_BROWSEROBJ;
			return AtlReportError(CLSID_vbWB, m_StrErr_Tmp,IID_IvbWB,DISP_E_EXCEPTION);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);

	return S_OK;
}

//Searches and highlights all matches in all frames
HRESULT CvbWB::FindAndHighlightAllTextFrames(short wbUID, BSTR TextToFind, VARIANT_BOOL bMatchWholeWord, VARIANT_BOOL bMatchCase, BSTR HighlightColor, long *NumOfMatchsFound)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			*NumOfMatchsFound = m_arrWB[i]->DocHighlightAllFindText(TextToFind,bMatchWholeWord, bMatchCase, HighlightColor );
		}
		else
		{
			m_StrErr_Tmp = (UINT)IDS_NO_BROWSEROBJ;
			return AtlReportError(CLSID_vbWB, m_StrErr_Tmp,IID_IvbWB,DISP_E_EXCEPTION);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);


	return S_OK;
}

//Searches and highlights matches in active document (accounts for frames)
STDMETHODIMP CvbWB::FindAndHighlightAllText(short wbUID,BSTR TextToFind, VARIANT_BOOL bMatchWholeWord, VARIANT_BOOL bMatchCase, BSTR HighlightColor, long *NumOfMatchsFound)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			*NumOfMatchsFound = m_arrWB[i]->DocHighlightFindText(TextToFind,bMatchWholeWord, bMatchCase, HighlightColor );
		}
		else
		{
			m_StrErr_Tmp = (UINT)IDS_NO_BROWSEROBJ;
			return AtlReportError(CLSID_vbWB, m_StrErr_Tmp,IID_IvbWB,DISP_E_EXCEPTION);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);


	return S_OK;
}

STDMETHODIMP CvbWB::FindAnyTextMatch( short wbUID, BSTR TextToFind, VARIANT_BOOL bMatchWholeWord, VARIANT_BOOL bMatchCase, VARIANT_BOOL *FindMatch)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
 		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
 		{
 			if(m_arrWB[i]->DocTextExists(TextToFind,bMatchWholeWord,bMatchCase) == true)
				*FindMatch = VARIANT_TRUE;
			else
				*FindMatch = VARIANT_FALSE;
 		}
 		else
		{
			m_StrErr_Tmp = (UINT)IDS_NO_BROWSEROBJ;
 			return AtlReportError(CLSID_vbWB, m_StrErr_Tmp,IID_IvbWB,DISP_E_EXCEPTION);
		}
	}
	else
 		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::get_IsDocFrameset(short wbUID, VARIANT_BOOL *pVal)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
 		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
 		{
 			if(m_arrWB[i]->IsFrameset() == true)
				*pVal = VARIANT_TRUE;
			else
				*pVal = VARIANT_FALSE;
 		}
 		else
		{
			m_StrErr_Tmp = (UINT)IDS_NO_BROWSEROBJ;
 			return AtlReportError(CLSID_vbWB, m_StrErr_Tmp, IID_IvbWB,DISP_E_EXCEPTION);
		}
	}
	else
 		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::get_ucScheme(BSTR *pVal)
{
	ClearBSTRPtr(*pVal);
	*pVal = strScheme.Copy(); 
	return S_OK;
}

STDMETHODIMP CvbWB::put_ucScheme(BSTR newVal)
{
	strScheme.Empty();
	strScheme = newVal;
	return S_OK;
}

STDMETHODIMP CvbWB::get_ucHostName(BSTR *pVal)
{
	ClearBSTRPtr(*pVal);
	*pVal = strHostName.Copy(); 
	return S_OK;
}

STDMETHODIMP CvbWB::put_ucHostName(BSTR newVal)
{
	strHostName.Empty();
	strHostName = newVal;
	return S_OK;
}

STDMETHODIMP CvbWB::get_ucPort(long *pVal)
{
	*pVal = Port;
	return S_OK;
}

STDMETHODIMP CvbWB::put_ucPort(long newVal)
{
	Port = newVal;
	return S_OK;
}

STDMETHODIMP CvbWB::get_ucUserName(BSTR *pVal)
{
	ClearBSTRPtr(*pVal);
	*pVal = strUserName.Copy(); 
	return S_OK;
}

STDMETHODIMP CvbWB::put_ucUserName(BSTR newVal)
{
	strUserName.Empty();
	strUserName = newVal;
	return S_OK;
}

STDMETHODIMP CvbWB::get_ucPassword(BSTR *pVal)
{
	ClearBSTRPtr(*pVal);
	*pVal = strPassword.Copy(); 
	return S_OK;
}

STDMETHODIMP CvbWB::put_ucPassword(BSTR newVal)
{
	strPassword.Empty();
	strPassword = newVal;
	return S_OK;
}

STDMETHODIMP CvbWB::get_ucUrlPath(BSTR *pVal)
{
	ClearBSTRPtr(*pVal);
	*pVal = strUrlPath.Copy(); 
	return S_OK;
}

STDMETHODIMP CvbWB::put_ucUrlPath(BSTR newVal)
{
	strUrlPath.Empty();
	strUrlPath = newVal;
	return S_OK;
}

STDMETHODIMP CvbWB::get_ucExtraInfo(BSTR *pVal)
{
	ClearBSTRPtr(*pVal);
	*pVal = strExtraInfo.Copy(); 
	return S_OK;
}

STDMETHODIMP CvbWB::put_ucExtraInfo(BSTR newVal)
{
	strExtraInfo.Empty();
	strExtraInfo = newVal;
	return S_OK;
}

STDMETHODIMP CvbWB::get_ucFullURL(BSTR *pVal)
{
	ClearBSTRPtr(*pVal);
	*pVal = strFullURL.Copy();
	return S_OK;
}

STDMETHODIMP CvbWB::put_ucFullURL(BSTR newVal)
{
	strFullURL.Empty();
	strFullURL = newVal;
	return S_OK;
}

STDMETHODIMP CvbWB::get_ucFileName(BSTR *pVal)
{
	ClearBSTRPtr(*pVal);
	*pVal = strFileName.Copy();
	return S_OK;
}

STDMETHODIMP CvbWB::get_ucFileExtension(BSTR *pVal)
{
	ClearBSTRPtr(*pVal);
	*pVal = strFileExtension.Copy();
	return S_OK;
}

STDMETHODIMP CvbWB::get_ucInternetScheme(long *pVal)
{
	*pVal = m_nScheme;
	return S_OK;
}

STDMETHODIMP CvbWB::put_ucInternetScheme( long newVal)
{
	m_nScheme = newVal;
	return S_OK;
}

/*
Sample URL:
http://www.codeguru.com/dbfiles/get_file/Example.zip?id=9285&lbl=EXAMPLE_ZIP&ds=20050308=80=3
URLPATH=/dbfiles/get_file/Example.zip
FILENAME=Example.zip
HOSTNAME=www.codeguru.com
EXTRAINFO=?id=9285&lbl=EXAMPLE_ZIP&ds=20050308=80=3
InternetScheme=INTERNET_SCHEME_HTTP
Port=80
*/
STDMETHODIMP CvbWB::ucInternetCrackUrl(BSTR URL,VARIANT_BOOL *bSuccess)
{
	//Reset buffers
	strScheme.Empty();
	strHostName.Empty();
	strUserName.Empty();
	strPassword.Empty();
	strUrlPath.Empty();
	strExtraInfo.Empty();
	strFullURL.Empty();
	strFileName.Empty();
	strFileExtension.Empty();
	Port					= 0;
	strFullURL				= URL;
	Port					= 0;
	m_nScheme				= 0; //Default
	
	//Assume success
	*bSuccess = VARIANT_TRUE;
	CUrlParts parts;
	if(parts.SplitUrl(URL) == false)
	{
		*bSuccess = VARIANT_FALSE;
		return S_OK;
	}
USES_CONVERSION;
	if(parts.GetSchemeLen() > 0)
	{
		strScheme = ::SysAllocStringLen(T2COLE(parts.GetScheme()), parts.GetSchemeLen() );
		m_nScheme = (long)parts.GetInternetScheme();
	}
	else
		strScheme				= L"";
	
	if(parts.GetHostNameLen() > 0)
	{
		strHostName = ::SysAllocStringLen(T2COLE(parts.GetHostName()), parts.GetHostNameLen() );
	}
	else
		strHostName				= L"";
	
	if(parts.GetUserNameLen() > 0)
	{
		strUserName = ::SysAllocStringLen(T2COLE(parts.GetUserName()), parts.GetUserNameLen() );
	}
	else
		strUserName				= L"";
	
	if(parts.GetPasswordLen() > 0)
	{
		strPassword = ::SysAllocStringLen(T2COLE(parts.GetPassword()), parts.GetPasswordLen() );
	}
	else
		strPassword				= L"";
	
	if(parts.GetUrlPathLen() > 0)
	{
		strUrlPath = ::SysAllocStringLen(T2COLE(parts.GetUrlPath()), parts.GetUrlPathLen() );
	}
	else
		strUrlPath				= L"";
	
	if(parts.GetFileNameLen() > 0)
	{
		strFileName = parts.GetFileNameAsBSTR(); //::SysAllocStringLen(T2OLE(parts.szFileName), parts.dwFileName );
	}
	else
		strFileName				= L"";
	
	if(parts.GetFileExtensionLen() > 0)
	{
		strFileExtension = parts.GetFileExtensionAsBSTR(); //::SysAllocStringLen(T2OLE(parts.szFileExtension), parts.dwFileExtension );
	}
	else
		strFileExtension		= L"";

	if(parts.GetExtraInfoLen() > 0)
	{
		strExtraInfo = ::SysAllocStringLen(T2COLE(parts.GetExtraInfo()), parts.GetExtraInfoLen());
	}
	else
		strExtraInfo			= L"";

	Port = (long)parts.GetPort();
	return S_OK;
}

STDMETHODIMP CvbWB::ucInternetCreateUrl(BSTR *URL)
{

	strFullURL.Empty();
	strFileName.Empty();
	strFileExtension.Empty();
	strFullURL				= L"";
	strFileName				= L"";
	strFileExtension		= L"";

	URL_COMPONENTS URLComponentsOut;
	ZeroMemory((LPVOID)&URLComponentsOut, sizeof(URLComponentsOut));
	URLComponentsOut.dwStructSize = sizeof(URLComponentsOut);
USES_CONVERSION;
	if(strScheme.Length() > 0)
	{
		URLComponentsOut.lpszScheme = OLE2T(strScheme);		// pointer to scheme name
		URLComponentsOut.dwSchemeLength = strScheme.Length();		// length of scheme name
	}
	URLComponentsOut.nScheme = (INTERNET_SCHEME)m_nScheme;			// pointer to scheme
	URLComponentsOut.nPort = (INTERNET_PORT)Port;					// pointer to port
	if(strHostName.Length() > 0)
	{
		URLComponentsOut.lpszHostName = OLE2T(strHostName);       // pointer to host name
		URLComponentsOut.dwHostNameLength = strHostName.Length();   // length of host name
	}
	if(strUserName.Length() > 0)
	{
		URLComponentsOut.lpszUserName = OLE2T(strUserName);       // pointer to user name
		URLComponentsOut.dwUserNameLength = strUserName.Length();   // length of user name
	}
	if(strPassword.Length() > 0)
	{
		URLComponentsOut.lpszPassword = OLE2T(strPassword);       // pointer to password
		URLComponentsOut.dwPasswordLength = strPassword.Length();   // length of password
	}
	if(strUrlPath.Length() > 0)
	{
		URLComponentsOut.lpszUrlPath = OLE2T(strUrlPath);        // pointer to URL-path
		URLComponentsOut.dwUrlPathLength = strUrlPath.Length();    // length of URL-path
    }
	if(strExtraInfo.Length() > 0)
	{
		URLComponentsOut.lpszExtraInfo = OLE2T(strExtraInfo);      // pointer to extra information (e.g. ?foo or #foo)
	    URLComponentsOut.dwExtraInfoLength = strExtraInfo.Length();  // length of extra information
	}
    TCHAR lpszUrl[INTERNET_MAX_PATH_LENGTH]; //Buffer
    DWORD dwUrlLength=INTERNET_MAX_PATH_LENGTH; //Len of buffer
	//MSDN
	//Converts all escape sequences (%xx) to their corresponding characters
	DWORD dwFlags = ICU_ESCAPE; //Create flags
	//Create
    BOOL bCreate = InternetCreateUrl(&URLComponentsOut, dwFlags, lpszUrl, &dwUrlLength);
	//If ok then copy to out param
	if (bCreate == TRUE)
	{
		ClearBSTRPtr(*URL);
		*URL = ::SysAllocStringLen(T2OLE(lpszUrl), dwUrlLength);
	}

	return S_OK;
}

STDMETHODIMP CvbWB::CancelFileDl(short UIDToCancel)
{
	if(m_arrDL.GetSize() > 0)
	{
		for(int i = 0; i < m_arrDL.GetSize() ; i++)
		{
			if( (m_arrDL[i]) && (m_arrDL[i]->IsDownloading() == true) )
			{
				//This should trigger a stop binding
				//which should notify the client
				m_arrDL[i]->CancelDL();
			}
		}
	}
	return S_OK;
}


STDMETHODIMP CvbWB::RegisterHTTPSprotocol(VARIANT_BOOL pVal)
{
	if( (pVal == VARIANT_TRUE) && (gb_IsHttpsRegistered == TRUE) )
	{
		m_StrErr_Tmp = (UINT)IDS_HTTPS_PROT_REGISTERED;
		return AtlReportError(CLSID_vbWB, m_StrErr_Tmp, IID_IvbWB,DISP_E_EXCEPTION);
	}
	
	//Get the current InternetSession
	CComPtr<IInternetSession> spSession;
	CoInternetGetSession(0, &spSession, 0);

	if(pVal == VARIANT_TRUE)
	{
		//Register
		MetaFactory::CreateInstance(CLSID_HttpSProtocol, &m_spCFHTTPS);
		spSession->RegisterNameSpace(m_spCFHTTPS, CLSID_NULL, L"https", 0, 0, 0);
		gb_IsHttpsRegistered = TRUE;
	}
	else
	{
		//Unregister
		spSession->UnregisterNameSpace(m_spCFHTTPS, L"https");
		m_spCFHTTPS.Release();
		gb_IsHttpsRegistered = FALSE;
	}
	return S_OK;
}

STDMETHODIMP CvbWB::RegisterHTTPprotocol(VARIANT_BOOL pVal)
{
	if( (pVal == VARIANT_TRUE) && (gb_IsHttpRegistered == TRUE) )
	{
		m_StrErr_Tmp = (UINT)IDS_HTTP_PROT_REGISTERED;
		return AtlReportError(CLSID_vbWB, m_StrErr_Tmp, IID_IvbWB,DISP_E_EXCEPTION);
	}
	
	//Get the current InternetSession
	CComPtr<IInternetSession> spSession;
	CoInternetGetSession(0, &spSession, 0);

	if(pVal == VARIANT_TRUE)
	{
		//Register
		MetaFactory::CreateInstance(CLSID_HttpProtocol, &m_spCFHTTP);
		spSession->RegisterNameSpace(m_spCFHTTP, CLSID_NULL, L"http", 0, 0, 0);
		gb_IsHttpRegistered = TRUE;
	}
	else
	{
		//Unregister
		spSession->UnregisterNameSpace(m_spCFHTTP, L"http");
		m_spCFHTTP.Release();
		gb_IsHttpRegistered = FALSE;
	}	
	return S_OK;
}

STDMETHODIMP CvbWB::DownloadUrlAsync( BSTR URL, BSTR SaveFileName, short *DLUID)
{
	CComPtr<IMoniker> pmk;
	CComPtr<IBindCtx> pbc;
	//CComPtr<IStream> pstm;
	IStream *pstm;
	HRESULT hr;
	
	//Unique id of this dl instance
	//used in combination with CancelFileDL to stop timed out dls,...
	m_dluid++;
	WBBSCBFileDL *pBSCB = new WBBSCBFileDL(m_dluid);
	if(!pBSCB)
	{
		m_StrErr_Tmp = (UINT)IDS_NO_DLMANAGER;
		return AtlReportError(CLSID_vbWB, m_StrErr_Tmp, IID_IvbWB,DISP_E_EXCEPTION);
	}

	//Pass uid to client to be used to cancel a dl
	*DLUID = m_dluid;
	pBSCB->InitByClient(this, URL, SaveFileName);

	USES_CONVERSION;
	//Create URLMonikor
    hr = CreateURLMoniker(NULL, OLE2W(URL), &pmk);
	if(FAILED(hr))
	{
		delete pBSCB;
		m_StrErr_Tmp = (UINT)IDS_NO_URLMONIKOR;
		return AtlReportError(CLSID_vbWB, m_StrErr_Tmp,IID_IvbWB,DISP_E_EXCEPTION);
	}
	
	//Create BindCtx and register BSCB at the same time, AddRef is called
    hr = CreateAsyncBindCtx(0, pBSCB, NULL, &pbc);
	if(FAILED(hr))
	{
		delete pBSCB;
		if(pmk) pmk.Release();
		m_StrErr_Tmp = (UINT)IDS_NO_ASYNCBINDCTX;
		return AtlReportError(CLSID_vbWB, m_StrErr_Tmp,IID_IvbWB,DISP_E_EXCEPTION);
	}
	
	//Bind stream to storage
	hr = pmk->BindToStorage(pbc,NULL,IID_IStream,(void**)&pstm);
	if(FAILED(hr))
	{
		if(pbc) pbc.Release();
		delete pBSCB;
		if(pmk) pmk.Release();
		m_StrErr_Tmp = (UINT)IDS_BINDTOSTORAGE_FAILED;
		return AtlReportError(CLSID_vbWB, m_StrErr_Tmp,IID_IvbWB,DISP_E_EXCEPTION);
	}
	//Add to Ptrarray
	m_arrDL.Add(pBSCB);
	return S_OK;

}

/* Another method to display SSL certificate
MSHTML uses InternetShowSecurityInfoByURL[A|W](LPCTSTR URL, HWND hwnd)-
an undocumented export from WinInet.dll. Remember __stdcall calling
convention and probably a BOOL return type.
the url as the first parameter, then the window handle second.
*/

STDMETHODIMP CvbWB::DisplayCertificateDialog(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
 		if (m_arrWB[i] && m_arrWB[i]->pOleCommandTarget)
 		{
			if(m_arrWB[i]->pOleCommandTarget)
			{
				m_arrWB[i]->pOleCommandTarget->Exec(&CGID_ShellDocView, SHDVID_SSLSTATUS, 0, NULL, NULL);
			}
			else if(m_arrWB[i]->pWebBrowser)
			{
				IOleCommandTarget *pct;
				if (SUCCEEDED(m_arrWB[i]->pWebBrowser->QueryInterface(IID_IOleCommandTarget, (void **) &pct)))
				{
				   pct->Exec(&CGID_ShellDocView, SHDVID_SSLSTATUS, 0, NULL, NULL);
				   pct->Release();
				}
			}
			else
			{
				m_StrErr_Tmp = (UINT)IDS_SSLCMD_FAILED;
				return AtlReportError(CLSID_vbWB, m_StrErr_Tmp, IID_IvbWB,DISP_E_EXCEPTION);
			}
 		}
 		else
		{
			m_StrErr_Tmp = (UINT)IDS_NO_BROWSEROBJ;
 			return AtlReportError(CLSID_vbWB, m_StrErr_Tmp, IID_IvbWB,DISP_E_EXCEPTION);
		}
	}
	else
 		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

//http://windowssdk.msdn.microsoft.com/en-us/library/ms671912.aspx
//http://www.delphidabbler.com/articles?article=14

//If content is greater than 256 characters, then a <base> tag must be present
//Sample
//Content:
//<html><body><base><h1>Stream Test</h1><p>This HTML content is being loaded from a stream.</body></html>
//BaseUrl:
//http://www.google.com
STDMETHODIMP CvbWB::LoadHTMLFromString( short wbUID, BSTR sContent, BSTR sBaseUrl)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
 		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
 		{
			HRESULT hr;
			CComPtr<IDispatch> spDisp;
			CComPtr<IBindCtx> pbc;
			CComQIPtr< IPersistMoniker > spPM;
			CLoadHTMLMoniker* cloader = new CLoadHTMLMoniker();
			//Setup data
			cloader->SetHTML(sContent, sBaseUrl);
			//Get document dispatch
			hr = m_arrWB[i]->pWebBrowser->get_Document( &spDisp );
			if( (SUCCEEDED(hr)) && (spDisp) )
			{
				//Get IHTMLDocument2
				CComQIPtr<IHTMLDocument2> spDoc( spDisp );
				if( (SUCCEEDED(hr)) && (spDoc) )
				{
					//QI for IPersistMoniker
					spPM = spDoc;
					if ( spPM )
					{
						//Create a dummy binctx
						hr = CreateBindCtx( 0, &pbc );
						//Load our moniker
						spPM->Load(TRUE, (IMoniker*)cloader, pbc, STGM_READ);
					}
				}
			}
			cloader->Release();
 		}
 		else
		{
			m_StrErr_Tmp = (UINT)IDS_NO_BROWSEROBJ;
 			return AtlReportError(CLSID_vbWB, m_StrErr_Tmp, IID_IvbWB,DISP_E_EXCEPTION);
		}
	}
	else
 		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::DrawWBThumbnailOnWnd(short wbUID, long WndHdc, long lX, long lY, long lW, long lH)
{
	HRESULT hret = S_FALSE;
	HDC hdc = (HDC)WndHdc;
	int i = FindWB(wbUID);
	if( (hdc) && (i > -1) ) 
	{
 		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
 		{
			CComPtr<IViewObject> spViewObject;
			CComPtr<IDispatch> spDisp;
			
			//Get the document dispatch
			m_arrWB[i]->pWebBrowser->get_Document(&spDisp);
			if(!spDisp) goto ReturnError;
			
			//Query for HtmlDocument2
			CComQIPtr<IHTMLDocument2> spDoc( spDisp );
			if(!spDoc) goto ReturnError;

			//Query for IViewObject
			hret = spDoc->QueryInterface(IID_IViewObject, 
						reinterpret_cast<void**>(&spViewObject));
			if( (SUCCEEDED(hret)) && (spViewObject) )
			{
				//Get the controls rect
 				RECT rWPos;
 				GetClientRect(&rWPos);
 				rWPos.right -= rWPos.left; //W
 				rWPos.bottom -= rWPos.top; //H
 				rWPos.left = 0;
 				rWPos.top = 0;

				CComPtr<IHTMLElement> spElem;
				CComPtr<IHTMLBodyElement> spBody;
				CComPtr<IHTMLStyle> spStyle;
				CComBSTR strStyle;
				hret = spDoc->get_body(&spElem);
				if(SUCCEEDED(hret) && spElem)
				{
					hret = spElem->QueryInterface(IID_IHTMLBodyElement, (void**)&spBody);
					if(SUCCEEDED(hret) && spBody)
					{
						// hide 3D border
						hret = spElem->get_style(&spStyle);
						if( (SUCCEEDED(hret)) && (spStyle) )
						{
							//Get the borderstyle so we can reset it
							spStyle->get_borderStyle(&strStyle);
							spStyle->put_borderStyle(CComBSTR(L"none"));
						}
						//Hide scrollbars
						spBody->put_scroll(CComBSTR(L"no"));
					}
				}

/*				
//We can use the IE_Server_Hwnd - much faster
//But no HDC is available if WB is hidden or covered
HWND iehwnd = m_arrWB[i]->GetIEServerHwnd();
HDC iehdc = NULL;
if(iehwnd)
{
	//::SendMessage(iehwnd, WM_PRINT, (WPARAM)iehdc, 0); 
	iehdc = ::GetDC(iehwnd);
	if(iehdc)
	{
		::StretchBlt(hdc, lX, lY, lW, lH, iehdc, 0, 0, 
						rWPos.right, 
						rWPos.bottom, SRCCOPY);
		return S_OK;
	}
}
*/
				//Second method

				//Basic pre-draw preaperation based on this controls pos
				HBITMAP hBitmap = CreateCompatibleBitmap(hdc, rWPos.right, rWPos.bottom);
				if(hBitmap == NULL) goto ReturnError;

				HDC hdcCompatible = ::CreateCompatibleDC(hdc);
				if(hBitmap == NULL) goto ReturnError;

				//If an error occurs and the selected object is not a region, the return value is NULL. Otherwise, it is HGDI_ERROR
				HBITMAP hBitmapOld = (HBITMAP)SelectObject(hdcCompatible, hBitmap);
				if( (hBitmap == NULL) || (hBitmap == HGDI_ERROR) ) goto ReturnError;
//Taken out to improve speed
//				//OLE_COLOR clrBackground = COLOR_WINDOW;
//				HBRUSH hbrBack = CreateSolidBrush(GetSysColor(COLOR_WINDOW));
//				FillRect(hdcCompatible, &rWPos, hbrBack);
//				DeleteObject(hbrBack);
				
				//Draw to our hdc
				hret = spViewObject->Draw(DVASPECT_CONTENT, -1, NULL, NULL, NULL, 
							hdcCompatible, (RECTL*)&rWPos, 
							(RECTL*)&rWPos, NULL, NULL);
				
				//Reset border and scrollbars
				if(spBody)
				{
					if( (spStyle) && (strStyle) )
					{
						spStyle->put_borderStyle(strStyle);
					}
					//auto display scrollbars
					spBody->put_scroll(CComBSTR(L"auto"));
				}

				//Check for errors
				switch (hret)
				{
				case S_OK:
					break;
				case OLE_E_BLANK:
					return AtlReportError(CLSID_vbWB, _T("OLE_E_BLANK") ,IID_IvbWB,DISP_E_EXCEPTION);
				case VIEW_E_DRAW:
					return AtlReportError(CLSID_vbWB, _T("VIEW_E_DRAW") ,IID_IvbWB,DISP_E_EXCEPTION);
				case DV_E_LINDEX:
					return AtlReportError(CLSID_vbWB, _T("DV_E_LINDEX") ,IID_IvbWB,DISP_E_EXCEPTION);
				case DV_E_DVASPECT:
					return AtlReportError(CLSID_vbWB, _T("DV_E_DVASPECT") ,IID_IvbWB,DISP_E_EXCEPTION);
				case OLE_E_INVALIDRECT:
					return AtlReportError(CLSID_vbWB, _T("OLE_E_INVALIDRECT") ,IID_IvbWB,DISP_E_EXCEPTION);
				default:
					{
						m_StrErr_Tmp = (UINT)IDS_DRAWOP_ABORTED;
						return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION);
					}
				}
				
				//Replaced with StretchBlt
				//::BitBlt(hdc, lX, lY, lW, lH,  hdcCompatible, 0, 0, SRCCOPY);
				::StretchBlt(hdc, lX, lY, lW, lH, hdcCompatible, 0, 0, 
								rWPos.right, 
								rWPos.bottom, SRCCOPY);
				::SelectObject(hdcCompatible, hBitmapOld); 
				::DeleteObject(hBitmap);
				::DeleteDC(hdcCompatible);
			}
			else
			{
				m_StrErr_Tmp = (UINT)IDS_NO_IVIEWOBJ;
				return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION);
			}
 		}
 		else
		{
			m_StrErr_Tmp = (UINT)IDS_NO_BROWSEROBJ;
 			return AtlReportError(CLSID_vbWB, m_StrErr_Tmp, IID_IvbWB,DISP_E_EXCEPTION);
		}
	}
	else
 		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;

ReturnError:
	m_StrErr_Tmp = (UINT)IDS_NO_ACTIVEDOC;
	return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION);
}

STDMETHODIMP CvbWB::get_WBPageTextSize(short wbUID, long *pVal)
{
	if(wbUID <= 0)
	{
		//First time this will return -1
		*pVal = (long)m_TextZoomVal;
		return S_OK;
	}
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			VARIANT vaZoomFactor;
			//ATLASSERT(V_VT(&vaZoomFactor) == VT_I4);
			if( !SUCCEEDED(m_arrWB[i]->pWebBrowser->ExecWB(OLECMDID_ZOOM, 
							OLECMDEXECOPT_DONTPROMPTUSER, NULL, &vaZoomFactor)) )
			{
				VariantClear(&vaZoomFactor);
				m_StrErr_Tmp = (UINT)IDS_NO_FONTSIZE;
				return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION);
			}
			*pVal = (long)V_I4(&vaZoomFactor);
			VariantClear(&vaZoomFactor);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	
	return S_OK;
}

STDMETHODIMP CvbWB::put_WBPageTextSize( short wbUID, long newVal)
{
	if( (newVal < 0) || (newVal > 4))
		return AtlReportError(CLSID_vbWB, _T("PageTextSize acceptable values 0 to 4.") ,IID_IvbWB,DISP_E_EXCEPTION);
	if(wbUID <= 0)
	{
		m_TextZoomVal = newVal;
		SetGlobalFlags(WB_FLAGS_PageZoom, (DWORD)m_TextZoomVal);
		return S_OK;
	}
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{
			VARIANT vaZoomFactor;					// input arguments
			VariantInit(&vaZoomFactor);
			V_VT(&vaZoomFactor) = VT_I4;
			V_I4(&vaZoomFactor) = newVal;
			HRESULT hr = m_arrWB[i]->pWebBrowser->ExecWB(OLECMDID_ZOOM, 
							OLECMDEXECOPT_DONTPROMPTUSER, &vaZoomFactor, NULL);
			VariantClear(&vaZoomFactor);
			if(FAILED(hr))
			{
				m_StrErr_Tmp = (UINT)IDS_NO_FONTSIZE_SET;
				return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION);
			}
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);

	return S_OK;
}

STDMETHODIMP CvbWB::ucResetFieldsToDefault(void)
{
	strScheme.Empty();
	strHostName.Empty();
	strUserName.Empty();
	strPassword.Empty();
	strUrlPath.Empty();
	strExtraInfo.Empty();
	strFullURL.Empty();
	strFileName.Empty();
	strFileExtension.Empty();
	strScheme				= L"";
	strHostName				= L"";
	strUserName				= L"";
	strPassword				= L"";
	strUrlPath				= L"";
	strExtraInfo			= L"";
	strFullURL				= L"";
	strFileName				= L"";
	strFileExtension		= L"";
	m_nScheme				= 0; //INTERNET_SCHEME_DEFAULT
	Port					= 0;
	return S_OK;
}

STDMETHODIMP CvbWB::SubclassWnd(long hwndWnd)
{
	if(hwndWnd <= 0 )
	{
		m_StrErr_Tmp = (UINT)IDS_NO_HWND_ERR;
		return AtlReportError(CLSID_vbWB, m_StrErr_Tmp,IID_IvbWB,DISP_E_EXCEPTION);
	}
	HWND hwnd = (HWND) hwndWnd;
	if( (hwnd) && (::IsWindow(hwnd)) )
	{
		CSubclassWnd *cSubclasser = new CSubclassWnd();
		if(cSubclasser)
		{
			if(cSubclasser->StartSubClassing(this, hwnd))
			{
				m_Subclassed.Add(cSubclasser);
			}
			else
			{
				delete cSubclasser;
				m_StrErr_Tmp = (UINT)IDS_NO_SUBCLASS_ERR;
				return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION);
			}
		}
	}
	else
	{
		m_StrErr_Tmp = (UINT)IDS_NO_HWND_ERR;
		return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION);
	}
	return S_OK;
}

STDMETHODIMP CvbWB::UnSubclassWnd(long hwndWnd)
{
	if(hwndWnd <= 0 )
	{
		m_StrErr_Tmp = (UINT)IDS_NO_HWND_ERR;
		return AtlReportError(CLSID_vbWB, m_StrErr_Tmp,IID_IvbWB,DISP_E_EXCEPTION);
	}
	HWND hwnd = (HWND) hwndWnd;
	if( (hwnd) && (::IsWindow(hwnd)) )
	{
		int isize = m_Subclassed.GetSize();
		for(int i = 0; i < isize; i++)
		{
			if( (m_Subclassed[i]) && (m_Subclassed[i]->IsSubClassedByThis(hwnd)) )
				break;
		}
		if(i >= isize )
		{
			m_StrErr_Tmp = (UINT)IDS_NO_HWND_SUBCLASSED;
			return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION);
		}
		m_Subclassed[i]->StopSubClassing(hwnd);
		delete m_Subclassed[i];
		m_Subclassed[i] = NULL;
		m_Subclassed.RemoveAt(i);
	}
	else
	{
		m_StrErr_Tmp = (UINT)IDS_NO_HWND_ERR;
		return AtlReportError(CLSID_vbWB, m_StrErr_Tmp,IID_IvbWB,DISP_E_EXCEPTION);
	}

	return S_OK;
}

STDMETHODIMP CvbWB::AddMessage(long hwndWnd, long lMsg)
{
	if(hwndWnd <= 0 )
	{
		m_StrErr_Tmp = (UINT)IDS_NO_HWND_ERR;
		return AtlReportError(CLSID_vbWB, m_StrErr_Tmp,IID_IvbWB,DISP_E_EXCEPTION);
	}
	HWND hwnd = (HWND) hwndWnd;
	if( (hwnd) && (::IsWindow(hwnd)) )
	{
		int isize = m_Subclassed.GetSize();
		for(int i = 0; i < isize; i++)
		{
			if( (m_Subclassed[i]) && (m_Subclassed[i]->IsSubClassedByThis(hwnd)) )
				break;
		}
		if(i >= isize )
		{
			m_StrErr_Tmp = (UINT)IDS_NO_HWND_SUBCLASSED;
			return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION);
		}
		m_Subclassed[i]->AddSubclassMsg((UINT)lMsg);
	}
	else
	{
		m_StrErr_Tmp = (UINT)IDS_NO_HWND_ERR;
		return AtlReportError(CLSID_vbWB, m_StrErr_Tmp,IID_IvbWB,DISP_E_EXCEPTION);
	}

	return S_OK;
}

STDMETHODIMP CvbWB::SetupShellAutoComplete(long hwndTarget, VARIANT_BOOL IsTargetComboBox, long lFlags)
{
	if(hwndTarget <= 0)
	{
		m_StrErr_Tmp = (UINT)IDS_NO_HWND_ERR;
		return AtlReportError(CLSID_vbWB, m_StrErr_Tmp,IID_IvbWB,DISP_E_EXCEPTION);;
	}
	
	if(CAutoCompleter::ShellAutoComplete((HWND)hwndTarget, VARIANTBOOLTOBOOL(IsTargetComboBox), (DWORD)lFlags))
		return S_OK;
	else
	{
		m_StrErr_Tmp = (UINT)IDS_SHAUTOCOMPLET_CALLFAILED;
		return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION);
	}
}

STDMETHODIMP CvbWB::SaveAsBitmap(short wbUID, BSTR BitmapName)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->pWebBrowser)
		{

			CComPtr<IViewObject> spViewObject;
			CComPtr<IDispatch> spDisp;
			
			//Get the document dispatch
			m_arrWB[i]->pWebBrowser->get_Document(&spDisp);
			if(!spDisp) goto ReturnError;
			
			//Query for HtmlDocument2
			CComQIPtr<IHTMLDocument2> spDoc( spDisp );
			if(!spDoc) goto ReturnError;

			//Query for HtmlDocument3
			CComQIPtr<IHTMLDocument3> spDoc3( spDisp );
			if(!spDoc3) goto ReturnError;

			//Query for IViewObject
			HRESULT hret = spDoc->QueryInterface(IID_IViewObject, 
						reinterpret_cast<void**>(&spViewObject));
			if( (SUCCEEDED(hret)) && (spViewObject) )
			{

				CComPtr<IHTMLElement> spElem;
				CComPtr<IHTMLBodyElement> spBody;
				CComPtr<IHTMLStyle> spStyle;
				CComPtr<IHTMLElement2> spBodyElem;
				CComBSTR strStyle;
				long bodyHeight = 0;
				long bodyWidth = 0;
				long rootHeight = 0;
				long rootWidth = 0;
				long height = 0;
				long width = 0;

				hret = spDoc->get_body(&spElem);
				if(SUCCEEDED(hret) && spElem)
				{
					// hide 3D border
					hret = spElem->get_style(&spStyle);
					if( (SUCCEEDED(hret)) && (spStyle) )
					{
						//Get the borderstyle so we can reset it
						spStyle->get_borderStyle(&strStyle);
						spStyle->put_borderStyle(CComBSTR("none"));
					}
					
					hret = spElem->QueryInterface(IID_IHTMLBodyElement, (void**)&spBody);
					if(SUCCEEDED(hret) && spBody)
						spBody->put_scroll(CComBSTR(L"no"));

					hret = spElem->QueryInterface(IID_IHTMLElement2, (void**)&spBodyElem);
					if(SUCCEEDED(hret) && spBodyElem)
					{
						spBodyElem->get_scrollHeight(&bodyHeight);
						spBodyElem->get_scrollWidth(&bodyWidth);
						spBodyElem.Release();
					}
					spElem.Release();
				}
//Do not use IHTMLDocument3
//If you want to save a partial image (just the viewing area)
				//Get IHTMLDocument3->IHTMLElement
				hret = spDoc3->get_documentElement(&spElem);
				if(SUCCEEDED(hret) && spElem)
				{
					hret = spElem->QueryInterface(IID_IHTMLElement2, (void**)&spBodyElem);
					if(SUCCEEDED(hret) && spBodyElem)
					{
						spBodyElem->get_scrollHeight(&rootHeight);
						spBodyElem->get_scrollWidth(&rootWidth);
					}
				}

				width = rootWidth > bodyWidth ? rootWidth : bodyWidth;
				height = rootHeight > bodyHeight ? rootHeight : bodyHeight;

				//Set rect
				RECT rWPos = { 0, 0, width, height };
				
				//Pre draw stuff
				HDC hdc = GetDC();
				HBITMAP hBitmap = CreateCompatibleBitmap(hdc, width, height);
				HDC hdcCompatible = ::CreateCompatibleDC(hdc);
				HBITMAP hBitmapOld = (HBITMAP)SelectObject(hdcCompatible, hBitmap);
				//This part can be commented out to improve speed.
				//OLE_COLOR clrBackground = COLOR_WINDOW;
				HBRUSH hbrBack = CreateSolidBrush(GetSysColor(COLOR_WINDOW));
				FillRect(hdcCompatible, &rWPos, hbrBack);
				DeleteObject(hbrBack);
				
				//Size browser
				//Here we can move WB to the end of ZOrder
				//and bring it back after we are done
				m_arrWB[i]->SetLocation(&rWPos);

				//Draw to our hdc
				//DVASPECT_DOCPRINT
				hret = spViewObject->Draw(DVASPECT_CONTENT, -1, NULL, NULL, NULL, 
							hdcCompatible, (RECTL*)&rWPos, 
							(RECTL*)&rWPos, NULL, NULL);

				//Resize back
 				GetClientRect(&rWPos);
 				rWPos.right -= rWPos.left; //W
 				rWPos.bottom -= rWPos.top; //H
 				rWPos.left = 0;
 				rWPos.top = 0;
				m_arrWB[i]->SetLocation(&rWPos);

				//Reset border style
				if( (spStyle) && (strStyle) )
				{
					spStyle->put_borderStyle(strStyle);
				}
				
				//Reset scrollbars
				if(spBody)
					spBody->put_scroll(CComBSTR(L"auto"));

				//Check for errors
				switch (hret)
				{
				case S_OK:
					break;
				case OLE_E_BLANK:
					return AtlReportError(CLSID_vbWB, _T("OLE_E_BLANK") ,IID_IvbWB,DISP_E_EXCEPTION);
				case VIEW_E_DRAW:
					return AtlReportError(CLSID_vbWB, _T("VIEW_E_DRAW") ,IID_IvbWB,DISP_E_EXCEPTION);
				case DV_E_LINDEX:
					return AtlReportError(CLSID_vbWB, _T("DV_E_LINDEX") ,IID_IvbWB,DISP_E_EXCEPTION);
				case DV_E_DVASPECT:
					return AtlReportError(CLSID_vbWB, _T("DV_E_DVASPECT") ,IID_IvbWB,DISP_E_EXCEPTION);
				case OLE_E_INVALIDRECT:
					return AtlReportError(CLSID_vbWB, _T("OLE_E_INVALIDRECT") ,IID_IvbWB,DISP_E_EXCEPTION);
				default:
					{
						m_StrErr_Tmp = (UINT)IDS_DRAWOP_ABORTED;
						return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION);
					}
				}
				
				//Create a bitmapinfo struct
				PBITMAPINFO bmpinfo = CreateBitmapInfoStruct(m_hWnd,hBitmap);
				USES_CONVERSION;
				//Save Bitmap
				BOOL bOk = CreateBMPFile(m_hWnd,OLE2T(BitmapName),bmpinfo,hBitmap,hdc);
				//Clean up
				::SelectObject(hdcCompatible, hBitmapOld); 
				::DeleteObject(hBitmap);
				::DeleteDC(hdcCompatible);
				ReleaseDC(hdc);

				//Did we succeed
				if (bOk == FALSE)
				{
					m_StrErr_Tmp = (UINT)IDS_UNABLE_TOSAVE_BMP;
					return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION);
				}
			}
			else
			{
				m_StrErr_Tmp = (UINT)IDS_NO_IVIEWOBJ;
				return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION);
			}
		}
 		else
		{
			m_StrErr_Tmp = (UINT)IDS_NO_BROWSEROBJ;
 			return AtlReportError(CLSID_vbWB, m_StrErr_Tmp,IID_IvbWB,DISP_E_EXCEPTION);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);

	return S_OK;

ReturnError:
	m_StrErr_Tmp = (UINT)IDS_NO_DOCOBJECT;
	return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION);
}

//If using POST, make sure that server supports it.

//POST
//sURL = http://www.site.com
//szData = _lang=EN&hm___tg= //Not including ? character

//GET
//sURL = http://www.site.com?_lang=EN&hm___tg=

//Replace spaces with + character

//in VB, WBPostData(url,"",id);
//in C++, BSTR str = ::SysAllocString(L""); WBPostData(url,str,id);
STDMETHODIMP CvbWB::WBPostData(BSTR sURL, BSTR sData, short *PostID)
{
	CComPtr<IMoniker> pmk;
	CComPtr<IBindCtx> pbc;
    LPSTREAM pstm = NULL;
    HRESULT hr;

	WBBSCBPost *pPost = new WBBSCBPost();
	if(!pPost)
	{
		m_StrErr_Tmp = (UINT)IDS_UNABLE_TOCREATE_CLASS;
		return AtlReportError(CLSID_vbWB, m_StrErr_Tmp,IID_IvbWB,DISP_E_EXCEPTION);
	}
	m_dluid++;
	USES_CONVERSION;
	
	if(::SysStringLen(sData) > 0)
		hr = pPost->InitPost(m_dluid, this, sURL, OLE2T(sData)); //Using POST
	else
		hr = pPost->InitPost(m_dluid, this, sURL, NULL); //Using GET

	if( FAILED(hr) )
	{
		delete pPost;
		m_StrErr_Tmp = (UINT)IDS_UNABLE_TOINIT_CLASS;
		return AtlReportError(CLSID_vbWB, m_StrErr_Tmp, IID_IvbWB,DISP_E_EXCEPTION);
	}
	
	//Create URLMonikor
    hr = CreateURLMoniker(NULL, OLE2W(sURL), &pmk);
	if(FAILED(hr))
	{
		delete pPost;
		m_StrErr_Tmp = (UINT)IDS_NO_URLMONIKOR;
		return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION);
	}
	
	//Create BindCtx and register BSCB at the same time
    hr = CreateAsyncBindCtx(0, pPost, NULL, &pbc);
	if(FAILED(hr))
	{
		delete pPost;
		if(pmk) pmk.Release();
		m_StrErr_Tmp = (UINT)IDS_NO_ASYNCBINDCTX;
		return AtlReportError(CLSID_vbWB, m_StrErr_Tmp,IID_IvbWB,DISP_E_EXCEPTION);
	}
	
	//Bind stream to storage
	hr = pmk->BindToStorage(pbc,NULL,IID_IStream,(void**)&pstm);
	if(FAILED(hr))
	{
		if(pbc) pbc.Release();
		delete pPost;
		if(pmk) pmk.Release();
		m_StrErr_Tmp = (UINT)IDS_BINDTOSTORAGE_FAILED;
		return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION);
	}

	*PostID = m_dluid;
	return S_OK;
}

STDMETHODIMP CvbWB::get_SourceOnDocComplete(short wbUID, VARIANT_BOOL *pVal)
{
	//Just return global flag
	if(wbUID <= 0)
	{
		*pVal = m_bSourceOnDocComplete;
		return S_OK;
	}
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->m_pWBEventDispatch)
		{
			
			if(m_arrWB[i]->m_pWBEventDispatch->m_bSendSourceOnDocComplete == true) 
				*pVal = VARIANT_TRUE;
			else
				*pVal = VARIANT_FALSE;
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::put_SourceOnDocComplete(short wbUID, VARIANT_BOOL newVal)
{
	if(wbUID <= 0)
	{
		m_bSourceOnDocComplete = newVal;
		SetGlobalFlags(WB_FLAGS_SendSourceOnDocComplete,m_bSourceOnDocComplete);
		return S_OK;
	}
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if (m_arrWB[i] && m_arrWB[i]->m_pWBEventDispatch)
		{
			m_arrWB[i]->m_pWBEventDispatch->m_bSendSourceOnDocComplete = VARIANTBOOLTObool(newVal);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

STDMETHODIMP CvbWB::OrganizeFavorites()
{
	HRESULT hr;
	CComPtr<IShellUIHelper> pShellUI = NULL;

	hr = CoCreateInstance(CLSID_ShellUIHelper, NULL, 
		CLSCTX_INPROC_SERVER, IID_IShellUIHelper, 
		reinterpret_cast<void **>(&pShellUI));

	if( (FAILED(hr)) || (!pShellUI) ) return S_FALSE;
/*
LanguageDialog
	Opens the Language Preference dialog box.
OrganizeFavorites
	Opens the Organize Favorites dialog box.
PrivacySettings
	Microsoft® Internet Explorer 6 and later. Opens the Privacy Preferences dialog box.
ProgramAccessAndDefaults
	Microsoft Windows® XP Service Pack 1 (SP1) and later. Opens the Set Program Access and Defaults dialog box.
*/
	pShellUI->ShowBrowserUI(CComBSTR(L"OrganizeFavorites"), NULL, NULL);
	//pShellUI->Release();

	return S_OK;
}

STDMETHODIMP CvbWB::ViewIEOptions(short wbUID)
{
	int i = FindWB(wbUID);
	if ( i > -1 ) 
	{
		if( (m_arrWB[i]) && (m_arrWB[i]->pOleCommandTarget) )
		{
			m_arrWB[i]->pOleCommandTarget->Exec(&WB_CGI_IWebBrowser,
									WB_MiscCommandTarget_Options ,
									OLECMDEXECOPT_DODEFAULT,NULL,NULL);
		}
	}
	else
		return AtlReportError(CLSID_vbWB, m_StrErr_WBNOTFOUND,IID_IvbWB,DISP_E_EXCEPTION);
	return S_OK;
}

BOOL CvbWB::RemoveHostFromArray(short uHostId)
{
	BOOL bRet = TRUE;
	int i = FindWB(uHostId);
	if ( i > -1 ) 
	{
		if(m_wbcurid == uHostId)
			m_wbcurid = 0;
		m_arrWB[i] = NULL;
		m_arrWB.RemoveAt(i);
	}
	else
		bRet = FALSE;
	return bRet;
}

STDMETHODIMP CvbWB::HookProcNCode(WINDOWSHOOK_TYPES lHookType, long *nCode)
{
	if(lHookType == WHT_CBT)
	{
		*nCode = (long)nCode_CBTProc;
	}
	else if(lHookType == WHT_MSGFILTER)
	{
		*nCode = (long)nCode_MessageProc;
	}
	else if(lHookType == WHT_SYSMSGFILTER)
	{
		*nCode = (long)nCode_SysMsgProc;
	}
	else
		*nCode = -1;
	return S_OK;
}

STDMETHODIMP CvbWB::SetupWindowsHook(WINDOWSHOOK_TYPES lHookType, long hwndTargetWnd, VARIANT_BOOL bStart, long *lUWMHookMsgID)
{
	BOOL bInstall = VARIANTBOOLTOBOOL(bStart);
	
	if( (bInstall == TRUE) && (wbhookdata[lHookType].bHookInstalled == FALSE) )
	{
		if(hwndTargetWnd == 0)
			wbhookdata[lHookType].hwndTarget = GetParent(); //Using parent wnd
		else
			wbhookdata[lHookType].hwndTarget = (HWND)hwndTargetWnd;

		wbhookdata[lHookType].hhook = SetWindowsHookEx( wbhookdata[lHookType].nType, 
			wbhookdata[lHookType].hkprc, 
			//_Module.GetModuleInstance(), GetCurrentThreadId());
			_Module.GetModuleInstance(), 0);
			//(HINSTANCE) NULL, GetCurrentThreadId());g
		//Check and send back hook msgid for the client to intercept
		if(wbhookdata[lHookType].hhook)
		{
			*lUWMHookMsgID = (long)wbhookdata[lHookType].uiHookMsgID;
			wbhookdata[lHookType].bHookInstalled = bInstall;
		}
		else
		{
			m_StrErr_Tmp = (UINT)IDS_FAILEDTOINSTALLHOOK;
			return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION);
		}
	}
	else if( (bInstall == FALSE) && (wbhookdata[lHookType].bHookInstalled == TRUE) )
	{
		if(wbhookdata[lHookType].hhook)
			UnhookWindowsHookEx(wbhookdata[lHookType].hhook);
		wbhookdata[lHookType].bHookInstalled = bInstall;
		wbhookdata[lHookType].hwndTarget = NULL;
	}

	return S_OK;
}

STDMETHODIMP CvbWB::SetupCustomAutoComplete(long hwndTarget,VARIANT_BOOL IsTargetComboBox , long lCustomAutoCompleteFlags, VARIANT * varStringArray)
{
	if( varStringArray->vt != (VT_ARRAY | VT_BSTR) )
	{
		return AtlReportError(CLSID_vbWB, _T("varStringArray parameter must be a valid string array") ,IID_IvbWB,DISP_E_EXCEPTION);
	}

	long lBound = 0;
	long uBound = 0;
	HRESULT hresult;
	SAFEARRAY * psa = varStringArray->parray;
	
	hresult = SafeArrayGetLBound(psa, 1, &lBound);
	if(FAILED(hresult))
	{
		return AtlReportError(CLSID_vbWB, _T("varStringArray parameter can not be empty!") ,IID_IvbWB,DISP_E_EXCEPTION);
	}

	hresult = SafeArrayGetUBound(psa, 1, &uBound);
	if( (FAILED(hresult)) || (uBound == 0) )
	{
		return AtlReportError(CLSID_vbWB, _T("varStringArray parameter can not be empty!") ,IID_IvbWB,DISP_E_EXCEPTION);
	}

	BSTR HUGEP *pbstr;

	CAutoCompleter *cac = new CAutoCompleter();

	if(!cac)
	{
		m_StrErr_Tmp = (UINT)IDS_FAILEDTOCREATEAC;
		return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION); //5th override
	}

	//Get a pointer to the elements of the array.
	hresult = SafeArrayAccessData(psa, (void **)&pbstr);
	if(FAILED(hresult))
	{
		delete cac;
		return AtlReportError(CLSID_vbWB, _T("Unable to access safearray descriptor.") ,IID_IvbWB,DISP_E_EXCEPTION);
	}

	for(int i = lBound; i <= uBound; i++)
	{
		if(pbstr[i])
		{
			cac->AddItem(pbstr[i], ::SysStringLen(pbstr[i]) ); //add to class
		}
	}
	SafeArrayUnaccessData(psa);

	if(cac->GetItemCount() > 0)
	{
		HWND hwnd = (HWND)hwndTarget;
		BOOL iscombo = VARIANTBOOLTOBOOL(IsTargetComboBox);
		BOOL bRet = cac->Bind(hwnd, iscombo, (DWORD)lCustomAutoCompleteFlags, NULL);
		if(!bRet)
		{
			delete cac;
			m_StrErr_Tmp = (UINT)IDS_ACBINDINGFAILED;
			return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION); 
		}
		//Add to our array of autocompleters
		//to add strings, enable, or disable
		m_AutoCompleters.Add(cac);
	}
	else
	{
		delete cac;
		m_StrErr_Tmp = (UINT)IDS_ACLISTEMPTY;
		return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION);
	}

	return S_OK;
}

STDMETHODIMP CvbWB::CustomAutoCompleteAddString(long hwndTarget,VARIANT_BOOL IsTargetComboBox , BSTR strItem)
{
	BOOL iscombo = VARIANTBOOLTOBOOL(IsTargetComboBox);
	HWND hwnd = (HWND)hwndTarget;

	int iSize = m_AutoCompleters.GetSize();
	if(iSize == 0)
	{
		m_StrErr_Tmp = (UINT)IDS_EMPTYACARRAY;
		return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION);
	}

	for(int i = 0; i < iSize ; i++)
	{
		if(iscombo)
		{
			if(m_AutoCompleters[i]->GetParentEditHwnd() == hwnd)
			{
				m_AutoCompleters[i]->AddItem(strItem, ::SysStringLen(strItem));
				return S_OK;
			}
		}
		else if(m_AutoCompleters[i]->GetEditHwnd() == hwnd)
		{
			m_AutoCompleters[i]->AddItem(strItem, ::SysStringLen(strItem));
			return S_OK;
		}
	}
	//Nothing
	m_StrErr_Tmp = (UINT)IDS_UNABLETOFINDAC;
	return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION);
}

STDMETHODIMP CvbWB::CustomAutoCompleteEnable(long hwndTarget, VARIANT_BOOL IsTargetComboBox ,VARIANT_BOOL bEnable)
{
	BOOL iscombo = VARIANTBOOLTOBOOL(IsTargetComboBox);
	BOOL enable = VARIANTBOOLTOBOOL(bEnable);
	HWND hwnd = (HWND)hwndTarget;

	int iSize = m_AutoCompleters.GetSize();
	if(iSize == 0)
	{
		m_StrErr_Tmp = (UINT)IDS_EMPTYACARRAY;
		return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION);
	}

	for(int i = 0; i < iSize ; i++)
	{
		if(iscombo)
		{
			if(m_AutoCompleters[i]->GetParentEditHwnd() == hwnd)
			{
				if(enable)
					m_AutoCompleters[i]->Enable();
				else
					m_AutoCompleters[i]->Disable();
				return S_OK;
			}
		}
		else if(m_AutoCompleters[i]->GetEditHwnd() == hwnd)
		{
			if(enable)
				m_AutoCompleters[i]->Enable();
			else
				m_AutoCompleters[i]->Disable();
			return S_OK;
		}
	}
	//Nothing
	m_StrErr_Tmp = (UINT)IDS_UNABLETOFINDAC;
	return AtlReportError(CLSID_vbWB, m_StrErr_Tmp ,IID_IvbWB,DISP_E_EXCEPTION);
}

//	LPTSTR buf = (LPTSTR)malloc((UINT)(MAX_PATH+1 * sizeof(TCHAR)));
//	if(buf)
//	{
//		buf[MAX_PATH] = _T('\0');
//	CRegKey reg;
//	DWORD dwcount = MAX_PATH;
//	reg.Open(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Internet Explorer\\Main"));
//	reg.QueryValue(buf ,_T("Disable Script Debugger"), &dwcount);
//	if( (buf[0] == _T('n')) || (buf[0] == _T('N')) )
//		reg.SetValue( _T("yes"), _T("Disable Script Debugger"));
//		free(buf);
//	}

STDMETHODIMP CvbWB::QueryIERegistryOption( long IeRegistryOptionsFlag, VARIANT * varBuffer)
{
	LONG hret = 1; //Assume failure
	CRegKey reg;
	DWORD dwcount = MAX_PATH; //In return from QueryValue will contain the length data copied

	//Attempt to open registery key
	hret = reg.Open(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Internet Explorer\\Main"));
	//Check for suceess
	if(hret != ERROR_SUCCESS)
		return AtlReportError(CLSID_vbWB, _T("Unable to open Software\\Microsoft\\Internet Explorer\\Main key.") ,IID_IvbWB,DISP_E_EXCEPTION);

	LPTSTR pbuf = (LPTSTR)new TCHAR[MAX_PATH + 1];
	if(pbuf)
	{
		pbuf[0] = _T('\0');
		pbuf[MAX_PATH] = _T('\0');
	}
	else
		return AtlReportError(CLSID_vbWB, _T("Unable to allocate a buffer.") ,IID_IvbWB,DISP_E_EXCEPTION);

	CComBSTR sRet;
	USES_CONVERSION;

	switch(IeRegistryOptionsFlag)
	{
	case DISABLE_SCRIPT_DEBUGGER:
		{
			hret = reg.QueryValue(pbuf ,_T("Disable Script Debugger"), &dwcount);
		}
		break;
	case ERROR_DLG_DISPLAYED_ON_EVERY_ERROR:
		{
			hret = reg.QueryValue(pbuf ,_T("Error Dlg Displayed On Every Error"), &dwcount);
		}
		break;
	case PLAY_ANIMATIONS:
		{
			hret = reg.QueryValue(pbuf ,_T("Play_Animations"), &dwcount);
		}
		break;
	case PLAY_BACKGROUND_SOUNDS:
		{
			hret = reg.QueryValue(pbuf ,_T("Play_Background_Sounds"), &dwcount);
		}
		break;
	case DISPLAY_INLINE_VIDEOS:
		{
			hret = reg.QueryValue(pbuf ,_T("Display Inline Videos"), &dwcount);
		}
		break;
	case DISPLAY_INLINE_IMAGES:
		{
			hret = reg.QueryValue(pbuf ,_T("Display Inline Images"), &dwcount);
		}
		break;
	case FORMSUGGEST_PW_ASK:
		{
			hret = reg.QueryValue(pbuf ,_T("FormSuggest PW Ask"), &dwcount);
		}
		break;
	case USE_FORMSUGGEST:
		{
			hret = reg.QueryValue(pbuf ,_T("Use FormSuggest"), &dwcount);
		}
		break;
	case USE_SEARCH_ASST:
		{
			hret = reg.QueryValue(pbuf ,_T("Use Search Asst"), &dwcount);
		}
		break;
	default:
		break;
	}
	
	//Check
	if( (hret == ERROR_SUCCESS) && (dwcount > 0) ) // && (pbuf[0] != _T('\0')) )
	{
		//Must be vt == VT_EMPTY
		varBuffer->vt = VT_BSTR;
		sRet = T2BSTR(pbuf);
		varBuffer->bstrVal = sRet.Copy();
		delete [] pbuf;
	}
	else
	{
		//Reset type
		varBuffer->vt = VT_EMPTY;
		delete [] pbuf;
		return AtlReportError(CLSID_vbWB, _T("Unable to query for the value.") ,IID_IvbWB,DISP_E_EXCEPTION);
	}
	return S_OK;
}

//Assume varBuffer is initialized
STDMETHODIMP CvbWB::SetIERegistryOption( long IeRegistryOptionsFlag, VARIANT * varBuffer)
{
	LONG hret = 1; //Assume failure
	CRegKey reg;
	DWORD dwcount = MAX_PATH;

	//Attempt to open registery key
	hret = reg.Open(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Internet Explorer\\Main"));
	//Check for suceess
	if(hret != ERROR_SUCCESS)
		return AtlReportError(CLSID_vbWB, _T("Unable to open Software\\Microsoft\\Internet Explorer\\Main key.") ,IID_IvbWB,DISP_E_EXCEPTION);

	CTmpBuffer buf;
	if(buf.AppendBSTR(varBuffer->bstrVal, ::SysStringLen(varBuffer->bstrVal)) == 0)
		return AtlReportError(CLSID_vbWB, _T("Unable to allocate required buffer.") ,IID_IvbWB,DISP_E_EXCEPTION);

	switch(IeRegistryOptionsFlag)
	{
	case DISABLE_SCRIPT_DEBUGGER:
		{
			hret = reg.SetValue( buf, _T("Disable Script Debugger"));
		}
		break;
	case ERROR_DLG_DISPLAYED_ON_EVERY_ERROR:
		{
			hret = reg.SetValue( buf, _T("Error Dlg Displayed On Every Error"));
		}
		break;
	case PLAY_ANIMATIONS:
		{
			hret = reg.SetValue( buf, _T("Play_Animations"));
		}
		break;
	case PLAY_BACKGROUND_SOUNDS:
		{
			hret = reg.SetValue( buf, _T("Play_Background_Sounds"));
		}
		break;
	case DISPLAY_INLINE_VIDEOS:
		{
			hret = reg.SetValue( buf, _T("Display Inline Videos"));
		}
		break;
	case DISPLAY_INLINE_IMAGES:
		{
			hret = reg.SetValue( buf, _T("Display Inline Images"));
		}
		break;
	case FORMSUGGEST_PW_ASK:
		{
			hret = reg.SetValue( buf, _T("FormSuggest PW Ask"));
		}
		break;
	case USE_FORMSUGGEST:
		{
			hret = reg.SetValue( buf, _T("Use FormSuggest"));
		}
		break;
	case USE_SEARCH_ASST:
		{
			hret = reg.SetValue( buf, _T("Use Search Asst"));
		}
		break;
	default:
		break;
	}

	if(hret != ERROR_SUCCESS)
		return AtlReportError(CLSID_vbWB, _T("Unable to set registry value.") ,IID_IvbWB,DISP_E_EXCEPTION);

	return S_OK;
}

STDMETHODIMP CvbWB::DecodeMime(BSTR strToDecode, BSTR *strDecoded)
{
	USES_CONVERSION;
	ClearBSTRPtr(*strDecoded);
	*strDecoded = ::SysAllocString(T2BSTR(DecodeHtml(OLE2T(strToDecode))));
	return S_OK;
}

STDMETHODIMP CvbWB::DeleteIEFiles(DELETE_IE_FILES_FLAGS enumWhichFiles)
{
	HRESULT hr = S_FALSE;
	switch (enumWhichFiles)
	{
		case DELETE_IE_CACHE:
			{
				hr = Delete_IECache();
			}
			break;
		case DELETE_IE_COOKIES:
			{
				hr = Delete_IECookies();
			}
			break;
		case DELETE_IE_HISTORY:
			{
				hr = Delete_IEHistory();
			}
			break;
		default: //Unknown value
			break;
	}
	if(SUCCEEDED(hr))
		return hr;
	else
		return AtlReportError(CLSID_vbWB, _T("Unable to Delete IE Files.") ,IID_IvbWB,DISP_E_EXCEPTION);
}

////////////////////////////////////////////////////////////////////////////////////////////////
//	HOOK CALLBACK IMPLEMENTATION
////////////////////////////////////////////////////////////////////////////////////////////////

static LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode < 0)  // do not process message 
        return CallNextHookEx(wbhookdata[H_KEYBOARD].hhook, nCode, wParam, lParam);

	if( (nCode == HC_ACTION) && (lParam) 
		&& (wbhookdata[H_KEYBOARD].hwndTarget) 
		&& (::IsWindow(wbhookdata[H_KEYBOARD].hwndTarget)) )
	{
		DWORD dwresult = 0;
		//UINT umsg = WM_KEYDOWN;
		////wParam = virtual-key code
		//// Reference: WM_KEYDOWN on MSDN
		//if (lParam & 0x80000000) // check bit 31 for up/down
		//{
		//	umsg = WM_KEYUP;
		//}
		//else
		//{
		//	if (lParam & 0x40000000) // check bit 30 for previous up/down
		//		umsg = WM_KEY_REPEAT; // It was pressed down before this key-down event, so it's a key-repeat for sure
		//	else
		//		umsg = WM_KEYDOWN;
		//}
		//always returns 1
		::SendMessageTimeout(wbhookdata[H_KEYBOARD].hwndTarget,
			wbhookdata[H_KEYBOARD].uiHookMsgID , //sending our own registered message 
			wParam, lParam, SMTO_ABORTIFHUNG, 500, &dwresult);
		//Check dwresult, return value from client, default 0, allow hook to continue
		long lret = (long)dwresult;
		//if return value is greater than 0 then cancel
		if(lret > 0) return lret;
//TCHAR tmp[50];
//#ifdef UNICODE
//	_ltow(lret, tmp, 10);
//#else
//	_ltoa(lret, tmp, 10);
//#endif
//MessageBox(GetDesktopWindow(), tmp, _T("KeyboardProc RETURN VALUE"),MB_OK);
	}

	//Default processing
    return CallNextHookEx(wbhookdata[H_KEYBOARD].hhook, nCode, wParam, lParam);
}

static LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode < 0)  // do not process message 
        return CallNextHookEx(wbhookdata[H_MOUSE].hhook, nCode, wParam, lParam);
	
	//LPMOUSEHOOKSTRUCT pMsg = (LPMOUSEHOOKSTRUCT)lParam;
	//wParam one of WM_xxx(LBUTTONDOWN, LBUTTONDOWN, MOUSEMOVE, NCMOUSEMOVE, MOUSEWHEEL,  ...)
	if( (nCode == HC_ACTION) && (lParam) 
		&& (wbhookdata[H_MOUSE].hwndTarget) 
		&& (::IsWindow(wbhookdata[H_MOUSE].hwndTarget)) )
	{
		DWORD dwresult = 0;
		::SendMessageTimeout(wbhookdata[H_MOUSE].hwndTarget, wbhookdata[H_MOUSE].uiHookMsgID , 
			wParam, lParam, SMTO_ABORTIFHUNG, 500, &dwresult);
		long lret = (long)dwresult;
		if(lret > 0) return lret;
	}
	
	//Default processingfgt
    return CallNextHookEx(wbhookdata[H_MOUSE].hhook, nCode, wParam, lParam);
}

static LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode < 0)  // do not process message 
        return CallNextHookEx(wbhookdata[H_KEYBOARD_LL].hhook, nCode, wParam, lParam);
	
	//LPKBDLLHOOKSTRUCT pMsg = (LPKBDLLHOOKSTRUCT)lParam;
	//wParam one of WM_KEYDOWN, WM_KEYUP, WM_SYSKEYDOWN, or WM_SYSKEYUP
	if( (nCode == HC_ACTION) && (lParam) 
		&& (wbhookdata[H_KEYBOARD_LL].hwndTarget) 
		&& (::IsWindow(wbhookdata[H_KEYBOARD_LL].hwndTarget)) )
	{
		DWORD dwresult = 0;
		
		::SendMessageTimeout(wbhookdata[H_KEYBOARD_LL].hwndTarget, 
			wbhookdata[H_KEYBOARD_LL].uiHookMsgID , 
			wParam, lParam, SMTO_ABORTIFHUNG, 500, &dwresult);
		long lret = (long)dwresult;
		if(lret > 0) return lret;
	}
	
	//Default processinghgok
    return CallNextHookEx(wbhookdata[H_KEYBOARD_LL].hhook, nCode, wParam, lParam);
}

static LRESULT CALLBACK CallWndProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode < 0)  // do not process message 
        return CallNextHookEx(wbhookdata[H_CALLWNDPROC].hhook, nCode, wParam, lParam);
	
	//wParam: Specifies whether the message was sent by the current thread.
	//If the message was sent by the current thread, it is nonzero; otherwise, it is zero
	//LPCWPSTRUCT lpcp = (LPCWPSTRUCT)wParam
	if( (nCode == HC_ACTION) && (lParam) 
		&& (wbhookdata[H_CALLWNDPROC].hwndTarget) 
		&& (::IsWindow(wbhookdata[H_CALLWNDPROC].hwndTarget)) )
	{
		DWORD dwresult = 0;
		::SendMessageTimeout(wbhookdata[H_CALLWNDPROC].hwndTarget,
			wbhookdata[H_CALLWNDPROC].uiHookMsgID , 
			wParam, lParam, SMTO_ABORTIFHUNG, 500, &dwresult);
		long lret = (long)dwresult;
		if(lret > 0) return lret;
	}
	
	//Default processing
    return CallNextHookEx(wbhookdata[H_CALLWNDPROC].hhook, nCode, wParam, lParam);
}

static LRESULT CALLBACK CBTProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode < 0)  // do not process message 
        return CallNextHookEx(wbhookdata[H_CBT].hhook, nCode, wParam, lParam);
	
	if( (nCode) && (lParam) 
		&& (wbhookdata[H_CBT].hwndTarget) 
		&& (::IsWindow(wbhookdata[H_CBT].hwndTarget)) )
	{
		DWORD dwresult = 0;
		nCode_CBTProc = nCode;
		//nCode
//HCBT_ACTIVATE
//HCBT_CLICKSKIPPED
//HCBT_CREATEWND
//HCBT_DESTROYWND
//HCBT_KEYSKIPPED
//HCBT_MINMAX
//HCBT_MOVESIZE
//HCBT_QS
//HCBT_SETFOCUS
//HCBT_SYSCOMMAND
		//lParam and wParam depend on nCode
		::SendMessageTimeout(wbhookdata[H_CBT].hwndTarget, 
			wbhookdata[H_CBT].uiHookMsgID , 
			wParam, lParam, SMTO_ABORTIFHUNG, 500, &dwresult);
		long lret = (long)dwresult;
		if(lret > 0) return lret;
	}
	
	//Default processing
    return CallNextHookEx(wbhookdata[H_CBT].hhook, nCode, wParam, lParam);
}

static LRESULT CALLBACK GetMsgProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode < 0)  // do not process message 
        return CallNextHookEx(wbhookdata[H_GETMESSAGE].hhook, nCode, wParam, lParam);
	
	//LPMSG msg = (LPMSG)lParam
	//wParam = PM_NOREMOVE or PM_REMOVE
	if( (nCode == HC_ACTION) && (lParam) 
		&& (wbhookdata[H_GETMESSAGE].hwndTarget) 
		&& (::IsWindow(wbhookdata[H_GETMESSAGE].hwndTarget)) )
	{
		DWORD dwresult = 0;
		::SendMessageTimeout(wbhookdata[H_GETMESSAGE].hwndTarget,
			wbhookdata[H_GETMESSAGE].uiHookMsgID , 
			wParam, lParam, SMTO_ABORTIFHUNG, 500, &dwresult);
		long lret = (long)dwresult;
		if(lret > 0) return lret;
	}
	
	//Default processing
    return CallNextHookEx(wbhookdata[H_GETMESSAGE].hhook, nCode, wParam, lParam);
}

static LRESULT CALLBACK MessageProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode < 0)  // do not process message 
        return CallNextHookEx(wbhookdata[H_MSGFILTER].hhook, nCode, wParam, lParam);
	
	if( (nCode) && (lParam) 
		&& (wbhookdata[H_MSGFILTER].hwndTarget) 
		&& (::IsWindow(wbhookdata[H_MSGFILTER].hwndTarget)) )
	{
		DWORD dwresult = 0;
		nCode_MessageProc = nCode;
		//nCode
//MSGF_DDEMGR
//MSGF_DIALOGBOX
//MSGF_MENU
//MSGF_SCROLLBAR
		//LPMSG msg = (LPMSG)lParam;
		//wParam is not used
		::SendMessageTimeout(wbhookdata[H_MSGFILTER].hwndTarget,
			wbhookdata[H_MSGFILTER].uiHookMsgID , 
			wParam, lParam, SMTO_ABORTIFHUNG, 500, &dwresult);
		long lret = (long)dwresult;
		if(lret > 0) return lret;
	}
	return CallNextHookEx(wbhookdata[H_MSGFILTER].hhook, nCode, wParam, lParam);
}

static LRESULT CALLBACK LowLevelMouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode < 0)  // do not process message 
        return CallNextHookEx(wbhookdata[H_MOUSE_LL].hhook, nCode, wParam, lParam);
	
	if( (nCode == HC_ACTION) && (lParam) 
		&& (wbhookdata[H_MOUSE_LL].hwndTarget) 
		&& (::IsWindow(wbhookdata[H_MOUSE_LL].hwndTarget)) )
	{
		DWORD dwresult = 0;
		//wParam, one of WM_LBUTTONDOWN, WM_LBUTTONUP, WM_MOUSEMOVE,
		//WM_MOUSEWHEEL, WM_RBUTTONDOWN, or WM_RBUTTONUP.
		//LPMSLLHOOKSTRUCT msg = (LPMSLLHOOKSTRUCT)lParam
		::SendMessageTimeout(wbhookdata[H_MOUSE_LL].hwndTarget,
			wbhookdata[H_MOUSE_LL].uiHookMsgID , 
			wParam, lParam, SMTO_ABORTIFHUNG, 500, &dwresult);
		long lret = (long)dwresult;
		if(lret > 0) return lret;
	}
	return CallNextHookEx(wbhookdata[H_MOUSE_LL].hhook, nCode, wParam, lParam);
}

static LRESULT CALLBACK ForegroundIdleProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode < 0)  // do not process message 
        return CallNextHookEx(wbhookdata[H_GETMESSAGE].hhook, nCode, wParam, lParam);
	
	if( (nCode == HC_ACTION) && (lParam) 
		&& (wbhookdata[H_FOREGROUNDIDLE].hwndTarget) 
		&& (::IsWindow(wbhookdata[H_FOREGROUNDIDLE].hwndTarget)) )
	{
		DWORD dwresult = 0;
		//wParam and lParam are not used
		::SendMessageTimeout(wbhookdata[H_FOREGROUNDIDLE].hwndTarget,
			wbhookdata[H_FOREGROUNDIDLE].uiHookMsgID , 
			wParam, lParam, SMTO_ABORTIFHUNG, 500, &dwresult);
		long lret = (long)dwresult;
		if(lret > 0) return lret;
	}
	return CallNextHookEx(wbhookdata[H_FOREGROUNDIDLE].hhook, nCode, wParam, lParam);
}

static LRESULT CALLBACK CallWndRetProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode < 0)  // do not process message 
        return CallNextHookEx(wbhookdata[H_CALLWNDPROCRET].hhook, nCode, wParam, lParam);
	
	if( (nCode == HC_ACTION) && (lParam) 
		&& (wbhookdata[H_CALLWNDPROCRET].hwndTarget) 
		&& (::IsWindow(wbhookdata[H_CALLWNDPROCRET].hwndTarget)) )
	{
		DWORD dwresult = 0;
		//wParam, Specifies whether the message is sent by the current process.
		//If the message is sent by the current process, it is nonzero; otherwise, it is NULL.
		//LPCWPRETSTRUCT msg = (LPCWPRETSTRUCT)lParam;
		::SendMessageTimeout(wbhookdata[H_CALLWNDPROCRET].hwndTarget,
			wbhookdata[H_CALLWNDPROCRET].uiHookMsgID , 
			wParam, lParam, SMTO_ABORTIFHUNG, 500, &dwresult);
		long lret = (long)dwresult;
		if(lret > 0) return lret;
	}
	return CallNextHookEx(wbhookdata[H_CALLWNDPROCRET].hhook, nCode, wParam, lParam);
}

static LRESULT CALLBACK SysMsgProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode < 0)  // do not process message 
        return CallNextHookEx(wbhookdata[H_SYSMSGFILTER].hhook, nCode, wParam, lParam);
	
	if( (nCode) && (lParam) 
		&& (wbhookdata[H_SYSMSGFILTER].hwndTarget) 
		&& (::IsWindow(wbhookdata[H_SYSMSGFILTER].hwndTarget)) )
	{
		DWORD dwresult = 0;
		nCode_SysMsgProc = nCode;
		//nCode
//MSGF_DIALOGBOX
//MSGF_MENU
//MSGF_SCROLLBAR
		//wParam is not used
		//LPMSG msg = (LPMSG)lParam
		::SendMessageTimeout(wbhookdata[H_SYSMSGFILTER].hwndTarget,
			wbhookdata[H_SYSMSGFILTER].uiHookMsgID , 
			wParam, lParam, SMTO_ABORTIFHUNG, 500, &dwresult);
		long lret = (long)dwresult;
		if(lret > 0) return lret;
	}
	return CallNextHookEx(wbhookdata[H_SYSMSGFILTER].hhook, nCode, wParam, lParam);
}

//////////////////////////////////////////////////////////////////////
// CSubclassWnd
//////////////////////////////////////////////////////////////////////
CSubclassWnd::~CSubclassWnd()
{
	if( (m_HwndSubclassed) && (::IsWindow(m_HwndSubclassed)) )
	{
		UnsubclassWindow();
	}
}

LRESULT CALLBACK CSubclassWnd::MyWindowProc
    (HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	int iSize = 0;
    // a thunk substitutes 'this' pointer for HWND parameter on the stack
    CSubclassWnd* pThis = static_cast<CSubclassWnd*>(reinterpret_cast<BaseClass*>(hWnd));
	iSize = pThis->m_Msgs.GetSize();
	UINT utmsg = 0;
	//Recurse through our list of msgs added using AddSubclassMsg method
	//Fire an event if a match is found
	for( int i = 0; i < iSize; i++)
	{
		utmsg = static_cast<UINT>(pThis->m_Msgs[i]);
		if(utmsg == uMsg)
		{
			//Prepare to fire event
			VARIANT_BOOL bHandled = VARIANT_FALSE; //Default
			long lRet = 0; //Default
			pThis->m_EventObj->Fire_OnWMMessage((long)hWnd, (long)uMsg, 
				(long)wParam, (long)lParam, &lRet, &bHandled);
			if(bHandled == VARIANT_TRUE)
				return lRet;
		}
	}
    // forward to original proc if not handled
    return BaseClass::WindowProc(hWnd, uMsg, wParam, lParam);
}

BOOL CSubclassWnd::StartSubClassing(CvbWB *cpHost, HWND HwndSubclassed)
{
	//Initially
	BOOL hr = FALSE;

	m_EventObj = cpHost;
	m_HwndSubclassed = HwndSubclassed;
	if( (m_HwndSubclassed) && (::IsWindow(m_HwndSubclassed)) )
	{
		//The subclassed window now uses CWindowImpl::WindowProc.
		//The original window procedure is saved in m_pfnSuperWindowProc.
		hr = SubclassWindow(m_HwndSubclassed);
	}
	//TRUE or FALSE;
	return hr;
}

BOOL CSubclassWnd::StopSubClassing(HWND HwndSubclassed)
{
	BOOL hr = FALSE;
	
	if( (m_HwndSubclassed == HwndSubclassed) && (::IsWindow(m_HwndSubclassed)) )
	{
		//The handle to the window previously subclassed.
		HWND hwnd = UnsubclassWindow();
		if(m_HwndSubclassed == hwnd)
		{
			hr = TRUE;
		}
	}
	
	//Either case
	m_Msgs.RemoveAll();
	m_EventObj = NULL;
	m_HwndSubclassed = NULL;

	return hr;
}

BOOL CSubclassWnd::IsSubClassedByThis(HWND HwndSubclassed)
{
	return (m_HwndSubclassed == HwndSubclassed) ? TRUE : FALSE;
}

BOOL CSubclassWnd::AddSubclassMsg(UINT uMsg)
{
	return m_Msgs.Add(uMsg);
}
//////////////////////////////////////////////////////////////////////
// Construction/Destruction IWB
//////////////////////////////////////////////////////////////////////

IWB::IWB(CvbWB *EventsPtr)
{
    // Setup member variables
    m_dwRefCount = 1; //So we don't delete this obj by mistake
	m_EventsPtr = EventsPtr;
	//Will be set after this call
	m_hwndParent = NULL;
	
	m_hwndShellEmbedding = NULL;
	m_hwndShellDocObjView = NULL;
	m_hwndIEServer = NULL;
	//Always use our own Download manager
	m_useieforfiledl = false;
	SetRectEmpty(&rWindowPos);

	m_pWBServiceProvider = NULL;
	m_pWBEventDispatch = NULL;
	m_pWBDocHostUIHandler = NULL;
	m_pWBDocHostShowUI = NULL;
	m_pWBInPlaceSite = NULL;
	m_pWBClientSite = NULL;
	m_pWBOleCommandTarget = NULL;
	m_pWBSecurityManager = NULL;
	m_pWBAuthenticate = NULL;
	m_pWBHttpSecurity = NULL;
	m_pWBWindowForBindingUI = NULL;
	m_pWBNewWindowManager = NULL;
	
	m_txtrange = NULL;
	m_visible = false;
	m_bAllowDragDrop = false;

	m_sbackcolor = L"BackColor";
	m_sword = L"Character";
	m_stextedit = L"Textedit";
}

//This is called twice for the first instance of this class,
//once when we release this obj
//and last, before unloading by the internal clean up crew
IWB::~IWB()
{
}

////////////////////////////////////////////////////
// *** IUnknown ***
////////////////////////////////////////////////////
ULONG STDMETHODCALLTYPE IWB::AddRef()
{ 
	return ++m_dwRefCount; 
}

ULONG STDMETHODCALLTYPE IWB::Release()
{
	if(--m_dwRefCount == 0)
	{
		delete this;
		return 0;
	}
	return m_dwRefCount;
}

STDMETHODIMP IWB::QueryInterface(REFIID iid, void ** ppvObject)
{
    if(ppvObject == NULL) return E_INVALIDARG;
    *ppvObject = NULL;

//IID_IUnknown
    if(iid == IID_IUnknown)
        *ppvObject = (IUnknown *)this;
//IID_IServiceProvider
	else if(iid == IID_IServiceProvider)
		*ppvObject = (IServiceProvider *)m_pWBServiceProvider;
//IID_IOleClientSite
    else if(iid == IID_IOleClientSite)
        *ppvObject = (IOleClientSite *)m_pWBClientSite;
//IID_IOleInPlaceSite
    else if(iid == IID_IOleInPlaceSite)
        *ppvObject = (IOleInPlaceSite *)m_pWBInPlaceSite;
//IID_IDocHostUIHandler
	else if(iid == IID_IDocHostUIHandler)
		*ppvObject = (IDocHostUIHandler *)m_pWBDocHostUIHandler;
//IID_IDocHostUIHandler2 - GetOverrideKeyPath
	else if(iid == IID_IDocHostUIHandler2)
		*ppvObject = (IDocHostUIHandler2 *)m_pWBDocHostUIHandler;
//DIID_DWebBrowserEvents2
    else if(iid == DIID_DWebBrowserEvents2)
        *ppvObject = (DWebBrowserEvents2 *)m_pWBEventDispatch;
//IID_IDispatch
    else if(iid == IID_IDispatch)
        *ppvObject = (IDispatch *)m_pWBEventDispatch;
//IID_IDocHostShowUI
	else if(iid == IID_IDocHostShowUI)
		*ppvObject = (IDocHostShowUI *)m_pWBDocHostShowUI;
//IID_IOleCommandTarget
	else if(iid == IID_IOleCommandTarget)
		*ppvObject = (IOleCommandTarget *)m_pWBOleCommandTarget;
//IID_IAuthenticate
	else if(iid == IID_IAuthenticate)
		*ppvObject = (IAuthenticate *)m_pWBAuthenticate;
//IID_IHttpSecurity
	else if(iid == IID_IHttpSecurity)
		*ppvObject = (IHttpSecurity *)m_pWBHttpSecurity;
//IID_IInternetSecurityManager
	else if(iid == IID_IInternetSecurityManager)
		*ppvObject = (IInternetSecurityManager *)m_pWBSecurityManager;
//IID_IWindowForBindingUI
	else if(iid == IID_IWindowForBindingUI)
		*ppvObject = (IWindowForBindingUI *)m_pWBWindowForBindingUI;
//IID_INewWindowManager
	else if(iid == IID_INewWindowManager)
		*ppvObject = (INewWindowManager *)m_pWBNewWindowManager;

    if(*ppvObject == NULL) return E_NOINTERFACE;
    AddRef();
    return S_OK;
}

////////////////////////////////////////////////////
// *** Methods ***
////////////////////////////////////////////////////
STDMETHODIMP IWB::StartWB(DWORD UiFlags, DWORD UiDblClk, DWORD DlFlag,
						  long CtxMnuAction, short sID, 
						  VARIANT_BOOL bAllowDragDrop, 
						  VARIANT_BOOL bUseInternalDragDrop, 
						  VARIANT_BOOL bSendSourceOnDocComplete,
						  BSTR sStartUp)
{
    HRESULT hret;
	//CComPtr<IOleObject> spOleObj;
	//CComQIPtr<IOleObject, &IID_IOleObject> spOleObj;
	CComPtr<IOleInPlaceObject> m_spInPlaceObject;
    CComPtr<IConnectionPoint> pConnectionPoint;
    CComPtr<IConnectionPointContainer> pConnectionPointContainer;

	//Take note of our unique id
	m_thisID = sID;
	m_visible = true;
    // Instantiate all needed interfaces
    m_pWBClientSite = new WBClientSite(this);
    m_pWBInPlaceSite = new WBInPlaceSite(this);

    m_pWBEventDispatch = new WBEventDispatch(this);
	m_pWBEventDispatch->m_bSendSourceOnDocComplete = VARIANTBOOLTObool(bSendSourceOnDocComplete);

	m_pWBDocHostUIHandler = new WBDocHostUIHandler(this);
	m_pWBOleCommandTarget = new WBOleCommandTarget(this);
	m_pWBSecurityManager = new WBSecurityManager(this);
	m_pWBAuthenticate = new WBAuthenticate(this);
	m_pWBHttpSecurity = new WBHttpSecurity(this);
	m_pWBWindowForBindingUI = new WBWindowForBindingUI(this);

	//Set up initial UIFlags, UIDbClk, DlCtlFlags, Accels action, and Context menu action
	m_pWBDocHostUIHandler->m_dwDocHostUIFlags = UiFlags;
	m_pWBDocHostUIHandler->m_dwDocHostUIDblClk = UiDblClk;
	m_pWBDocHostUIHandler->m_ContextMenuAction = CtxMnuAction;
	m_pWBEventDispatch->m_dwDLControl = DlFlag;

	//To take over downloading
	m_useieforfiledl = VARIANTBOOLTObool(m_EventsPtr->m_bUseIEDownloader);
	m_pWBServiceProvider = new WBServiceProvider(this);
	
	//To handle msgs
	m_pWBDocHostShowUI = new WBDocHostShowUI(this);
	
	//NewWindowManager
	m_pWBNewWindowManager = new WBNewWindowManager(this);

    // Get client coord
    GetClientRect(m_hwndParent, &rWindowPos);   
    rWindowPos.right -= rWindowPos.left; //W
    rWindowPos.bottom -= rWindowPos.top; //H
    rWindowPos.left = 0;
    rWindowPos.top = 0;

	// Create WebBrowser--store pointer in class member variable pWebBrowser
	//hret = CoCreateInstance(CLSID_WebBrowser, NULL, CLSCTX_INPROC, IID_IWebBrowser2, (void**)&pWebBrowser);
    hret = CoCreateInstance(CLSID_WebBrowser, NULL, CLSCTX_INPROC, IID_IUnknown, reinterpret_cast<void **>(&pUnknown));
	Assert(SUCCEEDED(hret));

	// Query WebBrowser for IOleObject pointer
	//hret = pWebBrowser->QueryInterface(IID_IOleObject, (void**)&spOleObj);
    hret = pUnknown->QueryInterface(IID_IOleObject, reinterpret_cast<void **>(&spOleObj));
	Assert(SUCCEEDED(hret));

	// Set client site
	hret = spOleObj->SetClientSite(m_pWBClientSite);
    Assert(SUCCEEDED(hret));
    
	//Set location
    //hret = pWebBrowser->QueryInterface(IID_IOleInPlaceObject, (void**)(&m_spInPlaceObject));
    hret = pUnknown->QueryInterface(IID_IOleInPlaceObject, reinterpret_cast<void **>(&m_spInPlaceObject));
	Assert(SUCCEEDED(hret));
    hret = m_spInPlaceObject->SetObjectRects(&rWindowPos, &rWindowPos);
    Assert(SUCCEEDED(hret));

	//Set Host names
	CComBSTR str = L"vbMHWBrowser";
	hret = spOleObj->SetHostNames(str,NULL);
	Assert(SUCCEEDED(hret));
	str.Empty();
    
	// Activate the site
    hret = spOleObj->DoVerb(OLEIVERB_INPLACEACTIVATE, NULL, m_pWBClientSite, 0, m_hwndParent, &rWindowPos);
    Assert(SUCCEEDED(hret));

    // Set event handler
    //hret = pWebBrowser->QueryInterface(IID_IConnectionPointContainer, (void**)(&pConnectionPointContainer));
	// Check that this is a connectable object.
	hret = pUnknown->QueryInterface(IID_IConnectionPointContainer, reinterpret_cast<void **>(&pConnectionPointContainer));
    Assert(SUCCEEDED(hret));
	// Find the connection point.
    hret = pConnectionPointContainer->FindConnectionPoint(DIID_DWebBrowserEvents2, &pConnectionPoint);
    Assert(SUCCEEDED(hret));
    hret = pConnectionPoint->Advise(m_pWBEventDispatch, &dwAdviseCookie);
    Assert(SUCCEEDED(hret));

    // Get Web Browser interface
    hret = pUnknown->QueryInterface(IID_IWebBrowser2, reinterpret_cast<void **>(&pWebBrowser));
    Assert(SUCCEEDED(hret));

	//Get the OleCommandTarget for Exec method calls
    hret = pUnknown->QueryInterface(IID_IOleCommandTarget, reinterpret_cast<void **>(&pOleCommandTarget));
    Assert(SUCCEEDED(hret));

	//DragDrop
	if(bAllowDragDrop == VARIANT_TRUE)
	{
		if(bUseInternalDragDrop == VARIANT_TRUE)
			m_bAllowDragDrop = true;
		else
			pWebBrowser->put_RegisterAsDropTarget(VARIANT_TRUE);
	}

	// Go to initial URL
    //hret = pWebBrowser->Navigate(L"about:blank", NULL, NULL, NULL, NULL);
	if(::SysStringLen(sStartUp) > 0)
		hret = pWebBrowser->Navigate(sStartUp, NULL, NULL, NULL, NULL);

//	//Get the hwnd for shell embedding
//	CComPtr<IOleWindow> pOWin;
//	hret = pUnknown->QueryInterface(IID_IOleWindow, reinterpret_cast<void **>(&pOWin));
//	Assert(SUCCEEDED(hret));
//	hret = pOWin->GetWindow(&m_hwndShellEmbedding);
	
	//place focus
	if (GetShellEmbedding()) // SUCCEEDED(hret))
	{
		//BringWbToTop();
		if(GetShellDocObjHwnd())
			GetIEServerHwnd();
	}

	return S_OK;
	
}

/*
IOleInPlaceObject::UIDeactivate
This method is called by the object's immediate container when, 
for example, the user has clicked in the client area outside the object. 

If the container has called IOleInPlaceObject::UIDeactivate,
it should later call IOleInPlaceObject::InPlaceDeactivate to properly clean up resources.
The container can assume that stopping or releasing the object cleans up resources
if necessary.
The object must be prepared to do so if IOleInPlaceObject::InPlaceDeactivate
has not been called. but either IOleInPlaceObject::UIDeactivate or IOleObject::Close
has been called. 

Notes to Implementers
Resources such as menus and windows can be either cleaned up or kept in a hidden state until 
your object is completely deactivated by calls to either IOleInPlaceObject::InPlaceDeactivate or 
IOleObject::Close. The object application must call IOleInPlaceSite::OnUIDeactivate before 
doing anything with the composite menus so that the container can first be detached from the frame window. On deactivating the in-place object's user interface, the object is left in a ready state so it can be quickly reactivated. The object stays in this state until the undo state of the document changes. The container should then call IOleInPlaceObject::InPlaceDeactivate to tell the object to discard its undo state.

*/

STDMETHODIMP IWB::StopWB()
{
	HRESULT hret = S_OK;
	//CComPtr<IOleObject> spOleObj;
	CComPtr<IOleInPlaceObject> m_spInPlaceObject;
    CComPtr<IConnectionPoint> pConnectionPoint;
    CComPtr<IConnectionPointContainer> pConnectionPointContainer;

    //check
	if (pWebBrowser)
	{

		//hret = pWebBrowser->QueryInterface(IID_IConnectionPointContainer, (void**)(&pConnectionPointContainer));
		hret = pUnknown->QueryInterface(IID_IConnectionPointContainer, reinterpret_cast<void **>(&pConnectionPointContainer));
	    Assert(SUCCEEDED(hret));
		hret = pConnectionPointContainer->FindConnectionPoint(DIID_DWebBrowserEvents2, &pConnectionPoint);
		Assert(SUCCEEDED(hret));
		hret = pConnectionPoint->Unadvise(dwAdviseCookie);
		Assert(SUCCEEDED(hret));

		// Query WebBrowser for IOleObject pointer
		//hret = pWebBrowser->QueryInterface(IID_IOleObject, (void**)&spOleObj);
		//hret = pUnknown->QueryInterface(IID_IOleObject, reinterpret_cast<void **>(&spOleObj));
	    //Assert(SUCCEEDED(hret));

		//Deactivate the browser UI and clean up
	    //hret = pWebBrowser->QueryInterface(IID_IOleInPlaceObject, (void**)(&m_spInPlaceObject));
		hret = pUnknown->QueryInterface(IID_IOleInPlaceObject, reinterpret_cast<void **>(&m_spInPlaceObject));
		Assert(SUCCEEDED(hret));
	    hret = m_spInPlaceObject->UIDeactivate();
		Assert(SUCCEEDED(hret));
	    hret = m_spInPlaceObject->InPlaceDeactivate();
		Assert(SUCCEEDED(hret));
		
		if(spOleObj)
		{
			//Close browser
			//OLECLOSE_NOSAVE = 0
			hret = spOleObj->Close(OLECLOSE_NOSAVE);
    		Assert(SUCCEEDED(hret));
			hret = spOleObj->SetClientSite(NULL);
    		Assert(SUCCEEDED(hret));
		}

		//Release last ref to our pointers
		spOleObj.Release();
		pOleCommandTarget.Release();
		pWebBrowser.Release();
		pUnknown.Release();

		CleanUp();
		hret = S_OK;
	}
	else
	{
		return E_FAIL;
	}
	return hret;
}

void IWB::CleanUp()
{
	// Clean up hosted classes
	if(m_pWBServiceProvider) delete m_pWBServiceProvider;	
	if(m_pWBEventDispatch) delete m_pWBEventDispatch;
	if(m_pWBDocHostUIHandler) delete m_pWBDocHostUIHandler;
	if(m_pWBDocHostShowUI) delete m_pWBDocHostShowUI;
	if(m_pWBInPlaceSite) delete m_pWBInPlaceSite;
	if(m_pWBClientSite) delete m_pWBClientSite;
	if(m_pWBOleCommandTarget) delete m_pWBOleCommandTarget;
	if(m_pWBSecurityManager) delete m_pWBSecurityManager;
	if(m_pWBAuthenticate) delete m_pWBAuthenticate;
	if(m_pWBHttpSecurity) delete m_pWBHttpSecurity;
	if(m_pWBWindowForBindingUI) delete m_pWBWindowForBindingUI;
	if(m_pWBNewWindowManager) delete m_pWBNewWindowManager;

	m_hwndParent = NULL;
	m_hwndShellEmbedding = NULL;
	m_hwndShellDocObjView = NULL;
	m_hwndIEServer = NULL;
	
	//Set all pointers to NULL
	m_pWBServiceProvider = NULL;
	m_pWBEventDispatch = NULL;
	m_pWBDocHostUIHandler = NULL;
	m_pWBDocHostShowUI = NULL;
	m_pWBInPlaceSite = NULL;
	m_pWBClientSite = NULL;
	m_pWBOleCommandTarget = NULL;
	m_pWBSecurityManager = NULL;
	m_pWBAuthenticate = NULL;
	m_pWBHttpSecurity = NULL;
	m_pWBWindowForBindingUI = NULL;
	
	if(m_txtrange)
		m_txtrange->Release();
	m_txtrange = NULL;

	m_thisID = 0;
	SetRectEmpty(&rWindowPos);

	m_EventsPtr = NULL;
}

bool IWB::SetVisible(bool bVisible)
{
//	if(!pUnknown) return false;
	
//	CComPtr<IOleObject> spOleObj;
//	pUnknown->QueryInterface(IID_IOleObject, reinterpret_cast<void **>(&spOleObj));
	if(!spOleObj) return false;

	m_visible = bVisible;
	if (bVisible)
		//Show the webbrowser
		spOleObj->DoVerb(OLEIVERB_SHOW, NULL, m_pWBClientSite , 0, m_hwndParent, &rWindowPos);
	else
    	// Hide the webbrowser
    	spOleObj->DoVerb(OLEIVERB_HIDE, NULL, m_pWBClientSite, 0, m_hwndParent, &rWindowPos);
	return true;
}


//This method is called from CvbWB::ResizeWBs to resize
//this WB rNewPos->right and rNewPos->bottom are set to
//new Width and new Height
void IWB::SetLocation(RECT *rNewPos)
{
	CComQIPtr<IOleInPlaceObject, &IID_IOleInPlaceObject> m_spInPlaceObject(pUnknown);
	if(m_spInPlaceObject)
	{
		/*Take note of new size*/
		//BOOL bcopied = CopyRect(&rWindowPos,rNewPos);
		//If failed, do it manually
		if(!CopyRect(&rWindowPos,rNewPos))
		{
			rWindowPos.left = rNewPos->left;
			rWindowPos.top = rNewPos->top;
			rWindowPos.right = rNewPos->right; //W
			rWindowPos.bottom = rNewPos->bottom; //H
		}
		
		//Set location
		//pWebBrowser->QueryInterface(IID_IOleInPlaceObject, reinterpret_cast<void **>(&m_spInPlaceObject));
		//pUnknown->QueryInterface(IID_IOleInPlaceObject, (void**)(&m_spInPlaceObject));
		m_spInPlaceObject->SetObjectRects(rNewPos, rNewPos);
	}
}

void IWB::InvokeShellDocObjCommand(long nID)
{
//	if(!m_hwndShellDocObjView)
//		GetShellDocObjHwnd();
	if(GetShellDocObjHwnd())
		SendMessage( m_hwndShellDocObjView, WM_COMMAND, MAKEWPARAM(LOWORD(nID), 0x0), 0 );
}

void IWB::InvokeIEServerCommand(long nID)
{
//	if(!m_hwndIEServer)
//		GetIEServerHwnd();
	if(GetIEServerHwnd())
		SendMessage( m_hwndIEServer, WM_COMMAND, MAKEWPARAM(LOWORD(nID), 0x0), 0 );
}

HWND IWB::GetShellEmbedding()
{
	if((m_hwndShellEmbedding) && (::IsWindow(m_hwndShellEmbedding)) )
		return m_hwndShellEmbedding;
	
	m_hwndShellEmbedding = NULL;
	CComPtr<IOleWindow> pOWin;
	//Get the hwnd for shell embedding
	HRESULT hret = pUnknown->QueryInterface(IID_IOleWindow, 
			reinterpret_cast<void **>(&pOWin));
	if( (pOWin) && (SUCCEEDED(hret)) )
	{
		pOWin->GetWindow(&m_hwndShellEmbedding);
		return m_hwndShellEmbedding;
	}
	else
		return NULL;
}

HWND IWB::GetShellDocObjHwnd()
{
	if ((m_hwndShellDocObjView)  && (::IsWindow(m_hwndShellDocObjView)) )
		return m_hwndShellDocObjView;
	
//	if (!m_hwndShellEmbedding)
//		GetShellEmbedding();

	m_hwndShellDocObjView = NULL;
	if (GetShellEmbedding())
	{
		m_hwndShellDocObjView = GetWindow(m_hwndShellEmbedding,GW_CHILD);
		return m_hwndShellDocObjView;
	}
	else
		return NULL;
}

HWND IWB::GetIEServerHwnd()
{
	if( (m_hwndIEServer)   && (::IsWindow(m_hwndIEServer)) )
		return m_hwndIEServer;
	
//	if (!m_hwndShellDocObjView)
//		GetShellDocObjHwnd();

	m_hwndIEServer = NULL;
	if (GetShellDocObjHwnd())
	{
		m_hwndIEServer = GetWindow(m_hwndShellDocObjView,GW_CHILD);
		return m_hwndIEServer;
	}
	else
		return NULL;
		//m_hwndIEServer = FindWindowEx(m_hwndShellDocObjView,NULL,"Internet Explorer_Server",NULL);
}

//UIActivates and places focus on the WB
void IWB::SetFocusDoc()
{
//	CComPtr<IOleObject> spOleObj;
//	HRESULT hret = pUnknown->QueryInterface(IID_IOleObject, 
//		reinterpret_cast<void **>(&spOleObj));
//	if (SUCCEEDED(hret))

	if(!spOleObj) return;
    spOleObj->DoVerb(OLEIVERB_UIACTIVATE, NULL, m_pWBClientSite, 0, m_hwndParent, &rWindowPos);
	if( GetIEServerHwnd() )
	{
		//::SetForegroundWindow(m_hwndIEServer);
		::SetFocus(m_hwndIEServer);
	}
}

//Brings this WB to the top of the Zorder
void IWB::BringWbToTop()
{
	if(m_hwndShellEmbedding == NULL)
		GetShellEmbedding();
	if(m_hwndShellEmbedding)
	{
		BringWindowToTop(m_hwndShellEmbedding);
	}
}

//To reset, do a search with a zero length string
//Attempts to find a match in the active document, accounts for frames
//able to continue search from last find positiion
bool IWB::DocFindText(BSTR pText,
							VARIANT_BOOL DownWard,
							VARIANT_BOOL MatchWholeWord,
							VARIANT_BOOL MatchCase,
							VARIANT_BOOL ScrollIntoView)
{						
	static CComBSTR sLastSearch;

	//To see if we are continuing a search or starting a new one
	CComBSTR sTmp(pText);
	if (sTmp.Length() == 0)
	{
		sLastSearch.Empty();
		if(m_txtrange)
		{
			m_txtrange->Release();
			m_txtrange = NULL;
		}
		return false;
	}

	//Do we have a htmltxtrange
	if(m_txtrange)
	{
		//If cur text to find and last search are the same
		if(sTmp == sLastSearch)
		{
			if(DownWard == VARIANT_TRUE)
				m_txtrange->collapse(VARIANT_FALSE);
			else
				m_txtrange->collapse(VARIANT_TRUE);
		}
		else
		{
			m_txtrange->Release();
			m_txtrange = NULL;
		}
	}

	sLastSearch.Empty();
	sLastSearch = sTmp;
	sTmp.Empty();

	bool bRet = false;
	VARIANT_BOOL bsearch = VARIANT_FALSE;
	HRESULT hr;
	long searchdir = 0;
	long searchcase = 0; //default
	
	//Set up search direction
	if(DownWard == VARIANT_TRUE)
		searchdir = 1000000;
	else
		searchdir = -1000000;
	//Set up search case
	if((MatchWholeWord == VARIANT_TRUE) && (MatchCase == VARIANT_TRUE))
		searchcase = 6;
	else if(MatchWholeWord == VARIANT_TRUE)
		searchcase = 2;
	else if(MatchCase == VARIANT_TRUE)
		searchcase = 4;

	CComPtr<IDispatch> spDisp;
	//Start with the main document
    hr = pWebBrowser->get_Document(&spDisp);
	if(FAILED(hr)) return bRet;

	CComQIPtr<IHTMLDocument2> spDoc( spDisp );
	if(!spDisp) return bRet;

	CComPtr<IHTMLElement> spElementHit;
	hr = spDoc->get_activeElement(&spElementHit);
	if(FAILED(hr)) return bRet;

	//Check for frames
	//Drill down till we have no more frames, and we reach loaded document
	//within frame
	CComQIPtr<IWebBrowser2> spFrame( spElementHit );
	while( spFrame )
	{
		spDisp.Release();
		spFrame->get_Document(&spDisp);
	    spDoc = spDisp;
		spElementHit.Release();
		spDoc->get_activeElement(&spElementHit);
		spFrame = spElementHit;
	}
	//Do we a valid document and element
	if(!spElementHit) return bRet;
	//Get the element
	IHTMLElement *pmBodyElem = NULL;
	hr = spDoc->get_body(&pmBodyElem);
	if(SUCCEEDED(hr) && pmBodyElem)
	{
		//Get the body
		IHTMLBodyElement *pmBody = NULL;
		hr = pmBodyElem->QueryInterface(IID_IHTMLBodyElement, reinterpret_cast<void **>(&pmBody));
		if(SUCCEEDED(hr) && pmBody)
		{
			if(!m_txtrange)//Starting a new search
			{
				hr = pmBody->createTextRange(&m_txtrange);
			}
			if(m_txtrange)
			{
				//Attempt to find text
				hr = m_txtrange->findText(pText,searchdir,searchcase,&bsearch);
				if((SUCCEEDED(hr)) && (bsearch == VARIANT_TRUE) && (ScrollIntoView == VARIANT_TRUE))
				{
					m_txtrange->select();
					m_txtrange->scrollIntoView(VARIANT_TRUE);
				}
			}
			pmBody->Release();
		}
		pmBodyElem->Release();
	}

	if(bsearch == VARIANT_TRUE)
		bRet = true;
	return bRet;

}

//Attempts to find and highlight any matches in a page
//accounts for frames and returns number of matches found or 0
//Called from DocHighlightAllFindText, ::SearchFramesets, and ::DocHighlightFindText methods
long IWB::DocFindAndHighlightText(IHTMLBodyElement *pBodyElement, BSTR pText, long searchcase, VARIANT HighlightColor)
{
	long lRet = 0;
	long t;
	VARIANT_BOOL bsearch = VARIANT_FALSE;
	HRESULT hr;
	CComPtr<IHTMLTxtRange> lpTxtRange;
	VARIANT_BOOL bresult = VARIANT_FALSE;

	hr = pBodyElement->createTextRange(&lpTxtRange);
	if(SUCCEEDED(hr) && lpTxtRange)
	{
		while(true)
		{
			hr = lpTxtRange->findText(pText,0,searchcase,&bsearch);
			if((SUCCEEDED(hr)) && (bsearch == VARIANT_TRUE))
			{
				lRet++;
				hr = lpTxtRange->execCommand(m_sbackcolor,VARIANT_FALSE, HighlightColor ,&bresult);
				lpTxtRange->moveStart(m_sword ,1,&t);
				lpTxtRange->moveEnd(m_stextedit ,1,&t);
			}
			else
				break;
		}
	}
	return lRet;
}

//Attempts to find and highlight all matches in a frameset page
//called from IWB::DocHighlightAllFindText
long IWB::SearchFramesets(IHTMLDocument2 *pFrameSet, BSTR pText, long searchcase, VARIANT HighlightColor)
{
	long lRet = 0;
	HRESULT hr;

	CComPtr<IHTMLElement> pmBodyElem;
	CComPtr<IHTMLBodyElement> pmBody;

	CComPtr<IHTMLFramesCollection2> pFrames;
	//Window and Document interfaces for this frame
	CComPtr<IHTMLDocument2> pFrameDoc;
	CComPtr<IHTMLWindow2> pFrameWindow;
	
	//Get frames collection from the main document
	hr = pFrameSet->get_frames(&pFrames);
	if(SUCCEEDED(hr) && pFrames)
	{
		long celem = 0;
		hr = pFrames->get_length(&celem);
		//Check each frame
		if(SUCCEEDED(hr) && celem > 0)
		{
			//Start loop, search all frames
			for ( int i=0; i< celem; i++ )
			{
				//lindex++;
				VARIANT varIndex;
				varIndex.vt = VT_UINT;
				varIndex.lVal = i;
				VARIANT var2;
				VariantInit( &var2 );
				//Get the item from collection
				hr = pFrames->item( &varIndex, &var2);
				if(SUCCEEDED(hr))
				{
					//Query for IHTMLWindow2
					hr = var2.pdispVal->QueryInterface(IID_IHTMLWindow2, reinterpret_cast<void **>(&pFrameWindow));
					if(SUCCEEDED(hr) && pFrameWindow)
					{
						//Get the document for this frame
						hr = pFrameWindow->get_document(&pFrameDoc);
						if(SUCCEEDED(hr) && pFrameDoc)
						{
							//If the document contains the body element,
							//this is a collection of all iframe elements in the document.
							hr = pFrameDoc->get_body(&pmBodyElem);
							if(SUCCEEDED(hr) && pmBodyElem)
							{
								hr = pmBodyElem->QueryInterface(IID_IHTMLBodyElement, (void**)&pmBody);
								if(SUCCEEDED(hr) && pmBody)
								{
									lRet += DocFindAndHighlightText(pmBody, pText, searchcase, HighlightColor);
									pmBody.Release();
								}
								else //Recurse this HTMLDocument2 which is a frameset itself
									lRet += SearchFramesets(pFrameDoc,pText, searchcase, HighlightColor);
								pmBodyElem.Release();
							}
							pFrameDoc.Release();
						}
						pFrameWindow.Release();
					}
				}
				VariantClear(&varIndex);
				VariantClear(&var2);
			} //End for
		} //End if celem > 0
	}

	return lRet;
}

//Called from CvbWB::FindAndHighlightAllTextFrames
//Attempts to find and highlight a given text.
//If frameset then searches all frames also
//Returns number of matches found
long IWB::DocHighlightAllFindText(BSTR pText,
							VARIANT_BOOL MatchWholeWord,
							VARIANT_BOOL MatchCase,
							BSTR HighlightColor)
{
	long lRet = 0;
	long searchcase = 0; //default
	HRESULT hr;
	VARIANT vcolor;

	//Set up search case
	if((MatchWholeWord == VARIANT_TRUE) && (MatchCase == VARIANT_TRUE))
		searchcase = 6;
	else if(MatchWholeWord == VARIANT_TRUE)
		searchcase = 2;
	else if(MatchCase == VARIANT_TRUE)
		searchcase = 4;

	VariantInit(&vcolor);
	vcolor.bstrVal = ::SysAllocString(HighlightColor); //royalblue");
	vcolor.vt = VT_BSTR;

CComPtr<IDispatch> spDisp;
	//Start with the main document dispatch
    hr = pWebBrowser->get_Document(&spDisp);
	if(FAILED(hr) || !spDisp) return lRet;

	//QI for IHTMLDocument2
CComQIPtr<IHTMLDocument2> spDoc( spDisp );
	if(!spDoc) return lRet;

	CComPtr<IHTMLElement> pmBodyElem;
	CComPtr<IHTMLBodyElement> pmBody;

//Is this a frameset

	//Get the body element
	hr = spDoc->get_body(&pmBodyElem);
	if(SUCCEEDED(hr) && pmBodyElem)
	{
		//Get the body
		//If no body present then this is a frameset
		hr = pmBodyElem->QueryInterface(IID_IHTMLBodyElement, reinterpret_cast<void **>(&pmBody));
		//Not a frameset
		if(SUCCEEDED(hr) && pmBody)
		{
			lRet = DocFindAndHighlightText(pmBody, pText, searchcase, vcolor);
			::SysFreeString(vcolor.bstrVal);
			return lRet;
		}
	}

	//We have a frameset
	lRet = SearchFramesets(spDoc, pText, searchcase, vcolor);

	::SysFreeString(vcolor.bstrVal);
	return lRet;
}

//Called from CvbWB::FindAndHighlightAllText
//Works on active document if frameset
//Returns number of matches found
long IWB::DocHighlightFindText(BSTR pText,
								VARIANT_BOOL MatchWholeWord,
								VARIANT_BOOL MatchCase,
								BSTR HighlightColor)
{

	long searchcase = 0; //default
	long lRet = 0;
	HRESULT hr;
	VARIANT vcolor;

	//Set up search case
	if((MatchWholeWord == VARIANT_TRUE) && (MatchCase == VARIANT_TRUE))
		searchcase = 6;
	else if(MatchWholeWord == VARIANT_TRUE)
		searchcase = 2;
	else if(MatchCase == VARIANT_TRUE)
		searchcase = 4;

	VariantInit(&vcolor);
	vcolor.bstrVal = ::SysAllocString(HighlightColor); //royalblue");
	vcolor.vt = VT_BSTR;

CComPtr<IDispatch> spDisp;
	//Start with the main document dispatch
    hr = pWebBrowser->get_Document(&spDisp);
	if(FAILED(hr) || !spDisp) return lRet;

	//QI for IHTMLDocument2
CComQIPtr<IHTMLDocument2> spDoc( spDisp );
	if(!spDoc) return lRet;

	//Get the active element
CComPtr<IHTMLElement> spElementHit;
	spDoc->get_activeElement(&spElementHit);
	if(!spElementHit) return lRet;

	//See if we can query the active element for IWebBrowser2 interface
	//indicating that this is a frame
CComQIPtr<IWebBrowser2> spFrame( spElementHit );
	while( spFrame )
	{
		spDisp.Release();
		//Get document dispatch
		spFrame->get_Document(&spDisp);
		//QI for IHTMLDocument2
		spDoc = spDisp;
		spElementHit.Release();
		spDoc->get_activeElement(&spElementHit);
		//Query for IWebBrowser2
		spFrame = spElementHit;
	}
	if( (!spDisp) || (!spDoc) ) 
		return lRet;

	CComPtr<IHTMLElement> pmBodyElem;
	CComPtr<IHTMLBodyElement> pmBody;

	//Get the element
	hr = spDoc->get_body(&pmBodyElem);
	if(SUCCEEDED(hr) && pmBodyElem)
	{
		//Get the body
		hr = pmBodyElem->QueryInterface(IID_IHTMLBodyElement, 
			reinterpret_cast<void **>(&pmBody));
		if(SUCCEEDED(hr) && pmBody)
		{
			lRet = DocFindAndHighlightText(pmBody, pText, searchcase, vcolor);
		}
	}
	
	::SysFreeString(vcolor.bstrVal);
	//VariantClear(&vcolor);
	return lRet;
}

//Returns true if a search phrase has been found
//Accounts for frames
//Called from CvbWB::FindAnyTextMatch
bool IWB::DocTextExists(BSTR pText,
							VARIANT_BOOL MatchWholeWord,
							VARIANT_BOOL MatchCase)
{
	long searchcase = 0; //default
	HRESULT hr;
	bool bRet = false;
	bool isframeset = false;

	//Set up search case
	if((MatchWholeWord == VARIANT_TRUE) && (MatchCase == VARIANT_TRUE))
		searchcase = 6;
	else if(MatchWholeWord == VARIANT_TRUE)
		searchcase = 2;
	else if(MatchCase == VARIANT_TRUE)
		searchcase = 4;

	CComPtr<IDispatch> spDisp;
	//Start with the main document
    hr = pWebBrowser->get_Document(&spDisp);
	if(FAILED(hr) || !spDisp) return bRet;

	CComQIPtr<IHTMLDocument2> spDoc( spDisp );
	if(!spDoc) return bRet;

	bRet = SearchDocument(spDoc,&isframeset,pText,searchcase);
	
	//If this is not a frameset or we have found a match, just return
	//if ((isframeset == false) || (bRet == true)) return bRet;
	if (isframeset == true)
		bRet = SearchFrameset(spDoc,pText,searchcase);
	
	return bRet;
}

//Searches frames within framesets, recursive
//called from DocTextExists
bool IWB::SearchFrameset(IHTMLDocument2 *pFrameSet,
							BSTR pText,
							long lCase)
{
//	CComPtr<IHTMLTxtRange> lpTxtRange;
	long searchcase = lCase; //default
//	long t = 0;
	HRESULT hr = S_OK;
	bool bRet = false;
	VARIANT_BOOL bsearch = VARIANT_FALSE;
	bool isframeset = false;

	CComPtr<IHTMLDocument2> spDoc = pFrameSet;
	if(!spDoc) return bRet;

//	CComPtr<IHTMLElement> pmBodyElem = NULL;
//	CComPtr<IHTMLBodyElement> pmBody = NULL;

	CComPtr<IHTMLFramesCollection2> pFrames = NULL;
	//Window and Document interfaces for this frame
	CComPtr<IHTMLDocument2> pFrameDoc = NULL;
	CComPtr<IHTMLWindow2> pFrameWindow;
	
	//Get frames collection from the main document
		hr = spDoc->get_frames(&pFrames);
		if(SUCCEEDED(hr) && pFrames)
		{
			long celem = 0;
			hr = pFrames->get_length(&celem);
			//Check each frame
			if(SUCCEEDED(hr) && celem > 0)
			{
				//Start loop, search all frames
				for ( int i=0; i< celem; i++ )
				{
					//lindex++;
					VARIANT varIndex;
					varIndex.vt = VT_UINT;
					varIndex.lVal = i;
					VARIANT var2;
					VariantInit( &var2 );
					//Get the item from collection
					hr = pFrames->item( &varIndex, &var2);
					if(SUCCEEDED(hr))
					{
						//Query for IHTMLWindow2
						hr = var2.pdispVal->QueryInterface(IID_IHTMLWindow2, reinterpret_cast<void **>(&pFrameWindow));
						if(SUCCEEDED(hr) && pFrameWindow)
						{
							//Get the document for this frame
							hr = pFrameWindow->get_document(&pFrameDoc);
							if(SUCCEEDED(hr) && pFrameDoc)
							{
								bRet = SearchDocument(pFrameDoc,&isframeset,pText,searchcase);
								if (isframeset == true)
									bRet = SearchFrameset(pFrameDoc,pText,searchcase);
								pFrameDoc.Release();
							}
							pFrameWindow.Release();
						}
					}
					VariantClear(&varIndex);
					VariantClear(&var2);
				} //End for
			} //End if celem > 0
		}

	return bRet;
}

//Searches a document
//Returns if the document is a frameset
//Called from DocTextExists
bool IWB::SearchDocument(IHTMLDocument2 *pFrameSet,bool *IsFrame, BSTR pText, long lCase)
{
	//Search result
	VARIANT_BOOL bsearch = VARIANT_FALSE;
	bool bRet = false;
	long t = 0;
	CComPtr<IHTMLTxtRange> lpTxtRange;
	CComPtr<IHTMLElement> pmBodyElem;
	CComPtr<IHTMLBodyElement> pmBody;
	
	//Initially
	*IsFrame = false;

	//Get the body element
	HRESULT hr = pFrameSet->get_body(&pmBodyElem);
	if(SUCCEEDED(hr) && pmBodyElem)
	{
		//Get the body
		//If no body present then this is a frameset
		hr = pmBodyElem->QueryInterface(IID_IHTMLBodyElement, reinterpret_cast<void **>(&pmBody));
		if(SUCCEEDED(hr) && pmBody)
		{
			//If we have a body then this is not a frameset
			hr = pmBody->createTextRange(&lpTxtRange);
			if(SUCCEEDED(hr) && lpTxtRange)
			{
				//Get the txtrange and htmldoc2 dipatchs
				CComQIPtr<IDispatch> spDisp( lpTxtRange );
				CComQIPtr<IDispatch> spDocDisp( pFrameSet );

				VARIANT_BOOL bStop = VARIANT_FALSE;

				//Attempt to find text and continue till client stops the
				//search or no more matches are found
				while(true)
				{
					hr = lpTxtRange->findText(pText,0,lCase,&bsearch);
					if((SUCCEEDED(hr)) && (bsearch == VARIANT_TRUE))
					{
						m_EventsPtr->Fire_FindAnyTextMatchCallback(m_thisID, spDocDisp, spDisp, &bStop);
						bRet = true;
						if(bStop == VARIANT_TRUE)
							break;
						lpTxtRange->moveStart(m_sword ,1,&t);
						lpTxtRange->moveEnd(m_stextedit ,1,&t);
					}
					else
						break;
				}
			}
		}
		else
			*IsFrame = true;
	}
	return bRet;
}

//Is this a frameset site
//Called from cvbWB:;IsDocFrameset
bool IWB::IsFrameset()
{

	CComPtr<IDispatch> spDisp;
	//Start with the main document
    HRESULT hr = pWebBrowser->get_Document(&spDisp);
	if(FAILED(hr) || !spDisp) return false;

	CComQIPtr<IHTMLDocument2> spDoc( spDisp );
	if(!spDoc) return false;

	CComPtr<IHTMLElement> pmBodyElem = NULL;
	CComPtr<IHTMLBodyElement> pmBody = NULL;

	//Get the body element
	hr = spDoc->get_body(&pmBodyElem);
	if(SUCCEEDED(hr) && pmBodyElem)
	{
		//Get the body
		//If no body present then this is a frameset
		hr = pmBodyElem->QueryInterface(IID_IHTMLBodyElement, reinterpret_cast<void **>(&pmBody));
		//pmBody = pmBodyElem;
		if(SUCCEEDED(hr) && pmBody)
			return false;
	}
	return true;
}

bool IWB::IsFrameset(IWebBrowser2 *pBrowser)
{
	CComPtr<IDispatch> spDisp;
	//Start with the main document
    HRESULT hr = pBrowser->get_Document(&spDisp);
	if(FAILED(hr) || !spDisp) return false;

	CComQIPtr<IHTMLDocument2> spDoc( spDisp );
	if(!spDoc) return false;

	CComPtr<IHTMLElement> pmBodyElem = NULL;
	CComPtr<IHTMLBodyElement> pmBody = NULL;

	//Get the body element
	hr = spDoc->get_body(&pmBodyElem);
	if(SUCCEEDED(hr) && pmBodyElem)
	{
		//Get the body
		//If no body present then this is a frameset
		hr = pmBodyElem->QueryInterface(IID_IHTMLBodyElement, reinterpret_cast<void **>(&pmBody));
		//pmBody = pmBodyElem;
		if(SUCCEEDED(hr) && pmBody)
			return false;
	}
	return true;
}

//Experimental
long IWB::FramesCount(IWebBrowser2 *pBrowser)
{
	long lcount = 0;
	CComPtr<IDispatch> spDisp;
	//Start with the main document
    HRESULT hr = pBrowser->get_Document(&spDisp);

	if(FAILED(hr) || !spDisp) return lcount;

	IOleContainer* pContainer = NULL;

	// Get the container
	hr = spDisp->QueryInterface(IID_IOleContainer,
									   (void**)&pContainer);

	if(FAILED(hr) || !pContainer) return lcount;

	CComPtr<IEnumUnknown> pEnumerator;

	// Get an enumerator for the frames
	hr = pContainer->EnumObjects(OLECONTF_EMBEDDINGS, &pEnumerator);

	if(FAILED(hr) || !pEnumerator) return lcount;

	IUnknown* pUnk = NULL;
	ULONG uFetched = 0;

	// Enumerate and refresh all the frames
	for (UINT i = 0; S_OK == pEnumerator->Next(1, &pUnk, &uFetched); i++)
	{
		IWebBrowser2* ptmpBrowser = NULL;

		hr = pUnk->QueryInterface(IID_IWebBrowser2, (void**)&pBrowser);
		pUnk->Release();

		if( (SUCCEEDED(hr)) && (pBrowser != NULL) )
		{
			//If frameset then find the actual frame
			//else
			//IHTMLDocument2* pDoc = NULL;
			//IDispatch* pDisp = NULL;
			//hr = ptmpBrowser->get_Document(&pDisp);
			//hr = pDisp->QueryInterface(IID_IHTMLDocument2, reinterpret_cast<void **>(&pDoc));
			// Refresh the frame
			ptmpBrowser->Refresh();
			ptmpBrowser->Release();
		}
	}

	return lcount;
}

//A recursive function
//Counts the number of frames in a given document
//Called from CvbWB::get_FramesCount
long IWB::FramesCount(IHTMLDocument2 *pFrameSet)
{
	long lcount = 0;
	HRESULT hr;
//USES_CONVERSION;
	//Get a copy
	CComPtr<IHTMLDocument2> spDoc = pFrameSet;
	if(!spDoc) return lcount;

	CComPtr<IHTMLElement> pmBodyElem = NULL;
	CComPtr<IHTMLBodyElement> pmBody = NULL;

	CComPtr<IHTMLFramesCollection2> pFrames = NULL;
	//Window and Document interfaces for this frame
	CComPtr<IHTMLDocument2> pFrameDoc = NULL;
	CComPtr<IHTMLWindow2> pFrameWindow;
	CComBSTR stag;
	//Get frames collection from the main document
		hr = spDoc->get_frames(&pFrames);
		if(SUCCEEDED(hr) && pFrames)
		{
			long celem = 0;
			hr = pFrames->get_length(&celem);
			//Check each frame
			if(SUCCEEDED(hr) && celem > 0)
			{
				//Start loop, search all frames
				for ( int i=0; i< celem; i++ )
				{
					//lindex++;
					VARIANT varIndex;
					varIndex.vt = VT_UINT;
					varIndex.lVal = i;
					VARIANT var2;
					VariantInit( &var2 );
					//Get the item from collection
					hr = pFrames->item( &varIndex, &var2);
					if(SUCCEEDED(hr))
					{
						//Query for IHTMLWindow2
						hr = var2.pdispVal->QueryInterface(IID_IHTMLWindow2, reinterpret_cast<void **>(&pFrameWindow));
						if(SUCCEEDED(hr) && pFrameWindow)
						{
							//Get the IHTMLDocument2 for this frame
							hr = pFrameWindow->get_document(&pFrameDoc);
							if(SUCCEEDED(hr) && pFrameDoc)
							{
								//If the document contains the body element,
								//this is a collection of all iframe elements in the document.
								hr = pFrameDoc->get_body(&pmBodyElem);
								if(SUCCEEDED(hr) && pmBodyElem)
								{
										stag.Empty();
										hr = pmBodyElem->get_tagName(&stag);
										if(SUCCEEDED(hr))
										{
											//This can be a IFRAME!!!
											stag.ToUpper();
											if(stag == L"BODY") // || (stag == L"FRAME"))
											{
//												stag.Empty();
//												hr = pFrameDoc->get_title(&stag);
//												Alert(OLE2T(stag));
												lcount++;
											}
											else if(stag == L"FRAMESET") //|| (stag == L"FRAME"))
											{
												lcount += FramesCount(pFrameDoc);
											}
//											else
//											{
//												//Display tag
//												Alert(OLE2T(stag));
//											}
										}
									pmBodyElem.Release();
								}
								pFrameDoc.Release();
							}
							pFrameWindow.Release();
						}
					}
					VariantClear(&varIndex);
					VariantClear(&var2);
					stag.Empty();
				} //End for
			} //End if celem > 0
		}

	return lcount;
}

HRESULT IWB::WBCreateBSCBFileDL(WBBSCBFileDL **ppTargetBSCBFileDL)
{
	if(ppTargetBSCBFileDL == NULL) return E_INVALIDARG;

	//used in combination with CancelFileDL to stop timed out dls,...
	m_EventsPtr->m_dluid++;
	*ppTargetBSCBFileDL = new WBBSCBFileDL(m_EventsPtr->m_dluid);
	if(*ppTargetBSCBFileDL == NULL)
		return E_OUTOFMEMORY;
	return S_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////
//WBDropTarget
/////////////////////////////////////////////////////////////////////////////////////////
WBDropTarget::WBDropTarget(IWB* pFrameSite)
{
	//Will be deleted from WBDocHostUIHandler destructor
	m_cRef = 1;
	m_pHost = pFrameSite;
} 
WBDropTarget::~WBDropTarget()
{
}

// IUnknown
STDMETHODIMP WBDropTarget::QueryInterface(REFIID iid, void ** ppvObject)
{
	if(ppvObject == NULL) return E_INVALIDARG;
	*ppvObject = NULL;

	if( (iid==IID_IDropTarget) || (iid==IID_IUnknown) )
	{
       *ppvObject = (IDropTarget*)this;
	}

	if (NULL != *ppvObject)
	{
        AddRef();
        return S_OK;
    }
	return E_NOINTERFACE; 
}

ULONG STDMETHODCALLTYPE WBDropTarget::AddRef()
{
	return ++m_cRef;
}

ULONG STDMETHODCALLTYPE WBDropTarget::Release()
{
	if(--m_cRef == 0)
	{
        delete this;
		return 0;
	}
	return m_cRef;
}

//No drag drop by default as is Webbrowser.RegisterAsBrowser
//default property value.
long WBDropTarget::DetermineEffect(DWORD dwEffects)
{
	long lRet = 0; //Always start with None
	if( (dwEffects & DROPEFFECT_COPY) == DROPEFFECT_COPY)
	{
		lRet = 1;
	}
	else if( (dwEffects & DROPEFFECT_MOVE) == DROPEFFECT_MOVE)
	{
		lRet = 2;
	}
	else if( (dwEffects & DROPEFFECT_LINK) == DROPEFFECT_LINK)
	{
		lRet = 4;
	}
	else if( (dwEffects & DROPEFFECT_SCROLL) == DROPEFFECT_SCROLL)
	{
		lRet = static_cast<long>(DROPEFFECT_SCROLL);
	}

	return lRet;
}

//Current state of the keyboard modifier keys on the keyboard.
//Valid values can be a combination of any of the flags
//MK_CONTROL, MK_SHIFT, MK_ALT, MK_BUTTON, MK_LBUTTON, MK_MBUTTON, and MK_RBUTTON. 

STDMETHODIMP WBDropTarget::DragEnter( 
    /* [unique][in] */ IDataObject *pDataObj,
    /* [in] */ DWORD grfKeyState,
    /* [in] */ POINTL pt,
    /* [out][in] */ DWORD *pdwEffect)
{
	if(m_pHost->m_bAllowDragDrop == false)
	{
		*pdwEffect = DROPEFFECT_NONE;
		return S_OK;
	}

	m_lEffects = DetermineEffect((*pdwEffect));
	m_pHost->m_EventsPtr->Fire_OnWBDragEnter(m_pHost->m_thisID, 
							(short)grfKeyState, (long)pt.x, (long)pt.y, &m_lEffects);

	*pdwEffect = static_cast<unsigned long>(m_lEffects); //DROPEFFECT_COPY;
	return S_OK;
}

STDMETHODIMP WBDropTarget::DragOver( 
    /* [in] */ DWORD grfKeyState,
    /* [in] */ POINTL pt,
    /* [out][in] */ DWORD *pdwEffect)
{
	if(m_pHost->m_bAllowDragDrop == false)
	{
		*pdwEffect = DROPEFFECT_NONE;
		return S_OK;
	}

	m_lEffects = DetermineEffect((*pdwEffect));
	m_pHost->m_EventsPtr->Fire_OnWBDragOver(m_pHost->m_thisID, 
							(short)grfKeyState, (long)pt.x, (long)pt.y, &m_lEffects);

	*pdwEffect = static_cast<unsigned long>(m_lEffects);
	return S_OK;
}

STDMETHODIMP WBDropTarget::DragLeave( void)
{
	if(m_pHost->m_bAllowDragDrop == true)
		m_pHost->m_EventsPtr->Fire_OnWBDragLeave(m_pHost->m_thisID);
	return S_OK;
}

//Drop, Can handle multiple file names and formats
//Using Two separate events
//One for a single file drop WBDrop (uses a BSTR)
//One for multiple file drops WBDrop2 (uses a VARIANT.vt = VT_BSTR|VT_ARRAY)
STDMETHODIMP WBDropTarget::Drop( 
    /* [unique][in] */ IDataObject *pDataObj,
    /* [in] */ DWORD grfKeyState,
    /* [in] */ POINTL pt,
    /* [out][in] */ DWORD *pdwEffect)
{
	if(m_pHost->m_bAllowDragDrop == false)
	{
		*pdwEffect = DROPEFFECT_NONE;
		return S_OK;
	}

	CComBSTR strDropFile(L"");
	HRESULT hr = S_FALSE;
	UINT iRes = 0;
	//Interpret the effect to be send via event to client app
	m_lEffects = DetermineEffect((*pdwEffect));

	//First we try CF_HDROP
	//If failed then we try to enum all possible formats
	//first acceptable format found we use it
	//Any textual format such as CF_TEXT, CF_UNICODETEXT, CF_HTML, CF_RTF, CF_URL
	//No other registered, private or GDI formats are supported
	//Local variables, structs and an example has been provided as how to handle
	//CF_FILEGROUPDESCRIPTOR struct, just uncomment and use

	FORMATETC	fe = { CF_HDROP , NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL};

	//The receiver of the medium is responsible for releasing it
	STGMEDIUM	stm;
	stm.tymed = TYMED_HGLOBAL;
	stm.hGlobal = NULL;


	//The provider indicates that the receiver of the medium
	//is responsible for freeing the medium by specifying NULL
	//for the punkForRelease structure member.
	stm.pUnkForRelease = NULL;

	//The medium must be allocated and filled in by IDataObject::GetData.
//	if(pDataObj)
//	{
	hr = pDataObj->GetData(&fe, &stm);
//	}

	//Do we have a HDROP
	if( SUCCEEDED(hr) )
	{
		if ( (stm.tymed == TYMED_HGLOBAL) && (stm.hGlobal) )
		{
			HDROP hDropInfo = (HDROP)stm.hGlobal;
			TCHAR szFileName[MAX_PATH];
			UINT iFile = 0;
			/*
			When the DragQueryFile function copies a file name to the buffer,
			the return value is a count of the characters copied,
			not including the terminating null character.
			If the index value is 0xFFFFFFFF, the return value is
			a count of the dropped files. Note that the index variable
			itself returns unchanged, and will therefore remain 0xFFFFFFFF.

			If the index value is between zero and the total number of
			dropped files and the lpszFile buffer address is NULL, the
			return value is the required size, in characters, of the buffer,
			not including the terminating null character.
			*/
			iFile = ::DragQueryFile(hDropInfo, 0xFFFFFFFF, szFileName, MAX_PATH);
			USES_CONVERSION;
			if(iFile == 1)
			{
				iFile = 0;
				iRes = ::DragQueryFile(hDropInfo, iFile, szFileName, MAX_PATH);
				if(iRes > 0)
				{
					strDropFile.AppendBSTR(T2BSTR(szFileName));
				}
				//Notify client
				//If all goes well, strDropFile will contain some sort of text else zero len string
				m_pHost->m_EventsPtr->Fire_OnWBDrop(m_pHost->m_thisID, 
										(short)grfKeyState, (long)pt.x, (long)pt.y, 
										strDropFile,(long)WB_CFSINGLEFILE, &m_lEffects);
			}
			//Multiple file names
			else if(iFile > 1)
			{
				CVariantBSTRArray varbstrarr(iFile);

				for(UINT i = 0; i < iFile; i++)
				{
					iRes = ::DragQueryFile(hDropInfo, i, szFileName, MAX_PATH);
					if(iRes > 0)
					{
						varbstrarr.AddItem((LPCTSTR)szFileName);
					}
				}

				if(varbstrarr.ItemsCount() > 0)
				{
					m_pHost->m_EventsPtr->Fire_OnWBDrop2(m_pHost->m_thisID, 
							(short)grfKeyState, (long)pt.x, (long)pt.y, 
							&varbstrarr, &m_lEffects);
				}
				else
				{
					//Just send an empty notification
					//So at least, the client app knows
					//that drop has occured but no data
					m_pHost->m_EventsPtr->Fire_OnWBDrop(m_pHost->m_thisID, 
											(short)grfKeyState, (long)pt.x, (long)pt.y, 
											strDropFile,(long)WB_CFERROR, &m_lEffects);
				}
			}
		}
		//Release
		::ReleaseStgMedium(&stm);
	}
	//Some sort of error
	//most likely, has to do with FORMATETC
	else
	{
		switch(hr)
		{
		case DV_E_FORMATETC: //Only error we handle
			{
				//
				//HTML
				//
				FORMATETC	fehtml = { m_pHost->m_EventsPtr->m_CF_HTML, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
				hr = pDataObj->GetData(&fehtml, &stm);
				if( SUCCEEDED(hr) )
				{
					if( (stm.tymed == TYMED_HGLOBAL) && 
						(stm.hGlobal) )
					{
						//TCHAR, LPTSTR, char *
						LPTSTR lpData = (LPTSTR)GlobalLock(stm.hGlobal);
						if(lpData != NULL)
						{
							strDropFile.Append(lpData);
						}
						GlobalUnlock(stm.hGlobal);
					}
					::ReleaseStgMedium(&stm);
					m_pHost->m_EventsPtr->Fire_OnWBDrop(m_pHost->m_thisID, 
									(short)grfKeyState, (long)pt.x, (long)pt.y, 
									strDropFile,(long)WB_CFHTML, &m_lEffects);
					break;
				}
				//
				//RTF
				//
				FORMATETC	fertf = { m_pHost->m_EventsPtr->m_CF_RTF, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
				hr = pDataObj->GetData(&fertf, &stm);
				if( SUCCEEDED(hr) )
				{
					if( (stm.tymed == TYMED_HGLOBAL) && 
						(stm.hGlobal) )
					{
						//TCHAR, LPTSTR, char *
						LPTSTR lpData = (LPTSTR)GlobalLock(stm.hGlobal);
						if(lpData != NULL)
						{
							strDropFile.Append(lpData);
						}
						GlobalUnlock(stm.hGlobal);
					}
					::ReleaseStgMedium(&stm);
					m_pHost->m_EventsPtr->Fire_OnWBDrop(m_pHost->m_thisID, 
									(short)grfKeyState, (long)pt.x, (long)pt.y, 
									strDropFile,(long)WB_CFRTF, &m_lEffects);
					break;
				}
				//Enum possible formats supported by this IDataObject instance
				//As soon as find one that is acceptable, we use that one.
				//The value DATADIR_GET enumerates the formats that can be passed in to
				//a call to IDataObject::GetData. The value DATADIR_SET enumerates
				//those formats that can be passed in to a call to IDataObject::SetData.
				//    DATADIR_GET = 1, 
				//    DATADIR_SET = 2, 
				bool gotit = false;
				IEnumFORMATETC *enumfe;
				FORMATETC	getfe = { m_pHost->m_EventsPtr->m_CF_URL, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
				HRESULT rethr = pDataObj->EnumFormatEtc(DATADIR_GET, &enumfe);
				if((enumfe) && (SUCCEEDED(rethr)) )
				{
					while(enumfe->Next(1, &getfe, 0) == S_OK)
					{
						if( (getfe.cfFormat == m_pHost->m_EventsPtr->m_CF_URL) ||
							(getfe.cfFormat == CF_TEXT) ||
							(getfe.cfFormat == CF_OEMTEXT) ||
							(getfe.cfFormat == CF_UNICODETEXT) ) //No UNICODE?
						{
							//Try again
							hr = pDataObj->GetData(&getfe, &stm);
							if( SUCCEEDED(hr) )
							{
								if( (stm.tymed == TYMED_HGLOBAL) && 
									(stm.hGlobal) )
								{
									LPTSTR lpData = (LPTSTR)GlobalLock(stm.hGlobal);
									if(lpData != NULL)
									{
										strDropFile.Append(lpData);
										gotit = true;
									}
									GlobalUnlock(stm.hGlobal);
								}
								::ReleaseStgMedium(&stm);
							}
							break;
						}
/*
//Other formats to handle, File Contents, Net Resource, ...
						else
						{
							//Registered format range
							//if( (getfe.cfFormat > 0xC000) && 
							//	(getfe.cfFormat < 0xFFFF) )
							
							if( (getfe.cfFormat == m_pHost->m_EventsPtr->m_CF_FILEGROUPDESCRIPTORA) ||
								(getfe.cfFormat == m_pHost->m_EventsPtr->m_CF_FILECONTENTS) )
							{
								hr = pDataObj->GetData(&getfe, &stm);
								if( SUCCEEDED(hr) )
								{
									if( (stm.tymed == TYMED_HGLOBAL) && 
										(stm.hGlobal) )
									{
										WBFILEGROUPDESCRIPTORA *hFile = (WBFILEGROUPDESCRIPTORA*)GlobalLock(stm.hGlobal);
										if(hFile->cItems > 0)
										{
											if(hFile->fgd[0].cFileName)
											{
												USES_CONVERSION;
												strDropFile.AppendBSTR(T2BSTR(hFile->fgd[0].cFileName));
											}
										}
										GlobalUnlock(stm.hGlobal);
									}
									::ReleaseStgMedium(&stm);
								}
								break;
							}
						}
*/
					} //End while

					//MSDN:
					//The caller is responsible for calling
					//IEnumFormatEtc::Release when it is finished with the enumeration.
					enumfe->Release();
					//Notify client, regardless
					if(gotit == true)
					{
						m_pHost->m_EventsPtr->Fire_OnWBDrop(m_pHost->m_thisID, 
								(short)grfKeyState, (long)pt.x, (long)pt.y, 
								strDropFile,(long)WB_CFTEXT, &m_lEffects);
					}
					else
					{
						m_pHost->m_EventsPtr->Fire_OnWBDrop(m_pHost->m_thisID, 
								(short)grfKeyState, (long)pt.x, (long)pt.y, 
								strDropFile,(long)WB_CFERROR, &m_lEffects);
					}
				}
			}
			break;
		case DV_E_LINDEX :
		case DV_E_TYMED:
		case DV_E_DVASPECT:
		case OLE_E_NOTRUNNING:
		case STG_E_MEDIUMFULL:
			{
				m_pHost->m_EventsPtr->Fire_OnWBDrop(m_pHost->m_thisID, 
						(short)grfKeyState, (long)pt.x, (long)pt.y, 
						strDropFile,(long)WB_CFERROR, &m_lEffects);
			}
			break;
		default:
			break;
		}
	}

	//Finish things up
	*pdwEffect = static_cast<unsigned long>(m_lEffects);
	return S_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////
//WBClientSite
/////////////////////////////////////////////////////////////////////////////////////////

WBClientSite::WBClientSite(IWB* pFrameSite) { m_pHost = pFrameSite; }
WBClientSite::~WBClientSite() { m_pHost = NULL; }

// IUnknown
STDMETHODIMP WBClientSite::QueryInterface(REFIID iid, void ** ppvObject)
{
	return m_pHost->QueryInterface(iid, ppvObject);
	
}

ULONG STDMETHODCALLTYPE WBClientSite::AddRef()
{
	return m_pHost->AddRef(); 
}

ULONG STDMETHODCALLTYPE WBClientSite::Release()
{
	return m_pHost->Release(); 
}

// IOleClientSite
STDMETHODIMP WBClientSite::SaveObject()
{ return E_NOTIMPL; }

STDMETHODIMP WBClientSite::GetMoniker(DWORD dwAssign, DWORD dwWhichMoniker, IMoniker ** ppmk)
{ return E_NOTIMPL; }

STDMETHODIMP WBClientSite::OnShowWindow(BOOL fShow)
{ return E_NOTIMPL; }

STDMETHODIMP WBClientSite::RequestNewObjectLayout()
{ return E_NOTIMPL; }

STDMETHODIMP WBClientSite::GetContainer(LPOLECONTAINER FAR* ppContainer)
{ return E_NOTIMPL; }

STDMETHODIMP WBClientSite::ShowObject()
{
	return S_OK; 
}

/////////////////////////////////////////////////////////////////////////////////////////
//WBInPlaceSite
/////////////////////////////////////////////////////////////////////////////////////////

WBInPlaceSite::WBInPlaceSite(IWB* pFrameSite) { m_pHost = pFrameSite; }
WBInPlaceSite::~WBInPlaceSite() { m_pHost = NULL; }

// IUnknown
STDMETHODIMP WBInPlaceSite::QueryInterface(REFIID iid, void ** ppvObject)
{
	return m_pHost->QueryInterface(iid, ppvObject);
	
}

ULONG STDMETHODCALLTYPE WBInPlaceSite::AddRef()
{
	return m_pHost->AddRef(); 
}

ULONG STDMETHODCALLTYPE WBInPlaceSite::Release()
{
	return m_pHost->Release(); 
}

// IOleWindow
STDMETHODIMP WBInPlaceSite::GetWindow(HWND * phwnd)
{
	*phwnd = m_pHost->m_hwndParent;
	return S_OK;
}

STDMETHODIMP WBInPlaceSite::ContextSensitiveHelp(BOOL fEnterMode)
{return E_NOTIMPL;}

// IOleInPlaceSite
STDMETHODIMP WBInPlaceSite::CanInPlaceActivate(void) //GotFocus
{
	return S_OK;
}

STDMETHODIMP WBInPlaceSite::OnInPlaceActivate(void)
{
	return S_OK;
}

STDMETHODIMP WBInPlaceSite::OnUIActivate(void)
{
	return S_OK;
}

STDMETHODIMP WBInPlaceSite::GetWindowContext(IOleInPlaceFrame **ppFrame,
                                                        IOleInPlaceUIWindow **ppDoc,
                                                        LPRECT lprcPosRect, LPRECT lprcClipRect,
                                                        LPOLEINPLACEFRAMEINFO lpFrameInfo)
{
	return E_NOTIMPL;
/*	
	//Implement the other two interfaces-sheshsh
    *ppFrame = (IOleInPlaceFrame *) m_pHost->m_pInPlaceFrame;
    *ppDoc = NULL;
	
	CopyRect(lprcPosRect,&m_pHost->rWindowPos);
	CopyRect(lprcClipRect,&m_pHost->rWindowPos);

	//GetClientRect(m_pHost->m_hwndParent, lprcPosRect);
	//GetClientRect(m_pHost->m_hwndParent, lprcClipRect);
	
	lpFrameInfo->cb = sizeof(LPOLEINPLACEFRAMEINFO);
	lpFrameInfo->fMDIApp = false;
	lpFrameInfo->hwndFrame = m_pHost->m_hwndParent;
	lpFrameInfo->haccel = NULL;
	lpFrameInfo->cAccelEntries = 0;
	(*ppFrame)->AddRef();
	return S_OK;

	//Make our own haccel table, need to be specific
	HACCEL hret = LoadAccelerators(_Module.GetResourceInstance(), 
											MAKEINTRESOURCE(IDR_WBACCEL));
	if(FAILED(hret))
	{
		Alert(_T("Failed to load accelator?"));
		lpFrameInfo->haccel = NULL;
		lpFrameInfo->cAccelEntries = 0;
	}
	else
	{
		lpFrameInfo->haccel = hret;
		lpFrameInfo->cAccelEntries = 2;
	}
	(*ppFrame)->AddRef();
	return S_OK;
	*/
}

STDMETHODIMP WBInPlaceSite::Scroll(SIZE scrollExtant)
{return E_NOTIMPL;}

STDMETHODIMP WBInPlaceSite::OnUIDeactivate(BOOL fUndoable)
{return E_NOTIMPL;}

STDMETHODIMP WBInPlaceSite::OnInPlaceDeactivate(void)
{return E_NOTIMPL;}

STDMETHODIMP WBInPlaceSite::DiscardUndoState(void)
{return E_NOTIMPL;}

STDMETHODIMP WBInPlaceSite::DeactivateAndUndo(void)
{return E_NOTIMPL;}

//Can be used to resize parent container.
STDMETHODIMP WBInPlaceSite::OnPosRectChange(LPCRECT lprcPosRect)
{return E_NOTIMPL;}

//////////////////////////////////////////////////////////////////////
//WBEventDispatch
//////////////////////////////////////////////////////////////////////

WBEventDispatch::WBEventDispatch(IWB* pFrameSite)
{
	m_pHost = pFrameSite;
	//Default
	m_dwDLControl = DLCTL_DLIMAGES | DLCTL_VIDEOS | DLCTL_BGSOUNDS;
	m_bSendSourceOnDocComplete = false;
	m_pszStrDoc = NULL;
	m_ZeroLenStr = L"";
}
WBEventDispatch::~WBEventDispatch()
{
	m_dwDLControl = 0;
	m_pHost = NULL;
}

// IUnknown
STDMETHODIMP WBEventDispatch::QueryInterface(REFIID iid, void ** ppvObject)
{
	return m_pHost->QueryInterface(iid, ppvObject);
	
}

ULONG STDMETHODCALLTYPE WBEventDispatch::AddRef()
{
	return m_pHost->AddRef(); 
}

ULONG STDMETHODCALLTYPE WBEventDispatch::Release()
{
	return m_pHost->Release();
}

// IDispatch
STDMETHODIMP WBEventDispatch::GetTypeInfoCount(unsigned int FAR* pctinfo)
{ return E_NOTIMPL; }

STDMETHODIMP WBEventDispatch::GetTypeInfo(unsigned int iTInfo, LCID  lcid,
                                                         ITypeInfo FAR* FAR*  ppTInfo)
{ return E_NOTIMPL; }

STDMETHODIMP WBEventDispatch::GetIDsOfNames(REFIID riid,
								OLECHAR FAR* FAR* rgszNames,
								unsigned int cNames,
								LCID lcid,
								DISPID FAR* rgDispId)
{ return E_NOTIMPL; }

STDMETHODIMP WBEventDispatch::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid,
                                                    WORD wFlags, DISPPARAMS FAR* pDispParams,
                                                    VARIANT FAR* parResult,
                                                    EXCEPINFO FAR* pExcepInfo,
                                                    unsigned int FAR* puArgErr) 
{
	//VARIANT_FALSE = ((VARIANT_BOOL)0)
	//VARIANT_TRUE = ((VARIANT_BOOL)-1)

	//The pDispParams are in reverse order
	//BeforeNavigate2 Cancel=[0], Headers[1], ...pDisp=[6]
	
    //return DISP_E_MEMBERNOTFOUND;

	USES_CONVERSION;
	switch (dispIdMember)
	{
		case DISPID_BEFORENAVIGATE2:
			{
				if((pDispParams->cArgs >= 7) && (pDispParams->rgvarg[0].vt == (VT_BOOL | VT_BYREF)))
				{
					//Cancel = false
					//((*pDispParams).rgvarg)[0].boolVal = FALSE;
					//Dereferencing
					//*V_BOOLREF(&pDispParams->rgvarg[0]) = VARIANT_TRUE;
					*(pDispParams->rgvarg[0].pboolVal)  = VARIANT_FALSE;
					if(m_pHost->m_EventsPtr)
					{
						m_pHost->m_EventsPtr->Fire_BeforeNavigate2(m_pHost->m_thisID,
							pDispParams->rgvarg[5].pvarVal,
							pDispParams->rgvarg[6].pdispVal,
							pDispParams->rgvarg[4].pvarVal, //VT_BSTR
							pDispParams->rgvarg[3].pvarVal, //VT_BSTR
							pDispParams->rgvarg[2].pvarVal, //VT_BYREF|VT_VARIANT
							pDispParams->rgvarg[1].pvarVal, //VT_BSTR
							pDispParams->rgvarg[0].pboolVal);
					}
							//&pDispParams->rgvarg[0].boolVal);
					pDispParams->rgvarg[4].bstrVal = NULL; //Must be set to NULL
//This part must be done from app, not here
//if(*(pDispParams->rgvarg[0].pboolVal) == VARIANT_TRUE)
//{
//	m_pHost->pWebBrowser->Stop();
//	m_pHost->pWebBrowser->Navigate(m_pHost->m_EventsPtr->m_Startup ,NULL,NULL,NULL,NULL);
//}
				}
			}
			break;
		//In Internet Explorer 6 or later, the IWebBrowser2::Navigate2 event fires only after
		//the first navigation made in code. It does not fire when a user
		//clicks a link on a Web page.
		//
        // [0]: URL - VT_BSTR
	    //
		case DISPID_NAVIGATECOMPLETE2: //Need to add isTopLevel
			{
				if(pDispParams->cArgs >= 2 && pDispParams->rgvarg[1].vt == VT_DISPATCH)
				{
					if(m_pHost->m_EventsPtr)
						m_pHost->m_EventsPtr->Fire_NavigateComplete2(m_pHost->m_thisID,
										pDispParams->rgvarg[0].pvarVal,
										pDispParams->rgvarg[1].pdispVal);
				}
			}
			break;
		case DISPID_PROGRESSCHANGE:
			if(pDispParams->cArgs >= 2 && pDispParams->rgvarg[0].vt == VT_I4)
			{
				if(m_pHost->m_EventsPtr)
					m_pHost->m_EventsPtr->Fire_ProgressChange(m_pHost->m_thisID, 
													pDispParams->rgvarg[1].lVal,
													pDispParams->rgvarg[0].lVal);
			}
			break;
		//
        // [0]: New status bar text - BSTR
	    //
		case DISPID_STATUSTEXTCHANGE:
			if (pDispParams->cArgs > 0 && pDispParams->rgvarg[0].vt == VT_BSTR)
			{
				if(m_pHost->m_EventsPtr)
					m_pHost->m_EventsPtr->Fire_StatusTextChange(m_pHost->m_thisID, 
													pDispParams->rgvarg[0].bstrVal);
			}
			break;
/*
> What I'd like to know is if there is a foolproof way for me to get the 
> source code of the main webpage and every frame immediately after they 
> are downloaded and before any scripts have run. 


Query the document object for IPersistStreamInit, call Save (you can 
create an in-memory IStream implementation with CreateStreamOnHGlobal). 
This gets the HTML exactly as the server sent it. Do it from, say, 
DocumentComplete event
*/
		//
        // [0]: URL - VT_BSTR
	    //
		case DISPID_DOCUMENTCOMPLETE:
			{
				if(pDispParams->cArgs >= 2 && pDispParams->rgvarg[1].vt == VT_DISPATCH)
				{
					LPDISPATCH lpWBDisp;
					HRESULT    hr;
					//Get the IDispatch of our browser for comparison
					hr = m_pHost->pUnknown->QueryInterface(IID_IDispatch, 
							reinterpret_cast<void **>(&lpWBDisp));
					if(SUCCEEDED(hr) && lpWBDisp)
					{
						//CComBSTR url = ((*pDispParams).rgvarg)[0].pvarVal->bstrVal;
						//Fire_DocumentCompleteWBEx m_pszStrDoc
						if(lpWBDisp == pDispParams->rgvarg[1].pdispVal)
						{
							//Top-level Window object
							if(m_pHost->m_EventsPtr)
							{
								//Do we want the source before javascripts exec
								if(m_bSendSourceOnDocComplete == true)
								{
									hr = WBHTMLDocAsStream(lpWBDisp);
									if( (SUCCEEDED(hr)) && (m_pszStrDoc) )
									{
										m_pHost->m_EventsPtr->Fire_DocumentCompleteWBEx(
													m_pHost->m_thisID,
													pDispParams->rgvarg[0].pvarVal,
													pDispParams->rgvarg[1].pdispVal,
													VARIANT_TRUE,
													T2BSTR(m_pszStrDoc));
										free (m_pszStrDoc);
										m_pszStrDoc = NULL;
									}
									else
									{
										m_pHost->m_EventsPtr->Fire_DocumentCompleteWBEx(
													m_pHost->m_thisID,
													pDispParams->rgvarg[0].pvarVal,
													pDispParams->rgvarg[1].pdispVal,
													VARIANT_TRUE,
													m_ZeroLenStr);
									}
								}
								else
								{
									m_pHost->m_EventsPtr->Fire_DocumentComplete(
												m_pHost->m_thisID,
												pDispParams->rgvarg[0].pvarVal,
												pDispParams->rgvarg[1].pdispVal,
												VARIANT_TRUE);
								}
							}
						}
						else
						{
							//Frame, IFrames, ...
							if(m_pHost->m_EventsPtr)
							{
								if(m_bSendSourceOnDocComplete == true)
								{
									hr = WBHTMLDocAsStream(pDispParams->rgvarg[1].pdispVal);
									if( (SUCCEEDED(hr)) && (m_pszStrDoc) )
									{
										m_pHost->m_EventsPtr->Fire_DocumentCompleteWBEx(
													m_pHost->m_thisID,
													pDispParams->rgvarg[0].pvarVal,
													pDispParams->rgvarg[1].pdispVal,
													VARIANT_FALSE,
													T2BSTR(m_pszStrDoc));
										free (m_pszStrDoc);
										m_pszStrDoc = NULL;
									}
									else
									{
										m_pHost->m_EventsPtr->Fire_DocumentCompleteWBEx(
													m_pHost->m_thisID,
													pDispParams->rgvarg[0].pvarVal,
													pDispParams->rgvarg[1].pdispVal,
													VARIANT_FALSE,
													m_ZeroLenStr);
									}
								}
								else
								{
									m_pHost->m_EventsPtr->Fire_DocumentComplete(
												m_pHost->m_thisID,
												pDispParams->rgvarg[0].pvarVal,
												pDispParams->rgvarg[1].pdispVal,
												VARIANT_FALSE);
								}
							}
						}
						lpWBDisp->Release();
					}
					
				}
			}
			break;
		//
		// [0]: Document title - BSTR
		//
		case DISPID_TITLECHANGE:
			{
				if (pDispParams->cArgs > 0 && pDispParams->rgvarg[0].vt == VT_BSTR)
				{
					if(m_pHost->m_EventsPtr)
						m_pHost->m_EventsPtr->Fire_TitleChange(m_pHost->m_thisID, 
														pDispParams->rgvarg[0].bstrVal);
				}
			}
			break;
		case DISPID_DOWNLOADBEGIN:
			{
				// Enable the stop menu item and toolbar button
				if(m_pHost->m_EventsPtr)
					m_pHost->m_EventsPtr->Fire_DownloadBegin(m_pHost->m_thisID);
			}
	        break;
		case DISPID_DOWNLOADCOMPLETE:
			{
				if(m_pHost->m_EventsPtr)
					m_pHost->m_EventsPtr->Fire_DownloadComplete(m_pHost->m_thisID);
			}
			break;
		case DISPID_WINDOWSETHEIGHT:
			if(pDispParams->cArgs > 0 && pDispParams->rgvarg[0].vt == VT_I4)
			{
				if(m_pHost->m_EventsPtr)
					m_pHost->m_EventsPtr->Fire_WindowSetHeight(m_pHost->m_thisID,
													pDispParams->rgvarg[0].lVal);
			}
			break;
		case DISPID_WINDOWSETLEFT:
			if(pDispParams->cArgs > 0 && pDispParams->rgvarg[0].vt == VT_I4)
			{
				if(m_pHost->m_EventsPtr)
					m_pHost->m_EventsPtr->Fire_WindowSetLeft(m_pHost->m_thisID,
													pDispParams->rgvarg[0].lVal);
			}
			break;
		case DISPID_WINDOWSETTOP:
			if(pDispParams->cArgs > 0 && pDispParams->rgvarg[0].vt == VT_I4)
			{
				if(m_pHost->m_EventsPtr)
					m_pHost->m_EventsPtr->Fire_WindowSetTop(m_pHost->m_thisID,
													pDispParams->rgvarg[0].lVal);
			}
			break;
		case DISPID_WINDOWSETWIDTH:
			if(pDispParams->cArgs > 0 && pDispParams->rgvarg[0].vt == VT_I4)
			{
				if(m_pHost->m_EventsPtr)
					m_pHost->m_EventsPtr->Fire_WindowSetWidth(m_pHost->m_thisID,
													pDispParams->rgvarg[0].lVal);
			}
			break;
		case DISPID_WINDOWCLOSING:
			{
				if((pDispParams->cArgs >= 2) && (pDispParams->rgvarg[0].vt == (VT_BOOL | VT_BYREF)))
				{
					//Initially, window is not allowed to close, Cancel = true
					//((*pDispParams).rgvarg)[0].boolVal = FALSE;
					*(pDispParams->rgvarg[0].pboolVal)  = VARIANT_TRUE;
					//IsChildWindow = TRUE => Window was created from script.
					if(m_pHost->m_EventsPtr)
						m_pHost->m_EventsPtr->Fire_WindowClosing(m_pHost->m_thisID,
														pDispParams->rgvarg[1].boolVal,
														pDispParams->rgvarg[0].pboolVal);
														//&pDispParams->rgvarg[0].boolVal);
				}
			}
			break;
		case DISPID_COMMANDSTATECHANGE:
			if(pDispParams->cArgs >= 2 && pDispParams->rgvarg[0].vt == VT_BOOL)
			{
				if(m_pHost->m_EventsPtr)
					m_pHost->m_EventsPtr->Fire_CommandStateChange(m_pHost->m_thisID,
														pDispParams->rgvarg[1].lVal,
														pDispParams->rgvarg[0].boolVal);
			}
			break;
		case DISPID_FILEDOWNLOAD:
			//*(pDispParams->rgvarg[0].pboolVal)  = VARIANT_FALSE;
			if((pDispParams->cArgs >= 2) && (pDispParams->rgvarg[0].vt == (VT_BOOL | VT_BYREF)))
			{
				//Initially all filedownload is done by us
				//if m_useieforfiledl == false, then we are using FileDownloadEx event
				//So we don't bother generating an event here
				if(m_pHost->m_useieforfiledl == true)
				{
					*(pDispParams->rgvarg[0].pboolVal)  = VARIANT_TRUE;
					if(m_pHost->m_EventsPtr)
						m_pHost->m_EventsPtr->Fire_FileDownload(m_pHost->m_thisID,
													pDispParams->rgvarg[1].pboolVal,
													pDispParams->rgvarg[0].pboolVal);
				}
			}
			break;
		case DISPID_CLIENTTOHOSTWINDOW:
			if((pDispParams->cArgs >= 2) && (pDispParams->rgvarg[0].vt == (VT_BYREF|VT_I4)))
			{
				if(m_pHost->m_EventsPtr)
					m_pHost->m_EventsPtr->Fire_ClientToHostWindow(m_pHost->m_thisID,
													pDispParams->rgvarg[1].plVal,
													pDispParams->rgvarg[0].plVal);
												//&pDispParams->rgvarg[1].lVal,
												//&pDispParams->rgvarg[0].lVal);
			}
			break;
		//
        // [3]: VT_BSTR
		// [2]: VT_BSTR
		// [1]: VT_I4 (LONG)
	    //
		case DISPID_NAVIGATEERROR:
			if((pDispParams->cArgs >= 5) && 
				(pDispParams->rgvarg[0].vt == (VT_BOOL | VT_BYREF)) )
			{
				//Cancel = false //default
				*(pDispParams->rgvarg[0].pboolVal)  = VARIANT_FALSE;
				if(m_pHost->m_EventsPtr)
					m_pHost->m_EventsPtr->Fire_NavigateError(m_pHost->m_thisID,
													pDispParams->rgvarg[4].pdispVal,
													pDispParams->rgvarg[3].pvarVal,
													pDispParams->rgvarg[2].pvarVal,
													pDispParams->rgvarg[1].pvarVal,
													pDispParams->rgvarg[0].pboolVal);
			}
	        ////Extract the status code from the DISPPARAMS structure
		    //VARIANT * vt_statuscode = pDispParams->rgvarg[1].pvarVal;
			//DWORD  dwStatusCode =  vt_statuscode->lVal;
	        ////Extract the event's IDispatch pointer
		    //IDispatch *pdispFiredEvent = pDispParams->rgvarg[4].pdispVal;
			break;
		case DISPID_SETSECURELOCKICON:
			{
				if(pDispParams->cArgs > 0 && pDispParams->rgvarg[0].vt == VT_I4)
				{
					if(m_pHost->m_EventsPtr)
						m_pHost->m_EventsPtr->Fire_SetSecureLockIcon(m_pHost->m_thisID,
															pDispParams->rgvarg[0].lVal);
				}
			}
			break;
		case DISPID_NEWWINDOW2:
			{
				//Initially cancel
				//Cancel = true
				if((pDispParams->cArgs >= 2) && 
					(pDispParams->rgvarg[0].vt == (VT_BOOL | VT_BYREF)) )
				{
					*(pDispParams->rgvarg[0].pboolVal)  = VARIANT_TRUE;
					if(m_pHost->m_EventsPtr)
						m_pHost->m_EventsPtr->Fire_NewWindow2(m_pHost->m_thisID,
														pDispParams->rgvarg[1].ppdispVal,
														pDispParams->rgvarg[0].pboolVal);
				}
			}
			break;
		//DWebBrowserEvents2::NewWindow3 is raised before DWebBrowserEvents2::NewWindow2.
		//XP sp2 only
		//
		// [4]: VT_DISPATCH | VT_BYREF
		// [3]: VT_BOOL | VT_BYREF
        // [2]: DWORD (long, NEW_WINDOW3_FLAGS enum)
		// [1]: VT_BSTR
		// [0]: VT_BSTR
	    //
		case DISPID_NEWWINDOW_WB3:
			{
				if( (pDispParams->cArgs >= 5) && 
					(pDispParams->rgvarg[3].vt == (VT_BOOL | VT_BYREF)) )
				{
					//Initially cancel
					*(pDispParams->rgvarg[3].pboolVal)  = VARIANT_TRUE;
					
					long lflags = 0;
					if(pDispParams->rgvarg[2].vt == VT_I4)
						long lflags = pDispParams->rgvarg[2].lVal;
					else if(pDispParams->rgvarg[2].vt == VT_UI4)
						long lflags = static_cast<long>(pDispParams->rgvarg[2].ulVal);

					//Send the event
					if(m_pHost->m_EventsPtr)
					{
						m_pHost->m_EventsPtr->Fire_NewWindow3(m_pHost->m_thisID,
														pDispParams->rgvarg[4].ppdispVal,
														pDispParams->rgvarg[3].pboolVal,
														lflags, 
														pDispParams->rgvarg[1].bstrVal,
														pDispParams->rgvarg[0].bstrVal);
					}
				}
			}
			break;
		//
		//[0 in] VT_BOOL that indicates whether the current top-level URL has violated
		//the browser's privacy settings.
		//True or False
		case DISPID_PRIVACYIMPACTEDSTATECHANGE:
			if(pDispParams->cArgs >= 1 && pDispParams->rgvarg[0].vt == VT_BOOL)
			{
				if(pDispParams->rgvarg[0].boolVal) //True or False
				{
					if(m_pHost->m_EventsPtr)
						m_pHost->m_EventsPtr->Fire_PrivacyImpactedStateChange(
										m_pHost->m_thisID, 
										VARIANT_TRUE);
				}
				else
				{
					if(m_pHost->m_EventsPtr)
						m_pHost->m_EventsPtr->Fire_PrivacyImpactedStateChange(
										m_pHost->m_thisID, 
										VARIANT_FALSE);
				}
														//or *(pDispParams->rgvarg[0].pboolVal));
			}
			break;
		case DISPID_WINDOWSETRESIZABLE:
			if(pDispParams->cArgs >= 1 && pDispParams->rgvarg[0].vt == VT_BOOL)
			{
				if(m_pHost->m_EventsPtr)
					m_pHost->m_EventsPtr->Fire_WindowSetResizable(m_pHost->m_thisID,
														pDispParams->rgvarg[0].boolVal);
			}
			break;
		//The DISPID_AMBIENT_* and DLCTL_* values are defined in Mshtmdid.h
		//
		// DISPID for Download Control
		//
		//CComVariant vtResult(static_cast<long>(m_dwDLControl));
		//*parResult = vtResult;
		//This only hits for every new webbrowser created
		//Or by setting globalDOCHOSTUIFLAGS property
		//which in turn calls OleControl.OnAmbientChanged forcing
		//MSHTML to call us here to get the flags.
		//Needs a refesh for the new flags to take effect
		case DISPID_AMBIENT_DLCONTROL:
			{
				if(parResult->vt == VT_EMPTY)
				{
					parResult->vt = VT_I4;
					parResult->lVal = static_cast<long>(m_dwDLControl);
				}
			}
			break;
//		// Change user agent for this web browser host during hyperlinks
			//MSHTML will also ask for a new user agent via DISPID_AMBIENT_USERAGENT
			//when navigating to clicked hyperlinks. This ambient property can be
			//overridden, but it is not used when programmatically calling
			//the Navigate method; it will also not cause the userAgent
			//property of the DOM's navigator object or clientInformation
			//behavior to be altered - this property will always reflect
			//Internet Explorer's own UserAgent string. 
//		case DISPID_AMBIENT_USERAGENT:
//		   {
//			  CString strUserAgent("MyWebBrowserHost");
//			  if(parResult->vt == VT_EMPTY)
//			  {
//				parResult->vt = VT_BSTR;
//				parResult->bstrVal = ::SysAllocString(T2OLE(strUserAgent));
//			  {
//		   }
//		   break;
	    default:
			return DISP_E_MEMBERNOTFOUND;
	}
	return S_OK;
}

HRESULT WBEventDispatch::WBHTMLDocAsStream(LPDISPATCH pDisp)
{
	HRESULT hr = S_OK;
	CComPtr<IWebBrowser2> thisBrowser;
	IStream* pStream = NULL;
	CComPtr<IDispatch> pHtmlDoc;
	IPersistStreamInit* pPersistStreamInit = NULL;
	
	//Get the IWebBrowser2 from dispatch
	hr = pDisp->QueryInterface(IID_IWebBrowser2, 
			reinterpret_cast<void **>(&thisBrowser));
	if( (FAILED(hr)) || (!thisBrowser) ) return hr;


//Reported by dosuryu Mar 02 2006
//A fatal error occurs if the file of EXCEL is specified for SRC attribute of the IFRAME tag.
//<iframe SRC="book1.xls" />
//Added (!pHtmlDoc)
	// Retrieve the document object.
	hr = thisBrowser->get_Document( &pHtmlDoc );
	if( (FAILED(hr)) || (!pHtmlDoc) ) return hr;

	//Create HGLOBAL internally, free on release
	hr = CreateStreamOnHGlobal( NULL, TRUE, &pStream );
	if ( SUCCEEDED(hr) )
	{
		// Query for IPersistStreamInit.
		hr = pHtmlDoc->QueryInterface( IID_IPersistStreamInit,  
				(void**)&pPersistStreamInit );
		if ( SUCCEEDED(hr) )
		{
			hr = pPersistStreamInit->Save(pStream,FALSE);
			if ( SUCCEEDED(hr) )
			{
				//LPTSTR pszString = NULL;
				ULONG ulSizeRequired = 0;
				//Get the size
				hr = StreamStringSize((LPSTREAM)pStream, (ULONG*)&ulSizeRequired);
				if( (ulSizeRequired > 0) && (hr == S_OK) )
				{
					//Allocate
					m_pszStrDoc = (LPTSTR)malloc(ulSizeRequired + sizeof(TCHAR));
					if (m_pszStrDoc)
					{
						//Set mem + 1
						memset ((void*)m_pszStrDoc, 0, ulSizeRequired + sizeof(TCHAR));
						hr = pStream->Read((void*)m_pszStrDoc, ulSizeRequired, NULL);
						//Failed to read, free buffer
						if(FAILED(hr))
						{
							free (m_pszStrDoc);
							m_pszStrDoc = NULL;
						}
					}
				}
			}
			pPersistStreamInit->Release();
		}
		pStream->Release();
	}

	return hr;
}

//////////////////////////////////////////////////////////////////////
//WBDocHostUIHandler
//////////////////////////////////////////////////////////////////////

WBDocHostUIHandler::WBDocHostUIHandler(IWB* pFrameSite)
{
	m_pHost = pFrameSite;
	//0-default do not display
	//1- display default ctxmenu
	//2- raise event
	m_ContextMenuAction = 0;

	//Default, selecttext+no3dborder+flatscrollbars
	m_dwDocHostUIFlags = DOCHOSTUIFLAG_NO3DBORDER | DOCHOSTUIFLAG_FLAT_SCROLLBAR;
	m_dwDocHostUIDblClk = DOCHOSTUIDBLCLK_DEFAULT; //0
	//Initialize droptarget
	m_pWBDropTarget = new WBDropTarget(m_pHost);
}

WBDocHostUIHandler::~WBDocHostUIHandler() 
{
	m_dwDocHostUIFlags = (DWORD) 0;
	m_dwDocHostUIDblClk = (DWORD) 0;
	m_ContextMenuAction = 0;
	m_pHost = NULL; 
	if(m_pWBDropTarget)
	{
		//delete object
		delete m_pWBDropTarget; //->Release();
		m_pWBDropTarget = NULL;
	}
}

// IUnknown
STDMETHODIMP WBDocHostUIHandler::QueryInterface(REFIID iid, void ** ppvObject)
{
	return m_pHost->QueryInterface(iid, ppvObject);
	
}

ULONG STDMETHODCALLTYPE WBDocHostUIHandler::AddRef()
{
	return m_pHost->AddRef(); 
}

ULONG STDMETHODCALLTYPE WBDocHostUIHandler::Release()
{
	return m_pHost->Release(); 
}

//ppt are screen coordinates, not client
STDMETHODIMP WBDocHostUIHandler::ShowContextMenu(DWORD dwID, POINT FAR* ppt,
							IUnknown FAR* pcmdtReserved,
                            IDispatch FAR* pdispReserved)
{

	//Display default menu
	if(m_ContextMenuAction == 1) return S_FALSE; 
	
	HRESULT hr = S_OK;
	//default- Do not display context menu
	if(m_ContextMenuAction == 0) return hr;

	//Raise event
	if(m_ContextMenuAction == 2) 
	{
		//default, do not display,
		//may change by client after triggering the event
		VARIANT_BOOL displayctm = VARIANT_FALSE;
		//POINT ptClk;

		//Convert pt to client coordinates
		//ptClk.x = ppt->x;
		//ptClk.y = ppt->y;
		//ScreenToClient(m_pHost->GetIEServerHwnd(),&ptClk);

		long ctmtype = (long)dwID;
		if(m_pHost->m_EventsPtr)
		{
			m_pHost->m_EventsPtr->Fire_OnContextMenu(m_pHost->m_thisID, ctmtype,
											ppt->x ,ppt->y,
											pdispReserved, &displayctm);
		}
		if(displayctm == VARIANT_TRUE)
		{
			hr = S_FALSE; //Display default
		}
	}
	return hr;
}
        
STDMETHODIMP WBDocHostUIHandler::GetHostInfo(DOCHOSTUIINFO FAR *pInfo)
{
	pInfo->cbSize  = sizeof(DOCHOSTUIINFO);
	pInfo->dwFlags = m_dwDocHostUIFlags;
	pInfo->dwDoubleClick = m_dwDocHostUIDblClk;
	return S_OK;
}

//pActiveObject.hwnd = Internet Explorer_Server hwnd
STDMETHODIMP WBDocHostUIHandler::ShowUI(DWORD dwID,
					IOleInPlaceActiveObject FAR* pActiveObject,
                    IOleCommandTarget FAR* pCommandTarget,
                    IOleInPlaceFrame  FAR* pFrame,
                    IOleInPlaceUIWindow FAR* pDoc)
{
	if(pActiveObject)
	   pActiveObject->GetWindow(&m_pHost->m_hwndIEServer);
/*
	   if(pActiveObject)
	   {
		   HWND thwnd;
		   HRESULT hret = pActiveObject->GetWindow(&thwnd); 
		   if(SUCCEEDED(hret))
		   {
			char printbuf[80];
			wsprintf(printbuf,"IOleInPlaceActiveObject - hwnd is %d\n",(long)thwnd);
			MessageBox(GetDesktopWindow(),printbuf,_T("IOleInPlaceActiveObject - hwnd"),MB_OK);
		   }
	   }

	if(m_pHost->pInPlaceActiveObject)
		m_pHost->pInPlaceActiveObject->Release();
	m_pHost->pInPlaceActiveObject = pActiveObject;
	if(m_pHost->pInPlaceActiveObject)
	{
		HRESULT hret;
		m_pHost->pInPlaceActiveObject->AddRef();
		//Query for IOleInPlaceUIWindow
		if(pFrame)
		{
			hret = pFrame->SetActiveObject(m_pHost->m_pInPlaceActiveObject,NULL);
			if(FAILED(hret)) Alert(_T("Failed to use IOleInPlaceFrame"));
		}
		if(pDoc)
			hret = pDoc->SetActiveObject(m_pHost->m_pInPlaceActiveObject,NULL);
		if(hret != S_OK) Alert(_T("Failed to use IOleInPlaceUIWindow"));
		return S_OK;
	}
	else
*/
	   //Have our own, so
	   return S_OK;
		//return E_NOTIMPL;
}
        
STDMETHODIMP WBDocHostUIHandler::HideUI(void)
{return S_OK;}
    
STDMETHODIMP WBDocHostUIHandler::UpdateUI(void)
{return S_OK;}
    
STDMETHODIMP WBDocHostUIHandler::EnableModeless (BOOL fEnable)
{return E_NOTIMPL;}

STDMETHODIMP WBDocHostUIHandler::OnDocWindowActivate(BOOL fActivate)
{return E_NOTIMPL;}

STDMETHODIMP WBDocHostUIHandler::OnFrameWindowActivate(BOOL fActivate)
{return E_NOTIMPL;}

STDMETHODIMP WBDocHostUIHandler::ResizeBorder(LPCRECT prcBorder, 
						IOleInPlaceUIWindow FAR* pUIWindow,
						BOOL fRameWindow)
{return E_NOTIMPL;}

STDMETHODIMP WBDocHostUIHandler::TranslateAccelerator(LPMSG lpMsg, 
						const GUID FAR* pguidCmdGroup,
                        DWORD nCmdID)
{
	//Initialize variables
	m_hr = S_FALSE; //IE default
	m_nVirtExtKey = 0;
	m_nKeyCode = (short)lpMsg->wParam;
	m_bhandled = VARIANT_FALSE; //Not handled

	//See if we have any accel keys coming through
	if (GetKeyState(VK_CONTROL) < 0)
		m_nVirtExtKey = VK_CONTROL;	//17
	else if (GetKeyState(VK_MENU) < 0)
		m_nVirtExtKey = VK_MENU;	//18
	else if (GetKeyState(VK_SHIFT) < 0)
		m_nVirtExtKey = VK_SHIFT;	//16


	if(lpMsg->message == WM_KEYDOWN)
	{
		m_pHost->m_EventsPtr->Fire_OnWBKeyDown(m_pHost->m_thisID,
			m_nKeyCode, m_nVirtExtKey, &m_bhandled);
	}
	else if(lpMsg->message == WM_KEYUP)
	{
		m_pHost->m_EventsPtr->Fire_OnWBKeyUp(m_pHost->m_thisID,
			m_nKeyCode, m_nVirtExtKey, &m_bhandled);
	}

	if(m_bhandled == VARIANT_TRUE)
		m_hr = S_OK;

	return m_hr;

////////////////////////////////////////////////////////////////////////
//Depreciated
////////////////////////////////////////////////////////////////////////
//	if( (m_nVirtExtKey != 0) && 
//		(lpMsg->message != WM_CHAR) )
//		// && (lpMsg->message != WM_KEYUP) ) 
//	{			
//		// Ignore WM_CHAR.  The wParam for WM_CHAR is 
//		// the ASCII code for the character.  We only
//		// want virtual key codes.
/*
Possible values if wParam == WM_CHAR:
Any character key
BACKSPACE
ENTER (carriage return)
ESC
SHIFT+ENTER (linefeed)
TAB
*/
//		//Do not fire for keyup, just return the last hr set
//		//Was firing for keydown+up (twice)
//		if(lpMsg->message == WM_KEYUP)
//		{
//			m_hr = m_Lasthr;
//		}
//		else if(m_lAccelAction == 0) //Cancel all, well not all
//		{
//			if(m_nVirtExtKey == VK_SHIFT)
//			{
//				if( ((m_nKeyCode >= 65) && (m_nKeyCode <= 90)) ||		// A to Z
//					((m_nKeyCode >= 48) && (m_nKeyCode <= 57)) ||		// ~!@#$%^&*(
//					((m_nKeyCode >= 186) && (m_nKeyCode <= 192)) ||		// )_+{}|:
//					((m_nKeyCode >= 219) && (m_nKeyCode <= 222))		// "<>?
//				  )
//				{
//					m_Lasthr = m_hr;
//					return m_hr;
//				}
//			}
//			else
//				m_hr = S_OK; //Cancel
//		}
//		else if(m_lAccelAction == 1) //Allow all - IE default
//		{
//			//Do not allow Ctrl+O (has no meanning in this context)
//			//has to be handled by client.
//			if( (m_nVirtExtKey == VK_CONTROL) && (m_nKeyCode == 0x4F) ) //O
//				m_hr = S_OK;
//		}
//		else //Raise event
//		{
//			VARIANT_BOOL bCancel = VARIANT_FALSE; //Always do IE default
//			//Raise event
//			if(m_pHost->m_EventsPtr)
//			{
//				m_pHost->m_EventsPtr->Fire_OnAcceletorKeys(m_pHost->m_thisID,
//												m_nKeyCode, m_nVirtExtKey, &bCancel);
//			}
//			//Did client canceled?
//			if( (bCancel == VARIANT_TRUE) ||
//				((m_nVirtExtKey == VK_CONTROL) && (m_nKeyCode == 0x4F)) )
//				m_hr = S_OK; //Canceled
//		}
//	}
//	//Take note of last return value
//	m_Lasthr = m_hr;
//	return m_hr;
}

/*
MSDN:
GetOptionKeyPath and GetOverrideKeyPath Compared
You probably don't see any difference between IDocHostUIHandler::GetOptionKeyPath and
IDocHostUIHandler2::GetOverrideKeyPath. The difference between them is subtle, but 
significant. If you implement IDocHostUIHandler::GetOptionKeyPath, your WebBrowser 
Control instance will ignore any user settings for Internet Explorer. These settings 
are stored in the registry under HKEY_CURRENT_USER/Software/Microsoft/Internet Explorer. 
If you implement IDocHostUIHandler2::GetOverrideKeyPath, your WebBrowser Control instance 
will incorporate any user settings font settings, menu extensions, and so forth into the 
way it displays and behaves.

To illustrate the difference between IDocHostUIHandler::GetOptionKeyPath and 
IDocHostUIHandler2::GetOverrideKeyPath, let's take a look again at the code example 
for the section on IDocHostUIHandler::ShowContextMenu. Remember the line:

spCT->Exec(&CGID_ShellDocView, SHDVID_ADDMENUEXTENSIONS, 0, &var1, &var2);

If you've implemented IDocHostUIHandler::GetOptionKeyPath, this line would add no 
menu items to the shortcut menu because menu extension information is stored in 
the registry for the current user. If you've implemented 
IDocHostUIHandler2::GetOverrideKeyPath, this line would add any extensions 
defined for the current user under 
HKEY_CURRENT_USER/Software/Microsoft/Internet Explorer/MenuExt, 
unless you explicitly supply an empty or alternative MenuExt key in 
your custom registry key.
*/
//IDocHostUIHandler2
STDMETHODIMP WBDocHostUIHandler::GetOverrideKeyPath( LPOLESTR *pchKey, DWORD dw)
{
	HRESULT hr;
	if (pchKey)
	{
		*pchKey = NULL;
		CComBSTR str(L"");
		//Notify client
		m_pHost->m_EventsPtr->Fire_OnGetOverrideKeyPath(m_pHost->m_thisID, &str);
		//Check the length
		int len = str.Length();
		if( len > 0)
		{
			//Allocate memory
			*pchKey = (LPOLESTR)CoTaskMemAlloc((len + 1) * sizeof(WCHAR));
			if (*pchKey)
			{
				USES_CONVERSION;
				//Copy what client wants to pass
				wcscpy(*pchKey, OLE2W(str));
				*(*pchKey + len) = (OLECHAR)NULL;
				//memcpy(*pchKey, OLE2W(str), sizeof(WCHAR) * len);
				//Done
				hr = S_OK;
			}
			else
				hr = E_OUTOFMEMORY;
		}
		else
			hr = E_NOTIMPL; //S_FALSE; //
	}
    else
        hr = E_INVALIDARG;

	return hr;
}

STDMETHODIMP WBDocHostUIHandler::GetOptionKeyPath(LPOLESTR *pchKey, DWORD dw)
{
	//MSDN:
	//Even if this method is unimplemented, the parameter should be set to NULL.
	HRESULT hr;
	if (pchKey)
	{
		*pchKey = NULL;
		CComBSTR str(L"");
		m_pHost->m_EventsPtr->Fire_OnGetOptionKeyPath(m_pHost->m_thisID, &str);
		int len = str.Length();
		if( len > 0)
		{
			*pchKey = (LPOLESTR)CoTaskMemAlloc((len + 1) * sizeof(WCHAR));
			if (*pchKey)
			{
				USES_CONVERSION;
				wcscpy(*pchKey, OLE2W(str));
				*(*pchKey + len) = (OLECHAR)NULL;
				//memcpy(*pchKey, OLE2W(str), sizeof(WCHAR) * len);
				hr = S_OK;
			}
			else
				hr = E_OUTOFMEMORY;
		}
		else
			hr = E_NOTIMPL; //S_FALSE; //
	}
	else
		hr = E_INVALIDARG;

	return hr;
}

//For Custom dragdrop which MSHTML will call as needed
//We provide our own IDropTarget implementation to be able to notify the client
STDMETHODIMP WBDocHostUIHandler::GetDropTarget(IDropTarget* pDropTarget,
						IDropTarget** ppDropTarget)
{
	//Are we using IE default
	if(m_pHost->m_bAllowDragDrop == false)
		return E_NOTIMPL;
	//After every call to GetOptionKeyPath + GetOverrideKeyPath
	//which happens after a BeforeNavigate event.
	//A call to this function is made
	//Also, a Release() is called on m_pWBDropTarget object
	//if implemented
	if(ppDropTarget == NULL) return E_INVALIDARG;
	*ppDropTarget = NULL;
	if(m_pWBDropTarget)
	{
		//Provide an alternative, our own
		m_pWBDropTarget->QueryInterface(IID_IDropTarget,
							reinterpret_cast<void**>(ppDropTarget));
		return S_OK;
	}
	else
		return E_NOTIMPL;

}

// 
// Method called by the WebBrowser control when
// you call window.external.SayHello from script
//if (pHost->m_pWBEventDispatch) *ppDispatch = pHost->m_pWBEventDispatch;
//return S_OK;
STDMETHODIMP WBDocHostUIHandler::GetExternal(IDispatch** ppDispatch)
{
//		if (m_pHost->m_pWBEventDispatch) 
//		{
//			*ppDispatch = m_pHost->m_pWBEventDispatch;
//			m_pHost->m_pWBEventDispatch->AddRef();
//			return S_OK;
//		}
//		else
		return E_NOTIMPL;
}

STDMETHODIMP WBDocHostUIHandler::TranslateUrl(DWORD dwTranslate,
						OLECHAR* pchURLIn,
						OLECHAR** ppchURLOut)
{
	*ppchURLOut = NULL;
	return S_FALSE;
}

/*
From Google Newsgroups:
For your concern, I have looked through the IE source code and verified 
that it is by-design: FilterDataObject will only be called when data is 
pasted onto the HTML Document. Although the documentation does not 
explicitly mention it will be called in drag and drop situations, it 
only mentions how it interact with the clipboard. As you have agreed, 
drag and drop is base on IDataObject and not the clipboard, it implies 
that the function will not be called if the clipboard is not involved. 
To clarify these specification issues, we will make the appropriate 
changes on the documentation and make it as clear as we can. We 
apologize for the confusion made by the current documentation. 

I understand that it will be more helpful if FilterDataObject can handle 
data in drag and drop actions, which is using IDataObject. I will 
forward this concern to the product team on your behalf. Hopefully this 
feature can be applied to future versions of IE. As of Internet Explorer 
6, this function will only get called when data is pasted into the 
MSHTML.
*/
STDMETHODIMP WBDocHostUIHandler::FilterDataObject(IDataObject* pDO,
						IDataObject** ppDORet)
{
	*ppDORet = NULL;
	return S_FALSE;
}

////////////////////////////////////////////////////////////////////////
//WBDownLoadManager
////////////////////////////////////////////////////////////////////////

WBDownLoadManager::WBDownLoadManager()
{
	m_pHost = NULL;
	m_hwndIEServer = NULL;
}

WBDownLoadManager::~WBDownLoadManager()
{
	m_pHost = NULL;
	m_hwndIEServer = NULL;
	//vbLog(_T("WBDownLoadManager Destructor called."),_T("WBDownLoadManager::~WBDownLoadManager"));
}

HRESULT WBDownLoadManager::InitDownloadManager(IWB* pFrameSite)
{
 	m_pHost = pFrameSite;
 	if(m_pHost)
 		m_hwndIEServer = m_pHost->m_EventsPtr->m_hWnd; //GetIEServerHwnd();
	return S_OK;
}

STDMETHODIMP WBDownLoadManager::Download(IMoniker *pmk, IBindCtx *pbc, DWORD dwBindVerb,
										LONG grfBINDF, BINDINFO *pBindInfo,
										LPCOLESTR pszHeaders, LPCOLESTR pszRedir, UINT uiCP)
{	
	//Just a check
	//if( (m_pHost == NULL) || (m_hwndIEServer == NULL) ) return E_FAIL;
	if(!::IsWindow(m_hwndIEServer)) return E_FAIL;
	
	HRESULT hr;
	//Stream will be released in the BSCB OnDataArrival
	IStream *pstm;

	//Attempt to create our BindStatusCallBack
	WBBSCBFileDL *filedl = NULL;
	//Returns a NonAddRef pointer to a new BSCB
	//AddRef is called on this BSCB during a successfull call
	//to RegisterBindStatusCallback
	if(m_pHost->WBCreateBSCBFileDL(&filedl) != S_OK)
	{
		return E_FAIL;
	}
	//Init the BSCB
	filedl->InitByUser(m_pHost, pszHeaders);
	
	IBindStatusCallback *pPrevBSCB = NULL;
	hr = RegisterBindStatusCallback(pbc, 
			reinterpret_cast<IBindStatusCallback*>(filedl), &pPrevBSCB, 0L);
	/*
		Exception to the rule
		RegisterBindStatusCallback return E_FAIL
		Cause: Content_Disposition header returned from a server
		in response to a file download via a post or ,..
		Example: downloading attachements from Hotmail, Yahoo, ...

Unfortunately, due to no documentation regarding an E_FAIL return,
and more specifically, regarding RegisterBindStatusCallback internal workings,
I had to resort to using RevokeObjectParam on the previous BSCB and in my
implementation of BSCB, relay certain calls to the previous BSCB to make DL work.
I do not know if this is a bug or done intentionaly.
	*/

	/*
	KB article http://support.microsoft.com/default.aspx?scid=kb;en-us;274201
	Notifies the client application that this resource contained a
	Content-Disposition header that indicates that this resource is an attachment.
	The content of this resource should not be automatically displayed.
	Client applications should request permission from the user.
	This value was added for Internet Explorer 5. 
	*/

	if( (FAILED(hr)) && (pPrevBSCB) )
	{
		//RevokeObjectParam for current BSCB, so we can register our BSCB
		//LPOLESTR oParam = L"_BSCB_Holder_";
		hr = pbc->RevokeObjectParam(oBindCtxBSCBObjectParam);
		if(SUCCEEDED(hr))
		{
			//Attempt register again, should succeed now
			hr = RegisterBindStatusCallback(pbc, 
					reinterpret_cast<IBindStatusCallback*>(filedl), 0, 0L);
			if(SUCCEEDED(hr))
			{
				filedl->m_pPrevBSCB = pPrevBSCB;
				//Need to add ref to our DLMan
				filedl->AddRef();
				pPrevBSCB->AddRef();
				filedl->m_pBindCtx = pbc;
				pbc->AddRef();
			}
		}
	}

	if(SUCCEEDED(hr))
	{
		//Add to our array of dls, if hanged then client can cancel dl
		//using the Unique id assigned to this BSCB object
		m_pHost->m_EventsPtr->m_arrDL.Add(filedl);
		hr = pmk->BindToStorage(pbc, 0, IID_IStream, (void**)&pstm);
	}
	else
	{
		delete filedl;
	}
	return hr;
}

/*
	//To get URL from Moniker
	hr = S_FALSE;
	LPOLESTR sURL = NULL;
	if(pmk)
		hr = pmk->GetDisplayName(pbc, NULL, &sURL);

	//When working with sURL, use CComBSTR strUrl(sURL)
	//Otherwise, you may end up with a huge mem leak?
	
	//Free string as stated in MSDN
	//Get IMalloc interface
	IMalloc *pMalloc;
	if(CoGetMalloc((DWORD)1, &pMalloc) == S_OK)
	{
		pMalloc->Free((LPVOID)sURL);
	}
	else
		CoTaskMemFree((LPVOID)sURL);

////////////////////////////////////////////////

//How to find out if we have a pdf file
// Acrobat IAcroAXDocShim Interface 
// 3B813CE7-7C10-4F84-AD06-9DF76D97A9AA 
DEFINE_GUID(IID_Acrobat, 
	0x3B813CE7, 0x7C10, 
	0x4F84, 0xad, 
	0x06, 0x9d, 0xf7, 0x6d, 0x97, 0xa9, 0xaa);

char *p, documentURL[INTERNET_MAX_URL_L­ENGTH]; 
 char tempPath[INTERNET_MAX_URL_LENG­TH]; 
 char theURL[INTERNET_MAX_URL_LENGTH­]; 
 IDispatch *pDisp, *iAcrobat; 
 HRESULT hr; 


 // load theURL with iwebbrowser2->get_LocationURL(­);
 hr = iwebbrowser2->get_Document(&pD­isp); 
 hr = pDisp->QueryInterface(IID_Acrobat, (LPVOID *)&iAcrobat); 
 pDisp->Release(); 


 // if this is a .pdf make sure the file 
 // terminates in a .pdf suffix 

 if ((hr == S_OK) && (iAcrobat != NULL)) { 
   iAcrobat->Release(); 
   strcpy(tempPath, theURL); 
   strlwr(tempPath); 
   p = PathFindExtension(tempPath);  // find an extension? 
   if (*p == 0x00)                   // if there is not one, add one 
     strcat(p, ".pdf"); 
   else { // if the extension is not .pdf - make it .pdf 
     if (strcmp(p, ".pdf") != 0) 
       strcpy(p, ".pdf");' 
     } 
   strcpy(documentURL, PathFindFileName(tempPath)); 
  } 
  else 
    strcpy(documentURL, PathFindFileName(fixedURL)); 


*/

////////////////////////////////////////////////////////////////////////
//WBServiceProvider
/////////////////////////////////////////////////////////////////////////

WBServiceProvider::WBServiceProvider(IWB* pFrameSite)
{
	m_pHost = pFrameSite;
}

WBServiceProvider::~WBServiceProvider() 
{
	m_pHost = NULL; 
}

// IUnknown
STDMETHODIMP WBServiceProvider::QueryInterface(REFIID iid, void ** ppvObject)
{
	return m_pHost->QueryInterface(iid, ppvObject);
	
}

ULONG STDMETHODCALLTYPE WBServiceProvider::AddRef()
{
	return m_pHost->AddRef(); 
}

ULONG STDMETHODCALLTYPE WBServiceProvider::Release()
{ 
	return m_pHost->Release();
}

//Many services are queried from this function
STDMETHODIMP WBServiceProvider::QueryService(REFGUID guidService, REFIID riid, void **ppv)
{
	if( (guidService == SID_SDownloadManager) && (m_pHost->m_useieforfiledl == false) )//&& riid == IID_IDownloadManager)
	{
		CComObject<WBDownLoadManager>* pDownloadMgr;
		HRESULT hr = CComObject<WBDownLoadManager>::CreateInstance(&pDownloadMgr);
		if( (SUCCEEDED(hr)) || (pDownloadMgr) )
		{
			pDownloadMgr->InitDownloadManager(m_pHost);
			return pDownloadMgr->QueryInterface(IID_IDownloadManager, ppv);
		}
	}
	else if(guidService == SID_SInternetSecurityManager) //&& riid == IID_IInternetSecurityManager)
	{
		return m_pHost->QueryInterface(IID_IInternetSecurityManager, ppv);
	}
	else if(riid == IID_IWindowForBindingUI) //QS
	{
		return m_pHost->QueryInterface(IID_IWindowForBindingUI, ppv);
	}
	else if(riid == IID_IHttpSecurity) //QS
	{
		return m_pHost->QueryInterface(IID_IHttpSecurity, ppv);
	}
	else if(riid == IID_INewWindowManager) //sp2 QS
	{
		return m_pHost->QueryInterface(IID_INewWindowManager, ppv);
	}
//IID_IHTMLOMWindowServices SID_SHTMLOMWindowServices sp2 QS

//	else if(guidService == SID_SToplevelBrowser) //QS
//	{
//		if(m_pHost->pWebBrowser)
//			*ppv = (IWebBrowser2*)m_pHost->pWebBrowser;
//		return S_OK;
//	}
	*ppv = NULL;
    return E_NOINTERFACE;
}

////////////////////////////////////////////////////////////////////////
//WBDocHostShowUI
/////////////////////////////////////////////////////////////////////////

WBDocHostShowUI::WBDocHostShowUI(IWB* pFrameSite)
{
	m_pHost = pFrameSite;
}
WBDocHostShowUI::~WBDocHostShowUI() { m_pHost = NULL;}

// IUnknown
STDMETHODIMP WBDocHostShowUI::QueryInterface(REFIID iid, void ** ppvObject)
{ 
	return m_pHost->QueryInterface(iid, ppvObject);
	
}

ULONG STDMETHODCALLTYPE WBDocHostShowUI::AddRef()
{
	return m_pHost->AddRef(); 
}

ULONG STDMETHODCALLTYPE WBDocHostShowUI::Release()
{ 
	return m_pHost->Release(); 
}

STDMETHODIMP WBDocHostShowUI::ShowHelp(HWND hwnd,LPOLESTR pszHelpFile,
						UINT uCommand,DWORD dwData,POINT ptMouse,
						IDispatch *pDispatchObjectHit)
{
	//TODO
	//Send an event to query for an html file along with options and a cancel flag.

	return E_NOTIMPL;
	//Display our own help dialog
	/*
	IHostDialogHelper *pHDH;
	IMoniker *pUrlMoniker;
	//Add other options
	BSTR bstrOptions = SysAllocString(L"dialogHeight:30;dialogWidth:40");
	//Point to the location of the document
	BSTR bstrPath = SysAllocString(L"c:\\dialog.htm");
	//Create monikor
	CreateURLMoniker(NULL, bstrPath, &pUrlMoniker);

	HRESULT hr = CoCreateInstance(CLSID_HostDialogHelper,NULL,CLSCTX_INPROC,IID_IHostDialogHelper,(void**)(&pHDH));
	if(SUCCEEDED(hr))
	{
		//Show HTML dialog
		pHDH->ShowHTMLDialog(NULL, pUrlMoniker, NULL, bstrOptions, NULL, NULL);
	}
	SysFreeString(bstrPath);
	SysFreeString(bstrOptions);
	pUrlMoniker->Release();
	pHDH->Release();
	return S_OK;
	*/
}

STDMETHODIMP WBDocHostShowUI::ShowMessage(HWND hwnd, LPOLESTR lpstrText, 
							LPOLESTR lpstrCaption,
							DWORD dwType,LPOLESTR lpstrHelpFile,
							DWORD dwHelpContext, LRESULT *plResult)
{
	USES_CONVERSION;
	
	//return E_NOTIMPL;
	// If ShowMessage is called when you have specified no execution of ActiveX 
	// controls and there is an ActiveX control on the page, plResult is NULL
	CComBSTR sText;
	CComBSTR sCaption;
	CComBSTR sHelpFile;
	long lType = (long)dwType;
	long lHelpContext = (long)dwHelpContext;
	long lReturnValue = -1;
	//Display default message
	VARIANT_BOOL bShow = VARIANT_TRUE;
	
	if(lpstrText)
		sText = lpstrText;
	else
		sText = L"";

	if(lpstrCaption)
		sCaption = lpstrCaption;
	else
		sCaption = L"";

	if(lpstrHelpFile)
		sHelpFile = lpstrHelpFile;
	else
		sHelpFile = L"";

	m_pHost->m_EventsPtr->Fire_DocHostShowMessage(m_pHost->m_thisID, 
		(long)hwnd, sText, sCaption, lType, sHelpFile, lHelpContext,
		&lReturnValue, &bShow);

	if (bShow == VARIANT_TRUE)
	{
		if (plResult)
			*plResult = ::MessageBox(hwnd, OLE2T(sText), OLE2T(sCaption), dwType);
		else
			::MessageBox(hwnd, OLE2T(sText), OLE2T(sCaption), dwType);
	}
	else if( (lReturnValue > -1) && (plResult) )
	{
		*plResult = static_cast<HRESULT>(lReturnValue);
	}

	/*
	BSTR strText = OLE2BSTR(lpstrText);
	if(strText == NULL)
		strText = ::SysAllocString(L"No text to display.");
	
	if(m_pHost->m_EventsPtr)
	{
		m_pHost->m_EventsPtr->Fire_ShowMessage(m_pHost->m_thisID,&strText,&bShow);
	}

	if (plResult)
	{
		if (bShow == VARIANT_TRUE)
			*plResult = ::MessageBox(hwnd, OLE2T(strText), OLE2T(lpstrCaption), dwType);
			//*plResult = ::MessageBox(hwnd, OLE2T(strText), OLE2T(L"vbMHWB"), dwType);
		else
			*plResult = S_FALSE;
	}
	else
	{
		if (bShow == VARIANT_TRUE)
			::MessageBox(hwnd, OLE2T(strText), OLE2T(lpstrCaption), dwType);
			//::MessageBox(hwnd, OLE2T(strText), OLE2T(L"vbMHWB"), dwType);
	}
	if(strText)
		::SysFreeString(strText);
	*/
	return S_OK;
}

////////////////////////////////////////////////////////////////////////////////////////
//WBOleCommandTarget
////////////////////////////////////////////////////////////////////////////////////

WBOleCommandTarget::WBOleCommandTarget(IWB* pFrameSite)
{ 
	m_pHost = pFrameSite;
//	m_lScriptError = 1;
}
WBOleCommandTarget::~WBOleCommandTarget()
{ 
//	m_lScriptError = 0;
	m_pHost = NULL;
}

// IUnknown
STDMETHODIMP WBOleCommandTarget::QueryInterface(REFIID iid, void ** ppvObject)
{ 
	return m_pHost->QueryInterface(iid, ppvObject); 
	
}

ULONG STDMETHODCALLTYPE WBOleCommandTarget::AddRef()
{
	return m_pHost->AddRef(); 
}

ULONG STDMETHODCALLTYPE WBOleCommandTarget::Release()
{
	return m_pHost->Release(); 
}

STDMETHODIMP WBOleCommandTarget::QueryStatus(
	 const GUID *pguidCmdGroup,
	 ULONG cCmds,
	 OLECMD prgCmds[],
	 OLECMDTEXT *pCmdText)
{
	if(m_pHost->pOleCommandTarget)
	{
		return m_pHost->pOleCommandTarget->QueryStatus(pguidCmdGroup, cCmds,
			prgCmds, pCmdText);
	}
	else
		return OLECMDERR_E_NOTSUPPORTED;
}
	
STDMETHODIMP WBOleCommandTarget::Exec(
	const GUID *pguidCmdGroup,
	DWORD nCmdID,
	DWORD nCmdExecOpt,
	VARIANT *pvaIn,
	VARIANT *pvaOut)
{
	//NOTE:
	//if "Disable script debugging" option is unchecked, this method will not be called
	//instead you will see the dialog notifying you of a script error and asking you
	//if you want to debug the script. modify the reg key

	HRESULT hret = S_OK;
	if (pguidCmdGroup  && IsEqualGUID(*pguidCmdGroup, CGID_DocHostCommandHandler))
	{
		if(nCmdID == OLECMDID_SHOWSCRIPTERROR)  //&& (m_lScriptError != 2) )
		{
			//Adapted and modified from KB article
			//http://support.microsoft.com/kb/261003
			CComPtr<IHTMLDocument2>     pDoc;
			CComPtr<IHTMLWindow2>       pWindow;
            CComPtr<IHTMLEventObj>      pEventObj;
            BSTR						rgwszNames[5] = 
                                        { 
                                           SysAllocString(L"errorLine"),
                                           SysAllocString(L"errorCharacter"),
                                           SysAllocString(L"errorCode"),
                                           SysAllocString(L"errorMessage"),
                                           SysAllocString(L"errorUrl")
                                        };
            DISPID                      rgDispIDs[5];
			//Can use CComVariant as well
			VARIANT						rgvaEventInfo[5];
            DISPPARAMS                  params = {NULL, NULL, 0, 0};
            int	                        i = 0;
			for (i = 0; i < 5; i++)
				VariantInit(&rgvaEventInfo[i]);

            // Get the document that is currently being viewed.
            HRESULT hr = pvaIn->punkVal->QueryInterface(IID_IHTMLDocument2, (void **) &pDoc);				
            
			// Get document.parentWindow.
            if( (SUCCEEDED(hr)) && (pDoc) )
				hr = pDoc->get_parentWindow(&pWindow);

            
			// Get the window.event object.
			if( (SUCCEEDED(hr)) && (pWindow) )
	            hr = pWindow->get_event(&pEventObj);

            // Get the error info from the window.event object
			if( (SUCCEEDED(hr)) && (pEventObj) )
			{
				HRESULT hrevent = S_FALSE;
				for (i = 0; i < 5; i++) 
				{  
					// Get the property's dispID.
					hrevent = pEventObj->GetIDsOfNames(IID_NULL, &rgwszNames[i], 1, 
						LOCALE_SYSTEM_DEFAULT, &rgDispIDs[i]);
					// Get the value of the property.
					if(SUCCEEDED(hr))
					{
						hrevent = pEventObj->Invoke(rgDispIDs[i], IID_NULL, 
							LOCALE_SYSTEM_DEFAULT, DISPATCH_PROPERTYGET, 
							&params, &rgvaEventInfo[i], NULL, NULL);
					}
				}
			}

            // At this point, you would normally alert the user with 
            // the information about the error, which is now contained
            // in rgvaEventInfo[].
			VARIANT_BOOL bStopRunningScripts = VARIANT_TRUE;

			if( (SUCCEEDED(hr)) && (pEventObj) )
			{
				m_pHost->m_EventsPtr->Fire_OnShowScriptError(m_pHost->m_thisID,
					&rgvaEventInfo[0], &rgvaEventInfo[1], &rgvaEventInfo[2], 
					&rgvaEventInfo[3], &rgvaEventInfo[4], &bStopRunningScripts);
			}	
			
			for (i = 0; i < 5; i++)
			{
				SysFreeString(rgwszNames[i]);
				VariantClear(&rgvaEventInfo[i]);
			}

			(*pvaOut).vt = VT_BOOL;
			if(bStopRunningScripts == VARIANT_TRUE) //m_lScriptError == 1
			{
				//stop running scripts on the page
				(*pvaOut).boolVal = VARIANT_FALSE;
			}
			else
			{
				//continue running scripts on the page.
				(*pvaOut).boolVal = VARIANT_TRUE;
			}
		}
		else
			hret = OLECMDERR_E_NOTSUPPORTED;
	}
	else
	{
		hret = OLECMDERR_E_UNKNOWNGROUP;
	}
	return hret;

}


/////////////////////////////////////////////////////////////////////
//WBBSCBFileDL
/////////////////////////////////////////////////////////////////////

//Constructor
WBBSCBFileDL::WBBSCBFileDL()
{
	ResetInternalVars();
}

WBBSCBFileDL::WBBSCBFileDL(short iID)
{
	ResetInternalVars();
	m_Uid = iID;
}

//This is used when client app initiates the dl
//In this case OnResponse and BeginningTransaction are called
//Here we we can resume a broken dl using OnResponse, by sending additional headers
//lpPathToSave = C:\dir\filename.ext
bool WBBSCBFileDL::InitByClient(CvbWB *EventsPtr, BSTR lpUrl, BSTR lpPathToSave)
{
	m_Events = EventsPtr;
	if(m_Events)
		m_hwndEvents = m_Events->m_hWnd;

	//lpPathToSave Contains only path, no filename
	//Filename is extracted in OnProgress
	fPathToSave = lpPathToSave;
	fUrl = lpUrl;

//	USES_CONVERSION;
//	vbLog(OLE2CT(fPathToSave),_T("WBBSCBFileDL::InitByClient"));
	return true;
}

//This is used when user initiates dl, clicking on a dl link
//In this case OnResponse and BeginningTransaction are never called.
//WB queries our service provider for a download manager interface and calls download method
//in which case we create an instance of this class and set up dl
bool WBBSCBFileDL::InitByUser(IWB *pHost, LPCOLESTR UrlMonExtraHeaders)
{
	if(UrlMonExtraHeaders)
		m_strDLManExtraHeaders = UrlMonExtraHeaders;
	m_pHost = pHost;
	m_Events = m_pHost->m_EventsPtr;
	if(m_Events)
		m_hwndEvents = m_Events->m_hWnd;
	//our IWB instance id, used when firing events
	m_hostid = m_pHost->m_thisID; //thisID;
	return true;
}

WBBSCBFileDL::~WBBSCBFileDL()
{
	if(hFile != INVALID_HANDLE_VALUE)
	{
		CloseHandle(hFile);
	}
	//vbLog(_T("WBBSCBFileDL Destructor called."),_T("WBBSCBFileDL::~WBBSCBFileDL"));
}

//Urlmon.dll uses the QueryInterface method on your implementation of
//IBindStatusCallback to obtain a pointer to your IHttpNegotiate interface.
//Only if we have initiated the download from code by creating own Moniker
STDMETHODIMP WBBSCBFileDL::QueryInterface(REFIID iid, void ** ppvObject)
{
	if(ppvObject == NULL) return E_INVALIDARG;
	*ppvObject = NULL;

	if( (iid==IID_IBindStatusCallback) || (iid==IID_IUnknown) )
	{
       *ppvObject = (IBindStatusCallback*)this;
	}
	else if ( iid == IID_IHttpNegotiate )
	{
		*ppvObject = (IHttpNegotiate*)this;
	}
//	else if( iid == IID_IBindStatusCallbackHolder)
//	{
//		vbLog(_T("QueryInterface::IID_IBindStatusCallbackHolderWB"),_T("WBBSCBFileDL::QueryInterface"));
//		*ppvObject = (IBindStatusCallback*)this;
//	}

	if (NULL != *ppvObject)
	{
        AddRef();
        return S_OK;
    }

//	{
//	OLECHAR wszBuff[39];
//	int i = StringFromGUID2(iid, wszBuff, 39);
//	TCHAR szBuff[39];
//	i = WideCharToMultiByte(CP_ACP, 0, wszBuff, -1, szBuff, 39, NULL, NULL);
//	vbLog((LPCTSTR)szBuff,_T("WBBSCBFileDL::QueryInterface"));
//	}

	return E_NOINTERFACE;
}

ULONG STDMETHODCALLTYPE WBBSCBFileDL::AddRef()
{
	return ++m_cRef;
}

ULONG STDMETHODCALLTYPE WBBSCBFileDL::Release()
{
	if(--m_cRef == 0)
	{
        delete this;
		return 0;
	}
	return m_cRef;
}

//IBindStatusCallback
STDMETHODIMP WBBSCBFileDL::OnStartBinding(DWORD dwReserved, IBinding * pib)
{
	//vbLog(_T("OnStartBinding"),_T("WBBSCBFileDL::OnStartBinding"));
	//Although, MSDN, states that simply returning E_FAIL should stop the DL. But as ususal
	//it does not work as documented. Well, returnning E_FAIL will not stop the save as dlg
	//from poping up. Releasing IBinding and returning E_FAIL does the trick.
	//Cache the URLMON-provided IBinding interface so that we can control the download,
	if(m_pBinding)
		m_pBinding->Release();
	m_pBinding = pib;
	if(m_pBinding)
	{
		m_pBinding->AddRef();
	}

	if(m_pPrevBSCB)
	{
		m_pPrevBSCB->OnStopBinding(HTTP_STATUS_OK, NULL);
	}

	return S_OK;
}

STDMETHODIMP WBBSCBFileDL::GetPriority(LONG * pnPriority)
{
	return E_NOTIMPL;
}

STDMETHODIMP WBBSCBFileDL::OnLowResource(DWORD reserved)
{
	return E_NOTIMPL;
}

//If a time out occurs, then the URLMon calls Release on this object
//Gives up on DL, cool. Timeout depends on the system settings.


/*
According to MSDN, the parameter ulProgressMax in OnProgress Method of
IBindStatusCallback has the following explaination.

ulProgressMax
[in] Unsigned long integer that contains the expected maximum value of the ulProgress
parameter for the duration of calls to IBindStatusCallback::OnProgress for this bind
operation. Note that this value might change across calls to this method.
A value of zero means that the maximum value of ulProgress is unknown (for example,
in the IMoniker::BindToStorage method when the data download size is unknown). 

The reason I gave it here is the clear that this is not at all the size of the file to
download. however in most cases it gives you the size of file but this is not a reliable
source of getting file size as in some cases, it will only give you the maximum value
ulProgress can have.

You are also calculating the percent of download completed from these parameters,
which is buggy. 

Client applications can call QueryInterface on the IBinding interface to get a pointer
to the IWinInetHttpInfo interface after your implementation of the
IBindStatusCallback::OnProgress method has been called.
*/

STDMETHODIMP WBBSCBFileDL::OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText)
{ 
	USES_CONVERSION;
	//Default = Continue download
	m_vboolCancelDL = VARIANT_FALSE;
	
	//After this call we get OnDataArrival
	//Notify client and set internal vars up
	if( ulStatusCode == BINDSTATUS_BEGINDOWNLOADDATA)
	{
		//CComBSTR sTest(szStatusText);
		//vbLog(OLE2CT(sTest), _T("BINDSTATUS_BEGINDOWNLOADDATA"));
		//Get the URL resource display name and extract filename + extension
		CUrlParts parts;
		fFullSavePath.Empty();
		fFileName.Empty();
		fFileExt.Empty();
		fUrl.Empty();

		fUrl = szStatusText;
		if(parts.SplitUrl(fUrl) == true)
		{
			if(parts.GetFileNameLen() > 0)
			{
				fFileName = parts.GetFileNameAsBSTR();
			}
			if(parts.GetFileExtensionLen() > 0)
			{
				fFileExt =  parts.GetFileExtensionAsBSTR(); 
			}
		}
		parts.ResetBuffers();

			if( (fFileName.Length() == 0) && (m_pPrevBSCB) )
			{
				//Grab the Content_Disposition header to get the filename
				//Content-Disposition: attachment; filename=AllApiDemo.zip
				//returns:
				//attachment; filename=AllApiDemo.zip
				if(m_pBinding)
				{
					//Get raw request headers and send them to client
					CComPtr<IWinInetHttpInfo> spWinInetHttpInfo;
					CComPtr<IBinding> pBinding = m_pBinding;
					HRESULT hrTemp = pBinding->QueryInterface(IID_IWinInetHttpInfo,
						reinterpret_cast<void**>(&spWinInetHttpInfo));
					if( (SUCCEEDED(hrTemp)) && (spWinInetHttpInfo) )
					{
						DWORD size = 0;
						DWORD flags = 0;
						hrTemp = spWinInetHttpInfo->QueryInfo( HTTP_QUERY_CONTENT_DISPOSITION,
							0, &size, &flags, 0);
						if(SUCCEEDED(hrTemp))
						{
							LPSTR pbuf = new char[size+1];
							if(pbuf)
							{
								pbuf[size] = '\0';
								hrTemp = spWinInetHttpInfo->QueryInfo( HTTP_QUERY_CONTENT_DISPOSITION,
									pbuf, &size, &flags, 0);
								if( (SUCCEEDED(hrTemp)) && (size > 0) && (pbuf[0] != '\0') )
								{
									int i = size - 1;
									while ( ( i > -1 ) && (pbuf[i] != '=') )
									{
										if(pbuf[i] == '.')
										{
											LPSTR pext = &pbuf[i];
											fFileExt.Empty();
											fFileExt.Append(pext);
										}
										--i;
									}
									if( i > 0 )
									{
										LPSTR pname = &pbuf[i+1];
										fFileName.Empty();
										fFileName.Append(pname);
									}
								}
								delete[] pbuf;
							}
						}
					}
				}
			}

//HTTP_QUERY_CONTENT_TYPE (text/html)
//HTTP_QUERY_CONTENT_LENGTH
//HTTP_QUERY_RAW_HEADERS_CRLF
		CComBSTR m_bstrResponseHeaders;
		if(m_pBinding)
		{
			//Get raw request headers and send them to client
			CComPtr<IWinInetHttpInfo> spWinInetHttpInfo;
			CComPtr<IBinding> pBinding = m_pBinding;
			HRESULT hrTemp = pBinding->QueryInterface(IID_IWinInetHttpInfo,
				reinterpret_cast<void**>(&spWinInetHttpInfo));
			if( (SUCCEEDED(hrTemp)) && (spWinInetHttpInfo) )
			{
				DWORD size = 0;
				DWORD flags = 0;
				hrTemp = spWinInetHttpInfo->QueryInfo( HTTP_QUERY_RAW_HEADERS_CRLF,
					0, &size, &flags, 0);
				if(SUCCEEDED(hrTemp))
				{
					LPSTR pbuf = new char[size+1];
					if(pbuf)
					{
						pbuf[size] = '\0';
						hrTemp = spWinInetHttpInfo->QueryInfo( HTTP_QUERY_RAW_HEADERS_CRLF,
							pbuf, &size, &flags, 0);
						if( (SUCCEEDED(hrTemp)) && (size > 0) && (pbuf[0] != '\0') )
						{
							//pbuf should contain all request headers
							m_bstrResponseHeaders.Append(pbuf);
						}
						else
							m_bstrResponseHeaders = L"";
						delete[] pbuf;
					}
				}
				else
					m_bstrResponseHeaders = L"";
			}
			else
				m_bstrResponseHeaders = L"";
		}
		else
			m_bstrResponseHeaders = L"";

		//Notify client via events
		if(::IsWindow(m_hwndEvents))
		{
			//Extra headers + redirect
			m_Events->Fire_FileDownloadEx(m_hostid, m_Uid, fUrl,
										fFileName, fFileExt,
										m_bstrResponseHeaders, 
										m_strRedirectedURL,
										&m_SendProgressEvent,
										&m_vboolCancelDL,
										&fPathToSave);
			//fPathToSave would be a path/filename.ext
		}

		//Cancel?
		if(m_vboolCancelDL == VARIANT_TRUE)
		{
			CancelDL();
			return S_OK;
		}
		//Set up fullpath for download
		if(fPathToSave.Length() > 0)
		{
			fFullSavePath = fPathToSave;		
		}
		else
		{
			if(fFileName.Length() > 0)
				fFullSavePath = fFileName; //Save in the same dir as client exe
			else
				fFullSavePath = L"UNKNOWN"; //Desparate???
		}
	}
	else if( ulStatusCode == BINDSTATUS_REDIRECTING)
	{
		m_fRedirect = TRUE;
		m_strRedirectedURL.Empty();
		m_strRedirectedURL.AppendBSTR(W2BSTR(szStatusText));
	}
	else if( (ulStatusCode == BINDSTATUS_DOWNLOADINGDATA) &&
			(m_SendProgressEvent == VARIANT_TRUE) )
	{
		if(::IsWindow(m_hwndEvents))
		{
			long lprogress = static_cast<long>(ulProgress);
			long lprogressmax = static_cast<long>(ulProgressMax);
			m_Events->Fire_OnFileDLProgress(m_Uid, fUrl, 
										lprogress, 
										lprogressmax, 
										&m_vboolCancelDL);
		}
	}
	else if( ulStatusCode == BINDSTATUS_ENDDOWNLOADDATA)
	{
		if(::IsWindow(m_hwndEvents))
			m_Events->Fire_OnFileDLEndDownload(m_Uid, fUrl);
	}

	//else, pass to previous BSCB coming from IDownloadManager::Download
	if(m_pPrevBSCB)
	{
		//Need to do this otherwise a filedownload dlg wil be displayed
		//as we are downloading the file.
		//Interestingly, according to MSDN, 
		//BINDSTATUS_CONTENTDISPOSITIONATTACH is declared obsolete????
		if(ulStatusCode == BINDSTATUS_CONTENTDISPOSITIONATTACH)
			return S_OK;
		m_pPrevBSCB->OnProgress(ulProgress, ulProgressMax, ulStatusCode, szStatusText);
	}

	if(m_vboolCancelDL == VARIANT_TRUE)
	{
		CancelDL();
	}

	return S_OK;

//Other status codes which may or may not fire
//depending on whatever MS feels like....
//  case BINDSTATUS_SENDINGREQUEST:
//  case BINDSTATUS_CONNECTING:
//  case BINDSTATUS_USINGCACHEDCOPY:
//  case BINDSTATUS_CACHEFILENAMEAVAILABLE:
//	case BINDSTATUS_FINDINGRESOURCE:;
//	case BINDSTATUS_BEGINDOWNLOADCOMPONENTS:
//	case BINDSTATUS_INSTALLINGCOMPONENTS:
//	case BINDSTATUS_ENDDOWNLOADCOMPONENTS:
//	case BINDSTATUS_CLASSIDAVAILABLE:
//	case BINDSTATUS_MIMETYPEAVAILABLE:
//..............
}

//This function is called regardless of success or failer in dl
STDMETHODIMP WBBSCBFileDL::OnStopBinding(HRESULT hresult,LPCWSTR szError)
{
	//vbLog(_T("OnStopBinding"),_T("WBBSCBFileDL::OnStopBinding"));
	if(m_pBinding)
	{
		m_pBinding->Release();
		m_pBinding = NULL;
	}

	//Notify the client that we are done
	//If client has not cancelled during actual dl via OnProgress
	//We send a normal event, else DLOnCancelDownload(m_Uid, Url, bool_cancelled during download)
	if(::IsWindow(m_hwndEvents))
	{
		if((hresult) && (szError))
		{
//One of
//INET_E_INVALID_URL
//INET_E_RESOURCE_NOT_FOUND
//.....
			USES_CONVERSION;
			CTmpBuffer buff(MAX_PATH);
			buff += W2CT(szError);
			//buff += _T(" Error Number = ");
			buff.AppendResStr((UINT)IDS_ERROR_NUMBER);
			buff.Appendlong(static_cast<long>(hresult));
			CComBSTR sMsg;
			sMsg.Append(buff);
			m_Events->Fire_OnFileDLDownloadError(m_Uid, fUrl, sMsg);
		}
		else if(m_bCancelled == TRUE) //set to true in CancelDL method
		{
			//Cancelled by client or errors in OnDataAvailable method
			m_Events->Fire_OnFileDLCancelDownload(m_Uid, fUrl, VARIANT_TRUE);
		}
		m_Events->RemoveBSCBFromDLArr(m_Uid);

//		else
//		{
//			//Remove from array
//			if(m_Events->RemoveBSCBFromDLArr(m_Uid))
//			{
//				m_Events->Fire_OnFileDLEndDownload(m_Uid, fUrl);
//			}
//			else
//			{
//				m_Events->Fire_OnFileDLDownloadError(m_Uid, fUrl, CComBSTR(L"Download Ended, but RemoveBSCBFromDLArr Failed."));
//			}
//		}
	}

	if( (m_pPrevBSCB) && (m_pBindCtx) )
	{
		//Register PrevBSCB and release our pointers
		//LPOLESTR oParam = L"_BSCB_Holder_";
		m_pBindCtx->RegisterObjectParam(oBindCtxBSCBObjectParam, 
					reinterpret_cast<IUnknown*>(m_pPrevBSCB));
		m_pPrevBSCB->Release();
		m_pPrevBSCB = NULL;
		m_pBindCtx->Release();
		m_pBindCtx = NULL;
		//Decrease our ref count, so when release is called
		//we delete this object
		--m_cRef;
	}
	//URLmon.dll will call release on this object, so says MSDN
	return S_OK;
}

STDMETHODIMP WBBSCBFileDL::GetBindInfo(DWORD *grfBINDF, BINDINFO * pbindinfo)
{
	if (pbindinfo==NULL || pbindinfo->cbSize==0 || grfBINDF==NULL)
		return E_INVALIDARG;

	//Set up bind flags
	*grfBINDF = BINDF_ASYNCHRONOUS | BINDF_ASYNCSTORAGE | BINDF_PULLDATA | BINDF_GETNEWESTVERSION | BINDF_NOWRITECACHE;
	//*grfBINDF |= BINDF_IGNORESECURITYPROBLEM;

	// Set up the BINDINFO data structure
//	pbindinfo->cbSize = sizeof(BINDINFO);

	//Clear and setup
	DWORD cbSize = pbindinfo->cbSize = sizeof(BINDINFO);
	memset(pbindinfo,0,cbSize);
	pbindinfo->cbSize = cbSize;

//BINDVERB_GET,
//BINDVERB_POST,
//BINDVERB_PUT,
//BINDVERB_CUSTOM
	pbindinfo->dwBindVerb = BINDVERB_GET;
	pbindinfo->szExtraInfo = NULL;

	//The stgmedData member of the BINDINFO structure should be set 
	//to TYMED_NULL for the GET operation. 
	memset(&pbindinfo->stgmedData, 0, TYMED_NULL);

//BINDINFOF_URLENCODESTGMEDDATA = 0
//BINDINFOF_URLENCODEDEXTRAINFO = 1
	pbindinfo->grfBindInfoF = 0;
//BSTR specifying a protocol-specific custom action to be performed
//during the bind operation (only if dwBindVerb is set to BINDVERB_CUSTOM)
	pbindinfo->szCustomVerb = NULL;
//Reserved. Must be set to 0
	pbindinfo->dwOptions = 0;
	pbindinfo->dwOptionsFlags = 0;
	pbindinfo->dwReserved = 0;

	return S_OK;
}

STDMETHODIMP WBBSCBFileDL::OnDataAvailable(DWORD grfBSCF, DWORD dwSize, FORMATETC* pformatetc, STGMEDIUM* pstgmed)
{
	HRESULT hr = S_OK;
	
	//First call here
    if (BSCF_FIRSTDATANOTIFICATION & grfBSCF)
    {
		// Cache the incoming Stream
        if (m_pstm == NULL &&  pstgmed->tymed == TYMED_ISTREAM)
	    {
			//Get a local copy of the stream
			m_pstm = pstgmed->pstm;
			if (m_pstm)
			{
				m_pstm->AddRef();
				if(fFullSavePath.Length() > 0)
				{
					USES_CONVERSION;
					hFile = CreateFile(OLE2T(fFullSavePath), GENERIC_WRITE, 0, NULL,
										OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
					if(hFile == INVALID_HANDLE_VALUE)
					{
						goto Error;
					}
					if(m_vboolResuming == TRUE)
					{
						//Move pointer to the end of file, if we have anything
						//#define INVALID_SET_FILE_POINTER ((DWORD)-1)
						if (SetFilePointer(hFile, 0, NULL, FILE_END) == ((DWORD)-1))
						{
							goto Error;
						}
					}
				}
				else
				{
					goto Error;
				}
			}
    	}
    }

    // If there is some data to be read then go ahead and read it
    if (m_pstm && dwSize > m_cbOld)
	{
        DWORD dwRead = dwSize - m_cbOld; // Minimum amount available that hasn't been read
        DWORD dwActuallyRead = 0;            // Placeholder for amount read during this pull
		DWORD dwWritten = 0; //WriteFile

		if (dwRead > 0)
		do
		{
	        //BYTE* pBytes = NULL;
			//pBytes = new BYTE[dwRead + 1]);
			//if(pBytes == NULL) goto Error;

			//Servers serve non Unicode content
			LPSTR pNewstr = new char[dwRead + 1];
			if (!pNewstr)
			{
				//E_OUTOFMEMORY
				//vbLog(_T("E_OUTOFMEMORY"),_T("WBBSCBFileDL::OnDataAvailable"));
				goto Error;
			}

			//hr= m_pstm->Read(pBytes, dwRead, &dwActuallyRead);
			hr = m_pstm->Read(pNewstr, dwRead, &dwActuallyRead);
			//pBytes[dwActuallyRead] = 0;
			pNewstr[dwActuallyRead] = '\0';
			// If we really read something then lets write it to file
			if (dwActuallyRead > 0)
			{
				m_cbOld += dwActuallyRead;
				//WriteFile(hFile, pBytes, dwActuallyRead, &dwWritten, NULL);
				WriteFile(hFile, pNewstr, dwActuallyRead, &dwWritten, NULL);
			}

			//delete[] pBytes;
			delete[] pNewstr;

		} while (!(hr == E_PENDING || hr == S_FALSE) && SUCCEEDED(hr));
	}

	// Clean up
	if (BSCF_LASTDATANOTIFICATION & grfBSCF)
	{
        if (m_pstm)
		{
            m_pstm->Release();
			m_pstm = NULL;
			if(hFile != INVALID_HANDLE_VALUE)
			{
				CloseHandle(hFile);
				hFile = INVALID_HANDLE_VALUE;
			}
		}
		hr = S_OK;  // If it was the last data then we should return S_OK as we just finished reading everything
	}

	return hr;

Error:
	//Just cancel
	//We will notify client in OnStopBinding, since hresult
	//will have a value
	CancelDL();
	return S_FALSE;
}

STDMETHODIMP WBBSCBFileDL::OnObjectAvailable(REFIID riid,IUnknown* punk)
{
	return E_NOTIMPL;
}

STDMETHODIMP WBBSCBFileDL::BeginningTransaction(
												LPCWSTR szURL,
                								LPCWSTR szHeaders,
                								DWORD dwReserved,
                								LPWSTR *pszAdditionalHeaders)
{
	//vbLog(_T("BeginningTransaction"),_T("WBBSCBFileDL::BeginningTransaction"));
	// Here's our opportunity to add headers
	if (!pszAdditionalHeaders)
	{
		return E_POINTER;
	}
	*pszAdditionalHeaders = NULL;

	USES_CONVERSION;
//vbLog(W2CT(szURL),_T("BeginningTransaction::URL"));
//vbLog(W2CT(szHeaders),_T("BeginningTransaction::Headers"));

	m_vboolResuming = VARIANT_FALSE;
	m_vboolCancelDL = VARIANT_FALSE;
	CComBSTR sAddClientHeaders(L"");
	CComBSTR sHeaders;

	fUrl.Empty();
	fUrl = szURL;
	if(szHeaders)
		sHeaders = szHeaders;
	else
		sHeaders = L"";

	//Notify client
	if(::IsWindow(m_hwndEvents))
		m_Events->Fire_OnFileDLBeginningTransaction(
												m_Uid, 
												fUrl, 
												sHeaders, 
												&sAddClientHeaders,
												&m_vboolResuming, 
												&m_vboolCancelDL);


	if(m_vboolCancelDL == VARIANT_TRUE)
		CancelDL();
	
	//See if we were send extra headers from IDownloadManager::Download method
	if(m_strDLManExtraHeaders.Length() > 0)
	{
		sAddClientHeaders += m_strDLManExtraHeaders;
	}

	//Add additional headers
	if(sAddClientHeaders.Length() > 0)
	{
		//Set additional headers
		LPWSTR wszAdditionalHeaders = 
			(LPWSTR)CoTaskMemAlloc((sAddClientHeaders.Length()+1) *sizeof(WCHAR));
		if (wszAdditionalHeaders)
		{
			//if (!wszAdditionalHeaders) return E_OUTOFMEMORY;
			//Copy
			wcscpy(wszAdditionalHeaders, OLE2W(sAddClientHeaders));
			wszAdditionalHeaders[sAddClientHeaders.Length()] = (WCHAR)NULL;
			//vbLog(wszAdditionalHeaders,_T("BeginningTransaction::Headers"));
			//Give URLmon a handle to our header
			*pszAdditionalHeaders = wszAdditionalHeaders;
		}
	}

	return S_OK;
}

STDMETHODIMP WBBSCBFileDL::OnResponse(
                DWORD dwResponseCode,
                LPCWSTR szResponseHeaders,
                LPCWSTR szRequestHeaders,
                LPWSTR *pszAdditionalRequestHeaders)
{
	if (!pszAdditionalRequestHeaders)
	{
		return E_POINTER;
	}
	*pszAdditionalRequestHeaders = NULL;

	//vbLog(_T("OnResponse"),_T("WBBSCBFileDL::OnResponse"));

	USES_CONVERSION;
	CTmpBuffer buff(MAX_PATH*2);
	buff = W2CT(szResponseHeaders);
	if (szRequestHeaders)
	{
		//buff += _T("(Repeat request)\r\n");
		buff += W2CT(szRequestHeaders);
	}
	m_vboolCancelDL = VARIANT_FALSE;
	//Fire event
	m_Events->Fire_OnFileDLResponse(m_Uid, fUrl, 
								(long)(dwResponseCode), 
								T2BSTR(buff), &m_vboolCancelDL);
	if(m_vboolCancelDL == VARIANT_TRUE)
		CancelDL();

	return S_OK;
}

bool WBBSCBFileDL::CancelDL(void)
{
	//vbLog(_T("CancelDL"),_T("WBBSCBFileDL::CancelDL"));
	m_bCancelled = TRUE;
    if (m_pstm)
	{
        m_pstm->Release();
		m_pstm = NULL;
	}
	if(hFile != INVALID_HANDLE_VALUE)
	{
		CloseHandle(hFile);
		hFile = INVALID_HANDLE_VALUE;
	}
	if(m_pBinding)
	{
		m_pBinding->Abort();
	}
	return true;
}

bool WBBSCBFileDL::IsDownloading(void)
{
	return (m_pBinding) ? true : false;
}

void WBBSCBFileDL::ResetInternalVars(void)
{
	m_cRef = 0;
	m_hostid = 0;
	m_Uid = 0;
	m_pPrevBSCB = NULL;
	m_pBindCtx = NULL;

	m_vboolCancelDL = VARIANT_FALSE;
	m_bCancelled = FALSE;

	m_fRedirect = FALSE;
	m_pBinding = NULL;
	m_pstm = NULL;
	m_cbOld = DW_ZERO;
	hFile = INVALID_HANDLE_VALUE;

	m_pHost = NULL;
	m_Events = NULL;
	m_hwndEvents = NULL;
	m_SendProgressEvent = VARIANT_TRUE;
	m_vboolResuming = VARIANT_FALSE;
	m_strRedirectedURL = L"";
}

////////////////////////////////////////////////////////////////////////////////////////
//WBSecurityManager
////////////////////////////////////////////////////////////////////////////////////////
/*
InternetSecurityZoneManager example;
Creating + getting + setting ZoneActionPolicy
   HRESULT hRes = ::CoCreateInstance( CLSID_InternetZoneManager, NULL, CLSCTX_SERVER, IID_IInternetZoneManager,
      reinterpret_cast< void ** >( &m_pZone ) );

   _ASSERTE( SUCCEEDED( hRes ) );

   m_pZone->GetZoneActionPolicy( URLZONE_INTERNET, URLACTION_DOWNLOAD_UNSIGNED_ACTIVEX, reinterpret_cast< BYTE * >( &m_dwOldPolicy ),
      sizeof( DWORD ), URLZONEREG_HKCU );

   DWORD dwPolicy = URLPOLICY_QUERY;
   m_pZone->SetZoneActionPolicy( URLZONE_INTERNET, URLACTION_DOWNLOAD_UNSIGNED_ACTIVEX, reinterpret_cast< BYTE * >( &dwPolicy ),
      sizeof( DWORD ), URLZONEREG_HKCU );
*/
WBSecurityManager::WBSecurityManager(IWB* pFrameSite)
{
	m_pHost = pFrameSite;
}

WBSecurityManager::~WBSecurityManager()
{
	m_pHost = NULL;
}

// *** IUnknown ***
STDMETHODIMP WBSecurityManager::QueryInterface(REFIID iid, void ** ppvObject)
{
	return m_pHost->QueryInterface(iid, ppvObject);
	
}

ULONG STDMETHODCALLTYPE WBSecurityManager::AddRef()
{
	return m_pHost->AddRef();
}

ULONG STDMETHODCALLTYPE WBSecurityManager::Release()
{
	return m_pHost->Release();
}

STDMETHODIMP WBSecurityManager::SetSecuritySite(IInternetSecurityMgrSite  *pSite)
{ return INET_E_DEFAULT_ACTION; }

STDMETHODIMP WBSecurityManager::GetSecuritySite(IInternetSecurityMgrSite  **ppSite)
{ return INET_E_DEFAULT_ACTION; }       

STDMETHODIMP WBSecurityManager::MapUrlToZone( LPCWSTR pwszUrl, DWORD  *pdwZone, DWORD dwFlags)
{
    // All URLs are on the local machine - most trusted
	//*pdwZone = URLZONE_LOCAL_MACHINE;
	return INET_E_DEFAULT_ACTION;
}

STDMETHODIMP WBSecurityManager::GetSecurityId( 
     LPCWSTR pwszUrl,
     BYTE  *pbSecurityId,
     DWORD  *pcbSecurityId,
     DWORD dwReserved)
{
/*
      static LPCTSTR strSecurity = _T( "None:localhost+My Computer" );
      ::strcpy( reinterpret_cast< char * >( pbSecurityId ), strSecurity );
      *pcbSecurityId = ::_tcslen( strSecurity );
*/
	return INET_E_DEFAULT_ACTION;
}
    
/*
MSDN:
The current list of URLACTION that will not be passed to the custom security manager
in most circumstances by Internet Explorer 5 are:
	URLACTION_SHELL_FILE_DOWNLOAD 
	URLACTION_COOKIES 
	URLACTION_JAVA_PERMISSIONS 
	URLACTION_SCRIPT_PASTE 
There is no workaround for this problem. The behavior for the URLACTION can only be
changed for all browser clients on the system by altering the security zone settings
from Internet Options. ????????
*/
STDMETHODIMP WBSecurityManager::ProcessUrlAction(
		LPCWSTR pwszUrl, DWORD dwAction, BYTE  *pPolicy, DWORD cbPolicy,
		BYTE  *pContext, DWORD cbContext, DWORD dwFlags, DWORD dwReserved)
{

	DWORD dwPolicy = URLPOLICY_ALLOW;
	VARIANT_BOOL handled = VARIANT_FALSE;
	
	//Inform client
	long lpolicy = static_cast<long>(dwPolicy);
	m_pHost->m_EventsPtr->Fire_WBProcessUrlAction(m_pHost->m_thisID, 
												CComBSTR(pwszUrl),(long)dwAction, 
												(long)dwFlags, &lpolicy, 
												&handled);
	//Add a new param bHandled (default = false)
	//If client returns VARIANT_FALSE then do default
	if(handled == VARIANT_FALSE)
		return INET_E_DEFAULT_ACTION;

	//Get the new policy
	dwPolicy = static_cast<ULONG>(lpolicy);

	//Set
	if (cbPolicy >= sizeof(DWORD))
	{
		*(DWORD *)pPolicy = dwPolicy;
		//*reinterpret_cast< DWORD * >( pPolicy ) = URLPOLICY_ALLOW;
		return S_OK;
	}
	else
		return S_FALSE;

	//Otherwise, always do default
	return INET_E_DEFAULT_ACTION;
}

STDMETHODIMP WBSecurityManager::QueryCustomPolicy( 
         LPCWSTR pwszUrl,
         REFGUID guidKey,
         BYTE  **ppPolicy,
         DWORD  *pcbPolicy,
         BYTE  *pContext,
         DWORD cbContext,
         DWORD dwReserved)
{ return INET_E_DEFAULT_ACTION; }

STDMETHODIMP WBSecurityManager::SetZoneMapping( 
         DWORD dwZone,
         LPCWSTR lpszPattern,
         DWORD dwFlags)
{ return INET_E_DEFAULT_ACTION; }

STDMETHODIMP WBSecurityManager::GetZoneMappings( 
         DWORD dwZone,
         IEnumString  **ppenumString,
         DWORD dwFlags)
{ return INET_E_DEFAULT_ACTION; }

////////////////////////////////////////////////////////////////////////////
//IAuthenticate
////////////////////////////////////////////////////////////////////////////
WBAuthenticate::WBAuthenticate(IWB* pFrameSite)
{ m_pHost = pFrameSite; }

WBAuthenticate::~WBAuthenticate()
{ m_pHost = NULL; }

// *** IUnknown ***
STDMETHODIMP WBAuthenticate::QueryInterface(REFIID iid, void ** ppvObject)
{
	return m_pHost->QueryInterface(iid, ppvObject);
	
}

ULONG STDMETHODCALLTYPE WBAuthenticate::AddRef()
{
	return m_pHost->AddRef(); 
}

ULONG STDMETHODCALLTYPE WBAuthenticate::Release()
{
	return m_pHost->Release();
}

// *** IAuthenticate ***

//Applications that implement the IAuthenticate::Authenticate method must allocate
//the memory of the pszUsername and pszPassword buffers using CoTaskMemAlloc. 

//Returns one of the following values:;
//S_OK Authentication was successful. 
//E_ACCESSDENIED Authentication failed. 
//E_INVALIDARG One or more parameters are invalid.
//Currently, the user name and password options handle only
//the Basic authentication scheme and N..
STDMETHODIMP WBAuthenticate::Authenticate(HWND *phwnd, LPWSTR *pszUsername, LPWSTR *pszPassword)
{
	if (!phwnd || !pszUsername || !pszPassword)
	{
	  return E_INVALIDARG;
	}

	*phwnd = NULL;
	*pszUsername = NULL;
	*pszPassword = NULL;
	CComBSTR strUsername(L"");
	CComBSTR strPassword(L"");
	//Default, do not cancel
	VARIANT_BOOL bCancel = VARIANT_FALSE;
	//Fire event to obtain Uname+Password
	m_pHost->m_EventsPtr->Fire_OnAuthentication(m_pHost->m_thisID, 
									&strUsername, &strPassword, &bCancel);
	//Cancelled, bail
	if(bCancel == VARIANT_TRUE)
		return E_ACCESSDENIED;
	//allocate mem
	WCHAR *wszUsername =  (WCHAR *)CoTaskMemAlloc((strUsername.Length()+1) *sizeof(WCHAR));
	if(!wszUsername)
	{
		return E_OUTOFMEMORY;
	}
	WCHAR *wszPassword =  (WCHAR *)CoTaskMemAlloc((strPassword.Length()+1) *sizeof(WCHAR));
	if(!wszPassword)
	{
		return E_OUTOFMEMORY;
	}
	USES_CONVERSION;
	//Copy
	wcscpy(wszUsername, OLE2W(strUsername));
	wszUsername[strUsername.Length()] = (WCHAR)NULL;
	wcscpy(wszPassword, OLE2W(strPassword));
	wszPassword[strPassword.Length()] = (WCHAR)NULL;
	//Assign to out params
	*pszUsername = wszUsername;
	*pszPassword = wszPassword;
	return S_OK;
}


////////////////////////////////////////////////////////
WBIHTMLOMWindowServices::WBIHTMLOMWindowServices(IWB* pFrameSite)
{
	m_pHost = pFrameSite;
}
WBIHTMLOMWindowServices::~WBIHTMLOMWindowServices()
{
}

// IUnknown
ULONG STDMETHODCALLTYPE WBIHTMLOMWindowServices::AddRef()
{
	return m_pHost->AddRef();
}

ULONG STDMETHODCALLTYPE WBIHTMLOMWindowServices::Release()
{
	return m_pHost->Release();
}

STDMETHODIMP WBIHTMLOMWindowServices::QueryInterface(REFIID iid, void ** ppvObject)
{
	return m_pHost->QueryInterface(iid, ppvObject);
}

//IHTMLOMWindowServices
STDMETHODIMP WBIHTMLOMWindowServices::moveTo(LONG x, LONG y)
{
	m_pHost->m_EventsPtr->Fire_OnHTMLOMWindowServicesMoveTo(m_pHost->m_thisID, (long)x, (long)y);
	return S_OK; //E_FAIL
}

STDMETHODIMP WBIHTMLOMWindowServices::moveBy(LONG x, LONG y)
{
	m_pHost->m_EventsPtr->Fire_OnHTMLOMWindowServicesMoveBy(m_pHost->m_thisID, (long)x, (long)y);
	return S_OK; //E_FAIL
}

STDMETHODIMP WBIHTMLOMWindowServices::resizeTo(LONG x, LONG y)
{
	m_pHost->m_EventsPtr->Fire_OnHTMLOMWindowServicesResizeTo(m_pHost->m_thisID, (long)x, (long)y);
	return S_OK; //E_FAIL
}

STDMETHODIMP WBIHTMLOMWindowServices::resizeBy(LONG x, LONG y)
{
	m_pHost->m_EventsPtr->Fire_OnHTMLOMWindowServicesResizeBy(m_pHost->m_thisID, (long)x, (long)y);
	return S_OK; //E_FAIL
}

////////////////////////////////////////////////////////
//WBHttpSecurity
////////////////////////////////////////////////////////
WBHttpSecurity::WBHttpSecurity(IWB* pFrameSite)
{
	m_pHost = pFrameSite;
}

WBHttpSecurity::~WBHttpSecurity()
{
	m_pHost = NULL;
}

// *** IUnknown ***
STDMETHODIMP WBHttpSecurity::QueryInterface(REFIID iid, void ** ppvObject)
{
	return m_pHost->QueryInterface(iid, ppvObject);
}

ULONG STDMETHODCALLTYPE WBHttpSecurity::AddRef()
{
	return m_pHost->AddRef();
}

ULONG STDMETHODCALLTYPE WBHttpSecurity::Release()
{
	return m_pHost->Release();
}

//IWindowForBindingUI
//If you implement this interface, you can return S_FALSE for this method to
//indicate that no window is available for displaying user interface information.
//rguidReason = Identifier that indicates the reason for the user interface.
//This can be either IID_IAuthenticate or IID_IHttpSecurity.
STDMETHODIMP WBHttpSecurity::GetWindow(REFGUID rguidReason,HWND *phwnd)
{
	*phwnd = NULL;
	if( (rguidReason == IID_IHttpSecurity) || (rguidReason == IID_IAuthenticate) )
	{
		*phwnd = m_pHost->GetIEServerHwnd(); //Return IEServer Hwnd
		if(*phwnd)
			return S_OK;
	}
	return S_FALSE;
}
	

/*
IHttpSecurity, Some possible problems:

ERROR_INTERNET_SEC_CERT_DATE_INVALID
ERROR_INTERNET_SEC_CERT_CN_INVALID
ERROR_INTERNET_HTTP_TO_HTTPS_ON_REDIR
ERROR_INTERNET_HTTPS_TO_HTTP_ON_REDIR
ERROR_HTTP_REDIRECT_NEEDS_CONFIRMATION
ERROR_INTERNET_INVALID_CA
ERROR_INTERNET_CLIENT_AUTH_CERT_NEEDED
*/

//Possible return values;
//RPC_E_RETRY (cautious) The calling application should continue or retry the download. 
//S_FALSE The calling application should open a dialog box to warn the user. 
//E_ABORT The calling application should abort the download.
STDMETHODIMP WBHttpSecurity::OnSecurityProblem(DWORD dwProblem)
{
	VARIANT_BOOL bcancel = VARIANT_TRUE;
	//Fire event
	m_pHost->m_EventsPtr->Fire_OnHTTPSecurityProblem(m_pHost->m_thisID, 
									(long)dwProblem, &bcancel);
	if(bcancel == VARIANT_TRUE)
		return E_ABORT;
	else
		//Be cautious:
		//Returning S_FALSE implies that you have asked the user
		//if it is ok to proceed despite a security problem and they have agreed
		return S_FALSE;
		//Retries using Registry options and most likely fails again
		//return RPC_E_RETRY;
/*
Implementing this method incorrectly can compromise the security of your application.
Returning a value of RPC_E_RETRY can potentially leave users of your application exposed
to unwanted information disclosure. RPC_E_RETRY should only be returned when
the application is running on a known trusted server or after you have verified
information from the user.
*/
}

////////////////////////////////////////////////////////
//WBWindowForBindingUI
////////////////////////////////////////////////////////
WBWindowForBindingUI::WBWindowForBindingUI(IWB* pFrameSite)
{
	m_pHost = pFrameSite;
}

WBWindowForBindingUI::~WBWindowForBindingUI()
{
	m_pHost = NULL;
}

// *** IUnknown ***
STDMETHODIMP WBWindowForBindingUI::QueryInterface(REFIID iid, void ** ppvObject)
{
	return m_pHost->QueryInterface(iid, ppvObject);
}

ULONG STDMETHODCALLTYPE WBWindowForBindingUI::AddRef()
{
	return m_pHost->AddRef();
}

ULONG STDMETHODCALLTYPE WBWindowForBindingUI::Release()
{
	return m_pHost->Release();
}

//If you implement this interface, you can return S_FALSE for this method to
//indicate that no window is available for displaying user interface information.
//rguidReason = Identifier that indicates the reason for the user interface.
//This can be either IID_IAuthenticate or IID_IHttpSecurity.
STDMETHODIMP WBWindowForBindingUI::GetWindow(REFGUID rguidReason,HWND *phwnd)
{
	*phwnd = NULL;
	if( (rguidReason == IID_IHttpSecurity) || (rguidReason == IID_IAuthenticate) )
	{
		*phwnd = m_pHost->GetIEServerHwnd(); //Return IEServer Hwnd
		if(*phwnd)
			return S_OK;
	}		
	return S_FALSE;
}

////////////////////////////////////////////////////////////////////////////////
//
//WBStream
//
////////////////////////////////////////////////////////////////////////////////

WBStream::WBStream()
{
	m_hwndEvents = NULL;
	m_Events = NULL;
	//We will release this obj
	//in a WBBSCBUpload instance after 
	//Upload and binding are finished
	m_cRef = 1;
	//File handle will be closed in WBBSCBUpload instance
	//After OnStopBinding is called
	m_hFile = NULL;
	m_pcBuffer = NULL;
	m_uBufferSize = 0;
	m_uFilePos = 0;
	m_Uid = 0;
}

WBStream::~WBStream()
{
}

void WBStream::InitWBStreamData(short iID, CvbWB *pHost, WBBSCBUpload *lpParent, BSTR URL, void *pvBuffer, ULONG uSize)
{
	m_Events = pHost;
	if(m_Events)
		m_hwndEvents = m_Events->m_hWnd;
	m_Uid = iID;
	m_lpParent = lpParent;
	fUrl = URL;

	m_pcBuffer = reinterpret_cast<char *>(pvBuffer);
	m_uBufferSize = uSize;
}

void WBStream::InitWBStreamFileName(short iID, CvbWB *pHost,WBBSCBUpload *lpParent, BSTR URL, HANDLE hFile, ULONG uFileSize)
{
	m_Events = pHost;
	if(m_Events)
		m_hwndEvents = m_Events->m_hWnd;
	m_Uid = iID;
	m_lpParent = lpParent;
	fUrl = URL;
	m_uBufferSize = uFileSize;
	m_hFile = hFile;
}

// IUnknown
STDMETHODIMP WBStream::QueryInterface(REFIID iid, void ** ppvObject)
{
	if(ppvObject == NULL) return E_INVALIDARG;
	*ppvObject = NULL;

	if( (iid==IID_IStream) || (iid==IID_IUnknown) )
	{
       *ppvObject = (IStream*)this;
	}

	if (NULL != *ppvObject)
	{
        AddRef();
        return S_OK;
    }
	return E_NOINTERFACE; 
}

ULONG STDMETHODCALLTYPE WBStream::AddRef()
{
	return ++m_cRef;
}

ULONG STDMETHODCALLTYPE WBStream::Release()
{
	if(--m_cRef == 0)
	{
        delete this;
		return 0;
	}
	return m_cRef;
}

//Data is requested via IStream::Read in 8kb
//parts allowing progress messages to be displayed

//Unlike posting data which uses HGLOBAL,
//we use an IStream to upload files much like IE

//OnProgress method of BSCB may or maynot be called..
//If OnProgress is called then in BSCB we get a BINDSTATUS_SENDINGREQUEST
//rather than BINDSTATUS_UPLOADINGDATA and with zero parameters.
//So I use internal pointer IStream class to display current upload position

//Also for some reason, BINDSTATUS_SENDINGREQUEST notification is sent
//more than once (it appears to be n+1 where n is the number of files
//being uploaded, but I haven't performed enough tests to be sure).

//Refer to KB Q303643 for a quick sample of IStream implementation
//Refer to KB Q165800 for SAMPLE: PostMon.exe,
//a Demonstrates How to Use URL Moniker to POST Data
STDMETHODIMP WBStream::Read(void *pv, ULONG cb, ULONG *pcbRead)
{
	if (m_uFilePos >= m_uBufferSize)
	{
		// Past end of file.
		if (pcbRead != NULL)
		{
			*pcbRead = 0;
		}
		return S_OK;
	}

	if (cb > m_uBufferSize - m_uFilePos)
	{
		cb = m_uBufferSize - m_uFilePos;
	}
	//Are we reading from mem buffer or a file (8 byte chunks)
	if( m_pcBuffer )
	{
		//const char * pszCur = &m_pcBuffer[m_uFilePos];
		memcpy( pv, &m_pcBuffer[m_uFilePos], cb );
		m_uFilePos += cb;
		if (pcbRead != NULL)
		{
			*pcbRead = cb;
		}
	}
	else
	{
		//Account for the file being a Unicode file
		DWORD dwBytesRead = ((DWORD)0);
		BOOL bSuccess = ReadFile(m_hFile, pv, cb, &dwBytesRead, NULL);
		if((bSuccess) && (dwBytesRead > 0) && (pcbRead != NULL))
		{
			m_uFilePos += dwBytesRead;
			if (pcbRead != NULL)
			{
				*pcbRead = dwBytesRead;
			}
		}
	}


	//Fire notification event to 
	//keep track of upload progress
	//Fire_UploadingData(iID, url, m_uFilePos-Read, m_uBufferSize-total, &bCancel);
	//if(bCancel == VARIANT_TRUE) {if(m_lpParent) m_lpParent->CancelUpload();}
	return S_OK;

}

////////////////////////////////////////////////////////
//
//WBBSCBPost
//
////////////////////////////////////////////////////////
WBBSCBPost::WBBSCBPost()
{
	m_Events = NULL;
	m_hwndEvents = NULL;
	m_pBinding = NULL;
	m_pstm = NULL;
	m_cRef = 0;
	m_cbOld = 0;
	m_dwAction = BINDVERB_POST; //Initially
	m_hDataToPost = NULL;
	m_cbDataToPost = 0;
	m_fRedirect = FALSE;
	m_vboolCancel = VARIANT_FALSE;
	m_lprogress = 0;
	m_lprogressmax = 0;
	m_lstatuscode = 0;
	m_Uid = 0;
}

WBBSCBPost::~WBBSCBPost()
{
	if (m_hDataToPost) 
	{
		GlobalFree(m_hDataToPost);
	}
}

// IUnknown
ULONG STDMETHODCALLTYPE WBBSCBPost::AddRef()
{ 
	return m_cRef++; 
}

ULONG STDMETHODCALLTYPE WBBSCBPost::Release()
{ 
	if (--m_cRef == 0) 
	{ 
		delete this; 
		return 0; 
	} 
	return m_cRef; 
}

STDMETHODIMP WBBSCBPost::QueryInterface(REFIID iid, void ** ppvObject)
{
	if(ppvObject == NULL) return E_INVALIDARG;
	*ppvObject = NULL;
	if( iid == IID_IBindStatusCallback  || iid == IID_IUnknown)
	{
		*ppvObject = (IBindStatusCallback*)this;
		AddRef();
		return S_OK;
	}
	else if ( iid == IID_IHttpNegotiate )
	{
		*ppvObject = (IHttpNegotiate*)this;
		AddRef();
		return S_OK;
	}
	return E_NOINTERFACE;
}

//IBindStatusCallback
STDMETHODIMP WBBSCBPost::OnStartBinding(DWORD dwReserved, IBinding * pib)
{
	if (m_pBinding)
	{
		m_pBinding->Release();
	}
	//Cache the URLMON-provided IBinding interface so that we can control the download
	m_pBinding = pib;
	if(m_pBinding)
	{
		m_pBinding->AddRef();
	}
	return S_OK;
}

STDMETHODIMP WBBSCBPost::GetPriority(LONG * pnPriority)
{ return E_NOTIMPL; }

STDMETHODIMP WBBSCBPost::OnLowResource(DWORD reserved)
{ return E_NOTIMPL; }

STDMETHODIMP WBBSCBPost::OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText)
{
	if(ulStatusCode == BINDSTATUS_REDIRECTING)
	{
		m_fRedirect = TRUE;
	}
	if(::IsWindow(m_hwndEvents))
	{
		//Reset
		m_vboolCancel = VARIANT_FALSE;
		m_lprogress = static_cast<long>(ulProgress);
		m_lprogressmax = static_cast<long>(ulProgressMax);
		m_lstatuscode = static_cast<long>(ulStatusCode);
		m_stattext.Empty();

		if(szStatusText)
		{
			m_stattext = szStatusText; //W2BSTR(szStatusText)
		}
		else
			m_stattext = L"";

		m_Events->Fire_OnPostOnProgress (m_Uid, fUrl, 
					m_lprogress, m_lprogressmax, m_lstatuscode, 
					m_stattext, &m_vboolCancel);
		if(m_vboolCancel == VARIANT_TRUE)
		{
			CancelPost();
		}
	}
	return S_OK;
}

STDMETHODIMP WBBSCBPost::OnStopBinding(HRESULT hresult,LPCWSTR szError)
{
	if(m_pBinding)
	{
		m_pBinding->Release();
		m_pBinding = NULL;
	}

	if(::IsWindow(m_hwndEvents))
	{
		if((hresult) && (szError))
		{
//One of
//INET_E_INVALID_URL
//INET_E_RESOURCE_NOT_FOUND
//.....
			USES_CONVERSION;
			CTmpBuffer buff(MAX_PATH);
			buff += W2CT(szError);
			//buff += _T(" Error Number = ");
			buff.AppendResStr((UINT)IDS_ERROR_NUMBER);
			buff.Appendlong(static_cast<long>(hresult));
			CComBSTR sMsg;
			sMsg.Append(buff);
			m_Events->Fire_OnPostError(m_Uid, fUrl, sMsg);
		}
		else
		{
			m_Events->Fire_OnPostEnd(m_Uid, fUrl);
		}
	}

	//URLmon.dll will call release on this object which will cause delete
	return S_OK;
}

STDMETHODIMP WBBSCBPost::GetBindInfo(DWORD *grfBINDF, BINDINFO * pbindinfo)
{
	if (m_fRedirect && BINDVERB_POST == m_dwAction)
	{
		// We're being redirected by the server. Stop posting
		m_dwAction = BINDVERB_GET;
	}

	*grfBINDF = BINDF_ASYNCHRONOUS | BINDF_ASYNCSTORAGE | BINDF_PULLDATA;
	*grfBINDF |= BINDF_GETNEWESTVERSION | BINDF_NOWRITECACHE;

	// Set up the BINDINFO data structure
	pbindinfo->cbSize = sizeof(BINDINFO);
	pbindinfo->dwBindVerb = m_dwAction; // here's where the action is defined
	pbindinfo->szExtraInfo = NULL;

	// Initialize the STGMEDIUM.
	if(m_dwAction == BINDVERB_POST)
	{
		memset(&pbindinfo->stgmedData, 0, sizeof(STGMEDIUM));
	}
	else
	{
		//The stgmedData member of the BINDINFO structure should be set 
		//to TYMED_NULL for the GET operation. 
		memset(&pbindinfo->stgmedData, 0, TYMED_NULL);
	}
	pbindinfo->grfBindInfoF = 0;
	pbindinfo->szCustomVerb = NULL;
	//Reserved. Must be set to 0
	pbindinfo->dwOptions = 0;
	pbindinfo->dwOptionsFlags = 0;
	pbindinfo->dwReserved = 0;

	// set up action-specific members
	switch(m_dwAction)
	{
	case BINDVERB_POST:
		if (m_hDataToPost)
		{			
			// Fill the STGMEDIUM with the data to post
			//MSDN:
			//	TYMED_HGLOBAL is the only medium urlmon supports right now
			//Seems to be wrong??:
			//IE uses TYMED_ISTREAM when submitting a form with <input type="file"> control
			pbindinfo->stgmedData.tymed = TYMED_HGLOBAL;
			pbindinfo->stgmedData.hGlobal = m_hDataToPost;
			pbindinfo->stgmedData.pUnkForRelease = (LPUNKNOWN)(LPBINDSTATUSCALLBACK)this; //  maintain control over the data. 
			//AddRef(); // It will be freed on final release
			pbindinfo->cbstgmedData = // this must be exact! 
				m_cbDataToPost;		  // Do not rely on GlobalSize() 
									  // which rounds up to the nearest power of two.
		}
		break;
	case BINDVERB_GET:
		break;
	default:
		return E_FAIL;
	}

	return S_OK;
}

STDMETHODIMP WBBSCBPost::OnDataAvailable(DWORD grfBSCF, DWORD dwSize, FORMATETC* pformatetc, STGMEDIUM* pstgmed)
{
	 HRESULT hr = S_OK;

	if (BSCF_FIRSTDATANOTIFICATION & grfBSCF)
	{
		// Cache the incoming Stream
		if (!m_pstm && pstgmed->tymed == TYMED_ISTREAM)
		{
			m_pstm = pstgmed->pstm;
			if (m_pstm)
				m_pstm->AddRef();
    	}
	}

	// If there is some data to be read then go ahead and read it
	if (m_pstm && dwSize > m_cbOld)
	{
		DWORD dwRead = dwSize - m_cbOld; // Minimum amount available that hasn't been read
		DWORD dwActuallyRead = 0;            // Placeholder for amount read during this pull

		if (dwRead > 0)
		do
		{
			//BYTE *pNewstr = new BYTE[dwRead + 1];
			LPSTR pNewstr = new char[dwRead + 1];
			if (!pNewstr)
			{
				// E_OUTOFMEMORY
				return S_FALSE;
			}

			hr= m_pstm->Read(pNewstr, dwRead, &dwActuallyRead);
			pNewstr[dwActuallyRead] = '\0';

			if (dwActuallyRead > 0)
			{
				m_cbOld += dwActuallyRead;
				if( (m_Events) && (::IsWindow(m_hwndEvents)) )
				{
					//Notify client
					USES_CONVERSION;
					m_vboolCancel = VARIANT_FALSE;
					m_Events->Fire_OnPostDataAvailable(m_Uid, fUrl, 
										A2BSTR(pNewstr), &m_vboolCancel);
					if(m_vboolCancel == VARIANT_TRUE)
					{
						CancelPost();
					}
				}
			}

			delete[] pNewstr;

		} while (!(hr == E_PENDING || hr == S_FALSE) && SUCCEEDED(hr));
	}

	// Clean up
	if (BSCF_LASTDATANOTIFICATION & grfBSCF)
	{
		if (m_pstm)
		{
			m_pstm->Release();
		}
		hr = S_OK;
	}
	return hr;
}

STDMETHODIMP WBBSCBPost::OnObjectAvailable(REFIID riid,IUnknown* punk)
{ return E_NOTIMPL; }

// IHttpNegotiate methods
STDMETHODIMP WBBSCBPost::BeginningTransaction(
        LPCWSTR szURL,
        LPCWSTR szHeaders,
        DWORD dwReserved,
        LPWSTR *pszAdditionalHeaders)
{
	if (!pszAdditionalHeaders)
	{
		return E_POINTER;
	}

	*pszAdditionalHeaders = NULL;

	// This header is required when performing a POST operation
	if (BINDVERB_POST == m_dwAction && m_hDataToPost)
	{
		const WCHAR c_wszHeaders[] = 
			L"Content-Type: application/x-www-form-urlencoded\r\n";
		ULONG llen = wcslen(c_wszHeaders);
		LPWSTR wszAdditionalHeaders = 
			(LPWSTR)CoTaskMemAlloc((llen+1) *sizeof(WCHAR));
		if (!wszAdditionalHeaders)
		{
			return E_OUTOFMEMORY;
		}
		wcscpy(wszAdditionalHeaders, c_wszHeaders);
		wszAdditionalHeaders[llen] = (WCHAR)NULL;
		*pszAdditionalHeaders = wszAdditionalHeaders;
	}

	return S_OK; //return NOERROR;
}

STDMETHODIMP WBBSCBPost::OnResponse(
            DWORD dwResponseCode,
            LPCWSTR szResponseHeaders,
            LPCWSTR szRequestHeaders,
            LPWSTR *pszAdditionalRequestHeaders)
{
	if (!pszAdditionalRequestHeaders)
	{
		return E_POINTER;
	}

	*pszAdditionalRequestHeaders = NULL;

	USES_CONVERSION;
	CTmpBuffer buff(MAX_PATH*2);
	buff = W2CT(szResponseHeaders);
	if (szRequestHeaders)
	{
		//buff += _T("(Repeat request)\r\n");
		buff += W2CT(szRequestHeaders);
	}

	if(::IsWindow(m_hwndEvents))
	{
		long lResponseCode = static_cast<long>(dwResponseCode);
		m_Events->Fire_OnPostResponse(m_Uid, fUrl, lResponseCode, T2BSTR(buff));
	}
	return S_OK; //return NOERROR;
}

HRESULT WBBSCBPost::InitPost(short iID, CvbWB *pHost, BSTR URL, LPCTSTR szData)
{
	if (szData)
	{
//		if(szData[0] == '?')
//			m_dwAction = BINDVERB_GET;
//		else { }
		// MSINTERNAL: See CINetHttp::INetAsyncSendRequest (cnethttp.cxx) that URLMON calls CINetHttp::GetDataToSend() followed by a call to WININET's HttpSendRequest(). GetDataToSend essentially pulls the data out of the BINDINFO that URLMON has cached away when it calls the host's implementation of IBindStatusCallback::GetBindInfo(). 
		// MSINTERNAL: It doesn't attempt to lock down the HGLOBAL at all, so we need to allocated GMEM_FIXED
		m_cbDataToPost = lstrlen(szData);
		m_hDataToPost = GlobalAlloc(GPTR, m_cbDataToPost+1); // GMEM_MOVEABLE won't work because URLMON doesn't attempt GlobalLock before dereferencing
		if (!m_hDataToPost)
		{
			return E_OUTOFMEMORY;
		}

		// the memory was allocate fixed, so no need to lock it down
		lstrcpy((LPTSTR)m_hDataToPost, szData);
	}
	else
	{
		m_dwAction = BINDVERB_GET;
//		DWORD dwTextLen = ::SysStringLen(URL);
//		if (dwTextLen > INTERNET_MAX_PATH_LENGTH)
//		{
//			//_T("Data exceeds max allowable length. Using POST...")
//			//Need to remove ? char and allocate mem for posting data
//			m_dwAction = BINDVERB_POST;
//		}
	}
	
	m_Uid = iID;
	fUrl = URL;
	m_Events = pHost;
	if(m_Events)
		m_hwndEvents = pHost->m_hWnd;

	return S_OK;
}

void WBBSCBPost::CancelPost()
{
	if (m_pstm)
	{
		m_pstm->Release();
		m_pstm = NULL;
	}
	if(m_pBinding)
	{
		m_pBinding->Abort();
	}
}

////////////////////////////////////////////////////////
//
//WBBSCBUpload
//
////////////////////////////////////////////////////////
WBBSCBUpload::WBBSCBUpload()
{
	m_Events = NULL;
	m_hwndEvents = NULL;
	m_pBinding = NULL;
	m_pstm = NULL;
	m_cRef = 0;
	m_cbOld = 0;
	m_dwAction = BINDVERB_POST; //Initially
	m_fRedirect = FALSE;
	m_lprogress = 0;
	m_lprogressmax = 0;
	m_lstatuscode = 0;
	m_vboolCancel = VARIANT_FALSE;
	m_lpBuffer = NULL;
	m_ulDataSize = 0;
	m_stPostData = NULL;
	m_Uid = 0;
	m_hFile = NULL;	
}

WBBSCBUpload::~WBBSCBUpload()
{
}

// IUnknown
ULONG STDMETHODCALLTYPE WBBSCBUpload::AddRef()
{ 
	return m_cRef++; 
}

ULONG STDMETHODCALLTYPE WBBSCBUpload::Release()
{ 
	if (--m_cRef == 0) 
	{ 
		delete this; 
		return 0; 
	} 
	return m_cRef; 
}

STDMETHODIMP WBBSCBUpload::QueryInterface(REFIID iid, void ** ppvObject)
{
	if(ppvObject == NULL) return E_INVALIDARG;
	*ppvObject = NULL;
	if( iid == IID_IBindStatusCallback  || iid == IID_IUnknown)
	{
		*ppvObject = (IBindStatusCallback*)this;
		AddRef();
		return S_OK;
	}
	else if ( iid == IID_IHttpNegotiate )
	{
		*ppvObject = (IHttpNegotiate*)this;
		AddRef();
		return S_OK;
	}
	return E_NOINTERFACE;
}

//IBindStatusCallback
STDMETHODIMP WBBSCBUpload::OnStartBinding(DWORD dwReserved, IBinding * pib)
{
	if (m_pBinding)
	{
		m_pBinding->Release();
	}
	//Cache the URLMON-provided IBinding interface so that we can control the download
	m_pBinding = pib;
	if(m_pBinding)
	{
		m_pBinding->AddRef();
	}
	return S_OK;
}

STDMETHODIMP WBBSCBUpload::GetPriority(LONG * pnPriority)
{ return E_NOTIMPL; }

STDMETHODIMP WBBSCBUpload::OnLowResource(DWORD reserved)
{ return E_NOTIMPL; }

STDMETHODIMP WBBSCBUpload::OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText)
{
	if(ulStatusCode == BINDSTATUS_REDIRECTING)
	{
		m_fRedirect = TRUE;
	}
	if(::IsWindow(m_hwndEvents))
	{
		//Reset
		m_vboolCancel = VARIANT_FALSE;
		m_lprogress = static_cast<long>(ulProgress);
		m_lprogressmax = static_cast<long>(ulProgressMax);
		m_lstatuscode = static_cast<long>(ulStatusCode);
		m_stattext.Empty();

		if(szStatusText)
		{
			m_stattext = szStatusText; //W2BSTR(szStatusText)
		}
		else
			m_stattext = L"";

		//m_Events->Fire_OnUploadOnProgress (m_Uid, fUrl, 
		//			m_lprogress, m_lprogressmax, m_lstatuscode, 
		//			m_stattext, &m_vboolCancel);
		if(m_vboolCancel == VARIANT_TRUE)
		{
			CancelUpload();
		}
	}
	return S_OK;
}

STDMETHODIMP WBBSCBUpload::OnStopBinding(HRESULT hresult,LPCWSTR szError)
{
	if(m_pBinding)
	{
		m_pBinding->Release();
		m_pBinding = NULL;
	}
	
	//Release stream
	if(m_stPostData)
	{
		m_stPostData->Release();
	}
	//Release file handle, if a file name was given
	//rather than raw data
	if(m_hFile)
	{
		CloseHandle(m_hFile);
	}

	//Release temp buffer
	if(m_lpBuffer)
	{
		free((void*)m_lpBuffer);
	}

	if(::IsWindow(m_hwndEvents))
	{
		if((hresult) && (szError))
		{
//One of
//INET_E_INVALID_URL
//INET_E_RESOURCE_NOT_FOUND
//.....
			USES_CONVERSION;
			CTmpBuffer buff(MAX_PATH);
			buff += W2CT(szError);
			buff.AppendResStr((UINT)IDS_ERROR_NUMBER);
			buff.Appendlong(static_cast<long>(hresult));
			CComBSTR sMsg;
			sMsg.Append(buff);
			//m_Events->Fire_OnUploadError(m_Uid, fUrl, sMsg);
		}
		else
		{
			//m_Events->Fire_OnUploadEnd(m_Uid, fUrl);
		}
	}

	//URLmon.dll will call release on this object which will cause delete
	return S_OK;
}

STDMETHODIMP WBBSCBUpload::GetBindInfo(DWORD *grfBINDF, BINDINFO * pbindinfo)
{
	if (m_fRedirect && BINDVERB_POST == m_dwAction)
	{
		// We're being redirected by the server. Stop posting
		m_dwAction = BINDVERB_GET;
	}

	*grfBINDF = BINDF_ASYNCHRONOUS | BINDF_ASYNCSTORAGE | BINDF_PULLDATA;
	*grfBINDF |= BINDF_GETNEWESTVERSION | BINDF_NOWRITECACHE;

	// Set up the BINDINFO data structure
	pbindinfo->cbSize = sizeof(BINDINFO);
	pbindinfo->dwBindVerb = m_dwAction; // here's where the action is defined
	pbindinfo->szExtraInfo = NULL;

	// Initialize the STGMEDIUM.
	if(m_dwAction == BINDVERB_POST)
	{
		memset(&pbindinfo->stgmedData, 0, sizeof(STGMEDIUM));
	}
	else
	{
		//The stgmedData member of the BINDINFO structure should be set 
		//to TYMED_NULL for the GET operation. 
		memset(&pbindinfo->stgmedData, 0, TYMED_NULL);
	}
	pbindinfo->grfBindInfoF = 0;
	pbindinfo->szCustomVerb = NULL;
	//Reserved. Must be set to 0
	pbindinfo->dwOptions = 0;
	pbindinfo->dwOptionsFlags = 0;
	pbindinfo->dwReserved = 0;

	// set up action-specific members
	switch(m_dwAction)
	{
	case BINDVERB_POST:
		if (m_stPostData)
		{			
			// Fill the STGMEDIUM with the data to post:
			//IE uses TYMED_ISTREAM when submitting a form with <input type="file"> control
			pbindinfo->stgmedData.tymed = TYMED_ISTREAM;
			pbindinfo->stgmedData.pstm = m_stPostData;
			pbindinfo->stgmedData.pUnkForRelease = (LPUNKNOWN)(LPBINDSTATUSCALLBACK)this; //  maintain control over the data.
			pbindinfo->cbstgmedData = // this must be exact! 
				m_ulDataSize;		  // Do not rely on GlobalSize() 
									  // which rounds up to the nearest power of two.
		}
		break;
	case BINDVERB_GET:
		break;
	default:
		return E_FAIL;
	}

	return S_OK;
}

STDMETHODIMP WBBSCBUpload::OnDataAvailable(DWORD grfBSCF, DWORD dwSize, FORMATETC* pformatetc, STGMEDIUM* pstgmed)
{
	 HRESULT hr = S_OK;

	if (BSCF_FIRSTDATANOTIFICATION & grfBSCF)
	{
		// Cache the incoming Stream
		if (!m_pstm && pstgmed->tymed == TYMED_ISTREAM)
		{
			m_pstm = pstgmed->pstm;
			if (m_pstm)
				m_pstm->AddRef();
    	}
	}

	// If there is some data to be read then go ahead and read it
	if (m_pstm && dwSize > m_cbOld)
	{
		DWORD dwRead = dwSize - m_cbOld; // Minimum amount available that hasn't been read
		DWORD dwActuallyRead = 0;            // Placeholder for amount read during this pull

		if (dwRead > 0)
		do
		{
			//BYTE *pNewstr = new BYTE[dwRead + 1];
			LPSTR pNewstr = new char[dwRead + 1];
			if (!pNewstr)
			{
				// E_OUTOFMEMORY
				return S_FALSE;
			}

			hr= m_pstm->Read(pNewstr, dwRead, &dwActuallyRead);
			pNewstr[dwActuallyRead] = '\0';

			if (dwActuallyRead > 0)
			{
				m_cbOld += dwActuallyRead;
				if( (m_Events) && (::IsWindow(m_hwndEvents)) )
				{
					//Notify client
					USES_CONVERSION;
					m_vboolCancel = VARIANT_FALSE;
					//m_Events->Fire_OnUploadDataAvailable(m_Uid, fUrl, 
					//			A2BSTR(pNewstr), &m_vboolCancel);
					if(m_vboolCancel == VARIANT_TRUE)
					{
						CancelUpload();
					}
				}
			}

			delete[] pNewstr;

		} while (!(hr == E_PENDING || hr == S_FALSE) && SUCCEEDED(hr));
	}

	// Clean up
	if (BSCF_LASTDATANOTIFICATION & grfBSCF)
	{
		if (m_pstm)
		{
			m_pstm->Release();
		}
		hr = S_OK;
	}
	return hr;
}

STDMETHODIMP WBBSCBUpload::OnObjectAvailable(REFIID riid,IUnknown* punk)
{ return E_NOTIMPL; }

// IHttpNegotiate methods
STDMETHODIMP WBBSCBUpload::BeginningTransaction(
        LPCWSTR szURL,
        LPCWSTR szHeaders,
        DWORD dwReserved,
        LPWSTR *pszAdditionalHeaders)
{
	if (!pszAdditionalHeaders)
	{
		return E_POINTER;
	}

	*pszAdditionalHeaders = NULL;

	// This header is required when performing a POST operation
	if ((BINDVERB_POST == m_dwAction) && (m_stPostData))
	{
		const WCHAR c_wszHeaders[] = 
			L"Content-Type: application/x-www-form-urlencoded\r\n";
		ULONG llen = wcslen(c_wszHeaders);
		LPWSTR wszAdditionalHeaders = 
			(LPWSTR)CoTaskMemAlloc((llen+1) *sizeof(WCHAR));
		if (!wszAdditionalHeaders)
		{
			return E_OUTOFMEMORY;
		}

		wcscpy(wszAdditionalHeaders, c_wszHeaders);
		wszAdditionalHeaders[llen] = (WCHAR)NULL;
		*pszAdditionalHeaders = wszAdditionalHeaders;
	}

	return S_OK; //return NOERROR;
}

STDMETHODIMP WBBSCBUpload::OnResponse(
            DWORD dwResponseCode,
            LPCWSTR szResponseHeaders,
            LPCWSTR szRequestHeaders,
            LPWSTR *pszAdditionalRequestHeaders)
{
	if (!pszAdditionalRequestHeaders)
	{
		return E_POINTER;
	}

	*pszAdditionalRequestHeaders = NULL;

	USES_CONVERSION;
	CTmpBuffer buff(MAX_PATH*2);
	buff = W2CT(szResponseHeaders);
	if (szRequestHeaders)
	{
		//buff += _T("(Repeat request)\r\n");
		buff += W2CT(szRequestHeaders);
	}

	if(::IsWindow(m_hwndEvents))
	{
		long lResponseCode = static_cast<long>(dwResponseCode);
		//m_Events->Fire_OnUploadResponse(m_Uid, fUrl, lResponseCode, T2BSTR(buff));
	}
	return S_OK; //return NOERROR;
}

HRESULT WBBSCBUpload::InitUpload(short iID, CvbWB *pHost, BSTR URL, void *pvBuffer, ULONG uSize)
{
	m_Uid = iID;
	fUrl = URL;
	m_Events = pHost;
	if(m_Events)
		m_hwndEvents = pHost->m_hWnd;
	m_ulDataSize = uSize;
	
	//Copy data to local variable
	char *chTmp = (char*) malloc((m_ulDataSize+1) * sizeof(char));
	if(chTmp == NULL)
		return S_FALSE;
	chTmp[m_ulDataSize] = '\0';
	m_lpBuffer = (void*)chTmp;
	memcpy(m_lpBuffer, pvBuffer, m_ulDataSize * sizeof(char));
	
	m_stPostData = new WBStream();
	if(m_stPostData == NULL)
		return S_FALSE;
	
	m_stPostData->InitWBStreamData(iID, pHost, this, URL, m_lpBuffer, m_ulDataSize);
	return S_OK;
}

HRESULT WBBSCBUpload::InitUploadFile(short iID, CvbWB *pHost, BSTR URL, LPCTSTR sFileName)
{
	m_Uid = iID;
	fUrl = URL;
	m_Events = pHost;
	if(m_Events)
		m_hwndEvents = pHost->m_hWnd;
//Attempt to open the file and get it's size
	if(sFileName == NULL || *sFileName == _T('\0'))
		return S_FALSE;

	//Open file
	m_hFile = CreateFile(sFileName, GENERIC_READ, 0, NULL,
						OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if(m_hFile == INVALID_HANDLE_VALUE)
		return S_FALSE;
	m_ulDataSize = GetFileSize(m_hFile, NULL);
	if( m_ulDataSize == INVALID_FILE_SIZE )
	{
		CloseHandle(m_hFile);
		return S_FALSE;
	}
	m_stPostData = new WBStream();
	if(m_stPostData == NULL)
		return S_FALSE;
	m_stPostData->InitWBStreamFileName(iID, pHost, this, URL, m_hFile, m_ulDataSize);
	return S_OK;
}

void WBBSCBUpload::CancelUpload()
{
	if (m_pstm)
	{
		m_pstm->Release();
		m_pstm = NULL;
	}
	if(m_pBinding)
	{
		m_pBinding->Abort();
	}
}



////////////////////////////////////////////////////////////////////////////////////////
//WBPassthruSink
//Monitor and/or cancel every request and responde
//WB makes, including images, sounds, scripts, etc
////////////////////////////////////////////////////////////////////////////////////////
HRESULT WBPassthruSink::OnStart(LPCWSTR szUrl, IInternetProtocolSink *pOIProtSink,
		IInternetBindInfo *pOIBindInfo, DWORD grfPI, DWORD dwReserved,
		IInternetProtocol* pTargetProtocol)
{
	HRESULT hr = BaseClass::OnStart(szUrl, pOIProtSink, pOIBindInfo, grfPI,
		dwReserved, pTargetProtocol);
	
	//Initialize our variables
	m_pHost = NULL;   //IWB instance
	m_pEvents = NULL; //vbWB instance
	m_Hostid = 0;
	m_strUrl.Empty();
	m_strRedirUrl.Empty();
	m_strRedirHeaders.Empty();

	//Find the instance of WB and IWB (host)
	CComPtr<IWindowForBindingUI> objWindowForBindingUI;
	HRESULT hret = QueryServiceFromClient(&objWindowForBindingUI);
	if( (SUCCEEDED(hret)) && (objWindowForBindingUI) )
	{
		HWND hwndIEServer = NULL;
		//Should return InternetExplorerServer HWND
		objWindowForBindingUI->GetWindow(IID_IHttpSecurity, &hwndIEServer);
		//From here we can find the ATL window hosting this instance of our control
		//and have it fire an event for the form/dlg hosting this instance of our control
		if(hwndIEServer)
		{
			for(int i = 0; i < gCtrlInstances.GetSize(); i++)
			{
				m_pEvents = reinterpret_cast<CvbWB*>(gCtrlInstances[i]);
				if(m_pEvents->FindWBHost(hwndIEServer, &m_pHost) == TRUE)
				{
					m_Hostid = m_pHost->m_thisID;
					break;
				}
			}
		}
	}

	//This is available for the primary connection (once per request)
	//and not for images,...
//	QueryServiceFromClient(&spBSCB);
//	if(spBscb)
//		Alert(_T("Got it"));
	return hr;
}

STDMETHODIMP WBPassthruSink::Switch(
	/* [in] */ PROTOCOLDATA *pProtocolData)
{
	ATLASSERT(m_spInternetProtocolSink != 0);

/*
From Igor Tandetnik "itandetnik@mvps.org"
"
Beware multithreading. URLMon has this nasty habit of spinning worker 
threads, not even bothering to initialize COM on them, and calling APP 
methods on those threads. If you try to raise COM events directly from 
such a thread, bad things happen (random crashes, events being lost). 
You are only guaranteed to be on the main STA thread in two cases. 
First, in methods of interfaces that were obtained with 
IServiceProvider, such as IHttpNegotiage::BeginningTransaction or 
IAuthenticate::Authenticate. Second, you can call 
IInternetProtocolSink::Switch with PD_FORCE_SWITCH flag in 
PROTOCOLDATA::grfFlags, eventually URLMon will turn around and call 
IInternetProtocol::Continue on the main thread. 

Or, if you happen to have a window handy that was created on the main 
thread, you can post yourself a message.
"
*/
	//if( (pProtocolData->grfFlags & PD_FORCE_SWITCH) != PD_FORCE_SWITCH)
	if( (pProtocolData->grfFlags & PD_FORCE_SWITCH) == 0)
		pProtocolData->grfFlags |= PD_FORCE_SWITCH;

	return m_spInternetProtocolSink ?
		m_spInternetProtocolSink->Switch(pProtocolData) :
		E_UNEXPECTED;
}


STDMETHODIMP WBPassthruSink::BeginningTransaction(LPCWSTR szURL, LPCWSTR szHeaders, DWORD dwReserved, LPWSTR *pszAdditionalHeaders)
{
	if (pszAdditionalHeaders)
	{
		*pszAdditionalHeaders = 0;
	}

	CComPtr<IHttpNegotiate> spHttpNegotiate;
	QueryServiceFromClient(&spHttpNegotiate);
	HRESULT hr = spHttpNegotiate ?
		spHttpNegotiate->BeginningTransaction(szURL, szHeaders,
			dwReserved, pszAdditionalHeaders) : S_OK;

	USES_CONVERSION;
	if(szURL)
		m_strUrl.AppendBSTR(W2BSTR(szURL));
	else
		m_strUrl = L"";
	m_strRedirUrl = L"";

		CComBSTR strRequestHeaders;
		//Get raw request headers and send them to client
		CComPtr<IWinInetHttpInfo> spWinInetHttpInfo;
		HRESULT hrTemp = m_spTargetProtocol->QueryInterface(IID_IWinInetHttpInfo,
			reinterpret_cast<void**>(&spWinInetHttpInfo));
		if(SUCCEEDED(hrTemp))
		{
			DWORD size = 0;
			DWORD flags = 0;
			hrTemp = spWinInetHttpInfo->QueryInfo(
				HTTP_QUERY_RAW_HEADERS_CRLF | HTTP_QUERY_FLAG_REQUEST_HEADERS,
				0, &size, &flags, 0);
			if(SUCCEEDED(hrTemp))
			{
				LPSTR pbuf = new char[size+1];
				pbuf[size] = '\0';
				hrTemp = spWinInetHttpInfo->QueryInfo(
					HTTP_QUERY_RAW_HEADERS_CRLF | HTTP_QUERY_FLAG_REQUEST_HEADERS,
					pbuf, &size, &flags, 0);
				if(SUCCEEDED(hrTemp))
				{
					//\r\n\r\n\0 Get rid of extra
					if( (size > 5) &&
						(pbuf[size-1] == '\n') && (pbuf[size-2] == '\r') &&
						(pbuf[size-3] == '\n') && (pbuf[size-4] == '\r') )
					{
						pbuf[size-1] = '\0';
						pbuf[size-2] = '\0';
					}
					//pbuf should contain all request headers
					strRequestHeaders.Append(pbuf);
				}
				else
					strRequestHeaders = L"";
			}
			else
				strRequestHeaders = L"";
		}
		else
			strRequestHeaders = L"";

		//Additional Client headers
		CComBSTR strAddHttpHeaders;

		if(szHeaders)
		{
			//Accept-Encoding: gzip, deflate
			strRequestHeaders += W2BSTR(szHeaders);
			strRequestHeaders.Append(vbCrLf);
		}
		if( pszAdditionalHeaders && *pszAdditionalHeaders)
		{
			//Referer: http://www.google.ca/
			//Accept-Language: en-ca
			strAddHttpHeaders = W2BSTR(*pszAdditionalHeaders);
			strRequestHeaders += strAddHttpHeaders;
		}
		//Fire event
		if( (m_pEvents) && (m_Hostid > 0) )
		{
			VARIANT_BOOL bcancel = VARIANT_FALSE;
			CComBSTR strTempHeaders(L"");
			m_pEvents->Fire_ProtocolHandlerOnBeginTransaction(m_Hostid, 
												m_strUrl, strRequestHeaders, 
												&strTempHeaders, &bcancel);
			if(bcancel == VARIANT_TRUE)
				return E_ABORT;
			
			//Did client add any of their headers
			if(strTempHeaders.Length() > 0)
			{
				strTempHeaders += strAddHttpHeaders;
				if(strTempHeaders.Length() > 0)
				{
					LPWSTR wszAdditionalHeaders = (LPWSTR)CoTaskMemAlloc((strTempHeaders.Length()+1) *sizeof(WCHAR));
					if(wszAdditionalHeaders)
					{
						//Free what we had
						CoTaskMemFree(*pszAdditionalHeaders);
						wcscpy(wszAdditionalHeaders, OLE2W(strTempHeaders));
						wszAdditionalHeaders[strTempHeaders.Length()] = (WCHAR)NULL;
						*pszAdditionalHeaders = wszAdditionalHeaders;
					}
				}
			}
		}

	return hr;
}

STDMETHODIMP WBPassthruSink::OnResponse(DWORD dwResponseCode, LPCWSTR szResponseHeaders, LPCWSTR szRequestHeaders, LPWSTR *pszAdditionalRequestHeaders)
{
	if (pszAdditionalRequestHeaders)
	{
		*pszAdditionalRequestHeaders = 0;
	}
	CComPtr<IHttpNegotiate> spHttpNegotiate;
	QueryServiceFromClient(&spHttpNegotiate);
	HRESULT hr = spHttpNegotiate ?
		spHttpNegotiate->OnResponse(dwResponseCode, szResponseHeaders,
			szRequestHeaders, pszAdditionalRequestHeaders) : S_OK;


	USES_CONVERSION;
	CTmpBuffer buff(MAX_PATH*2);
	buff = W2CT(szResponseHeaders);
	if (szRequestHeaders)
	{
		//buff += _T("(Repeat request)\r\n");
		buff += W2CT(szRequestHeaders);
		if (SUCCEEDED(hr) && pszAdditionalRequestHeaders &&
			*pszAdditionalRequestHeaders)
		{
			buff += W2CT(*pszAdditionalRequestHeaders);
		}
	}
	if( (m_pEvents) && (m_Hostid > 0) )
	{
		VARIANT_BOOL bcancel = VARIANT_FALSE;
		//Fire event
		m_pEvents->Fire_ProtocolHandlerOnResponse(m_Hostid, m_strUrl, 
											T2BSTR(buff), m_strRedirUrl, 
											m_strRedirHeaders, &bcancel);

		if(bcancel == VARIANT_TRUE)
			return m_spTargetProtocol->Abort(E_ABORT,0);

		if(m_strRedirUrl.Length() > 0)
		{
			m_strUrl.Empty();
			m_strUrl = m_strRedirUrl;
		}
	}

	return hr;
}

STDMETHODIMP WBPassthruSink::ReportProgress(ULONG ulStatusCode, LPCWSTR szStatusText)
{

	ATLASSERT(m_spInternetProtocolSink != 0);
	HRESULT hr = m_spInternetProtocolSink ?
		m_spInternetProtocolSink->ReportProgress(ulStatusCode, szStatusText) :
		S_OK;

	if(ulStatusCode == BINDSTATUS_REDIRECTING)
	{
		USES_CONVERSION;

		//Get redirected URL
		m_strRedirUrl.Empty();
		if(szStatusText)
			m_strRedirUrl.AppendBSTR(W2BSTR(szStatusText));
		else
			m_strRedirUrl = L"";
		
		//To get redirect headers during a redirect
		//No OnResponse is fired for a redirect
		m_strRedirHeaders.Empty();
		//Get raw request headers and send them to client
/*
Client applications can call QueryInterface on the IBinding 
interface to get a pointer to the IWinInetHttpInfo interface 
after your implementation of the IBindStatusCallback::OnProgress 
method has been called.
*/
		CComPtr<IWinInetHttpInfo> spWinInetHttpInfo;
		HRESULT hrTemp = m_spTargetProtocol->QueryInterface(IID_IWinInetHttpInfo,
			reinterpret_cast<void**>(&spWinInetHttpInfo));
		if(SUCCEEDED(hrTemp))
		{
			DWORD size = 0;
			DWORD flags = 0;
			hrTemp = spWinInetHttpInfo->QueryInfo( HTTP_QUERY_RAW_HEADERS_CRLF,
				0, &size, &flags, 0);
			if(SUCCEEDED(hrTemp))
			{
				LPSTR pbuf = new char[size+1];
				pbuf[size] = '\0';
				hrTemp = spWinInetHttpInfo->QueryInfo( HTTP_QUERY_RAW_HEADERS_CRLF,
					pbuf, &size, &flags, 0);
				if(SUCCEEDED(hrTemp))
				{
					//\r\n\r\n\0 Get rid of extra
					if( (size > 5) &&
						(pbuf[size-1] == '\n') && (pbuf[size-2] == '\r') &&
						(pbuf[size-3] == '\n') && (pbuf[size-4] == '\r') )
					{
						pbuf[size-1] = '\0';
						pbuf[size-2] = '\0';
					}
					//pbuf should contain all request headers
					m_strRedirHeaders.Append(pbuf);
				}
				else
					m_strRedirHeaders = L"";
			}
			else
				m_strRedirHeaders = L"";
		}
		else
			m_strRedirHeaders = L"";
	}

	return hr;
}

//////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////
STDMETHODIMP WBNewWindowManager::EvaluateNewWindow(LPCWSTR pszUrl, LPCWSTR pszName, 
						  LPCWSTR pszUrlContext, LPCWSTR pszFeatures, 
						  BOOL fReplace, DWORD dwFlags,
						  DWORD dwUserActionTime)
{

	HRESULT hr = E_FAIL; //To perform default IE action
	long lRet = lEFail;
	
	VARIANT_BOOL bReplace = VARIANT_FALSE;
	if(fReplace)
		bReplace = VARIANT_TRUE;

	CComBSTR surl;
	CComBSTR sname;
	CComBSTR surlctx;
	CComBSTR sfeat;

	if(pszUrl)
		surl = pszUrl;
	else
		surl = L"";

	if(pszName)
		sname = pszName;
	else
		sname = L"";

	if(pszUrlContext)
		surlctx = pszUrlContext;
	else
		surlctx = L"";

	if(pszFeatures)
		sfeat = pszFeatures;
	else
		sfeat = L"";

	m_pHost->m_EventsPtr->Fire_WBEvaluateNewWindow(m_pHost->m_thisID, 
		surl, sname, surlctx, sfeat, bReplace, (long)dwFlags, (long)dwUserActionTime, &lRet);

	if(lRet == 0) //Allow
		hr = S_OK;
	else if(lRet == 1) //Disallow
		hr = S_FALSE;

	return hr;
}

//////////////////////////////////////////////////////////////
//CTmpBuffer
//////////////////////////////////////////////////////////////
CTmpBuffer::CTmpBuffer()
{
	InitLocalResources();
	AllocateBuffer(STARTUP_TEMP_BUFFER);
}

CTmpBuffer::CTmpBuffer(LPCTSTR strText)
{
	InitLocalResources();
	Append(strText);
}

CTmpBuffer::CTmpBuffer(UINT iSize)
{
	InitLocalResources();
	AllocateBuffer(iSize);
}

CTmpBuffer::~CTmpBuffer()
{
	ClearLocalResources();
}

void CTmpBuffer::ResetBuffer()
{
	if( (m_Buffer) && (m_BufferLen > 0) && (m_Allocated == true) )
	{
		//Mark the beginning and end
		m_Buffer[m_BufferLen] = _T('\0');
		m_Buffer[0] = _T('\0');
	}
	m_BufferTextLen = 0;
}

//Allocate buffer
UINT CTmpBuffer::AllocateBuffer(UINT nsize)
{
	if(nsize < 1)
		return 0;
	//Attempting to increase storage
	if( (m_Buffer) && (m_Allocated == true) )
	{
		LPTSTR tempbuffer = (LPTSTR)malloc((m_BufferLen+nsize+1) * sizeof(TCHAR));
		if(tempbuffer == NULL)
			return -1;
		//Adjust actual size of buffer
		m_BufferLen += nsize;
		tempbuffer[m_BufferLen] = _T('\0');
		//Copy what we have (m_BufferTextLen = actual number of characters in the buffer)
		if(m_BufferTextLen > 0)
			memcpy(tempbuffer, m_Buffer, m_BufferTextLen * sizeof(TCHAR));

		tempbuffer[m_BufferTextLen] = _T('\0');
		//Free current buffer and reassign
		free(m_Buffer);
		m_Buffer = tempbuffer;
	}
	else
	{
		//First time, just allocate
		m_Buffer = (LPTSTR)malloc( (nsize+1) * sizeof(TCHAR));
		if(m_Buffer == NULL)
			return -1;
		m_BufferLen = nsize;

		m_Buffer[m_BufferLen] = _T('\0');
		m_Buffer[0] = _T('\0');

		//No text in the buffer
		m_BufferTextLen = 0;
	}
	m_Allocated = true;
	return m_BufferLen;
}

//Append a string
UINT CTmpBuffer::Append(LPCTSTR strText, UINT iMaxLen)
{
	if( (strText == NULL) || (*strText == _T('\0')) )
		return 0;

	UINT nappend = 0;
	if(iMaxLen > 0)
		nappend = iMaxLen;
	else
		nappend = _tcslen(strText);

	if(nappend == 0)
		return 0;

	//Get actual buffer len + len of new text
	//to compare with the total buffer len
	UINT newlen = m_BufferTextLen + nappend;

	//Check
	if( (m_Buffer == NULL) || (m_Allocated == false) )
	{
		AllocateBuffer(newlen);
	}

	//Still have room
	if(m_BufferLen >= newlen)
	{
		//Just copy data
		memcpy(m_Buffer+m_BufferTextLen, strText, nappend * sizeof(TCHAR));
	}
	else
	{
		//Create a new storage + nGrowSize for the next strText
		LPTSTR tempbuffer = (LPTSTR)malloc( (newlen+1) * sizeof(TCHAR));
		if(tempbuffer == NULL)
			return 0;
		m_BufferLen = newlen;
		tempbuffer[m_BufferLen] = _T('\0');
		//Copy from buffer first and then the actual data
		memcpy(tempbuffer, m_Buffer, m_BufferTextLen * sizeof(TCHAR));
		memcpy(tempbuffer+m_BufferTextLen, strText, nappend * sizeof(TCHAR));
		//Empty buffer and reassign
		free(m_Buffer);
		m_Buffer = tempbuffer;
	}
	//Adjust actual number of text in buffer
	m_BufferTextLen = newlen;
	//Mark the end of actual text appended
	m_Buffer[m_BufferTextLen] = _T('\0');
	return newlen;
}

//Append a BSTR
UINT CTmpBuffer::AppendBSTR(BSTR strText, UINT iMaxLen)
{
	if(strText == NULL)
		return 0;
	UINT dwChars = ::SysStringLen(strText);
	LPTSTR pLocal = (LPTSTR)malloc( (dwChars+1) * sizeof(TCHAR));
	if(pLocal == NULL)
		return 0;
	pLocal[dwChars] = _T('\0');
#ifdef UNICODE
	lstrcpyn(pLocal, strText, dwChars);
#else
	WideCharToMultiByte(CP_ACP, 0, strText, -1, pLocal, dwChars, NULL, NULL);
#endif
	
	UINT iRet = Append(pLocal, iMaxLen);
	free(pLocal);
	return iRet;
}

//Append an int value
UINT CTmpBuffer::Appendint(int iNumber, int radix)
{
	TCHAR tmp[50];
#ifdef UNICODE
	_itow(iNumber, tmp, radix);
#else
	_itoa(iNumber, tmp, radix);
#endif
	return Append(tmp);
}

//Append a long value
UINT CTmpBuffer::Appendlong(long lNumber, int radix)
{
	TCHAR tmp[50];
#ifdef UNICODE
	_ltow(lNumber, tmp, radix);
#else
	_ltoa(lNumber, tmp, radix);
#endif
	return Append(tmp);
}

UINT CTmpBuffer::AppendGUID(REFGUID src)
{
	OLECHAR wszBuff[39];
	int i = StringFromGUID2(src, wszBuff, 39);
	TCHAR szBuff[39];
#ifdef UNICODE
	lstrcpyn(szBuff, wszBuff, 39);
#else
	WideCharToMultiByte(CP_ACP, 0, wszBuff, -1, szBuff, 39, NULL, NULL);
#endif
	return Append((LPCTSTR)szBuff);
}

UINT CTmpBuffer::AppendResStr(UINT nID, UINT iMaxLen)
{
	TCHAR sz[RES_BUFFER_SIZE];
	int nCount =  sizeof(sz) / sizeof(sz[0]);
//	UINT nLen = ::LoadString(m_hInst, nID, sz, sizeof(sz)/sizeof(TCHAR));
	UINT nLen = ::LoadString(m_hInst, nID, sz, nCount);
	UINT iRet = 0;
	if(nLen == 0)
		return iRet;
	//All string was read else need to read entire string
	//by increasing buffer size and trying again.
	//if (nCount - nLen > CHAR_FUDGE)
	iRet = Append( (LPCTSTR)sz, iMaxLen );
	return iRet;
}

//Accessors
TCHAR* CTmpBuffer::GetString(void)
{ return m_Buffer; }

UINT CTmpBuffer::ReleaseString(void)
{
	UINT iRet = 0;
	if(m_Buffer)
	{
		iRet = _tcslen(m_Buffer);
		if (iRet > 0)
		{
			m_BufferLen = iRet;
			m_BufferTextLen = iRet;
			m_Buffer[m_BufferTextLen] = _T('\0');
		}
	}
	return iRet;
}

LPCTSTR CTmpBuffer::GetBuffer(void) const
{ return m_Buffer; }

UINT CTmpBuffer::GetBufferLen(void) const
{ return m_BufferLen; }

UINT CTmpBuffer::GetBufferTextLen(void) const
{ return m_BufferTextLen; }

TCHAR CTmpBuffer::GetAt(int nIndex)
{
	if((UINT)nIndex < m_BufferLen) 
		return m_Buffer[nIndex];
	else
		return 0;
}
void CTmpBuffer::SetAt(int nIndex, TCHAR ch)
{
	if((UINT)nIndex < m_BufferLen)
		m_Buffer[nIndex] = ch;
}

TCHAR CTmpBuffer::operator[] (int nIndex)
{
	if((UINT)nIndex < m_BufferLen) 
		return m_Buffer[nIndex];
	else
		return 0;
}

CTmpBuffer& CTmpBuffer::operator=(const CTmpBuffer& src)
{
	//We don't destroy any buffers allocated
	ResetBuffer();
	Append(src);
	return *this;
}

CTmpBuffer& CTmpBuffer::operator=(const LPCTSTR src)
{
	ResetBuffer();
	Append(src);
	return *this;
}

CTmpBuffer& CTmpBuffer::operator+=(const CTmpBuffer& strSrc)
{
	Append(strSrc);
	return *this;
}

CTmpBuffer& CTmpBuffer::operator+=(const LPCTSTR strSrc)
{
	Append(strSrc);
	return *this;
}

CTmpBuffer& CTmpBuffer::operator=(const UINT nID)
{
	ResetBuffer();
	AppendResStr(nID);
	return *this;
}

CTmpBuffer& CTmpBuffer::operator+=(const UINT nID)
{
	AppendResStr(nID);
	return *this;
}

void CTmpBuffer::InitLocalResources()
{
	m_cRef = 1;
	m_Buffer = NULL;
	m_BufferLen = 0;
	m_BufferTextLen = 0;
	m_Allocated = false;
	#if (_ATL_VER >= 0x0700)
		m_hInst = ATL::_AtlBaseModule.GetResourceInstance();
	#else //#if (_ATL_VER == 0x0300)
		m_hInst = _Module.GetResourceInstance();
	#endif
}

void CTmpBuffer::ClearLocalResources()
{
	if( (m_Buffer) && (m_BufferLen > 0) && (m_Allocated == true) )
		free(m_Buffer);
	m_Buffer = NULL;
	m_BufferLen = 0;
	m_BufferTextLen = 0;
	m_Allocated = false;
}

////////////////////////////////////////////////////////////////////////////////////////
//CVariantBSTRArray
////////////////////////////////////////////////////////////////////////////////////////
CVariantBSTRArray::CVariantBSTRArray()
{
	InternalInit();
}

CVariantBSTRArray::CVariantBSTRArray(ULONG lInitSize)
{
	InternalInit();
	if(lInitSize > 0)
		CreateArray(lInitSize);
}

CVariantBSTRArray::~CVariantBSTRArray()
{
	/*
	For VT_ARRAY | any type, the rule is analogous to the rule for VT_BSTR.
	All arrays in variants must be allocated with SafeArrayCreate.
	When releasing or changing the type of a variant with the VT_ARRAY flag set,
	SafeArrayDestroy is called.
	Safearrays of BSTR will have SysFreeString called
	on each element not VariantClear.
	*/
	VariantClear(&var);
}

BOOL CVariantBSTRArray::CreateArray(ULONG lInitSize)
{
	rgsabound[0].cElements = lInitSize;
	psa = SafeArrayCreate(VT_BSTR, 1, rgsabound);
	var.parray = psa;
	return (psa != NULL) ? TRUE : FALSE;
}

//Adds BSTRs by making a local copy of data and checks for duplicates
//Comparison case incensetive
BOOL CVariantBSTRArray::AddItemNoDuplicate(LPCTSTR pszItem)
{
	if( (pszItem == NULL) || (*pszItem == _T('\0')) )
		return FALSE;

	USES_CONVERSION;
	BSTR bstrTemp = ::SysAllocString(T2BSTR(pszItem));
	if(bstrTemp == NULL)
		return FALSE;

	if(psa == NULL) //Create?
	{
		if(!CreateArray())
		{
			SysFreeString(bstrTemp);
			return FALSE;
		}
	}
	else
	{
		//First item
		if(m_lCur == -1)
			return AddBSTRItem(bstrTemp);
		//Check for duplicates
		if(IsDuplicate(bstrTemp))
		{
			SysFreeString(bstrTemp);
			return FALSE;
		}
	}
	return AddBSTRItem(bstrTemp);
}

//Adds BSTRs by making a local copy of data
BOOL CVariantBSTRArray::AddItem(LPCTSTR pszItem)
{
	if( (pszItem == NULL) || (*pszItem == _T('\0')) )
		return FALSE;
	if(psa == NULL) //Create?
	{
		if(!CreateArray())
			return FALSE;
	}

	USES_CONVERSION;
	return AddBSTRItem(::SysAllocString(T2BSTR(pszItem)));
}

//Do not Free pItem memory. It is stored without making a copy
//the memory for the item will be released when class terminates.
//If bFreeBSTROnError is TRUE, pItem will be freed if an error occurs
BOOL CVariantBSTRArray::AddBSTR(BSTR pItem, BOOL bFreeBSTROnError)
{
	if(pItem == NULL)
		return FALSE;
	if(psa == NULL) //Create?
	{
		if(!CreateArray())
		{
			if(bFreeBSTROnError)
				SysFreeString(pItem);
			return FALSE;
		}
	}
	return AddBSTRItem(pItem, bFreeBSTROnError);
}

//If bFreeBSTROnError is TRUE, pItem will be freed if
//an error occurs or a duplicated is found
BOOL CVariantBSTRArray::AddBSTRNoDuplicate(BSTR pItem, BOOL bFreeBSTROnError)
{
	if(pItem == NULL)
		return FALSE;

	if(psa == NULL)
	{
		if(!CreateArray())
		{
			if(bFreeBSTROnError)
				SysFreeString(pItem);
			return FALSE;
		}
		return AddBSTRItem(pItem);
	}

	if(m_lCur == -1) //First item
		return AddBSTRItem(pItem);

	if(IsDuplicate(pItem))
	{
		if(bFreeBSTROnError)
			SysFreeString(pItem);
		return FALSE;
	}

	return AddBSTRItem(pItem);
}

BOOL CVariantBSTRArray::ClearExtra()
{
	if(psa == NULL)
		return FALSE;
	//No extras
	if((m_lCur+1) == psa->rgsabound[0].cElements)
		return TRUE;
	//Resize
	rgsabound[0].cElements = m_lCur + 1;
	HRESULT hr = SafeArrayRedim(psa, rgsabound);

	return (SUCCEEDED(hr)) ? TRUE : FALSE;
}

//Simple sort, Call after ClearExtra if Size > ItemsCount
BOOL CVariantBSTRArray::SortArray()
{
	if(psa == NULL)
		return FALSE;

	ULONG i, j, min;
	BSTR bstrTemp;

	HRESULT hr = SafeArrayAccessData(psa, (void HUGEP**)&pbstr);
	if(FAILED(hr))
		return FALSE;

	// Selection sort;
	for (i = 0; i < psa->rgsabound[0].cElements-1; i++)
	{
	   min = i;
	   for (j = i+1; j < psa->rgsabound[0].cElements; j++)
	   {
		  if (wcscmp(pbstr[j], pbstr[min]) < 0)
			 min = j;
	   }

	   // Swap array[min] and array[i].
	   bstrTemp = pbstr[min];
	   pbstr[min] = pbstr[i];
	   pbstr[i] = bstrTemp;
	}

	SafeArrayUnaccessData(psa);
	return TRUE;
}

void CVariantBSTRArray::InternalInit()
{
	VariantInit(&var);
	var.vt = VT_ARRAY | VT_BSTR;
	psa = NULL; //Not created yet
	rgsabound[0].lLbound = 0;
	m_lCur = -1;
	rgsabound[0].cElements = 0; //initialy
}

BOOL CVariantBSTRArray::AddBSTRItem(BSTR pItem, BOOL bFreeBSTROnError)
{
	HRESULT hr = SafeArrayAccessData(psa, (void HUGEP**)&pbstr);
	if(FAILED(hr))
		goto Error;

	m_lCur++;
	//Check for storage space
	if(m_lCur >= psa->rgsabound[0].cElements)
	{
		rgsabound[0].cElements = psa->rgsabound[0].cElements + 1;
		SafeArrayUnaccessData(psa); //Unlock
		//Redim
		hr = SafeArrayRedim(psa, rgsabound);
		if(FAILED(hr))
			goto Error;
		//Access data
		hr = SafeArrayAccessData(psa, (void HUGEP**)&pbstr);
		if(FAILED(hr))
			goto Error;
	}
	
	//Assign
	pbstr[m_lCur] = pItem;
	SafeArrayUnaccessData(psa);

	return (pbstr[m_lCur] != NULL) ? TRUE : FALSE;

	Error:
		if( (pItem) && (bFreeBSTROnError) )
			SysFreeString(pItem);
		return FALSE;
}

//Searches for duplicates case sensitive
//If a dup is found BSTR is freed
BOOL CVariantBSTRArray::IsDuplicate(BSTR pItem)
{
	BOOL bRet = FALSE;
	HRESULT hr = SafeArrayAccessData(psa, (void HUGEP**)&pbstr);
	if(FAILED(hr))
		return FALSE;

	for (ULONG i = 0; i < psa->rgsabound[0].cElements-1; i++)
	{
		if (wcscmp(pbstr[i], pItem) == 0)
		{
			bRet = TRUE;
			break;
		}
	}
	SafeArrayUnaccessData(psa);
	return bRet;
}

////////////////////////////////////////////////////////////////////////////////////////

int vbLog(LPCTSTR szData,LPCTSTR szHeader,LPCTSTR szFileName)
{
	if( (szData == NULL) || (szHeader == NULL) )
		return 0;
/*
If you call the CreateFile API with the OPEN_ALWAYS flag when the specified file
already exists, the API should return a valid handle and 
GetLastError should return ERROR_ALREADY_EXISTS. 

When the file that is being opened is being accessed using either
a UNC path name or through a mapped drive, GetLastError sometimes
returns ERROR_SUCCESS even if the file already exists. 
RESOLUTION
Break up the CreateFile call with the OPEN_ALWAYS flag into two separate calls to
CreateFile. 

Call CreateFile with the OPEN_EXISTING flag. If the call to CreateFile succeeds,
the file already existed. If the call to CreateFile fails, you can call CreateFile
with the OPEN_ALWAYS flag. 
*/
	HANDLE hFile = CreateFile(szFileName, GENERIC_WRITE, 0, NULL,
						OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if(GetLastError() == ERROR_ALREADY_EXISTS)
	{
		//Get the file size
		DWORD dwSize = GetFileSize(hFile, 0);
		//Move pointer to the end of file, if we have anything
		if(dwSize > 0)
		{
			if (SetFilePointer(hFile, 0, NULL, FILE_END) == NO_FILE)
			{
				//Alert(_T("UNABLE-TO-SET-FILEPOINTER-ERROR_vbLog"));
				return 0;
			}
		}
	}
	//No file?
	if(hFile == INVALID_HANDLE_VALUE)
		return 0;
	
	//How much to write
	DWORD dwHeader  = lstrlen(szHeader);
	DWORD dwWrite = lstrlen(szData);
	DWORD dwWritten = DW_ZERO;

	DWORD dwCrLf = lstrlen(vbCrLf);
	const LPCTSTR vbCrLf1 = _T("\r\n\r\n");
	DWORD dwCrLf1 = lstrlen(vbCrLf1);

	//Write to file
	if (dwWrite > DW_ZERO)
	{
		WriteFile(hFile, szHeader, dwHeader, &dwWritten, NULL); //Print header
		WriteFile(hFile, vbCrLf, dwCrLf, &dwWritten, NULL);     //Print a \r\n
		WriteFile(hFile, szData, dwWrite, &dwWritten, NULL);    //Print data
		WriteFile(hFile, vbCrLf1, dwCrLf1, &dwWritten, NULL);   //print \n\r\n\r
	}
	CloseHandle(hFile);
	hFile = INVALID_HANDLE_VALUE;
	dwWrite = DW_ZERO;
	dwWritten = DW_ZERO;
	dwCrLf = DW_ZERO;
	dwCrLf1 = DW_ZERO;
	return (int)dwWritten;
}

int vbLogBSTR(BSTR szData,LPCTSTR szHeader, LPCTSTR szFileName)
{
	if(szData == NULL) return 0;
	USES_CONVERSION;
	return vbLog(OLE2T(szData),szHeader,szFileName);
}

//Call ClearBSTRPtr(*pURL);
void ClearBSTRPtr(BSTR& bstrText)
{
	if (bstrText != NULL)
	{
		::SysFreeString(bstrText);
		bstrText = NULL;
	}
}

PBITMAPINFO CreateBitmapInfoStruct(HWND hwnd, HBITMAP hBmp)
{ 
    BITMAP bmp; 
    PBITMAPINFO pbmi = NULL; 
    WORD    cClrBits; 

    // Retrieve the bitmap color format, width, and height. 
    if (!GetObject(hBmp, sizeof(BITMAP), (LPSTR)&bmp)) 
        return pbmi;
		//errhandler("GetObject", hwnd); 

    // Convert the color format to a count of bits. 
    cClrBits = (WORD)(bmp.bmPlanes * bmp.bmBitsPixel); 
    if (cClrBits == 1) 
        cClrBits = 1; 
    else if (cClrBits <= 4) 
        cClrBits = 4; 
    else if (cClrBits <= 8) 
        cClrBits = 8; 
    else if (cClrBits <= 16) 
        cClrBits = 16; 
    else if (cClrBits <= 24) 
        cClrBits = 24; 
    else cClrBits = 32; 

    // Allocate memory for the BITMAPINFO structure. (This structure 
    // contains a BITMAPINFOHEADER structure and an array of RGBQUAD 
    // data structures.) 

     if (cClrBits != 24) 
         pbmi = (PBITMAPINFO) LocalAlloc(LPTR, 
                    sizeof(BITMAPINFOHEADER) + 
                    sizeof(RGBQUAD) * (1<< cClrBits)); 

     // There is no RGBQUAD array for the 24-bit-per-pixel format. 

     else 
         pbmi = (PBITMAPINFO) LocalAlloc(LPTR, 
                    sizeof(BITMAPINFOHEADER)); 

    // Initialize the fields in the BITMAPINFO structure. 

    pbmi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER); 
    pbmi->bmiHeader.biWidth = bmp.bmWidth; 
    pbmi->bmiHeader.biHeight = bmp.bmHeight; 
    pbmi->bmiHeader.biPlanes = bmp.bmPlanes; 
    pbmi->bmiHeader.biBitCount = bmp.bmBitsPixel; 
    if (cClrBits < 24) 
        pbmi->bmiHeader.biClrUsed = (1<<cClrBits); 

    // If the bitmap is not compressed, set the BI_RGB flag. 
    pbmi->bmiHeader.biCompression = BI_RGB; 

    // Compute the number of bytes in the array of color 
    // indices and store the result in biSizeImage. 
    // For Windows NT, the width must be DWORD aligned unless 
    // the bitmap is RLE compressed. This example shows this. 
    // For Windows 95/98/Me, the width must be WORD aligned unless the 
    // bitmap is RLE compressed.
    pbmi->bmiHeader.biSizeImage = ((pbmi->bmiHeader.biWidth * cClrBits +31) & ~31) /8
                                  * pbmi->bmiHeader.biHeight;
	/*
					biSizeImage = (((pbmi->bmiHeader.biWidth * cClrBits) + 31) & ~31) >>3 
								  * pbmi->bmiHeader.biHeight;
	*/
    // Set biClrImportant to 0, indicating that all of the 
    // device colors are important. 
     pbmi->bmiHeader.biClrImportant = 0; 
     return pbmi; 
} 

BOOL CreateBMPFile(HWND hwnd, LPTSTR pszFile, PBITMAPINFO pbi, HBITMAP hBMP, HDC hDC)
{
	HANDLE hf;                 // file handle 
    BITMAPFILEHEADER hdr;       // bitmap file-header 
    PBITMAPINFOHEADER pbih;     // bitmap info-header 
    LPBYTE lpBits;              // memory pointer 
    DWORD dwTotal;              // total count of bytes 
    DWORD cb;                   // incremental count of bytes 
    BYTE *hp;                   // byte pointer 
    DWORD dwTmp; 

    pbih = (PBITMAPINFOHEADER) pbi; 
    lpBits = (LPBYTE) GlobalAlloc(GMEM_FIXED, pbih->biSizeImage);

    if (!lpBits) 
         return FALSE;

    // Retrieve the color table (RGBQUAD array) and the bits 
    // (array of palette indices) from the DIB. 
    if (!GetDIBits(hDC, hBMP, 0, (WORD) pbih->biHeight, lpBits, pbi, 
        DIB_RGB_COLORS)) 
    {
        goto BMPERROR;
    }

    // Create the .BMP file. 
    hf = CreateFile(pszFile, 
                   GENERIC_READ | GENERIC_WRITE, 
                   (DWORD) 0, 
                    NULL, 
                   CREATE_ALWAYS, 
                   FILE_ATTRIBUTE_NORMAL, 
                   (HANDLE) NULL); 
    if (hf == INVALID_HANDLE_VALUE) 
        goto BMPERROR;
	
    hdr.bfType = 0x4d42;        // 0x42 = "B" 0x4d = "M" 
    // Compute the size of the entire file. 
    hdr.bfSize = (DWORD) (sizeof(BITMAPFILEHEADER) + 
                 pbih->biSize + pbih->biClrUsed 
                 * sizeof(RGBQUAD) + pbih->biSizeImage); 
    hdr.bfReserved1 = 0; 
    hdr.bfReserved2 = 0; 

    // Compute the offset to the array of color indices. 
    hdr.bfOffBits = (DWORD) sizeof(BITMAPFILEHEADER) + 
                    pbih->biSize + pbih->biClrUsed 
                    * sizeof (RGBQUAD); 

    // Copy the BITMAPFILEHEADER into the .BMP file. 
    if (!WriteFile(hf, (LPVOID) &hdr, sizeof(BITMAPFILEHEADER), 
        (LPDWORD) &dwTmp,  NULL)) 
    {
		goto BMPERROR;
    }

    // Copy the BITMAPINFOHEADER and RGBQUAD array into the file. 
    if (!WriteFile(hf, (LPVOID) pbih, sizeof(BITMAPINFOHEADER) 
                  + pbih->biClrUsed * sizeof (RGBQUAD), 
                  (LPDWORD) &dwTmp, ( NULL)) ) 
        goto BMPERROR;

    // Copy the array of color indices into the .BMP file. 
    dwTotal = cb = pbih->biSizeImage; 
    hp = lpBits; 
    if (!WriteFile(hf, (LPSTR) hp, (int) cb, (LPDWORD) &dwTmp,NULL)) 
           goto BMPERROR; 

    // Close the .BMP file. 
     if (!CloseHandle(hf)) 
           goto BMPERROR; 

    // Free memory. 
    GlobalFree((HGLOBAL)lpBits);

	return TRUE;
BMPERROR:
	if(lpBits)
		GlobalFree((HGLOBAL)lpBits);
	return FALSE;
}

HBITMAP CaptureDesktop()
{
    HWND hWnd = NULL;

    hWnd = GetDesktopWindow();          // Get handle to desktop window.

    return CaptureWindow(hWnd, FALSE);  // Capture an image of this window.
}

HBITMAP CaptureForegroundWindow(BOOL bClientAreaOnly)
{
    HWND hWnd = NULL;

    hWnd = ::GetForegroundWindow();             // Get the foreground window.

    return CaptureWindow(hWnd, bClientAreaOnly);// Capture an image of this window.
}

HBITMAP CaptureWindow(HWND hWnd, BOOL bClientAreaOnly)
{
    if(!hWnd)
        return NULL;

    HDC hdc;
    RECT rect;
    if(bClientAreaOnly)
    {
        hdc = GetDC(hWnd);
        GetClientRect(hWnd, &rect);
    }
    else
    {
        hdc = GetWindowDC(hWnd);
        GetWindowRect(hWnd, &rect);
    }

    if(!hdc)
        return NULL;

    HDC hMemDC = CreateCompatibleDC(hdc);
    if(hMemDC == NULL)
        return NULL;

    SIZE size;
    size.cx = rect.right - rect.left;
    if(rect.right < rect.left)
        size.cx = -size.cx;
    size.cy = rect.bottom - rect.top;
    if(rect.bottom < rect.top)
        size.cy = -size.cy;

    HBITMAP hDDBmp = CreateCompatibleBitmap(hdc, size.cx, size.cy);
    if(hDDBmp == NULL)
    {
        DeleteDC(hMemDC);
        ReleaseDC(hWnd, hdc);
        return NULL;
    }

    HBITMAP hOldBmp = static_cast<HBITMAP>(SelectObject(hMemDC, hDDBmp));
    BitBlt(hMemDC, 0, 0, size.cx, size.cy, hdc, 0, 0, SRCCOPY);
    SelectObject(hMemDC, hOldBmp);
    DeleteDC(hMemDC);
    ReleaseDC(hWnd, hdc);

    HBITMAP hBmp = static_cast<HBITMAP>(CopyImage(hDDBmp,
                                                    IMAGE_BITMAP,
                                                    0,
                                                    0,
                                                    LR_CREATEDIBSECTION));

    DeleteObject(hDDBmp);

    return hBmp;
}

/*Sample usage

TCHAR *ppString[3] = 
{
  "Hey diddle diddle...",
  "The cat and the fiddle...",
  "The cow jumps over the moon..."
};


long MemoryStringTest_Function()
{
  LPTSTR pszString = NULL;
  ULONG ulSizeRequired = 0;
  ULONG ulCount = 0;
  int i = 0;
  LPSTREAM lpStream = NULL;

  CreateStreamOnHGlobal(NULL, TRUE, &lpStream);

  StreamStringCopy ((LPSTREAM)lpStream, (LPCTSTR)"");

  for (i = 0; i < 3; i++)
  {
	StreamStringCat ((LPSTREAM)lpStream, ppString[i]);
  }

  StreamStringRead ((LPSTREAM)lpStream, (LPTSTR)NULL, (ULONG*)&ulSizeRequired);

  pszString = (LPTSTR)malloc(ulSizeRequired + sizeof(char));

  if (pszString)
  {
	StreamStringRead ((LPSTREAM)lpStream, (LPTSTR)pszString, (ULONG*)NULL);
	free (pszString);
	pszString = NULL;
  }

  StreamStringCopy ((LPSTREAM)lpStream, (LPCTSTR)"The dish ran away with the spoon.");

  StreamStringRead ((LPSTREAM)lpStream, (LPTSTR)NULL, (ULONG*)&ulSizeRequired);

  pszString = (LPTSTR)malloc(ulSizeRequired + sizeof(char));
  if (pszString)
  {
	StreamStringRead ((LPSTREAM)lpStream, (LPTSTR)pszString, (ULONG*)NULL);
	free (pszString);
	pszString = NULL;
  }

  if (lpStream)
  {
    lpStream -> Release();
	lpStream = NULL;
  }

  return 0;
}
*/

HRESULT StreamResetPointer (LPSTREAM lpStream)
{
  LARGE_INTEGER liBeggining = { 0 };
  HRESULT hrRet = S_OK;

  hrRet = lpStream -> Seek(liBeggining, STREAM_SEEK_SET, NULL);

  return hrRet;
}

HRESULT StreamStringSize(LPSTREAM lpStream, ULONG* lpulSize)
{
  LARGE_INTEGER liBeggining = { 0 };
  STATSTG statstg;
  HRESULT hrRetTemp = S_OK;
  HRESULT hrRet = S_OK;
  
  hrRetTemp = lpStream->Seek(liBeggining, STREAM_SEEK_SET, NULL);
  //
  //hrRetTemp = StreamResetPointer ((LPSTREAM)lpStream);
  if (hrRetTemp != S_OK)
  {
    hrRet = hrRetTemp;
    goto StreamStringSize_0;
  }

  memset (&statstg, 0, sizeof(statstg));
  hrRetTemp = lpStream -> Stat(&statstg, STATFLAG_NONAME);
  if (hrRetTemp != S_OK)
  {
    hrRet = hrRetTemp;
	goto StreamStringSize_0;
  }

  if ((ULONG*)lpulSize)
  {
    *((ULONG*)lpulSize) = statstg.cbSize.LowPart;
  }

StreamStringSize_0:

  return hrRet;
}

HRESULT StreamStringCopy (LPSTREAM lpStream, LPCTSTR lpString)
{
  ULONG ulBytesWritten = 0;
  ULONG ulSize = 0;
  ULARGE_INTEGER uliSize = { 0 };
  HRESULT hrRetTemp = S_OK;
  HRESULT hrRet = S_OK;

  hrRetTemp = StreamResetPointer ((LPSTREAM)lpStream);
  if (hrRetTemp != S_OK)
  {
    hrRet = hrRetTemp;
	goto StreamStringCopy_0;
  }

  hrRetTemp = lpStream -> SetSize (uliSize);
  if (hrRetTemp != S_OK)
  {
    hrRetTemp = hrRet;
	goto StreamStringCopy_0;
  }

  ulSize = (ULONG)_tcslen(lpString);
  
  hrRetTemp = lpStream -> Write((void const*)lpString, (ULONG)ulSize, (ULONG*)&ulBytesWritten);
  if (hrRetTemp != S_OK)
  {
    hrRet = hrRetTemp;
	goto StreamStringCopy_0;
  }

  if (ulSize == ulBytesWritten)
  {
    hrRet = S_OK;
  }
  else
  {
    hrRet = S_FALSE;
  }

StreamStringCopy_0:

  return hrRet;
}

HRESULT StreamStringCat (LPSTREAM lpStream, LPCTSTR lpString)
{
  ULONG ulBytesWritten = 0;
  ULONG ulSize = 0;
  HRESULT hrRetTemp = S_OK;
  HRESULT hrRet = S_OK;

  ulSize = (ULONG)_tcslen(lpString);
  
  hrRetTemp = lpStream -> Write((void const*)lpString, (ULONG)ulSize, (ULONG*)&ulBytesWritten);
  if (hrRetTemp != S_OK)
  {
    hrRet = hrRetTemp;
	goto StreamStringCat_0;
  }

  if (ulSize == ulBytesWritten)
  {
    hrRet = S_OK;
  }
  else
  {
    hrRet = S_FALSE;
  }

StreamStringCat_0:

  return hrRet;
}

HRESULT StreamStringRead (LPSTREAM lpStream, LPTSTR lpszReceiver, ULONG* lpulSizeReceiver)
{
  STATSTG statstg;
  HRESULT hrRetTemp = S_OK;
  HRESULT hrRet = S_OK;

  hrRetTemp = StreamResetPointer ((LPSTREAM)lpStream);
  if (hrRetTemp != S_OK)
  {
    hrRet = hrRetTemp;
    goto StreamStringRead_0;
  }

  memset (&statstg, 0, sizeof(statstg));
  hrRetTemp = lpStream -> Stat(&statstg, STATFLAG_NONAME);
  if (hrRetTemp != S_OK)
  {
    hrRet = hrRetTemp;
	goto StreamStringRead_0;
  }

  if ((ULONG*)lpulSizeReceiver)
  {
    *((ULONG*)lpulSizeReceiver) = statstg.cbSize.LowPart;
  }

  if ((void*)lpszReceiver)
  {
    memset ((void*)lpszReceiver, 0, statstg.cbSize.LowPart + sizeof(char));
    lpStream -> Read((void*)lpszReceiver, statstg.cbSize.LowPart, NULL);
  }

StreamStringRead_0:

  return hrRet;
}

HRESULT StreamStringRead2 (LPSTREAM lpStream, LPTSTR lpszReceiver, ULONG ulSizeReceiver)
{
  HRESULT hrRet = S_OK;

  if ((void*)lpszReceiver)
  {
    memset ((void*)lpszReceiver, 0, ulSizeReceiver + sizeof(char));
    hrRet = lpStream->Read((void*)lpszReceiver, ulSizeReceiver, NULL);
  }
  return hrRet;
}

// Replaces MIME encoded strings
// "%20" --> " "
// "%FC" --> "ü"
// "%25" --> "%"     etc....
LPCTSTR DecodeHtml(LPCTSTR s_In)
{
	UINT len = _tcslen(s_In);
	CTmpBuffer s_Out(len);
	TCHAR *pt_Out = (TCHAR*) s_Out.GetString();
	TCHAR *pt_In  = (TCHAR*) s_In;

	const UINT u_0 = 48;
	const UINT u_9 = 57;
	const UINT u_a = 97;
	const UINT u_A = 65;
	const UINT u_f = 102;
	const UINT u_F = 70;

	int O=0;
	for (UINT I=0; I<len; I++)
	{
		TCHAR t_Chr = pt_In[I];

		if (t_Chr == _T('%')) 
		{
			UINT u32_Hex = 0;

			// convert hexadecimal string into UINT ("FA" --> 0xFA)
			for (UINT D=1; D<=2; D++)
			{
				UINT u32_Digit = (UINT) pt_In[I+D];

					 if (u32_Digit >= u_0 && u32_Digit <= u_9) u32_Digit -=  u_0;
				else if (u32_Digit >= u_A && u32_Digit <= u_F) u32_Digit -= (u_A - 10);
				else if (u32_Digit >= u_a && u32_Digit <= u_f) u32_Digit -= (u_a - 10);
				else break;

//					 if (u32_Digit >= (UINT)'0' && u32_Digit <= (UINT)'9') u32_Digit -=  (UINT) '0';
//				else if (u32_Digit >= (UINT)'A' && u32_Digit <= (UINT)'F') u32_Digit -= ((UINT) 'A' -10);
//				else if (u32_Digit >= (UINT)'a' && u32_Digit <= (UINT)'f') u32_Digit -= ((UINT) 'a' -10);
//				else break;

				u32_Hex = u32_Hex * 16 + u32_Digit;

				if (D == 2) // second hex digit
				{
					t_Chr = (TCHAR) u32_Hex;
					I += 2; // skip two hex digits
				}
			}
		}

		pt_Out[O++] = t_Chr;
	}

	s_Out.ReleaseString();
	return s_Out;
}

/*
Delete methods have been taken from article By Marcel Lambert.
	http://www.codeproject.com/system/Cleanup_API.asp
	Thank you
*/
HRESULT Delete_IECookies(BOOL bDeleteCookies, BOOL bDeleteCookiesIndex)
{
	TCHAR szUserProfile[MAX_PATH*2]; 
	TCHAR szFilePath[MAX_PATH*2];
	HANDLE hCacheEnumHandle  = NULL;
	LPINTERNET_CACHE_ENTRY_INFO lpCacheEntry = NULL;
	DWORD  dwSize = 4096; // initial buffer size

	// Delete index.dat if requested. Be sure that index.dat is not locked.
	if(bDeleteCookiesIndex)
	{
		// Retrieve from environment user profile path.
		DWORD bufCharCount = ExpandEnvironmentStrings(_T("%userprofile%"), szUserProfile, 
														 sizeof(szUserProfile)); 
		//Was buffer large enough?
		//if(bufCharCount < MAX_PATH*2)
        wsprintf(szFilePath, _T("%s%s"), szUserProfile, _T("\\Cookies\\index.dat"));
		DeleteFile(szFilePath);

		if(!bDeleteCookies) return S_OK;
	}
	
	// Enable initial buffer size for cache entry structure.
	lpCacheEntry = (LPINTERNET_CACHE_ENTRY_INFO) new char[dwSize];
    lpCacheEntry->dwStructSize = dwSize;
	
	// URL search pattern (1st parameter) options are:  "cookie:", "visited:", 
	// or NULL ("*.*").
	hCacheEnumHandle = FindFirstUrlCacheEntry(_T("cookie:") /* in */, 
		                         lpCacheEntry /* out */, &dwSize /* in, out */);
	
	// First, obtain handle to internet cache with FindFirstUrlCacheEntry
	// for late use with FindNextUrlCacheEntry.
	
	if(hCacheEnumHandle != NULL) 
	{
        DeleteUrlCacheEntry(lpCacheEntry->lpszSourceUrlName);
	}
	else
	{
        switch(GetLastError())
		{
            case ERROR_INSUFFICIENT_BUFFER:
			    lpCacheEntry = (LPINTERNET_CACHE_ENTRY_INFO) new char[dwSize];
			    lpCacheEntry->dwStructSize = dwSize;

			    // Repeat first step search with adjusted buffer, exit if not
				// found again (in practice one buffer's size adustment is  
				// always OK).
				hCacheEnumHandle = FindFirstUrlCacheEntry(NULL, lpCacheEntry, 
					                                                   &dwSize);
				if(hCacheEnumHandle != NULL) 
				{
					DeleteUrlCacheEntry(lpCacheEntry->lpszSourceUrlName);
					break;        
				}
				else
				{
					// FindFirstUrlCacheEntry fails again, return.
					return S_FALSE; 
				}
			default:
				FindCloseUrlCache(hCacheEnumHandle);
				return S_FALSE;
		}
	}
	
	// Next, use hCacheEnumHandle obtained from the previous step to delete 
	// subsequent items of cache.

	do 
	{
	     // Notice that return values of FindNextUrlCacheEntry (BOOL) and 
		 // FindFirstUrlCacheEntry (HANDLE) are different.

		 if(FindNextUrlCacheEntry(hCacheEnumHandle, lpCacheEntry, &dwSize))
		 {
		     DeleteUrlCacheEntry(lpCacheEntry->lpszSourceUrlName);
		 }
		 else
		 {
			 switch(GetLastError())
			 {
                 case ERROR_INSUFFICIENT_BUFFER:
					lpCacheEntry = (LPINTERNET_CACHE_ENTRY_INFO) 
						                                       new char[dwSize];
					lpCacheEntry->dwStructSize = dwSize;

					// Repeat next step search with adjusted buffer, exit if 
					// error comes up again ((in practice one buffer's size 
					// adustment is always OK).

					if(FindNextUrlCacheEntry(hCacheEnumHandle, lpCacheEntry, 
						                                               &dwSize)) 
					{
						DeleteUrlCacheEntry(lpCacheEntry->lpszSourceUrlName);
						break;          
					}
					else
					{
						// FindFirstUrlCacheEntry fails again, return.
						FindCloseUrlCache(hCacheEnumHandle);
						return S_FALSE; 
					}
				    break;
			     case ERROR_NO_MORE_ITEMS:
					 FindCloseUrlCache(hCacheEnumHandle);
					 return S_OK; 
				 default:
					 FindCloseUrlCache(hCacheEnumHandle);
					 return S_FALSE;
			 }
		 } 
	} while (TRUE);

    return S_FALSE; // never here
}

HRESULT Delete_IECache(BOOL bDeleteCache, BOOL bDeleteCacheIndex)
{
	TCHAR szUserProfile[MAX_PATH*2]; 
	TCHAR szFilePath[MAX_PATH*2];
	HANDLE hCacheEnumHandle  = NULL;
	LPINTERNET_CACHE_ENTRY_INFO lpCacheEntry = NULL;
	DWORD  dwSize = 4096; // initial buffer size

	// Delete index.dat if requested. Be sure that index.dat is not locked.
	if(bDeleteCacheIndex)
	{
		// Retrieve from environment user profile path.
		ExpandEnvironmentStrings(_T("%userprofile%"), szUserProfile, 
														 sizeof(szUserProfile)); 
		wsprintf(szFilePath, _T("%s%s"), szUserProfile, 
		  _T("\\Local Settings\\Temporary Internet Files\\Content.IE5\\index.dat"));

		DeleteFile(szFilePath);

		if(!bDeleteCache) return S_OK;
	}

	// Enable initial buffer size for cache entry structure.
	lpCacheEntry = (LPINTERNET_CACHE_ENTRY_INFO) new char[dwSize];
    lpCacheEntry->dwStructSize = dwSize;
	
	// URL search pattern (1st parameter) options are:  NULL ("*.*"), "cookie:", 
	// or "visited:".
	hCacheEnumHandle = FindFirstUrlCacheEntry(NULL /* in */, 
		                         lpCacheEntry /* out */, &dwSize /* in, out */);
	
	// First, obtain handle to internet cache with FindFirstUrlCacheEntry
	// for later use with FindNextUrlCacheEntry.
	if(hCacheEnumHandle != NULL) 
	{
		// When cache entry is not a cookie, delete entry. 
		if (!(lpCacheEntry->CacheEntryType & COOKIE_CACHE_ENTRY))
		{
		    DeleteUrlCacheEntry(lpCacheEntry->lpszSourceUrlName);
		}
	}
	else
	{
        switch(GetLastError())
		{
            case ERROR_INSUFFICIENT_BUFFER:
			    lpCacheEntry = (LPINTERNET_CACHE_ENTRY_INFO) new char[dwSize];
			    lpCacheEntry->dwStructSize = dwSize;

			    // Repeat first step search with adjusted buffer, exit if not
				// found again (in practice one buffer's size adustment is  
				// always OK).
				hCacheEnumHandle = FindFirstUrlCacheEntry(NULL, lpCacheEntry, 
					                                                   &dwSize);
				if(hCacheEnumHandle != NULL) 
				{
				    // When cache entry is not a cookie, delete entry. 
					if (!(lpCacheEntry->CacheEntryType & COOKIE_CACHE_ENTRY))
					{
						DeleteUrlCacheEntry(lpCacheEntry->lpszSourceUrlName);
					}
					break;        
				}
				else
				{
					// FindFirstUrlCacheEntry fails again, return.
					return S_FALSE; 
				}
			default:
				FindCloseUrlCache(hCacheEnumHandle);
				return S_FALSE;
		}
	}
	
	// Next, use hCacheEnumHandle obtained from the previous step to delete 
	// subsequent items of the cache.
	do 
	{
	     // Notice that return values of FindNextUrlCacheEntry (BOOL) and 
		 // FindFirstUrlCacheEntry (HANDLE) are different.
		 if(FindNextUrlCacheEntry(hCacheEnumHandle, lpCacheEntry, &dwSize))
		 {
		     // When cache entry is not a cookie, delete entry. 
		     if (!(lpCacheEntry->CacheEntryType & COOKIE_CACHE_ENTRY))
		     {
			     DeleteUrlCacheEntry(lpCacheEntry->lpszSourceUrlName);
		     }
		 }
		 else
		 {
			 switch(GetLastError())
			 {
                 case ERROR_INSUFFICIENT_BUFFER:
					lpCacheEntry = (LPINTERNET_CACHE_ENTRY_INFO) 
						                                       new char[dwSize];
					lpCacheEntry->dwStructSize = dwSize;

					// Repeat next step search with adjusted buffer, exit if 
					// error comes up again ((in practice one buffer's size 
					// adustment is always OK).
					if(FindNextUrlCacheEntry(hCacheEnumHandle, lpCacheEntry, 
						                                               &dwSize)) 
					{
					    // When cache entry is not a cookie, delete entry. 
						if (!(lpCacheEntry->CacheEntryType & COOKIE_CACHE_ENTRY))
						{
							DeleteUrlCacheEntry(lpCacheEntry->lpszSourceUrlName);
						}
						break;          
					}
					else
					{
						// FindFirstUrlCacheEntry fails again, return.
						FindCloseUrlCache(hCacheEnumHandle);
						return S_FALSE; 
					}
				    break;
			     case ERROR_NO_MORE_ITEMS:
					 FindCloseUrlCache(hCacheEnumHandle);
					 return S_OK; 
				 default:
					 FindCloseUrlCache(hCacheEnumHandle);
					 return S_FALSE;
			 }
		 } 
	} while (TRUE);

    return S_FALSE; // never here
}

HRESULT Delete_IEHistory(BOOL bDeleteHistory, BOOL bDeleteHistoryIndex)
{
	TCHAR szUserProfile[MAX_PATH*2]; 
    TCHAR szFilePath[MAX_PATH*2];
	HRESULT hr;
	IUrlHistoryStg2* pUrlHistoryStg2 = NULL;

    // Delete index.dat if requested. Be sure that index.dat is not locked. 
	if(bDeleteHistoryIndex)
	{
		// Retrieve from environment user profile path.
		ExpandEnvironmentStrings(_T("%userprofile%"), szUserProfile, 
														 sizeof(szUserProfile)); 
		wsprintf(szFilePath, _T("%s%s"), szUserProfile, 
		                   _T("\\Local Settings\\History\\History.IE5\\index.dat"));
		DeleteFile(szFilePath);

		if (!bDeleteHistory) return S_OK;
	}
	
    hr = CoCreateInstance(CLSID_CUrlHistory, NULL, CLSCTX_INPROC, 
		                         IID_IUrlHistoryStg2, (void**)&pUrlHistoryStg2);
    if( (SUCCEEDED(hr)) && (pUrlHistoryStg2) )
    {
		hr = pUrlHistoryStg2->ClearHistory();
        pUrlHistoryStg2->Release();
    }

	return hr;
}

HRESULT Delete_IEAddressBarTypedURLs(void)
{
    HKEY hKey;
	DWORD dwResult;
	TCHAR szValueName[10];

	// Open TypedURLs key.
	dwResult = RegOpenKey(HKEY_CURRENT_USER,
		            _T("Software\\Microsoft\\Internet Explorer\\TypedURLs"), &hKey);

	int i = 1; wsprintf(szValueName, _T("url%d"), i); 

	while(RegDeleteValue(hKey, szValueName) == ERROR_SUCCESS) 
	{
		i++; wsprintf(szValueName, _T("url%d"), i);
	}

	RegCloseKey(hKey); 

	return S_OK;
}

// Note: actually, effect of running Delete_DesktopRunHistory is 
// visible after reboot. 

HRESULT Delete_DesktopRunMRU(void)
{
	HKEY hKey;
	DWORD dwResult;
	TCHAR* pszIndex = _T("abcdefghijklmnopqrstuvwxyz");
	TCHAR szBuffer[2];    // character plus terminating NULL-character
	TCHAR szValueName[2]; // registry value name
	int i;

	// Open RunMRU key.
	dwResult = RegOpenKey(HKEY_CURRENT_USER,
        _T("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU"), 
		                                                                &hKey );
	// Traverse all possible values and delete. This guarantees deletion
    // even if the sequence is broken.
	for(i = 0; i < 26 /* z */; i++)
	{
	    szBuffer[0] = *pszIndex;
		szBuffer[1] = _T('\0');
		lstrcpy(szValueName, szBuffer);
		RegDeleteValue(hKey, szValueName); pszIndex++;
    }

	RegDeleteValue(hKey, _T("MRUList"));
	
	RegCloseKey(hKey); 

	return S_OK;
}

HRESULT Delete_DesktopRecentDocsHistory(void)
{
	SHAddToRecentDocs(SHARD_PATH, NULL /* NULL clears history */);
	return S_OK;
}

/*
struct tagVARIANT
    {
    union 
        {
        struct __tagVARIANT
            {
            VARTYPE vt;
            WORD wReserved1;
            WORD wReserved2;
            WORD wReserved3;
            union 
                {
                LONGLONG llVal;
                LONG lVal;
                BYTE bVal;
                SHORT iVal;
                FLOAT fltVal;
                DOUBLE dblVal;
                VARIANT_BOOL boolVal;
                _VARIANT_BOOL bool;
                SCODE scode;
                CY cyVal;
                DATE date;
                BSTR bstrVal;
                IUnknown *punkVal;
                IDispatch *pdispVal;
                SAFEARRAY *parray;
                BYTE *pbVal;
                SHORT *piVal;
                LONG *plVal;
                LONGLONG *pllVal;
                FLOAT *pfltVal;
                DOUBLE *pdblVal;
                VARIANT_BOOL *pboolVal;
                _VARIANT_BOOL *pbool;
                SCODE *pscode;
                CY *pcyVal;
                DATE *pdate;
                BSTR *pbstrVal;
                IUnknown **ppunkVal;
                IDispatch **ppdispVal;
                SAFEARRAY **pparray;
                VARIANT *pvarVal;
                PVOID byref;
                CHAR cVal;
                USHORT uiVal;
                ULONG ulVal;
                ULONGLONG ullVal;
                INT intVal;
                UINT uintVal;
                DECIMAL *pdecVal;
                CHAR *pcVal;
                USHORT *puiVal;
                ULONG *pulVal;
                ULONGLONG *pullVal;
                INT *pintVal;
                UINT *puintVal;
                struct __tagBRECORD
                    {
                    PVOID pvRecord;
                    IRecordInfo *pRecInfo;
                    } 	__VARIANT_NAME_4;
                } 	__VARIANT_NAME_3;
            } 	__VARIANT_NAME_2;
        DECIMAL decVal;
        }
*/

/* VARIANT STRUCTURE
 *
 *  VARTYPE vt;
 *  WORD wReserved1;
 *  WORD wReserved2;
 *  WORD wReserved3;
 *  union {
 *    LONG           VT_I4
 *    BYTE           VT_UI1
 *    SHORT          VT_I2
 *    FLOAT          VT_R4
 *    DOUBLE         VT_R8
 *    VARIANT_BOOL   VT_BOOL
 *    SCODE          VT_ERROR
 *    CY             VT_CY
 *    DATE           VT_DATE
 *    BSTR           VT_BSTR
 *    IUnknown *     VT_UNKNOWN
 *    IDispatch *    VT_DISPATCH
 *    SAFEARRAY *    VT_ARRAY
 *    BYTE *         VT_BYREF|VT_UI1
 *    SHORT *        VT_BYREF|VT_I2
 *    LONG *         VT_BYREF|VT_I4
 *    FLOAT *        VT_BYREF|VT_R4
 *    DOUBLE *       VT_BYREF|VT_R8
 *    VARIANT_BOOL * VT_BYREF|VT_BOOL
 *    SCODE *        VT_BYREF|VT_ERROR
 *    CY *           VT_BYREF|VT_CY
 *    DATE *         VT_BYREF|VT_DATE
 *    BSTR *         VT_BYREF|VT_BSTR
 *    IUnknown **    VT_BYREF|VT_UNKNOWN
 *    IDispatch **   VT_BYREF|VT_DISPATCH
 *    SAFEARRAY **   VT_BYREF|VT_ARRAY
 *    VARIANT *      VT_BYREF|VT_VARIANT
 *    PVOID          VT_BYREF (Generic ByRef)
 *    CHAR           VT_I1
 *    USHORT         VT_UI2
 *    ULONG          VT_UI4
 *    INT            VT_INT
 *    UINT           VT_UINT
 *    DECIMAL *      VT_BYREF|VT_DECIMAL
 *    CHAR *         VT_BYREF|VT_I1
 *    USHORT *       VT_BYREF|VT_UI2
 *    ULONG *        VT_BYREF|VT_UI4
 *    INT *          VT_BYREF|VT_INT
 *    UINT *         VT_BYREF|VT_UINT
 *  }
 */


//typedef unsigned short VARTYPE;

/*
 * VARENUM usage key,
 *
 * * [V] - may appear in a VARIANT
 * * [T] - may appear in a TYPEDESC
 * * [P] - may appear in an OLE property set
 * * [S] - may appear in a Safe Array
 *
 *
 *  VT_EMPTY            [V]   [P]     nothing
 *  VT_NULL             [V]   [P]     SQL style Null
 *  VT_I2               [V][T][P][S]  2 byte signed int
 *  VT_I4               [V][T][P][S]  4 byte signed int
 *  VT_R4               [V][T][P][S]  4 byte real
 *  VT_R8               [V][T][P][S]  8 byte real
 *  VT_CY               [V][T][P][S]  currency
 *  VT_DATE             [V][T][P][S]  date
 *  VT_BSTR             [V][T][P][S]  OLE Automation string
 *  VT_DISPATCH         [V][T]   [S]  IDispatch *
 *  VT_ERROR            [V][T][P][S]  SCODE
 *  VT_BOOL             [V][T][P][S]  True=-1, False=0
 *  VT_VARIANT          [V][T][P][S]  VARIANT *
 *  VT_UNKNOWN          [V][T]   [S]  IUnknown *
 *  VT_DECIMAL          [V][T]   [S]  16 byte fixed point
 *  VT_RECORD           [V]   [P][S]  user defined type
 *  VT_I1               [V][T][P][s]  signed char
 *  VT_UI1              [V][T][P][S]  unsigned char
 *  VT_UI2              [V][T][P][S]  unsigned short
 *  VT_UI4              [V][T][P][S]  unsigned long
 *  VT_I8                  [T][P]     signed 64-bit int
 *  VT_UI8                 [T][P]     unsigned 64-bit int
 *  VT_INT              [V][T][P][S]  signed machine int
 *  VT_UINT             [V][T]   [S]  unsigned machine int
 *  VT_INT_PTR             [T]        signed machine register size width
 *  VT_UINT_PTR            [T]        unsigned machine register size width
 *  VT_VOID                [T]        C style void
 *  VT_HRESULT             [T]        Standard return type
 *  VT_PTR                 [T]        pointer type
 *  VT_SAFEARRAY           [T]        (use VT_ARRAY in VARIANT)
 *  VT_CARRAY              [T]        C style array
 *  VT_USERDEFINED         [T]        user defined type
 *  VT_LPSTR               [T][P]     null terminated string
 *  VT_LPWSTR              [T][P]     wide null terminated string
 *  VT_FILETIME               [P]     FILETIME
 *  VT_BLOB                   [P]     Length prefixed bytes
 *  VT_STREAM                 [P]     Name of the stream follows
 *  VT_STORAGE                [P]     Name of the storage follows
 *  VT_STREAMED_OBJECT        [P]     Stream contains an object
 *  VT_STORED_OBJECT          [P]     Storage contains an object
 *  VT_VERSIONED_STREAM       [P]     Stream with a GUID version
 *  VT_BLOB_OBJECT            [P]     Blob contains an object 
 *  VT_CF                     [P]     Clipboard format
 *  VT_CLSID                  [P]     A Class ID
 *  VT_VECTOR                 [P]     simple counted array
 *  VT_ARRAY            [V]           SAFEARRAY*
 *  VT_BYREF            [V]           void* for local use
 *  VT_BSTR_BLOB                      Reserved for system use
 */


/*
 * VARENUM usage key,
 *
 * * [V] - may appear in a VARIANT
 * * [T] - may appear in a TYPEDESC
 * * [P] - may appear in an OLE property set
 * * [S] - may appear in a Safe Array
 * * [C] - supported by class _variant_t
 *
 *
 *  VT_EMPTY            [V]   [P]        nothing
 *  VT_NULL             [V]   [P]        SQL style Null
 *  VT_I2               [V][T][P][S][C]  2 byte signed int
 *  VT_I4               [V][T][P][S][C]  4 byte signed int
 *  VT_R4               [V][T][P][S][C]  4 byte real
 *  VT_R8               [V][T][P][S][C]  8 byte real
 *  VT_CY               [V][T][P][S][C]  currency
 *  VT_DATE             [V][T][P][S][C]  date
 *  VT_BSTR             [V][T][P][S][C]  OLE Automation string
 *  VT_DISPATCH         [V][T][P][S][C]  IDispatch *
 *  VT_ERROR            [V][T]   [S][C]  SCODE
 *  VT_BOOL             [V][T][P][S][C]  True=-1, False=0
 *  VT_VARIANT          [V][T][P][S]     VARIANT *
 *  VT_UNKNOWN          [V][T]   [S][C]  IUnknown *
 *  VT_DECIMAL          [V][T]   [S][C]  16 byte fixed point
 *  VT_I1                  [T]           signed char
 *  VT_UI1              [V][T][P][S][C]  unsigned char
 *  VT_UI2                 [T][P]        unsigned short
 *  VT_UI4                 [T][P]        unsigned short
 *  VT_I8                  [T][P]        signed 64-bit int
 *  VT_UI8                 [T][P]        unsigned 64-bit int
 *  VT_INT                 [T]           signed machine int
 *  VT_UINT                [T]           unsigned machine int
 *  VT_VOID                [T]           C style void
 *  VT_HRESULT             [T]           Standard return type
 *  VT_PTR                 [T]           pointer type
 *  VT_SAFEARRAY           [T]          (use VT_ARRAY in VARIANT)
 *  VT_CARRAY              [T]           C style array
 *  VT_USERDEFINED         [T]           user defined type
 *  VT_LPSTR               [T][P]        null terminated string
 *  VT_LPWSTR              [T][P]        wide null terminated string
 *  VT_FILETIME               [P]        FILETIME
 *  VT_BLOB                   [P]        Length prefixed bytes
 *  VT_STREAM                 [P]        Name of the stream follows
 *  VT_STORAGE                [P]        Name of the storage follows
 *  VT_STREAMED_OBJECT        [P]        Stream contains an object
 *  VT_STORED_OBJECT          [P]        Storage contains an object
 *  VT_BLOB_OBJECT            [P]        Blob contains an object
 *  VT_CF                     [P]        Clipboard format
 *  VT_CLSID                  [P]        A Class ID
 *  VT_VECTOR                 [P]        simple counted array
 *  VT_ARRAY            [V]              SAFEARRAY*
 *  VT_BYREF            [V]              void* for local use
 */

/*
#include <atlbase.h>
#include <shlobj.h>
#include <UrlHist.h>
//Deleting history
// Error checking minimized for clarity.
int main(int argc, char* argv[])
{
	USES_CONVERSION;
	CoInitialize(NULL);

	IUrlHistoryStg2* pUrlHistoryStg2 = NULL;
	HRESULT hr = CoCreateInstance(CLSID_CUrlHistory,
		NULL, CLSCTX_INPROC, IID_IUrlHistoryStg2,
		(void**)&pUrlHistoryStg2);
//hr = pUrlHistoryStg2->ClearHistory();
//IUrlHistoryStg::QueryUrl iscached/
	IEnumSTATURL* pEnumURL;
	hr = pUrlHistoryStg2->EnumUrls(&pEnumURL);

	STATURL suURL;
	ULONG pceltFetched;
	suURL.cbSize = sizeof(suURL);
	hr = pEnumURL->Reset();

	while((hr = pEnumURL->Next(1, &suURL, &pceltFetched)) == S_OK)
	{
		hr = pUrlHistoryStg2->DeleteUrl(suURL.pwcsUrl, 0);
		printf("\"%s\" deleted.\n", W2T(suURL.pwcsUrl));
	}

	pEnumURL->Release();
	pUrlHistoryStg2->Release();
	CoUninitialize();
}

// Error checking minimized for clarity.
//Draw back - a confirmation dialog will be displayed
void DeleteUrlFromHistoryShell()
{
	HRESULT hr;

	// Call this if needed.
	CoInitialize( NULL );

	IShellFolder* pDesktopFolder = NULL;
	IMalloc* pMalloc = NULL;

	hr = ::SHGetMalloc(&pMalloc);

	// Get desktop folder.
	hr = ::SHGetDesktopFolder(&pDesktopFolder);

	// Get the history folder.
	ITEMIDLIST* pidlHistoryFolder = NULL;
	hr = ::SHGetSpecialFolderLocation(NULL, CSIDL_HISTORY, &pidlHistoryFolder);

	// Get the IShellFolder of the history folder.
	IShellFolder* pHistoryFolder = NULL;
	hr = pDesktopFolder->BindToObject(pidlHistoryFolder, NULL, IID_IShellFolder, (void**)&pHistoryFolder);

	// Enumerate the history items.
	IEnumIDList* pHistoryEnum = NULL;
	hr = pHistoryFolder->EnumObjects(NULL, SHCONTF_FOLDERS | SHCONTF_NONFOLDERS, &pHistoryEnum);

	ITEMIDLIST* pidl = NULL;
	ULONG fetched = 0;

	hr = pHistoryEnum->Next(1, &pidl, &fetched);

	if (SUCCEEDED(hr))
	{
		const ITEMIDLIST* pidl2 = pidl;

		// Get the IContextMenu interface.
		IContextMenu* pContextMenu = NULL;
		hr = pHistoryFolder->GetUIObjectOf(NULL, 1, &pidl2, IID_IContextMenu, NULL, (void**)&pContextMenu);

		if (SUCCEEDED(hr))
		{
			CMINVOKECOMMANDINFO pCommandInfo = { 0 };

			pCommandInfo.cbSize = sizeof(CMINVOKECOMMANDINFO);
			pCommandInfo.lpVerb = _T("delete");
			pCommandInfo.fMask = CMIC_MASK_FLAG_NO_UI; // has no effect
			hr = pContextMenu->InvokeCommand(&pCommandInfo);
		}

		pContextMenu->Release();
	}

	pHistoryEnum->Release();
	pHistoryFolder->Release();
	pMalloc->Release();
	pDesktopFolder->Release();
}
*/




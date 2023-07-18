
/*
IProtectFocus

*	Author: MH
*	Contact: mehr13@hotmail.com
*	Homepage: http://vbmhwb.sourceforge.net/
*	http://sourceforge.net/projects/vbmhwb/
*
*	Last Modified: Sep 20 2006
*	Current version: 1.2.1.6
*
*	Changes from 1.2.1.5:
*	=====================
*	1)New Interface
*		IHTMLOMWindowServices - IE6 XP sp2
*			Allows applications hosting the WebBrowser Control to intercept the window object
*			calls moveTo, moveBy, resizeTo, and resizeBy for manipulating the host's window 
*			coordinates from Dynamic HTML (DHTML) script. No events have been implemeted yet.
*
*	2)New Functionality
*		Added CAutoCompleter to wrap both shell and custom autocomplete
*			Custom autocomplete uses a client supplied string list and IEnumString iface
*			Use SetupCustomAutoComplete, CustomAutoCompleteAddString, and CustomAutoCompleteEnable
*			methods to setup, add strings, and enable/disable custom autocomplete.
*		Added ability to install 11 different kinds of windows hooks
*		both global and application instance specific:
*			WHT_CALLWNDPROC
*			WHT_CBT
*			WHT_GETMESSAGE
*			WHT_KEYBOARD
*			WHT_MOUSE
*			WHT_MSGFILTER
*			WHT_KEYBOARD_LL
*			WHT_MOUSE_LL
*			WHT_FOREGROUNDIDLE
*			WHT_CALLWNDPROCRET
*			WHT_SYSMSGFILTER
*		The notifications for hooks are send via SendMessageTimeout function.
*		Windows message ids passed from SetupWindowsHook method to calling
*		client for each hook notifications are registered using
*		RegisterWindowMessage method. The result param from SendMessageTimeout is
*		used to determine if a hook call has been cancelled.
*
*	3)New Events:
*		OnWBKeyDown
*			Replacement for OnAcceletorKeys
*		OnWBKeyUp
*			Replacement for OnAcceletorKeys
*		Replaced ShowMessage with DocHostShowMessage,
*			New event passes all the params from DocHostShowUI::ShowMessage method
*		FindAnyTextMatchCallback - fired in response to a call to FindAnyTextMatch
*			Searching for a match continues till stop is set to true or no more matches
*			Frames are searched as well.
*		OnShowScriptError
*			This event replaces ScriptErrorAction property. It passes;
*				ErrorLine, ErrorCharacter, ErrorCode, ErrorMsg, ErrorURL,
*				and a boolean parameter to indicate whether to
*				stop or continue running scripts bStopRunningScript (default TRUE)
*
*	4)New Methods
*		SetupWindowsHook, allows client to install windows hooks and receive notifications.
*			I am using registered windows messages for each hook procedure notification
*			to insure uniqueness of the message id which is passed to SendMessageTimeout.
*			The window message id is passed to lUWMHookMsgID variable during a call to
*			this method so the client can look for notification for a specific hook.
*		HookProcNCode, allows a client to retreive the nCode param from three hook callback
*			functions. For the rest of the windows hooks, the nCode param is meanningless.
*			WHT_CBT, WHT_MSGFILTER, and WHT_SYSMSGFILTER.
*		FindAndHighlightAllTextFrames, Unlike FindAndHighlightAllText which searches
*			and highlights matches in the active document, the new method searches and
*			highlights matches in all frames. Also returns number of found matches.
*		SetupCustomAutoComplete
*			Uses IEnumString interface to enable custom autocomplete for a combo or edit control
*		CustomAutoCompleteAddString
*			Adds a new string to the list of values to be used
*		CustomAutoCompleteEnable
*			Enables or disables custom autocomplete for a specific control
*		QueryIERegistryOption
*			Queries HKEY_CURRENT_USER\\Software\\Microsoft\\Internet Explorer\\Main for one of
*				DISABLE_SCRIPT_DEBUGGER
*				ERROR_DLG_DISPLAYED_ON_EVERY_ERROR
*				PLAY_ANIMATIONS
*				PLAY_BACKGROUND_SOUNDS
*				DISPLAY_INLINE_VIDEOS
*				DISPLAY_INLINE_IMAGES
*				FORMSUGGEST_PW_ASK
*				USE_FORMSUGGEST
*				USE_SEARCH_ASST
*		SetIERegistryOption
*			Uses HKEY_CURRENT_USER\\Software\\Microsoft\\Internet Explorer\\Main to set
*			IE registry options mentioned in QueryIERegistryOption
*		DecodeMime
*			Replaces MIME encoded strings
*			"%20" --> " "
*			"%FC" --> "ü"
*			"%25" --> "%"     etc...
*		DeleteIEFiles
*			DELETE_IE_CACHE
*			DELETE_IE_COOKIES
*			DELETE_IE_HISTORY
*
*	5)Bug fixs:
*		DocHostUIHandler::TranslateAccelerator.
*		Last param of FindAndHighlightAllText method now returns number of matches found
*			rather than returning a boolean value indicating success or failure
*		Added a boolean optional parameter to AddBrowser method to 
*			allow the client to open WBs in the background. By default, Browsers are
*			opened in the background.
*		Incorporated IDownloadManager interface within idl. No need for downloadmgr.h
*		LoadHTMLFromString
*			Fixed a bug that caused the base URL to be set to about:blank
*			Added a new parameter (sBaseUrl) to enable client to set base URL
*			Note:
*				If length of HTML content is greater than 256 characters,
*				to display the entire content, client must add a <base> tag
*				to the beginning of the HTML content <html><body><base>
*
*	6)Removed:
*		ShowMessage event
*			Replaced with DocHostShowMessage event
*		OnAcceletorKeys event
*			Replaced with OnWBKeyDown and OnWBKeyUp events
*		WB_SCRIPT_ERROR_ACTION enum
*		WB_ACCELETOR_KEYS_ACTION enum
*		AcceletorKeysAction property
*			Replaced with OnWBKeyDown and OnWBKeyUp events
*		ScriptErrorAction property
*			Replaced with OnShowScriptError event
*		Terminate method
*
*
*	Changes from 1.2.1.4:
*	=====================
*	1)New Events:
*		WBEvaluateNewWindow, Winxp sp2 and up
*
*	Changes from 1.2.1.3:
*	=====================
*	1)Bug fixs
*		IWB::GetIEServerHwnd
*		IWB::GetShellDocObjHwnd
*		IWB::GetShellEmbedding
*		WBDocHostUIHandler::TranslateAccelerator
*			OnAcceletorKeys was firing for both keydown+up
*			disable Ctrl+O, has to be handled by client. No default action exists.
*	2)Added VBDemoEx to download page
*		Received a lot of requests for this demo.
*			
*
*	Changes from 1.2.1.2:
*	=====================
*	1)New methods
*		OrganizeFavorites. (Thank you dosuryu)
*		ViewIEOptions.
*	3)Bug fixs
*		Replaced SecurityManagerProcessUrlAction event with WBProcessUrlAction
*		New event has two extra parameters PUAF_Flag (one of PUAF enum) and bHandled.
*		By default, bHandled is false, if setting lpUrlPolicy parameter, you also need
*		to set the bHandled to true.
*		lpUrlPolicy parameter is declared as long variable that can be set by client
*		one of URL Policy Flags. (Thank you ZackJ)
*
*		WBEventDispatch::WBHTMLDocAsStream method. (Thank you dosuryu)
*		Find method.
*		SaveAs method.
*
*		Moved all string literals to res file.
*
*	Changes from 1.2.1.1:
*	=====================
*	1)New Properties
*		SourceOnDocComplete (Fires DocumentCompleteWBEx instead of DocumentComplete passing document text.)
*	2)New events
*		DocumentCompleteWBEx (Set SourceOnDocComplete property to true, to have this event fire instead of DocumentComplete passing doc text)
*	3)Bug fixs
*		Disabeled Terminate method. Calling this method has no effect.
*		Fixed WBDocHostShowUI::ShowMessage to use MSHTML provided title.
*		Modified LoadHtmlFromString to be able to load buffers larger than 500 KB.
*		Added an optional parameter (bUseIEDefault) to RegisterAsDropTarget property.
*			(bUseIEDefault default value is False)
*			(Set bUseIEDefault to true to use default IE drag drop behaviour)
*		Added a parameter (lWBDropFormat) to WBDrop event. The value can be one of
*			WB_CFHTML			= 0 (includes HTML tags)
*			WB_CFTEXT			= 1
*			WB_CFSINGLEFILE		= 2
*			WB_CFRTF			= 3 (Includes RTF tags)
*			WB_CFERROR			= 4
*
*	Changes from 1.1.1.1:
*	=====================
*	1)New Properties
*		WBPageTextSize (ZOOM level - 0 to 4)
*
*	2)New methods
*		SaveAsBitmap (Entire page, no scrllbars, no borderstyle)
*		DrawWBThumbnailOnWnd (stretchblt a thumb img of WB viewing area)
*		LoadHtmlFromString (Loads an HTML string using PersistStreamInit of document)
*		DisplayCertificateDialog (If one is available)
*		SubclassWnd (Subclass a win, for future implementation of mouse gestures)
*		UnSubclassWnd (Unsubclass previously subclassed win)
*		AddMessage (Add subclass msg, WM_xxx)
*		SetupShellAutoComplete (Sets up an EDIT or COMBO for Shell autocomplete)
*		WBPostData:
*			(POST Style)
*				sURL = http://www.site.com
*				szData = _lang=EN&hm___tg= //Not including ? char
*
*			(GET Style)
*				sURL = http://www.site.com?_lang=EN&hm___tg=
*
*	3)New events
*		OnGetOptionKeyPath (WebBrowser Control instance will ignore any user settings for Internet Explorer)
*		OnGetOverrideKeyPath (WebBrowser Control instance will incorporate any user settings font settings)
*		OnWBDragEnter
*		OnWBDragOver
*		OnWBDrop (Single file/Link drop - Multi format HDROP,... - Explorer, WB, ...)
*		OnWBDrop2 (Multiple file drops - Multi format HDROP,... - Explorere,...)
*		OnWBDragLeave
*		OnPostDataAvailable
*		OnPostOnProgress
*		OnPostError
*		OnPostEnd
*		OnPostResponse
*		OnWMMessage (Fires for any WM_xxx msgs registered via AddMessage method for a subclassed window)
*
*	4)New interfaces
*		IDropTarget (DragDrop)
*		IDocHostUIHandler2 (GetOverrideKeyPath)
*		IStream (For futher implementation of upload with progress)
*
*	5)Bug fixs
*		Changed default value of m_StartupURL to L"" (Thank you dosuryu)
*		Changed the failed return value of WBHttpSecurity::OnSecurityProblem
*			method from RPC_E_RETRY to S_FALSE (Thank you folklayer)
*		Added _T to allow UNICODE build (Thank you Robert).
*		Modified Terminate and RemoveBrowser methods so as not to display
*			any messages in regard to ref count and not to generate any COM 
*			errors if ref count of IWB instance is greater than one.
*		Overrode IOleControlImpl::GetControlInfo and added default handling
*			of accelerator keys to ProcessWBAccelKeys method based on KB article 187644.
*		Removed optional keyword from vbMHWB.idl file.
*		Handled WM_SETFOCUS message to pass the focus from the control to the
*			first WB while tabbing through controls on a dialog/form.
*
*
*	Changes from 1.0.1.1:
*	=====================
*	1)Added a number of new events:
*		OnAuthentication
*		OnHTTPSecurityProblem
*		ProtocolHandlerOnBeginTransaction
*		ProtocolHandlerOnResponse
*		NewWindow3 (WinXP sp2 specific)
*	2)Fixed a bug with IOleCommandTarget::Exec method causing certain pages to crash.
*	3)Corrected a problem with the internal download control.
*		Downloading attachements from Hotmail, Yahoo, ... was not being intercepted
*		due to the use of Content_Disposition header.
*	4)Added dosuryu solution to CvbWB::ProcessWBAccelKeys method to process
*		<SELECT> tags properly.
*	5)Simplified the VBDemo Project.
*	6)Added a MFCDemo project.
*	7)Removed two events and added their functionalty to FileDownloadEx event
*		OnFileDLRedirect
*		OnFileDLStartDownload
*
*
*	Changes from 1.0.0.1:
*	=====================
*	1)Added ClearBSTRPtr function to free incoming BSTRs from client
*		before assignning new values to them.
*	2)Fixed a memory leak in WBDownLoadManager::Download method.
*		URL obtained from IMonikor.GetDisplayName is actually a
*		LPWSTR and not a BSTR, so the method SplitUrl was causing a leak.
*		Converting the URL to a BSTR using CComBSTR fixed the bug.
*/

//To avoid memory leaks caused by BSTR parameters pass byRef:
/*
*	In properties that have an in,out BSTR ptr
*	we must clear the BSTR ptr before assignning new values to it.
*	This is done using ClearBSTRPtr function.
*
*	In events that pass an in,out BSTR to be filled by client
*	we must use an initialized <CComBSTR str(L"")> and then pass it
*	to client like so <&str>
*/

//////////////////////////////////////
// vbWB.h : Declaration of the CvbWB
//////////////////////////////////////

#ifndef __VBWB_H_
#define __VBWB_H_

#include "resource.h"       // main symbols

#include <exdispid.h>
#include <exdisp.h>
//#include <initguid.h>
#include <shldisp.h>
#include <shlguid.h>
#include <shlobj.h>   // CLSID_CUrlHistory
#include <UrlHist.h>  // IUrlHistoryStg2  SHAddToRecentDocs, ...
//#include "shellapi.h" // SHEmptyRecycleBin

#include <mshtmdid.h>
#include <mshtmhst.h>
#include <mshtmcid.h>
#include <mshtml.h>
#include <urlmon.h>
//#include <downloadmgr.h> //Declared in idl
#include <servprov.h>
#include "UrlParts.h"
//To use our own protocol handlers for HTTP and HTTPS
#include "ProtocolImpl.h"
#ifndef _WIN32_WCE
#include "AutoCompleter.h"
#endif
//AuxCrt.cpp added to ATL include directory
//Refer to stdafx.cpp for explanation

//////////////////////////////////////////////End extras headers

#include <atlctl.h>
#include "vbMHWBCP.h"

//Forawrd declaration of classes
class CTmpBuffer; //Can't use CString, or string, or std:: stuff
class CVariantBSTRArray;
class CSubclassWnd; //For subclassing purposes - Mouse Gestures (future)
class IWB;
class WBNewWindowManager;
class WBDropTarget;
class WBClientSite;
class WBInPlaceSite;
class WBEventDispatch;
class WBDocHostUIHandler;
class WBDownLoadManager;
class WBDocHostShowUI;
class WBServiceProvider;
class WBOleCommandTarget;
class WBBSCBFileDL;
class WBSecurityManager;
class WBAuthenticate;
class WBHttpSecurity;
class WBWindowForBindingUI;
class WBStream;
class WBBSCBPost;
class WBBSCBUpload;
class WBIHTMLOMWindowServices;
class CLoadHTMLMoniker;
//For handling porotocols (http+https)
class WBPassthru;
class WBPassthruSink;

////////////////////////
//Simple buffer class.
//Since we are building this control with min dep
//we need a simple str buffer, can't use CString,....
////////////////////////
class CTmpBuffer
{
	#define STARTUP_TEMP_BUFFER MAX_PATH
	#define RES_BUFFER_SIZE 512
	#ifdef _UNICODE
		#define CHAR_FUDGE 1    // one TCHAR unused is good enough
	#else
		#define CHAR_FUDGE 2    // two BYTES unused for case of DBC last char
	#endif
public:
	CTmpBuffer();
	CTmpBuffer(LPCTSTR strText);
	CTmpBuffer(UINT iSize);
	~CTmpBuffer();
	
	// *** Local ***

	//We don't destroy the buffer
	//Usefull in loops when reading values into the buffer
	//using = operator.
	void ResetBuffer();
//Allocate buffer
	UINT AllocateBuffer(UINT nsize);
//Append a string
	UINT Append(LPCTSTR strText, UINT iMaxLen = 0);
//Append a BSTR
	UINT AppendBSTR(BSTR strText, UINT iMaxLen = 0);
//Append an int value
	UINT Appendint(int iNumber, int radix = 10);
//Append a long value
	UINT Appendlong(long lNumber, int radix = 10);
//Append resource string
	UINT AppendResStr(UINT nID, UINT iMaxLen = 0);
//Append GUID
	UINT AppendGUID(REFGUID src);

//Accessors
	TCHAR* GetString(void);
	UINT ReleaseString(void);
	LPCTSTR GetBuffer(void) const;
	//Get buffer len, may or may not contain any characters
	UINT GetBufferLen(void) const;
	//Get the Text len (number of actual chars)
	UINT GetBufferTextLen(void) const;
	TCHAR GetAt(int nIndex);
	void SetAt(int nIndex, TCHAR ch);

//Operators
	TCHAR* operator &() { return m_Buffer; }
	operator LPCTSTR() const { return m_Buffer; }
	TCHAR operator[] (int nIndex);

	CTmpBuffer& operator=(const CTmpBuffer& src);
	CTmpBuffer& operator=(const LPCTSTR src);
	CTmpBuffer& operator+=(const CTmpBuffer& strSrc);
	CTmpBuffer& operator+=(const LPCTSTR strSrc);
	CTmpBuffer& operator=(const UINT nID);
	CTmpBuffer& operator+=(const UINT nID);

private:
	ULONG		m_cRef;
	LPTSTR		m_Buffer;
	UINT		m_BufferLen;
	//where to write
	UINT		m_BufferTextLen;
	bool		m_Allocated;
	HINSTANCE	m_hInst;
	
	void InitLocalResources();
	void ClearLocalResources();
};

//Represents a simple BSTR array encapsulated in a variant
/*

Taken from WBDropTarget::Drop

TCHAR szFileName[MAX_PATH];
UINT iFile = = ::DragQueryFile(hDropInfo, 0xFFFFFFFF, szFileName, MAX_PATH);

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

*/
class CVariantBSTRArray
{
public:

	CVariantBSTRArray();
	CVariantBSTRArray(ULONG lInitSize);
	~CVariantBSTRArray();

	BOOL CreateArray(ULONG lInitSize = 1);

	//Adds BSTRs by making a local copy of data and checks for duplicates
	//Comparison case incensetive
	BOOL AddItemNoDuplicate(LPCTSTR pszItem);
	//Adds BSTRs by making a local copy of data
	BOOL AddItem(LPCTSTR pszItem);

	//Do not Free pItem memory. It is stored without making a copy
	//the memory for the item will be released when class terminates.
	//If bFreeBSTROnError is TRUE, pItem will be freed if an error occurs
	BOOL AddBSTR(BSTR pItem, BOOL bFreeBSTROnError = TRUE);
	//If bFreeBSTROnError is TRUE, pItem will be freed if
	//an error occurs or a duplicated is found
	BOOL AddBSTRNoDuplicate(BSTR pItem, BOOL bFreeBSTROnError = TRUE);

	BOOL ClearExtra();
	//Simple sort, Call after ClearExtra if Size > ItemsCount
	BOOL SortArray();

	ULONG ItemsCount() { return (m_lCur + 1); }
	ULONG ArraySize() { return (psa != NULL) ? psa->rgsabound[0].cElements : 0; }

	VARIANT ItemsVariant() { return var; }
	VARIANT* ItemsVariantPtr() { return &var; }

	operator VARIANT() { return var; }
	VARIANT* operator &() { return &var; }

private:
	VARIANT var;
	SAFEARRAY * psa; //safearray descriptor
	SAFEARRAYBOUND rgsabound[1]; //safearray bound structure, One bound for each dimension.
	BSTR HUGEP *pbstr; //Pointer to safearray elements
	ULONG m_lCur; //Cur index to add items, also acts as a counter

	void InternalInit();
	BOOL AddBSTRItem(BSTR pItem, BOOL bFreeBSTROnError = TRUE);
	//Searches for duplicates case sensitive
	//If a dup is found BSTR is freed
	BOOL IsDuplicate(BSTR pItem);

};

class CvbWBLicense
{
protected:
	static BOOL VerifyLicenseKey(BSTR bstr)
	{
		return wcscmp(bstr, L"ByVN45eOeUOrLz2t6u4X7Q") == 0;
	}
	static BOOL GetLicenseKey(DWORD, BSTR *pBstr)
	{
		*pBstr = SysAllocString(L"ByVN45eOeUOrLz2t6u4X7Q");
		return TRUE;
	}
	static BOOL IsLicenseValid() { return TRUE; }
};

/////////////////////////////////////////////////////////////////////////////
// CvbWB
class ATL_NO_VTABLE CvbWB : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IvbWB, &IID_IvbWB, &LIBID_VBMHWBLib>,
//	public IDispatchImpl<IvbWBUI, &IID_IvbWBUI, &LIBID_VBMHWBLib>,
	public CComControl<CvbWB>,
	public IPersistStreamInitImpl<CvbWB>,
	public IOleControlImpl<CvbWB>,
	public IOleObjectImpl<CvbWB>,
	public IOleInPlaceActiveObjectImpl<CvbWB>,
	public IViewObjectExImpl<CvbWB>,
	public IOleInPlaceObjectWindowlessImpl<CvbWB>,
	public ISupportErrorInfoImpl<&IID_IvbWB>,
	public IConnectionPointContainerImpl<CvbWB>,
	public IPersistStorageImpl<CvbWB>,
	public ISpecifyPropertyPagesImpl<CvbWB>,
	public IQuickActivateImpl<CvbWB>,
#ifndef _WIN32_WCE
	public IDataObjectImpl<CvbWB>,
#endif
	public IProvideClassInfo2Impl<&CLSID_vbWB, &DIID__IvbWBEvents, &LIBID_VBMHWBLib>,
	public IPropertyNotifySinkCP<CvbWB>,
	public CComCoClass<CvbWB, &CLSID_vbWB>,
	//To add persistance to design time properties
	//Uncomment below, under BEGIN_COM_MAP, and under BEGIN_PROP_MAP macros
	//Warnning, in VB, this action will require recompiling of all previous projects
	//that use this control. Or you need to modify the .frm file manually.
	//Find OleObjectBlob entry, remove it and add entries
	///// First two are mandatory
	//_cx             =   15690
	//_cy             =   6165
	//StartupURL      =   "http://www.google.com"
	//ucPort          =   80
	//Any other proeprties added to PROP_MAP section
	/////
	//public IPersistPropertyBagImpl<CvbWB>, // Added
	public CProxy_IvbWBEvents< CvbWB >
{
public:
	CvbWB();
	~CvbWB();
	DECLARE_CLASSFACTORY2(CvbWBLicense)

	DECLARE_OLEMISC_STATUS(OLEMISC_RECOMPOSEONRESIZE |
		OLEMISC_CANTLINKINSIDE |
		OLEMISC_INSIDEOUT |
		OLEMISC_ACTIVATEWHENVISIBLE |
		OLEMISC_SETCLIENTSITEFIRST)

DECLARE_REGISTRY_RESOURCEID(IDR_VBWB)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CvbWB)
	COM_INTERFACE_ENTRY(IvbWB)
//	COM_INTERFACE_ENTRY(IvbWBUI)
	COM_INTERFACE_ENTRY2(IDispatch, IvbWB)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY(IPersistStorage)
#ifndef _WIN32_WCE
	COM_INTERFACE_ENTRY(IDataObject)
#endif
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
	//Uncomment to add persistance to design time properties
	//COM_INTERFACE_ENTRY(IPersistPropertyBag) //Added
END_COM_MAP()

BEGIN_PROP_MAP(CvbWB)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	//Uncomment or add the properties...
	//PROP_ENTRY("StartupURL", 52, CLSID_NULL)
	//PROP_ENTRY("ucPort", 77, CLSID_NULL)
	//PROP_ENTRY("ucScheme", 75, CLSID_NULL)
END_PROP_MAP()

BEGIN_CONNECTION_POINT_MAP(CvbWB)
	CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
	CONNECTION_POINT_ENTRY(DIID__IvbWBEvents)
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(CvbWB)
	//MESSAGE_HANDLER(WM_CREATE, OnCreate)
	CHAIN_MSG_MAP(CComControl<CvbWB>)
	MESSAGE_HANDLER(WM_SIZE, OnSize)
	MESSAGE_HANDLER(WM_SETFOCUS, OnSetFocus)
	MESSAGE_HANDLER(WM_ERASEBKGND, OnEraseBkgnd)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

	HRESULT IPersistStreamInit_Load(LPSTREAM, ATL_PROPMAP_ENTRY const *) { return S_OK; }

// IViewObjectEx
	DECLARE_VIEW_STATUS(0)

// IvbWB
public:
	STDMETHOD(DeleteIEFiles)(/*[in]*/ DELETE_IE_FILES_FLAGS enumWhichFiles);
	STDMETHOD(DecodeMime)(/*[in]*/ BSTR strToDecode, /*[in, out]*/ BSTR *strDecoded);
	STDMETHOD(QueryIERegistryOption)(/*[in]*/ long IeRegistryOptionsFlag,/*[in, out]*/ VARIANT * varBuffer);
	STDMETHOD(SetIERegistryOption)(/*[in]*/ long IeRegistryOptionsFlag,/*[in]*/ VARIANT * varBuffer);
	STDMETHOD(CustomAutoCompleteAddString)(/*[in]*/ long hwndTarget,/*[in]*/ VARIANT_BOOL IsTargetComboBox , /*[in]*/ BSTR strItem);
	STDMETHOD(CustomAutoCompleteEnable)(/*[in]*/ long hwndTarget,/*[in]*/ VARIANT_BOOL IsTargetComboBox ,/*[in]*/ VARIANT_BOOL bEnable);
	STDMETHOD(SetupCustomAutoComplete)(/*[in]*/ long hwndTarget,/*[in]*/ VARIANT_BOOL IsTargetComboBox , /*[in]*/ long lCustomAutoCompleteFlags, /*[in]*/ VARIANT * varStringArray);
	STDMETHOD(HookProcNCode)(/*[in]*/ WINDOWSHOOK_TYPES lHookType, /*[in,out]*/ long *nCode);
	STDMETHOD(SetupWindowsHook)(/*[in]*/ WINDOWSHOOK_TYPES lHookType, /*[in]*/ long hwndTargetWnd , /*[in]*/ VARIANT_BOOL bStart, /*[in,out]*/ long *lUWMHookMsgID);
	STDMETHOD(FindAndHighlightAllTextFrames)(/*[in]*/ short wbUID,/*[in]*/ BSTR TextToFind,/*[in]*/ VARIANT_BOOL bMatchWholeWord,/*[in]*/ VARIANT_BOOL bMatchCase,/*[in]*/ BSTR HighlightColor,/*[in,out]*/ long *NumOfMatchsFound);
	STDMETHOD(ViewIEOptions)(/*[in]*/ short wbUID);
	STDMETHOD(OrganizeFavorites)();
	STDMETHOD(get_SourceOnDocComplete)(/*[in]*/ short wbUID, /*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_SourceOnDocComplete)(/*[in]*/ short wbUID, /*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(WBPostData)(/*[in]*/ BSTR sURL, /*[in]*/ BSTR sData, /*[in, out]*/ short *PostID);
	STDMETHOD(SaveAsBitmap)(/*[in]*/ short wbUID,/*[in]*/ BSTR BitmapName);
	STDMETHOD(SetupShellAutoComplete)(/*[in]*/ long hwndTarget,/*[in]*/ VARIANT_BOOL IsTargetComboBox, /*[in]*/ long lFlags);
	STDMETHOD(AddMessage)(/*[in]*/ long hwndWnd, /*[in]*/ long lMsg);
	STDMETHOD(UnSubclassWnd)(/*[in]*/ long hwndWnd);
	STDMETHOD(SubclassWnd)(/*[in]*/ long hwndWnd);
	STDMETHOD(ucResetFieldsToDefault)(void);
	STDMETHOD(get_WBPageTextSize)(/*[in,defaultvalue(0)]*/ short wbUID,/*[out, retval]*/ long *pVal);
	STDMETHOD(put_WBPageTextSize)(/*[in,defaultvalue(0)]*/ short wbUID, /*[in]*/ long newVal);
	STDMETHOD(DrawWBThumbnailOnWnd)(/*[in]*/ short wbUID, /*[in]*/ long WndHdc, /*[in]*/ long lX, /*[in]*/ long lY, /*[in]*/ long lW, /*[in]*/ long lH);
	STDMETHOD(LoadHTMLFromString)(/*[in]*/ short wbUID, /*[in]*/ BSTR sContent, /*[in]*/ BSTR sBaseUrl);
	STDMETHOD(DisplayCertificateDialog)(/*[in]*/ short wbUID);
	STDMETHOD(RegisterHTTPSprotocol)(/*[in]*/ VARIANT_BOOL pVal);
	STDMETHOD(RegisterHTTPprotocol)(/*[in]*/ VARIANT_BOOL pVal);
	STDMETHOD(DownloadUrlAsync)(/*[in]*/ BSTR URL,/*[in]*/ BSTR SaveFileName, /*[in, out]*/ short *DLUID);
	STDMETHOD(CancelFileDl)(/*[in]*/ short UIDToCancel);
	STDMETHOD(ucInternetCreateUrl)(/*[in, out]*/ BSTR *URL);
	STDMETHOD(get_ucInternetScheme)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_ucInternetScheme)(/*[in]*/ long newVal);
	STDMETHOD(ucInternetCrackUrl)(/*[in]*/ BSTR URL,/*[in, out]*/ VARIANT_BOOL *bSuccess);
	STDMETHOD(get_ucFileExtension)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_ucFileName)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_ucFullURL)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_ucFullURL)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_ucExtraInfo)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_ucExtraInfo)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_ucUrlPath)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_ucUrlPath)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_ucPassword)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_ucPassword)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_ucUserName)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_ucUserName)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_ucPort)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_ucPort)(/*[in]*/ long newVal);
	STDMETHOD(get_ucHostName)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_ucHostName)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_ucScheme)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_ucScheme)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_IsDocFrameset)(/*[in]*/ short wbUID, /*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(FindAnyTextMatch)(/*[in]*/ short wbUID,/*[in]*/ BSTR TextToFind,/*[in]*/ VARIANT_BOOL bMatchWholeWord,/*[in]*/ VARIANT_BOOL bMatchCase,/*[in,out]*/ VARIANT_BOOL *FindMatch);
	STDMETHOD(FindTextSimple)(/*[in]*/ short wbUID,/*[in]*/ BSTR TextToFind,/*[in]*/ VARIANT_BOOL bDownward,/*[in]*/ VARIANT_BOOL bMatchWholeWord,/*[in]*/ VARIANT_BOOL bMatchCase,/*[in]*/ VARIANT_BOOL bScrollIntoView,/*[in,out]*/ VARIANT_BOOL *FindMatch);
	STDMETHOD(FindAndHighlightAllText)(/*[in]*/ short wbUID,/*[in]*/ BSTR TextToFind,/*[in]*/ VARIANT_BOOL bMatchWholeWord,/*[in]*/ VARIANT_BOOL bMatchCase,/*[in]*/ BSTR HighlightColor,/*[in,out]*/ long *NumOfMatchsFound);
	STDMETHOD(get_DocumentHostUiDoubleClickAction)(/*[in,defaultvalue(0)]*/ short wbUID, /*[out, retval]*/ long *pVal);
	STDMETHOD(put_DocumentHostUiDoubleClickAction)(/*[in,defaultvalue(0)]*/ short wbUID, /*[in]*/ long newVal);
	STDMETHOD(get_DocumentHostUiFlags)(/*[in,defaultvalue(0)]*/ short wbUID, /*[out, retval]*/ long *pVal);
	STDMETHOD(put_DocumentHostUiFlags)(/*[in,defaultvalue(0)]*/ short wbUID, /*[in]*/ long newVal);
	STDMETHOD(get_DocumentDownloadControlFlags)(/*[in,defaultvalue(0)]*/ short wbUID, /*[out, retval]*/ long *pVal);
	STDMETHOD(put_DocumentDownloadControlFlags)(/*[in,defaultvalue(0)]*/ short wbUID, /*[in]*/ long newVal);
	STDMETHOD(get_ContextMenuAction)(/*[in,defaultvalue(0)]*/ short wbUID, /*[out, retval]*/ long *pVal);
	STDMETHOD(put_ContextMenuAction)(/*[in,defaultvalue(0)]*/ short wbUID, /*[in]*/ long newVal);
	STDMETHOD(get_ObjectWB)(/*[in]*/ short wbUID, /*[out, retval]*/ LPDISPATCH *pVal);
	STDMETHOD(AddBrowser)(/*[in,out]*/short *wbUID, /*[in,defaultvalue(0)]*/ VARIANT_BOOL bBringToFront);
	STDMETHOD(Navigate)(/*[in]*/ short wbUID, /*[in]*/ BSTR URL, /*[in,defaultvalue(0)]*/ VARIANT *Flags, /*[in,defaultvalue(0)]*/ VARIANT *TargetFrameName, /*[in,defaultvalue(0)]*/ VARIANT *PostData, /*[in,defaultvalue(0)]*/ VARIANT *Headers);
	STDMETHOD(Navigate2)(/*[in]*/ short wbUID, /*[in]*/ VARIANT *URL, /*[in,defaultvalue(0)]*/ VARIANT *Flags, /*[in,defaultvalue(0)]*/ VARIANT *TargetFrameName, /*[in,defaultvalue(0)]*/ VARIANT *PostData, /*[in,defaultvalue(0)]*/ VARIANT *Headers);
	STDMETHOD(get_ActiveDocumentObj)(/*[in]*/ short wbUID, /*[out, retval]*/ LPDISPATCH *pVal);
	STDMETHOD(get_ActiveElementObj)(/*[in]*/ short wbUID, /*[out, retval]*/ LPDISPATCH *pVal);
	STDMETHOD(get_Document)(/*[in]*/ short wbUID, /*[out, retval]*/ LPDISPATCH *pVal);
	STDMETHOD(get_Application)(/*[in]*/ short wbUID, /*[out, retval]*/ LPDISPATCH *pVal);
	STDMETHOD(get_WBVisible)(/*[in]*/ short wbUID, /*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_WBVisible)(/*[in]*/ short wbUID, /*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_FramesCount)(/*[in]*/ short wbUID, /*[out, retval]*/ long *pVal);
	STDMETHOD(get_HWNDShellEmbedding)(/*[in]*/ short wbUID, /*[out, retval]*/ long *pVal);
	STDMETHOD(get_UseIEDefaultFileDownload)(/*[in]*/ short wbUID, /*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_UseIEDefaultFileDownload)(/*[in]*/ short wbUID, /*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_StartupURL)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_StartupURL)(/*[in]*/ BSTR newVal);
	STDMETHOD(QueryStatusWB)(/*[in]*/ short wbUID, /*[in]*/ long cmdID, /*[out, retval]*/ long * pcmdf);
	STDMETHOD(ExecWB)(/*[in]*/ short wbUID,/*[in]*/ long cmdID,/*[in]*/ long cmdExecOpt,/*[in,defaultvalue(NULL)]*/ VARIANT *pvaIn,/*[in,out,defaultvalue(NULL)]*/ VARIANT *pvaOut);
	STDMETHOD(AnyDocHasFocus)(/*[out,retval]*/ short *wbUID);
	STDMETHOD(get_HWNDMainWnd)(/*[out, retval]*/ long *pVal);
	STDMETHOD(PlaceWBOnTop)(/*[in]*/ short wbUID);
	STDMETHOD(SetFocusW)(/*[in]*/ short wbUID);
	STDMETHOD(AddToFavorites)(/*[in]*/ short wbUID);
	STDMETHOD(ViewSource)(/*[in]*/ short wbUID);
	STDMETHOD(get_HWNDInternetExplorerServer)(/*[in]*/ short wbUID, /*[out, retval]*/ long *pVal);
	STDMETHOD(get_HWNDShellDocObjectView)(/*[in]*/ short wbUID, /*[out, retval]*/ long *pVal);
	STDMETHOD(PrintPreview2)(/*[in]*/ short wbUID);
	STDMETHOD(Print2)(/*[in]*/ short wbUID);
	STDMETHOD(PageSetup)(/*[in]*/ short wbUID);
	STDMETHOD(PrintPreview)(/*[in]*/ short wbUID);
	STDMETHOD(Print)(/*[in]*/ short wbUID);
	STDMETHOD(SaveAs)(/*[in]*/ short wbUID);
	STDMETHOD(Save)(/*[in]*/ short wbUID);
	STDMETHOD(FileOpen)(/*[in]*/ short wbUID);
	STDMETHOD(NewWindow)(/*[in]*/ short wbUID);
	STDMETHOD(Properties)(/*[in]*/ short wbUID);
	STDMETHOD(Spell)(/*[in]*/ short wbUID);
	STDMETHOD(PasteSpecial)(/*[in]*/ short wbUID);
	STDMETHOD(Find)(/*[in]*/ short wbUID);
	STDMETHOD(Delete)(/*[in]*/ short wbUID);
	STDMETHOD(ClearSelection)(/*[in]*/ short wbUID);
	STDMETHOD(Redo)(/*[in]*/ short wbUID);
	STDMETHOD(Undo)(/*[in]*/ short wbUID);
	STDMETHOD(Cut)(/*[in]*/ short wbUID);
	STDMETHOD(Copy)(/*[in]*/ short wbUID);
	STDMETHOD(Paste)(/*[in]*/ short wbUID);
	STDMETHOD(SelectAll)(/*[in]*/ short wbUID);
	STDMETHOD(get_LocationName)(/*[in]*/ short wbUID, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_Silent)(/*[in]*/ short wbUID, /*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_Silent)(/*[in]*/ short wbUID, /*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_RegisterAsDropTarget)(/*[in]*/ short wbUID, /*[in]*/ VARIANT_BOOL bUseIEDefault, /*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_RegisterAsDropTarget)(/*[in]*/ short wbUID, /*[in]*/ VARIANT_BOOL bUseIEDefault, /*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_RegisterAsBrowser)(/*[in]*/ short wbUID, /*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_RegisterAsBrowser)(/*[in]*/ short wbUID, /*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_Busy)(/*[in]*/ short wbUID, /*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(Refresh2)(/*[in]*/ short wbUID, /*[in]*/ VARIANT *level);
	STDMETHOD(GoSearch)(/*[in]*/ short wbUID);
	STDMETHOD(ReadyState)(/*[in]*/ short wbUID,/*[out,retval]*/ READYSTATE *plReadyState);
	STDMETHOD(get_Offline)(/*[in]*/ short wbUID, /*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_Offline)(/*[in]*/ short wbUID, /*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_LocationURL)(/*[in]*/ short wbUID, /*[out, retval]*/ BSTR *pURL);
	STDMETHOD(get_WebBrowser)(/*[in]*/ short wbUID, /*[out, retval]*/ LPDISPATCH *pVal);
	STDMETHOD(NavigateSimple)(/*[in]*/ short wbUID,/*[in]*/ BSTR URL);
	STDMETHOD(GoHome)(short wbUID);
	STDMETHOD(GoForward)(short wbUID);
	STDMETHOD(GoBack)(short wbUID);
	STDMETHOD(Stop)(short wbUID);
	STDMETHOD(Refresh)(short wbUID);
	STDMETHOD(RemoveBrowser)(/*[in]*/ short wbUIDToRemove);
	STDMETHOD(get_Count)(/*[out, retval]*/ short *pVal);
	//Added to pass focus to a WB on top of Zorder if any exists
	LRESULT OnSetFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnSize(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);
	LRESULT OnEraseBkgnd(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	//LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);
	//Added for MFC
	//Used in PreTranslateMessage method to allow WBs
	//to process accel keys
	BOOL(PreTranslateMessage)(MSG* pMsg);
	//Default implementation in ATL of the 
	//IOleControlImpl::GetControlInfo() and 
	//IOleInPlaceActiveObjectImpl::TranslateAccelerator() methods 
	//just returns E_NOTIMPL. The container calls GetControlInfo to get 
	//the control's keyboard mnemonics and keyboard behavior, and it calls 
	//TranslateAccelerator() to process the keys.
	STDMETHOD(TranslateAccelerator)(MSG *pMsg);
	STDMETHOD(GetControlInfo)(CONTROLINFO *pCI);
	//This is called in OnDrawAdvanced in CComControlBase
	HRESULT OnDraw(ATL_DRAWINFO& di);
	BOOL RemoveBSCBFromDLArr(short uID);
	BOOL RemoveHostFromArray(short uHostId);

public:
	//Unique id for each dl, starts at one and increases
	short m_dluid;
	//Array of BindStatusCallBacks for file downloads
	//Used from client side to abort timed out dls, ...
	CSimpleArray<WBBSCBFileDL*> m_arrDL;
	//Used in finding the instance of our control to use for firing events
	//Returns m_thisID of the IWB(host) or 0
	BOOL FindWBHost(HWND hIEServer,IWB **ppHost);
	//Startup URL
	CComBSTR	m_StartupURL;
	VARIANT_BOOL  m_bUseIEDownloader;
	//Clipboard formats that need to be registered for drag and drop
	//Registered clipboard formats are identified by values in the
	//range 0xC000 through 0xFFFF.
	//When registered clipboard formats are placed on or retrieved from the clipboard,
	//they must be in the form of an HGLOBAL value.
	UINT		m_CF_HTML; //HTML format
	UINT		m_CF_RTF; //Rich Text Format
	UINT		m_CF_URL; //UniformResourceLocator-UniformResourceLocatorW
	UINT		m_CF_FILECONTENTS; //FileContents
	UINT		m_CF_NETRESOURCE; //Net Resource
	UINT		m_CF_FILEGROUPDESCRIPTORA; //FileGroupDescriptor 

private:
	enum WB_FLAGS
	{
		WB_FLAGS_Accels,
		WB_FLAGS_CtxMnu,
		WB_FLAGS_DL,
		WB_FLAGS_UI,
		WB_FLAGS_DblClk,
		WB_FLAGS_ScriptError,
		WB_FLAGS_PageZoom,
		WB_FLAGS_Silen,
		WB_FLAGS_Offline,
		WB_FLAGS_UseIEDefaultDownloader,
		WB_FLAGS_RegisterAsBrowser,
		WB_FLAGS_RegisterAsDropTraget_IE,
		WB_FLAGS_RegisterAsDropTraget_Internal,
		WB_FLAGS_SendSourceOnDocComplete
	}WB_FALGS;
	
	enum WB_MiscCommandTarget
	{
		WB_MiscCommandTarget_Find = 1,
		WB_MiscCommandTarget_ViewSource,
		WB_MiscCommandTarget_Options
	}MiscCommandTarget;

	bool InIDE();
	void SetGlobalFlags(WB_FLAGS lCase, VARIANT_BOOL newVal);
	void SetGlobalFlags(WB_FLAGS lCase, DWORD newVal);
	void ResizeWBs();
	HRESULT ProcessWBAccelKeys(MSG *pMsg);
	//Helper function to find a WB based on it's uID
	int FindWB(short nID);
	//Simple array of WB pointers
	CSimpleArray<IWB*> m_arrWB;
	//Unique id assigned to each IWB class instance
	//Starts at one and increments for every new WB
	short m_wbuid;
	//Currently viewed WB, or 0 if none has been
	//created. Used for passing focus to WB from
	//this control
	short m_wbcurid;

	//To control the startup browsers global flags
	//that need to be set before creating wb
	DWORD m_HostUiFlags;
	DWORD m_HostDbClickAction;
	DWORD m_HostDlFlag;
	DWORD m_dwCtxMnuAction;
	
	VARIANT_BOOL  m_bSilent;
	VARIANT_BOOL  m_bOffLine;
	VARIANT_BOOL  m_bRegisterAsBrowser;
	VARIANT_BOOL  m_bRegisterAsDropTarget;
	VARIANT_BOOL  m_bUseInternalDragDrop;
	VARIANT_BOOL  m_bSourceOnDocComplete;

	//Used for crackURL function
	CComBSTR    strScheme;
	CComBSTR    strHostName;
	CComBSTR    strUserName;
	CComBSTR    strPassword;
	CComBSTR    strUrlPath;
	CComBSTR    strExtraInfo;
	CComBSTR    strFullURL;
	CComBSTR    strFileName;
	CComBSTR    strFileExtension;
	long		Port;
	long		m_nScheme; //Scheme as INTERNET_SCHEME
	long		m_TextZoomVal; //Font size 0-4 (smallest to largerst)
	//Array of SubClassed Wnds
	CSimpleArray<CSubclassWnd*> m_Subclassed;
#ifndef _WIN32_WCE
	CSimpleArray<CAutoCompleter*> m_AutoCompleters;
#endif

	void InitInternalHookStructures();
// IvbWBUI
//public:

};

////////////////////////////////////////////////////////////////////
//A simple subclassing class
//Subclasses a given window and fires WM_xxx msgs back to client
//Not using ATL msg map, rather firing events right from WindowProc
////////////////////////////////////////////////////////////////////
class CSubclassWnd : public CWindowImpl<CSubclassWnd> 
{
	typedef CWindowImpl<CSubclassWnd> BaseClass;

private:
  static LRESULT CALLBACK MyWindowProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
  CSimpleArray<UINT> m_Msgs;
  CvbWB *m_EventObj;
  HWND m_HwndSubclassed;

public:
	CSubclassWnd() : m_EventObj(NULL),
					m_HwndSubclassed(NULL)
	{
	}
	~CSubclassWnd();

	//To avoid compiler error, declare an empty msg map:)
	DECLARE_EMPTY_MSG_MAP();
	
	BOOL AddSubclassMsg(UINT uMsg);
	BOOL IsSubClassedByThis(HWND HwndSubclassed);
	BOOL StopSubClassing(HWND HwndSubclassed);
	BOOL StartSubClassing(CvbWB *cpHost, HWND HwndSubclassed);
	//Need to override GetWindowProc virtual function
	//so we can pass our WindowProc address to be used
    WNDPROC GetWindowProc( ) {return MyWindowProc;}
};

//////////////////////////////////////////////
//
//IWB
//
//////////////////////////////////////////////
class IWB : public IUnknown
{
public:
	void SetFocusDoc();
	HWND GetIEServerHwnd();
	HWND GetShellDocObjHwnd();
	HWND GetShellEmbedding();

	IWB(CvbWB *EventsPtr);
	~IWB();

    // IUnknown
    ULONG STDMETHODCALLTYPE AddRef();
    ULONG STDMETHODCALLTYPE Release();
    STDMETHODIMP QueryInterface(REFIID iid, void ** ppvObject);

	STDMETHOD(StartWB)(DWORD UiFlags, 
						DWORD UiDblClk, 
						DWORD DlFlag, 
						long CtxMnuAction, 
						short sID, 
						VARIANT_BOOL bAllowDragDrop, 
						VARIANT_BOOL bUseInternalDragDrop,
						VARIANT_BOOL bSendSourceOnDocComplete,
						BSTR sStartUp = L"about:blank");
	STDMETHOD(StopWB)();
	void SetLocation(RECT *rNewPos);
	bool SetVisible( bool bVisible );
	void InvokeIEServerCommand(long nID);
	void InvokeShellDocObjCommand(long nID);
	void BringWbToTop();

	//Finds, scrolls into view and highlights text
	bool DocFindText(BSTR pText,
							VARIANT_BOOL DownWard,
							VARIANT_BOOL MatchWholeWord,
							VARIANT_BOOL MatchCase,
							VARIANT_BOOL ScrollIntoView);

	long SearchFramesets(IHTMLDocument2 *pFrameSet, 
		BSTR pText, long searchcase, VARIANT HighlightColor);

	long DocFindAndHighlightText(IHTMLBodyElement *pBodyElement, 
		BSTR pText, long searchcase, VARIANT HighlightColor);

	long DocHighlightAllFindText(BSTR pText,
							VARIANT_BOOL MatchWholeWord,
							VARIANT_BOOL MatchCase,
							BSTR HighlightColor = L"greenyellow");

	long DocHighlightFindText(BSTR pText,
							VARIANT_BOOL MatchWholeWord,
							VARIANT_BOOL MatchCase,
							BSTR HighlightColor = L"greenyellow");

	bool DocTextExists(BSTR pText,
							VARIANT_BOOL MatchWholeWord,
							VARIANT_BOOL MatchCase);

	bool SearchFrameset(IHTMLDocument2 *pFrameSet,
							BSTR pText,
							long lCase);

	bool SearchDocument(IHTMLDocument2 *pFrameSet,
							bool *IsFrame,
							BSTR pText,
							long lCase);
	bool IsFrameset();
	bool IsFrameset(IWebBrowser2 *pBrowser);
	long FramesCount(IHTMLDocument2 *pFrameSet);
	long FramesCount(IWebBrowser2 *pBrowser);
	HRESULT WBCreateBSCBFileDL(WBBSCBFileDL **ppTargetBSCBFileDL);

    // Classes Implemented
    WBClientSite				*m_pWBClientSite;
    WBInPlaceSite				*m_pWBInPlaceSite;
    WBEventDispatch				*m_pWBEventDispatch;
	WBDocHostUIHandler			*m_pWBDocHostUIHandler;
	WBServiceProvider			*m_pWBServiceProvider;
	WBDocHostShowUI				*m_pWBDocHostShowUI;
	//Our own implementation of IOleCommandTarget to stop script errors
	WBOleCommandTarget			*m_pWBOleCommandTarget;
	//Our own security manager
	WBSecurityManager			*m_pWBSecurityManager;
	WBAuthenticate				*m_pWBAuthenticate;
	WBHttpSecurity				*m_pWBHttpSecurity;
	WBWindowForBindingUI		*m_pWBWindowForBindingUI;
	WBNewWindowManager			*m_pWBNewWindowManager;
	
	//Unique id of this wb
	short				m_thisID;
	//To relay events
	CvbWB				*m_EventsPtr;
    // Master reference count
    ULONG               m_dwRefCount;
	DWORD               dwAdviseCookie;
    //Parent to host our browsers is the ATL created window
	//Although, it can be any window with a bit of modifications
	//to this code.
    HWND                m_hwndParent;
	//Rect for setting focus + visible
	RECT				rWindowPos;

	CComPtr<IUnknown>				pUnknown;
	CComPtr<IWebBrowser2>			pWebBrowser;
	CComPtr<IOleCommandTarget>		pOleCommandTarget;
	CComPtr<IOleObject>				spOleObj;
//	CComPtr<IBindHost>				pBindHost;
//	CComPtr<IServiceProvider>		pServiceProvider;

	//Use ie internal dl mechanism. default false
	bool				m_useieforfiledl;
	//Are we visible
	bool				m_visible;
	//To search for text
	IHTMLTxtRange		*m_txtrange;
	//Default false, as is the Webbrowser::RegisterAsDropTarget proeprty's default value.
	//This flag is used in our implementation of IDropTarget to allow/disallow dragdrops
	//from any source
	bool				m_bAllowDragDrop;

	//Internet Explorere_Server
	HWND				m_hwndIEServer;

private:
	//Parent ==> child
	//Shell Embedding (OleWindow)
	HWND				m_hwndShellEmbedding;
	//Shell DocObject View
	HWND				m_hwndShellDocObjView;
	CComBSTR			m_sbackcolor;
	CComBSTR			m_sword;
	CComBSTR			m_stextedit;
	void CleanUp();
};

#ifndef _WIN32_WCE
////////////////////////////////////////////////////////////////////////
//WBNewWindowManager
////////////////////////////////////////////////////////////////////////
class WBNewWindowManager : public INewWindowManager
{
public:
	WBNewWindowManager(IWB* pFrameSite)
	{
		m_pHost = pFrameSite;
		lEFail = static_cast<long>(E_FAIL);
	}
	~WBNewWindowManager()
	{
	}

    // IUnknown
    STDMETHODIMP QueryInterface(REFIID iid, void ** ppvObject)
	{
		return m_pHost->QueryInterface(iid, ppvObject);
	}
    ULONG STDMETHODCALLTYPE AddRef()
	{
		return m_pHost->AddRef();
	}
    ULONG STDMETHODCALLTYPE Release()
	{
		return m_pHost->Release();
	}

	STDMETHODIMP EvaluateNewWindow(LPCWSTR pszUrl, LPCWSTR pszName, 
							  LPCWSTR pszUrlContext, LPCWSTR pszFeatures, 
							  BOOL fReplace, DWORD dwFlags,
							  DWORD dwUserActionTime);
private:
    IWB			*m_pHost;
	long		lEFail;
};
#endif

////////////////////////////////////////////////////////////////////////
//WBDropTarget
//Only one instance of this class is created and maintained via 
//WBDocHostUIHandler::GetDropTarget. It is released from WBDocHostUIHandler
//destructor
////////////////////////////////////////////////////////////////////////

class WBDropTarget : public IDropTarget
{
//	#define MIN_REGISTERED_CLIPFORMAT 0xC000
//	#define MAX_REGISTRERD_CLIPFORMAT 0xFFFF
public:
	WBDropTarget(IWB* pFrameSite);
	~WBDropTarget();

    // IUnknown
    STDMETHODIMP QueryInterface(REFIID iid, void ** ppvObject);
    ULONG STDMETHODCALLTYPE AddRef();
    ULONG STDMETHODCALLTYPE Release();
	
	//IDropTarget
    STDMETHODIMP DragEnter( 
        /* [unique][in] */ IDataObject *pDataObj,
        /* [in] */ DWORD grfKeyState,
        /* [in] */ POINTL pt,
        /* [out][in] */ DWORD *pdwEffect);
    
    STDMETHODIMP DragOver( 
        /* [in] */ DWORD grfKeyState,
        /* [in] */ POINTL pt,
        /* [out][in] */ DWORD *pdwEffect);
    
    STDMETHODIMP DragLeave( void);
    
    STDMETHODIMP Drop( 
        /* [unique][in] */ IDataObject *pDataObj,
        /* [in] */ DWORD grfKeyState,
        /* [in] */ POINTL pt,
        /* [out][in] */ DWORD *pdwEffect);

private:
    IWB			*m_pHost;
    ULONG		m_cRef;
	long		m_lEffects;
	long DetermineEffect(DWORD dwEffects);
};

///////////////////////////////////////////////////////////////////////
///////////WBClientSite
///////////////////////////////////////////////////////////////////////
class WBClientSite : public IOleClientSite
{
public:
    WBClientSite(IWB* pFrameSite);
    ~WBClientSite();

    // IUnknown
    STDMETHODIMP QueryInterface(REFIID iid, void ** ppvObject);
    ULONG STDMETHODCALLTYPE AddRef();
    ULONG STDMETHODCALLTYPE Release();

    // IOleClientSite
    STDMETHODIMP GetContainer(LPOLECONTAINER FAR* ppContainer);
    STDMETHODIMP SaveObject();
    STDMETHODIMP GetMoniker(DWORD dwAssign, DWORD dwWhichMoniker, IMoniker ** ppmk);
    STDMETHODIMP ShowObject();
    STDMETHODIMP OnShowWindow(BOOL fShow);
    STDMETHODIMP RequestNewObjectLayout();

private:
    IWB *m_pHost;
};

///////////////////////////////////////////////////////////////////////
///////////WBInPlaceSite
///////////////////////////////////////////////////////////////////////
class WBInPlaceSite : public IOleInPlaceSite
{
public:
    WBInPlaceSite(IWB* pFrameSite);
    ~WBInPlaceSite();

    // IUnknown
    STDMETHODIMP QueryInterface(REFIID iid, void ** ppvObject);
    ULONG STDMETHODCALLTYPE AddRef();
    ULONG STDMETHODCALLTYPE Release();

    // IOleWindow
    STDMETHODIMP GetWindow(HWND * phwnd);
    STDMETHODIMP ContextSensitiveHelp(BOOL fEnterMode);

    // IOleInPlaceSite
    STDMETHODIMP CanInPlaceActivate(void);
    STDMETHODIMP OnInPlaceActivate(void);
    STDMETHODIMP OnUIActivate(void);
    STDMETHODIMP GetWindowContext(IOleInPlaceFrame **ppFrame,
                                               IOleInPlaceUIWindow **ppDoc, LPRECT lprcPosRect,
                                               LPRECT lprcClipRect,
                                               LPOLEINPLACEFRAMEINFO lpFrameInfo);
    STDMETHODIMP Scroll(SIZE scrollExtant);
    STDMETHODIMP OnUIDeactivate(BOOL fUndoable);
    STDMETHODIMP OnInPlaceDeactivate(void);
    STDMETHODIMP DiscardUndoState(void);
    STDMETHODIMP DeactivateAndUndo(void);
    STDMETHODIMP OnPosRectChange(LPCRECT lprcPosRect);

private:
    IWB *m_pHost;
};

///////////////////////////////////////////////////////////////////////
///////////WBEventDispatch
///////////////////////////////////////////////////////////////////////
class WBEventDispatch : public IDispatch
{
public:
    WBEventDispatch(IWB* pFrameSite);
    ~WBEventDispatch();

    // IUnknown
    STDMETHODIMP QueryInterface(REFIID iid, void ** ppvObject);
    ULONG STDMETHODCALLTYPE AddRef();
    ULONG STDMETHODCALLTYPE Release();

    // IDispatch
    STDMETHODIMP GetTypeInfoCount(unsigned int FAR* pctinfo);
    STDMETHODIMP GetTypeInfo(unsigned int iTInfo, LCID  lcid,
                                          ITypeInfo FAR* FAR*  ppTInfo);
    STDMETHODIMP GetIDsOfNames(REFIID riid, OLECHAR FAR* FAR* rgszNames,
                                            unsigned int cNames, LCID lcid, DISPID FAR* rgDispId);
    STDMETHODIMP Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags,
                                     DISPPARAMS FAR* pDispParams, VARIANT FAR* parResult,
                                     EXCEPINFO FAR* pExcepInfo, unsigned int FAR* puArgErr);

	DWORD m_dwDLControl;
	bool m_bSendSourceOnDocComplete;
private:
    IWB *m_pHost;
	LPTSTR m_pszStrDoc;
	CComBSTR m_ZeroLenStr;
	HRESULT WBHTMLDocAsStream(LPDISPATCH pDisp);
};

///////////////////////////////////////////////////////////////////////
///////////WBDocHostUIHandler -> IDocHostUIHandler + IDocHostUIHandler2
///////////////////////////////////////////////////////////////////////
class WBDocHostUIHandler : 
				//public IDocHostUIHandler
				public IDocHostUIHandler2
{
public:
	WBDocHostUIHandler(IWB* pFrameSite);
	~WBDocHostUIHandler();

	// IUnknown
	STDMETHODIMP QueryInterface(REFIID iid, void ** ppvObject);
	ULONG STDMETHODCALLTYPE AddRef();
	ULONG STDMETHODCALLTYPE Release();

	//IDocHostUIHandler
	STDMETHODIMP ShowContextMenu(DWORD dwID, POINT FAR* ppt, IUnknown FAR* pcmdtReserved, IDispatch FAR* pdispReserved);       
	STDMETHODIMP GetHostInfo(DOCHOSTUIINFO FAR *pInfo);        
	STDMETHODIMP ShowUI(DWORD dwID, IOleInPlaceActiveObject FAR* pActiveObject,
					IOleCommandTarget FAR* pCommandTarget,
					IOleInPlaceFrame  FAR* pFrame,
					IOleInPlaceUIWindow FAR* pDoc);
	STDMETHODIMP HideUI(void);        
	STDMETHODIMP UpdateUI(void);        
	STDMETHODIMP EnableModeless(BOOL fEnable);   
	STDMETHODIMP OnDocWindowActivate(BOOL fActivate);   
	STDMETHODIMP OnFrameWindowActivate(BOOL fActivate);   
	STDMETHODIMP ResizeBorder(LPCRECT prcBorder, IOleInPlaceUIWindow FAR* pUIWindow,BOOL fRameWindow);   
	STDMETHODIMP TranslateAccelerator(LPMSG lpMsg, const GUID FAR* pguidCmdGroup,DWORD nCmdID);   
	STDMETHODIMP GetOptionKeyPath(LPOLESTR *pchKey, DWORD dw);   
	STDMETHODIMP GetDropTarget(IDropTarget* pDropTarget, IDropTarget** ppDropTarget);   
	// 
	// Method called by the WebBrowser control when
	// you call window.external.SayHello from script
	//
	STDMETHODIMP GetExternal(IDispatch** ppDispatch);   
	STDMETHODIMP TranslateUrl(DWORD dwTranslate, OLECHAR* pchURLIn,OLECHAR** ppchURLOut);
	//Called by MSHTML to allow the host to replace the MSHTML data object.
	STDMETHODIMP FilterDataObject(IDataObject* pDO, IDataObject** ppDORet);

	//IDocHostUIHandler2
	STDMETHODIMP GetOverrideKeyPath( 
            /* [out] */ LPOLESTR *pchKey,
            /* [in] */ DWORD dw);

	long m_ContextMenuAction;
	DWORD m_dwDocHostUIFlags;
	DWORD m_dwDocHostUIDblClk;

private:
    IWB *m_pHost;
	//For DragDrop notifications
	WBDropTarget *m_pWBDropTarget;
	VARIANT_BOOL m_bhandled;
	short m_nVirtExtKey;
	short m_nKeyCode;
	HRESULT m_hr;
};

#ifndef _WIN32_WCE
///////////////////////////////////////////////////////////////////////
///////////WBDownLoadManager
///////////////////////////////////////////////////////////////////////
class WBDownLoadManager : 
		public CComObjectRootEx<CComSingleThreadModel>,
		public IDownloadManager
{
public:
	WBDownLoadManager();
	~WBDownLoadManager();

BEGIN_COM_MAP(WBDownLoadManager)
	COM_INTERFACE_ENTRY(IDownloadManager)
END_COM_MAP()

	// *** IDownloadManager ***
	STDMETHODIMP Download(IMoniker *pmk,IBindCtx *pbc,DWORD dwBindVerb,
										LONG grfBINDF,
										BINDINFO *pBindInfo,
										LPCOLESTR pszHeaders,
										LPCOLESTR pszRedir,
										UINT uiCP);
	//To initialize class
	HRESULT InitDownloadManager(IWB* pFrameSite);

private:
	IWB *m_pHost;
	HWND m_hwndIEServer;
};
#endif

///////////////////////////////////////////////////////////////////////
///////////WBServiceProvider
///////////////////////////////////////////////////////////////////////
class WBServiceProvider : public IServiceProvider
{
public:
	WBServiceProvider(IWB* pFrameSite);
	~WBServiceProvider();

    // IUnknown
    ULONG STDMETHODCALLTYPE AddRef();
    ULONG STDMETHODCALLTYPE Release();
    STDMETHODIMP QueryInterface(REFIID iid, void ** ppvObject);

	//QueryService
	STDMETHODIMP QueryService(REFGUID guidService,REFIID riid,void **ppv);

private:
	IWB *m_pHost;
};

///////////////////////////////////////////////////////////////////////
///////////WBDocHostShowUI
///////////////////////////////////////////////////////////////////////
class WBDocHostShowUI : public IDocHostShowUI
{
public:
	WBDocHostShowUI(IWB* pFrameSite);
	~WBDocHostShowUI();

    // IUnknown
    STDMETHODIMP QueryInterface(REFIID iid, void ** ppvObject);
    ULONG STDMETHODCALLTYPE AddRef();
    ULONG STDMETHODCALLTYPE Release();

	STDMETHODIMP ShowHelp(HWND hwnd,LPOLESTR pszHelpFile,
							UINT uCommand,DWORD dwData,POINT ptMouse,
							IDispatch *pDispatchObjectHit);

	STDMETHODIMP ShowMessage(HWND hwnd, LPOLESTR lpstrText, LPOLESTR lpstrCaption,
							    DWORD dwType,LPOLESTR lpstrHelpFile,
								DWORD dwHelpContext, LRESULT *plResult);

private:
	IWB *m_pHost;
};

///////////////////////////////////////////////////////////////////////
///////////WBOleCommandTarget
//////////A class just to stop script errors. Other option to use registry
///////////////////////////////////////////////////////////////////////
class WBOleCommandTarget : public IOleCommandTarget
{
public:
	WBOleCommandTarget(IWB* pFrameSite);
	~WBOleCommandTarget();

    // IUnknown
    STDMETHODIMP QueryInterface(REFIID iid, void ** ppvObject);
    ULONG STDMETHODCALLTYPE AddRef();
    ULONG STDMETHODCALLTYPE Release();

	//IOleCommandTarget Methods
	STDMETHODIMP QueryStatus(const GUID *pguidCmdGroup, ULONG cCmds,
						OLECMD prgCmds[], OLECMDTEXT *pCmdText);
	STDMETHODIMP Exec(const GUID *pguidCmdGroup, DWORD nCmdID,
				DWORD nCmdExecOpt, VARIANT *pvaIn, VARIANT *pvaOut);

//	long  m_lScriptError;

private:
	IWB* m_pHost;
};

///////////////////////////////////////////////////////////////////////
///////////A simple download manager with resume capabilities
///////////Used for downloads initiated by user via a link click or us
///////////by calling DownloadUrlAsync
////////////////////////////////////////////////////////////////////////
class WBBSCBFileDL : 
		public IBindStatusCallback, 
		public IHttpNegotiate
{
public:
	WBBSCBFileDL();
	WBBSCBFileDL(short iID);
	~WBBSCBFileDL();

    // IUnknown
    ULONG STDMETHODCALLTYPE AddRef();
    ULONG STDMETHODCALLTYPE Release();
    STDMETHODIMP QueryInterface(REFIID iid, void ** ppvObject);

	//IBindStatusCallback
    STDMETHODIMP OnStartBinding(DWORD dwReserved, IBinding * pib);
    STDMETHODIMP GetPriority(LONG * pnPriority);
    STDMETHODIMP OnLowResource(DWORD reserved);
    STDMETHODIMP OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText);
    STDMETHODIMP OnStopBinding(HRESULT hresult,LPCWSTR szError);
    STDMETHODIMP GetBindInfo(DWORD *grfBINDF, BINDINFO * pbindinfo);
    STDMETHODIMP OnDataAvailable(DWORD grfBSCF, DWORD dwSize, FORMATETC* pformatetc, STGMEDIUM* pstgmed);
    STDMETHODIMP OnObjectAvailable(REFIID riid,IUnknown* punk);

	// IHttpNegotiate methods
    STDMETHODIMP BeginningTransaction(
                LPCWSTR szURL,
                LPCWSTR szHeaders,
                DWORD dwReserved,
                LPWSTR *pszAdditionalHeaders);

    STDMETHODIMP OnResponse(
                DWORD dwResponseCode,
                LPCWSTR szResponseHeaders,
                LPCWSTR szRequestHeaders,
                LPWSTR *pszAdditionalRequestHeaders);

	//Class specific
	bool InitByClient(CvbWB *EventsPtr, BSTR lpUrl, BSTR lpPathToSave);
	bool InitByUser(IWB *pHost, LPCOLESTR UrlMonExtraHeaders);

	bool CancelDL(void);
	bool IsDownloading(void);
	//UID of this instance
	short m_Uid;
	//Previous BSCB before we used RegisterBindStatuscallback
	IBindStatusCallback *m_pPrevBSCB;
	IBindCtx			*m_pBindCtx;

private:
	ULONG				m_cRef;
	BOOL				m_fRedirect; // need to be informed when we're being redirected by the server
	short				m_hostid;


	IBinding			*m_pBinding;
	LPSTREAM			m_pstm;
	//Path with backslash m_bstr
	CComBSTR			fPathToSave;
	//File name
	CComBSTR			fFileName;
	CComBSTR			fFileExt;
	//Contains URL
	//This can change if we receive a redirect in onprogress
	CComBSTR			fUrl;
	CComBSTR			m_strRedirectedURL;
	CComBSTR			m_strDLManExtraHeaders;
	//This is the full path (Path+filename) of save target file
	//If we receive a redirect in BeginningTranscaction, URL will change
	CComBSTR			fFullSavePath;
	//To write to file
	DWORD				m_cbOld;
	HANDLE				hFile;
	//This flag is used to send/not progress events
	//decided to have it to avoid unnecessary events fired
	//when client does not care to have them
	VARIANT_BOOL		m_SendProgressEvent;
	//To relay events
	CvbWB				*m_Events;
	IWB					*m_pHost;
	//To make sure we have a client to send info to
	//This is needed since we can end our app while URLMon
	//is using this class to continue download. Independent of
	//our app. Cool.
	HWND				m_hwndEvents;
	//To get client return value for Cancel
	VARIANT_BOOL		m_vboolCancelDL;
	BOOL				m_bCancelled;
	VARIANT_BOOL		m_vboolResuming;
	//To reset internal vars since we are reusing this class
	void ResetInternalVars(void);
};

///////////////////////////////////////////////////////////////////////
//WBSecurityManager
///////////////////////////////////////////////////////////////////////		
//The Internet Security Manager calls the QueryInterface method on MSHTML
//to get its IServiceProvider interface. MSHTML then calls the QueryInterface
//method on the IOleClientSite interface to get the IServiceProvider interface.
class WBSecurityManager : public IInternetSecurityManager
{
public:
	WBSecurityManager(IWB* pFrameSite);
	~WBSecurityManager();

	// *** IUnknown ***
    STDMETHODIMP QueryInterface(REFIID iid, void ** ppvObject);
    ULONG STDMETHODCALLTYPE AddRef();
	ULONG STDMETHODCALLTYPE Release();

	STDMETHODIMP SetSecuritySite(IInternetSecurityMgrSite  *pSite);
	STDMETHODIMP GetSecuritySite(IInternetSecurityMgrSite  **ppSite);      
    STDMETHODIMP MapUrlToZone( LPCWSTR pwszUrl, DWORD  *pdwZone, DWORD dwFlags);
    STDMETHODIMP GetSecurityId( 
         LPCWSTR pwszUrl,
         BYTE  *pbSecurityId,
         DWORD  *pcbSecurityId,
         DWORD dwReserved);
    
	//Only function that we are interested in overloading
	//Determines the policy for the specified action and displays a user
	//interface if the policy indicates that the user should be queried.
    STDMETHODIMP ProcessUrlAction( 
         LPCWSTR pwszUrl,
         DWORD dwAction,
         BYTE  *pPolicy,
         DWORD cbPolicy,
         BYTE  *pContext,
         DWORD cbContext,
         DWORD dwFlags,
         DWORD dwReserved);

    STDMETHODIMP QueryCustomPolicy( 
         LPCWSTR pwszUrl,
         REFGUID guidKey,
         BYTE  **ppPolicy,
         DWORD  *pcbPolicy,
         BYTE  *pContext,
         DWORD cbContext,
         DWORD dwReserved);

    STDMETHODIMP SetZoneMapping( 
         DWORD dwZone,
         LPCWSTR lpszPattern,
         DWORD dwFlags);

    STDMETHODIMP GetZoneMappings( 
         DWORD dwZone,
         IEnumString  **ppenumString,
         DWORD dwFlags);

private:
	IWB *m_pHost; 
};

//////////////////////////////////////////////
//class WBAuthenticate
//Callback interface for problems with application installations or file downloads.
//////////////////////////////////////////////
//Mshtml.dll will request a pointer to the client application's implementation of
//IAuthenticate interface by calling QueryInterface on the client application's
//IServiceProvider interface.
class WBAuthenticate : public IAuthenticate
{
public:
	WBAuthenticate(IWB* pFrameSite);
	~WBAuthenticate();

	// *** IUnknown ***
    STDMETHODIMP QueryInterface(REFIID iid, void ** ppvObject);
    ULONG STDMETHODCALLTYPE AddRef();
	ULONG STDMETHODCALLTYPE Release();
	
	//IAuthenticate
	
	//Applications that implement the IAuthenticate::Authenticate method must allocate
	//the memory of the pszUsername and pszPassword buffers using CoTaskMemAlloc. 
	
	//Returns one of the following values:;
	//S_OK Authentication was successful. 
	//E_ACCESSDENIED Authentication failed. 
	//E_INVALIDARG One or more parameters are invalid.
	//Currently, the user name and password options handle only
	//the Basic authentication scheme and N..
	STDMETHODIMP Authenticate(HWND *phwnd, LPWSTR *pszUsername, LPWSTR *pszPassword);

private:
	IWB *m_pHost;
};

//////////////////////////////////////////////
//class IHttpSecurity
//This interface notifies a client application of authentication problems.
//////////////////////////////////////////////
//Mshtml.dll will request a pointer to your IHttpSecurity interface by calling
//QueryInterface on your IServiceProvider interface.
class WBHttpSecurity : public IHttpSecurity
{
public:
	WBHttpSecurity(IWB* pFrameSite);
	~WBHttpSecurity();

	// *** IUnknown ***
    STDMETHODIMP QueryInterface(REFIID iid, void ** ppvObject);
    ULONG STDMETHODCALLTYPE AddRef();
	ULONG STDMETHODCALLTYPE Release();
	
	//IWindowForBindingUI
	//If you implement this interface, you can return S_FALSE for this method to
	//indicate that no window is available for displaying user interface information.
	//rguidReason = Identifier that indicates the reason for the user interface.
	//This can be either IID_IAuthenticate or IID_IHttpSecurity.
	STDMETHODIMP GetWindow(REFGUID rguidReason,HWND *phwnd);
	//IHttpSecurity
	//Some possible problems
	/*
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
	STDMETHODIMP OnSecurityProblem(DWORD dwProblem);
private:
	IWB *m_pHost;
};

//////////////////////////////////////////////
//IWindowForBindingUI
//////////////////////////////////////////////
class WBWindowForBindingUI : public IWindowForBindingUI
{
public:
	WBWindowForBindingUI(IWB* pFrameSite);
	~WBWindowForBindingUI();

	// *** IUnknown ***
	STDMETHODIMP QueryInterface(REFIID iid, void ** ppvObject);
	ULONG STDMETHODCALLTYPE AddRef();
	ULONG STDMETHODCALLTYPE Release();

	//Must return IE Server Hwnd
	HRESULT STDMETHODCALLTYPE GetWindow( 
	/* [in] */ REFGUID rguidReason, 
	/* [out] */ HWND *phwnd);
private:
	IWB *m_pHost;
};

/*
Note that the client does not know nor care where the bytes come from. 
It does not matter in the slightest whether the object internally stores 
the data global memory, or memory allocated with new, or reads it from 
the file on disk, or from network socket, or generates it on the fly 
with e.g. a random number generator. The whole point of IStream is to 
hide any source of binary data behind a uniform interface. 
*/

///////////////////////////////////////////////////
//
//WBStream - For uploading file with progress
//when submitting a form with <input type="file">
//
///////////////////////////////////////////////////
class WBStream : public IStream
{
public:
	WBStream();
	~WBStream();

	void InitWBStreamData(short iID, CvbWB *pHost,WBBSCBUpload *lpParent, 
							BSTR URL, void *pvBuffer, ULONG uSize);

	void InitWBStreamFileName(short iID, CvbWB *pHost,WBBSCBUpload *lpParent, 
							BSTR URL, HANDLE hFile, ULONG uFileSize);

    // IUnknown
    STDMETHODIMP QueryInterface(REFIID iid, void ** ppvObject);
    ULONG STDMETHODCALLTYPE AddRef();
    ULONG STDMETHODCALLTYPE Release();

// ISequentialStream
    HRESULT STDMETHODCALLTYPE Read(
        /* [length_is][size_is][out] */ void *pv,
        /* [in] */ ULONG cb,
        /* [out] */ ULONG *pcbRead);

    HRESULT STDMETHODCALLTYPE Write(
        /* [size_is][in] */ const void *pv,
        /* [in] */ ULONG cb,
        /* [out] */ ULONG *pcbWritten)
	{ 	// Not needed.
		return E_NOTIMPL;
	}

// IStream
    HRESULT STDMETHODCALLTYPE Seek(
        /* [in] */ LARGE_INTEGER dlibMove,
        /* [in] */ DWORD dwOrigin,
        /* [out] */ ULARGE_INTEGER *plibNewPosition)
	{
		return E_NOTIMPL;
	}

    HRESULT STDMETHODCALLTYPE SetSize(
        /* [in] */ ULARGE_INTEGER libNewSize)
	{
		return E_NOTIMPL;
	}

    HRESULT STDMETHODCALLTYPE CopyTo(
        /* [unique][in] */ IStream *pstm,
        /* [in] */ ULARGE_INTEGER cb,
        /* [out] */ ULARGE_INTEGER *pcbRead,
        /* [out] */ ULARGE_INTEGER *pcbWritten)
	{
		return E_NOTIMPL;
	}

    HRESULT STDMETHODCALLTYPE Commit(
        /* [in] */ DWORD grfCommitFlags)
	{
		return E_NOTIMPL;
	}

    HRESULT STDMETHODCALLTYPE Revert( void)
	{
		return E_NOTIMPL;
	}

    HRESULT STDMETHODCALLTYPE LockRegion(
        /* [in] */ ULARGE_INTEGER libOffset,
        /* [in] */ ULARGE_INTEGER cb,
        /* [in] */ DWORD dwLockType)
	{
		return E_NOTIMPL;
	}

    HRESULT STDMETHODCALLTYPE UnlockRegion(
        /* [in] */ ULARGE_INTEGER libOffset,
        /* [in] */ ULARGE_INTEGER cb,
        /* [in] */ DWORD dwLockType)
	{
		return E_NOTIMPL;
	}

    HRESULT STDMETHODCALLTYPE Stat(
        /* [out] */ STATSTG *pstatstg,
        /* [in] */ DWORD grfStatFlag)
	{
		return E_NOTIMPL;
	}

    HRESULT STDMETHODCALLTYPE Clone(
        /* [out] */ IStream **ppstm)
	{
		return E_NOTIMPL;
	}
	
private:
	//UID of this instance
	short			m_Uid;
	CComBSTR		fUrl;
	CvbWB			*m_Events;
	HWND			m_hwndEvents;
	ULONG			m_cRef;
	HANDLE			m_hFile;
	char*			m_pcBuffer;		//ptr to upload buffer
	ULONG			m_uBufferSize;	//upload buffer size
	ULONG			m_uFilePos;		//last read pos
	WBBSCBUpload	*m_lpParent;
};

///////////////////////////////////////////////////////////////////////
//
//WBBSCBPost
//
/*
One possible sequence of events:

  IBindStatusCallback.GetBindInfo
  IBindStatusCallback.OnStartBinding
  IHttpNegotiate.BeginningTransaction
  IBindStatusCallback.OnProgress: Unknown status
  IBindStatusCallback.OnProgress: Finding resource
  IBindStatusCallback.OnProgress: Connecting
  IBindStatusCallback.OnProgress: Sending request
  IHttpNegotiate.OnResponse: 200 OK
  IBindStatusCallback.OnProgress: MIME type available
  IBindStatusCallback.OnProgress: Beginning to download data
  IBindStatusCallback.OnProgress: Ending data download
  IBindStatusCallback.OnDataAvailable: the ASP script's reply shows POST
data is received
  IBindStatusCallback.OnStopBinding
  Class gets Release()d
*/
////////////////////////////////////////////////////////////////////////
class WBBSCBPost : 
		public IBindStatusCallback, 
		public IHttpNegotiate
{
public:
	WBBSCBPost();
	~WBBSCBPost();

    // IUnknown
    ULONG STDMETHODCALLTYPE AddRef();
    ULONG STDMETHODCALLTYPE Release();
    STDMETHODIMP QueryInterface(REFIID iid, void ** ppvObject);

	//IBindStatusCallback
    STDMETHODIMP OnStartBinding(DWORD dwReserved, IBinding * pib);
    STDMETHODIMP GetPriority(LONG * pnPriority);
    STDMETHODIMP OnLowResource(DWORD reserved);
    STDMETHODIMP OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText);
    STDMETHODIMP OnStopBinding(HRESULT hresult,LPCWSTR szError);
    STDMETHODIMP GetBindInfo(DWORD *grfBINDF, BINDINFO * pbindinfo);
    STDMETHODIMP OnDataAvailable(DWORD grfBSCF, DWORD dwSize, FORMATETC* pformatetc, STGMEDIUM* pstgmed);
    STDMETHODIMP OnObjectAvailable(REFIID riid,IUnknown* punk);

	// IHttpNegotiate methods
    STDMETHODIMP BeginningTransaction(
                LPCWSTR szURL,
                LPCWSTR szHeaders,
                DWORD dwReserved,
                LPWSTR *pszAdditionalHeaders);

    STDMETHODIMP OnResponse(
                DWORD dwResponseCode,
                LPCWSTR szResponseHeaders,
                LPCWSTR szRequestHeaders,
                LPWSTR *pszAdditionalRequestHeaders);

	HRESULT InitPost(short iID, CvbWB *pHost, BSTR URL, LPCTSTR szData);
	void CancelPost();

private:
	//UID of this instance
	short				m_Uid;
	ULONG				m_cRef;
	HGLOBAL				m_hDataToPost; // data that we're going to post
	DWORD				m_cbDataToPost;
	BINDVERB			m_dwAction;
	BOOL				m_fRedirect; // need to be informed when we're being redirected by the server

	IBinding			*m_pBinding;
	//used when a post turns into a get
	//due to a redirect and data starts
	//to arrive
	LPSTREAM			m_pstm;
	DWORD				m_cbOld;
	//URL
	CComBSTR			fUrl;
	CvbWB				*m_Events;
	HWND				m_hwndEvents;
	VARIANT_BOOL		m_vboolCancel;
	long				m_lprogress;
	long				m_lprogressmax;
	long				m_lstatuscode;
	CComBSTR			m_stattext;
};

////////////////////////////////////////////////////////////////////////
class WBBSCBUpload : 
		public IBindStatusCallback, 
		public IHttpNegotiate
{
public:
	WBBSCBUpload();
	~WBBSCBUpload();

    // IUnknown
    ULONG STDMETHODCALLTYPE AddRef();
    ULONG STDMETHODCALLTYPE Release();
    STDMETHODIMP QueryInterface(REFIID iid, void ** ppvObject);

	//IBindStatusCallback
    STDMETHODIMP OnStartBinding(DWORD dwReserved, IBinding * pib);
    STDMETHODIMP GetPriority(LONG * pnPriority);
    STDMETHODIMP OnLowResource(DWORD reserved);
    STDMETHODIMP OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText);
    STDMETHODIMP OnStopBinding(HRESULT hresult,LPCWSTR szError);
    STDMETHODIMP GetBindInfo(DWORD *grfBINDF, BINDINFO * pbindinfo);
    STDMETHODIMP OnDataAvailable(DWORD grfBSCF, DWORD dwSize, FORMATETC* pformatetc, STGMEDIUM* pstgmed);
    STDMETHODIMP OnObjectAvailable(REFIID riid,IUnknown* punk);

	// IHttpNegotiate methods
    STDMETHODIMP BeginningTransaction(
                LPCWSTR szURL,
                LPCWSTR szHeaders,
                DWORD dwReserved,
                LPWSTR *pszAdditionalHeaders);

    STDMETHODIMP OnResponse(
                DWORD dwResponseCode,
                LPCWSTR szResponseHeaders,
                LPCWSTR szRequestHeaders,
                LPWSTR *pszAdditionalRequestHeaders);

	HRESULT InitUpload(short iID, CvbWB *pHost, BSTR URL, void *pvBuffer, ULONG uSize);
	HRESULT InitUploadFile(short iID, CvbWB *pHost, BSTR URL, LPCTSTR sFileName);
	void CancelUpload();

private:
	//UID of this instance
	short				m_Uid;
	ULONG				m_cRef;
	DWORD				m_ulDataSize;
	BINDVERB			m_dwAction;
	BOOL				m_fRedirect; // need to be informed when we're being redirected by the server

	IBinding			*m_pBinding;
	//used when a post turns into a get
	//due to a redirect and data starts
	//to arrive
	LPSTREAM			m_pstm;
	WBStream			*m_stPostData;
	DWORD				m_cbOld;
	//URL
	CComBSTR			fUrl;
	CvbWB				*m_Events;
	HWND				m_hwndEvents;
	VARIANT_BOOL		m_vboolCancel;
	long				m_lprogress;
	long				m_lprogressmax;
	long				m_lstatuscode;
	CComBSTR			m_stattext;
	HANDLE				m_hFile;
	void				*m_lpBuffer;
};

//////////////////////////////////////////////////////////////////////////////////////////////
class WBIHTMLOMWindowServices : IHTMLOMWindowServices
{
public:
	WBIHTMLOMWindowServices(IWB* pFrameSite);
	~WBIHTMLOMWindowServices();

    // IUnknown
	// *** IUnknown ***
    STDMETHODIMP QueryInterface(REFIID iid, void ** ppvObject);
    ULONG STDMETHODCALLTYPE AddRef();
	ULONG STDMETHODCALLTYPE Release();

	//IHTMLOMWindowServices
	STDMETHODIMP moveTo( LONG x, LONG y);
	STDMETHODIMP moveBy( LONG x, LONG y);
	STDMETHODIMP resizeTo( LONG x, LONG y);
	STDMETHODIMP resizeBy( LONG x, LONG y);

private:
	IWB	*m_pHost;
};

//////////////////////////////////////////////////////////////////////////////////////////////
//
/*
Problem:

Loading HTML content from stream using IPersistStreamInit causes
the base URL to always be "about:blank"

Solution:

Another way is to write a custom implementation of IMoniker interface. 
You only need a non-trivial implementation of two methods: BindToStorage 
should return the IStream with your HTML content, and GetDisplayName 
should return the base URL you want to use to resolve relative links. 
You then use IPersistMoniker to feed the content into MSHTML using this 
custom implementation, instead of IPersistStreamInit. Igor
*/
//Except for BindToStorage and GetDisplayName methods
//All other methods return E_NOTIMPL
//////////////////////////////////////////////////////////////////////////////////////////////

class CLoadHTMLMoniker : public IMoniker
{
public:

	CLoadHTMLMoniker() { m_cRef = 1; } //We delete this ourselves
	~CLoadHTMLMoniker() { }
    // IUnknown
    ULONG STDMETHODCALLTYPE AddRef() { return ++m_cRef; }
    ULONG STDMETHODCALLTYPE Release()
	{
		if(--m_cRef == 0)
		{
			delete this;
			return 0;
		}
		return m_cRef;
	}

    STDMETHODIMP QueryInterface(REFIID iid, void ** ppvObject)
	{
		if(ppvObject == NULL) return E_INVALIDARG;
		*ppvObject = NULL;

		if( iid==IID_IMoniker )
		{
		   *ppvObject = (IMoniker*)this;
		}

		if (NULL != *ppvObject)
		{
			AddRef();
			return S_OK;
		}
		return E_NOINTERFACE;
	}

    STDMETHODIMP BindToObject( 
        /* [unique][in] */ IBindCtx *pbc,
        /* [unique][in] */ IMoniker *pmkToLeft,
        /* [in] */ REFIID riidResult,
        /* [iid_is][out] */ void **ppvResult) { return E_NOTIMPL; }
        
    STDMETHODIMP BindToStorage( 
        /* [unique][in] */ IBindCtx *pbc,
        /* [unique][in] */ IMoniker *pmkToLeft,
        /* [in] */ REFIID riid,
        /* [iid_is][out] */ void **ppvObj)
	{
		// NB: only IID_IStream seems to be used
		return m_spStream->QueryInterface(riid, ppvObj);
	}
        
    STDMETHODIMP Reduce( 
        /* [unique][in] */ IBindCtx *pbc,
        /* [in] */ DWORD dwReduceHowFar,
        /* [unique][out][in] */ IMoniker **ppmkToLeft,
        /* [out] */ IMoniker **ppmkReduced) { return E_NOTIMPL; }
    
    STDMETHODIMP ComposeWith( 
        /* [unique][in] */ IMoniker *pmkRight,
        /* [in] */ BOOL fOnlyIfNotGeneric,
        /* [out] */ IMoniker **ppmkComposite) { return E_NOTIMPL; }
    
    STDMETHODIMP Enum( 
        /* [in] */ BOOL fForward,
        /* [out] */ IEnumMoniker **ppenumMoniker) { return E_NOTIMPL; }
    
    STDMETHODIMP IsEqual( 
        /* [unique][in] */ IMoniker *pmkOtherMoniker) { return E_NOTIMPL; }
    
    STDMETHODIMP Hash( 
        /* [out] */ DWORD *pdwHash) { return E_NOTIMPL; }
    
    STDMETHODIMP IsRunning( 
        /* [unique][in] */ IBindCtx *pbc,
        /* [unique][in] */ IMoniker *pmkToLeft,
        /* [unique][in] */ IMoniker *pmkNewlyRunning) { return E_NOTIMPL; }
    
    STDMETHODIMP GetTimeOfLastChange( 
        /* [unique][in] */ IBindCtx *pbc,
        /* [unique][in] */ IMoniker *pmkToLeft,
        /* [out] */ FILETIME *pFileTime) { return E_NOTIMPL; }
    
    STDMETHODIMP Inverse( 
        /* [out] */ IMoniker **ppmk) { return E_NOTIMPL; }
    
    STDMETHODIMP CommonPrefixWith( 
        /* [unique][in] */ IMoniker *pmkOther,
        /* [out] */ IMoniker **ppmkPrefix) { return E_NOTIMPL; }
    
    STDMETHODIMP RelativePathTo( 
        /* [unique][in] */ IMoniker *pmkOther,
        /* [out] */ IMoniker **ppmkRelPath) { return E_NOTIMPL; }
    
    STDMETHODIMP GetDisplayName( 
        /* [unique][in] */ IBindCtx *pbc,
        /* [unique][in] */ IMoniker *pmkToLeft,
        /* [out] */ LPOLESTR *ppszDisplayName)
	{ 
		if (!ppszDisplayName) return E_INVALIDARG;  

		CComPtr<IMalloc> spMalloc;
		CoGetMalloc(1, &spMalloc);
		if (m_strBaseURL.Length()) 
		{
			UINT cchCommandText = sizeof(OLECHAR) * (m_strBaseURL.Length() + 1);
			*ppszDisplayName = (OLECHAR*) spMalloc->Alloc( cchCommandText );
			if(*ppszDisplayName != NULL)
			{
				memcpy(*ppszDisplayName, m_strBaseURL, cchCommandText);
				*(*ppszDisplayName + m_strBaseURL.Length()) = (OLECHAR)NULL;
				return S_OK;
			}
		}

		*ppszDisplayName = NULL;
		return E_NOTIMPL; 
	}
        
    STDMETHODIMP ParseDisplayName( 
        /* [unique][in] */ IBindCtx *pbc,
        /* [unique][in] */ IMoniker *pmkToLeft,
        /* [in] */ LPOLESTR pszDisplayName,
        /* [out] */ ULONG *pchEaten,
        /* [out] */ IMoniker **ppmkOut) { return E_NOTIMPL; }
    
    STDMETHODIMP IsSystemMoniker( 
        /* [out] */ DWORD *pdwMksys) { return E_NOTIMPL; }

//IPersistStream
        STDMETHODIMP  IsDirty( void) { return E_NOTIMPL; }
        
        STDMETHODIMP  Load( 
            /* [unique][in] */ IStream *pStm) { return E_NOTIMPL; }
        
        STDMETHODIMP  Save( 
            /* [unique][in] */ IStream *pStm,
            /* [in] */ BOOL fClearDirty) { return E_NOTIMPL; }
        
        STDMETHODIMP  GetSizeMax( 
            /* [out] */ ULARGE_INTEGER *pcbSize) { return E_NOTIMPL; }
//IPersist
        STDMETHODIMP GetClassID( 
            /* [out] */ CLSID *pClassID) { return E_NOTIMPL; }

	/////////////////////////////////////////////// 
	// init the moniker object 
	HRESULT SetHTML(BSTR pszHTML, BSTR pszBaseURL) 
	{ 
		m_strBaseURL = pszBaseURL; 
		m_spStream.Release(); 

		UINT len = ::SysStringLen(pszHTML);

		//Allocate global memory to copy the HTML content to
		//GPTR
		HGLOBAL hHTMLContent = ::GlobalAlloc(GMEM_ZEROINIT , 
					( len + 1 ) * sizeof(OLECHAR) ); 
		if (!hHTMLContent) 
			return E_FAIL; 
		memcpy(hHTMLContent, (void*)pszHTML, len * sizeof(OLECHAR));

		// mark this string as UNICODE 
		//((wchar_t*) hHTMLContent)[0] = 0xfeff; 
		//::wcscpy( ((wchar_t*) hHTMLContent)+1, pszHTML ); 

		CComPtr<IStream> spStream; 
		return ::CreateStreamOnHGlobal( hHTMLContent, 
							TRUE, &m_spStream );
	}

private:
	ULONG m_cRef;
	CComBSTR m_strBaseURL;
	CComPtr<IStream> m_spStream;
    };

//////////////////////////////////////////////////////////////////////////////////////////////
//WBPassthruSink
//To allow implementation of temp protocols, http, https,...
//Posted by Igor Tandetnik "itandetnik@mvps.org"
//Can be found using a search for PassthroughApp in google groups
//////////////////////////////////////////////////////////////////////////////////////////////
class WBPassthruSink :
	public PassthroughAPP::CInternetProtocolSinkWithSP<WBPassthruSink>,
	public IHttpNegotiate
{
	typedef PassthroughAPP::CInternetProtocolSinkWithSP<WBPassthruSink> BaseClass;
public:

	BEGIN_COM_MAP(WBPassthruSink)
		COM_INTERFACE_ENTRY(IHttpNegotiate)
		COM_INTERFACE_ENTRY_CHAIN(BaseClass)
	END_COM_MAP()

	BEGIN_SERVICE_MAP(WBPassthruSink)
		SERVICE_ENTRY(IID_IHttpNegotiate)
	END_SERVICE_MAP()


	STDMETHODIMP BeginningTransaction(
		/* [in] */ LPCWSTR szURL,
		/* [in] */ LPCWSTR szHeaders,
		/* [in] */ DWORD dwReserved,
		/* [out] */ LPWSTR *pszAdditionalHeaders);

	STDMETHODIMP OnResponse(
		/* [in] */ DWORD dwResponseCode,
		/* [in] */ LPCWSTR szResponseHeaders,
		/* [in] */ LPCWSTR szRequestHeaders,
		/* [out] */ LPWSTR *pszAdditionalRequestHeaders);

	HRESULT OnStart(LPCWSTR szUrl, IInternetProtocolSink *pOIProtSink,
		IInternetBindInfo *pOIBindInfo, DWORD grfPI, DWORD dwReserved,
		IInternetProtocol* pTargetProtocol);

	STDMETHODIMP ReportProgress(
		/* [in] */ ULONG ulStatusCode,
		/* [in] */ LPCWSTR szStatusText);

	STDMETHODIMP Switch(
		/* [in] */ PROTOCOLDATA *pProtocolData);

//private:
	CvbWB *m_pEvents;
	IWB *m_pHost;
//	CComPtr<IBindStatusCallback> spBSCB;
	short m_Hostid;
	CComBSTR m_strUrl;
	CComBSTR m_strRedirUrl;
	CComBSTR m_strRedirHeaders;
};

typedef PassthroughAPP::CustomSinkStartPolicy<WBPassthruSink>
	TestStartPolicy;

class WBPassthru :
	public PassthroughAPP::CInternetProtocol<TestStartPolicy>
{
/*
public:

	STDMETHODIMP Start(LPCWSTR szUrl, IInternetProtocolSink *pOIProtSink,
		IInternetBindInfo *pOIBindInfo, DWORD grfPI, DWORD dwReserved)
	{
		::MessageBox(GetDesktopWindow(), _T("Start"),_T("PassthroughAPP::CInternetProtocol"),MB_OK);
		ATLASSERT(m_spInternetProtocol != 0);
		if (!m_spInternetProtocol)
		{
			return E_UNEXPECTED;
		}
		return TestStartPolicy::OnStart(szUrl, pOIProtSink, pOIBindInfo, grfPI,
			dwReserved, m_spInternetProtocol);
	}
*/
};

#endif //__VBWB_H_

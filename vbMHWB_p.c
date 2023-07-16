

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Wed Sep 20 20:31:21 2006
 */
/* Compiler settings for C:\Mike\vbMHWB\vbMHWB.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */
#pragma warning( disable: 4211 )  /* redefine extent to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "vbMHWB.h"

#define TYPE_FORMAT_STRING_SIZE   1099                              
#define PROC_FORMAT_STRING_SIZE   5713                              
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   2            

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO INewWindowManager_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO INewWindowManager_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHTMLOMWindowServices_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHTMLOMWindowServices_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IvbWB_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IvbWB_ProxyInfo;

/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IvbWB_put_SourceOnDocComplete_Proxy( 
    IvbWB * This,
    /* [defaultvalue][in] */ short wbUID,
    /* [in] */ VARIANT_BOOL newVal)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[5130],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_OrganizeFavorites_Proxy( 
    IvbWB * This)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[5172],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_ViewIEOptions_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[5202],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_FindAndHighlightAllTextFrames_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [in] */ BSTR TextToFind,
    /* [in] */ VARIANT_BOOL bMatchWholeWord,
    /* [in] */ VARIANT_BOOL bMatchCase,
    /* [in] */ BSTR HighlightColor,
    /* [out][in] */ long *NumOfMatchsFound)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[5238],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_SetupWindowsHook_Proxy( 
    IvbWB * This,
    /* [in] */ WINDOWSHOOK_TYPES lHookType,
    /* [in] */ long hwndTargetWnd,
    /* [in] */ VARIANT_BOOL bStart,
    /* [out][in] */ long *lUWMHookMsgID)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[5304],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_HookProcNCode_Proxy( 
    IvbWB * This,
    /* [in] */ WINDOWSHOOK_TYPES lHookType,
    /* [out][in] */ long *nCode)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[5358],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_SetupCustomAutoComplete_Proxy( 
    IvbWB * This,
    /* [in] */ long hwndTarget,
    /* [in] */ VARIANT_BOOL IsTargetComboBox,
    /* [in] */ long lCustomAutoCompleteFlags,
    /* [in] */ VARIANT *varStringArray)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[5400],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_CustomAutoCompleteAddString_Proxy( 
    IvbWB * This,
    /* [in] */ long hwndTarget,
    /* [in] */ VARIANT_BOOL IsTargetComboBox,
    /* [in] */ BSTR strItem)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[5454],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_CustomAutoCompleteEnable_Proxy( 
    IvbWB * This,
    /* [in] */ long hwndTarget,
    /* [in] */ VARIANT_BOOL IsTargetComboBox,
    /* [in] */ VARIANT_BOOL bEnable)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[5502],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_QueryIERegistryOption_Proxy( 
    IvbWB * This,
    /* [in] */ long IeRegistryOptionsFlag,
    /* [in] */ VARIANT *varBuffer)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[5550],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_SetIERegistryOption_Proxy( 
    IvbWB * This,
    /* [in] */ long IeRegistryOptionsFlag,
    /* [in] */ VARIANT *varBuffer)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[5592],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_DecodeMime_Proxy( 
    IvbWB * This,
    /* [in] */ BSTR strToDecode,
    /* [out][in] */ BSTR *strDecoded)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[5634],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_DeleteIEFiles_Proxy( 
    IvbWB * This,
    /* [in] */ DELETE_IE_FILES_FLAGS enumWhichFiles)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[5676],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need a Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure EvaluateNewWindow */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x3 ),	/* 3 */
/*  8 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 10 */	NdrFcShort( 0x18 ),	/* 24 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pszUrl */

/* 24 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter pszName */

/* 30 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter pszUrlContext */

/* 36 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 38 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 40 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter pszFeatures */

/* 42 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 44 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 46 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter fReplace */

/* 48 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 50 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 52 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwFlags */

/* 54 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 56 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 58 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwUserActionTime */

/* 60 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 62 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 64 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 66 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 68 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 70 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure moveTo */

/* 72 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 74 */	NdrFcLong( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0x3 ),	/* 3 */
/* 80 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 82 */	NdrFcShort( 0x10 ),	/* 16 */
/* 84 */	NdrFcShort( 0x8 ),	/* 8 */
/* 86 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 88 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 90 */	NdrFcShort( 0x0 ),	/* 0 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter x */

/* 96 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 98 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 100 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter y */

/* 102 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 104 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 108 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 110 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure moveBy */

/* 114 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 116 */	NdrFcLong( 0x0 ),	/* 0 */
/* 120 */	NdrFcShort( 0x4 ),	/* 4 */
/* 122 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 124 */	NdrFcShort( 0x10 ),	/* 16 */
/* 126 */	NdrFcShort( 0x8 ),	/* 8 */
/* 128 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 130 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 136 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter x */

/* 138 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 140 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter y */

/* 144 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 146 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 148 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 150 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 152 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 154 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure resizeTo */

/* 156 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 158 */	NdrFcLong( 0x0 ),	/* 0 */
/* 162 */	NdrFcShort( 0x5 ),	/* 5 */
/* 164 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 166 */	NdrFcShort( 0x10 ),	/* 16 */
/* 168 */	NdrFcShort( 0x8 ),	/* 8 */
/* 170 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 172 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 178 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter x */

/* 180 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 182 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 184 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter y */

/* 186 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 188 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 192 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 194 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 196 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure resizeBy */

/* 198 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 200 */	NdrFcLong( 0x0 ),	/* 0 */
/* 204 */	NdrFcShort( 0x6 ),	/* 6 */
/* 206 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 208 */	NdrFcShort( 0x10 ),	/* 16 */
/* 210 */	NdrFcShort( 0x8 ),	/* 8 */
/* 212 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 214 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 220 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter x */

/* 222 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 224 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter y */

/* 228 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 230 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 232 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 234 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 236 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Count */

/* 240 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 242 */	NdrFcLong( 0x0 ),	/* 0 */
/* 246 */	NdrFcShort( 0x7 ),	/* 7 */
/* 248 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 252 */	NdrFcShort( 0x22 ),	/* 34 */
/* 254 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 256 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 262 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 264 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 266 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 268 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 270 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 272 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 274 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoveBrowser */

/* 276 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 278 */	NdrFcLong( 0x0 ),	/* 0 */
/* 282 */	NdrFcShort( 0x8 ),	/* 8 */
/* 284 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 286 */	NdrFcShort( 0x6 ),	/* 6 */
/* 288 */	NdrFcShort( 0x8 ),	/* 8 */
/* 290 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 292 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 298 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUIDToRemove */

/* 300 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 302 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 304 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 306 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 308 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 310 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Refresh */

/* 312 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 314 */	NdrFcLong( 0x0 ),	/* 0 */
/* 318 */	NdrFcShort( 0x9 ),	/* 9 */
/* 320 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 322 */	NdrFcShort( 0x6 ),	/* 6 */
/* 324 */	NdrFcShort( 0x8 ),	/* 8 */
/* 326 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 328 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 330 */	NdrFcShort( 0x0 ),	/* 0 */
/* 332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 334 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 336 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 338 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 340 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 342 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 344 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 346 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Stop */

/* 348 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 350 */	NdrFcLong( 0x0 ),	/* 0 */
/* 354 */	NdrFcShort( 0xa ),	/* 10 */
/* 356 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 358 */	NdrFcShort( 0x6 ),	/* 6 */
/* 360 */	NdrFcShort( 0x8 ),	/* 8 */
/* 362 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 364 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 370 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 372 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 374 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 376 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 378 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 380 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 382 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GoBack */

/* 384 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 386 */	NdrFcLong( 0x0 ),	/* 0 */
/* 390 */	NdrFcShort( 0xb ),	/* 11 */
/* 392 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 394 */	NdrFcShort( 0x6 ),	/* 6 */
/* 396 */	NdrFcShort( 0x8 ),	/* 8 */
/* 398 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 400 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 406 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 408 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 410 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 412 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 414 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 416 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 418 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GoForward */

/* 420 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 422 */	NdrFcLong( 0x0 ),	/* 0 */
/* 426 */	NdrFcShort( 0xc ),	/* 12 */
/* 428 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 430 */	NdrFcShort( 0x6 ),	/* 6 */
/* 432 */	NdrFcShort( 0x8 ),	/* 8 */
/* 434 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 436 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 440 */	NdrFcShort( 0x0 ),	/* 0 */
/* 442 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 444 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 446 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 448 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 450 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 452 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 454 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GoHome */

/* 456 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 458 */	NdrFcLong( 0x0 ),	/* 0 */
/* 462 */	NdrFcShort( 0xd ),	/* 13 */
/* 464 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 466 */	NdrFcShort( 0x6 ),	/* 6 */
/* 468 */	NdrFcShort( 0x8 ),	/* 8 */
/* 470 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 472 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 478 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 480 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 482 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 484 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 486 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 488 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 490 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure NavigateSimple */

/* 492 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 494 */	NdrFcLong( 0x0 ),	/* 0 */
/* 498 */	NdrFcShort( 0xe ),	/* 14 */
/* 500 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 502 */	NdrFcShort( 0x6 ),	/* 6 */
/* 504 */	NdrFcShort( 0x8 ),	/* 8 */
/* 506 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 508 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 512 */	NdrFcShort( 0x1 ),	/* 1 */
/* 514 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 516 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 518 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 520 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter URL */

/* 522 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 524 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 526 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 528 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 530 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 532 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_WebBrowser */

/* 534 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 536 */	NdrFcLong( 0x0 ),	/* 0 */
/* 540 */	NdrFcShort( 0xf ),	/* 15 */
/* 542 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 544 */	NdrFcShort( 0x6 ),	/* 6 */
/* 546 */	NdrFcShort( 0x8 ),	/* 8 */
/* 548 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 550 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 556 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 558 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 560 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 562 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 564 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 566 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 568 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 570 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 572 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 574 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_LocationURL */

/* 576 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 578 */	NdrFcLong( 0x0 ),	/* 0 */
/* 582 */	NdrFcShort( 0x10 ),	/* 16 */
/* 584 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 586 */	NdrFcShort( 0x6 ),	/* 6 */
/* 588 */	NdrFcShort( 0x8 ),	/* 8 */
/* 590 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 592 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 594 */	NdrFcShort( 0x1 ),	/* 1 */
/* 596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 598 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 600 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 602 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 604 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pURL */

/* 606 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 608 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 610 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 612 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 614 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 616 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Offline */

/* 618 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 620 */	NdrFcLong( 0x0 ),	/* 0 */
/* 624 */	NdrFcShort( 0x11 ),	/* 17 */
/* 626 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 628 */	NdrFcShort( 0x6 ),	/* 6 */
/* 630 */	NdrFcShort( 0x22 ),	/* 34 */
/* 632 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 634 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 640 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 642 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 644 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 646 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 648 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 650 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 652 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 654 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 656 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 658 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Offline */

/* 660 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 662 */	NdrFcLong( 0x0 ),	/* 0 */
/* 666 */	NdrFcShort( 0x12 ),	/* 18 */
/* 668 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 670 */	NdrFcShort( 0xc ),	/* 12 */
/* 672 */	NdrFcShort( 0x8 ),	/* 8 */
/* 674 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 676 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 682 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 684 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 686 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 688 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 690 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 692 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 694 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 696 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 698 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 700 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReadyState */

/* 702 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 704 */	NdrFcLong( 0x0 ),	/* 0 */
/* 708 */	NdrFcShort( 0x13 ),	/* 19 */
/* 710 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 712 */	NdrFcShort( 0x6 ),	/* 6 */
/* 714 */	NdrFcShort( 0x24 ),	/* 36 */
/* 716 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 718 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 724 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 726 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 728 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 730 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter plReadyState */

/* 732 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 734 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 736 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 738 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 740 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 742 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GoSearch */

/* 744 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 746 */	NdrFcLong( 0x0 ),	/* 0 */
/* 750 */	NdrFcShort( 0x14 ),	/* 20 */
/* 752 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 754 */	NdrFcShort( 0x6 ),	/* 6 */
/* 756 */	NdrFcShort( 0x8 ),	/* 8 */
/* 758 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 760 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 766 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 768 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 770 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 772 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 774 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 776 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 778 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Refresh2 */

/* 780 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 782 */	NdrFcLong( 0x0 ),	/* 0 */
/* 786 */	NdrFcShort( 0x15 ),	/* 21 */
/* 788 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 790 */	NdrFcShort( 0x6 ),	/* 6 */
/* 792 */	NdrFcShort( 0x8 ),	/* 8 */
/* 794 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 796 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 800 */	NdrFcShort( 0x20 ),	/* 32 */
/* 802 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 804 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 806 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 808 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter level */

/* 810 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 812 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 814 */	NdrFcShort( 0x430 ),	/* Type Offset=1072 */

	/* Return value */

/* 816 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 818 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 820 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Busy */

/* 822 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 824 */	NdrFcLong( 0x0 ),	/* 0 */
/* 828 */	NdrFcShort( 0x16 ),	/* 22 */
/* 830 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 832 */	NdrFcShort( 0x6 ),	/* 6 */
/* 834 */	NdrFcShort( 0x22 ),	/* 34 */
/* 836 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 838 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 844 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 846 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 848 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 850 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 852 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 854 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 856 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 858 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 860 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 862 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RegisterAsBrowser */

/* 864 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 866 */	NdrFcLong( 0x0 ),	/* 0 */
/* 870 */	NdrFcShort( 0x17 ),	/* 23 */
/* 872 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 874 */	NdrFcShort( 0x6 ),	/* 6 */
/* 876 */	NdrFcShort( 0x22 ),	/* 34 */
/* 878 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 880 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 886 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 888 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 890 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 892 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 894 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 896 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 898 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 900 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 902 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 904 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_RegisterAsBrowser */

/* 906 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 908 */	NdrFcLong( 0x0 ),	/* 0 */
/* 912 */	NdrFcShort( 0x18 ),	/* 24 */
/* 914 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 916 */	NdrFcShort( 0xc ),	/* 12 */
/* 918 */	NdrFcShort( 0x8 ),	/* 8 */
/* 920 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 922 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 928 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 930 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 932 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 934 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 936 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 938 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 940 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 942 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 944 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 946 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RegisterAsDropTarget */

/* 948 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 950 */	NdrFcLong( 0x0 ),	/* 0 */
/* 954 */	NdrFcShort( 0x19 ),	/* 25 */
/* 956 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 958 */	NdrFcShort( 0xc ),	/* 12 */
/* 960 */	NdrFcShort( 0x22 ),	/* 34 */
/* 962 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 964 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 970 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 972 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 974 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 976 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bUseIEDefault */

/* 978 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 980 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 982 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 984 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 986 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 988 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 990 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 992 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 994 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_RegisterAsDropTarget */

/* 996 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 998 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1002 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1004 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1006 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1008 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1010 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 1012 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1014 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1018 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1020 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1022 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1024 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bUseIEDefault */

/* 1026 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1028 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1030 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 1032 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1034 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1036 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1038 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1040 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1042 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Silent */

/* 1044 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1046 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1050 */	NdrFcShort( 0x1b ),	/* 27 */
/* 1052 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1054 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1056 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1058 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1060 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1062 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1064 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1066 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1068 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1070 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1072 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1074 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1076 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1078 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1080 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1082 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1084 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Silent */

/* 1086 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1088 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1092 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1094 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1096 */	NdrFcShort( 0xc ),	/* 12 */
/* 1098 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1100 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1102 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1108 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1110 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1112 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1114 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 1116 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1118 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1120 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1122 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1124 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1126 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_LocationName */

/* 1128 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1130 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1134 */	NdrFcShort( 0x1d ),	/* 29 */
/* 1136 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1138 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1140 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1142 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1144 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1146 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1150 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1152 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1154 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1156 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1158 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1160 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1162 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 1164 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1166 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1168 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SelectAll */

/* 1170 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1172 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1176 */	NdrFcShort( 0x1e ),	/* 30 */
/* 1178 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1180 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1182 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1184 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1186 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1192 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1194 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1196 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1198 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1200 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1202 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1204 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Paste */

/* 1206 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1208 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1212 */	NdrFcShort( 0x1f ),	/* 31 */
/* 1214 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1216 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1218 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1220 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1222 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1228 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1230 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1232 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1234 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1236 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1238 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1240 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Copy */

/* 1242 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1244 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1248 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1250 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1252 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1254 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1256 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1258 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1264 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1266 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1268 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1270 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1272 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1274 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Cut */

/* 1278 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1280 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1284 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1286 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1288 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1290 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1292 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1294 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1300 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1302 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1304 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1306 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1308 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1310 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1312 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Undo */

/* 1314 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1316 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1320 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1322 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1324 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1326 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1328 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1330 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1336 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1338 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1340 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1342 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1344 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1346 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1348 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Redo */

/* 1350 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1352 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1356 */	NdrFcShort( 0x23 ),	/* 35 */
/* 1358 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1360 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1362 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1364 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1366 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1372 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1374 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1376 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1378 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1380 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1382 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ClearSelection */

/* 1386 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1388 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1392 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1394 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1396 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1398 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1400 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1402 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1408 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1410 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1412 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1414 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1416 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1418 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1420 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Delete */

/* 1422 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1424 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1428 */	NdrFcShort( 0x25 ),	/* 37 */
/* 1430 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1432 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1434 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1436 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1438 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1440 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1444 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1446 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1448 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1450 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1452 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1454 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1456 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Find */

/* 1458 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1460 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1464 */	NdrFcShort( 0x26 ),	/* 38 */
/* 1466 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1468 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1470 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1472 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1474 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1480 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1482 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1484 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1486 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1488 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1490 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1492 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PasteSpecial */

/* 1494 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1496 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1500 */	NdrFcShort( 0x27 ),	/* 39 */
/* 1502 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1504 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1506 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1508 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1510 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1516 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1518 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1520 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1522 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1524 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1526 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1528 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Spell */

/* 1530 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1532 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1536 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1538 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1540 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1542 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1544 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1546 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1552 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1554 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1556 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1558 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1560 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1562 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1564 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Properties */

/* 1566 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1568 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1572 */	NdrFcShort( 0x29 ),	/* 41 */
/* 1574 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1576 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1578 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1580 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1582 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1588 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1590 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1592 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1594 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1596 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1598 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1600 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure NewWindow */

/* 1602 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1604 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1608 */	NdrFcShort( 0x2a ),	/* 42 */
/* 1610 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1612 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1614 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1616 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1618 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1624 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1626 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1628 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1630 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1632 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1634 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1636 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FileOpen */

/* 1638 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1640 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1644 */	NdrFcShort( 0x2b ),	/* 43 */
/* 1646 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1648 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1650 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1652 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1654 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1660 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1662 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1664 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1666 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1668 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1670 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1672 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Save */

/* 1674 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1676 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1680 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1682 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1684 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1686 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1688 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1690 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1696 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1698 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1700 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1702 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1704 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1706 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1708 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SaveAs */

/* 1710 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1712 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1716 */	NdrFcShort( 0x2d ),	/* 45 */
/* 1718 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1720 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1722 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1724 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1726 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1728 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1732 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1734 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1736 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1738 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1740 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1742 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1744 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Print */

/* 1746 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1748 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1752 */	NdrFcShort( 0x2e ),	/* 46 */
/* 1754 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1756 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1758 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1760 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1762 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1768 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1770 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1772 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1774 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1776 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1778 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1780 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PrintPreview */

/* 1782 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1784 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1788 */	NdrFcShort( 0x2f ),	/* 47 */
/* 1790 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1792 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1794 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1796 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1798 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1804 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1806 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1808 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1810 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1812 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1814 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1816 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PageSetup */

/* 1818 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1820 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1824 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1826 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1828 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1830 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1832 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1834 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1840 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1842 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1844 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1846 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1848 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1850 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1852 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Print2 */

/* 1854 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1856 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1860 */	NdrFcShort( 0x31 ),	/* 49 */
/* 1862 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1864 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1866 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1868 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1870 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1876 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1878 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1880 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1882 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1884 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1886 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1888 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PrintPreview2 */

/* 1890 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1892 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1896 */	NdrFcShort( 0x32 ),	/* 50 */
/* 1898 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1900 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1902 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1904 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1906 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1912 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1914 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1916 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1918 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1920 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1922 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1924 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_HWNDShellDocObjectView */

/* 1926 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1928 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1932 */	NdrFcShort( 0x33 ),	/* 51 */
/* 1934 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1936 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1938 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1940 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1942 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1946 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1948 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1950 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1952 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1954 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1956 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1958 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1960 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1962 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1964 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1966 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_HWNDInternetExplorerServer */

/* 1968 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1970 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1974 */	NdrFcShort( 0x34 ),	/* 52 */
/* 1976 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1978 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1980 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1982 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1984 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1986 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1988 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1990 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1992 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1994 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1996 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1998 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2000 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2002 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2004 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2006 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2008 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ViewSource */

/* 2010 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2012 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2016 */	NdrFcShort( 0x35 ),	/* 53 */
/* 2018 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2020 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2022 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2024 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2026 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2028 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2032 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2034 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2036 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2038 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2040 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2042 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2044 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddToFavorites */

/* 2046 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2048 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2052 */	NdrFcShort( 0x36 ),	/* 54 */
/* 2054 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2056 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2058 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2060 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2062 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2064 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2066 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2068 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2070 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2072 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2074 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2076 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2078 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2080 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFocusW */

/* 2082 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2084 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2088 */	NdrFcShort( 0x37 ),	/* 55 */
/* 2090 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2092 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2094 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2096 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2098 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2104 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2106 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2108 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2110 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2112 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2114 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PlaceWBOnTop */

/* 2118 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2120 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2124 */	NdrFcShort( 0x38 ),	/* 56 */
/* 2126 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2128 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2130 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2132 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2134 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2140 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2142 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2144 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2146 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2148 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2150 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2152 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_HWNDMainWnd */

/* 2154 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2156 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2160 */	NdrFcShort( 0x39 ),	/* 57 */
/* 2162 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2166 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2168 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2170 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2176 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 2178 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2180 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2182 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2184 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2186 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2188 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AnyDocHasFocus */

/* 2190 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2192 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2196 */	NdrFcShort( 0x3a ),	/* 58 */
/* 2198 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2202 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2204 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2206 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2212 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2214 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2216 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2218 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2220 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2222 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2224 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ExecWB */

/* 2226 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2228 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2232 */	NdrFcShort( 0x3b ),	/* 59 */
/* 2234 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2236 */	NdrFcShort( 0x16 ),	/* 22 */
/* 2238 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2240 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2242 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2246 */	NdrFcShort( 0x40 ),	/* 64 */
/* 2248 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2250 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2252 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2254 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter cmdID */

/* 2256 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2258 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2260 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter cmdExecOpt */

/* 2262 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2264 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2266 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pvaIn */

/* 2268 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2270 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2272 */	NdrFcShort( 0x430 ),	/* Type Offset=1072 */

	/* Parameter pvaOut */

/* 2274 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2276 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2278 */	NdrFcShort( 0x430 ),	/* Type Offset=1072 */

	/* Return value */

/* 2280 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2282 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2284 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure QueryStatusWB */

/* 2286 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2288 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2292 */	NdrFcShort( 0x3c ),	/* 60 */
/* 2294 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2296 */	NdrFcShort( 0xe ),	/* 14 */
/* 2298 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2300 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 2302 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2308 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2310 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2312 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2314 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter cmdID */

/* 2316 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2318 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2320 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pcmdf */

/* 2322 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2324 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2326 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2328 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2330 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2332 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_StartupURL */

/* 2334 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2336 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2340 */	NdrFcShort( 0x3d ),	/* 61 */
/* 2342 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2346 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2348 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2350 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2352 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2356 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 2358 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 2360 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2362 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 2364 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2366 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2368 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_StartupURL */

/* 2370 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2372 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2376 */	NdrFcShort( 0x3e ),	/* 62 */
/* 2378 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2382 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2384 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2386 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2390 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2392 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 2394 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2396 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2398 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 2400 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2402 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2404 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_UseIEDefaultFileDownload */

/* 2406 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2408 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2412 */	NdrFcShort( 0x3f ),	/* 63 */
/* 2414 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2416 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2418 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2420 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2422 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2428 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2430 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2432 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2434 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 2436 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2438 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2440 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2442 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2444 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2446 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_UseIEDefaultFileDownload */

/* 2448 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2450 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2454 */	NdrFcShort( 0x40 ),	/* 64 */
/* 2456 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2458 */	NdrFcShort( 0xc ),	/* 12 */
/* 2460 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2462 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2464 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2470 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2472 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2474 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2476 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 2478 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2480 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2482 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2484 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2486 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2488 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_HWNDShellEmbedding */

/* 2490 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2492 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2496 */	NdrFcShort( 0x41 ),	/* 65 */
/* 2498 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2500 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2502 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2504 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2506 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2508 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2512 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2514 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2516 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2518 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 2520 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2522 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2524 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2526 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2528 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_FramesCount */

/* 2532 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2534 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2538 */	NdrFcShort( 0x42 ),	/* 66 */
/* 2540 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2542 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2544 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2546 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2548 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2554 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2556 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2558 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2560 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 2562 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2564 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2566 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2568 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2570 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2572 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_WBVisible */

/* 2574 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2576 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2580 */	NdrFcShort( 0x43 ),	/* 67 */
/* 2582 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2584 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2586 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2588 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2590 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2596 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2598 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2600 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2602 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 2604 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2606 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2608 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2610 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2612 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2614 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_WBVisible */

/* 2616 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2618 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2622 */	NdrFcShort( 0x44 ),	/* 68 */
/* 2624 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2626 */	NdrFcShort( 0xc ),	/* 12 */
/* 2628 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2630 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2632 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2634 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2638 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2640 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2642 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2644 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 2646 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2648 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2650 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2652 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2654 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2656 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Application */

/* 2658 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2660 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2664 */	NdrFcShort( 0x45 ),	/* 69 */
/* 2666 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2668 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2670 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2672 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2674 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2676 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2680 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2682 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2684 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2686 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 2688 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2690 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2692 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 2694 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2696 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2698 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Document */

/* 2700 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2702 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2706 */	NdrFcShort( 0x46 ),	/* 70 */
/* 2708 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2710 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2712 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2714 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2716 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2718 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2722 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2724 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2726 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2728 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 2730 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2732 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2734 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 2736 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2738 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2740 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ActiveElementObj */

/* 2742 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2744 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2748 */	NdrFcShort( 0x47 ),	/* 71 */
/* 2750 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2752 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2754 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2756 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2758 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2764 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2766 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2768 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2770 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 2772 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2774 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2776 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 2778 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2780 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2782 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ActiveDocumentObj */

/* 2784 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2786 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2790 */	NdrFcShort( 0x48 ),	/* 72 */
/* 2792 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2794 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2796 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2798 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2800 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2806 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2808 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2810 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2812 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 2814 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2816 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2818 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 2820 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2822 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2824 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Navigate2 */

/* 2826 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2828 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2832 */	NdrFcShort( 0x49 ),	/* 73 */
/* 2834 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2836 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2838 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2840 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 2842 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2846 */	NdrFcShort( 0xa0 ),	/* 160 */
/* 2848 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2850 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2852 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2854 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter URL */

/* 2856 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2858 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2860 */	NdrFcShort( 0x430 ),	/* Type Offset=1072 */

	/* Parameter Flags */

/* 2862 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2864 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2866 */	NdrFcShort( 0x430 ),	/* Type Offset=1072 */

	/* Parameter TargetFrameName */

/* 2868 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2870 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2872 */	NdrFcShort( 0x430 ),	/* Type Offset=1072 */

	/* Parameter PostData */

/* 2874 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2876 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2878 */	NdrFcShort( 0x430 ),	/* Type Offset=1072 */

	/* Parameter Headers */

/* 2880 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2882 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2884 */	NdrFcShort( 0x430 ),	/* Type Offset=1072 */

	/* Return value */

/* 2886 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2888 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2890 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Navigate */

/* 2892 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2894 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2898 */	NdrFcShort( 0x4a ),	/* 74 */
/* 2900 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2902 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2904 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2906 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 2908 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2912 */	NdrFcShort( 0x81 ),	/* 129 */
/* 2914 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2916 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2918 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2920 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter URL */

/* 2922 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2924 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2926 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter Flags */

/* 2928 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2930 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2932 */	NdrFcShort( 0x430 ),	/* Type Offset=1072 */

	/* Parameter TargetFrameName */

/* 2934 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2936 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2938 */	NdrFcShort( 0x430 ),	/* Type Offset=1072 */

	/* Parameter PostData */

/* 2940 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2942 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2944 */	NdrFcShort( 0x430 ),	/* Type Offset=1072 */

	/* Parameter Headers */

/* 2946 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2948 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2950 */	NdrFcShort( 0x430 ),	/* Type Offset=1072 */

	/* Return value */

/* 2952 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2954 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2956 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddBrowser */

/* 2958 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2960 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2964 */	NdrFcShort( 0x4b ),	/* 75 */
/* 2966 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2968 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2970 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2972 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2974 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2976 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2980 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2982 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 2984 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2986 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bBringToFront */

/* 2988 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2990 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2992 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2994 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2996 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2998 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ObjectWB */

/* 3000 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3002 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3006 */	NdrFcShort( 0x4c ),	/* 76 */
/* 3008 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3010 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3012 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3014 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 3016 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3018 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3022 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3024 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3026 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3028 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 3030 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3032 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3034 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 3036 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3038 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3040 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ContextMenuAction */

/* 3042 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3044 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3048 */	NdrFcShort( 0x4d ),	/* 77 */
/* 3050 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3052 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3054 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3056 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3058 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3062 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3064 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3066 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3068 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3070 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 3072 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3074 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3076 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3078 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3080 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3082 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ContextMenuAction */

/* 3084 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3086 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3090 */	NdrFcShort( 0x4e ),	/* 78 */
/* 3092 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3094 */	NdrFcShort( 0xe ),	/* 14 */
/* 3096 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3098 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3100 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3106 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3108 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3110 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3112 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 3114 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3116 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3118 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3120 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3122 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3124 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DocumentDownloadControlFlags */

/* 3126 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3128 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3132 */	NdrFcShort( 0x4f ),	/* 79 */
/* 3134 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3136 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3138 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3140 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3142 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3146 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3148 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3150 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3152 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3154 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 3156 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3158 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3160 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3162 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3164 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3166 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_DocumentDownloadControlFlags */

/* 3168 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3170 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3174 */	NdrFcShort( 0x50 ),	/* 80 */
/* 3176 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3178 */	NdrFcShort( 0xe ),	/* 14 */
/* 3180 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3182 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3184 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3190 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3192 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3194 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3196 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 3198 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3200 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3204 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3206 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3208 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DocumentHostUiFlags */

/* 3210 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3212 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3216 */	NdrFcShort( 0x51 ),	/* 81 */
/* 3218 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3220 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3222 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3224 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3226 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3232 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3234 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3236 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3238 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 3240 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3242 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3244 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3246 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3248 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3250 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_DocumentHostUiFlags */

/* 3252 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3254 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3258 */	NdrFcShort( 0x52 ),	/* 82 */
/* 3260 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3262 */	NdrFcShort( 0xe ),	/* 14 */
/* 3264 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3266 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3268 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3274 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3276 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3278 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3280 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 3282 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3284 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3288 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3290 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3292 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DocumentHostUiDoubleClickAction */

/* 3294 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3296 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3300 */	NdrFcShort( 0x53 ),	/* 83 */
/* 3302 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3304 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3306 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3308 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3310 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3316 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3318 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3320 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3322 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 3324 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3326 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3328 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3330 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3332 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3334 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_DocumentHostUiDoubleClickAction */

/* 3336 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3338 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3342 */	NdrFcShort( 0x54 ),	/* 84 */
/* 3344 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3346 */	NdrFcShort( 0xe ),	/* 14 */
/* 3348 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3350 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3352 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3358 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3360 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3362 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3364 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 3366 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3368 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3370 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3372 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3374 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3376 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindTextSimple */

/* 3378 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3380 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3384 */	NdrFcShort( 0x55 ),	/* 85 */
/* 3386 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 3388 */	NdrFcShort( 0x38 ),	/* 56 */
/* 3390 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3392 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 3394 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3398 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3400 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3402 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3404 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3406 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter TextToFind */

/* 3408 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3410 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3412 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter bDownward */

/* 3414 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3416 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3418 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bMatchWholeWord */

/* 3420 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3422 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3424 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bMatchCase */

/* 3426 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3428 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3430 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bScrollIntoView */

/* 3432 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3434 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3436 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter FindMatch */

/* 3438 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3440 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3442 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3444 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3446 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3448 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindAndHighlightAllText */

/* 3450 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3452 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3456 */	NdrFcShort( 0x56 ),	/* 86 */
/* 3458 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3460 */	NdrFcShort( 0x2e ),	/* 46 */
/* 3462 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3464 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 3466 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3470 */	NdrFcShort( 0x2 ),	/* 2 */
/* 3472 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3474 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3476 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3478 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter TextToFind */

/* 3480 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3482 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3484 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter bMatchWholeWord */

/* 3486 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3488 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3490 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bMatchCase */

/* 3492 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3494 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3496 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter HighlightColor */

/* 3498 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3500 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3502 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter NumOfMatchsFound */

/* 3504 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3506 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3508 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3510 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3512 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindAnyTextMatch */

/* 3516 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3518 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3522 */	NdrFcShort( 0x57 ),	/* 87 */
/* 3524 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3526 */	NdrFcShort( 0x2c ),	/* 44 */
/* 3528 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3530 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 3532 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3536 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3538 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3540 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3542 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3544 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter TextToFind */

/* 3546 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3548 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3550 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter bMatchWholeWord */

/* 3552 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3554 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3556 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bMatchCase */

/* 3558 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3560 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3562 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter FindMatch */

/* 3564 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3566 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3568 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3570 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3572 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3574 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_IsDocFrameset */

/* 3576 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3578 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3582 */	NdrFcShort( 0x58 ),	/* 88 */
/* 3584 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3586 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3588 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3590 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3592 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3598 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3600 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3602 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3604 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 3606 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3608 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3610 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3612 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3614 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3616 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ucScheme */

/* 3618 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3620 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3624 */	NdrFcShort( 0x59 ),	/* 89 */
/* 3626 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3630 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3632 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3634 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3636 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3640 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 3642 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 3644 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3646 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 3648 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3650 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3652 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ucScheme */

/* 3654 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3656 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3660 */	NdrFcShort( 0x5a ),	/* 90 */
/* 3662 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3666 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3668 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3670 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3674 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3676 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 3678 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3680 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3682 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 3684 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3686 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3688 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ucHostName */

/* 3690 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3692 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3696 */	NdrFcShort( 0x5b ),	/* 91 */
/* 3698 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3702 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3704 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3706 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3708 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3712 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 3714 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 3716 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3718 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 3720 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3722 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3724 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ucHostName */

/* 3726 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3728 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3732 */	NdrFcShort( 0x5c ),	/* 92 */
/* 3734 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3738 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3740 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3742 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3746 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3748 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 3750 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3752 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3754 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 3756 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3758 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3760 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ucPort */

/* 3762 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3764 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3768 */	NdrFcShort( 0x5d ),	/* 93 */
/* 3770 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3772 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3774 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3776 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3778 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3784 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 3786 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3788 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3790 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3792 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3794 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3796 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ucPort */

/* 3798 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3800 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3804 */	NdrFcShort( 0x5e ),	/* 94 */
/* 3806 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3808 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3810 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3812 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3814 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3820 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 3822 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3824 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3826 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3828 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3830 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ucUserName */

/* 3834 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3836 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3840 */	NdrFcShort( 0x5f ),	/* 95 */
/* 3842 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3846 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3848 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3850 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3852 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3854 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3856 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 3858 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 3860 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3862 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 3864 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3866 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3868 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ucUserName */

/* 3870 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3872 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3876 */	NdrFcShort( 0x60 ),	/* 96 */
/* 3878 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3882 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3884 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3886 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3890 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3892 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 3894 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3896 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3898 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 3900 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3902 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3904 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ucPassword */

/* 3906 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3908 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3912 */	NdrFcShort( 0x61 ),	/* 97 */
/* 3914 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3918 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3920 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3922 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3924 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3928 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 3930 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 3932 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3934 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 3936 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3938 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3940 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ucPassword */

/* 3942 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3944 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3948 */	NdrFcShort( 0x62 ),	/* 98 */
/* 3950 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3952 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3954 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3956 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3958 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3962 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3964 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 3966 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3968 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3970 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 3972 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3974 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3976 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ucUrlPath */

/* 3978 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3980 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3984 */	NdrFcShort( 0x63 ),	/* 99 */
/* 3986 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3988 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3990 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3992 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3994 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3996 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4000 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 4002 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 4004 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4006 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 4008 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4010 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4012 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ucUrlPath */

/* 4014 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4016 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4020 */	NdrFcShort( 0x64 ),	/* 100 */
/* 4022 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4024 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4026 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4028 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4030 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4032 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4034 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4036 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 4038 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4040 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4042 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 4044 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4046 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4048 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ucExtraInfo */

/* 4050 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4052 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4056 */	NdrFcShort( 0x65 ),	/* 101 */
/* 4058 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4062 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4064 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4066 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 4068 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4070 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4072 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 4074 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 4076 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4078 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 4080 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4082 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4084 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ucExtraInfo */

/* 4086 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4088 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4092 */	NdrFcShort( 0x66 ),	/* 102 */
/* 4094 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4098 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4100 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4102 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4106 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4108 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 4110 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4112 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4114 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 4116 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4118 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4120 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ucFullURL */

/* 4122 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4124 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4128 */	NdrFcShort( 0x67 ),	/* 103 */
/* 4130 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4134 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4136 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4138 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 4140 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4144 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 4146 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 4148 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4150 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 4152 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4154 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ucFullURL */

/* 4158 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4160 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4164 */	NdrFcShort( 0x68 ),	/* 104 */
/* 4166 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4170 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4172 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4174 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4178 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4180 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 4182 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4184 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4186 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 4188 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4190 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4192 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ucFileName */

/* 4194 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4196 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4200 */	NdrFcShort( 0x69 ),	/* 105 */
/* 4202 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4206 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4208 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4210 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 4212 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4216 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 4218 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 4220 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4222 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 4224 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4226 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4228 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ucFileExtension */

/* 4230 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4232 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4236 */	NdrFcShort( 0x6a ),	/* 106 */
/* 4238 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4240 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4242 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4244 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4246 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 4248 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4252 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 4254 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 4256 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4258 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 4260 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4262 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4264 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ucInternetCrackUrl */

/* 4266 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4268 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4272 */	NdrFcShort( 0x6b ),	/* 107 */
/* 4274 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4276 */	NdrFcShort( 0x1a ),	/* 26 */
/* 4278 */	NdrFcShort( 0x22 ),	/* 34 */
/* 4280 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4282 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4286 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4288 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter URL */

/* 4290 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4292 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4294 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter bSuccess */

/* 4296 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 4298 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4300 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 4302 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4304 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4306 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ucInternetScheme */

/* 4308 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4310 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4314 */	NdrFcShort( 0x6c ),	/* 108 */
/* 4316 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4320 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4322 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4324 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4330 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 4332 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4334 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4336 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4338 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4340 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4342 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ucInternetScheme */

/* 4344 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4346 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4350 */	NdrFcShort( 0x6d ),	/* 109 */
/* 4352 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4354 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4356 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4358 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4360 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4366 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 4368 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4370 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4372 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4374 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4376 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4378 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ucInternetCreateUrl */

/* 4380 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4382 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4386 */	NdrFcShort( 0x6e ),	/* 110 */
/* 4388 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4392 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4394 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4396 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 4398 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4400 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4402 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter URL */

/* 4404 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 4406 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4408 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 4410 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4412 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4414 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CancelFileDl */

/* 4416 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4418 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4422 */	NdrFcShort( 0x6f ),	/* 111 */
/* 4424 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4426 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4428 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4430 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4432 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4438 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter UIDToCancel */

/* 4440 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4442 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4444 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 4446 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4448 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4450 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DownloadUrlAsync */

/* 4452 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4454 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4458 */	NdrFcShort( 0x70 ),	/* 112 */
/* 4460 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4462 */	NdrFcShort( 0x1a ),	/* 26 */
/* 4464 */	NdrFcShort( 0x22 ),	/* 34 */
/* 4466 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 4468 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4472 */	NdrFcShort( 0x2 ),	/* 2 */
/* 4474 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter URL */

/* 4476 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4478 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4480 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter SaveFileName */

/* 4482 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4484 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4486 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter DLUID */

/* 4488 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 4490 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4492 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 4494 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4496 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4498 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RegisterHTTPprotocol */

/* 4500 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4502 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4506 */	NdrFcShort( 0x71 ),	/* 113 */
/* 4508 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4510 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4512 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4514 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4516 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4522 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 4524 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4526 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4528 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 4530 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4532 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4534 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RegisterHTTPSprotocol */

/* 4536 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4538 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4542 */	NdrFcShort( 0x72 ),	/* 114 */
/* 4544 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4546 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4548 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4550 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4552 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4558 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 4560 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4562 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4564 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 4566 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4568 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4570 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DisplayCertificateDialog */

/* 4572 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4574 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4578 */	NdrFcShort( 0x73 ),	/* 115 */
/* 4580 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4582 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4584 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4586 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4588 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4590 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4594 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 4596 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4598 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4600 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 4602 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4604 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4606 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LoadHTMLFromString */

/* 4608 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4610 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4614 */	NdrFcShort( 0x74 ),	/* 116 */
/* 4616 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4618 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4620 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4622 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 4624 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4628 */	NdrFcShort( 0x2 ),	/* 2 */
/* 4630 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 4632 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4634 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4636 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter sContent */

/* 4638 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4640 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4642 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter sBaseUrl */

/* 4644 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4646 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4648 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 4650 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4652 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4654 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DrawWBThumbnailOnWnd */

/* 4656 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4658 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4662 */	NdrFcShort( 0x75 ),	/* 117 */
/* 4664 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4666 */	NdrFcShort( 0x2e ),	/* 46 */
/* 4668 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4670 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x7,		/* 7 */
/* 4672 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4676 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4678 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 4680 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4682 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4684 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter WndHdc */

/* 4686 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4688 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4690 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lX */

/* 4692 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4694 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4696 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lY */

/* 4698 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4700 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4702 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lW */

/* 4704 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4706 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4708 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lH */

/* 4710 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4712 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4714 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4716 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4718 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4720 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_WBPageTextSize */

/* 4722 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4724 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4728 */	NdrFcShort( 0x76 ),	/* 118 */
/* 4730 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4732 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4734 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4736 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 4738 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4744 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 4746 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4748 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4750 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 4752 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4754 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4756 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4758 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4760 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4762 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_WBPageTextSize */

/* 4764 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4766 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4770 */	NdrFcShort( 0x77 ),	/* 119 */
/* 4772 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4774 */	NdrFcShort( 0xe ),	/* 14 */
/* 4776 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4778 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 4780 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4786 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 4788 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4790 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4792 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 4794 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4796 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4798 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4800 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4802 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4804 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ucResetFieldsToDefault */

/* 4806 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4808 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4812 */	NdrFcShort( 0x78 ),	/* 120 */
/* 4814 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4818 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4820 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4822 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4828 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4830 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4832 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4834 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SubclassWnd */

/* 4836 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4838 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4842 */	NdrFcShort( 0x79 ),	/* 121 */
/* 4844 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4846 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4848 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4850 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4852 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4854 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4858 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hwndWnd */

/* 4860 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4862 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4864 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4866 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4868 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4870 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UnSubclassWnd */

/* 4872 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4874 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4878 */	NdrFcShort( 0x7a ),	/* 122 */
/* 4880 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4882 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4884 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4886 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4888 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4890 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4894 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hwndWnd */

/* 4896 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4898 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4900 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4902 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4904 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4906 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddMessage */

/* 4908 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4910 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4914 */	NdrFcShort( 0x7b ),	/* 123 */
/* 4916 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4918 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4920 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4922 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 4924 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4930 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hwndWnd */

/* 4932 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4934 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4936 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lMsg */

/* 4938 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4940 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4942 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4944 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4946 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4948 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetupShellAutoComplete */

/* 4950 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4952 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4956 */	NdrFcShort( 0x7c ),	/* 124 */
/* 4958 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4960 */	NdrFcShort( 0x16 ),	/* 22 */
/* 4962 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4964 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 4966 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4972 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hwndTarget */

/* 4974 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4976 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4978 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter IsTargetComboBox */

/* 4980 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4982 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4984 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter lFlags */

/* 4986 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4988 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4990 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4992 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4994 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4996 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SaveAsBitmap */

/* 4998 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5000 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5004 */	NdrFcShort( 0x7d ),	/* 125 */
/* 5006 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5008 */	NdrFcShort( 0x6 ),	/* 6 */
/* 5010 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5012 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 5014 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 5016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5018 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5020 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 5022 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5024 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5026 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter BitmapName */

/* 5028 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 5030 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5032 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 5034 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5036 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5038 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WBPostData */

/* 5040 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5042 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5046 */	NdrFcShort( 0x7e ),	/* 126 */
/* 5048 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5050 */	NdrFcShort( 0x1a ),	/* 26 */
/* 5052 */	NdrFcShort( 0x22 ),	/* 34 */
/* 5054 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 5056 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 5058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5060 */	NdrFcShort( 0x2 ),	/* 2 */
/* 5062 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter sURL */

/* 5064 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 5066 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5068 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter sData */

/* 5070 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 5072 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5074 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter PostID */

/* 5076 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 5078 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5080 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 5082 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5084 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5086 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_SourceOnDocComplete */

/* 5088 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5090 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5094 */	NdrFcShort( 0x7f ),	/* 127 */
/* 5096 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5098 */	NdrFcShort( 0x6 ),	/* 6 */
/* 5100 */	NdrFcShort( 0x22 ),	/* 34 */
/* 5102 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5104 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5110 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 5112 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5114 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5116 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 5118 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5120 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5122 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 5124 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5126 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5128 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_SourceOnDocComplete */

/* 5130 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5132 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5136 */	NdrFcShort( 0x80 ),	/* 128 */
/* 5138 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5140 */	NdrFcShort( 0xc ),	/* 12 */
/* 5142 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5144 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5146 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5152 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 5154 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5156 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5158 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 5160 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5162 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5164 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 5166 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5168 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5170 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OrganizeFavorites */

/* 5172 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5174 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5178 */	NdrFcShort( 0x81 ),	/* 129 */
/* 5180 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5184 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5186 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 5188 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5194 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 5196 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5198 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5200 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ViewIEOptions */

/* 5202 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5204 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5208 */	NdrFcShort( 0x82 ),	/* 130 */
/* 5210 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5212 */	NdrFcShort( 0x6 ),	/* 6 */
/* 5214 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5216 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5218 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5224 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 5226 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5228 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5230 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 5232 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5234 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5236 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindAndHighlightAllTextFrames */

/* 5238 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5240 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5244 */	NdrFcShort( 0x83 ),	/* 131 */
/* 5246 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 5248 */	NdrFcShort( 0x2e ),	/* 46 */
/* 5250 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5252 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 5254 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 5256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5258 */	NdrFcShort( 0x2 ),	/* 2 */
/* 5260 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 5262 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5264 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5266 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter TextToFind */

/* 5268 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 5270 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5272 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter bMatchWholeWord */

/* 5274 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5276 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5278 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bMatchCase */

/* 5280 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5282 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5284 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter HighlightColor */

/* 5286 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 5288 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5290 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter NumOfMatchsFound */

/* 5292 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 5294 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5296 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5298 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5300 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 5302 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetupWindowsHook */

/* 5304 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5306 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5310 */	NdrFcShort( 0x84 ),	/* 132 */
/* 5312 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5314 */	NdrFcShort( 0x30 ),	/* 48 */
/* 5316 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5318 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 5320 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5322 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5326 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lHookType */

/* 5328 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5330 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5332 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter hwndTargetWnd */

/* 5334 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5336 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5338 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bStart */

/* 5340 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5342 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5344 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter lUWMHookMsgID */

/* 5346 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 5348 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5350 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5352 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5354 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5356 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure HookProcNCode */

/* 5358 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5360 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5364 */	NdrFcShort( 0x85 ),	/* 133 */
/* 5366 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5368 */	NdrFcShort( 0x22 ),	/* 34 */
/* 5370 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5372 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5374 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5380 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lHookType */

/* 5382 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5384 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5386 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter nCode */

/* 5388 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 5390 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5392 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5394 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5396 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5398 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetupCustomAutoComplete */

/* 5400 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5402 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5406 */	NdrFcShort( 0x86 ),	/* 134 */
/* 5408 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5410 */	NdrFcShort( 0x16 ),	/* 22 */
/* 5412 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5414 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 5416 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 5418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5420 */	NdrFcShort( 0x20 ),	/* 32 */
/* 5422 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hwndTarget */

/* 5424 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5426 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5428 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter IsTargetComboBox */

/* 5430 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5432 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5434 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter lCustomAutoCompleteFlags */

/* 5436 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5438 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5440 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter varStringArray */

/* 5442 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5444 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5446 */	NdrFcShort( 0x430 ),	/* Type Offset=1072 */

	/* Return value */

/* 5448 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5450 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5452 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CustomAutoCompleteAddString */

/* 5454 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5456 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5460 */	NdrFcShort( 0x87 ),	/* 135 */
/* 5462 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5464 */	NdrFcShort( 0xe ),	/* 14 */
/* 5466 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5468 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 5470 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 5472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5474 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5476 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hwndTarget */

/* 5478 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5480 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5482 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter IsTargetComboBox */

/* 5484 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5486 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5488 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter strItem */

/* 5490 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 5492 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5494 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 5496 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5498 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5500 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CustomAutoCompleteEnable */

/* 5502 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5504 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5508 */	NdrFcShort( 0x88 ),	/* 136 */
/* 5510 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5512 */	NdrFcShort( 0x14 ),	/* 20 */
/* 5514 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5516 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 5518 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5524 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hwndTarget */

/* 5526 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5528 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter IsTargetComboBox */

/* 5532 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5534 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5536 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bEnable */

/* 5538 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5540 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5542 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 5544 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5546 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5548 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure QueryIERegistryOption */

/* 5550 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5552 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5556 */	NdrFcShort( 0x89 ),	/* 137 */
/* 5558 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5560 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5562 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5564 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 5566 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 5568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5570 */	NdrFcShort( 0x20 ),	/* 32 */
/* 5572 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IeRegistryOptionsFlag */

/* 5574 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5576 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5578 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter varBuffer */

/* 5580 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5582 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5584 */	NdrFcShort( 0x430 ),	/* Type Offset=1072 */

	/* Return value */

/* 5586 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5588 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5590 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIERegistryOption */

/* 5592 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5594 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5598 */	NdrFcShort( 0x8a ),	/* 138 */
/* 5600 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5602 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5604 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5606 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 5608 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 5610 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5612 */	NdrFcShort( 0x20 ),	/* 32 */
/* 5614 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IeRegistryOptionsFlag */

/* 5616 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5618 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5620 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter varBuffer */

/* 5622 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5624 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5626 */	NdrFcShort( 0x430 ),	/* Type Offset=1072 */

	/* Return value */

/* 5628 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5630 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5632 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DecodeMime */

/* 5634 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5636 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5640 */	NdrFcShort( 0x8b ),	/* 139 */
/* 5642 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5646 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5648 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 5650 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 5652 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5654 */	NdrFcShort( 0x2 ),	/* 2 */
/* 5656 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter strToDecode */

/* 5658 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 5660 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5662 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter strDecoded */

/* 5664 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 5666 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5668 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 5670 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5672 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5674 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DeleteIEFiles */

/* 5676 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5678 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5682 */	NdrFcShort( 0x8c ),	/* 140 */
/* 5684 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5686 */	NdrFcShort( 0x6 ),	/* 6 */
/* 5688 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5690 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5692 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5698 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter enumWhichFiles */

/* 5700 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5702 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5704 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 5706 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5708 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5710 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/*  4 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  8 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 10 */	
			0x12, 0x0,	/* FC_UP */
/* 12 */	NdrFcShort( 0xe ),	/* Offset= 14 (26) */
/* 14 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 16 */	NdrFcShort( 0x2 ),	/* 2 */
/* 18 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 20 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 22 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 24 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 26 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 28 */	NdrFcShort( 0x8 ),	/* 8 */
/* 30 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (14) */
/* 32 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 34 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 36 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 38 */	NdrFcShort( 0x0 ),	/* 0 */
/* 40 */	NdrFcShort( 0x4 ),	/* 4 */
/* 42 */	NdrFcShort( 0x0 ),	/* 0 */
/* 44 */	NdrFcShort( 0xffde ),	/* Offset= -34 (10) */
/* 46 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 48 */	NdrFcShort( 0x2 ),	/* Offset= 2 (50) */
/* 50 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 52 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */
/* 60 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 62 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 64 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 66 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 68 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 70 */	NdrFcShort( 0x6 ),	/* Offset= 6 (76) */
/* 72 */	
			0x13, 0x0,	/* FC_OP */
/* 74 */	NdrFcShort( 0xffd0 ),	/* Offset= -48 (26) */
/* 76 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 78 */	NdrFcShort( 0x0 ),	/* 0 */
/* 80 */	NdrFcShort( 0x4 ),	/* 4 */
/* 82 */	NdrFcShort( 0x0 ),	/* 0 */
/* 84 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (72) */
/* 86 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 88 */	0xe,		/* FC_ENUM32 */
			0x5c,		/* FC_PAD */
/* 90 */	
			0x11, 0x0,	/* FC_RP */
/* 92 */	NdrFcShort( 0x3d4 ),	/* Offset= 980 (1072) */
/* 94 */	
			0x12, 0x0,	/* FC_UP */
/* 96 */	NdrFcShort( 0x3bc ),	/* Offset= 956 (1052) */
/* 98 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 100 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 102 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 104 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 106 */	NdrFcShort( 0x2 ),	/* Offset= 2 (108) */
/* 108 */	NdrFcShort( 0x10 ),	/* 16 */
/* 110 */	NdrFcShort( 0x2f ),	/* 47 */
/* 112 */	NdrFcLong( 0x14 ),	/* 20 */
/* 116 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 118 */	NdrFcLong( 0x3 ),	/* 3 */
/* 122 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 124 */	NdrFcLong( 0x11 ),	/* 17 */
/* 128 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 130 */	NdrFcLong( 0x2 ),	/* 2 */
/* 134 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 136 */	NdrFcLong( 0x4 ),	/* 4 */
/* 140 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 142 */	NdrFcLong( 0x5 ),	/* 5 */
/* 146 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 148 */	NdrFcLong( 0xb ),	/* 11 */
/* 152 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 154 */	NdrFcLong( 0xa ),	/* 10 */
/* 158 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 160 */	NdrFcLong( 0x6 ),	/* 6 */
/* 164 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (396) */
/* 166 */	NdrFcLong( 0x7 ),	/* 7 */
/* 170 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 172 */	NdrFcLong( 0x8 ),	/* 8 */
/* 176 */	NdrFcShort( 0xff5a ),	/* Offset= -166 (10) */
/* 178 */	NdrFcLong( 0xd ),	/* 13 */
/* 182 */	NdrFcShort( 0xdc ),	/* Offset= 220 (402) */
/* 184 */	NdrFcLong( 0x9 ),	/* 9 */
/* 188 */	NdrFcShort( 0xff76 ),	/* Offset= -138 (50) */
/* 190 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 194 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (420) */
/* 196 */	NdrFcLong( 0x24 ),	/* 36 */
/* 200 */	NdrFcShort( 0x30a ),	/* Offset= 778 (978) */
/* 202 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 206 */	NdrFcShort( 0x304 ),	/* Offset= 772 (978) */
/* 208 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 212 */	NdrFcShort( 0x302 ),	/* Offset= 770 (982) */
/* 214 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 218 */	NdrFcShort( 0x300 ),	/* Offset= 768 (986) */
/* 220 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 224 */	NdrFcShort( 0x2fe ),	/* Offset= 766 (990) */
/* 226 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 230 */	NdrFcShort( 0x2fc ),	/* Offset= 764 (994) */
/* 232 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 236 */	NdrFcShort( 0x2fa ),	/* Offset= 762 (998) */
/* 238 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 242 */	NdrFcShort( 0x2f8 ),	/* Offset= 760 (1002) */
/* 244 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 248 */	NdrFcShort( 0x2e2 ),	/* Offset= 738 (986) */
/* 250 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 254 */	NdrFcShort( 0x2e0 ),	/* Offset= 736 (990) */
/* 256 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 260 */	NdrFcShort( 0x2ea ),	/* Offset= 746 (1006) */
/* 262 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 266 */	NdrFcShort( 0x2e0 ),	/* Offset= 736 (1002) */
/* 268 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 272 */	NdrFcShort( 0x2e2 ),	/* Offset= 738 (1010) */
/* 274 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 278 */	NdrFcShort( 0x2e0 ),	/* Offset= 736 (1014) */
/* 280 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 284 */	NdrFcShort( 0x2de ),	/* Offset= 734 (1018) */
/* 286 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 290 */	NdrFcShort( 0x2dc ),	/* Offset= 732 (1022) */
/* 292 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 296 */	NdrFcShort( 0x2da ),	/* Offset= 730 (1026) */
/* 298 */	NdrFcLong( 0x10 ),	/* 16 */
/* 302 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 304 */	NdrFcLong( 0x12 ),	/* 18 */
/* 308 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 310 */	NdrFcLong( 0x13 ),	/* 19 */
/* 314 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 316 */	NdrFcLong( 0x15 ),	/* 21 */
/* 320 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 322 */	NdrFcLong( 0x16 ),	/* 22 */
/* 326 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 328 */	NdrFcLong( 0x17 ),	/* 23 */
/* 332 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 334 */	NdrFcLong( 0xe ),	/* 14 */
/* 338 */	NdrFcShort( 0x2b8 ),	/* Offset= 696 (1034) */
/* 340 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 344 */	NdrFcShort( 0x2bc ),	/* Offset= 700 (1044) */
/* 346 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 350 */	NdrFcShort( 0x2ba ),	/* Offset= 698 (1048) */
/* 352 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 356 */	NdrFcShort( 0x276 ),	/* Offset= 630 (986) */
/* 358 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 362 */	NdrFcShort( 0x274 ),	/* Offset= 628 (990) */
/* 364 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 368 */	NdrFcShort( 0x272 ),	/* Offset= 626 (994) */
/* 370 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 374 */	NdrFcShort( 0x268 ),	/* Offset= 616 (990) */
/* 376 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 380 */	NdrFcShort( 0x262 ),	/* Offset= 610 (990) */
/* 382 */	NdrFcLong( 0x0 ),	/* 0 */
/* 386 */	NdrFcShort( 0x0 ),	/* Offset= 0 (386) */
/* 388 */	NdrFcLong( 0x1 ),	/* 1 */
/* 392 */	NdrFcShort( 0x0 ),	/* Offset= 0 (392) */
/* 394 */	NdrFcShort( 0xffff ),	/* Offset= -1 (393) */
/* 396 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 398 */	NdrFcShort( 0x8 ),	/* 8 */
/* 400 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 402 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 404 */	NdrFcLong( 0x0 ),	/* 0 */
/* 408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 412 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 414 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 416 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 418 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 420 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 422 */	NdrFcShort( 0x2 ),	/* Offset= 2 (424) */
/* 424 */	
			0x12, 0x0,	/* FC_UP */
/* 426 */	NdrFcShort( 0x216 ),	/* Offset= 534 (960) */
/* 428 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 430 */	NdrFcShort( 0x18 ),	/* 24 */
/* 432 */	NdrFcShort( 0xa ),	/* 10 */
/* 434 */	NdrFcLong( 0x8 ),	/* 8 */
/* 438 */	NdrFcShort( 0x5a ),	/* Offset= 90 (528) */
/* 440 */	NdrFcLong( 0xd ),	/* 13 */
/* 444 */	NdrFcShort( 0x7e ),	/* Offset= 126 (570) */
/* 446 */	NdrFcLong( 0x9 ),	/* 9 */
/* 450 */	NdrFcShort( 0x9e ),	/* Offset= 158 (608) */
/* 452 */	NdrFcLong( 0xc ),	/* 12 */
/* 456 */	NdrFcShort( 0xc8 ),	/* Offset= 200 (656) */
/* 458 */	NdrFcLong( 0x24 ),	/* 36 */
/* 462 */	NdrFcShort( 0x124 ),	/* Offset= 292 (754) */
/* 464 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 468 */	NdrFcShort( 0x140 ),	/* Offset= 320 (788) */
/* 470 */	NdrFcLong( 0x10 ),	/* 16 */
/* 474 */	NdrFcShort( 0x15a ),	/* Offset= 346 (820) */
/* 476 */	NdrFcLong( 0x2 ),	/* 2 */
/* 480 */	NdrFcShort( 0x174 ),	/* Offset= 372 (852) */
/* 482 */	NdrFcLong( 0x3 ),	/* 3 */
/* 486 */	NdrFcShort( 0x18e ),	/* Offset= 398 (884) */
/* 488 */	NdrFcLong( 0x14 ),	/* 20 */
/* 492 */	NdrFcShort( 0x1a8 ),	/* Offset= 424 (916) */
/* 494 */	NdrFcShort( 0xffff ),	/* Offset= -1 (493) */
/* 496 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 498 */	NdrFcShort( 0x4 ),	/* 4 */
/* 500 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 504 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 506 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 508 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 510 */	NdrFcShort( 0x4 ),	/* 4 */
/* 512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 514 */	NdrFcShort( 0x1 ),	/* 1 */
/* 516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 520 */	0x12, 0x0,	/* FC_UP */
/* 522 */	NdrFcShort( 0xfe10 ),	/* Offset= -496 (26) */
/* 524 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 526 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 528 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 530 */	NdrFcShort( 0x8 ),	/* 8 */
/* 532 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 534 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 536 */	NdrFcShort( 0x4 ),	/* 4 */
/* 538 */	NdrFcShort( 0x4 ),	/* 4 */
/* 540 */	0x11, 0x0,	/* FC_RP */
/* 542 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (496) */
/* 544 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 546 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 548 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 552 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 556 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 558 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 562 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 564 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 566 */	NdrFcShort( 0xff5c ),	/* Offset= -164 (402) */
/* 568 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 570 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 572 */	NdrFcShort( 0x8 ),	/* 8 */
/* 574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 576 */	NdrFcShort( 0x6 ),	/* Offset= 6 (582) */
/* 578 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 580 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 582 */	
			0x11, 0x0,	/* FC_RP */
/* 584 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (548) */
/* 586 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 590 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 594 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 596 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 600 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 602 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 604 */	NdrFcShort( 0xfdd6 ),	/* Offset= -554 (50) */
/* 606 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 608 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 610 */	NdrFcShort( 0x8 ),	/* 8 */
/* 612 */	NdrFcShort( 0x0 ),	/* 0 */
/* 614 */	NdrFcShort( 0x6 ),	/* Offset= 6 (620) */
/* 616 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 618 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 620 */	
			0x11, 0x0,	/* FC_RP */
/* 622 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (586) */
/* 624 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 626 */	NdrFcShort( 0x4 ),	/* 4 */
/* 628 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 632 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 634 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 636 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 638 */	NdrFcShort( 0x4 ),	/* 4 */
/* 640 */	NdrFcShort( 0x0 ),	/* 0 */
/* 642 */	NdrFcShort( 0x1 ),	/* 1 */
/* 644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 648 */	0x12, 0x0,	/* FC_UP */
/* 650 */	NdrFcShort( 0x192 ),	/* Offset= 402 (1052) */
/* 652 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 654 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 656 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 658 */	NdrFcShort( 0x8 ),	/* 8 */
/* 660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 662 */	NdrFcShort( 0x6 ),	/* Offset= 6 (668) */
/* 664 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 666 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 668 */	
			0x11, 0x0,	/* FC_RP */
/* 670 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (624) */
/* 672 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 674 */	NdrFcLong( 0x2f ),	/* 47 */
/* 678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 682 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 684 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 686 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 688 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 690 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 692 */	NdrFcShort( 0x1 ),	/* 1 */
/* 694 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 696 */	NdrFcShort( 0x4 ),	/* 4 */
/* 698 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 700 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 702 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 704 */	NdrFcShort( 0x10 ),	/* 16 */
/* 706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 708 */	NdrFcShort( 0xa ),	/* Offset= 10 (718) */
/* 710 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 712 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 714 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (672) */
/* 716 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 718 */	
			0x12, 0x0,	/* FC_UP */
/* 720 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (690) */
/* 722 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 724 */	NdrFcShort( 0x4 ),	/* 4 */
/* 726 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 728 */	NdrFcShort( 0x0 ),	/* 0 */
/* 730 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 732 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 734 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 736 */	NdrFcShort( 0x4 ),	/* 4 */
/* 738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 740 */	NdrFcShort( 0x1 ),	/* 1 */
/* 742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 746 */	0x12, 0x0,	/* FC_UP */
/* 748 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (702) */
/* 750 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 752 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 754 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 756 */	NdrFcShort( 0x8 ),	/* 8 */
/* 758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 760 */	NdrFcShort( 0x6 ),	/* Offset= 6 (766) */
/* 762 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 764 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 766 */	
			0x11, 0x0,	/* FC_RP */
/* 768 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (722) */
/* 770 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 772 */	NdrFcShort( 0x8 ),	/* 8 */
/* 774 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 776 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 778 */	NdrFcShort( 0x10 ),	/* 16 */
/* 780 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 782 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 784 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (770) */
			0x5b,		/* FC_END */
/* 788 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 790 */	NdrFcShort( 0x18 ),	/* 24 */
/* 792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 794 */	NdrFcShort( 0xa ),	/* Offset= 10 (804) */
/* 796 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 798 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 800 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (776) */
/* 802 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 804 */	
			0x11, 0x0,	/* FC_RP */
/* 806 */	NdrFcShort( 0xfefe ),	/* Offset= -258 (548) */
/* 808 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 810 */	NdrFcShort( 0x1 ),	/* 1 */
/* 812 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 814 */	NdrFcShort( 0x0 ),	/* 0 */
/* 816 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 818 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 820 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 822 */	NdrFcShort( 0x8 ),	/* 8 */
/* 824 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 826 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 828 */	NdrFcShort( 0x4 ),	/* 4 */
/* 830 */	NdrFcShort( 0x4 ),	/* 4 */
/* 832 */	0x12, 0x0,	/* FC_UP */
/* 834 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (808) */
/* 836 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 838 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 840 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 842 */	NdrFcShort( 0x2 ),	/* 2 */
/* 844 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 846 */	NdrFcShort( 0x0 ),	/* 0 */
/* 848 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 850 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 852 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 854 */	NdrFcShort( 0x8 ),	/* 8 */
/* 856 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 858 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 860 */	NdrFcShort( 0x4 ),	/* 4 */
/* 862 */	NdrFcShort( 0x4 ),	/* 4 */
/* 864 */	0x12, 0x0,	/* FC_UP */
/* 866 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (840) */
/* 868 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 870 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 872 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 874 */	NdrFcShort( 0x4 ),	/* 4 */
/* 876 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 878 */	NdrFcShort( 0x0 ),	/* 0 */
/* 880 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 882 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 884 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 886 */	NdrFcShort( 0x8 ),	/* 8 */
/* 888 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 890 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 892 */	NdrFcShort( 0x4 ),	/* 4 */
/* 894 */	NdrFcShort( 0x4 ),	/* 4 */
/* 896 */	0x12, 0x0,	/* FC_UP */
/* 898 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (872) */
/* 900 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 902 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 904 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 906 */	NdrFcShort( 0x8 ),	/* 8 */
/* 908 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 912 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 914 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 916 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 918 */	NdrFcShort( 0x8 ),	/* 8 */
/* 920 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 922 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 924 */	NdrFcShort( 0x4 ),	/* 4 */
/* 926 */	NdrFcShort( 0x4 ),	/* 4 */
/* 928 */	0x12, 0x0,	/* FC_UP */
/* 930 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (904) */
/* 932 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 934 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 936 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 938 */	NdrFcShort( 0x8 ),	/* 8 */
/* 940 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 942 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 944 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 946 */	NdrFcShort( 0x8 ),	/* 8 */
/* 948 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 950 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 952 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 954 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 956 */	NdrFcShort( 0xffec ),	/* Offset= -20 (936) */
/* 958 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 960 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 962 */	NdrFcShort( 0x28 ),	/* 40 */
/* 964 */	NdrFcShort( 0xffec ),	/* Offset= -20 (944) */
/* 966 */	NdrFcShort( 0x0 ),	/* Offset= 0 (966) */
/* 968 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 970 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 972 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 974 */	NdrFcShort( 0xfdde ),	/* Offset= -546 (428) */
/* 976 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 978 */	
			0x12, 0x0,	/* FC_UP */
/* 980 */	NdrFcShort( 0xfeea ),	/* Offset= -278 (702) */
/* 982 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 984 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 986 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 988 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 990 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 992 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 994 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 996 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 998 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1000 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 1002 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1004 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 1006 */	
			0x12, 0x0,	/* FC_UP */
/* 1008 */	NdrFcShort( 0xfd9c ),	/* Offset= -612 (396) */
/* 1010 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1012 */	NdrFcShort( 0xfc16 ),	/* Offset= -1002 (10) */
/* 1014 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1016 */	NdrFcShort( 0xfd9a ),	/* Offset= -614 (402) */
/* 1018 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1020 */	NdrFcShort( 0xfc36 ),	/* Offset= -970 (50) */
/* 1022 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1024 */	NdrFcShort( 0xfda4 ),	/* Offset= -604 (420) */
/* 1026 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1028 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1030) */
/* 1030 */	
			0x12, 0x0,	/* FC_UP */
/* 1032 */	NdrFcShort( 0x14 ),	/* Offset= 20 (1052) */
/* 1034 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 1036 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1038 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 1040 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 1042 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1044 */	
			0x12, 0x0,	/* FC_UP */
/* 1046 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1034) */
/* 1048 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1050 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 1052 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1054 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1058 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1058) */
/* 1060 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1062 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1064 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1066 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1068 */	NdrFcShort( 0xfc36 ),	/* Offset= -970 (98) */
/* 1070 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1072 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1074 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1076 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1078 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1080 */	NdrFcShort( 0xfc26 ),	/* Offset= -986 (94) */
/* 1082 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1084 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1086 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 1088 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 1090 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 1092 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1094 */	
			0x11, 0x0,	/* FC_RP */
/* 1096 */	NdrFcShort( 0xfc04 ),	/* Offset= -1020 (76) */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            },
            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            }

        };



/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: INewWindowManager, ver. 0.0,
   GUID={0xD2BC4C84,0x3F72,0x4a52,{0xA6,0x04,0x7B,0xCB,0xF3,0x98,0x2C,0xBB}} */

#pragma code_seg(".orpc")
static const unsigned short INewWindowManager_FormatStringOffsetTable[] =
    {
    0
    };

static const MIDL_STUBLESS_PROXY_INFO INewWindowManager_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &INewWindowManager_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO INewWindowManager_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &INewWindowManager_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _INewWindowManagerProxyVtbl = 
{
    &INewWindowManager_ProxyInfo,
    &IID_INewWindowManager,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* INewWindowManager::EvaluateNewWindow */
};

const CInterfaceStubVtbl _INewWindowManagerStubVtbl =
{
    &IID_INewWindowManager,
    &INewWindowManager_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHTMLOMWindowServices, ver. 0.0,
   GUID={0x3050f5fc,0x98b5,0x11cf,{0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b}} */

#pragma code_seg(".orpc")
static const unsigned short IHTMLOMWindowServices_FormatStringOffsetTable[] =
    {
    72,
    114,
    156,
    198
    };

static const MIDL_STUBLESS_PROXY_INFO IHTMLOMWindowServices_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHTMLOMWindowServices_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHTMLOMWindowServices_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHTMLOMWindowServices_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IHTMLOMWindowServicesProxyVtbl = 
{
    &IHTMLOMWindowServices_ProxyInfo,
    &IID_IHTMLOMWindowServices,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHTMLOMWindowServices::moveTo */ ,
    (void *) (INT_PTR) -1 /* IHTMLOMWindowServices::moveBy */ ,
    (void *) (INT_PTR) -1 /* IHTMLOMWindowServices::resizeTo */ ,
    (void *) (INT_PTR) -1 /* IHTMLOMWindowServices::resizeBy */
};

const CInterfaceStubVtbl _IHTMLOMWindowServicesStubVtbl =
{
    &IID_IHTMLOMWindowServices,
    &IHTMLOMWindowServices_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Standard interface: __MIDL_itf_vbMHWB_0259, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IDownloadManager, ver. 0.0,
   GUID={0x988934A4,0x064B,0x11D3,{0xBB,0x80,0x00,0x10,0x4B,0x35,0xE7,0xF9}} */


/* Standard interface: __MIDL_itf_vbMHWB_0260, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IvbWB, ver. 0.0,
   GUID={0x6E73D516,0x7CDC,0x435E,{0x8A,0x8D,0x86,0xE0,0xAE,0x4D,0x5E,0x08}} */

#pragma code_seg(".orpc")
static const unsigned short IvbWB_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    240,
    276,
    312,
    348,
    384,
    420,
    456,
    492,
    534,
    576,
    618,
    660,
    702,
    744,
    780,
    822,
    864,
    906,
    948,
    996,
    1044,
    1086,
    1128,
    1170,
    1206,
    1242,
    1278,
    1314,
    1350,
    1386,
    1422,
    1458,
    1494,
    1530,
    1566,
    1602,
    1638,
    1674,
    1710,
    1746,
    1782,
    1818,
    1854,
    1890,
    1926,
    1968,
    2010,
    2046,
    2082,
    2118,
    2154,
    2190,
    2226,
    2286,
    2334,
    2370,
    2406,
    2448,
    2490,
    2532,
    2574,
    2616,
    2658,
    2700,
    2742,
    2784,
    2826,
    2892,
    2958,
    3000,
    3042,
    3084,
    3126,
    3168,
    3210,
    3252,
    3294,
    3336,
    3378,
    3450,
    3516,
    3576,
    3618,
    3654,
    3690,
    3726,
    3762,
    3798,
    3834,
    3870,
    3906,
    3942,
    3978,
    4014,
    4050,
    4086,
    4122,
    4158,
    4194,
    4230,
    4266,
    4308,
    4344,
    4380,
    4416,
    4452,
    4500,
    4536,
    4572,
    4608,
    4656,
    4722,
    4764,
    4806,
    4836,
    4872,
    4908,
    4950,
    4998,
    5040,
    5088,
    5130,
    5172,
    5202,
    5238,
    5304,
    5358,
    5400,
    5454,
    5502,
    5550,
    5592,
    5634,
    5676
    };

static const MIDL_STUBLESS_PROXY_INFO IvbWB_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IvbWB_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IvbWB_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IvbWB_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(141) _IvbWBProxyVtbl = 
{
    &IvbWB_ProxyInfo,
    &IID_IvbWB,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_Count */ ,
    (void *) (INT_PTR) -1 /* IvbWB::RemoveBrowser */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Refresh */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Stop */ ,
    (void *) (INT_PTR) -1 /* IvbWB::GoBack */ ,
    (void *) (INT_PTR) -1 /* IvbWB::GoForward */ ,
    (void *) (INT_PTR) -1 /* IvbWB::GoHome */ ,
    (void *) (INT_PTR) -1 /* IvbWB::NavigateSimple */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_WebBrowser */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_LocationURL */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_Offline */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_Offline */ ,
    (void *) (INT_PTR) -1 /* IvbWB::ReadyState */ ,
    (void *) (INT_PTR) -1 /* IvbWB::GoSearch */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Refresh2 */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_Busy */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_RegisterAsBrowser */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_RegisterAsBrowser */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_RegisterAsDropTarget */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_RegisterAsDropTarget */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_Silent */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_Silent */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_LocationName */ ,
    (void *) (INT_PTR) -1 /* IvbWB::SelectAll */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Paste */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Copy */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Cut */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Undo */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Redo */ ,
    (void *) (INT_PTR) -1 /* IvbWB::ClearSelection */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Delete */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Find */ ,
    (void *) (INT_PTR) -1 /* IvbWB::PasteSpecial */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Spell */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Properties */ ,
    (void *) (INT_PTR) -1 /* IvbWB::NewWindow */ ,
    (void *) (INT_PTR) -1 /* IvbWB::FileOpen */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Save */ ,
    (void *) (INT_PTR) -1 /* IvbWB::SaveAs */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Print */ ,
    (void *) (INT_PTR) -1 /* IvbWB::PrintPreview */ ,
    (void *) (INT_PTR) -1 /* IvbWB::PageSetup */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Print2 */ ,
    (void *) (INT_PTR) -1 /* IvbWB::PrintPreview2 */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_HWNDShellDocObjectView */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_HWNDInternetExplorerServer */ ,
    (void *) (INT_PTR) -1 /* IvbWB::ViewSource */ ,
    (void *) (INT_PTR) -1 /* IvbWB::AddToFavorites */ ,
    (void *) (INT_PTR) -1 /* IvbWB::SetFocusW */ ,
    (void *) (INT_PTR) -1 /* IvbWB::PlaceWBOnTop */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_HWNDMainWnd */ ,
    (void *) (INT_PTR) -1 /* IvbWB::AnyDocHasFocus */ ,
    (void *) (INT_PTR) -1 /* IvbWB::ExecWB */ ,
    (void *) (INT_PTR) -1 /* IvbWB::QueryStatusWB */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_StartupURL */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_StartupURL */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_UseIEDefaultFileDownload */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_UseIEDefaultFileDownload */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_HWNDShellEmbedding */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_FramesCount */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_WBVisible */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_WBVisible */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_Application */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_Document */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ActiveElementObj */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ActiveDocumentObj */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Navigate2 */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Navigate */ ,
    (void *) (INT_PTR) -1 /* IvbWB::AddBrowser */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ObjectWB */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ContextMenuAction */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_ContextMenuAction */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_DocumentDownloadControlFlags */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_DocumentDownloadControlFlags */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_DocumentHostUiFlags */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_DocumentHostUiFlags */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_DocumentHostUiDoubleClickAction */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_DocumentHostUiDoubleClickAction */ ,
    (void *) (INT_PTR) -1 /* IvbWB::FindTextSimple */ ,
    (void *) (INT_PTR) -1 /* IvbWB::FindAndHighlightAllText */ ,
    (void *) (INT_PTR) -1 /* IvbWB::FindAnyTextMatch */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_IsDocFrameset */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ucScheme */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_ucScheme */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ucHostName */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_ucHostName */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ucPort */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_ucPort */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ucUserName */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_ucUserName */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ucPassword */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_ucPassword */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ucUrlPath */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_ucUrlPath */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ucExtraInfo */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_ucExtraInfo */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ucFullURL */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_ucFullURL */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ucFileName */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ucFileExtension */ ,
    (void *) (INT_PTR) -1 /* IvbWB::ucInternetCrackUrl */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ucInternetScheme */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_ucInternetScheme */ ,
    (void *) (INT_PTR) -1 /* IvbWB::ucInternetCreateUrl */ ,
    (void *) (INT_PTR) -1 /* IvbWB::CancelFileDl */ ,
    (void *) (INT_PTR) -1 /* IvbWB::DownloadUrlAsync */ ,
    (void *) (INT_PTR) -1 /* IvbWB::RegisterHTTPprotocol */ ,
    (void *) (INT_PTR) -1 /* IvbWB::RegisterHTTPSprotocol */ ,
    (void *) (INT_PTR) -1 /* IvbWB::DisplayCertificateDialog */ ,
    (void *) (INT_PTR) -1 /* IvbWB::LoadHTMLFromString */ ,
    (void *) (INT_PTR) -1 /* IvbWB::DrawWBThumbnailOnWnd */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_WBPageTextSize */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_WBPageTextSize */ ,
    (void *) (INT_PTR) -1 /* IvbWB::ucResetFieldsToDefault */ ,
    (void *) (INT_PTR) -1 /* IvbWB::SubclassWnd */ ,
    (void *) (INT_PTR) -1 /* IvbWB::UnSubclassWnd */ ,
    (void *) (INT_PTR) -1 /* IvbWB::AddMessage */ ,
    (void *) (INT_PTR) -1 /* IvbWB::SetupShellAutoComplete */ ,
    (void *) (INT_PTR) -1 /* IvbWB::SaveAsBitmap */ ,
    (void *) (INT_PTR) -1 /* IvbWB::WBPostData */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_SourceOnDocComplete */ ,
    IvbWB_put_SourceOnDocComplete_Proxy ,
    IvbWB_OrganizeFavorites_Proxy ,
    IvbWB_ViewIEOptions_Proxy ,
    IvbWB_FindAndHighlightAllTextFrames_Proxy ,
    IvbWB_SetupWindowsHook_Proxy ,
    IvbWB_HookProcNCode_Proxy ,
    IvbWB_SetupCustomAutoComplete_Proxy ,
    IvbWB_CustomAutoCompleteAddString_Proxy ,
    IvbWB_CustomAutoCompleteEnable_Proxy ,
    IvbWB_QueryIERegistryOption_Proxy ,
    IvbWB_SetIERegistryOption_Proxy ,
    IvbWB_DecodeMime_Proxy ,
    IvbWB_DeleteIEFiles_Proxy
};


static const PRPC_STUB_FUNCTION IvbWB_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IvbWBStubVtbl =
{
    &IID_IvbWB,
    &IvbWB_ServerInfo,
    141,
    &IvbWB_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x6000169, /* MIDL Version 6.0.361 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0   /* Reserved5 */
    };

const CInterfaceProxyVtbl * _vbMHWB_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IvbWBProxyVtbl,
    ( CInterfaceProxyVtbl *) &_INewWindowManagerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHTMLOMWindowServicesProxyVtbl,
    0
};

const CInterfaceStubVtbl * _vbMHWB_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IvbWBStubVtbl,
    ( CInterfaceStubVtbl *) &_INewWindowManagerStubVtbl,
    ( CInterfaceStubVtbl *) &_IHTMLOMWindowServicesStubVtbl,
    0
};

PCInterfaceName const _vbMHWB_InterfaceNamesList[] = 
{
    "IvbWB",
    "INewWindowManager",
    "IHTMLOMWindowServices",
    0
};

const IID *  _vbMHWB_BaseIIDList[] = 
{
    &IID_IDispatch,
    0,
    0,
    0
};


#define _vbMHWB_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _vbMHWB, pIID, n)

int __stdcall _vbMHWB_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _vbMHWB, 3, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _vbMHWB, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _vbMHWB, 3, *pIndex )
    
}

const ExtendedProxyFileInfo vbMHWB_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _vbMHWB_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _vbMHWB_StubVtblList,
    (const PCInterfaceName * ) & _vbMHWB_InterfaceNamesList,
    (const IID ** ) & _vbMHWB_BaseIIDList,
    & _vbMHWB_IID_Lookup, 
    3,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Wed Sep 20 20:31:21 2006
 */
/* Compiler settings for C:\Mike\vbMHWB\vbMHWB.idl:
    Oicf, W1, Zp8, env=Win64 (32b run,appending)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if defined(_M_IA64) || defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extent to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "vbMHWB.h"

#define TYPE_FORMAT_STRING_SIZE   1049                              
#define PROC_FORMAT_STRING_SIZE   5991                              
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   2            

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO INewWindowManager_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO INewWindowManager_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHTMLOMWindowServices_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHTMLOMWindowServices_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IvbWB_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IvbWB_ProxyInfo;

/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IvbWB_put_SourceOnDocComplete_Proxy( 
    IvbWB * This,
    /* [defaultvalue][in] */ short wbUID,
    /* [in] */ VARIANT_BOOL newVal)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[5382],
                  ( unsigned char * )This,
                  wbUID,
                  newVal);
return ( HRESULT  )_RetVal.Simple;

}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_OrganizeFavorites_Proxy( 
    IvbWB * This)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[5426],
                  ( unsigned char * )This);
return ( HRESULT  )_RetVal.Simple;

}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_ViewIEOptions_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[5458],
                  ( unsigned char * )This,
                  wbUID);
return ( HRESULT  )_RetVal.Simple;

}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_FindAndHighlightAllTextFrames_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [in] */ BSTR TextToFind,
    /* [in] */ VARIANT_BOOL bMatchWholeWord,
    /* [in] */ VARIANT_BOOL bMatchCase,
    /* [in] */ BSTR HighlightColor,
    /* [out][in] */ long *NumOfMatchsFound)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[5496],
                  ( unsigned char * )This,
                  wbUID,
                  TextToFind,
                  bMatchWholeWord,
                  bMatchCase,
                  HighlightColor,
                  NumOfMatchsFound);
return ( HRESULT  )_RetVal.Simple;

}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_SetupWindowsHook_Proxy( 
    IvbWB * This,
    /* [in] */ WINDOWSHOOK_TYPES lHookType,
    /* [in] */ long hwndTargetWnd,
    /* [in] */ VARIANT_BOOL bStart,
    /* [out][in] */ long *lUWMHookMsgID)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[5564],
                  ( unsigned char * )This,
                  lHookType,
                  hwndTargetWnd,
                  bStart,
                  lUWMHookMsgID);
return ( HRESULT  )_RetVal.Simple;

}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_HookProcNCode_Proxy( 
    IvbWB * This,
    /* [in] */ WINDOWSHOOK_TYPES lHookType,
    /* [out][in] */ long *nCode)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[5620],
                  ( unsigned char * )This,
                  lHookType,
                  nCode);
return ( HRESULT  )_RetVal.Simple;

}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_SetupCustomAutoComplete_Proxy( 
    IvbWB * This,
    /* [in] */ long hwndTarget,
    /* [in] */ VARIANT_BOOL IsTargetComboBox,
    /* [in] */ long lCustomAutoCompleteFlags,
    /* [in] */ VARIANT *varStringArray)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[5664],
                  ( unsigned char * )This,
                  hwndTarget,
                  IsTargetComboBox,
                  lCustomAutoCompleteFlags,
                  varStringArray);
return ( HRESULT  )_RetVal.Simple;

}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_CustomAutoCompleteAddString_Proxy( 
    IvbWB * This,
    /* [in] */ long hwndTarget,
    /* [in] */ VARIANT_BOOL IsTargetComboBox,
    /* [in] */ BSTR strItem)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[5720],
                  ( unsigned char * )This,
                  hwndTarget,
                  IsTargetComboBox,
                  strItem);
return ( HRESULT  )_RetVal.Simple;

}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_CustomAutoCompleteEnable_Proxy( 
    IvbWB * This,
    /* [in] */ long hwndTarget,
    /* [in] */ VARIANT_BOOL IsTargetComboBox,
    /* [in] */ VARIANT_BOOL bEnable)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[5770],
                  ( unsigned char * )This,
                  hwndTarget,
                  IsTargetComboBox,
                  bEnable);
return ( HRESULT  )_RetVal.Simple;

}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_QueryIERegistryOption_Proxy( 
    IvbWB * This,
    /* [in] */ long IeRegistryOptionsFlag,
    /* [in] */ VARIANT *varBuffer)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[5820],
                  ( unsigned char * )This,
                  IeRegistryOptionsFlag,
                  varBuffer);
return ( HRESULT  )_RetVal.Simple;

}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_SetIERegistryOption_Proxy( 
    IvbWB * This,
    /* [in] */ long IeRegistryOptionsFlag,
    /* [in] */ VARIANT *varBuffer)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[5864],
                  ( unsigned char * )This,
                  IeRegistryOptionsFlag,
                  varBuffer);
return ( HRESULT  )_RetVal.Simple;

}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_DecodeMime_Proxy( 
    IvbWB * This,
    /* [in] */ BSTR strToDecode,
    /* [out][in] */ BSTR *strDecoded)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[5908],
                  ( unsigned char * )This,
                  strToDecode,
                  strDecoded);
return ( HRESULT  )_RetVal.Simple;

}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_DeleteIEFiles_Proxy( 
    IvbWB * This,
    /* [in] */ DELETE_IE_FILES_FLAGS enumWhichFiles)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[5952],
                  ( unsigned char * )This,
                  enumWhichFiles);
return ( HRESULT  )_RetVal.Simple;

}


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure EvaluateNewWindow */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x3 ),	/* 3 */
/*  8 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 10 */	NdrFcShort( 0x18 ),	/* 24 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 16 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pszUrl */

/* 26 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 28 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 30 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter pszName */

/* 32 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 34 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 36 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter pszUrlContext */

/* 38 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 40 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 42 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter pszFeatures */

/* 44 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 46 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 48 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter fReplace */

/* 50 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 52 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 54 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwFlags */

/* 56 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 58 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 60 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwUserActionTime */

/* 62 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 64 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 66 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 68 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 70 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 72 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure moveTo */

/* 74 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 76 */	NdrFcLong( 0x0 ),	/* 0 */
/* 80 */	NdrFcShort( 0x3 ),	/* 3 */
/* 82 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 84 */	NdrFcShort( 0x10 ),	/* 16 */
/* 86 */	NdrFcShort( 0x8 ),	/* 8 */
/* 88 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 90 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */
/* 96 */	NdrFcShort( 0x0 ),	/* 0 */
/* 98 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter x */

/* 100 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 102 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 104 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter y */

/* 106 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 108 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 112 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 114 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure moveBy */

/* 118 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 120 */	NdrFcLong( 0x0 ),	/* 0 */
/* 124 */	NdrFcShort( 0x4 ),	/* 4 */
/* 126 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 128 */	NdrFcShort( 0x10 ),	/* 16 */
/* 130 */	NdrFcShort( 0x8 ),	/* 8 */
/* 132 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 134 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 142 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter x */

/* 144 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 146 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 148 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter y */

/* 150 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 152 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 154 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 156 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 158 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 160 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure resizeTo */

/* 162 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 164 */	NdrFcLong( 0x0 ),	/* 0 */
/* 168 */	NdrFcShort( 0x5 ),	/* 5 */
/* 170 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 172 */	NdrFcShort( 0x10 ),	/* 16 */
/* 174 */	NdrFcShort( 0x8 ),	/* 8 */
/* 176 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 178 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 186 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter x */

/* 188 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 190 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 192 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter y */

/* 194 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 196 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 198 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 200 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 202 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 204 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure resizeBy */

/* 206 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 208 */	NdrFcLong( 0x0 ),	/* 0 */
/* 212 */	NdrFcShort( 0x6 ),	/* 6 */
/* 214 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 216 */	NdrFcShort( 0x10 ),	/* 16 */
/* 218 */	NdrFcShort( 0x8 ),	/* 8 */
/* 220 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 222 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 230 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter x */

/* 232 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 234 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 236 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter y */

/* 238 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 240 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 242 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 244 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 246 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 248 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Count */

/* 250 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 252 */	NdrFcLong( 0x0 ),	/* 0 */
/* 256 */	NdrFcShort( 0x7 ),	/* 7 */
/* 258 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 262 */	NdrFcShort( 0x22 ),	/* 34 */
/* 264 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 266 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 274 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 276 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 278 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 280 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 282 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 284 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoveBrowser */

/* 288 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 294 */	NdrFcShort( 0x8 ),	/* 8 */
/* 296 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 298 */	NdrFcShort( 0x6 ),	/* 6 */
/* 300 */	NdrFcShort( 0x8 ),	/* 8 */
/* 302 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 304 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 312 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUIDToRemove */

/* 314 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 316 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 318 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 320 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 322 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 324 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Refresh */

/* 326 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 328 */	NdrFcLong( 0x0 ),	/* 0 */
/* 332 */	NdrFcShort( 0x9 ),	/* 9 */
/* 334 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 336 */	NdrFcShort( 0x6 ),	/* 6 */
/* 338 */	NdrFcShort( 0x8 ),	/* 8 */
/* 340 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 342 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 350 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 352 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 354 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 356 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 358 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 360 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 362 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Stop */

/* 364 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 366 */	NdrFcLong( 0x0 ),	/* 0 */
/* 370 */	NdrFcShort( 0xa ),	/* 10 */
/* 372 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 374 */	NdrFcShort( 0x6 ),	/* 6 */
/* 376 */	NdrFcShort( 0x8 ),	/* 8 */
/* 378 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 380 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 388 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 390 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 392 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 394 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 396 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 398 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 400 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GoBack */

/* 402 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 404 */	NdrFcLong( 0x0 ),	/* 0 */
/* 408 */	NdrFcShort( 0xb ),	/* 11 */
/* 410 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 412 */	NdrFcShort( 0x6 ),	/* 6 */
/* 414 */	NdrFcShort( 0x8 ),	/* 8 */
/* 416 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 418 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 426 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 428 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 430 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 432 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 434 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 436 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 438 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GoForward */

/* 440 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 442 */	NdrFcLong( 0x0 ),	/* 0 */
/* 446 */	NdrFcShort( 0xc ),	/* 12 */
/* 448 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 450 */	NdrFcShort( 0x6 ),	/* 6 */
/* 452 */	NdrFcShort( 0x8 ),	/* 8 */
/* 454 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 456 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 464 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 466 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 468 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 470 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 472 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 474 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 476 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GoHome */

/* 478 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 480 */	NdrFcLong( 0x0 ),	/* 0 */
/* 484 */	NdrFcShort( 0xd ),	/* 13 */
/* 486 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 488 */	NdrFcShort( 0x6 ),	/* 6 */
/* 490 */	NdrFcShort( 0x8 ),	/* 8 */
/* 492 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 494 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 502 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 504 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 506 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 508 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 510 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 512 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure NavigateSimple */

/* 516 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 518 */	NdrFcLong( 0x0 ),	/* 0 */
/* 522 */	NdrFcShort( 0xe ),	/* 14 */
/* 524 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 526 */	NdrFcShort( 0x6 ),	/* 6 */
/* 528 */	NdrFcShort( 0x8 ),	/* 8 */
/* 530 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 532 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 536 */	NdrFcShort( 0x1 ),	/* 1 */
/* 538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 540 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 542 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 544 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 546 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter URL */

/* 548 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 550 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 552 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 554 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 556 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 558 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_WebBrowser */

/* 560 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 562 */	NdrFcLong( 0x0 ),	/* 0 */
/* 566 */	NdrFcShort( 0xf ),	/* 15 */
/* 568 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 570 */	NdrFcShort( 0x6 ),	/* 6 */
/* 572 */	NdrFcShort( 0x8 ),	/* 8 */
/* 574 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 576 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 584 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 586 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 588 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 590 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 592 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 594 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 596 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 598 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 600 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 602 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_LocationURL */

/* 604 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 606 */	NdrFcLong( 0x0 ),	/* 0 */
/* 610 */	NdrFcShort( 0x10 ),	/* 16 */
/* 612 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 614 */	NdrFcShort( 0x6 ),	/* 6 */
/* 616 */	NdrFcShort( 0x8 ),	/* 8 */
/* 618 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 620 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 622 */	NdrFcShort( 0x1 ),	/* 1 */
/* 624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 628 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 630 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 632 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 634 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pURL */

/* 636 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 638 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 640 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 642 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 644 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 646 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Offline */

/* 648 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 650 */	NdrFcLong( 0x0 ),	/* 0 */
/* 654 */	NdrFcShort( 0x11 ),	/* 17 */
/* 656 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 658 */	NdrFcShort( 0x6 ),	/* 6 */
/* 660 */	NdrFcShort( 0x22 ),	/* 34 */
/* 662 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 664 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 672 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 674 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 676 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 678 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 680 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 682 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 684 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 686 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 688 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 690 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Offline */

/* 692 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 694 */	NdrFcLong( 0x0 ),	/* 0 */
/* 698 */	NdrFcShort( 0x12 ),	/* 18 */
/* 700 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 702 */	NdrFcShort( 0xc ),	/* 12 */
/* 704 */	NdrFcShort( 0x8 ),	/* 8 */
/* 706 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 708 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 712 */	NdrFcShort( 0x0 ),	/* 0 */
/* 714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 716 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 718 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 720 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 722 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 724 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 726 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 728 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 730 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 732 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 734 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReadyState */

/* 736 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 738 */	NdrFcLong( 0x0 ),	/* 0 */
/* 742 */	NdrFcShort( 0x13 ),	/* 19 */
/* 744 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 746 */	NdrFcShort( 0x6 ),	/* 6 */
/* 748 */	NdrFcShort( 0x24 ),	/* 36 */
/* 750 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 752 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 760 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 762 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 764 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 766 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter plReadyState */

/* 768 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 770 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 772 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 774 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 776 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 778 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GoSearch */

/* 780 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 782 */	NdrFcLong( 0x0 ),	/* 0 */
/* 786 */	NdrFcShort( 0x14 ),	/* 20 */
/* 788 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 790 */	NdrFcShort( 0x6 ),	/* 6 */
/* 792 */	NdrFcShort( 0x8 ),	/* 8 */
/* 794 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 796 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 804 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 806 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 808 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 810 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 812 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 814 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 816 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Refresh2 */

/* 818 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 820 */	NdrFcLong( 0x0 ),	/* 0 */
/* 824 */	NdrFcShort( 0x15 ),	/* 21 */
/* 826 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 828 */	NdrFcShort( 0x6 ),	/* 6 */
/* 830 */	NdrFcShort( 0x8 ),	/* 8 */
/* 832 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 834 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 838 */	NdrFcShort( 0x20 ),	/* 32 */
/* 840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 842 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 844 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 846 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 848 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter level */

/* 850 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 852 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 854 */	NdrFcShort( 0x3fe ),	/* Type Offset=1022 */

	/* Return value */

/* 856 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 858 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 860 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Busy */

/* 862 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 864 */	NdrFcLong( 0x0 ),	/* 0 */
/* 868 */	NdrFcShort( 0x16 ),	/* 22 */
/* 870 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 872 */	NdrFcShort( 0x6 ),	/* 6 */
/* 874 */	NdrFcShort( 0x22 ),	/* 34 */
/* 876 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 878 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 886 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 888 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 890 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 892 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 894 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 896 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 898 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 900 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 902 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 904 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RegisterAsBrowser */

/* 906 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 908 */	NdrFcLong( 0x0 ),	/* 0 */
/* 912 */	NdrFcShort( 0x17 ),	/* 23 */
/* 914 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 916 */	NdrFcShort( 0x6 ),	/* 6 */
/* 918 */	NdrFcShort( 0x22 ),	/* 34 */
/* 920 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 922 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 930 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 932 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 934 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 936 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 938 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 940 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 942 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 944 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 946 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 948 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_RegisterAsBrowser */

/* 950 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 952 */	NdrFcLong( 0x0 ),	/* 0 */
/* 956 */	NdrFcShort( 0x18 ),	/* 24 */
/* 958 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 960 */	NdrFcShort( 0xc ),	/* 12 */
/* 962 */	NdrFcShort( 0x8 ),	/* 8 */
/* 964 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 966 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 972 */	NdrFcShort( 0x0 ),	/* 0 */
/* 974 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 976 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 978 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 980 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 982 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 984 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 986 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 988 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 990 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 992 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RegisterAsDropTarget */

/* 994 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 996 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1000 */	NdrFcShort( 0x19 ),	/* 25 */
/* 1002 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1004 */	NdrFcShort( 0xc ),	/* 12 */
/* 1006 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1008 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 1010 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1014 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1018 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1020 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1022 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1024 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bUseIEDefault */

/* 1026 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1028 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1030 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1032 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1034 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1036 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1038 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1040 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1042 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_RegisterAsDropTarget */

/* 1044 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1046 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1050 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1052 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1054 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1056 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1058 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 1060 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1062 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1064 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1066 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1068 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1070 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1072 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1074 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bUseIEDefault */

/* 1076 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1078 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1080 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 1082 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1084 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1086 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1088 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1090 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1092 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Silent */

/* 1094 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1096 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1100 */	NdrFcShort( 0x1b ),	/* 27 */
/* 1102 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1104 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1106 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1108 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1110 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1118 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1120 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1122 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1124 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1126 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1128 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1130 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1132 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1134 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Silent */

/* 1138 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1140 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1144 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1146 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1148 */	NdrFcShort( 0xc ),	/* 12 */
/* 1150 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1152 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1154 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1162 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1164 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1166 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1168 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 1170 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1172 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1174 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1176 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1178 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1180 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_LocationName */

/* 1182 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1184 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1188 */	NdrFcShort( 0x1d ),	/* 29 */
/* 1190 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1192 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1194 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1196 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1198 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1200 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1206 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1208 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1210 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1212 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1214 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1216 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1218 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 1220 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1222 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1224 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SelectAll */

/* 1226 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1228 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1232 */	NdrFcShort( 0x1e ),	/* 30 */
/* 1234 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1236 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1238 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1240 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1242 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1250 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1252 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1254 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1256 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1258 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1260 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1262 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Paste */

/* 1264 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1266 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1270 */	NdrFcShort( 0x1f ),	/* 31 */
/* 1272 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1274 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1276 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1278 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1280 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1288 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1290 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1292 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1294 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1296 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1298 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1300 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Copy */

/* 1302 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1304 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1308 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1310 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1312 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1314 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1316 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1318 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1322 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1326 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1328 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1330 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1332 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1334 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1336 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1338 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Cut */

/* 1340 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1342 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1346 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1348 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1350 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1352 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1354 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1356 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1364 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1366 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1368 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1370 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1372 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1374 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1376 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Undo */

/* 1378 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1380 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1384 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1386 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1388 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1390 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1392 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1394 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1402 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1404 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1406 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1408 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1410 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1412 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1414 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Redo */

/* 1416 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1418 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1422 */	NdrFcShort( 0x23 ),	/* 35 */
/* 1424 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1426 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1428 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1430 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1432 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1440 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1442 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1444 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1446 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1448 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1450 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1452 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ClearSelection */

/* 1454 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1456 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1460 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1462 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1464 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1466 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1468 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1470 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1478 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1480 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1482 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1484 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1486 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1488 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1490 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Delete */

/* 1492 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1494 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1498 */	NdrFcShort( 0x25 ),	/* 37 */
/* 1500 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1502 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1504 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1506 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1508 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1516 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1518 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1520 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1522 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1524 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1526 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1528 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Find */

/* 1530 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1532 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1536 */	NdrFcShort( 0x26 ),	/* 38 */
/* 1538 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1540 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1542 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1544 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1546 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1554 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1556 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1558 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1560 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1562 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1564 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1566 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PasteSpecial */

/* 1568 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1570 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1574 */	NdrFcShort( 0x27 ),	/* 39 */
/* 1576 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1578 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1580 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1582 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1584 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1590 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1592 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1594 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1596 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1598 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1600 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1602 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1604 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Spell */

/* 1606 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1608 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1612 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1614 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1616 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1618 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1620 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1622 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1630 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1632 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1634 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1636 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1638 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1640 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1642 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Properties */

/* 1644 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1646 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1650 */	NdrFcShort( 0x29 ),	/* 41 */
/* 1652 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1654 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1656 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1658 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1660 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1662 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1668 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1670 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1672 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1674 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1676 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1678 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1680 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure NewWindow */

/* 1682 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1684 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1688 */	NdrFcShort( 0x2a ),	/* 42 */
/* 1690 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1692 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1694 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1696 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1698 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1706 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1708 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1710 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1712 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1714 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1716 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1718 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FileOpen */

/* 1720 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1722 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1726 */	NdrFcShort( 0x2b ),	/* 43 */
/* 1728 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1730 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1732 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1734 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1736 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1744 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1746 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1748 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1750 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1752 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1754 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1756 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Save */

/* 1758 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1760 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1764 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1766 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1768 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1770 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1772 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1774 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1782 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1784 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1786 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1788 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1790 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1792 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1794 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SaveAs */

/* 1796 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1798 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1802 */	NdrFcShort( 0x2d ),	/* 45 */
/* 1804 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1806 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1808 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1810 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1812 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1814 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1820 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1822 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1824 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1826 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1828 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1830 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Print */

/* 1834 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1836 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1840 */	NdrFcShort( 0x2e ),	/* 46 */
/* 1842 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1844 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1846 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1848 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1850 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1854 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1858 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1860 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1862 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1864 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1866 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1868 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1870 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PrintPreview */

/* 1872 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1874 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1878 */	NdrFcShort( 0x2f ),	/* 47 */
/* 1880 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1882 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1884 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1886 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1888 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1890 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1896 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1898 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1900 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1902 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1904 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1906 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1908 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PageSetup */

/* 1910 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1912 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1916 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1918 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1920 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1922 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1924 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1926 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1930 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1934 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1936 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1938 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1940 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1942 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1944 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1946 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Print2 */

/* 1948 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1950 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1954 */	NdrFcShort( 0x31 ),	/* 49 */
/* 1956 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1958 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1960 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1962 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1964 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1972 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 1974 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1976 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1978 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1980 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1982 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1984 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PrintPreview2 */

/* 1986 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1988 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1992 */	NdrFcShort( 0x32 ),	/* 50 */
/* 1994 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1996 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1998 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2000 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2002 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2010 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2012 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2014 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2016 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2018 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2020 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2022 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_HWNDShellDocObjectView */

/* 2024 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2026 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2030 */	NdrFcShort( 0x33 ),	/* 51 */
/* 2032 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2034 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2036 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2038 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2040 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2042 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2048 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2050 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2052 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2054 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 2056 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2058 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2060 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2062 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2064 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2066 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_HWNDInternetExplorerServer */

/* 2068 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2070 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2074 */	NdrFcShort( 0x34 ),	/* 52 */
/* 2076 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2078 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2080 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2082 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2084 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2092 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2094 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2096 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2098 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 2100 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2102 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2104 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2106 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2108 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ViewSource */

/* 2112 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2114 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2118 */	NdrFcShort( 0x35 ),	/* 53 */
/* 2120 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2122 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2124 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2126 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2128 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2136 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2138 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2140 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2142 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2144 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2146 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2148 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddToFavorites */

/* 2150 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2152 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2156 */	NdrFcShort( 0x36 ),	/* 54 */
/* 2158 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2160 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2162 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2164 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2166 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2174 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2176 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2178 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2180 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2182 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2184 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2186 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFocusW */

/* 2188 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2190 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2194 */	NdrFcShort( 0x37 ),	/* 55 */
/* 2196 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2198 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2200 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2202 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2204 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2212 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2214 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2216 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2218 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2220 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2222 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2224 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PlaceWBOnTop */

/* 2226 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2228 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2232 */	NdrFcShort( 0x38 ),	/* 56 */
/* 2234 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2236 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2238 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2240 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2242 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2250 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2252 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2254 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2256 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2258 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2260 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2262 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_HWNDMainWnd */

/* 2264 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2266 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2270 */	NdrFcShort( 0x39 ),	/* 57 */
/* 2272 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2276 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2278 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2280 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2288 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 2290 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2292 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2294 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2296 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2298 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2300 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AnyDocHasFocus */

/* 2302 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2304 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2308 */	NdrFcShort( 0x3a ),	/* 58 */
/* 2310 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2314 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2316 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2318 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2322 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2326 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2328 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2330 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2332 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2334 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2336 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2338 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ExecWB */

/* 2340 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2342 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2346 */	NdrFcShort( 0x3b ),	/* 59 */
/* 2348 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 2350 */	NdrFcShort( 0x16 ),	/* 22 */
/* 2352 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2354 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2356 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2360 */	NdrFcShort( 0x40 ),	/* 64 */
/* 2362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2364 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2366 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2368 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2370 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter cmdID */

/* 2372 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2374 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2376 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter cmdExecOpt */

/* 2378 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2380 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2382 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pvaIn */

/* 2384 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2386 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2388 */	NdrFcShort( 0x3fe ),	/* Type Offset=1022 */

	/* Parameter pvaOut */

/* 2390 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2392 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2394 */	NdrFcShort( 0x3fe ),	/* Type Offset=1022 */

	/* Return value */

/* 2396 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2398 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 2400 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure QueryStatusWB */

/* 2402 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2404 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2408 */	NdrFcShort( 0x3c ),	/* 60 */
/* 2410 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2412 */	NdrFcShort( 0xe ),	/* 14 */
/* 2414 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2416 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 2418 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2426 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2428 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2430 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2432 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter cmdID */

/* 2434 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2436 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2438 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pcmdf */

/* 2440 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2442 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2444 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2446 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2448 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2450 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_StartupURL */

/* 2452 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2454 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2458 */	NdrFcShort( 0x3d ),	/* 61 */
/* 2460 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2464 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2466 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2468 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2470 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2476 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 2478 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 2480 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2482 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 2484 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2486 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2488 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_StartupURL */

/* 2490 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2492 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2496 */	NdrFcShort( 0x3e ),	/* 62 */
/* 2498 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2502 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2504 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2506 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2508 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2510 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2514 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 2516 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2518 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2520 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 2522 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2524 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2526 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_UseIEDefaultFileDownload */

/* 2528 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2530 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2534 */	NdrFcShort( 0x3f ),	/* 63 */
/* 2536 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2538 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2540 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2542 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2544 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2552 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2554 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2556 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2558 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 2560 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2562 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2564 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2566 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2568 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2570 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_UseIEDefaultFileDownload */

/* 2572 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2574 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2578 */	NdrFcShort( 0x40 ),	/* 64 */
/* 2580 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2582 */	NdrFcShort( 0xc ),	/* 12 */
/* 2584 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2586 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2588 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2590 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2596 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2598 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2600 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2602 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 2604 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2606 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2608 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2610 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2612 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2614 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_HWNDShellEmbedding */

/* 2616 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2618 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2622 */	NdrFcShort( 0x41 ),	/* 65 */
/* 2624 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2626 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2628 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2630 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2632 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2634 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2640 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2642 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2644 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2646 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 2648 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2650 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2652 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2654 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2656 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2658 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_FramesCount */

/* 2660 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2662 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2666 */	NdrFcShort( 0x42 ),	/* 66 */
/* 2668 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2670 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2672 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2674 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2676 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2684 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2686 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2688 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2690 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 2692 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2694 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2696 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2698 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2700 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2702 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_WBVisible */

/* 2704 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2706 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2710 */	NdrFcShort( 0x43 ),	/* 67 */
/* 2712 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2714 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2716 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2718 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2720 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2728 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2730 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2732 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2734 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 2736 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2738 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2740 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2742 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2744 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2746 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_WBVisible */

/* 2748 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2750 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2754 */	NdrFcShort( 0x44 ),	/* 68 */
/* 2756 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2758 */	NdrFcShort( 0xc ),	/* 12 */
/* 2760 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2762 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2764 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2768 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2770 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2772 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2774 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2776 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2778 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 2780 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2782 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2784 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2786 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2788 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2790 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Application */

/* 2792 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2794 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2798 */	NdrFcShort( 0x45 ),	/* 69 */
/* 2800 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2802 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2804 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2806 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2808 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2810 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2814 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2816 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2818 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2820 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2822 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 2824 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2826 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2828 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 2830 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2832 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2834 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Document */

/* 2836 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2838 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2842 */	NdrFcShort( 0x46 ),	/* 70 */
/* 2844 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2846 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2848 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2850 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2852 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2854 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2860 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2862 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2864 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2866 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 2868 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2870 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2872 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 2874 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2876 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2878 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ActiveElementObj */

/* 2880 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2882 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2886 */	NdrFcShort( 0x47 ),	/* 71 */
/* 2888 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2890 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2892 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2894 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2896 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2898 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2900 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2904 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2906 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2908 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2910 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 2912 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2914 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2916 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 2918 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2920 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2922 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ActiveDocumentObj */

/* 2924 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2926 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2930 */	NdrFcShort( 0x48 ),	/* 72 */
/* 2932 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2934 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2936 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2938 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2940 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2946 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2948 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2950 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2952 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2954 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 2956 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2958 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2960 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 2962 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2964 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2966 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Navigate2 */

/* 2968 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2970 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2974 */	NdrFcShort( 0x49 ),	/* 73 */
/* 2976 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 2978 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2980 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2982 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 2984 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2986 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2988 */	NdrFcShort( 0xa0 ),	/* 160 */
/* 2990 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2992 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 2994 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2996 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2998 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter URL */

/* 3000 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3002 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3004 */	NdrFcShort( 0x3fe ),	/* Type Offset=1022 */

	/* Parameter Flags */

/* 3006 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3008 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3010 */	NdrFcShort( 0x3fe ),	/* Type Offset=1022 */

	/* Parameter TargetFrameName */

/* 3012 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3014 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3016 */	NdrFcShort( 0x3fe ),	/* Type Offset=1022 */

	/* Parameter PostData */

/* 3018 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3020 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3022 */	NdrFcShort( 0x3fe ),	/* Type Offset=1022 */

	/* Parameter Headers */

/* 3024 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3026 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3028 */	NdrFcShort( 0x3fe ),	/* Type Offset=1022 */

	/* Return value */

/* 3030 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3032 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 3034 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Navigate */

/* 3036 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3038 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3042 */	NdrFcShort( 0x4a ),	/* 74 */
/* 3044 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 3046 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3048 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3050 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 3052 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3056 */	NdrFcShort( 0x81 ),	/* 129 */
/* 3058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3060 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3062 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3064 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3066 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter URL */

/* 3068 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3070 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3072 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter Flags */

/* 3074 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3076 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3078 */	NdrFcShort( 0x3fe ),	/* Type Offset=1022 */

	/* Parameter TargetFrameName */

/* 3080 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3082 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3084 */	NdrFcShort( 0x3fe ),	/* Type Offset=1022 */

	/* Parameter PostData */

/* 3086 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3088 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3090 */	NdrFcShort( 0x3fe ),	/* Type Offset=1022 */

	/* Parameter Headers */

/* 3092 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3094 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3096 */	NdrFcShort( 0x3fe ),	/* Type Offset=1022 */

	/* Return value */

/* 3098 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3100 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 3102 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddBrowser */

/* 3104 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3106 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3110 */	NdrFcShort( 0x4b ),	/* 75 */
/* 3112 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3114 */	NdrFcShort( 0x20 ),	/* 32 */
/* 3116 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3118 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3120 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3128 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3130 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3132 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3134 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bBringToFront */

/* 3136 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3138 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3140 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3142 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3144 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3146 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ObjectWB */

/* 3148 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3150 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3154 */	NdrFcShort( 0x4c ),	/* 76 */
/* 3156 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3158 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3160 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3162 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 3164 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3172 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3174 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3176 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3178 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 3180 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3182 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3184 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 3186 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3188 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ContextMenuAction */

/* 3192 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3194 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3198 */	NdrFcShort( 0x4d ),	/* 77 */
/* 3200 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3202 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3204 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3206 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3208 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3216 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3218 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3220 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3222 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 3224 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3226 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3228 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3230 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3232 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3234 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ContextMenuAction */

/* 3236 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3238 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3242 */	NdrFcShort( 0x4e ),	/* 78 */
/* 3244 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3246 */	NdrFcShort( 0xe ),	/* 14 */
/* 3248 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3250 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3252 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3260 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3262 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3264 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3266 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 3268 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3270 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3272 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3274 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3276 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3278 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DocumentDownloadControlFlags */

/* 3280 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3282 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3286 */	NdrFcShort( 0x4f ),	/* 79 */
/* 3288 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3290 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3292 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3294 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3296 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3304 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3306 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3308 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3310 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 3312 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3314 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3316 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3318 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3320 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_DocumentDownloadControlFlags */

/* 3324 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3326 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3330 */	NdrFcShort( 0x50 ),	/* 80 */
/* 3332 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3334 */	NdrFcShort( 0xe ),	/* 14 */
/* 3336 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3338 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3340 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3348 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3350 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3352 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3354 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 3356 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3358 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3360 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3362 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3364 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3366 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DocumentHostUiFlags */

/* 3368 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3370 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3374 */	NdrFcShort( 0x51 ),	/* 81 */
/* 3376 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3378 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3380 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3382 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3384 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3392 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3394 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3396 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3398 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 3400 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3402 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3404 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3406 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3408 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3410 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_DocumentHostUiFlags */

/* 3412 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3414 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3418 */	NdrFcShort( 0x52 ),	/* 82 */
/* 3420 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3422 */	NdrFcShort( 0xe ),	/* 14 */
/* 3424 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3426 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3428 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3430 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3436 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3438 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3440 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3442 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 3444 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3446 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3448 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3450 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3452 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3454 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DocumentHostUiDoubleClickAction */

/* 3456 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3458 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3462 */	NdrFcShort( 0x53 ),	/* 83 */
/* 3464 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3466 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3468 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3470 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3472 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3480 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3482 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3484 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3486 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 3488 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3490 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3492 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3494 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3496 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3498 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_DocumentHostUiDoubleClickAction */

/* 3500 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3502 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3506 */	NdrFcShort( 0x54 ),	/* 84 */
/* 3508 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3510 */	NdrFcShort( 0xe ),	/* 14 */
/* 3512 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3514 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3516 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3524 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3526 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3528 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3530 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 3532 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3534 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3536 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3538 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3540 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3542 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindTextSimple */

/* 3544 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3546 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3550 */	NdrFcShort( 0x55 ),	/* 85 */
/* 3552 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 3554 */	NdrFcShort( 0x38 ),	/* 56 */
/* 3556 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3558 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 3560 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3564 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3568 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3570 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3572 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3574 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter TextToFind */

/* 3576 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3578 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3580 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter bDownward */

/* 3582 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3584 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3586 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bMatchWholeWord */

/* 3588 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3590 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3592 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bMatchCase */

/* 3594 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3596 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3598 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bScrollIntoView */

/* 3600 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3602 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3604 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter FindMatch */

/* 3606 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3608 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 3610 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3612 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3614 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 3616 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindAndHighlightAllText */

/* 3618 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3620 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3624 */	NdrFcShort( 0x56 ),	/* 86 */
/* 3626 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 3628 */	NdrFcShort( 0x2e ),	/* 46 */
/* 3630 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3632 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 3634 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3638 */	NdrFcShort( 0x2 ),	/* 2 */
/* 3640 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3642 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3644 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3646 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3648 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter TextToFind */

/* 3650 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3652 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3654 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter bMatchWholeWord */

/* 3656 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3658 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3660 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bMatchCase */

/* 3662 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3664 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3666 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter HighlightColor */

/* 3668 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3670 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3672 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter NumOfMatchsFound */

/* 3674 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3676 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3678 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3680 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3682 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 3684 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindAnyTextMatch */

/* 3686 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3688 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3692 */	NdrFcShort( 0x57 ),	/* 87 */
/* 3694 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 3696 */	NdrFcShort( 0x2c ),	/* 44 */
/* 3698 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3700 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 3702 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3706 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3710 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3712 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3714 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3716 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter TextToFind */

/* 3718 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3720 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3722 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter bMatchWholeWord */

/* 3724 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3726 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3728 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bMatchCase */

/* 3730 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3732 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3734 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter FindMatch */

/* 3736 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3738 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3740 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3742 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3744 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3746 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_IsDocFrameset */

/* 3748 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3750 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3754 */	NdrFcShort( 0x58 ),	/* 88 */
/* 3756 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3758 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3760 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3762 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3764 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3768 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3770 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3772 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 3774 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3776 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3778 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 3780 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3782 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3784 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3786 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3788 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3790 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ucScheme */

/* 3792 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3794 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3798 */	NdrFcShort( 0x59 ),	/* 89 */
/* 3800 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3804 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3806 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3808 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3810 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3814 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3816 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 3818 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 3820 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3822 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 3824 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3826 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3828 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ucScheme */

/* 3830 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3832 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3836 */	NdrFcShort( 0x5a ),	/* 90 */
/* 3838 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3842 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3844 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3846 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3850 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3854 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 3856 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3858 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3860 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 3862 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3864 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3866 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ucHostName */

/* 3868 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3870 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3874 */	NdrFcShort( 0x5b ),	/* 91 */
/* 3876 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3878 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3880 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3882 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3884 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3886 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3890 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3892 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 3894 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 3896 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3898 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 3900 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3902 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3904 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ucHostName */

/* 3906 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3908 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3912 */	NdrFcShort( 0x5c ),	/* 92 */
/* 3914 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3918 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3920 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3922 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3926 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3930 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 3932 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3934 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3936 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 3938 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3940 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3942 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ucPort */

/* 3944 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3946 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3950 */	NdrFcShort( 0x5d ),	/* 93 */
/* 3952 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3954 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3956 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3958 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3960 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3964 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3968 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 3970 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3972 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3974 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3976 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3978 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3980 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ucPort */

/* 3982 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3984 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3988 */	NdrFcShort( 0x5e ),	/* 94 */
/* 3990 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3992 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3994 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3996 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3998 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4006 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 4008 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4010 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4012 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4014 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4016 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4018 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ucUserName */

/* 4020 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4022 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4026 */	NdrFcShort( 0x5f ),	/* 95 */
/* 4028 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4032 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4034 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4036 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 4038 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4042 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4044 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 4046 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 4048 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4050 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 4052 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4054 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4056 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ucUserName */

/* 4058 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4060 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4064 */	NdrFcShort( 0x60 ),	/* 96 */
/* 4066 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4068 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4070 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4072 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4074 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4076 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4078 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4082 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 4084 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4086 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4088 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 4090 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4092 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4094 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ucPassword */

/* 4096 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4098 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4102 */	NdrFcShort( 0x61 ),	/* 97 */
/* 4104 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4108 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4110 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4112 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 4114 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4120 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 4122 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 4124 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4126 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 4128 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4130 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4132 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ucPassword */

/* 4134 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4136 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4140 */	NdrFcShort( 0x62 ),	/* 98 */
/* 4142 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4146 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4148 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4150 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4154 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4158 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 4160 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4162 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4164 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 4166 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4168 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4170 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ucUrlPath */

/* 4172 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4174 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4178 */	NdrFcShort( 0x63 ),	/* 99 */
/* 4180 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4184 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4186 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4188 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 4190 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4196 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 4198 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 4200 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4202 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 4204 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4206 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4208 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ucUrlPath */

/* 4210 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4212 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4216 */	NdrFcShort( 0x64 ),	/* 100 */
/* 4218 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4222 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4224 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4226 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4230 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4234 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 4236 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4238 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4240 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 4242 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4244 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4246 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ucExtraInfo */

/* 4248 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4250 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4254 */	NdrFcShort( 0x65 ),	/* 101 */
/* 4256 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4260 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4262 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4264 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 4266 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4272 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 4274 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 4276 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4278 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 4280 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4282 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4284 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ucExtraInfo */

/* 4286 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4288 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4292 */	NdrFcShort( 0x66 ),	/* 102 */
/* 4294 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4298 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4300 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4302 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4306 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4310 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 4312 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4314 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4316 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 4318 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4320 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ucFullURL */

/* 4324 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4326 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4330 */	NdrFcShort( 0x67 ),	/* 103 */
/* 4332 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4336 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4338 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4340 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 4342 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4348 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 4350 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 4352 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4354 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 4356 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4358 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4360 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ucFullURL */

/* 4362 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4364 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4368 */	NdrFcShort( 0x68 ),	/* 104 */
/* 4370 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4374 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4376 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4378 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4382 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4386 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 4388 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4390 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4392 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 4394 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4396 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4398 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ucFileName */

/* 4400 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4402 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4406 */	NdrFcShort( 0x69 ),	/* 105 */
/* 4408 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4412 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4414 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4416 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 4418 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4424 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 4426 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 4428 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4430 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 4432 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4434 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4436 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ucFileExtension */

/* 4438 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4440 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4444 */	NdrFcShort( 0x6a ),	/* 106 */
/* 4446 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4450 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4452 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4454 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 4456 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4462 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 4464 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 4466 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4468 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 4470 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4472 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4474 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ucInternetCrackUrl */

/* 4476 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4478 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4482 */	NdrFcShort( 0x6b ),	/* 107 */
/* 4484 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4486 */	NdrFcShort( 0x1a ),	/* 26 */
/* 4488 */	NdrFcShort( 0x22 ),	/* 34 */
/* 4490 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4492 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4496 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4500 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter URL */

/* 4502 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4504 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4506 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter bSuccess */

/* 4508 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 4510 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4512 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 4514 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4516 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4518 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ucInternetScheme */

/* 4520 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4522 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4526 */	NdrFcShort( 0x6c ),	/* 108 */
/* 4528 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4532 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4534 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4536 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4544 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 4546 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4548 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4550 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4552 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4554 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4556 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ucInternetScheme */

/* 4558 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4560 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4564 */	NdrFcShort( 0x6d ),	/* 109 */
/* 4566 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4568 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4570 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4572 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4574 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4582 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 4584 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4586 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4588 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4590 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4592 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4594 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ucInternetCreateUrl */

/* 4596 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4598 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4602 */	NdrFcShort( 0x6e ),	/* 110 */
/* 4604 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4608 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4610 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4612 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 4614 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4616 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4618 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4620 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter URL */

/* 4622 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 4624 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4626 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 4628 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4630 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4632 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CancelFileDl */

/* 4634 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4636 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4640 */	NdrFcShort( 0x6f ),	/* 111 */
/* 4642 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4644 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4646 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4648 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4650 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4654 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4658 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter UIDToCancel */

/* 4660 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4662 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4664 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 4666 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4668 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4670 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DownloadUrlAsync */

/* 4672 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4674 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4678 */	NdrFcShort( 0x70 ),	/* 112 */
/* 4680 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 4682 */	NdrFcShort( 0x1a ),	/* 26 */
/* 4684 */	NdrFcShort( 0x22 ),	/* 34 */
/* 4686 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 4688 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4692 */	NdrFcShort( 0x2 ),	/* 2 */
/* 4694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4696 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter URL */

/* 4698 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4700 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4702 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter SaveFileName */

/* 4704 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4706 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4708 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter DLUID */

/* 4710 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 4712 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4714 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 4716 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4718 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4720 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RegisterHTTPprotocol */

/* 4722 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4724 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4728 */	NdrFcShort( 0x71 ),	/* 113 */
/* 4730 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4732 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4734 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4736 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4738 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4746 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 4748 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4750 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4752 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 4754 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4756 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4758 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RegisterHTTPSprotocol */

/* 4760 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4762 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4766 */	NdrFcShort( 0x72 ),	/* 114 */
/* 4768 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4770 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4772 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4774 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4776 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4784 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 4786 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4788 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4790 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 4792 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4794 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4796 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DisplayCertificateDialog */

/* 4798 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4800 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4804 */	NdrFcShort( 0x73 ),	/* 115 */
/* 4806 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4808 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4810 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4812 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4814 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4822 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 4824 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4826 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4828 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 4830 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4832 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4834 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LoadHTMLFromString */

/* 4836 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4838 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4842 */	NdrFcShort( 0x74 ),	/* 116 */
/* 4844 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 4846 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4848 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4850 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 4852 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4854 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4856 */	NdrFcShort( 0x2 ),	/* 2 */
/* 4858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4860 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 4862 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4864 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4866 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter sContent */

/* 4868 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4870 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4872 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter sBaseUrl */

/* 4874 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4876 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4878 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 4880 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4882 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4884 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DrawWBThumbnailOnWnd */

/* 4886 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4888 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4892 */	NdrFcShort( 0x75 ),	/* 117 */
/* 4894 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 4896 */	NdrFcShort( 0x2e ),	/* 46 */
/* 4898 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4900 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x7,		/* 7 */
/* 4902 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4906 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4910 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 4912 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4914 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4916 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter WndHdc */

/* 4918 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4920 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4922 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lX */

/* 4924 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4926 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4928 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lY */

/* 4930 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4932 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4934 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lW */

/* 4936 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4938 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 4940 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lH */

/* 4942 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4944 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 4946 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4948 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4950 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 4952 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_WBPageTextSize */

/* 4954 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4956 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4960 */	NdrFcShort( 0x76 ),	/* 118 */
/* 4962 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4964 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4966 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4968 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 4970 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4972 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4974 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4976 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4978 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 4980 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4982 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4984 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 4986 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4988 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4990 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4992 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4994 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4996 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_WBPageTextSize */

/* 4998 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5000 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5004 */	NdrFcShort( 0x77 ),	/* 119 */
/* 5006 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5008 */	NdrFcShort( 0xe ),	/* 14 */
/* 5010 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5012 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5014 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5018 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5022 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 5024 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5026 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5028 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 5030 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5032 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5034 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5036 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5038 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5040 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ucResetFieldsToDefault */

/* 5042 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5044 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5048 */	NdrFcShort( 0x78 ),	/* 120 */
/* 5050 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5054 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5056 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 5058 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5062 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5064 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5066 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 5068 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5070 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5072 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SubclassWnd */

/* 5074 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5076 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5080 */	NdrFcShort( 0x79 ),	/* 121 */
/* 5082 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5084 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5086 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5088 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5090 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5098 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hwndWnd */

/* 5100 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5102 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5104 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5106 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5108 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UnSubclassWnd */

/* 5112 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5114 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5118 */	NdrFcShort( 0x7a ),	/* 122 */
/* 5120 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5122 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5124 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5126 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5128 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5136 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hwndWnd */

/* 5138 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5140 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5144 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5146 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5148 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddMessage */

/* 5150 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5152 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5156 */	NdrFcShort( 0x7b ),	/* 123 */
/* 5158 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5160 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5162 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5164 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5166 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5174 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hwndWnd */

/* 5176 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5178 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5180 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lMsg */

/* 5182 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5184 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5186 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5188 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5190 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5192 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetupShellAutoComplete */

/* 5194 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5196 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5200 */	NdrFcShort( 0x7c ),	/* 124 */
/* 5202 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5204 */	NdrFcShort( 0x16 ),	/* 22 */
/* 5206 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5208 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 5210 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5218 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hwndTarget */

/* 5220 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5222 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5224 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter IsTargetComboBox */

/* 5226 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5228 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5230 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter lFlags */

/* 5232 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5234 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5236 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5238 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5240 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5242 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SaveAsBitmap */

/* 5244 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5246 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5250 */	NdrFcShort( 0x7d ),	/* 125 */
/* 5252 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5254 */	NdrFcShort( 0x6 ),	/* 6 */
/* 5256 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5258 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 5260 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 5262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5264 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5268 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 5270 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5272 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5274 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter BitmapName */

/* 5276 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 5278 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5280 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 5282 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5284 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WBPostData */

/* 5288 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5294 */	NdrFcShort( 0x7e ),	/* 126 */
/* 5296 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5298 */	NdrFcShort( 0x1a ),	/* 26 */
/* 5300 */	NdrFcShort( 0x22 ),	/* 34 */
/* 5302 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 5304 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 5306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5308 */	NdrFcShort( 0x2 ),	/* 2 */
/* 5310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5312 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter sURL */

/* 5314 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 5316 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5318 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter sData */

/* 5320 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 5322 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5324 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter PostID */

/* 5326 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 5328 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5330 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 5332 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5334 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5336 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_SourceOnDocComplete */

/* 5338 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5340 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5344 */	NdrFcShort( 0x7f ),	/* 127 */
/* 5346 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5348 */	NdrFcShort( 0x6 ),	/* 6 */
/* 5350 */	NdrFcShort( 0x22 ),	/* 34 */
/* 5352 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5354 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5362 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 5364 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5366 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5368 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 5370 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5372 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5374 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 5376 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5378 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5380 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_SourceOnDocComplete */

/* 5382 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5384 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5388 */	NdrFcShort( 0x80 ),	/* 128 */
/* 5390 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5392 */	NdrFcShort( 0xc ),	/* 12 */
/* 5394 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5396 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5398 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5406 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 5408 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5410 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5412 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 5414 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5416 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5418 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 5420 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5422 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5424 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OrganizeFavorites */

/* 5426 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5428 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5432 */	NdrFcShort( 0x81 ),	/* 129 */
/* 5434 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5438 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5440 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 5442 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5450 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 5452 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5454 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5456 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ViewIEOptions */

/* 5458 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5460 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5464 */	NdrFcShort( 0x82 ),	/* 130 */
/* 5466 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5468 */	NdrFcShort( 0x6 ),	/* 6 */
/* 5470 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5472 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5474 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5482 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 5484 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5486 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5488 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 5490 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5492 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5494 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindAndHighlightAllTextFrames */

/* 5496 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5498 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5502 */	NdrFcShort( 0x83 ),	/* 131 */
/* 5504 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 5506 */	NdrFcShort( 0x2e ),	/* 46 */
/* 5508 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5510 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 5512 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 5514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5516 */	NdrFcShort( 0x2 ),	/* 2 */
/* 5518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5520 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wbUID */

/* 5522 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5524 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5526 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter TextToFind */

/* 5528 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 5530 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5532 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter bMatchWholeWord */

/* 5534 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5536 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5538 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bMatchCase */

/* 5540 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5542 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5544 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter HighlightColor */

/* 5546 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 5548 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5550 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter NumOfMatchsFound */

/* 5552 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 5554 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 5556 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5558 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5560 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 5562 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetupWindowsHook */

/* 5564 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5566 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5570 */	NdrFcShort( 0x84 ),	/* 132 */
/* 5572 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 5574 */	NdrFcShort( 0x30 ),	/* 48 */
/* 5576 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5578 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 5580 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5588 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lHookType */

/* 5590 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5592 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5594 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter hwndTargetWnd */

/* 5596 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5598 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5600 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bStart */

/* 5602 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5604 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5606 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter lUWMHookMsgID */

/* 5608 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 5610 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5612 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5614 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5616 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5618 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure HookProcNCode */

/* 5620 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5622 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5626 */	NdrFcShort( 0x85 ),	/* 133 */
/* 5628 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5630 */	NdrFcShort( 0x22 ),	/* 34 */
/* 5632 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5634 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5636 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5640 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5644 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lHookType */

/* 5646 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5648 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5650 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter nCode */

/* 5652 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 5654 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5656 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5658 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5660 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5662 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetupCustomAutoComplete */

/* 5664 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5666 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5670 */	NdrFcShort( 0x86 ),	/* 134 */
/* 5672 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 5674 */	NdrFcShort( 0x16 ),	/* 22 */
/* 5676 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5678 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 5680 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 5682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5684 */	NdrFcShort( 0x20 ),	/* 32 */
/* 5686 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5688 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hwndTarget */

/* 5690 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5692 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5694 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter IsTargetComboBox */

/* 5696 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5698 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5700 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter lCustomAutoCompleteFlags */

/* 5702 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5704 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5706 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter varStringArray */

/* 5708 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5710 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5712 */	NdrFcShort( 0x3fe ),	/* Type Offset=1022 */

	/* Return value */

/* 5714 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5716 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5718 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CustomAutoCompleteAddString */

/* 5720 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5722 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5726 */	NdrFcShort( 0x87 ),	/* 135 */
/* 5728 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5730 */	NdrFcShort( 0xe ),	/* 14 */
/* 5732 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5734 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 5736 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 5738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5740 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5744 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hwndTarget */

/* 5746 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5748 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5750 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter IsTargetComboBox */

/* 5752 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5754 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5756 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter strItem */

/* 5758 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 5760 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5762 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 5764 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5766 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5768 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CustomAutoCompleteEnable */

/* 5770 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5772 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5776 */	NdrFcShort( 0x88 ),	/* 136 */
/* 5778 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5780 */	NdrFcShort( 0x14 ),	/* 20 */
/* 5782 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5784 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 5786 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5794 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hwndTarget */

/* 5796 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5798 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5800 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter IsTargetComboBox */

/* 5802 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5804 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5806 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bEnable */

/* 5808 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5810 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5812 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 5814 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5816 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5818 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure QueryIERegistryOption */

/* 5820 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5822 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5826 */	NdrFcShort( 0x89 ),	/* 137 */
/* 5828 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5830 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5832 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5834 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 5836 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 5838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5840 */	NdrFcShort( 0x20 ),	/* 32 */
/* 5842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5844 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IeRegistryOptionsFlag */

/* 5846 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5848 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5850 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter varBuffer */

/* 5852 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5854 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5856 */	NdrFcShort( 0x3fe ),	/* Type Offset=1022 */

	/* Return value */

/* 5858 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5860 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5862 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIERegistryOption */

/* 5864 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5866 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5870 */	NdrFcShort( 0x8a ),	/* 138 */
/* 5872 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5874 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5876 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5878 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 5880 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 5882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5884 */	NdrFcShort( 0x20 ),	/* 32 */
/* 5886 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5888 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IeRegistryOptionsFlag */

/* 5890 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5892 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5894 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter varBuffer */

/* 5896 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5898 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5900 */	NdrFcShort( 0x3fe ),	/* Type Offset=1022 */

	/* Return value */

/* 5902 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5904 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5906 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DecodeMime */

/* 5908 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5910 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5914 */	NdrFcShort( 0x8b ),	/* 139 */
/* 5916 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5918 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5920 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5922 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 5924 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 5926 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5928 */	NdrFcShort( 0x2 ),	/* 2 */
/* 5930 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5932 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter strToDecode */

/* 5934 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 5936 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5938 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter strDecoded */

/* 5940 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 5942 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5944 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 5946 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5948 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5950 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DeleteIEFiles */

/* 5952 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5954 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5958 */	NdrFcShort( 0x8c ),	/* 140 */
/* 5960 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5962 */	NdrFcShort( 0x6 ),	/* 6 */
/* 5964 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5966 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5968 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5972 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5974 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5976 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter enumWhichFiles */

/* 5978 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5980 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5982 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 5984 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5986 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5988 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/*  4 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  8 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 10 */	
			0x12, 0x0,	/* FC_UP */
/* 12 */	NdrFcShort( 0xe ),	/* Offset= 14 (26) */
/* 14 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 16 */	NdrFcShort( 0x2 ),	/* 2 */
/* 18 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 20 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 22 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 24 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 26 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 28 */	NdrFcShort( 0x8 ),	/* 8 */
/* 30 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (14) */
/* 32 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 34 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 36 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 38 */	NdrFcShort( 0x0 ),	/* 0 */
/* 40 */	NdrFcShort( 0x8 ),	/* 8 */
/* 42 */	NdrFcShort( 0x0 ),	/* 0 */
/* 44 */	NdrFcShort( 0xffde ),	/* Offset= -34 (10) */
/* 46 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 48 */	NdrFcShort( 0x2 ),	/* Offset= 2 (50) */
/* 50 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 52 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */
/* 60 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 62 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 64 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 66 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 68 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 70 */	NdrFcShort( 0x6 ),	/* Offset= 6 (76) */
/* 72 */	
			0x13, 0x0,	/* FC_OP */
/* 74 */	NdrFcShort( 0xffd0 ),	/* Offset= -48 (26) */
/* 76 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 78 */	NdrFcShort( 0x0 ),	/* 0 */
/* 80 */	NdrFcShort( 0x8 ),	/* 8 */
/* 82 */	NdrFcShort( 0x0 ),	/* 0 */
/* 84 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (72) */
/* 86 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 88 */	0xe,		/* FC_ENUM32 */
			0x5c,		/* FC_PAD */
/* 90 */	
			0x11, 0x0,	/* FC_RP */
/* 92 */	NdrFcShort( 0x3a2 ),	/* Offset= 930 (1022) */
/* 94 */	
			0x12, 0x0,	/* FC_UP */
/* 96 */	NdrFcShort( 0x38a ),	/* Offset= 906 (1002) */
/* 98 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 100 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 102 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 104 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 106 */	NdrFcShort( 0x2 ),	/* Offset= 2 (108) */
/* 108 */	NdrFcShort( 0x10 ),	/* 16 */
/* 110 */	NdrFcShort( 0x2f ),	/* 47 */
/* 112 */	NdrFcLong( 0x14 ),	/* 20 */
/* 116 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 118 */	NdrFcLong( 0x3 ),	/* 3 */
/* 122 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 124 */	NdrFcLong( 0x11 ),	/* 17 */
/* 128 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 130 */	NdrFcLong( 0x2 ),	/* 2 */
/* 134 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 136 */	NdrFcLong( 0x4 ),	/* 4 */
/* 140 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 142 */	NdrFcLong( 0x5 ),	/* 5 */
/* 146 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 148 */	NdrFcLong( 0xb ),	/* 11 */
/* 152 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 154 */	NdrFcLong( 0xa ),	/* 10 */
/* 158 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 160 */	NdrFcLong( 0x6 ),	/* 6 */
/* 164 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (396) */
/* 166 */	NdrFcLong( 0x7 ),	/* 7 */
/* 170 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 172 */	NdrFcLong( 0x8 ),	/* 8 */
/* 176 */	NdrFcShort( 0xff5a ),	/* Offset= -166 (10) */
/* 178 */	NdrFcLong( 0xd ),	/* 13 */
/* 182 */	NdrFcShort( 0xdc ),	/* Offset= 220 (402) */
/* 184 */	NdrFcLong( 0x9 ),	/* 9 */
/* 188 */	NdrFcShort( 0xff76 ),	/* Offset= -138 (50) */
/* 190 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 194 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (420) */
/* 196 */	NdrFcLong( 0x24 ),	/* 36 */
/* 200 */	NdrFcShort( 0x2d8 ),	/* Offset= 728 (928) */
/* 202 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 206 */	NdrFcShort( 0x2d2 ),	/* Offset= 722 (928) */
/* 208 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 212 */	NdrFcShort( 0x2d0 ),	/* Offset= 720 (932) */
/* 214 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 218 */	NdrFcShort( 0x2ce ),	/* Offset= 718 (936) */
/* 220 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 224 */	NdrFcShort( 0x2cc ),	/* Offset= 716 (940) */
/* 226 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 230 */	NdrFcShort( 0x2ca ),	/* Offset= 714 (944) */
/* 232 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 236 */	NdrFcShort( 0x2c8 ),	/* Offset= 712 (948) */
/* 238 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 242 */	NdrFcShort( 0x2c6 ),	/* Offset= 710 (952) */
/* 244 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 248 */	NdrFcShort( 0x2b0 ),	/* Offset= 688 (936) */
/* 250 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 254 */	NdrFcShort( 0x2ae ),	/* Offset= 686 (940) */
/* 256 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 260 */	NdrFcShort( 0x2b8 ),	/* Offset= 696 (956) */
/* 262 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 266 */	NdrFcShort( 0x2ae ),	/* Offset= 686 (952) */
/* 268 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 272 */	NdrFcShort( 0x2b0 ),	/* Offset= 688 (960) */
/* 274 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 278 */	NdrFcShort( 0x2ae ),	/* Offset= 686 (964) */
/* 280 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 284 */	NdrFcShort( 0x2ac ),	/* Offset= 684 (968) */
/* 286 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 290 */	NdrFcShort( 0x2aa ),	/* Offset= 682 (972) */
/* 292 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 296 */	NdrFcShort( 0x2a8 ),	/* Offset= 680 (976) */
/* 298 */	NdrFcLong( 0x10 ),	/* 16 */
/* 302 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 304 */	NdrFcLong( 0x12 ),	/* 18 */
/* 308 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 310 */	NdrFcLong( 0x13 ),	/* 19 */
/* 314 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 316 */	NdrFcLong( 0x15 ),	/* 21 */
/* 320 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 322 */	NdrFcLong( 0x16 ),	/* 22 */
/* 326 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 328 */	NdrFcLong( 0x17 ),	/* 23 */
/* 332 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 334 */	NdrFcLong( 0xe ),	/* 14 */
/* 338 */	NdrFcShort( 0x286 ),	/* Offset= 646 (984) */
/* 340 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 344 */	NdrFcShort( 0x28a ),	/* Offset= 650 (994) */
/* 346 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 350 */	NdrFcShort( 0x288 ),	/* Offset= 648 (998) */
/* 352 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 356 */	NdrFcShort( 0x244 ),	/* Offset= 580 (936) */
/* 358 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 362 */	NdrFcShort( 0x242 ),	/* Offset= 578 (940) */
/* 364 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 368 */	NdrFcShort( 0x240 ),	/* Offset= 576 (944) */
/* 370 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 374 */	NdrFcShort( 0x236 ),	/* Offset= 566 (940) */
/* 376 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 380 */	NdrFcShort( 0x230 ),	/* Offset= 560 (940) */
/* 382 */	NdrFcLong( 0x0 ),	/* 0 */
/* 386 */	NdrFcShort( 0x0 ),	/* Offset= 0 (386) */
/* 388 */	NdrFcLong( 0x1 ),	/* 1 */
/* 392 */	NdrFcShort( 0x0 ),	/* Offset= 0 (392) */
/* 394 */	NdrFcShort( 0xffff ),	/* Offset= -1 (393) */
/* 396 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 398 */	NdrFcShort( 0x8 ),	/* 8 */
/* 400 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 402 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 404 */	NdrFcLong( 0x0 ),	/* 0 */
/* 408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 412 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 414 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 416 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 418 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 420 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 422 */	NdrFcShort( 0x2 ),	/* Offset= 2 (424) */
/* 424 */	
			0x12, 0x0,	/* FC_UP */
/* 426 */	NdrFcShort( 0x1e4 ),	/* Offset= 484 (910) */
/* 428 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x89,		/* 137 */
/* 430 */	NdrFcShort( 0x20 ),	/* 32 */
/* 432 */	NdrFcShort( 0xa ),	/* 10 */
/* 434 */	NdrFcLong( 0x8 ),	/* 8 */
/* 438 */	NdrFcShort( 0x50 ),	/* Offset= 80 (518) */
/* 440 */	NdrFcLong( 0xd ),	/* 13 */
/* 444 */	NdrFcShort( 0x70 ),	/* Offset= 112 (556) */
/* 446 */	NdrFcLong( 0x9 ),	/* 9 */
/* 450 */	NdrFcShort( 0x90 ),	/* Offset= 144 (594) */
/* 452 */	NdrFcLong( 0xc ),	/* 12 */
/* 456 */	NdrFcShort( 0xb0 ),	/* Offset= 176 (632) */
/* 458 */	NdrFcLong( 0x24 ),	/* 36 */
/* 462 */	NdrFcShort( 0x102 ),	/* Offset= 258 (720) */
/* 464 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 468 */	NdrFcShort( 0x11e ),	/* Offset= 286 (754) */
/* 470 */	NdrFcLong( 0x10 ),	/* 16 */
/* 474 */	NdrFcShort( 0x138 ),	/* Offset= 312 (786) */
/* 476 */	NdrFcLong( 0x2 ),	/* 2 */
/* 480 */	NdrFcShort( 0x14e ),	/* Offset= 334 (814) */
/* 482 */	NdrFcLong( 0x3 ),	/* 3 */
/* 486 */	NdrFcShort( 0x164 ),	/* Offset= 356 (842) */
/* 488 */	NdrFcLong( 0x14 ),	/* 20 */
/* 492 */	NdrFcShort( 0x17a ),	/* Offset= 378 (870) */
/* 494 */	NdrFcShort( 0xffff ),	/* Offset= -1 (493) */
/* 496 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 500 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 504 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 506 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 510 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 512 */	
			0x12, 0x0,	/* FC_UP */
/* 514 */	NdrFcShort( 0xfe18 ),	/* Offset= -488 (26) */
/* 516 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 518 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 520 */	NdrFcShort( 0x10 ),	/* 16 */
/* 522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 524 */	NdrFcShort( 0x6 ),	/* Offset= 6 (530) */
/* 526 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 528 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 530 */	
			0x11, 0x0,	/* FC_RP */
/* 532 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (496) */
/* 534 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 538 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 542 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 544 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 548 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 550 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 552 */	NdrFcShort( 0xff6a ),	/* Offset= -150 (402) */
/* 554 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 556 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 558 */	NdrFcShort( 0x10 ),	/* 16 */
/* 560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 562 */	NdrFcShort( 0x6 ),	/* Offset= 6 (568) */
/* 564 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 566 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 568 */	
			0x11, 0x0,	/* FC_RP */
/* 570 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (534) */
/* 572 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 576 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 580 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 582 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 586 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 588 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 590 */	NdrFcShort( 0xfde4 ),	/* Offset= -540 (50) */
/* 592 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 594 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 596 */	NdrFcShort( 0x10 ),	/* 16 */
/* 598 */	NdrFcShort( 0x0 ),	/* 0 */
/* 600 */	NdrFcShort( 0x6 ),	/* Offset= 6 (606) */
/* 602 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 604 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 606 */	
			0x11, 0x0,	/* FC_RP */
/* 608 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (572) */
/* 610 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 612 */	NdrFcShort( 0x0 ),	/* 0 */
/* 614 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 618 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 620 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 624 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 626 */	
			0x12, 0x0,	/* FC_UP */
/* 628 */	NdrFcShort( 0x176 ),	/* Offset= 374 (1002) */
/* 630 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 632 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 634 */	NdrFcShort( 0x10 ),	/* 16 */
/* 636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 638 */	NdrFcShort( 0x6 ),	/* Offset= 6 (644) */
/* 640 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 642 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 644 */	
			0x11, 0x0,	/* FC_RP */
/* 646 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (610) */
/* 648 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 650 */	NdrFcLong( 0x2f ),	/* 47 */
/* 654 */	NdrFcShort( 0x0 ),	/* 0 */
/* 656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 658 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 660 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 662 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 664 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 666 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 668 */	NdrFcShort( 0x1 ),	/* 1 */
/* 670 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 672 */	NdrFcShort( 0x4 ),	/* 4 */
/* 674 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 676 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 678 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 680 */	NdrFcShort( 0x18 ),	/* 24 */
/* 682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 684 */	NdrFcShort( 0xa ),	/* Offset= 10 (694) */
/* 686 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 688 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 690 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (648) */
/* 692 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 694 */	
			0x12, 0x0,	/* FC_UP */
/* 696 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (666) */
/* 698 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 702 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 706 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 708 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 712 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 714 */	
			0x12, 0x0,	/* FC_UP */
/* 716 */	NdrFcShort( 0xffda ),	/* Offset= -38 (678) */
/* 718 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 720 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 722 */	NdrFcShort( 0x10 ),	/* 16 */
/* 724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 726 */	NdrFcShort( 0x6 ),	/* Offset= 6 (732) */
/* 728 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 730 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 732 */	
			0x11, 0x0,	/* FC_RP */
/* 734 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (698) */
/* 736 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 738 */	NdrFcShort( 0x8 ),	/* 8 */
/* 740 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 742 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 744 */	NdrFcShort( 0x10 ),	/* 16 */
/* 746 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 748 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 750 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (736) */
			0x5b,		/* FC_END */
/* 754 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 756 */	NdrFcShort( 0x20 ),	/* 32 */
/* 758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 760 */	NdrFcShort( 0xa ),	/* Offset= 10 (770) */
/* 762 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 764 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 766 */	0x0,		/* 0 */
			NdrFcShort( 0xffe7 ),	/* Offset= -25 (742) */
			0x5b,		/* FC_END */
/* 770 */	
			0x11, 0x0,	/* FC_RP */
/* 772 */	NdrFcShort( 0xff12 ),	/* Offset= -238 (534) */
/* 774 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 776 */	NdrFcShort( 0x1 ),	/* 1 */
/* 778 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 782 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 784 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 786 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 788 */	NdrFcShort( 0x10 ),	/* 16 */
/* 790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 792 */	NdrFcShort( 0x6 ),	/* Offset= 6 (798) */
/* 794 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 796 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 798 */	
			0x12, 0x0,	/* FC_UP */
/* 800 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (774) */
/* 802 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 804 */	NdrFcShort( 0x2 ),	/* 2 */
/* 806 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 808 */	NdrFcShort( 0x0 ),	/* 0 */
/* 810 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 812 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 814 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 816 */	NdrFcShort( 0x10 ),	/* 16 */
/* 818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 820 */	NdrFcShort( 0x6 ),	/* Offset= 6 (826) */
/* 822 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 824 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 826 */	
			0x12, 0x0,	/* FC_UP */
/* 828 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (802) */
/* 830 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 832 */	NdrFcShort( 0x4 ),	/* 4 */
/* 834 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 838 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 840 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 842 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 844 */	NdrFcShort( 0x10 ),	/* 16 */
/* 846 */	NdrFcShort( 0x0 ),	/* 0 */
/* 848 */	NdrFcShort( 0x6 ),	/* Offset= 6 (854) */
/* 850 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 852 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 854 */	
			0x12, 0x0,	/* FC_UP */
/* 856 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (830) */
/* 858 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 860 */	NdrFcShort( 0x8 ),	/* 8 */
/* 862 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 864 */	NdrFcShort( 0x0 ),	/* 0 */
/* 866 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 868 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 870 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 872 */	NdrFcShort( 0x10 ),	/* 16 */
/* 874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 876 */	NdrFcShort( 0x6 ),	/* Offset= 6 (882) */
/* 878 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 880 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 882 */	
			0x12, 0x0,	/* FC_UP */
/* 884 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (858) */
/* 886 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 888 */	NdrFcShort( 0x8 ),	/* 8 */
/* 890 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 892 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 894 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 896 */	NdrFcShort( 0x8 ),	/* 8 */
/* 898 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 900 */	NdrFcShort( 0xffc8 ),	/* -56 */
/* 902 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 904 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 906 */	NdrFcShort( 0xffec ),	/* Offset= -20 (886) */
/* 908 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 910 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 912 */	NdrFcShort( 0x38 ),	/* 56 */
/* 914 */	NdrFcShort( 0xffec ),	/* Offset= -20 (894) */
/* 916 */	NdrFcShort( 0x0 ),	/* Offset= 0 (916) */
/* 918 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 920 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 922 */	0x40,		/* FC_STRUCTPAD4 */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 924 */	0x0,		/* 0 */
			NdrFcShort( 0xfe0f ),	/* Offset= -497 (428) */
			0x5b,		/* FC_END */
/* 928 */	
			0x12, 0x0,	/* FC_UP */
/* 930 */	NdrFcShort( 0xff04 ),	/* Offset= -252 (678) */
/* 932 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 934 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 936 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 938 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 940 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 942 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 944 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 946 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 948 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 950 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 952 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 954 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 956 */	
			0x12, 0x0,	/* FC_UP */
/* 958 */	NdrFcShort( 0xfdce ),	/* Offset= -562 (396) */
/* 960 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 962 */	NdrFcShort( 0xfc48 ),	/* Offset= -952 (10) */
/* 964 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 966 */	NdrFcShort( 0xfdcc ),	/* Offset= -564 (402) */
/* 968 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 970 */	NdrFcShort( 0xfc68 ),	/* Offset= -920 (50) */
/* 972 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 974 */	NdrFcShort( 0xfdd6 ),	/* Offset= -554 (420) */
/* 976 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 978 */	NdrFcShort( 0x2 ),	/* Offset= 2 (980) */
/* 980 */	
			0x12, 0x0,	/* FC_UP */
/* 982 */	NdrFcShort( 0x14 ),	/* Offset= 20 (1002) */
/* 984 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 986 */	NdrFcShort( 0x10 ),	/* 16 */
/* 988 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 990 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 992 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 994 */	
			0x12, 0x0,	/* FC_UP */
/* 996 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (984) */
/* 998 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1000 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 1002 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1004 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1008 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1008) */
/* 1010 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1012 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1014 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1016 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1018 */	NdrFcShort( 0xfc68 ),	/* Offset= -920 (98) */
/* 1020 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1022 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1024 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1026 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1028 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1030 */	NdrFcShort( 0xfc58 ),	/* Offset= -936 (94) */
/* 1032 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1034 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1036 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 1038 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 1040 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 1042 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1044 */	
			0x11, 0x0,	/* FC_RP */
/* 1046 */	NdrFcShort( 0xfc36 ),	/* Offset= -970 (76) */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            },
            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            }

        };



/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: INewWindowManager, ver. 0.0,
   GUID={0xD2BC4C84,0x3F72,0x4a52,{0xA6,0x04,0x7B,0xCB,0xF3,0x98,0x2C,0xBB}} */

#pragma code_seg(".orpc")
static const unsigned short INewWindowManager_FormatStringOffsetTable[] =
    {
    0
    };

static const MIDL_STUBLESS_PROXY_INFO INewWindowManager_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &INewWindowManager_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO INewWindowManager_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &INewWindowManager_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _INewWindowManagerProxyVtbl = 
{
    &INewWindowManager_ProxyInfo,
    &IID_INewWindowManager,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* INewWindowManager::EvaluateNewWindow */
};

const CInterfaceStubVtbl _INewWindowManagerStubVtbl =
{
    &IID_INewWindowManager,
    &INewWindowManager_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHTMLOMWindowServices, ver. 0.0,
   GUID={0x3050f5fc,0x98b5,0x11cf,{0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b}} */

#pragma code_seg(".orpc")
static const unsigned short IHTMLOMWindowServices_FormatStringOffsetTable[] =
    {
    74,
    118,
    162,
    206
    };

static const MIDL_STUBLESS_PROXY_INFO IHTMLOMWindowServices_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHTMLOMWindowServices_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHTMLOMWindowServices_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHTMLOMWindowServices_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IHTMLOMWindowServicesProxyVtbl = 
{
    &IHTMLOMWindowServices_ProxyInfo,
    &IID_IHTMLOMWindowServices,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHTMLOMWindowServices::moveTo */ ,
    (void *) (INT_PTR) -1 /* IHTMLOMWindowServices::moveBy */ ,
    (void *) (INT_PTR) -1 /* IHTMLOMWindowServices::resizeTo */ ,
    (void *) (INT_PTR) -1 /* IHTMLOMWindowServices::resizeBy */
};

const CInterfaceStubVtbl _IHTMLOMWindowServicesStubVtbl =
{
    &IID_IHTMLOMWindowServices,
    &IHTMLOMWindowServices_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Standard interface: __MIDL_itf_vbMHWB_0259, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IDownloadManager, ver. 0.0,
   GUID={0x988934A4,0x064B,0x11D3,{0xBB,0x80,0x00,0x10,0x4B,0x35,0xE7,0xF9}} */


/* Standard interface: __MIDL_itf_vbMHWB_0260, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IvbWB, ver. 0.0,
   GUID={0x6E73D516,0x7CDC,0x435E,{0x8A,0x8D,0x86,0xE0,0xAE,0x4D,0x5E,0x08}} */

#pragma code_seg(".orpc")
static const unsigned short IvbWB_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    250,
    288,
    326,
    364,
    402,
    440,
    478,
    516,
    560,
    604,
    648,
    692,
    736,
    780,
    818,
    862,
    906,
    950,
    994,
    1044,
    1094,
    1138,
    1182,
    1226,
    1264,
    1302,
    1340,
    1378,
    1416,
    1454,
    1492,
    1530,
    1568,
    1606,
    1644,
    1682,
    1720,
    1758,
    1796,
    1834,
    1872,
    1910,
    1948,
    1986,
    2024,
    2068,
    2112,
    2150,
    2188,
    2226,
    2264,
    2302,
    2340,
    2402,
    2452,
    2490,
    2528,
    2572,
    2616,
    2660,
    2704,
    2748,
    2792,
    2836,
    2880,
    2924,
    2968,
    3036,
    3104,
    3148,
    3192,
    3236,
    3280,
    3324,
    3368,
    3412,
    3456,
    3500,
    3544,
    3618,
    3686,
    3748,
    3792,
    3830,
    3868,
    3906,
    3944,
    3982,
    4020,
    4058,
    4096,
    4134,
    4172,
    4210,
    4248,
    4286,
    4324,
    4362,
    4400,
    4438,
    4476,
    4520,
    4558,
    4596,
    4634,
    4672,
    4722,
    4760,
    4798,
    4836,
    4886,
    4954,
    4998,
    5042,
    5074,
    5112,
    5150,
    5194,
    5244,
    5288,
    5338,
    5382,
    5426,
    5458,
    5496,
    5564,
    5620,
    5664,
    5720,
    5770,
    5820,
    5864,
    5908,
    5952
    };

static const MIDL_STUBLESS_PROXY_INFO IvbWB_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IvbWB_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IvbWB_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IvbWB_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(141) _IvbWBProxyVtbl = 
{
    &IvbWB_ProxyInfo,
    &IID_IvbWB,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_Count */ ,
    (void *) (INT_PTR) -1 /* IvbWB::RemoveBrowser */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Refresh */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Stop */ ,
    (void *) (INT_PTR) -1 /* IvbWB::GoBack */ ,
    (void *) (INT_PTR) -1 /* IvbWB::GoForward */ ,
    (void *) (INT_PTR) -1 /* IvbWB::GoHome */ ,
    (void *) (INT_PTR) -1 /* IvbWB::NavigateSimple */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_WebBrowser */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_LocationURL */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_Offline */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_Offline */ ,
    (void *) (INT_PTR) -1 /* IvbWB::ReadyState */ ,
    (void *) (INT_PTR) -1 /* IvbWB::GoSearch */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Refresh2 */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_Busy */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_RegisterAsBrowser */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_RegisterAsBrowser */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_RegisterAsDropTarget */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_RegisterAsDropTarget */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_Silent */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_Silent */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_LocationName */ ,
    (void *) (INT_PTR) -1 /* IvbWB::SelectAll */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Paste */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Copy */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Cut */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Undo */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Redo */ ,
    (void *) (INT_PTR) -1 /* IvbWB::ClearSelection */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Delete */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Find */ ,
    (void *) (INT_PTR) -1 /* IvbWB::PasteSpecial */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Spell */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Properties */ ,
    (void *) (INT_PTR) -1 /* IvbWB::NewWindow */ ,
    (void *) (INT_PTR) -1 /* IvbWB::FileOpen */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Save */ ,
    (void *) (INT_PTR) -1 /* IvbWB::SaveAs */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Print */ ,
    (void *) (INT_PTR) -1 /* IvbWB::PrintPreview */ ,
    (void *) (INT_PTR) -1 /* IvbWB::PageSetup */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Print2 */ ,
    (void *) (INT_PTR) -1 /* IvbWB::PrintPreview2 */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_HWNDShellDocObjectView */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_HWNDInternetExplorerServer */ ,
    (void *) (INT_PTR) -1 /* IvbWB::ViewSource */ ,
    (void *) (INT_PTR) -1 /* IvbWB::AddToFavorites */ ,
    (void *) (INT_PTR) -1 /* IvbWB::SetFocusW */ ,
    (void *) (INT_PTR) -1 /* IvbWB::PlaceWBOnTop */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_HWNDMainWnd */ ,
    (void *) (INT_PTR) -1 /* IvbWB::AnyDocHasFocus */ ,
    (void *) (INT_PTR) -1 /* IvbWB::ExecWB */ ,
    (void *) (INT_PTR) -1 /* IvbWB::QueryStatusWB */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_StartupURL */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_StartupURL */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_UseIEDefaultFileDownload */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_UseIEDefaultFileDownload */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_HWNDShellEmbedding */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_FramesCount */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_WBVisible */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_WBVisible */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_Application */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_Document */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ActiveElementObj */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ActiveDocumentObj */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Navigate2 */ ,
    (void *) (INT_PTR) -1 /* IvbWB::Navigate */ ,
    (void *) (INT_PTR) -1 /* IvbWB::AddBrowser */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ObjectWB */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ContextMenuAction */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_ContextMenuAction */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_DocumentDownloadControlFlags */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_DocumentDownloadControlFlags */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_DocumentHostUiFlags */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_DocumentHostUiFlags */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_DocumentHostUiDoubleClickAction */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_DocumentHostUiDoubleClickAction */ ,
    (void *) (INT_PTR) -1 /* IvbWB::FindTextSimple */ ,
    (void *) (INT_PTR) -1 /* IvbWB::FindAndHighlightAllText */ ,
    (void *) (INT_PTR) -1 /* IvbWB::FindAnyTextMatch */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_IsDocFrameset */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ucScheme */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_ucScheme */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ucHostName */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_ucHostName */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ucPort */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_ucPort */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ucUserName */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_ucUserName */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ucPassword */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_ucPassword */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ucUrlPath */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_ucUrlPath */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ucExtraInfo */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_ucExtraInfo */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ucFullURL */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_ucFullURL */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ucFileName */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ucFileExtension */ ,
    (void *) (INT_PTR) -1 /* IvbWB::ucInternetCrackUrl */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_ucInternetScheme */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_ucInternetScheme */ ,
    (void *) (INT_PTR) -1 /* IvbWB::ucInternetCreateUrl */ ,
    (void *) (INT_PTR) -1 /* IvbWB::CancelFileDl */ ,
    (void *) (INT_PTR) -1 /* IvbWB::DownloadUrlAsync */ ,
    (void *) (INT_PTR) -1 /* IvbWB::RegisterHTTPprotocol */ ,
    (void *) (INT_PTR) -1 /* IvbWB::RegisterHTTPSprotocol */ ,
    (void *) (INT_PTR) -1 /* IvbWB::DisplayCertificateDialog */ ,
    (void *) (INT_PTR) -1 /* IvbWB::LoadHTMLFromString */ ,
    (void *) (INT_PTR) -1 /* IvbWB::DrawWBThumbnailOnWnd */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_WBPageTextSize */ ,
    (void *) (INT_PTR) -1 /* IvbWB::put_WBPageTextSize */ ,
    (void *) (INT_PTR) -1 /* IvbWB::ucResetFieldsToDefault */ ,
    (void *) (INT_PTR) -1 /* IvbWB::SubclassWnd */ ,
    (void *) (INT_PTR) -1 /* IvbWB::UnSubclassWnd */ ,
    (void *) (INT_PTR) -1 /* IvbWB::AddMessage */ ,
    (void *) (INT_PTR) -1 /* IvbWB::SetupShellAutoComplete */ ,
    (void *) (INT_PTR) -1 /* IvbWB::SaveAsBitmap */ ,
    (void *) (INT_PTR) -1 /* IvbWB::WBPostData */ ,
    (void *) (INT_PTR) -1 /* IvbWB::get_SourceOnDocComplete */ ,
    IvbWB_put_SourceOnDocComplete_Proxy ,
    IvbWB_OrganizeFavorites_Proxy ,
    IvbWB_ViewIEOptions_Proxy ,
    IvbWB_FindAndHighlightAllTextFrames_Proxy ,
    IvbWB_SetupWindowsHook_Proxy ,
    IvbWB_HookProcNCode_Proxy ,
    IvbWB_SetupCustomAutoComplete_Proxy ,
    IvbWB_CustomAutoCompleteAddString_Proxy ,
    IvbWB_CustomAutoCompleteEnable_Proxy ,
    IvbWB_QueryIERegistryOption_Proxy ,
    IvbWB_SetIERegistryOption_Proxy ,
    IvbWB_DecodeMime_Proxy ,
    IvbWB_DeleteIEFiles_Proxy
};


static const PRPC_STUB_FUNCTION IvbWB_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IvbWBStubVtbl =
{
    &IID_IvbWB,
    &IvbWB_ServerInfo,
    141,
    &IvbWB_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x6000169, /* MIDL Version 6.0.361 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0   /* Reserved5 */
    };

const CInterfaceProxyVtbl * _vbMHWB_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IvbWBProxyVtbl,
    ( CInterfaceProxyVtbl *) &_INewWindowManagerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHTMLOMWindowServicesProxyVtbl,
    0
};

const CInterfaceStubVtbl * _vbMHWB_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IvbWBStubVtbl,
    ( CInterfaceStubVtbl *) &_INewWindowManagerStubVtbl,
    ( CInterfaceStubVtbl *) &_IHTMLOMWindowServicesStubVtbl,
    0
};

PCInterfaceName const _vbMHWB_InterfaceNamesList[] = 
{
    "IvbWB",
    "INewWindowManager",
    "IHTMLOMWindowServices",
    0
};

const IID *  _vbMHWB_BaseIIDList[] = 
{
    &IID_IDispatch,
    0,
    0,
    0
};


#define _vbMHWB_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _vbMHWB, pIID, n)

int __stdcall _vbMHWB_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _vbMHWB, 3, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _vbMHWB, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _vbMHWB, 3, *pIndex )
    
}

const ExtendedProxyFileInfo vbMHWB_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _vbMHWB_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _vbMHWB_StubVtblList,
    (const PCInterfaceName * ) & _vbMHWB_InterfaceNamesList,
    (const IID ** ) & _vbMHWB_BaseIIDList,
    & _vbMHWB_IID_Lookup, 
    3,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_IA64) || defined(_M_AMD64)*/


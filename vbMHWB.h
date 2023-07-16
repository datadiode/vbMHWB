

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __vbMHWB_h__
#define __vbMHWB_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __INewWindowManager_FWD_DEFINED__
#define __INewWindowManager_FWD_DEFINED__
typedef interface INewWindowManager INewWindowManager;
#endif 	/* __INewWindowManager_FWD_DEFINED__ */


#ifndef __IHTMLOMWindowServices_FWD_DEFINED__
#define __IHTMLOMWindowServices_FWD_DEFINED__
typedef interface IHTMLOMWindowServices IHTMLOMWindowServices;
#endif 	/* __IHTMLOMWindowServices_FWD_DEFINED__ */


#ifndef __IDownloadManager_FWD_DEFINED__
#define __IDownloadManager_FWD_DEFINED__
typedef interface IDownloadManager IDownloadManager;
#endif 	/* __IDownloadManager_FWD_DEFINED__ */


#ifndef __IvbWB_FWD_DEFINED__
#define __IvbWB_FWD_DEFINED__
typedef interface IvbWB IvbWB;
#endif 	/* __IvbWB_FWD_DEFINED__ */


#ifndef ___IvbWBEvents_FWD_DEFINED__
#define ___IvbWBEvents_FWD_DEFINED__
typedef interface _IvbWBEvents _IvbWBEvents;
#endif 	/* ___IvbWBEvents_FWD_DEFINED__ */


#ifndef __vbWB_FWD_DEFINED__
#define __vbWB_FWD_DEFINED__

#ifdef __cplusplus
typedef class vbWB vbWB;
#else
typedef struct vbWB vbWB;
#endif /* __cplusplus */

#endif 	/* __vbWB_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __INewWindowManager_INTERFACE_DEFINED__
#define __INewWindowManager_INTERFACE_DEFINED__

/* interface INewWindowManager */
/* [unique][object][uuid] */ 


EXTERN_C const IID IID_INewWindowManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D2BC4C84-3F72-4a52-A604-7BCBF3982CBB")
    INewWindowManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EvaluateNewWindow( 
            /* [in] */ LPCWSTR pszUrl,
            /* [in] */ LPCWSTR pszName,
            /* [in] */ LPCWSTR pszUrlContext,
            /* [in] */ LPCWSTR pszFeatures,
            /* [in] */ BOOL fReplace,
            /* [in] */ DWORD dwFlags,
            /* [in] */ DWORD dwUserActionTime) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INewWindowManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INewWindowManager * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INewWindowManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INewWindowManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *EvaluateNewWindow )( 
            INewWindowManager * This,
            /* [in] */ LPCWSTR pszUrl,
            /* [in] */ LPCWSTR pszName,
            /* [in] */ LPCWSTR pszUrlContext,
            /* [in] */ LPCWSTR pszFeatures,
            /* [in] */ BOOL fReplace,
            /* [in] */ DWORD dwFlags,
            /* [in] */ DWORD dwUserActionTime);
        
        END_INTERFACE
    } INewWindowManagerVtbl;

    interface INewWindowManager
    {
        CONST_VTBL struct INewWindowManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INewWindowManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INewWindowManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INewWindowManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INewWindowManager_EvaluateNewWindow(This,pszUrl,pszName,pszUrlContext,pszFeatures,fReplace,dwFlags,dwUserActionTime)	\
    (This)->lpVtbl -> EvaluateNewWindow(This,pszUrl,pszName,pszUrlContext,pszFeatures,fReplace,dwFlags,dwUserActionTime)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE INewWindowManager_EvaluateNewWindow_Proxy( 
    INewWindowManager * This,
    /* [in] */ LPCWSTR pszUrl,
    /* [in] */ LPCWSTR pszName,
    /* [in] */ LPCWSTR pszUrlContext,
    /* [in] */ LPCWSTR pszFeatures,
    /* [in] */ BOOL fReplace,
    /* [in] */ DWORD dwFlags,
    /* [in] */ DWORD dwUserActionTime);


void __RPC_STUB INewWindowManager_EvaluateNewWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INewWindowManager_INTERFACE_DEFINED__ */


#ifndef __IHTMLOMWindowServices_INTERFACE_DEFINED__
#define __IHTMLOMWindowServices_INTERFACE_DEFINED__

/* interface IHTMLOMWindowServices */
/* [uuid][unique][object] */ 


EXTERN_C const IID IID_IHTMLOMWindowServices;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3050f5fc-98b5-11cf-bb82-00aa00bdce0b")
    IHTMLOMWindowServices : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE moveTo( 
            /* [in] */ LONG x,
            /* [in] */ LONG y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE moveBy( 
            /* [in] */ LONG x,
            /* [in] */ LONG y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE resizeTo( 
            /* [in] */ LONG x,
            /* [in] */ LONG y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE resizeBy( 
            /* [in] */ LONG x,
            /* [in] */ LONG y) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHTMLOMWindowServicesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHTMLOMWindowServices * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHTMLOMWindowServices * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHTMLOMWindowServices * This);
        
        HRESULT ( STDMETHODCALLTYPE *moveTo )( 
            IHTMLOMWindowServices * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y);
        
        HRESULT ( STDMETHODCALLTYPE *moveBy )( 
            IHTMLOMWindowServices * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y);
        
        HRESULT ( STDMETHODCALLTYPE *resizeTo )( 
            IHTMLOMWindowServices * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y);
        
        HRESULT ( STDMETHODCALLTYPE *resizeBy )( 
            IHTMLOMWindowServices * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y);
        
        END_INTERFACE
    } IHTMLOMWindowServicesVtbl;

    interface IHTMLOMWindowServices
    {
        CONST_VTBL struct IHTMLOMWindowServicesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHTMLOMWindowServices_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHTMLOMWindowServices_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHTMLOMWindowServices_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHTMLOMWindowServices_moveTo(This,x,y)	\
    (This)->lpVtbl -> moveTo(This,x,y)

#define IHTMLOMWindowServices_moveBy(This,x,y)	\
    (This)->lpVtbl -> moveBy(This,x,y)

#define IHTMLOMWindowServices_resizeTo(This,x,y)	\
    (This)->lpVtbl -> resizeTo(This,x,y)

#define IHTMLOMWindowServices_resizeBy(This,x,y)	\
    (This)->lpVtbl -> resizeBy(This,x,y)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHTMLOMWindowServices_moveTo_Proxy( 
    IHTMLOMWindowServices * This,
    /* [in] */ LONG x,
    /* [in] */ LONG y);


void __RPC_STUB IHTMLOMWindowServices_moveTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHTMLOMWindowServices_moveBy_Proxy( 
    IHTMLOMWindowServices * This,
    /* [in] */ LONG x,
    /* [in] */ LONG y);


void __RPC_STUB IHTMLOMWindowServices_moveBy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHTMLOMWindowServices_resizeTo_Proxy( 
    IHTMLOMWindowServices * This,
    /* [in] */ LONG x,
    /* [in] */ LONG y);


void __RPC_STUB IHTMLOMWindowServices_resizeTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHTMLOMWindowServices_resizeBy_Proxy( 
    IHTMLOMWindowServices * This,
    /* [in] */ LONG x,
    /* [in] */ LONG y);


void __RPC_STUB IHTMLOMWindowServices_resizeBy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHTMLOMWindowServices_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vbMHWB_0259 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_vbMHWB_0259_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vbMHWB_0259_v0_0_s_ifspec;

#ifndef __IDownloadManager_INTERFACE_DEFINED__
#define __IDownloadManager_INTERFACE_DEFINED__

/* interface IDownloadManager */
/* [local][unique][uuid][object][helpstring] */ 


EXTERN_C const IID IID_IDownloadManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("988934A4-064B-11D3-BB80-00104B35E7F9")
    IDownloadManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Download( 
            /* [in] */ IMoniker *pmk,
            /* [in] */ IBindCtx *pbc,
            /* [in] */ DWORD dwBindVerb,
            /* [in] */ LONG grfBINDF,
            /* [in] */ BINDINFO *pBindInfo,
            /* [in] */ LPCOLESTR pszHeaders,
            /* [in] */ LPCOLESTR pszRedir,
            /* [in] */ UINT uiCP) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDownloadManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDownloadManager * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDownloadManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDownloadManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *Download )( 
            IDownloadManager * This,
            /* [in] */ IMoniker *pmk,
            /* [in] */ IBindCtx *pbc,
            /* [in] */ DWORD dwBindVerb,
            /* [in] */ LONG grfBINDF,
            /* [in] */ BINDINFO *pBindInfo,
            /* [in] */ LPCOLESTR pszHeaders,
            /* [in] */ LPCOLESTR pszRedir,
            /* [in] */ UINT uiCP);
        
        END_INTERFACE
    } IDownloadManagerVtbl;

    interface IDownloadManager
    {
        CONST_VTBL struct IDownloadManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDownloadManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDownloadManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDownloadManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDownloadManager_Download(This,pmk,pbc,dwBindVerb,grfBINDF,pBindInfo,pszHeaders,pszRedir,uiCP)	\
    (This)->lpVtbl -> Download(This,pmk,pbc,dwBindVerb,grfBINDF,pBindInfo,pszHeaders,pszRedir,uiCP)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IDownloadManager_Download_Proxy( 
    IDownloadManager * This,
    /* [in] */ IMoniker *pmk,
    /* [in] */ IBindCtx *pbc,
    /* [in] */ DWORD dwBindVerb,
    /* [in] */ LONG grfBINDF,
    /* [in] */ BINDINFO *pBindInfo,
    /* [in] */ LPCOLESTR pszHeaders,
    /* [in] */ LPCOLESTR pszRedir,
    /* [in] */ UINT uiCP);


void __RPC_STUB IDownloadManager_Download_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDownloadManager_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vbMHWB_0260 */
/* [local] */ 

typedef 
enum WINDOWSHOOK_TYPES
    {	WHT_CALLWNDPROC	= 0,
	WHT_CBT	= 1,
	WHT_GETMESSAGE	= 2,
	WHT_KEYBOARD	= 3,
	WHT_MOUSE	= 4,
	WHT_MSGFILTER	= 5,
	WHT_KEYBOARD_LL	= 6,
	WHT_MOUSE_LL	= 7,
	WHT_FOREGROUNDIDLE	= 8,
	WHT_CALLWNDPROCRET	= 9,
	WHT_SYSMSGFILTER	= 10
    } 	WINDOWSHOOK_TYPES;

typedef 
enum DELETE_IE_FILES_FLAGS
    {	DELETE_IE_CACHE	= 0,
	DELETE_IE_COOKIES	= 1,
	DELETE_IE_HISTORY	= 2
    } 	DELETE_IE_FILES_FLAGS;



extern RPC_IF_HANDLE __MIDL_itf_vbMHWB_0260_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vbMHWB_0260_v0_0_s_ifspec;

#ifndef __IvbWB_INTERFACE_DEFINED__
#define __IvbWB_INTERFACE_DEFINED__

/* interface IvbWB */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IvbWB;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E73D516-7CDC-435E-8A8D-86E0AE4D5E08")
    IvbWB : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ short *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveBrowser( 
            /* [in] */ short wbUIDToRemove) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( 
            short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Stop( 
            short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GoBack( 
            short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GoForward( 
            short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GoHome( 
            short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NavigateSimple( 
            /* [in] */ short wbUID,
            /* [in] */ BSTR URL) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WebBrowser( 
            /* [in] */ short wbUID,
            /* [retval][out] */ LPDISPATCH *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LocationURL( 
            /* [in] */ short wbUID,
            /* [retval][out] */ BSTR *pURL) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Offline( 
            /* [defaultvalue][in] */ short wbUID,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Offline( 
            /* [defaultvalue][in] */ short wbUID,
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadyState( 
            /* [in] */ short wbUID,
            /* [retval][out] */ READYSTATE *plReadyState) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GoSearch( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh2( 
            /* [in] */ short wbUID,
            /* [in] */ VARIANT *level) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Busy( 
            /* [in] */ short wbUID,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RegisterAsBrowser( 
            /* [defaultvalue][in] */ short wbUID,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RegisterAsBrowser( 
            /* [defaultvalue][in] */ short wbUID,
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RegisterAsDropTarget( 
            /* [defaultvalue][in] */ short wbUID,
            /* [defaultvalue][in] */ VARIANT_BOOL bUseIEDefault,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RegisterAsDropTarget( 
            /* [defaultvalue][in] */ short wbUID,
            /* [defaultvalue][in] */ VARIANT_BOOL bUseIEDefault,
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Silent( 
            /* [defaultvalue][in] */ short wbUID,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Silent( 
            /* [defaultvalue][in] */ short wbUID = 0,
            /* [defaultvalue][in] */ VARIANT_BOOL newVal = ( VARIANT_BOOL  )0) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LocationName( 
            /* [in] */ short wbUID,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectAll( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Paste( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Copy( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Cut( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Undo( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Redo( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearSelection( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Find( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PasteSpecial( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Spell( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Properties( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NewWindow( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FileOpen( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveAs( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Print( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PrintPreview( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PageSetup( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Print2( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PrintPreview2( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HWNDShellDocObjectView( 
            /* [in] */ short wbUID,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HWNDInternetExplorerServer( 
            /* [in] */ short wbUID,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ViewSource( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddToFavorites( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetFocusW( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PlaceWBOnTop( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HWNDMainWnd( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AnyDocHasFocus( 
            /* [retval][out] */ short *wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExecWB( 
            /* [in] */ short wbUID,
            /* [in] */ long cmdID,
            /* [in] */ long cmdExecOpt,
            /* [defaultvalue][in] */ VARIANT *pvaIn = 0,
            /* [defaultvalue][in] */ VARIANT *pvaOut = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE QueryStatusWB( 
            /* [in] */ short wbUID,
            /* [in] */ long cmdID,
            /* [retval][out] */ long *pcmdf) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StartupURL( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_StartupURL( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UseIEDefaultFileDownload( 
            /* [defaultvalue][in] */ short wbUID,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseIEDefaultFileDownload( 
            /* [defaultvalue][in] */ short wbUID,
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HWNDShellEmbedding( 
            /* [in] */ short wbUID,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FramesCount( 
            /* [in] */ short wbUID,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WBVisible( 
            /* [in] */ short wbUID,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_WBVisible( 
            /* [in] */ short wbUID,
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [in] */ short wbUID,
            /* [retval][out] */ LPDISPATCH *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Document( 
            /* [in] */ short wbUID,
            /* [retval][out] */ LPDISPATCH *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActiveElementObj( 
            /* [in] */ short wbUID,
            /* [retval][out] */ LPDISPATCH *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActiveDocumentObj( 
            /* [in] */ short wbUID,
            /* [retval][out] */ LPDISPATCH *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Navigate2( 
            /* [in] */ short wbUID,
            /* [in] */ VARIANT *URL,
            /* [defaultvalue][in] */ VARIANT *Flags = 0,
            /* [defaultvalue][in] */ VARIANT *TargetFrameName = 0,
            /* [defaultvalue][in] */ VARIANT *PostData = 0,
            /* [defaultvalue][in] */ VARIANT *Headers = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Navigate( 
            /* [in] */ short wbUID,
            /* [in] */ BSTR URL,
            /* [defaultvalue][in] */ VARIANT *Flags = 0,
            /* [defaultvalue][in] */ VARIANT *TargetFrameName = 0,
            /* [defaultvalue][in] */ VARIANT *PostData = 0,
            /* [defaultvalue][in] */ VARIANT *Headers = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddBrowser( 
            /* [out][in] */ short *wbUID,
            /* [defaultvalue][in] */ VARIANT_BOOL bBringToFront = 0) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ObjectWB( 
            /* [in] */ short wbUID,
            /* [retval][out] */ LPDISPATCH *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ContextMenuAction( 
            /* [defaultvalue][in] */ short wbUID,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ContextMenuAction( 
            /* [defaultvalue][in] */ short wbUID,
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DocumentDownloadControlFlags( 
            /* [defaultvalue][in] */ short wbUID,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DocumentDownloadControlFlags( 
            /* [defaultvalue][in] */ short wbUID,
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DocumentHostUiFlags( 
            /* [defaultvalue][in] */ short wbUID,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DocumentHostUiFlags( 
            /* [defaultvalue][in] */ short wbUID,
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DocumentHostUiDoubleClickAction( 
            /* [defaultvalue][in] */ short wbUID,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DocumentHostUiDoubleClickAction( 
            /* [defaultvalue][in] */ short wbUID,
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindTextSimple( 
            /* [in] */ short wbUID,
            /* [in] */ BSTR TextToFind,
            /* [in] */ VARIANT_BOOL bDownward,
            /* [in] */ VARIANT_BOOL bMatchWholeWord,
            /* [in] */ VARIANT_BOOL bMatchCase,
            /* [in] */ VARIANT_BOOL bScrollIntoView,
            /* [out][in] */ VARIANT_BOOL *FindMatch) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindAndHighlightAllText( 
            /* [in] */ short wbUID,
            /* [in] */ BSTR TextToFind,
            /* [in] */ VARIANT_BOOL bMatchWholeWord,
            /* [in] */ VARIANT_BOOL bMatchCase,
            /* [in] */ BSTR HighlightColor,
            /* [out][in] */ long *NumOfMatchsFound) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindAnyTextMatch( 
            /* [in] */ short wbUID,
            /* [in] */ BSTR TextToFind,
            /* [in] */ VARIANT_BOOL bMatchWholeWord,
            /* [in] */ VARIANT_BOOL bMatchCase,
            /* [out][in] */ VARIANT_BOOL *FindMatch) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsDocFrameset( 
            /* [in] */ short wbUID,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ucScheme( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ucScheme( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ucHostName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ucHostName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ucPort( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ucPort( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ucUserName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ucUserName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ucPassword( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ucPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ucUrlPath( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ucUrlPath( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ucExtraInfo( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ucExtraInfo( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ucFullURL( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ucFullURL( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ucFileName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ucFileExtension( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ucInternetCrackUrl( 
            /* [in] */ BSTR URL,
            /* [out][in] */ VARIANT_BOOL *bSuccess) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ucInternetScheme( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ucInternetScheme( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ucInternetCreateUrl( 
            /* [out][in] */ BSTR *URL) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CancelFileDl( 
            /* [in] */ short UIDToCancel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DownloadUrlAsync( 
            /* [in] */ BSTR URL,
            /* [in] */ BSTR SaveFileName,
            /* [out][in] */ short *DLUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RegisterHTTPprotocol( 
            /* [in] */ VARIANT_BOOL pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RegisterHTTPSprotocol( 
            /* [in] */ VARIANT_BOOL pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DisplayCertificateDialog( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadHTMLFromString( 
            /* [in] */ short wbUID,
            /* [in] */ BSTR sContent,
            /* [in] */ BSTR sBaseUrl) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawWBThumbnailOnWnd( 
            /* [in] */ short wbUID,
            /* [in] */ long WndHdc,
            /* [in] */ long lX,
            /* [in] */ long lY,
            /* [in] */ long lW,
            /* [in] */ long lH) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WBPageTextSize( 
            /* [defaultvalue][in] */ short wbUID,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_WBPageTextSize( 
            /* [defaultvalue][in] */ short wbUID,
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ucResetFieldsToDefault( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SubclassWnd( 
            /* [in] */ long hwndWnd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnSubclassWnd( 
            /* [in] */ long hwndWnd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddMessage( 
            /* [in] */ long hwndWnd,
            /* [in] */ long lMsg) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetupShellAutoComplete( 
            /* [in] */ long hwndTarget,
            /* [in] */ VARIANT_BOOL IsTargetComboBox,
            /* [in] */ long lFlags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveAsBitmap( 
            /* [in] */ short wbUID,
            /* [in] */ BSTR BitmapName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WBPostData( 
            /* [in] */ BSTR sURL,
            /* [in] */ BSTR sData,
            /* [out][in] */ short *PostID) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SourceOnDocComplete( 
            /* [defaultvalue][in] */ short wbUID,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SourceOnDocComplete( 
            /* [defaultvalue][in] */ short wbUID,
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OrganizeFavorites( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ViewIEOptions( 
            /* [in] */ short wbUID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindAndHighlightAllTextFrames( 
            /* [in] */ short wbUID,
            /* [in] */ BSTR TextToFind,
            /* [in] */ VARIANT_BOOL bMatchWholeWord,
            /* [in] */ VARIANT_BOOL bMatchCase,
            /* [in] */ BSTR HighlightColor,
            /* [out][in] */ long *NumOfMatchsFound) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetupWindowsHook( 
            /* [in] */ WINDOWSHOOK_TYPES lHookType,
            /* [in] */ long hwndTargetWnd,
            /* [in] */ VARIANT_BOOL bStart,
            /* [out][in] */ long *lUWMHookMsgID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE HookProcNCode( 
            /* [in] */ WINDOWSHOOK_TYPES lHookType,
            /* [out][in] */ long *nCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetupCustomAutoComplete( 
            /* [in] */ long hwndTarget,
            /* [in] */ VARIANT_BOOL IsTargetComboBox,
            /* [in] */ long lCustomAutoCompleteFlags,
            /* [in] */ VARIANT *varStringArray) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CustomAutoCompleteAddString( 
            /* [in] */ long hwndTarget,
            /* [in] */ VARIANT_BOOL IsTargetComboBox,
            /* [in] */ BSTR strItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CustomAutoCompleteEnable( 
            /* [in] */ long hwndTarget,
            /* [in] */ VARIANT_BOOL IsTargetComboBox,
            /* [in] */ VARIANT_BOOL bEnable) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE QueryIERegistryOption( 
            /* [in] */ long IeRegistryOptionsFlag,
            /* [in] */ VARIANT *varBuffer) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetIERegistryOption( 
            /* [in] */ long IeRegistryOptionsFlag,
            /* [in] */ VARIANT *varBuffer) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DecodeMime( 
            /* [in] */ BSTR strToDecode,
            /* [out][in] */ BSTR *strDecoded) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteIEFiles( 
            /* [in] */ DELETE_IE_FILES_FLAGS enumWhichFiles) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IvbWBVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IvbWB * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IvbWB * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IvbWB * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IvbWB * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IvbWB * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IvbWB * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IvbWB * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IvbWB * This,
            /* [retval][out] */ short *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveBrowser )( 
            IvbWB * This,
            /* [in] */ short wbUIDToRemove);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IvbWB * This,
            short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IvbWB * This,
            short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GoBack )( 
            IvbWB * This,
            short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GoForward )( 
            IvbWB * This,
            short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GoHome )( 
            IvbWB * This,
            short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NavigateSimple )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [in] */ BSTR URL);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WebBrowser )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [retval][out] */ LPDISPATCH *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LocationURL )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [retval][out] */ BSTR *pURL);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Offline )( 
            IvbWB * This,
            /* [defaultvalue][in] */ short wbUID,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Offline )( 
            IvbWB * This,
            /* [defaultvalue][in] */ short wbUID,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadyState )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [retval][out] */ READYSTATE *plReadyState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GoSearch )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh2 )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [in] */ VARIANT *level);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Busy )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RegisterAsBrowser )( 
            IvbWB * This,
            /* [defaultvalue][in] */ short wbUID,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RegisterAsBrowser )( 
            IvbWB * This,
            /* [defaultvalue][in] */ short wbUID,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RegisterAsDropTarget )( 
            IvbWB * This,
            /* [defaultvalue][in] */ short wbUID,
            /* [defaultvalue][in] */ VARIANT_BOOL bUseIEDefault,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RegisterAsDropTarget )( 
            IvbWB * This,
            /* [defaultvalue][in] */ short wbUID,
            /* [defaultvalue][in] */ VARIANT_BOOL bUseIEDefault,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Silent )( 
            IvbWB * This,
            /* [defaultvalue][in] */ short wbUID,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Silent )( 
            IvbWB * This,
            /* [defaultvalue][in] */ short wbUID,
            /* [defaultvalue][in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LocationName )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectAll )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Paste )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Cut )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Undo )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Redo )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearSelection )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Find )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PasteSpecial )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Spell )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Properties )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NewWindow )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FileOpen )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveAs )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Print )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PrintPreview )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PageSetup )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Print2 )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PrintPreview2 )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HWNDShellDocObjectView )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HWNDInternetExplorerServer )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ViewSource )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddToFavorites )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetFocusW )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlaceWBOnTop )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HWNDMainWnd )( 
            IvbWB * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AnyDocHasFocus )( 
            IvbWB * This,
            /* [retval][out] */ short *wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExecWB )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [in] */ long cmdID,
            /* [in] */ long cmdExecOpt,
            /* [defaultvalue][in] */ VARIANT *pvaIn,
            /* [defaultvalue][in] */ VARIANT *pvaOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *QueryStatusWB )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [in] */ long cmdID,
            /* [retval][out] */ long *pcmdf);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StartupURL )( 
            IvbWB * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StartupURL )( 
            IvbWB * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseIEDefaultFileDownload )( 
            IvbWB * This,
            /* [defaultvalue][in] */ short wbUID,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseIEDefaultFileDownload )( 
            IvbWB * This,
            /* [defaultvalue][in] */ short wbUID,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HWNDShellEmbedding )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FramesCount )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WBVisible )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_WBVisible )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [retval][out] */ LPDISPATCH *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [retval][out] */ LPDISPATCH *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveElementObj )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [retval][out] */ LPDISPATCH *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveDocumentObj )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [retval][out] */ LPDISPATCH *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Navigate2 )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [in] */ VARIANT *URL,
            /* [defaultvalue][in] */ VARIANT *Flags,
            /* [defaultvalue][in] */ VARIANT *TargetFrameName,
            /* [defaultvalue][in] */ VARIANT *PostData,
            /* [defaultvalue][in] */ VARIANT *Headers);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Navigate )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [in] */ BSTR URL,
            /* [defaultvalue][in] */ VARIANT *Flags,
            /* [defaultvalue][in] */ VARIANT *TargetFrameName,
            /* [defaultvalue][in] */ VARIANT *PostData,
            /* [defaultvalue][in] */ VARIANT *Headers);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddBrowser )( 
            IvbWB * This,
            /* [out][in] */ short *wbUID,
            /* [defaultvalue][in] */ VARIANT_BOOL bBringToFront);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectWB )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [retval][out] */ LPDISPATCH *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ContextMenuAction )( 
            IvbWB * This,
            /* [defaultvalue][in] */ short wbUID,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ContextMenuAction )( 
            IvbWB * This,
            /* [defaultvalue][in] */ short wbUID,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DocumentDownloadControlFlags )( 
            IvbWB * This,
            /* [defaultvalue][in] */ short wbUID,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DocumentDownloadControlFlags )( 
            IvbWB * This,
            /* [defaultvalue][in] */ short wbUID,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DocumentHostUiFlags )( 
            IvbWB * This,
            /* [defaultvalue][in] */ short wbUID,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DocumentHostUiFlags )( 
            IvbWB * This,
            /* [defaultvalue][in] */ short wbUID,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DocumentHostUiDoubleClickAction )( 
            IvbWB * This,
            /* [defaultvalue][in] */ short wbUID,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DocumentHostUiDoubleClickAction )( 
            IvbWB * This,
            /* [defaultvalue][in] */ short wbUID,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindTextSimple )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [in] */ BSTR TextToFind,
            /* [in] */ VARIANT_BOOL bDownward,
            /* [in] */ VARIANT_BOOL bMatchWholeWord,
            /* [in] */ VARIANT_BOOL bMatchCase,
            /* [in] */ VARIANT_BOOL bScrollIntoView,
            /* [out][in] */ VARIANT_BOOL *FindMatch);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindAndHighlightAllText )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [in] */ BSTR TextToFind,
            /* [in] */ VARIANT_BOOL bMatchWholeWord,
            /* [in] */ VARIANT_BOOL bMatchCase,
            /* [in] */ BSTR HighlightColor,
            /* [out][in] */ long *NumOfMatchsFound);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindAnyTextMatch )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [in] */ BSTR TextToFind,
            /* [in] */ VARIANT_BOOL bMatchWholeWord,
            /* [in] */ VARIANT_BOOL bMatchCase,
            /* [out][in] */ VARIANT_BOOL *FindMatch);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsDocFrameset )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ucScheme )( 
            IvbWB * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ucScheme )( 
            IvbWB * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ucHostName )( 
            IvbWB * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ucHostName )( 
            IvbWB * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ucPort )( 
            IvbWB * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ucPort )( 
            IvbWB * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ucUserName )( 
            IvbWB * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ucUserName )( 
            IvbWB * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ucPassword )( 
            IvbWB * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ucPassword )( 
            IvbWB * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ucUrlPath )( 
            IvbWB * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ucUrlPath )( 
            IvbWB * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ucExtraInfo )( 
            IvbWB * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ucExtraInfo )( 
            IvbWB * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ucFullURL )( 
            IvbWB * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ucFullURL )( 
            IvbWB * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ucFileName )( 
            IvbWB * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ucFileExtension )( 
            IvbWB * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ucInternetCrackUrl )( 
            IvbWB * This,
            /* [in] */ BSTR URL,
            /* [out][in] */ VARIANT_BOOL *bSuccess);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ucInternetScheme )( 
            IvbWB * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ucInternetScheme )( 
            IvbWB * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ucInternetCreateUrl )( 
            IvbWB * This,
            /* [out][in] */ BSTR *URL);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CancelFileDl )( 
            IvbWB * This,
            /* [in] */ short UIDToCancel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DownloadUrlAsync )( 
            IvbWB * This,
            /* [in] */ BSTR URL,
            /* [in] */ BSTR SaveFileName,
            /* [out][in] */ short *DLUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RegisterHTTPprotocol )( 
            IvbWB * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RegisterHTTPSprotocol )( 
            IvbWB * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DisplayCertificateDialog )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadHTMLFromString )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [in] */ BSTR sContent,
            /* [in] */ BSTR sBaseUrl);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DrawWBThumbnailOnWnd )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [in] */ long WndHdc,
            /* [in] */ long lX,
            /* [in] */ long lY,
            /* [in] */ long lW,
            /* [in] */ long lH);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WBPageTextSize )( 
            IvbWB * This,
            /* [defaultvalue][in] */ short wbUID,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_WBPageTextSize )( 
            IvbWB * This,
            /* [defaultvalue][in] */ short wbUID,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ucResetFieldsToDefault )( 
            IvbWB * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SubclassWnd )( 
            IvbWB * This,
            /* [in] */ long hwndWnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnSubclassWnd )( 
            IvbWB * This,
            /* [in] */ long hwndWnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddMessage )( 
            IvbWB * This,
            /* [in] */ long hwndWnd,
            /* [in] */ long lMsg);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetupShellAutoComplete )( 
            IvbWB * This,
            /* [in] */ long hwndTarget,
            /* [in] */ VARIANT_BOOL IsTargetComboBox,
            /* [in] */ long lFlags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveAsBitmap )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [in] */ BSTR BitmapName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WBPostData )( 
            IvbWB * This,
            /* [in] */ BSTR sURL,
            /* [in] */ BSTR sData,
            /* [out][in] */ short *PostID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SourceOnDocComplete )( 
            IvbWB * This,
            /* [defaultvalue][in] */ short wbUID,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SourceOnDocComplete )( 
            IvbWB * This,
            /* [defaultvalue][in] */ short wbUID,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OrganizeFavorites )( 
            IvbWB * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ViewIEOptions )( 
            IvbWB * This,
            /* [in] */ short wbUID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindAndHighlightAllTextFrames )( 
            IvbWB * This,
            /* [in] */ short wbUID,
            /* [in] */ BSTR TextToFind,
            /* [in] */ VARIANT_BOOL bMatchWholeWord,
            /* [in] */ VARIANT_BOOL bMatchCase,
            /* [in] */ BSTR HighlightColor,
            /* [out][in] */ long *NumOfMatchsFound);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetupWindowsHook )( 
            IvbWB * This,
            /* [in] */ WINDOWSHOOK_TYPES lHookType,
            /* [in] */ long hwndTargetWnd,
            /* [in] */ VARIANT_BOOL bStart,
            /* [out][in] */ long *lUWMHookMsgID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *HookProcNCode )( 
            IvbWB * This,
            /* [in] */ WINDOWSHOOK_TYPES lHookType,
            /* [out][in] */ long *nCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetupCustomAutoComplete )( 
            IvbWB * This,
            /* [in] */ long hwndTarget,
            /* [in] */ VARIANT_BOOL IsTargetComboBox,
            /* [in] */ long lCustomAutoCompleteFlags,
            /* [in] */ VARIANT *varStringArray);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CustomAutoCompleteAddString )( 
            IvbWB * This,
            /* [in] */ long hwndTarget,
            /* [in] */ VARIANT_BOOL IsTargetComboBox,
            /* [in] */ BSTR strItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CustomAutoCompleteEnable )( 
            IvbWB * This,
            /* [in] */ long hwndTarget,
            /* [in] */ VARIANT_BOOL IsTargetComboBox,
            /* [in] */ VARIANT_BOOL bEnable);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *QueryIERegistryOption )( 
            IvbWB * This,
            /* [in] */ long IeRegistryOptionsFlag,
            /* [in] */ VARIANT *varBuffer);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetIERegistryOption )( 
            IvbWB * This,
            /* [in] */ long IeRegistryOptionsFlag,
            /* [in] */ VARIANT *varBuffer);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DecodeMime )( 
            IvbWB * This,
            /* [in] */ BSTR strToDecode,
            /* [out][in] */ BSTR *strDecoded);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteIEFiles )( 
            IvbWB * This,
            /* [in] */ DELETE_IE_FILES_FLAGS enumWhichFiles);
        
        END_INTERFACE
    } IvbWBVtbl;

    interface IvbWB
    {
        CONST_VTBL struct IvbWBVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IvbWB_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IvbWB_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IvbWB_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IvbWB_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IvbWB_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IvbWB_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IvbWB_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IvbWB_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#define IvbWB_RemoveBrowser(This,wbUIDToRemove)	\
    (This)->lpVtbl -> RemoveBrowser(This,wbUIDToRemove)

#define IvbWB_Refresh(This,wbUID)	\
    (This)->lpVtbl -> Refresh(This,wbUID)

#define IvbWB_Stop(This,wbUID)	\
    (This)->lpVtbl -> Stop(This,wbUID)

#define IvbWB_GoBack(This,wbUID)	\
    (This)->lpVtbl -> GoBack(This,wbUID)

#define IvbWB_GoForward(This,wbUID)	\
    (This)->lpVtbl -> GoForward(This,wbUID)

#define IvbWB_GoHome(This,wbUID)	\
    (This)->lpVtbl -> GoHome(This,wbUID)

#define IvbWB_NavigateSimple(This,wbUID,URL)	\
    (This)->lpVtbl -> NavigateSimple(This,wbUID,URL)

#define IvbWB_get_WebBrowser(This,wbUID,pVal)	\
    (This)->lpVtbl -> get_WebBrowser(This,wbUID,pVal)

#define IvbWB_get_LocationURL(This,wbUID,pURL)	\
    (This)->lpVtbl -> get_LocationURL(This,wbUID,pURL)

#define IvbWB_get_Offline(This,wbUID,pVal)	\
    (This)->lpVtbl -> get_Offline(This,wbUID,pVal)

#define IvbWB_put_Offline(This,wbUID,newVal)	\
    (This)->lpVtbl -> put_Offline(This,wbUID,newVal)

#define IvbWB_ReadyState(This,wbUID,plReadyState)	\
    (This)->lpVtbl -> ReadyState(This,wbUID,plReadyState)

#define IvbWB_GoSearch(This,wbUID)	\
    (This)->lpVtbl -> GoSearch(This,wbUID)

#define IvbWB_Refresh2(This,wbUID,level)	\
    (This)->lpVtbl -> Refresh2(This,wbUID,level)

#define IvbWB_get_Busy(This,wbUID,pVal)	\
    (This)->lpVtbl -> get_Busy(This,wbUID,pVal)

#define IvbWB_get_RegisterAsBrowser(This,wbUID,pVal)	\
    (This)->lpVtbl -> get_RegisterAsBrowser(This,wbUID,pVal)

#define IvbWB_put_RegisterAsBrowser(This,wbUID,newVal)	\
    (This)->lpVtbl -> put_RegisterAsBrowser(This,wbUID,newVal)

#define IvbWB_get_RegisterAsDropTarget(This,wbUID,bUseIEDefault,pVal)	\
    (This)->lpVtbl -> get_RegisterAsDropTarget(This,wbUID,bUseIEDefault,pVal)

#define IvbWB_put_RegisterAsDropTarget(This,wbUID,bUseIEDefault,newVal)	\
    (This)->lpVtbl -> put_RegisterAsDropTarget(This,wbUID,bUseIEDefault,newVal)

#define IvbWB_get_Silent(This,wbUID,pVal)	\
    (This)->lpVtbl -> get_Silent(This,wbUID,pVal)

#define IvbWB_put_Silent(This,wbUID,newVal)	\
    (This)->lpVtbl -> put_Silent(This,wbUID,newVal)

#define IvbWB_get_LocationName(This,wbUID,pVal)	\
    (This)->lpVtbl -> get_LocationName(This,wbUID,pVal)

#define IvbWB_SelectAll(This,wbUID)	\
    (This)->lpVtbl -> SelectAll(This,wbUID)

#define IvbWB_Paste(This,wbUID)	\
    (This)->lpVtbl -> Paste(This,wbUID)

#define IvbWB_Copy(This,wbUID)	\
    (This)->lpVtbl -> Copy(This,wbUID)

#define IvbWB_Cut(This,wbUID)	\
    (This)->lpVtbl -> Cut(This,wbUID)

#define IvbWB_Undo(This,wbUID)	\
    (This)->lpVtbl -> Undo(This,wbUID)

#define IvbWB_Redo(This,wbUID)	\
    (This)->lpVtbl -> Redo(This,wbUID)

#define IvbWB_ClearSelection(This,wbUID)	\
    (This)->lpVtbl -> ClearSelection(This,wbUID)

#define IvbWB_Delete(This,wbUID)	\
    (This)->lpVtbl -> Delete(This,wbUID)

#define IvbWB_Find(This,wbUID)	\
    (This)->lpVtbl -> Find(This,wbUID)

#define IvbWB_PasteSpecial(This,wbUID)	\
    (This)->lpVtbl -> PasteSpecial(This,wbUID)

#define IvbWB_Spell(This,wbUID)	\
    (This)->lpVtbl -> Spell(This,wbUID)

#define IvbWB_Properties(This,wbUID)	\
    (This)->lpVtbl -> Properties(This,wbUID)

#define IvbWB_NewWindow(This,wbUID)	\
    (This)->lpVtbl -> NewWindow(This,wbUID)

#define IvbWB_FileOpen(This,wbUID)	\
    (This)->lpVtbl -> FileOpen(This,wbUID)

#define IvbWB_Save(This,wbUID)	\
    (This)->lpVtbl -> Save(This,wbUID)

#define IvbWB_SaveAs(This,wbUID)	\
    (This)->lpVtbl -> SaveAs(This,wbUID)

#define IvbWB_Print(This,wbUID)	\
    (This)->lpVtbl -> Print(This,wbUID)

#define IvbWB_PrintPreview(This,wbUID)	\
    (This)->lpVtbl -> PrintPreview(This,wbUID)

#define IvbWB_PageSetup(This,wbUID)	\
    (This)->lpVtbl -> PageSetup(This,wbUID)

#define IvbWB_Print2(This,wbUID)	\
    (This)->lpVtbl -> Print2(This,wbUID)

#define IvbWB_PrintPreview2(This,wbUID)	\
    (This)->lpVtbl -> PrintPreview2(This,wbUID)

#define IvbWB_get_HWNDShellDocObjectView(This,wbUID,pVal)	\
    (This)->lpVtbl -> get_HWNDShellDocObjectView(This,wbUID,pVal)

#define IvbWB_get_HWNDInternetExplorerServer(This,wbUID,pVal)	\
    (This)->lpVtbl -> get_HWNDInternetExplorerServer(This,wbUID,pVal)

#define IvbWB_ViewSource(This,wbUID)	\
    (This)->lpVtbl -> ViewSource(This,wbUID)

#define IvbWB_AddToFavorites(This,wbUID)	\
    (This)->lpVtbl -> AddToFavorites(This,wbUID)

#define IvbWB_SetFocusW(This,wbUID)	\
    (This)->lpVtbl -> SetFocusW(This,wbUID)

#define IvbWB_PlaceWBOnTop(This,wbUID)	\
    (This)->lpVtbl -> PlaceWBOnTop(This,wbUID)

#define IvbWB_get_HWNDMainWnd(This,pVal)	\
    (This)->lpVtbl -> get_HWNDMainWnd(This,pVal)

#define IvbWB_AnyDocHasFocus(This,wbUID)	\
    (This)->lpVtbl -> AnyDocHasFocus(This,wbUID)

#define IvbWB_ExecWB(This,wbUID,cmdID,cmdExecOpt,pvaIn,pvaOut)	\
    (This)->lpVtbl -> ExecWB(This,wbUID,cmdID,cmdExecOpt,pvaIn,pvaOut)

#define IvbWB_QueryStatusWB(This,wbUID,cmdID,pcmdf)	\
    (This)->lpVtbl -> QueryStatusWB(This,wbUID,cmdID,pcmdf)

#define IvbWB_get_StartupURL(This,pVal)	\
    (This)->lpVtbl -> get_StartupURL(This,pVal)

#define IvbWB_put_StartupURL(This,newVal)	\
    (This)->lpVtbl -> put_StartupURL(This,newVal)

#define IvbWB_get_UseIEDefaultFileDownload(This,wbUID,pVal)	\
    (This)->lpVtbl -> get_UseIEDefaultFileDownload(This,wbUID,pVal)

#define IvbWB_put_UseIEDefaultFileDownload(This,wbUID,newVal)	\
    (This)->lpVtbl -> put_UseIEDefaultFileDownload(This,wbUID,newVal)

#define IvbWB_get_HWNDShellEmbedding(This,wbUID,pVal)	\
    (This)->lpVtbl -> get_HWNDShellEmbedding(This,wbUID,pVal)

#define IvbWB_get_FramesCount(This,wbUID,pVal)	\
    (This)->lpVtbl -> get_FramesCount(This,wbUID,pVal)

#define IvbWB_get_WBVisible(This,wbUID,pVal)	\
    (This)->lpVtbl -> get_WBVisible(This,wbUID,pVal)

#define IvbWB_put_WBVisible(This,wbUID,newVal)	\
    (This)->lpVtbl -> put_WBVisible(This,wbUID,newVal)

#define IvbWB_get_Application(This,wbUID,pVal)	\
    (This)->lpVtbl -> get_Application(This,wbUID,pVal)

#define IvbWB_get_Document(This,wbUID,pVal)	\
    (This)->lpVtbl -> get_Document(This,wbUID,pVal)

#define IvbWB_get_ActiveElementObj(This,wbUID,pVal)	\
    (This)->lpVtbl -> get_ActiveElementObj(This,wbUID,pVal)

#define IvbWB_get_ActiveDocumentObj(This,wbUID,pVal)	\
    (This)->lpVtbl -> get_ActiveDocumentObj(This,wbUID,pVal)

#define IvbWB_Navigate2(This,wbUID,URL,Flags,TargetFrameName,PostData,Headers)	\
    (This)->lpVtbl -> Navigate2(This,wbUID,URL,Flags,TargetFrameName,PostData,Headers)

#define IvbWB_Navigate(This,wbUID,URL,Flags,TargetFrameName,PostData,Headers)	\
    (This)->lpVtbl -> Navigate(This,wbUID,URL,Flags,TargetFrameName,PostData,Headers)

#define IvbWB_AddBrowser(This,wbUID,bBringToFront)	\
    (This)->lpVtbl -> AddBrowser(This,wbUID,bBringToFront)

#define IvbWB_get_ObjectWB(This,wbUID,pVal)	\
    (This)->lpVtbl -> get_ObjectWB(This,wbUID,pVal)

#define IvbWB_get_ContextMenuAction(This,wbUID,pVal)	\
    (This)->lpVtbl -> get_ContextMenuAction(This,wbUID,pVal)

#define IvbWB_put_ContextMenuAction(This,wbUID,newVal)	\
    (This)->lpVtbl -> put_ContextMenuAction(This,wbUID,newVal)

#define IvbWB_get_DocumentDownloadControlFlags(This,wbUID,pVal)	\
    (This)->lpVtbl -> get_DocumentDownloadControlFlags(This,wbUID,pVal)

#define IvbWB_put_DocumentDownloadControlFlags(This,wbUID,newVal)	\
    (This)->lpVtbl -> put_DocumentDownloadControlFlags(This,wbUID,newVal)

#define IvbWB_get_DocumentHostUiFlags(This,wbUID,pVal)	\
    (This)->lpVtbl -> get_DocumentHostUiFlags(This,wbUID,pVal)

#define IvbWB_put_DocumentHostUiFlags(This,wbUID,newVal)	\
    (This)->lpVtbl -> put_DocumentHostUiFlags(This,wbUID,newVal)

#define IvbWB_get_DocumentHostUiDoubleClickAction(This,wbUID,pVal)	\
    (This)->lpVtbl -> get_DocumentHostUiDoubleClickAction(This,wbUID,pVal)

#define IvbWB_put_DocumentHostUiDoubleClickAction(This,wbUID,newVal)	\
    (This)->lpVtbl -> put_DocumentHostUiDoubleClickAction(This,wbUID,newVal)

#define IvbWB_FindTextSimple(This,wbUID,TextToFind,bDownward,bMatchWholeWord,bMatchCase,bScrollIntoView,FindMatch)	\
    (This)->lpVtbl -> FindTextSimple(This,wbUID,TextToFind,bDownward,bMatchWholeWord,bMatchCase,bScrollIntoView,FindMatch)

#define IvbWB_FindAndHighlightAllText(This,wbUID,TextToFind,bMatchWholeWord,bMatchCase,HighlightColor,NumOfMatchsFound)	\
    (This)->lpVtbl -> FindAndHighlightAllText(This,wbUID,TextToFind,bMatchWholeWord,bMatchCase,HighlightColor,NumOfMatchsFound)

#define IvbWB_FindAnyTextMatch(This,wbUID,TextToFind,bMatchWholeWord,bMatchCase,FindMatch)	\
    (This)->lpVtbl -> FindAnyTextMatch(This,wbUID,TextToFind,bMatchWholeWord,bMatchCase,FindMatch)

#define IvbWB_get_IsDocFrameset(This,wbUID,pVal)	\
    (This)->lpVtbl -> get_IsDocFrameset(This,wbUID,pVal)

#define IvbWB_get_ucScheme(This,pVal)	\
    (This)->lpVtbl -> get_ucScheme(This,pVal)

#define IvbWB_put_ucScheme(This,newVal)	\
    (This)->lpVtbl -> put_ucScheme(This,newVal)

#define IvbWB_get_ucHostName(This,pVal)	\
    (This)->lpVtbl -> get_ucHostName(This,pVal)

#define IvbWB_put_ucHostName(This,newVal)	\
    (This)->lpVtbl -> put_ucHostName(This,newVal)

#define IvbWB_get_ucPort(This,pVal)	\
    (This)->lpVtbl -> get_ucPort(This,pVal)

#define IvbWB_put_ucPort(This,newVal)	\
    (This)->lpVtbl -> put_ucPort(This,newVal)

#define IvbWB_get_ucUserName(This,pVal)	\
    (This)->lpVtbl -> get_ucUserName(This,pVal)

#define IvbWB_put_ucUserName(This,newVal)	\
    (This)->lpVtbl -> put_ucUserName(This,newVal)

#define IvbWB_get_ucPassword(This,pVal)	\
    (This)->lpVtbl -> get_ucPassword(This,pVal)

#define IvbWB_put_ucPassword(This,newVal)	\
    (This)->lpVtbl -> put_ucPassword(This,newVal)

#define IvbWB_get_ucUrlPath(This,pVal)	\
    (This)->lpVtbl -> get_ucUrlPath(This,pVal)

#define IvbWB_put_ucUrlPath(This,newVal)	\
    (This)->lpVtbl -> put_ucUrlPath(This,newVal)

#define IvbWB_get_ucExtraInfo(This,pVal)	\
    (This)->lpVtbl -> get_ucExtraInfo(This,pVal)

#define IvbWB_put_ucExtraInfo(This,newVal)	\
    (This)->lpVtbl -> put_ucExtraInfo(This,newVal)

#define IvbWB_get_ucFullURL(This,pVal)	\
    (This)->lpVtbl -> get_ucFullURL(This,pVal)

#define IvbWB_put_ucFullURL(This,newVal)	\
    (This)->lpVtbl -> put_ucFullURL(This,newVal)

#define IvbWB_get_ucFileName(This,pVal)	\
    (This)->lpVtbl -> get_ucFileName(This,pVal)

#define IvbWB_get_ucFileExtension(This,pVal)	\
    (This)->lpVtbl -> get_ucFileExtension(This,pVal)

#define IvbWB_ucInternetCrackUrl(This,URL,bSuccess)	\
    (This)->lpVtbl -> ucInternetCrackUrl(This,URL,bSuccess)

#define IvbWB_get_ucInternetScheme(This,pVal)	\
    (This)->lpVtbl -> get_ucInternetScheme(This,pVal)

#define IvbWB_put_ucInternetScheme(This,newVal)	\
    (This)->lpVtbl -> put_ucInternetScheme(This,newVal)

#define IvbWB_ucInternetCreateUrl(This,URL)	\
    (This)->lpVtbl -> ucInternetCreateUrl(This,URL)

#define IvbWB_CancelFileDl(This,UIDToCancel)	\
    (This)->lpVtbl -> CancelFileDl(This,UIDToCancel)

#define IvbWB_DownloadUrlAsync(This,URL,SaveFileName,DLUID)	\
    (This)->lpVtbl -> DownloadUrlAsync(This,URL,SaveFileName,DLUID)

#define IvbWB_RegisterHTTPprotocol(This,pVal)	\
    (This)->lpVtbl -> RegisterHTTPprotocol(This,pVal)

#define IvbWB_RegisterHTTPSprotocol(This,pVal)	\
    (This)->lpVtbl -> RegisterHTTPSprotocol(This,pVal)

#define IvbWB_DisplayCertificateDialog(This,wbUID)	\
    (This)->lpVtbl -> DisplayCertificateDialog(This,wbUID)

#define IvbWB_LoadHTMLFromString(This,wbUID,sContent,sBaseUrl)	\
    (This)->lpVtbl -> LoadHTMLFromString(This,wbUID,sContent,sBaseUrl)

#define IvbWB_DrawWBThumbnailOnWnd(This,wbUID,WndHdc,lX,lY,lW,lH)	\
    (This)->lpVtbl -> DrawWBThumbnailOnWnd(This,wbUID,WndHdc,lX,lY,lW,lH)

#define IvbWB_get_WBPageTextSize(This,wbUID,pVal)	\
    (This)->lpVtbl -> get_WBPageTextSize(This,wbUID,pVal)

#define IvbWB_put_WBPageTextSize(This,wbUID,newVal)	\
    (This)->lpVtbl -> put_WBPageTextSize(This,wbUID,newVal)

#define IvbWB_ucResetFieldsToDefault(This)	\
    (This)->lpVtbl -> ucResetFieldsToDefault(This)

#define IvbWB_SubclassWnd(This,hwndWnd)	\
    (This)->lpVtbl -> SubclassWnd(This,hwndWnd)

#define IvbWB_UnSubclassWnd(This,hwndWnd)	\
    (This)->lpVtbl -> UnSubclassWnd(This,hwndWnd)

#define IvbWB_AddMessage(This,hwndWnd,lMsg)	\
    (This)->lpVtbl -> AddMessage(This,hwndWnd,lMsg)

#define IvbWB_SetupShellAutoComplete(This,hwndTarget,IsTargetComboBox,lFlags)	\
    (This)->lpVtbl -> SetupShellAutoComplete(This,hwndTarget,IsTargetComboBox,lFlags)

#define IvbWB_SaveAsBitmap(This,wbUID,BitmapName)	\
    (This)->lpVtbl -> SaveAsBitmap(This,wbUID,BitmapName)

#define IvbWB_WBPostData(This,sURL,sData,PostID)	\
    (This)->lpVtbl -> WBPostData(This,sURL,sData,PostID)

#define IvbWB_get_SourceOnDocComplete(This,wbUID,pVal)	\
    (This)->lpVtbl -> get_SourceOnDocComplete(This,wbUID,pVal)

#define IvbWB_put_SourceOnDocComplete(This,wbUID,newVal)	\
    (This)->lpVtbl -> put_SourceOnDocComplete(This,wbUID,newVal)

#define IvbWB_OrganizeFavorites(This)	\
    (This)->lpVtbl -> OrganizeFavorites(This)

#define IvbWB_ViewIEOptions(This,wbUID)	\
    (This)->lpVtbl -> ViewIEOptions(This,wbUID)

#define IvbWB_FindAndHighlightAllTextFrames(This,wbUID,TextToFind,bMatchWholeWord,bMatchCase,HighlightColor,NumOfMatchsFound)	\
    (This)->lpVtbl -> FindAndHighlightAllTextFrames(This,wbUID,TextToFind,bMatchWholeWord,bMatchCase,HighlightColor,NumOfMatchsFound)

#define IvbWB_SetupWindowsHook(This,lHookType,hwndTargetWnd,bStart,lUWMHookMsgID)	\
    (This)->lpVtbl -> SetupWindowsHook(This,lHookType,hwndTargetWnd,bStart,lUWMHookMsgID)

#define IvbWB_HookProcNCode(This,lHookType,nCode)	\
    (This)->lpVtbl -> HookProcNCode(This,lHookType,nCode)

#define IvbWB_SetupCustomAutoComplete(This,hwndTarget,IsTargetComboBox,lCustomAutoCompleteFlags,varStringArray)	\
    (This)->lpVtbl -> SetupCustomAutoComplete(This,hwndTarget,IsTargetComboBox,lCustomAutoCompleteFlags,varStringArray)

#define IvbWB_CustomAutoCompleteAddString(This,hwndTarget,IsTargetComboBox,strItem)	\
    (This)->lpVtbl -> CustomAutoCompleteAddString(This,hwndTarget,IsTargetComboBox,strItem)

#define IvbWB_CustomAutoCompleteEnable(This,hwndTarget,IsTargetComboBox,bEnable)	\
    (This)->lpVtbl -> CustomAutoCompleteEnable(This,hwndTarget,IsTargetComboBox,bEnable)

#define IvbWB_QueryIERegistryOption(This,IeRegistryOptionsFlag,varBuffer)	\
    (This)->lpVtbl -> QueryIERegistryOption(This,IeRegistryOptionsFlag,varBuffer)

#define IvbWB_SetIERegistryOption(This,IeRegistryOptionsFlag,varBuffer)	\
    (This)->lpVtbl -> SetIERegistryOption(This,IeRegistryOptionsFlag,varBuffer)

#define IvbWB_DecodeMime(This,strToDecode,strDecoded)	\
    (This)->lpVtbl -> DecodeMime(This,strToDecode,strDecoded)

#define IvbWB_DeleteIEFiles(This,enumWhichFiles)	\
    (This)->lpVtbl -> DeleteIEFiles(This,enumWhichFiles)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_Count_Proxy( 
    IvbWB * This,
    /* [retval][out] */ short *pVal);


void __RPC_STUB IvbWB_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_RemoveBrowser_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUIDToRemove);


void __RPC_STUB IvbWB_RemoveBrowser_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_Refresh_Proxy( 
    IvbWB * This,
    short wbUID);


void __RPC_STUB IvbWB_Refresh_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_Stop_Proxy( 
    IvbWB * This,
    short wbUID);


void __RPC_STUB IvbWB_Stop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_GoBack_Proxy( 
    IvbWB * This,
    short wbUID);


void __RPC_STUB IvbWB_GoBack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_GoForward_Proxy( 
    IvbWB * This,
    short wbUID);


void __RPC_STUB IvbWB_GoForward_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_GoHome_Proxy( 
    IvbWB * This,
    short wbUID);


void __RPC_STUB IvbWB_GoHome_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_NavigateSimple_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [in] */ BSTR URL);


void __RPC_STUB IvbWB_NavigateSimple_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_WebBrowser_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [retval][out] */ LPDISPATCH *pVal);


void __RPC_STUB IvbWB_get_WebBrowser_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_LocationURL_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [retval][out] */ BSTR *pURL);


void __RPC_STUB IvbWB_get_LocationURL_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_Offline_Proxy( 
    IvbWB * This,
    /* [defaultvalue][in] */ short wbUID,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IvbWB_get_Offline_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IvbWB_put_Offline_Proxy( 
    IvbWB * This,
    /* [defaultvalue][in] */ short wbUID,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IvbWB_put_Offline_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_ReadyState_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [retval][out] */ READYSTATE *plReadyState);


void __RPC_STUB IvbWB_ReadyState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_GoSearch_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_GoSearch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_Refresh2_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [in] */ VARIANT *level);


void __RPC_STUB IvbWB_Refresh2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_Busy_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IvbWB_get_Busy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_RegisterAsBrowser_Proxy( 
    IvbWB * This,
    /* [defaultvalue][in] */ short wbUID,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IvbWB_get_RegisterAsBrowser_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IvbWB_put_RegisterAsBrowser_Proxy( 
    IvbWB * This,
    /* [defaultvalue][in] */ short wbUID,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IvbWB_put_RegisterAsBrowser_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_RegisterAsDropTarget_Proxy( 
    IvbWB * This,
    /* [defaultvalue][in] */ short wbUID,
    /* [defaultvalue][in] */ VARIANT_BOOL bUseIEDefault,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IvbWB_get_RegisterAsDropTarget_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IvbWB_put_RegisterAsDropTarget_Proxy( 
    IvbWB * This,
    /* [defaultvalue][in] */ short wbUID,
    /* [defaultvalue][in] */ VARIANT_BOOL bUseIEDefault,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IvbWB_put_RegisterAsDropTarget_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_Silent_Proxy( 
    IvbWB * This,
    /* [defaultvalue][in] */ short wbUID,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IvbWB_get_Silent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IvbWB_put_Silent_Proxy( 
    IvbWB * This,
    /* [defaultvalue][in] */ short wbUID,
    /* [defaultvalue][in] */ VARIANT_BOOL newVal);


void __RPC_STUB IvbWB_put_Silent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_LocationName_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IvbWB_get_LocationName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_SelectAll_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_SelectAll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_Paste_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_Paste_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_Copy_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_Copy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_Cut_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_Cut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_Undo_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_Undo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_Redo_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_Redo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_ClearSelection_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_ClearSelection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_Delete_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_Delete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_Find_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_Find_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_PasteSpecial_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_PasteSpecial_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_Spell_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_Spell_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_Properties_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_Properties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_NewWindow_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_NewWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_FileOpen_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_FileOpen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_Save_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_SaveAs_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_SaveAs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_Print_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_Print_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_PrintPreview_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_PrintPreview_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_PageSetup_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_PageSetup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_Print2_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_Print2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_PrintPreview2_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_PrintPreview2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_HWNDShellDocObjectView_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [retval][out] */ long *pVal);


void __RPC_STUB IvbWB_get_HWNDShellDocObjectView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_HWNDInternetExplorerServer_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [retval][out] */ long *pVal);


void __RPC_STUB IvbWB_get_HWNDInternetExplorerServer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_ViewSource_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_ViewSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_AddToFavorites_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_AddToFavorites_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_SetFocusW_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_SetFocusW_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_PlaceWBOnTop_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_PlaceWBOnTop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_HWNDMainWnd_Proxy( 
    IvbWB * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB IvbWB_get_HWNDMainWnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_AnyDocHasFocus_Proxy( 
    IvbWB * This,
    /* [retval][out] */ short *wbUID);


void __RPC_STUB IvbWB_AnyDocHasFocus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_ExecWB_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [in] */ long cmdID,
    /* [in] */ long cmdExecOpt,
    /* [defaultvalue][in] */ VARIANT *pvaIn,
    /* [defaultvalue][in] */ VARIANT *pvaOut);


void __RPC_STUB IvbWB_ExecWB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_QueryStatusWB_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [in] */ long cmdID,
    /* [retval][out] */ long *pcmdf);


void __RPC_STUB IvbWB_QueryStatusWB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_StartupURL_Proxy( 
    IvbWB * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IvbWB_get_StartupURL_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IvbWB_put_StartupURL_Proxy( 
    IvbWB * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IvbWB_put_StartupURL_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_UseIEDefaultFileDownload_Proxy( 
    IvbWB * This,
    /* [defaultvalue][in] */ short wbUID,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IvbWB_get_UseIEDefaultFileDownload_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IvbWB_put_UseIEDefaultFileDownload_Proxy( 
    IvbWB * This,
    /* [defaultvalue][in] */ short wbUID,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IvbWB_put_UseIEDefaultFileDownload_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_HWNDShellEmbedding_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [retval][out] */ long *pVal);


void __RPC_STUB IvbWB_get_HWNDShellEmbedding_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_FramesCount_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [retval][out] */ long *pVal);


void __RPC_STUB IvbWB_get_FramesCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_WBVisible_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IvbWB_get_WBVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IvbWB_put_WBVisible_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IvbWB_put_WBVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_Application_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [retval][out] */ LPDISPATCH *pVal);


void __RPC_STUB IvbWB_get_Application_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_Document_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [retval][out] */ LPDISPATCH *pVal);


void __RPC_STUB IvbWB_get_Document_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_ActiveElementObj_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [retval][out] */ LPDISPATCH *pVal);


void __RPC_STUB IvbWB_get_ActiveElementObj_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_ActiveDocumentObj_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [retval][out] */ LPDISPATCH *pVal);


void __RPC_STUB IvbWB_get_ActiveDocumentObj_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_Navigate2_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [in] */ VARIANT *URL,
    /* [defaultvalue][in] */ VARIANT *Flags,
    /* [defaultvalue][in] */ VARIANT *TargetFrameName,
    /* [defaultvalue][in] */ VARIANT *PostData,
    /* [defaultvalue][in] */ VARIANT *Headers);


void __RPC_STUB IvbWB_Navigate2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_Navigate_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [in] */ BSTR URL,
    /* [defaultvalue][in] */ VARIANT *Flags,
    /* [defaultvalue][in] */ VARIANT *TargetFrameName,
    /* [defaultvalue][in] */ VARIANT *PostData,
    /* [defaultvalue][in] */ VARIANT *Headers);


void __RPC_STUB IvbWB_Navigate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_AddBrowser_Proxy( 
    IvbWB * This,
    /* [out][in] */ short *wbUID,
    /* [defaultvalue][in] */ VARIANT_BOOL bBringToFront);


void __RPC_STUB IvbWB_AddBrowser_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_ObjectWB_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [retval][out] */ LPDISPATCH *pVal);


void __RPC_STUB IvbWB_get_ObjectWB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_ContextMenuAction_Proxy( 
    IvbWB * This,
    /* [defaultvalue][in] */ short wbUID,
    /* [retval][out] */ long *pVal);


void __RPC_STUB IvbWB_get_ContextMenuAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IvbWB_put_ContextMenuAction_Proxy( 
    IvbWB * This,
    /* [defaultvalue][in] */ short wbUID,
    /* [in] */ long newVal);


void __RPC_STUB IvbWB_put_ContextMenuAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_DocumentDownloadControlFlags_Proxy( 
    IvbWB * This,
    /* [defaultvalue][in] */ short wbUID,
    /* [retval][out] */ long *pVal);


void __RPC_STUB IvbWB_get_DocumentDownloadControlFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IvbWB_put_DocumentDownloadControlFlags_Proxy( 
    IvbWB * This,
    /* [defaultvalue][in] */ short wbUID,
    /* [in] */ long newVal);


void __RPC_STUB IvbWB_put_DocumentDownloadControlFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_DocumentHostUiFlags_Proxy( 
    IvbWB * This,
    /* [defaultvalue][in] */ short wbUID,
    /* [retval][out] */ long *pVal);


void __RPC_STUB IvbWB_get_DocumentHostUiFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IvbWB_put_DocumentHostUiFlags_Proxy( 
    IvbWB * This,
    /* [defaultvalue][in] */ short wbUID,
    /* [in] */ long newVal);


void __RPC_STUB IvbWB_put_DocumentHostUiFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_DocumentHostUiDoubleClickAction_Proxy( 
    IvbWB * This,
    /* [defaultvalue][in] */ short wbUID,
    /* [retval][out] */ long *pVal);


void __RPC_STUB IvbWB_get_DocumentHostUiDoubleClickAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IvbWB_put_DocumentHostUiDoubleClickAction_Proxy( 
    IvbWB * This,
    /* [defaultvalue][in] */ short wbUID,
    /* [in] */ long newVal);


void __RPC_STUB IvbWB_put_DocumentHostUiDoubleClickAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_FindTextSimple_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [in] */ BSTR TextToFind,
    /* [in] */ VARIANT_BOOL bDownward,
    /* [in] */ VARIANT_BOOL bMatchWholeWord,
    /* [in] */ VARIANT_BOOL bMatchCase,
    /* [in] */ VARIANT_BOOL bScrollIntoView,
    /* [out][in] */ VARIANT_BOOL *FindMatch);


void __RPC_STUB IvbWB_FindTextSimple_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_FindAndHighlightAllText_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [in] */ BSTR TextToFind,
    /* [in] */ VARIANT_BOOL bMatchWholeWord,
    /* [in] */ VARIANT_BOOL bMatchCase,
    /* [in] */ BSTR HighlightColor,
    /* [out][in] */ long *NumOfMatchsFound);


void __RPC_STUB IvbWB_FindAndHighlightAllText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_FindAnyTextMatch_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [in] */ BSTR TextToFind,
    /* [in] */ VARIANT_BOOL bMatchWholeWord,
    /* [in] */ VARIANT_BOOL bMatchCase,
    /* [out][in] */ VARIANT_BOOL *FindMatch);


void __RPC_STUB IvbWB_FindAnyTextMatch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_IsDocFrameset_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IvbWB_get_IsDocFrameset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_ucScheme_Proxy( 
    IvbWB * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IvbWB_get_ucScheme_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IvbWB_put_ucScheme_Proxy( 
    IvbWB * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IvbWB_put_ucScheme_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_ucHostName_Proxy( 
    IvbWB * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IvbWB_get_ucHostName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IvbWB_put_ucHostName_Proxy( 
    IvbWB * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IvbWB_put_ucHostName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_ucPort_Proxy( 
    IvbWB * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB IvbWB_get_ucPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IvbWB_put_ucPort_Proxy( 
    IvbWB * This,
    /* [in] */ long newVal);


void __RPC_STUB IvbWB_put_ucPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_ucUserName_Proxy( 
    IvbWB * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IvbWB_get_ucUserName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IvbWB_put_ucUserName_Proxy( 
    IvbWB * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IvbWB_put_ucUserName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_ucPassword_Proxy( 
    IvbWB * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IvbWB_get_ucPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IvbWB_put_ucPassword_Proxy( 
    IvbWB * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IvbWB_put_ucPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_ucUrlPath_Proxy( 
    IvbWB * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IvbWB_get_ucUrlPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IvbWB_put_ucUrlPath_Proxy( 
    IvbWB * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IvbWB_put_ucUrlPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_ucExtraInfo_Proxy( 
    IvbWB * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IvbWB_get_ucExtraInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IvbWB_put_ucExtraInfo_Proxy( 
    IvbWB * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IvbWB_put_ucExtraInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_ucFullURL_Proxy( 
    IvbWB * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IvbWB_get_ucFullURL_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IvbWB_put_ucFullURL_Proxy( 
    IvbWB * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IvbWB_put_ucFullURL_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_ucFileName_Proxy( 
    IvbWB * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IvbWB_get_ucFileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_ucFileExtension_Proxy( 
    IvbWB * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IvbWB_get_ucFileExtension_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_ucInternetCrackUrl_Proxy( 
    IvbWB * This,
    /* [in] */ BSTR URL,
    /* [out][in] */ VARIANT_BOOL *bSuccess);


void __RPC_STUB IvbWB_ucInternetCrackUrl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_ucInternetScheme_Proxy( 
    IvbWB * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB IvbWB_get_ucInternetScheme_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IvbWB_put_ucInternetScheme_Proxy( 
    IvbWB * This,
    /* [in] */ long newVal);


void __RPC_STUB IvbWB_put_ucInternetScheme_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_ucInternetCreateUrl_Proxy( 
    IvbWB * This,
    /* [out][in] */ BSTR *URL);


void __RPC_STUB IvbWB_ucInternetCreateUrl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_CancelFileDl_Proxy( 
    IvbWB * This,
    /* [in] */ short UIDToCancel);


void __RPC_STUB IvbWB_CancelFileDl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_DownloadUrlAsync_Proxy( 
    IvbWB * This,
    /* [in] */ BSTR URL,
    /* [in] */ BSTR SaveFileName,
    /* [out][in] */ short *DLUID);


void __RPC_STUB IvbWB_DownloadUrlAsync_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_RegisterHTTPprotocol_Proxy( 
    IvbWB * This,
    /* [in] */ VARIANT_BOOL pVal);


void __RPC_STUB IvbWB_RegisterHTTPprotocol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_RegisterHTTPSprotocol_Proxy( 
    IvbWB * This,
    /* [in] */ VARIANT_BOOL pVal);


void __RPC_STUB IvbWB_RegisterHTTPSprotocol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_DisplayCertificateDialog_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_DisplayCertificateDialog_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_LoadHTMLFromString_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [in] */ BSTR sContent,
    /* [in] */ BSTR sBaseUrl);


void __RPC_STUB IvbWB_LoadHTMLFromString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_DrawWBThumbnailOnWnd_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [in] */ long WndHdc,
    /* [in] */ long lX,
    /* [in] */ long lY,
    /* [in] */ long lW,
    /* [in] */ long lH);


void __RPC_STUB IvbWB_DrawWBThumbnailOnWnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_WBPageTextSize_Proxy( 
    IvbWB * This,
    /* [defaultvalue][in] */ short wbUID,
    /* [retval][out] */ long *pVal);


void __RPC_STUB IvbWB_get_WBPageTextSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IvbWB_put_WBPageTextSize_Proxy( 
    IvbWB * This,
    /* [defaultvalue][in] */ short wbUID,
    /* [in] */ long newVal);


void __RPC_STUB IvbWB_put_WBPageTextSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_ucResetFieldsToDefault_Proxy( 
    IvbWB * This);


void __RPC_STUB IvbWB_ucResetFieldsToDefault_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_SubclassWnd_Proxy( 
    IvbWB * This,
    /* [in] */ long hwndWnd);


void __RPC_STUB IvbWB_SubclassWnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_UnSubclassWnd_Proxy( 
    IvbWB * This,
    /* [in] */ long hwndWnd);


void __RPC_STUB IvbWB_UnSubclassWnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_AddMessage_Proxy( 
    IvbWB * This,
    /* [in] */ long hwndWnd,
    /* [in] */ long lMsg);


void __RPC_STUB IvbWB_AddMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_SetupShellAutoComplete_Proxy( 
    IvbWB * This,
    /* [in] */ long hwndTarget,
    /* [in] */ VARIANT_BOOL IsTargetComboBox,
    /* [in] */ long lFlags);


void __RPC_STUB IvbWB_SetupShellAutoComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_SaveAsBitmap_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [in] */ BSTR BitmapName);


void __RPC_STUB IvbWB_SaveAsBitmap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_WBPostData_Proxy( 
    IvbWB * This,
    /* [in] */ BSTR sURL,
    /* [in] */ BSTR sData,
    /* [out][in] */ short *PostID);


void __RPC_STUB IvbWB_WBPostData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbWB_get_SourceOnDocComplete_Proxy( 
    IvbWB * This,
    /* [defaultvalue][in] */ short wbUID,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IvbWB_get_SourceOnDocComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IvbWB_put_SourceOnDocComplete_Proxy( 
    IvbWB * This,
    /* [defaultvalue][in] */ short wbUID,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IvbWB_put_SourceOnDocComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_OrganizeFavorites_Proxy( 
    IvbWB * This);


void __RPC_STUB IvbWB_OrganizeFavorites_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_ViewIEOptions_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID);


void __RPC_STUB IvbWB_ViewIEOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_FindAndHighlightAllTextFrames_Proxy( 
    IvbWB * This,
    /* [in] */ short wbUID,
    /* [in] */ BSTR TextToFind,
    /* [in] */ VARIANT_BOOL bMatchWholeWord,
    /* [in] */ VARIANT_BOOL bMatchCase,
    /* [in] */ BSTR HighlightColor,
    /* [out][in] */ long *NumOfMatchsFound);


void __RPC_STUB IvbWB_FindAndHighlightAllTextFrames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_SetupWindowsHook_Proxy( 
    IvbWB * This,
    /* [in] */ WINDOWSHOOK_TYPES lHookType,
    /* [in] */ long hwndTargetWnd,
    /* [in] */ VARIANT_BOOL bStart,
    /* [out][in] */ long *lUWMHookMsgID);


void __RPC_STUB IvbWB_SetupWindowsHook_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_HookProcNCode_Proxy( 
    IvbWB * This,
    /* [in] */ WINDOWSHOOK_TYPES lHookType,
    /* [out][in] */ long *nCode);


void __RPC_STUB IvbWB_HookProcNCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_SetupCustomAutoComplete_Proxy( 
    IvbWB * This,
    /* [in] */ long hwndTarget,
    /* [in] */ VARIANT_BOOL IsTargetComboBox,
    /* [in] */ long lCustomAutoCompleteFlags,
    /* [in] */ VARIANT *varStringArray);


void __RPC_STUB IvbWB_SetupCustomAutoComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_CustomAutoCompleteAddString_Proxy( 
    IvbWB * This,
    /* [in] */ long hwndTarget,
    /* [in] */ VARIANT_BOOL IsTargetComboBox,
    /* [in] */ BSTR strItem);


void __RPC_STUB IvbWB_CustomAutoCompleteAddString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_CustomAutoCompleteEnable_Proxy( 
    IvbWB * This,
    /* [in] */ long hwndTarget,
    /* [in] */ VARIANT_BOOL IsTargetComboBox,
    /* [in] */ VARIANT_BOOL bEnable);


void __RPC_STUB IvbWB_CustomAutoCompleteEnable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_QueryIERegistryOption_Proxy( 
    IvbWB * This,
    /* [in] */ long IeRegistryOptionsFlag,
    /* [in] */ VARIANT *varBuffer);


void __RPC_STUB IvbWB_QueryIERegistryOption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_SetIERegistryOption_Proxy( 
    IvbWB * This,
    /* [in] */ long IeRegistryOptionsFlag,
    /* [in] */ VARIANT *varBuffer);


void __RPC_STUB IvbWB_SetIERegistryOption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_DecodeMime_Proxy( 
    IvbWB * This,
    /* [in] */ BSTR strToDecode,
    /* [out][in] */ BSTR *strDecoded);


void __RPC_STUB IvbWB_DecodeMime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbWB_DeleteIEFiles_Proxy( 
    IvbWB * This,
    /* [in] */ DELETE_IE_FILES_FLAGS enumWhichFiles);


void __RPC_STUB IvbWB_DeleteIEFiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IvbWB_INTERFACE_DEFINED__ */



#ifndef __VBMHWBLib_LIBRARY_DEFINED__
#define __VBMHWBLib_LIBRARY_DEFINED__

/* library VBMHWBLib */
/* [helpstring][version][uuid] */ 

typedef 
enum NEW_WINDOW3_FLAGS
    {	NWMF_UNLOADING	= 0x1,
	NWMF_USERINITED	= 0x2,
	NWMF_FIRST	= 0x4,
	NWMF_OVERRIDEKEY	= 0x8,
	NWMF_SHOWHELP	= 0x10,
	NWMF_HTMLDIALOG	= 0x20,
	NWMF_FROMDIALOGCHILD	= 0x40,
	NWMF_USERREQUESTED	= 0x80,
	NWMF_USERALLOWED	= 0x100
    } 	NEW_WINDOW3_FLAGS;

typedef 
enum WB_DOC_HOST_UI_DBL_CLK
    {	WBDOCHOSTUIDBLCLK_DEFAULT	= 0,
	WBDOCHOSTUIDBLCLK_SHOWPROPERTIES	= 1,
	WBDOCHOSTUIDBLCLK_SHOWCODE	= 2
    } 	WB_DOC_HOST_UI_DBL_CLK;

typedef 
enum WB_DOC_HOST_UI_FLAGS
    {	WBDOCHOSTUIFLAG_DIALOG	= 0x1,
	WBDOCHOSTUIFLAG_DISABLE_HELP_MENU	= 0x2,
	WBDOCHOSTUIFLAG_NO3DBORDER	= 0x4,
	WBDOCHOSTUIFLAG_SCROLL_NO	= 0x8,
	WBDOCHOSTUIFLAG_DISABLE_SCRIPT_INACTIVE	= 0x10,
	WBDOCHOSTUIFLAG_OPENNEWWIN	= 0x20,
	WBDOCHOSTUIFLAG_DISABLE_OFFSCREEN	= 0x40,
	WBDOCHOSTUIFLAG_FLAT_SCROLLBAR	= 0x80,
	WBDOCHOSTUIFLAG_DIV_BLOCKDEFAULT	= 0x100,
	WBDOCHOSTUIFLAG_ACTIVATE_CLIENTHIT_ONLY	= 0x200,
	WBDOCHOSTUIFLAG_OVERRIDEBEHAVIORFACTORY	= 0x400,
	WBDOCHOSTUIFLAG_CODEPAGELINKEDFONTS	= 0x800,
	WBDOCHOSTUIFLAG_URL_ENCODING_DISABLE_UTF8	= 0x1000,
	WBDOCHOSTUIFLAG_URL_ENCODING_ENABLE_UTF8	= 0x2000,
	WBDOCHOSTUIFLAG_ENABLE_FORMS_AUTOCOMPLETE	= 0x4000,
	WBDOCHOSTUIFLAG_ENABLE_INPLACE_NAVIGATION	= 0x10000,
	WBDOCHOSTUIFLAG_IME_ENABLE_RECONVERSION	= 0x20000,
	WBDOCHOSTUIFLAG_THEME	= 0x40000,
	WBDOCHOSTUIFLAG_NOTHEME	= 0x80000,
	WBDOCHOSTUIFLAG_NOPICS	= 0x100000,
	WBDOCHOSTUIFLAG_NO3DOUTERBORDER	= 0x200000,
	WBDOCHOSTUIFLAG_DISABLE_EDIT_NS_FIXUP	= 0x400000,
	WBDOCHOSTUIFLAG_LOCAL_MACHINE_ACCESS_CHECK	= 0x800000,
	WBDOCHOSTUIFLAG_DISABLE_UNTRUSTEDPROTOCOL	= 0x1000000
    } 	WB_DOC_HOST_UI_FLAGS;

typedef 
enum WB_DOC_DOWNLOAD_CONTROL_FLAGS
    {	WBDOCDOWNLOADCTLFLAG_DLIMAGES	= 0x10,
	WBDOCDOWNLOADCTLFLAG_VIDEOS	= 0x20,
	WBDOCDOWNLOADCTLFLAG_BGSOUNDS	= 0x40,
	WBDOCDOWNLOADCTLFLAG_NO_SCRIPTS	= 0x80,
	WBDOCDOWNLOADCTLFLAG_NO_JAVA	= 0x100,
	WBDOCDOWNLOADCTLFLAG_NO_RUNACTIVEXCTLS	= 0x200,
	WBDOCDOWNLOADCTLFLAG_NO_DLACTIVEXCTLS	= 0x400,
	WBDOCDOWNLOADCTLFLAG_DOWNLOADONLY	= 0x800,
	WBDOCDOWNLOADCTLFLAG_NO_FRAMEDOWNLOAD	= 0x1000,
	WBDOCDOWNLOADCTLFLAG_RESYNCHRONIZE	= 0x2000,
	WBDOCDOWNLOADCTLFLAG_PRAGMA_NO_CACHE	= 0x4000,
	WBDOCDOWNLOADCTLFLAG_NO_BEHAVIORS	= 0x8000,
	WBDOCDOWNLOADCTLFLAG_NO_METACHARSET	= 0x10000,
	WBDOCDOWNLOADCTLFLAG_URL_ENCODING_DISABLE_UTF8	= 0x20000,
	WBDOCDOWNLOADCTLFLAG_URL_ENCODING_ENABLE_UTF8	= 0x40000,
	WBDOCDOWNLOADCTLFLAG_NOFRAMES	= 0x80000,
	WBDOCDOWNLOADCTLFLAG_FORCEOFFLINE	= 0x10000000,
	WBDOCDOWNLOADCTLFLAG_NO_CLIENTPULL	= 0x20000000,
	WBDOCDOWNLOADCTLFLAG_SILENT	= 0x40000000,
	WBDOCDOWNLOADCTLFLAG_OFFLINEIFNOTCONNECTED	= 0x80000000,
	WBDOCDOWNLOADCTLFLAG_OFFLINE	= 0x80000000
    } 	WB_DOC_DOWNLOAD_CONTROL_FLAGS;

typedef 
enum WB_CONTEXT_MENU_TYPE
    {	WBCONTEXTMENUTYPE_DEFAULT	= 0,
	WBCONTEXTMENUTYPE_IMAGE	= 1,
	WBCONTEXTMENUTYPE_CONTROL	= 2,
	WBCONTEXTMENUTYPE_TABLE	= 3,
	WBCONTEXTMENUTYPE_TEXTSELECT	= 4,
	WBCONTEXTMENUTYPE_ANCHOR	= 5,
	WBCONTEXTMENUTYPE_UNKNOWN	= 6,
	WBCONTEXTMENUTYPE_IMGDYNSRC	= 7,
	WBCONTEXTMENUTYPE_IMGART	= 8,
	WBCONTEXTMENUTYPE_DEBUG	= 9,
	WBCONTEXTMENUTYPE_VSCROLL	= 10,
	WBCONTEXTMENUTYPE_HSCROLL	= 11
    } 	WB_CONTEXT_MENU_TYPE;

typedef 
enum WB_CONTEXT_MENU_ACTION
    {	WBCONTEXTMENUACTION_DISPLAY_NONE	= 0,
	WBCONTEXTMENUACTION_DISPLAY_IE_DEFAULT	= 1,
	WBCONTEXTMENUACTION_RAISE_ONCONTEXTMENU_EVENT	= 2
    } 	WB_CONTEXT_MENU_ACTION;

typedef 
enum WB_DROP_FORMATS
    {	WB_CFHTML	= 0,
	WB_CFTEXT	= 1,
	WB_CFSINGLEFILE	= 2,
	WB_CFRTF	= 3,
	WB_CFERROR	= 4
    } 	WB_DROP_FORMATS;

typedef 
enum AUTOCOMPLETE_FLAGS
    {	SHELLACF_DEFAULT	= 0,
	SHELLACF_FILESYSTEM	= 0x1,
	SHELLACF_URLHISTORY	= 0x2,
	SHELLACF_URLMRU	= 0x4,
	SHELLACF_URLALL	= SHELLACF_URLHISTORY | SHELLACF_URLMRU,
	SHELLACF_USETAB	= 0x8,
	SHELLACF_FILESYS_ONLY	= 0x10,
	SHELLACF_FILESYS_DIRS	= 0x20,
	SHELLACF_AUTOSUGGEST_FORCE_ON	= 0x10000000,
	SHELLACF_AUTOSUGGEST_FORCE_OFF	= 0x20000000,
	SHELLACF_AUTOAPPEND_FORCE_ON	= 0x40000000,
	SHELLACF_AUTOAPPEND_FORCE_OFF	= 0x80000000
    } 	AUTOCOMPLETE_FLAGS;

typedef 
enum CUSTOM_AUTOCOMPLETE_FLAGS
    {	CACO_NONE	= 0,
	CACO_AUTOSUGGEST	= 0x1,
	CACO_AUTOAPPEND	= 0x2,
	CACO_SEARCH	= 0x4,
	CACO_FILTERPREFIXES	= 0x8,
	CACO_USETAB	= 0x10,
	CACO_UPDOWNKEYDROPSLIST	= 0x20,
	CACO_RTLREADING	= 0x40
    } 	CUSTOM_AUTOCOMPLETE_FLAGS;

typedef 
enum IE_REGISTRY_OPTIONS_FLAGS
    {	DISABLE_SCRIPT_DEBUGGER	= 0,
	ERROR_DLG_DISPLAYED_ON_EVERY_ERROR	= 1,
	PLAY_ANIMATIONS	= 2,
	PLAY_BACKGROUND_SOUNDS	= 3,
	DISPLAY_INLINE_VIDEOS	= 4,
	DISPLAY_INLINE_IMAGES	= 5,
	FORMSUGGEST_PW_ASK	= 6,
	USE_FORMSUGGEST	= 7,
	USE_SEARCH_ASST	= 8
    } 	IE_REGISTRY_OPTIONS_FLAGS;


EXTERN_C const IID LIBID_VBMHWBLib;

#ifndef ___IvbWBEvents_DISPINTERFACE_DEFINED__
#define ___IvbWBEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IvbWBEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IvbWBEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("A8096483-2E53-45CF-A0E5-4E17CED6B7EF")
    _IvbWBEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IvbWBEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IvbWBEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IvbWBEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IvbWBEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IvbWBEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IvbWBEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IvbWBEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IvbWBEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IvbWBEventsVtbl;

    interface _IvbWBEvents
    {
        CONST_VTBL struct _IvbWBEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IvbWBEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IvbWBEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IvbWBEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IvbWBEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IvbWBEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IvbWBEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IvbWBEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IvbWBEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_vbWB;

#ifdef __cplusplus

class DECLSPEC_UUID("20247C83-3429-47B1-817F-C99F29D2BF3A")
vbWB;
#endif
#endif /* __VBMHWBLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



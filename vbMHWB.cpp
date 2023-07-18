// vbMHWB.cpp : Implementation of DLL Exports.


// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL, 
//      run nmake -f vbMHWBps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"

//Globals
CSimpleArray<void*> gCtrlInstances;
BOOL gb_IsHttpRegistered;
BOOL gb_IsHttpsRegistered;
CComPtr<IClassFactory> m_spCFHTTP;
CComPtr<IClassFactory> m_spCFHTTPS;

CComModule _Module;

#include "vbMHWB.h"

#include "vbMHWB_i.c"
#include "vbWB.h"

BEGIN_OBJECT_MAP(ObjectMap)
OBJECT_ENTRY(CLSID_vbWB, CvbWB)
END_OBJECT_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C"
BOOL WINAPI DllMain(HANDLE hInstance, DWORD dwReason, LPVOID /*lpReserved*/)
{

    if (dwReason == DLL_PROCESS_ATTACH)
    {
        //Default is false
        gb_IsHttpRegistered = FALSE;
        gb_IsHttpsRegistered = FALSE;
        _Module.Init(ObjectMap, (HINSTANCE)hInstance, &LIBID_VBMHWBLib);
        DisableThreadLibraryCalls((HINSTANCE)hInstance);
    }
    else if (dwReason == DLL_PROCESS_DETACH)
    {
        //Any registered HTTPProtocol + HTTPSProtocol
        //will be unregistered once we are done here
        if(gCtrlInstances.GetSize() > 0)
        {
            for(int i = 0; i < gCtrlInstances.GetSize(); i++)
                gCtrlInstances[i] = NULL;
        }
        gCtrlInstances.RemoveAll();
        _Module.Term();
    }
    return TRUE;    // ok
}

/////////////////////////////////////////////////////////////////////////////
// Used to determine whether the DLL can be unloaded by OLE

STDAPI DllCanUnloadNow(void)
{
    return (_Module.GetLockCount()==0) ? S_OK : S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// Returns a class factory to create an object of the requested type

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _Module.GetClassObject(rclsid, riid, ppv);
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
    // registers object, typelib and all interfaces in typelib
    return _Module.RegisterServer(TRUE);
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
    return _Module.UnregisterServer(TRUE);
}

#ifdef _WIN32_WCE
HRESULT ATL::AtlRegisterClassCategoriesHelper(
    _In_ REFCLSID clsid,
    _In_opt_ const struct _ATL_CATMAP_ENTRY* pCatMap,
    _In_ BOOL bRegister)
{
    return S_OK;
}
#endif

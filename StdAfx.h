// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#define STRICT

#define _WIN32_WINNT 0x0501
#define _WIN32_IE    0x0600

#define _ATL_APARTMENT_THREADED

#include <atlbase.h>

//gCtrlInstances keeps track of each instance of our control
//This global is needed due to the fact that a client may place
//this control on more than one form/dlg or have multiple instances of BW
//hosting in one control. In this case, using one
//global ptr to our control will cause the events to be routed to the
//first control, not the one we want. The control instances (this) is
//added to this array in Constructor and removed in Destructor or CvbWB class.
extern CSimpleArray<void*> gCtrlInstances;

//Flag to track registering and unregistering of HTTP/HTTPS protocols
//Can only be done once per DLL load. Effects all instances of WB.
extern BOOL gb_IsHttpRegistered;
extern BOOL gb_IsHttpsRegistered;
//Protocol handling
extern CComPtr<IClassFactory> m_spCFHTTP;
extern CComPtr<IClassFactory> m_spCFHTTPS;

extern CComModule _Module;
#include <atlcom.h>
#include <atlhost.h>
#include <wininet.h>

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

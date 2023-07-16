

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_INewWindowManager,0xD2BC4C84,0x3F72,0x4a52,0xA6,0x04,0x7B,0xCB,0xF3,0x98,0x2C,0xBB);


MIDL_DEFINE_GUID(IID, IID_IHTMLOMWindowServices,0x3050f5fc,0x98b5,0x11cf,0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b);


MIDL_DEFINE_GUID(IID, IID_IDownloadManager,0x988934A4,0x064B,0x11D3,0xBB,0x80,0x00,0x10,0x4B,0x35,0xE7,0xF9);


MIDL_DEFINE_GUID(IID, IID_IvbWB,0x6E73D516,0x7CDC,0x435E,0x8A,0x8D,0x86,0xE0,0xAE,0x4D,0x5E,0x08);


MIDL_DEFINE_GUID(IID, LIBID_VBMHWBLib,0x33658027,0x1004,0x4E1E,0x8D,0x35,0xC9,0x14,0x6D,0xF8,0x79,0x19);


MIDL_DEFINE_GUID(IID, DIID__IvbWBEvents,0xA8096483,0x2E53,0x45CF,0xA0,0xE5,0x4E,0x17,0xCE,0xD6,0xB7,0xEF);


MIDL_DEFINE_GUID(CLSID, CLSID_vbWB,0x20247C83,0x3429,0x47B1,0x81,0x7F,0xC9,0x9F,0x29,0xD2,0xBF,0x3A);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_INewWindowManager,0xD2BC4C84,0x3F72,0x4a52,0xA6,0x04,0x7B,0xCB,0xF3,0x98,0x2C,0xBB);


MIDL_DEFINE_GUID(IID, IID_IHTMLOMWindowServices,0x3050f5fc,0x98b5,0x11cf,0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b);


MIDL_DEFINE_GUID(IID, IID_IDownloadManager,0x988934A4,0x064B,0x11D3,0xBB,0x80,0x00,0x10,0x4B,0x35,0xE7,0xF9);


MIDL_DEFINE_GUID(IID, IID_IvbWB,0x6E73D516,0x7CDC,0x435E,0x8A,0x8D,0x86,0xE0,0xAE,0x4D,0x5E,0x08);


MIDL_DEFINE_GUID(IID, LIBID_VBMHWBLib,0x33658027,0x1004,0x4E1E,0x8D,0x35,0xC9,0x14,0x6D,0xF8,0x79,0x19);


MIDL_DEFINE_GUID(IID, DIID__IvbWBEvents,0xA8096483,0x2E53,0x45CF,0xA0,0xE5,0x4E,0x17,0xCE,0xD6,0xB7,0xEF);


MIDL_DEFINE_GUID(CLSID, CLSID_vbWB,0x20247C83,0x3429,0x47B1,0x81,0x7F,0xC9,0x9F,0x29,0xD2,0xBF,0x3A);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* defined(_M_IA64) || defined(_M_AMD64)*/


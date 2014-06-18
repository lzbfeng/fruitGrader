

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sat Mar 30 13:43:53 2013
 */
/* Compiler settings for FruitReco.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

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

MIDL_DEFINE_GUID(IID, LIBID_FruitRecoLib,0xD5868B35,0xD358,0x4158,0xB5,0xC0,0x1C,0x20,0xE8,0x3A,0xB2,0xD9);


MIDL_DEFINE_GUID(IID, DIID__DFruitReco,0x8F8F657E,0x6647,0x477D,0xAC,0xEF,0x75,0xB3,0x76,0xE3,0x1E,0x7A);


MIDL_DEFINE_GUID(IID, DIID__DFruitRecoEvents,0x0A059C64,0x4679,0x4EDF,0x80,0x01,0xF9,0x76,0x7C,0xD5,0xF9,0xC9);


MIDL_DEFINE_GUID(CLSID, CLSID_FruitReco,0xE9E8D6E8,0xABFF,0x483A,0xA7,0xFD,0xBF,0x98,0x05,0x9B,0x25,0x13);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif




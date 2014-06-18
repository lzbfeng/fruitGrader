

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __FruitRecoidl_h__
#define __FruitRecoidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DFruitReco_FWD_DEFINED__
#define ___DFruitReco_FWD_DEFINED__
typedef interface _DFruitReco _DFruitReco;
#endif 	/* ___DFruitReco_FWD_DEFINED__ */


#ifndef ___DFruitRecoEvents_FWD_DEFINED__
#define ___DFruitRecoEvents_FWD_DEFINED__
typedef interface _DFruitRecoEvents _DFruitRecoEvents;
#endif 	/* ___DFruitRecoEvents_FWD_DEFINED__ */


#ifndef __FruitReco_FWD_DEFINED__
#define __FruitReco_FWD_DEFINED__

#ifdef __cplusplus
typedef class FruitReco FruitReco;
#else
typedef struct FruitReco FruitReco;
#endif /* __cplusplus */

#endif 	/* __FruitReco_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __FruitRecoLib_LIBRARY_DEFINED__
#define __FruitRecoLib_LIBRARY_DEFINED__

/* library FruitRecoLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_FruitRecoLib;

#ifndef ___DFruitReco_DISPINTERFACE_DEFINED__
#define ___DFruitReco_DISPINTERFACE_DEFINED__

/* dispinterface _DFruitReco */
/* [uuid] */ 


EXTERN_C const IID DIID__DFruitReco;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("8F8F657E-6647-477D-ACEF-75B376E31E7A")
    _DFruitReco : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DFruitRecoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DFruitReco * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DFruitReco * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DFruitReco * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DFruitReco * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DFruitReco * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DFruitReco * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DFruitReco * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DFruitRecoVtbl;

    interface _DFruitReco
    {
        CONST_VTBL struct _DFruitRecoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DFruitReco_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DFruitReco_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DFruitReco_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DFruitReco_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DFruitReco_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DFruitReco_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DFruitReco_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DFruitReco_DISPINTERFACE_DEFINED__ */


#ifndef ___DFruitRecoEvents_DISPINTERFACE_DEFINED__
#define ___DFruitRecoEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DFruitRecoEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DFruitRecoEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("0A059C64-4679-4EDF-8001-F9767CD5F9C9")
    _DFruitRecoEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DFruitRecoEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DFruitRecoEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DFruitRecoEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DFruitRecoEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DFruitRecoEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DFruitRecoEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DFruitRecoEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DFruitRecoEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DFruitRecoEventsVtbl;

    interface _DFruitRecoEvents
    {
        CONST_VTBL struct _DFruitRecoEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DFruitRecoEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DFruitRecoEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DFruitRecoEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DFruitRecoEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DFruitRecoEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DFruitRecoEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DFruitRecoEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DFruitRecoEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_FruitReco;

#ifdef __cplusplus

class DECLSPEC_UUID("E9E8D6E8-ABFF-483A-A7FD-BF98059B2513")
FruitReco;
#endif
#endif /* __FruitRecoLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



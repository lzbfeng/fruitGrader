// FruitReco.cpp : CFruitRecoApp 和 DLL 注册的实现。

#include "stdafx.h"
#include "FruitReco.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CFruitRecoApp theApp;

const GUID CDECL _tlid = { 0xD5868B35, 0xD358, 0x4158, { 0xB5, 0xC0, 0x1C, 0x20, 0xE8, 0x3A, 0xB2, 0xD9 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CFruitRecoApp::InitInstance - DLL 初始化

BOOL CFruitRecoApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: 在此添加您自己的模块初始化代码。
	}

	return bInit;
}



// CFruitRecoApp::ExitInstance - DLL 终止

int CFruitRecoApp::ExitInstance()
{
	// TODO: 在此添加您自己的模块终止代码。

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 将项添加到系统注册表

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 将项从系统注册表中移除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}

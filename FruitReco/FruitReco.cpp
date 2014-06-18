// FruitReco.cpp : CFruitRecoApp �� DLL ע���ʵ�֡�

#include "stdafx.h"
#include "FruitReco.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CFruitRecoApp theApp;

const GUID CDECL _tlid = { 0xD5868B35, 0xD358, 0x4158, { 0xB5, 0xC0, 0x1C, 0x20, 0xE8, 0x3A, 0xB2, 0xD9 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CFruitRecoApp::InitInstance - DLL ��ʼ��

BOOL CFruitRecoApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: �ڴ�������Լ���ģ���ʼ�����롣
	}

	return bInit;
}



// CFruitRecoApp::ExitInstance - DLL ��ֹ

int CFruitRecoApp::ExitInstance()
{
	// TODO: �ڴ�������Լ���ģ����ֹ���롣

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - ������ӵ�ϵͳע���

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - �����ϵͳע������Ƴ�

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}

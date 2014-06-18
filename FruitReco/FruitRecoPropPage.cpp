// FruitRecoPropPage.cpp : CFruitRecoPropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "FruitReco.h"
#include "FruitRecoPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CFruitRecoPropPage, COlePropertyPage)



// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CFruitRecoPropPage, COlePropertyPage)
END_MESSAGE_MAP()



// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CFruitRecoPropPage, "FRUITRECO.FruitRecoPropPage.1",
	0x92257a76, 0xdd21, 0x40a9, 0x8e, 0x5d, 0x78, 0xc9, 0x6f, 0xbe, 0x1, 0x60)



// CFruitRecoPropPage::CFruitRecoPropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� CFruitRecoPropPage ��ϵͳע�����

BOOL CFruitRecoPropPage::CFruitRecoPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_FRUITRECO_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CFruitRecoPropPage::CFruitRecoPropPage - ���캯��

CFruitRecoPropPage::CFruitRecoPropPage() :
	COlePropertyPage(IDD, IDS_FRUITRECO_PPG_CAPTION)
{
}



// CFruitRecoPropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CFruitRecoPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CFruitRecoPropPage ��Ϣ�������

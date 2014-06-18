// FruitRecoPropPage.cpp : CFruitRecoPropPage 属性页类的实现。

#include "stdafx.h"
#include "FruitReco.h"
#include "FruitRecoPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CFruitRecoPropPage, COlePropertyPage)



// 消息映射

BEGIN_MESSAGE_MAP(CFruitRecoPropPage, COlePropertyPage)
END_MESSAGE_MAP()



// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CFruitRecoPropPage, "FRUITRECO.FruitRecoPropPage.1",
	0x92257a76, 0xdd21, 0x40a9, 0x8e, 0x5d, 0x78, 0xc9, 0x6f, 0xbe, 0x1, 0x60)



// CFruitRecoPropPage::CFruitRecoPropPageFactory::UpdateRegistry -
// 添加或移除 CFruitRecoPropPage 的系统注册表项

BOOL CFruitRecoPropPage::CFruitRecoPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_FRUITRECO_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CFruitRecoPropPage::CFruitRecoPropPage - 构造函数

CFruitRecoPropPage::CFruitRecoPropPage() :
	COlePropertyPage(IDD, IDS_FRUITRECO_PPG_CAPTION)
{
}



// CFruitRecoPropPage::DoDataExchange - 在页和属性间移动数据

void CFruitRecoPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CFruitRecoPropPage 消息处理程序

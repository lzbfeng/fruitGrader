#pragma once

// FruitRecoPropPage.h : CFruitRecoPropPage 属性页类的声明。


// CFruitRecoPropPage : 有关实现的信息，请参阅 FruitRecoPropPage.cpp。
//全局结构体


class CFruitRecoPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CFruitRecoPropPage)
	DECLARE_OLECREATE_EX(CFruitRecoPropPage)

// 构造函数
public:
	CFruitRecoPropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_FRUITRECO };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};


#pragma once

// FruitRecoPropPage.h : CFruitRecoPropPage ����ҳ���������


// CFruitRecoPropPage : �й�ʵ�ֵ���Ϣ������� FruitRecoPropPage.cpp��
//ȫ�ֽṹ��


class CFruitRecoPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CFruitRecoPropPage)
	DECLARE_OLECREATE_EX(CFruitRecoPropPage)

// ���캯��
public:
	CFruitRecoPropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_FRUITRECO };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};


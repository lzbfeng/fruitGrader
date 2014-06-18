#pragma once
#include <cxcore.h>
#include <cv.h>
#include <highgui.h>
#include "CvvImage.h"
#include "touFile.h"
// FruitRecoCtrl.h : CFruitRecoCtrl ActiveX �ؼ����������


// CFruitRecoCtrl : �й�ʵ�ֵ���Ϣ������� FruitRecoCtrl.cpp��
// #define  WENLINUM 8				//ͼ�����������ĸ���
// typedef struct juzheng
// {
// 	int B;
// 	int G;
// 	int R;
// 	float AREA;
// 	double wenli[WENLINUM];	
// }JUZHENG;
typedef struct FRUIT
{
	int IndexOfFruit;
	CString TypeOfFruit;
}FRUIT;
#define WM_TRAINED 0X9876
typedef CArray<FRUIT,FRUIT&> CArrayFruit;
class CFruitRecoCtrl : public COleControl
{
	DECLARE_DYNCREATE(CFruitRecoCtrl)

// ���캯��
public:
	CFruitRecoCtrl();

// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ʵ��
protected:
	~CFruitRecoCtrl();

	DECLARE_OLECREATE_EX(CFruitRecoCtrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CFruitRecoCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CFruitRecoCtrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CFruitRecoCtrl)		// �������ƺ�����״̬

// ��Ϣӳ��
	DECLARE_MESSAGE_MAP()

// ����ӳ��
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// �¼�ӳ��
	DECLARE_EVENT_MAP()

// ���Ⱥ��¼� ID
public:
	enum {
		dispidRecognizeFruit = 6L,
		//dispidRecognize = 5L,
		dispidOpenCamera = 4L,
		dispidInit = 3L,
		dispidTrainFruit = 2L,
		dispidCreateBG = 1L
	};
protected:
	void CreateBG(LPCTSTR path_saveBG);
	void TrainFruit(LPCTSTR name_fruit, SHORT index_fruit, LPCTSTR path_fruit);
	void Init(void);
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
public:
	CvCapture * capture;				//ץȡ��Ƶ
	IplImage* frame;					//ÿһ֡ͼ��ı���
	IplImage* fruit;
	IplImage* bg;
	CvvImage m_cvvImage;
	HDC m_pPicCtlHdc;
	CRect m_pPicCtlRect;
	CDC* m_dc;
	bool flag_OpenCamera;				//������ͷ�ı�ʾ
	CString m_pathBG;
	CString m_iniPath;
	CString m_pathFeatures;
	CArrayFruit m_listFruit;
protected:
	void OpenCamera(void);
private:
	void SaveFeatures(IplImage* img,LPCTSTR name_fruit, SHORT index_fruit, LPCTSTR path_fruit);
	void Write(JUZHENG*jz,char filenameWrite[],int index_fruit);
	CString GetTypeOfFruit(IplImage* img,int & index_fruit,CString path_fruits);
protected:
	//BSTR Recognize(void);
	BSTR RecognizeFruit(LPCTSTR path_fruits);
public:
	afx_msg void OnDestroy();
};


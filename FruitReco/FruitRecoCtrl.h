#pragma once
#include <cxcore.h>
#include <cv.h>
#include <highgui.h>
#include "CvvImage.h"
#include "touFile.h"
// FruitRecoCtrl.h : CFruitRecoCtrl ActiveX 控件类的声明。


// CFruitRecoCtrl : 有关实现的信息，请参阅 FruitRecoCtrl.cpp。
// #define  WENLINUM 8				//图像纹理特征的个数
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

// 构造函数
public:
	CFruitRecoCtrl();

// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 实现
protected:
	~CFruitRecoCtrl();

	DECLARE_OLECREATE_EX(CFruitRecoCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CFruitRecoCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CFruitRecoCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CFruitRecoCtrl)		// 类型名称和杂项状态

// 消息映射
	DECLARE_MESSAGE_MAP()

// 调度映射
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// 事件映射
	DECLARE_EVENT_MAP()

// 调度和事件 ID
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
	CvCapture * capture;				//抓取视频
	IplImage* frame;					//每一帧图像的保存
	IplImage* fruit;
	IplImage* bg;
	CvvImage m_cvvImage;
	HDC m_pPicCtlHdc;
	CRect m_pPicCtlRect;
	CDC* m_dc;
	bool flag_OpenCamera;				//打开摄像头的标示
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


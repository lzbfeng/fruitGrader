// FruitRecoCtrl.cpp : CFruitRecoCtrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "FruitReco.h"
#include "FruitRecoCtrl.h"
#include "FruitRecoPropPage.h"
#include "afxdialogex.h"
#include "touFile.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CFruitRecoCtrl, COleControl)



// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CFruitRecoCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_TIMER()
	ON_WM_DESTROY()
END_MESSAGE_MAP()



// ����ӳ��

BEGIN_DISPATCH_MAP(CFruitRecoCtrl, COleControl)
	DISP_FUNCTION_ID(CFruitRecoCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CFruitRecoCtrl, "CreateBG", dispidCreateBG, CreateBG, VT_EMPTY, VTS_BSTR)
	DISP_FUNCTION_ID(CFruitRecoCtrl, "TrainFruit", dispidTrainFruit, TrainFruit, VT_EMPTY, VTS_BSTR VTS_I2 VTS_BSTR)
	DISP_FUNCTION_ID(CFruitRecoCtrl, "Init", dispidInit, Init, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CFruitRecoCtrl, "OpenCamera", dispidOpenCamera, OpenCamera, VT_EMPTY, VTS_NONE)
	//DISP_FUNCTION_ID(CFruitRecoCtrl, "Recognize", dispidRecognize, Recognize, VT_BSTR, VTS_NONE)
	DISP_FUNCTION_ID(CFruitRecoCtrl, "RecognizeFruit", dispidRecognizeFruit, RecognizeFruit, VT_BSTR, VTS_BSTR)
END_DISPATCH_MAP()



// �¼�ӳ��

BEGIN_EVENT_MAP(CFruitRecoCtrl, COleControl)
END_EVENT_MAP()



// ����ҳ

// TODO: ����Ҫ��Ӹ�������ҳ�����ס���Ӽ���!
BEGIN_PROPPAGEIDS(CFruitRecoCtrl, 1)
	PROPPAGEID(CFruitRecoPropPage::guid)
END_PROPPAGEIDS(CFruitRecoCtrl)



// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CFruitRecoCtrl, "FRUITRECO.FruitRecoCtrl.1",
	0xe9e8d6e8, 0xabff, 0x483a, 0xa7, 0xfd, 0xbf, 0x98, 0x5, 0x9b, 0x25, 0x13)



// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CFruitRecoCtrl, _tlid, _wVerMajor, _wVerMinor)



// �ӿ� ID

const IID IID_DFruitReco = { 0x8F8F657E, 0x6647, 0x477D, { 0xAC, 0xEF, 0x75, 0xB3, 0x76, 0xE3, 0x1E, 0x7A } };
const IID IID_DFruitRecoEvents = { 0xA059C64, 0x4679, 0x4EDF, { 0x80, 0x1, 0xF9, 0x76, 0x7C, 0xD5, 0xF9, 0xC9 } };


// �ؼ�������Ϣ

static const DWORD _dwFruitRecoOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CFruitRecoCtrl, IDS_FRUITRECO, _dwFruitRecoOleMisc)



// CFruitRecoCtrl::CFruitRecoCtrlFactory::UpdateRegistry -
// ��ӻ��Ƴ� CFruitRecoCtrl ��ϵͳע�����

BOOL CFruitRecoCtrl::CFruitRecoCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: ��֤���Ŀؼ��Ƿ���ϵ�Ԫģ���̴߳������
	// �йظ�����Ϣ����ο� MFC ����˵�� 64��
	// ������Ŀؼ������ϵ�Ԫģ�͹�����
	// �����޸����´��룬��������������
	// afxRegApartmentThreading ��Ϊ 0��

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_FRUITRECO,
			IDB_FRUITRECO,
			afxRegApartmentThreading,
			_dwFruitRecoOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}



// CFruitRecoCtrl::CFruitRecoCtrl - ���캯��

CFruitRecoCtrl::CFruitRecoCtrl()
{
	InitializeIIDs(&IID_DFruitReco, &IID_DFruitRecoEvents);
	// TODO: �ڴ˳�ʼ���ؼ���ʵ�����ݡ�
	flag_OpenCamera=false;
	m_pPicCtlHdc=NULL;
	m_dc=NULL;
	bg=NULL;
	frame=NULL;
}



// CFruitRecoCtrl::~CFruitRecoCtrl - ��������

CFruitRecoCtrl::~CFruitRecoCtrl()
{
	// TODO: �ڴ�����ؼ���ʵ�����ݡ�
}



// CFruitRecoCtrl::OnDraw - ��ͼ����

void CFruitRecoCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	// TODO: �����Լ��Ļ�ͼ�����滻����Ĵ��롣
	//pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	if (m_dc==NULL)
	{
		m_dc=(CDC*)GetDC();
	}
	if (m_pPicCtlHdc==NULL)
	{
		m_pPicCtlHdc=m_dc->GetSafeHdc();
	}

	CRect rect;

	GetClientRect(&m_pPicCtlRect);

	if (flag_OpenCamera)
	{
		if (frame!=NULL)
		{
			m_cvvImage.CopyOf(frame);
			m_cvvImage.DrawToHDC(m_pPicCtlHdc,m_pPicCtlRect);
		}
		
	}
}



// CFruitRecoCtrl::DoPropExchange - �־���֧��

void CFruitRecoCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Ϊÿ���־õ��Զ������Ե��� PX_ ������
}



// CFruitRecoCtrl::OnResetState - ���ؼ�����ΪĬ��״̬

void CFruitRecoCtrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO: �ڴ��������������ؼ�״̬��
}



// CFruitRecoCtrl::AboutBox - ���û���ʾ�����ڡ���

void CFruitRecoCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_FRUITRECO);
	dlgAbout.DoModal();
}



// CFruitRecoCtrl ��Ϣ�������


void CFruitRecoCtrl::CreateBG(LPCTSTR path_saveBG)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	if (m_dc==NULL)
	{
		m_dc=(CClientDC*)GetDC();
	}
	if (m_pPicCtlHdc==NULL)
	{
		m_pPicCtlHdc=m_dc->GetSafeHdc();
	}
	if (flag_OpenCamera)
	{
		KillTimer(1);	
		m_cvvImage.CopyOf(frame);
		m_cvvImage.DrawToHDC(m_pPicCtlHdc,m_pPicCtlRect);
		cvSaveImage(m_pathBG,frame);
		//m_pathBG=path_saveBG;
		SetTimer(1,40,NULL);
	}
	else
	{
		MessageBox("�������ͷ��");
		return;
	}	
	
}
CString CFruitRecoCtrl::GetTypeOfFruit(IplImage* img,int & index_fruit,CString path_fruits)
{
	cvSmooth(img,img,CV_GAUSSIAN,9,9);
	cvErode(img,img);

	fruit=cvCloneImage(img);
	IplImage*gray=cvCreateImage(cvGetSize(img),8,1);
	if (bg==NULL)
	{
		bg=cvLoadImage(m_pathBG);
	}	
	cvSub(img,bg,img);
	cvCvtColor(img,gray,CV_BGR2GRAY);
	cvThreshold(gray,gray,20,255,CV_THRESH_BINARY);
	cvErode(gray,gray);
	cvDilate(gray,gray);
	cvWaitKey(1);
	cvZero(img);
	cvCopy(fruit,img,gray);
// 	cvShowImage("img",img);
// 	cvShowImage("dst",gray);
	JUZHENG JZ;
	JZ.AREA=float(cvCountNonZero(gray));
	JZ.B=int(cvSum(img).val[0]/JZ.AREA);
	JZ.G=int(cvSum(img).val[1]/JZ.AREA);
	JZ.R=int(cvSum(img).val[2]/JZ.AREA);

	/*GetWenLi(img,&JZ);*/
	/*Write(&JZ,filenameWrite);*/
	cvReleaseImage(&gray);
	return KFengLeiQ(&JZ,path_fruits.GetBuffer(path_fruits.GetLength()),index_fruit);

}
void CFruitRecoCtrl::SaveFeatures(IplImage* img,LPCTSTR name_fruit, SHORT index_fruit, LPCTSTR path_fruit)
{
	cvSmooth(img,img,CV_GAUSSIAN,9,9);
	cvErode(img,img);
	if (bg==NULL)
	{
		bg=cvLoadImage(m_pathBG);
	}	
	fruit=cvCloneImage(img);
	IplImage*gray=cvCreateImage(cvGetSize(img),8,1);
	cvSub(img,bg,img);
	cvCvtColor(img,gray,CV_BGR2GRAY);
	cvThreshold(gray,gray,20,255,CV_THRESH_BINARY);
	cvErode(gray,gray);
	cvDilate(gray,gray);
	cvWaitKey(1);
	cvZero(img);
	cvCopy(fruit,img,gray);
// 	cvShowImage("img",img);
// 	cvShowImage("dst",gray);
	JUZHENG JZ;
	JZ.AREA=float(cvCountNonZero(gray));
	JZ.B=int(cvSum(img).val[0]/JZ.AREA);
	JZ.G=int(cvSum(img).val[1]/JZ.AREA);
	JZ.R=int(cvSum(img).val[2]/JZ.AREA);

	/*GetWenLi(img,&JZ);*/
	CString str_path=path_fruit;
	char* path=str_path.GetBuffer(str_path.GetLength());
	Write(&JZ,path,index_fruit);
	cvReleaseImage(&gray);
}


void CFruitRecoCtrl::Write(JUZHENG*jz,char filenameWrite[],int index_fruit)
{
	FILE *fp;
	fp=fopen(filenameWrite,"at");
	char a[100];
	memset(a,'\0',100);
	sprintf(a,"%d ",index_fruit);
	char b[100];
	memset(b,'\0',100);
	sprintf(b,"%f %d %d %d ",jz->AREA,jz->B,jz->G,jz->R);

	char dataWrite[100];
	memset(dataWrite,'\0',100);
	strcat(dataWrite,a);
	strcat(dataWrite,b);
	fprintf(fp,"%s",dataWrite);
	fprintf(fp,"\n");
	fclose(fp);
}


void CFruitRecoCtrl::TrainFruit(LPCTSTR name_fruit, SHORT index_fruit, LPCTSTR path_fruit)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	if (m_dc==NULL)
	{
		m_dc=(CClientDC*)GetDC();
	}
	if (m_pPicCtlHdc==NULL)
	{
		m_pPicCtlHdc=m_dc->GetSafeHdc();
	}
	CRect ROI;
	if (flag_OpenCamera)
	{
		KillTimer(1);	
		frame = cvRetrieveFrame(capture,-1);
		m_cvvImage.CopyOf(frame);
		m_cvvImage.DrawToHDC(m_pPicCtlHdc,m_pPicCtlRect);
		SaveFeatures(frame,name_fruit,index_fruit,m_pathFeatures);
		SetTimer(1,40,NULL);
		HWND HSRobot_hWnd=::FindWindow(NULL,"ˮ��ʶ���");
		::PostMessageA(HSRobot_hWnd,WM_TRAINED,NULL,NULL);		
	}
	else
	{
		MessageBox("�������ͷ��");
		return;
	}
}
char* ReadIni(CString a,CString b,CString def,char*buf,CString iniPath)
{
	CString order;	
	//char buf[100];
	memset(buf,'\0',100);
	GetPrivateProfileString(a,b,def,buf,100,iniPath);
	return buf;
}
void CFruitRecoCtrl::Init(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	//if (AmbientUserMode())
	{
		//SetTimer(1,40,NULL);
		m_iniPath="C:\\Users\\LiZhibo\\Desktop\\ˮ������\\project\\Config.ini";
		CString def="def";
		char buf[100];
		ReadIni("FRUITS","nCounts",def,buf,m_iniPath);
		int counts=atoi(buf);
		for (int i=0;i<counts;i++)
		{
			FRUIT fruit;
			
			char a[100];
			char b[100];
			memset(a,'\0',100);
			memset(b,'\0',100);
			strcat(a,"IndexOfFruit");
			sprintf(b,"%d",i+1);
			strcat(a,b);
			//GetPrivateProfileString("FRUITS",a,def,buf,100,m_iniPath);
			ReadIni("FRUITS",a,def,buf,m_iniPath);
			fruit.IndexOfFruit=atoi(buf);

			char aa[100];
			char bb[100];
			memset(aa,'\0',100);
			memset(bb,'\0',100);
			strcat(aa,"TypeOfFruit");
			sprintf(bb,"%d",i+1);
			strcat(aa,bb);
			//GetPrivateProfileString("FRUITS",aa,def,buf,100,m_iniPath);
			ReadIni("FRUITS",aa,def,buf,m_iniPath);
			fruit.TypeOfFruit=buf;
			m_listFruit.Add(fruit);			
		}

		ReadIni("FRUITSET","PathBG",def,buf,m_iniPath);
		m_pathBG=buf;
		ReadIni("FRUITSET","PathFeaturesOfFruits",def,buf,m_iniPath);
		m_pathFeatures=buf;
		GetClientRect(&m_pPicCtlRect);
	}
}


void CFruitRecoCtrl::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	COleControl::OnTimer(nIDEvent);
	if (capture)
	{
		{
			if( !cvGrabFrame( capture ))
				return;

			frame = cvRetrieveFrame(capture,-1);

			if( frame )
			{
				flag_OpenCamera=true;
				Invalidate();
				//SendMessage(WM_SHOWIMAGE);
			}
			else
				return;
		}
	}
}


void CFruitRecoCtrl::OpenCamera(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	CString video_str;

	if(!(capture=cvCaptureFromCAM(0)))
	{
		MessageBox("�ðɣ�δ������������ͷ%>_<%������");
		return;
	}	
	flag_OpenCamera=TRUE;
	SetTimer(1,40,NULL);
}


// BSTR CFruitRecoCtrl::Recognize(void)
// {
// 	AFX_MANAGE_STATE(AfxGetStaticModuleState());
// 
// 	CString strResult;
// 
// 	// TODO: �ڴ���ӵ��ȴ���������
// 	
// 	return strResult.AllocSysString();
// }


BSTR CFruitRecoCtrl::RecognizeFruit(LPCTSTR path_fruits)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: �ڴ���ӵ��ȴ���������
	int index_fruit=-1;
	if (m_dc==NULL)
	{
		m_dc=(CClientDC*)GetDC();
	}
	if (m_pPicCtlHdc==NULL)
	{
		m_pPicCtlHdc=m_dc->GetSafeHdc();
	}
	CRect ROI;
	if (flag_OpenCamera)
	{
		KillTimer(1);	
		m_cvvImage.CopyOf(frame);
		m_cvvImage.DrawToHDC(m_pPicCtlHdc,m_pPicCtlRect);
		//SaveFeatures(frame,name_fruit,index_fruit,path_fruit);

		GetTypeOfFruit(frame,index_fruit,m_pathFeatures);
		int counts=m_listFruit.GetCount();
		//ASSERT(index_fruit>=1);
		if (index_fruit<1)
		{
			CString str="δ��ʶ��ˮ����";
			SetTimer(1,40,NULL);
			return str.AllocSysString();
		}
		FRUIT recoFruit=m_listFruit[index_fruit-1];
		strResult=recoFruit.TypeOfFruit;
		
		SetTimer(1,40,NULL);
	}
	else
	{
		MessageBox("�������ͷ��");
		return strResult.AllocSysString();
	}
	return strResult.AllocSysString();
}


void CFruitRecoCtrl::OnDestroy()
{
	COleControl::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	if(flag_OpenCamera)
	{
		cvReleaseCapture(&capture);
	}
}

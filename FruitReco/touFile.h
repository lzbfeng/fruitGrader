#pragma once
#include <string.h>
#include "cv.h"
#include "highgui.h"
#include "ctype.h"
#include "stdio.h"
#include <string> 
#include "cv.h"
#include "highgui.h"
#include "stdio.h"
#include "math.h"
#include <iostream>
using namespace std;
#include <fstream>
using namespace std;
#include <opencv2/opencv.hpp>
#include <ml.h>
#include <time.h>
#include "opencv2/highgui/highgui.hpp"
/*#include "types_c.h"*/
#include "cv.h"
#include "highgui.h"
#include "ctype.h"
#include "stdio.h"
#include "stdio.h"
#include "math.h"
#include <iostream>
using namespace std;
#include <fstream>
using namespace std;
#include<iostream> 
using namespace std;
#include <math.h>
#include <fstream>
using namespace std;
//ȫ����
#define  NATTRS 4 //number of attributes
#define  MAXSZ  1700 //max size of training set����ŵ���������
#define  MAXVALUE  10000.0 //the biggest attribute's value is below 10000(int)
#define  K  15 
//ȫ�ֱ���
#define  TIMES 10//ÿ�������ģ��ҵĴ���
#define  MINAREA 10//԰������͵���Сֵ
#define  WENLINUM 8//ͼ�����������ĸ���
#define  minarear 10//ÿһ��԰����С�뾶
#define  SUB	5//����ȡ����ʱ��Ϊ�þ��ο���ֻ�����壬������Ҫ��С
#define  FRUITKINDS	5//ˮ��������
#define  YUANTEZHENGNUMS 2//���ڼ�⵽Բ�ε�����£�֧����������ѡȡ��������
#define  WENJIANGESHU 100//���ڼ�⵽Բ�ε�����£�֧����������ѡȡ���ļ����¼������
				 /***************************
				 ��Ҫ���ĵ�������
					#define  NUMS 3
					void YuanDect(IplImage*img,int minarea,YUANTEZHENG* YTZ)�е�minarear����ʾԲ����С�뾶
				 ***************************/
typedef struct vector 
{
	double attributes[NATTRS];
	double classlabel;
}VECTOR;
typedef struct item
{
	double distance;
	double classlabel;
}ITEM;
//ȫ�ֽṹ��
typedef struct juzheng
{
	int B;
	int G;
	int R;
	float AREA;
	double wenli[WENLINUM];	
}JUZHENG;
IplImage* GetPic(int flag,char filename[256]);
void GetWenLi(IplImage* img,JUZHENG* JZ);
int GetTexturePara(CvMat* paraMatri[4],double *texturePara);
double GetVar(double ar[4]);//����������ķ���
double GetMean(double ar[4]);//����������ľ�ֵ
int GetGLCM(CvMat * ImgMat,double* texturePara);//�ɹ���������ȡ�������������
void juzhengchushihua(JUZHENG*ju);
//void Write(JUZHENG*jz,char filenameWrite[256]);
CString KFengLeiQ(JUZHENG *ju,char filenameRead[],int& index_fruit);
//����д��filenameWrite��
//�������filenameRead��
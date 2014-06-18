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
//全局量
#define  NATTRS 4 //number of attributes
#define  MAXSZ  1700 //max size of training set最多存放的样本矩阵
#define  MAXVALUE  10000.0 //the biggest attribute's value is below 10000(int)
#define  K  15 
//全局变量
#define  TIMES 10//每次找最大的，找的次数
#define  MINAREA 10//园的面积和的最小值
#define  WENLINUM 8//图像纹理特征的个数
#define  minarear 10//每一个园的最小半径
#define  SUB	5//在提取纹理时，为让矩形框内只有物体，长度需要减小
#define  FRUITKINDS	5//水果的种类
#define  YUANTEZHENGNUMS 2//对于检测到圆形的情况下，支持向量机所选取特征个数
#define  WENJIANGESHU 100//对于检测到圆形的情况下，支持向量机所选取的文件类记录的数量
				 /***************************
				 需要更改的物理量
					#define  NUMS 3
					void YuanDect(IplImage*img,int minarea,YUANTEZHENG* YTZ)中的minarear，表示圆的最小半径
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
//全局结构体
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
double GetVar(double ar[4]);//求纹理参数的方差
double GetMean(double ar[4]);//求纹理参数的均值
int GetGLCM(CvMat * ImgMat,double* texturePara);//由共生矩阵提取各个纹理参数，
void juzhengchushihua(JUZHENG*ju);
//void Write(JUZHENG*jz,char filenameWrite[256]);
CString KFengLeiQ(JUZHENG *ju,char filenameRead[],int& index_fruit);
//矩阵写在filenameWrite中
//矩阵读在filenameRead中
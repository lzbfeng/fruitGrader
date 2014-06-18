//说明
/*********************************************************
从文件中读取矩阵,利用最近邻分类器识别方法
收录2种水果，每种水果含有50个样本
每一个样本为4维(NATTRS)矩阵，即特征向量
找最近的距离样本个数为15个(K)
/*********************************************************/
#include "stdafx.h"
#include"touFile.h"
VECTOR trSet[MAXSZ];//global variable,the training set
ITEM knn[K];//global variable,the k-neareast-neighbour set
int curTSize = 0; //current size of the training set
int AddtoTSet(VECTOR v)
{
	if(curTSize>=MAXSZ) {
		cout<<endl<<"The training set has "<<MAXSZ<<" examples!"<<endl<<endl; 
		return 0;
	}
	trSet[curTSize] = v;
	curTSize++;
	return 1;
}
double Distance(VECTOR v1,VECTOR v2)
{
	double d = 0.0;
	double tem = 0.0;
	for(int i = 0;i < NATTRS;i++)
		tem += (v1.attributes[i]-v2.attributes[i])*(v1.attributes[i]-v2.attributes[i]);
	d = sqrt(tem);
	return d;
}
int max(struct item knn[]) //return the no. of the item which has biggest distance(
                           //should be replaced) 
{
	int maxNo = 0;
	if(K > 1)
	for(int i = 1;i < K;i++)
		if(knn[i].distance>knn[maxNo].distance)
			maxNo = i;
    return maxNo;
}

double Classify(VECTOR v)	//decide which class label will be assigned to
                             //a given input vetor with the knn method
{
	double dd = 0;
	int maxn = 0;
	int freq[K];
	double mfreqC = 0;//the class label appears most frequently 
	int i;
	for(i = 0;i < K;i++)
		knn[i].distance = MAXVALUE;
	for(i = 0;i < curTSize;i++)
	{
		dd = Distance(trSet[i],v);
		maxn = max(knn);//for every new state of the training set should update maxn
		if(dd < knn[maxn].distance) {
				knn[maxn].distance = dd;
				knn[maxn].classlabel = trSet[i].classlabel;
            }
	}
	for(i = 0;i < K;i++)//freq[i] represents knn[i].classlabel appears how many times 
		freq[i] = 1;
	for(i = 0;i < K;i++)  
		for(int j = 0;j < K;j++)
			if((i!=j)&&(knn[i].classlabel == knn[j].classlabel))
				freq[i]+=1;
	int mfreq = 1;
	mfreqC = knn[0].classlabel;
	for(i = 0;i < K;i++)
		if(freq[i] > mfreq)  {
			mfreq = freq[i];//mfreq represents the most frepuences
 			mfreqC = knn[i].classlabel; //mfreqNo is the item no. with the most frequent
			                             //classlabel
		}
	return mfreqC;
}
CString KFengLeiQ(JUZHENG *ju,char filenameRead[],int& index_fruit)
{   
	CString fruit_type="";
	VECTOR testv;
	int classlabel;
	double c; 
	double n;
	VECTOR trExmp;	
	int i;
	ifstream filein(filenameRead);
	if(filein.fail()){cout<<"Can't open data.txt"<<endl; return fruit_type;}
	//读数据部分
	while(!filein.eof()) 
	{
		filein>>c;
		trExmp.classlabel = c;
		for(int i = 0;i < NATTRS;i++) 
		{
		filein>>n;
		trExmp.attributes[i] = n;
		/*cout<<trExmp.attributes[i]<<" ";*/
		}

		/*cout<<endl;*/
	 if(!AddtoTSet(trExmp))
		break;
	}

	filein.close();
	//将传入的矩阵元素传入结构体testv
	
	testv.attributes[0]=ju->AREA;
	testv.attributes[1]=ju->B;
	testv.attributes[2]=ju->G;
	testv.attributes[3]=ju->R;

	classlabel = Classify(testv);
	cout<<"The classlable of the testv is:	";
	cout<<classlabel<<endl;
	
	index_fruit=(int)classlabel;
	switch(int(classlabel))
	{
	case 1:fruit_type="优质苹果";break;
	case 2:fruit_type="中等苹果";break;
	case 3:fruit_type="橘子";	break;
	case 4:fruit_type="香蕉";	break;
	case 5:fruit_type="梨子";	break;
	default:break;
	}
	return fruit_type;
}
//Author: Zhuo Su 
//Date: 05/2016
//main function

#include<iostream>
#include<string>
#include<list>
#include "Global.h"
#include "Sample.h"
#include <iomanip> 
#include "Gaussian.h"
#include<math.h>
#include "VJdetector.h"
#include <windows.h> 

int main6()
{
	std::string filepath = "E:\\苏卓\\C++_C#资料\\face detection\\data\\parameters6_11_2_50.vj";
	VJdetector vj;
	//vj.sam = new Sample(2,1000);
	vj.getFeatures();
	vj.loadParameter(filepath);
	int count(0);
	int a = vj.DrawPositives(count);
	std::cout<<a<<std::endl;
	std::cin.get();
	return 0;
}

int main5()
{
	
	std::string filepath = "E:\\苏卓\\C++_C#资料\\face detection\\data\\parameters6_10_7_22.vj";
	VJdetector vj;
	vj.getFeatures();
	vj.loadParameter(filepath);
	int count(0);
	Element ele;
	std::string filespath = "E:\\苏卓\\C++_C#资料\\face detection\\data\\training negatives\\layer5\\";
	//std::string filespath = "E:\\苏卓\\C++_C#资料\\face detection\\data\\face2\\";
	for(int i = 0; i < 1000; i++)
	{
		std::string filepath2 = filespath+std::to_string((long long)i)+".jpg";
		cv::Mat image = cv::imread(filepath2,0);
		int a = image.channels();
		ele.Calc_Integral(image);
		if(vj.cascadeDecision(ele))
			count++;
	}
	std::cout<<count<<std::endl;
	std::cin.get();
	return 0;
}

int main()
{
	std::string filepath = "E:\\苏卓\\C++_C#资料\\face detection\\data\\parameters6_11_18_18.vj";
	VJdetector vj;
	vj.getFeatures();
	vj.loadParameter(filepath);

	OPENFILENAME ofn;     
	TCHAR szFile[MAX_PATH];                    
	ZeroMemory(&ofn, sizeof(OPENFILENAME));    
	ofn.lStructSize = sizeof(OPENFILENAME);    
	ofn.hwndOwner = NULL;    
	ofn.lpstrFile = szFile;    
	ofn.lpstrFile[0] = '\0';   
	ofn.nMaxFile = sizeof(szFile);    
	ofn.lpstrFilter = "Image(*.jpg)\0*.JPG\0*.bmp\0*.jpeg\0.*tif\0\0";    
	ofn.nFilterIndex = 1;    
	ofn.lpstrFileTitle = NULL;    
	ofn.nMaxFileTitle = 0;    
	ofn.lpstrInitialDir = NULL;    
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;          
	if ( GetOpenFileName(&ofn) )    
	{      
		OutputDebugString(szFile);    
		OutputDebugString("\r\n");    
	} 

	cv::Mat image = cv::imread(szFile,0);
	//Element ele;
	//ele.Calc_Integral(image);
	//bool a = vj.cascadeDecision(ele);
	//cv::cvtColor(image,image,CV_RGB2GRAY);
	//int a = image.channels();
	cv::Mat imageout;
	int a = vj.detect(image,imageout);
	cv::namedWindow("image");
	cv::imshow("image",imageout);
	/*cv::namedWindow("resize");
	cv::imshow("resize",image);*/
	cv::waitKey();
	/*std::cout<<a<<std::endl;
	cv::namedWindow("After detection");
	cv::imshow("After detection", image);
	cv::waitKey();*/

	std::cin.get();
	return 0;
}

int main3()
{
	std::string filepath = "C:\\Users\\buaa\\Desktop\\face detection\\parameters4_28_16_51.vj";
	std::ifstream ifile(filepath);
	std::string str1;
	int layer(0);
	int numberOfcls;
	double bias;
	int idx;
	int featureidx;
	std::string strvalue;

	while (!ifile.eof())
	{
		ifile>>str1;
		if(str1=="Layer:") layer++;
		if(str1 == "bias:") 
		{
			ifile>>strvalue;
			bias = std::stod(strvalue);
		}
		else if(str1 == "index:")
		{
			ifile>>strvalue;
			featureidx = std::stoi(strvalue);
		}

	}
	ifile.close();
	std::cin.get();
	return 0;
}

int main2()
{
	//std::string filespath = "E:\\苏卓\\C++_C#资料\\face detection\\data";
	std::string filespath = "D:\\face detection\\data";
	//std::string savepath = "E:\\苏卓\\C++_C#资料\\face detection\\data\\training negatives";
	std::string savepath = "D:\\face detection\\data\\training negatives";
	VJdetector vj(1000,1000,352592,1.5,filespath,savepath);
	double re = vj.train(0.00001,0.35,0.99,12);
	std::cout<<"finish: "<<re<<std::endl;
	std::cin.get();
	return 0;
}

int main1()
{
	//std::string path = "C:\\Users\\buaa\\Desktop\\face detection\\face";
	//cv::Mat image = cv::imread(path+"\\0.jpg");
	//cv::Mat inte_img;
	//Calc_Integral(image,inte_img);//,inte_imgsquare);

	//Sample s(1,1,162336);
	//int c = s.getFeatures();

	/*cv::Mat1f m(4,1);
	for(int i = 0; i<4 ;i++)
	{
	m.at<float>(i,0) = i+1;
	}
	cv::Mat1f mm = cv::Mat1f::zeros(4,4);
	mm = mm + m*m.t()*3;
	std::cout<<mm<<std::endl;*/

	/*double a = log(exp((double)2));
	std::cout<<a<<std::endl;*/
	/*cv::Mat1d m = cv::Mat1d::ones(6,3);
	std::cout<<m<<std::endl;
	m = m.reshape(3);
	std::cout<<std::endl<<m<<std::endl;*/
	/*std::list<int*> a;
	if(a.empty())
	{
		std::cout<<123<<std::endl;
	}*/
	/*a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	for(auto ite = a.begin(); ite!=a.end(); ite++)
	{
	std::cout<<*ite<<std::endl;
	}*/
	//VJdetector vj;
	//vj.firstSetNegatives("C:\\Users\\buaa\\Desktop\\face detection\\non_face");
	/*srand((unsigned)time(NULL));
	int a[20];
	for(int i = 0; i<20; i++)
	{
		a[i] = 4*rand()/RAND_MAX;
	}*/
	//cv::Mat1d m;
	//m = cv::imread("C:\\Users\\buaa\\Desktop\\face detection\\training negatives\\layer0\\0.jpg");
	//std::cout<<std::endl<<std::endl<<std::endl<<m<<std::endl;
	//std::cout<<"finish..."<<std::endl;
	//SYSTEMTIME sys;
	//GetLocalTime(&sys);
	////std::cout<<sys.wDay<<sys.wHour<<std::endl;
	//std::string time = std::to_string((long long)sys.wMonth) + "_" + std::to_string((long long)sys.wDay) + "_" 
	//	+ std::to_string((long long)sys.wHour) + "_" + std::to_string((long long)sys.wMinute);

	//std::string filespath = "C:\\Users\\buaa\\Desktop\\face detection";
	//std::string filename = filespath+"\\parameters"+time+".vj";
	//std::ofstream ofile(filename);
	//if(1)
	//{
	//	ofile<<"no parameters trained."<<std::endl;
	//	ofile.close();
	//}

	/*std::list<ShiftedClassifier*> cascadeLis;
	ShiftedClassifier* shiftlis = new ShiftedClassifier;
	Classifier* cls = new Classifier;
	cls->alpha = 0.1472567787189757;
	cls->er = 0.88629782745894769;
	cls->index = 25;
	cls->polarity = 1;
	cls->vt = 0.6987236478912630923;
	shiftlis->s = 3;
	shiftlis->lis.push_back(cls);
	cascadeLis.push_back(shiftlis);

	SYSTEMTIME sys;
	GetLocalTime(&sys);
	std::string filespath = "C:\\Users\\buaa\\Desktop\\face detection";
	std::string time = std::to_string((long long)sys.wMonth) + "_" + std::to_string((long long)sys.wDay) + "_" 
	+ std::to_string((long long)sys.wHour) + "_" + std::to_string((long long)sys.wMinute);

	std::string filename = filespath+"\\parameters"+time+".vj";
	std::ofstream ofile(filename);
	if(cascadeLis.empty())
	{
	ofile<<"no parameters trained."<<std::endl;
	ofile.close();
	return 0;
	}
	int layer(0);
	for(auto item = cascadeLis.begin(); item != cascadeLis.end(); item++)
	{
	layer++;
	ofile<<"Layer: "<<layer<<std::endl;
	ofile<<"\t"<<"number of Classifier: "<<(*item)->lis.size()<<std::endl;
	ofile<<"\t"<<"bias: "<<std::setprecision(10)<<((*item)->s)<<std::endl;
	int count(0);
	for(auto clsfier = (*item)->lis.begin(); clsfier != (*item)->lis.end(); clsfier++)
	{
	int index;
	double er;
	double vt;
	int polarity;
	double alpha;
	count++;
	ofile<<"\t"<<count<<": "<<std::endl;
	ofile<<"\t\t"<<"feature index: "<<(*clsfier)->index<<std::endl;
	ofile<<"\t\t"<<"error: "<<std::setprecision(10)<<(*clsfier)->er<<std::endl;
	ofile<<"\t\t"<<"threshold: "<<std::setprecision(10)<<(*clsfier)->vt<<std::endl;
	ofile<<"\t\t"<<"polarity: "<<(*clsfier)->polarity<<std::endl;
	ofile<<"\t\t"<<"alpha: "<<std::setprecision(10)<<(*clsfier)->alpha<<std::endl;
	}
	ofile<<std::endl;
	}
	ofile.close();

	int cas_size = cascadeLis.size();
	for(int i = 0; i < cas_size; i++)
	{
	ShiftedClassifier* item = cascadeLis.back();
	cascadeLis.pop_back();
	int s = item->lis.size();
	for(int j = 0; j < s; j++)
	{
	Classifier* cls = item->lis.back();
	item->lis.pop_back();
	delete cls;
	}
	delete item;
	}*/


	/*std::list<int*> lis;
	int* a = new int(3);
	int* b = new int(9);
	lis.push_back(a);
	lis.push_back(b);
	int s = lis.size();
	for(int i = 0; i<s; i++)
	{
	auto aa = lis.back();
	lis.pop_back();
	delete aa;
	}
	*/
	std::cin.get();
	return 0;
}
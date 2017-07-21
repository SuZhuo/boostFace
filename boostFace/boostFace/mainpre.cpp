//Author: Zhuo Su 
//Date: 05/2016
//preprocessing


#include<iostream>
#include<string>
#include<list>
#include<afx.h>
#include<algorithm>
#include "Global.h"

void getfilenames(std::list<std::string>& files,CString& str_filepath)
{
	CString fdpath,filepath;
	filepath = str_filepath+"\\*.*";
	CString strtmp;
	CFileFind find;
	bool bf = find.FindFile(filepath);
	while(bf)
	{
		bf = find.FindNextFileA();
		if(!find.IsDots())
		{
			fdpath = find.GetFilePath();
			if(find.IsDirectory())
			{
				getfilenames(files,fdpath);
			}
			else
			{
				strtmp = fdpath.Right(4);
				strtmp.MakeLower();
				if(".bmp" == strtmp||".tif" == strtmp)
				{
					if("02.tif" == fdpath.Right(6)||"05.tif" == fdpath.Right(6))
						continue;
					files.push_back(fdpath.GetBuffer(0));
				}
			}
		}
	}
	find.Close();

}

void getprejpg(std::string& filepath,cv::Mat& image,bool flag = 0)
{
	int width,height;
	if(flag)
	{	
		width = 24;
		height = 24;
	}
	else
	{
		float scale = (std::max)(320.0/image.cols,240.0/image.rows);
		width = static_cast<int>(image.cols*scale);
		height = static_cast<int>(image.rows*scale);
	}
	//cv::Mat image2 = image(cv::Rect(0,image.rows-image.cols,image.cols,image.cols)).clone();
	//cv::Mat dst = cv::Mat(height,width,CV_8U);
	//cv::resize(image2,dst,cv::Size(width,height));
	cv::imwrite(filepath,image);
}

int mainppp()
{
	CString filepath = "C:\\Users\\buaa\\Desktop\\face detection\\facedetdemo";
	std::string picbasepath = "C:\\Users\\buaa\\Desktop\\face detection\\face2\\";
	std::string picpath;
	int idx(1801);
	std::list<std::string> files;
	getfilenames(files,filepath);
	int a = files.size();
	cv::Mat image;
	std::string filename;
	while(!files.empty())
	{
		filename = files.back();
		files.pop_back();
		try
		{
			image = cv::imread(filename);
			cv::cvtColor(image,image,CV_RGB2GRAY);
			picpath = picbasepath+std::to_string((long long)idx)+".jpg";
			getprejpg(picpath,image,1);
			idx++;
		}
		catch(cv::Exception)
		{
			continue;
		}
	}
	std::cout<<"finish preprocessing"<<std::endl;
	std::cin.get();
	return 0;
}


int mainpre_nonface()
{
	CString filepath = "C:\\Users\\buaa\\Desktop\\face detection\\pictures";
	std::string picbasepath = "C:\\Users\\buaa\\Desktop\\face detection\\non_face\\";
	std::string picpath;
	int idx(0);
	std::list<std::string> files;
	getfilenames(files,filepath);
	cv::Mat image;
	std::string filename;
	while(!files.empty())
	{
		filename = files.back();
		files.pop_back();
		try
		{
			image = cv::imread(filename);
			cv::cvtColor(image,image,CV_RGB2GRAY);
			picpath = picbasepath+std::to_string((long long)idx)+".jpg";
			getprejpg(picpath,image);
			idx++;
		}
		catch(cv::Exception)
		{
			continue;
		}
	}
	std::cout<<"finish preprocessing"<<std::endl;
	std::cin.get();
	return 0;

}


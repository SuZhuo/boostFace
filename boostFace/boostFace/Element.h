//Author: Zhuo Su 
//Date: 05/2016
//single sample

#pragma once
#include<array>
#include"Global.h"

class Element
{
public:
	Element()
		:w(0),probability(0),accumulatedBias(0)
	{
		//inte_image = cv::Mat1d::zeros(D,1);
	}
public:
	double w;
	double probability;
	double accumulatedBias;
	cv::Mat1d inte_image;
public:
	int Calc_Integral(cv::Mat& image);
};

class Positive : public Element{};
//{
//public:
//	Positive():Element(){}
//};

class Negative : public Element{};
//{
//public:
//	Negative():Element(){}
//};
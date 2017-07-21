/////初稿，完成于2016年4月27日23:53
//Author: Zhuo Su 
//Date: 05/2016
//core file

#pragma once

#include<iostream>
#include <iomanip> 
#include<string>
#include<list>
#include<math.h>
#include<time.h>
#include <direct.h>
#include<fstream>
#include <windows.h> 
#include "Element.h"
#include "Sample.h"
#include "Classifier.h"
#include "Feature.h"

struct ShiftedClassifier
{
	ShiftedClassifier():s(0),FPR(0),DETR(0){}
	std::list<Classifier*> lis;
	double FPR;
	double DETR;
	double s;
};

class VJdetector
{
public:
	//constructor for detection
	VJdetector(double step = 1.5):NF(352592),scale_step(step)
	{
		sam = nullptr;
		pf = new feature[NF];
	}


	//constructor for training 
	VJdetector(int np, int nn, int nf, double step, std::string infilespath, std::string insavepath)
		:NF(nf),have_feature(false),scale_step(step),filespath(infilespath),savepath(insavepath)
	{
		sam = new Sample(np,nn);
		pf = new feature[nf];
	}
	~VJdetector()
	{
		delete [] pf;
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
		}
		if(sam!=nullptr)
			delete sam;
	}
public:
	std::list<ShiftedClassifier*> cascadeLis;
	int NF;//number of features
	Sample* sam;
	pfeature pf;
private:
	double TRAINING_FPR;
	double TRAINING_DETR;
	std::string filespath;
	std::string savepath;
	bool have_feature;
	double scale_step;

public:
	int getFeatures();
	bool giveFeatures();
	int findBestStump(Classifier* clsfier);
	int calculateEr(Sample* sam, Classifier* clsfier);
	int adaBoost(std::list<Classifier*>& lis, int T, bool start_from_scratch);
	double attentionalCascade(double alpha_all, double alpha_layer, double beta_layer, int numberOfLayer);
	bool layerDecision(Element& ele, const std::list<Classifier*>& lis, bool makeDecisionFromStart, double bias = 0.01);
	bool layerDecision2(Element& ele, const std::list<Classifier*>& lis, double bias = 0);
	int calculateFPR_and_DETR(const std::list<Classifier*>& lis, double& FPR, double& DETR,
								bool makeDecisionFromStart,double biasRate);
	int DrawNegatives(int layer = 1);
	int DrawNegatives_over(int layer);
	int getBaseNumberOfFeaturesInLayer(int layer);
	int getNumberStepOfFeaturesInLayer(int layer);
	int getNumberOfNegatives(int layer);
	bool cascadeDecision(Element& ele);
	int DrawPositives(int& index);
	double train(double alpha_all, double alpha_layer, double beta_layer, int numberOfLayer);
	int saveToFile(bool succ = 1);
	int loadParameter(std::string path);
	int detect(cv::Mat& image, cv::Mat& imageout);

};
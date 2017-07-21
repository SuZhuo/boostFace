//Author: Zhuo Su 
//Date: 05/2016
//weak classifer

#pragma once
#include<array>
#include "Element.h"
#include "Feature.h"
#include "Global.h"
#include "Gaussian.h"

struct Classifier
{
	int index;
	double er;
	double vt;
	int polarity;
	double alpha;
	static void mult(cv::Mat1d& m, std::array<Position,16>& G, double& value);
	static void findStump(const double& p_p, const double& u_p, const double& sig_p, 
		const double& p_n, const double& u_n, const double& sig_n, 
		double& vt, double& er, int& polarity);
	int makeDecision(Element& ele, pfeature& pf);
};
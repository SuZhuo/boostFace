//Author: Zhuo Su 
//Date: 05/2016
//Samples

#pragma once
#include "Element.h"
#include "Classifier.h"
#include "Feature.h"

class Sample
{
public:
	Sample(int np, int nn):NP(np),NN(nn),has_feature(false)
	{
		pPos = new Positive[NP+500];
		pNeg = new Negative[NN];
		pf = nullptr;
	}
	~Sample()
	{
		delete [] pPos;
		delete [] pNeg;
		pf = nullptr;
	}
public:
	int NP;//number of positives
	int NN;//number of negatives
	Positive* pPos;
	Negative* pNeg;
	pfeature pf;

private:
	bool has_feature;

public:
	void setFeatureFlag();
	void resetW();
	int updateW(Classifier* clsfier);
};
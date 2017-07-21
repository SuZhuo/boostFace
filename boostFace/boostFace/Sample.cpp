
#include "Sample.h"
#include<math.h>

void Sample::setFeatureFlag()
{
	has_feature = true;
}

int Sample::updateW(Classifier* clsfier)
{
	int i;
	double zt(0);
	for(i = 0; i < NP; i++)
	{
		if(clsfier->makeDecision(pPos[i],pf) > 0)
		{
			zt += pPos[i].w * sqrt(clsfier->er/(1-clsfier->er));
		}
		else
		{
			zt += pPos[i].w * sqrt((1-clsfier->er)/clsfier->er);
		}	
	}

	for(i = 0; i < NN; i++)
	{
		if(clsfier->makeDecision(pNeg[i],pf) > 0)
		{
			zt += pNeg[i].w * sqrt((1-clsfier->er)/clsfier->er);
		}
		else
		{
			zt += pNeg[i].w * sqrt(clsfier->er/(1-clsfier->er));
		}
	}

	for(i = 0; i < NP; i++)
	{
		if(clsfier->makeDecision(pPos[i],pf) > 0)
		{
			//pPos[i].w = pPos[i].w/2/(1-clsfier->er);
			//pPos[i].w = pPos[i].w/2/(clsfier->er);
			pPos[i].w *= sqrt(clsfier->er/(1-clsfier->er))/zt;
		}
		else
		{
			//pPos[i].w = pPos[i].w/2/(clsfier->er);
			//pPos[i].w = pPos[i].w/2/(1-clsfier->er);
			pPos[i].w *= sqrt((1-clsfier->er)/clsfier->er)/zt;
		}	
	}

	for(i = 0; i < NN; i++)
	{
		if(clsfier->makeDecision(pNeg[i],pf) > 0)
		{
			//pNeg[i].w = pNeg[i].w/2/(clsfier->er);
			//pNeg[i].w = pNeg[i].w/2/(1-clsfier->er);
			pNeg[i].w *= sqrt((1-clsfier->er)/clsfier->er)/zt;
		}
		else
		{
			//pNeg[i].w = pNeg[i].w/2/(1-clsfier->er);
			//pNeg[i].w = pNeg[i].w/2/(clsfier->er);
			pNeg[i].w *= sqrt(clsfier->er/(1-clsfier->er))/zt;
		}
	}

	return 0;
}

void Sample::resetW()
{
	int i;
	for(i = 0; i < NP; i++)
	{
		pPos[i].w = 1.0/2/((double)NP);
	}
	for(i = 0; i < NN; i++)
	{
		pNeg[i].w = 1.0/2/((double)NN);
	}
}
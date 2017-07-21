#include "Feature.h"
#include "Global.h"

void feature::getPosition(const int& i,const int& j,const int& pola,feature*& pf,int& count,int& g_count)
{
	if(i < 0 || j < 0)
		return ;
	else
	{	
		pf[count].G[g_count].pol = pola;
		pf[count].G[g_count].idx = i*DIM + j;
		g_count++;
	}
}
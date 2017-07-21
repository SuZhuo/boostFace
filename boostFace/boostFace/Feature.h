//Author: Zhuo Su 
//Date: 05/2016
//feature

#pragma once
#include<array>

struct Position
{
	Position():idx(-1),pol(0){}
	int idx;
	int pol;
};

typedef struct feature
{
	feature()//:er(2),vt(0)
	{G.fill(Position());}
	char tp;
	/*double er;
	double vt;
	int polarity;*/
	std::array<Position,16> G;
public:
	static void getPosition(const int& i,const int& j,const int& pola,feature*& pf,int& count,int& g_count);
} *pfeature;
#include "Classifier.h"

inline void Classifier::mult(cv::Mat1d& m, std::array<Position,16>& G, double& value)
{
	int i,j;
	value = 0;
	if(1 == m.cols)
	{
		for(i = 0; i < 16; i++)
		{
			if(G[i].idx >= 0)
			{
				value += (G[i].pol)*(m.at<double>(G[i].idx,0));
			}
			else
			{
				break;
			}
		}
	}

	else
	{
		double* v = new double[16];
		memset(v,0,16*sizeof(double));
		for(i = 0; i < 16; i++)
		{
			if(G[i].idx >= 0)
			{
				for(j = 0; j < 16; j++)
				{
					if(G[j].idx >= 0)
					{
						v[i] += (m.at<double>(G[j].idx ,G[i].idx))*(G[j].pol);
					}
					else
					{
						break;
					}
				}
				value += v[i]*(G[i].pol);			
			}
			else
			{
				break;
			}
		}
		delete [] v;
	}
}

void Classifier::findStump(const double& p_p, const double& u_p, const double& sig_p, 
	const double& p_n, const double& u_n, const double& sig_n, 
	double& vt, double& er, int& polarity)
{
	double e;
	//polarity = 1. value>threshold : positive; value<threshold : negative vice versa
	polarity = 1;
	double a = log(pow(p_n,2)*sig_p/pow(p_p,2)/sig_n);
	if(abs(sig_n-sig_p)<10e-4)
	{
		double x = (sig_p*a+u_p-u_n)/(u_p-u_n)/2;
		er = p_p*Gaussian::phi_cplx(x,u_p,sig_p)+p_n*(1-Gaussian::phi_cplx(x,u_n,sig_n));
		e = p_p*(1-Gaussian::phi_cplx(x,u_p,sig_p))+p_n*Gaussian::phi_cplx(x,u_n,sig_n);
		vt = x;
		if(e<er)
		{
			er = e;
			polarity = -1;
		}
		return;
	}
	double x1 = (u_n*sig_p-u_p*sig_n+sqrt(sig_n*sig_p*(pow(u_p-u_n,2)+a*(sig_p-sig_n))))/(sig_p-sig_n);
	double x2 = (u_n*sig_p-u_p*sig_n-sqrt(sig_n*sig_p*(pow(u_p-u_n,2)+a*(sig_p-sig_n))))/(sig_p-sig_n);
	e = p_p*Gaussian::phi_cplx(x1,u_p,sig_p)+p_n*(1-Gaussian::phi_cplx(x1,u_n,sig_n));
	er = p_p*Gaussian::phi_cplx(x2,u_p,sig_p)+p_n*(1-Gaussian::phi_cplx(x2,u_n,sig_n));
	vt = x2;
	if(e<er)
	{
		er = e;
		vt = x1;
	}

	e = p_p*(1-Gaussian::phi_cplx(x1,u_p,sig_p))+p_n*Gaussian::phi_cplx(x1,u_n,sig_n);
	if(e<er)
	{
		er = e;
		vt = x1;
		polarity = -1;
	}
	e = p_p*(1-Gaussian::phi_cplx(x2,u_p,sig_p))+p_n*Gaussian::phi_cplx(x2,u_n,sig_n);
	if(e<er)
	{
		er = e;
		vt = x2;
		polarity = -1;
	}
}

int Classifier::makeDecision(Element& ele, pfeature& pf)
{
	double value(0);
	mult(ele.inte_image,pf[index].G,value);
	if(1 == polarity)
	{
		if(value > vt) return 1;
		else return -1;
	}
	else
	{
		if(value > vt) return -1;
		else return 1;
	}
}
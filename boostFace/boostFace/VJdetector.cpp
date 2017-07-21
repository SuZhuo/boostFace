
#include "VJdetector.h"
//#include "Element.cpp"



//[1] Fast Training and Selection of Haar Features using Statistics in Boosting-based Face Detection.
//Minh-Tri Pham Tat-Jen Cham. ICCV 2007.

int VJdetector::getFeatures()
{
	int count(0),g_count;
	int i,j,w,h;
	//step 1: get features of type (a)
	for(i = 0; i < DIM; i++)
	{
		for(j = 0; j < DIM; j++)
		{
			for(w = 1; 2*w < 25-j; w++)
			{
				for(h = 1; h < 25-i; h++)
				{
					g_count = 0;
					feature::getPosition(i+h-1, j+w-1, 2, pf, count, g_count);
					feature::getPosition(i+h-1, j-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j+w-1, -2, pf, count, g_count);
					feature::getPosition(i-1, j-1, 1,pf, count, g_count);

					feature::getPosition(i+h-1, j+2*w-1, -1, pf, count, g_count);
					//feature::getPosition(i+h-1, j+w-1, 1, pf, count, g_count);
					feature::getPosition(i-1, j+2*w-1, 1, pf, count, g_count);
					//feature::getPosition(i-1, j+w-1, -1, pf, count, g_count);

					pf[count].tp = 'a';
					count++;
				}
			}
		}
	}

	//step 2: get features of type (b)
	for(i = 0; i < DIM; i++)
	{
		for(j = 0; j < DIM; j++)
		{
			for(w = 1; 3*w < 25-j; w++)
			{
				for(h = 1; h < 25-i; h++)
				{
					g_count  = 0;
					feature::getPosition(i+h-1, j+w-1, 2, pf, count, g_count);
					feature::getPosition(i+h-1, j-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j+w-1, -2, pf, count, g_count);
					feature::getPosition(i-1, j-1, 1,pf, count, g_count);

					feature::getPosition(i+h-1, j+2*w-1, -2, pf, count, g_count);
					//feature::getPosition(i+h-1, j+w-1, 1, pf, count, g_count);
					feature::getPosition(i-1, j+2*w-1, 2, pf, count, g_count);
					//feature::getPosition(i-1, j+w-1, -1, pf, count, g_count);

					feature::getPosition(i+h-1, j+3*w-1, 1, pf, count, g_count);
					//feature::getPosition(i+h-1, j+2*w-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j+3*w-1, -1, pf, count, g_count);
					//feature::getPosition(i-1, j+2*w-1, 1, pf, count, g_count);

					pf[count].tp = 'b';
					count++;
				}
			}
		}
	}

	//step 3: get features of type (c)
	for(i = 0; i < DIM; i++)
	{
		for(j = 0; j < DIM; j++)
		{
			for(w = 1; w < 25-j; w++)
			{
				for(h = 1; 2*h < 25-i; h++)
				{
					g_count = 0;
					feature::getPosition(i+h-1, j+w-1, 2, pf, count, g_count);
					feature::getPosition(i+h-1, j-1, -2, pf, count, g_count);
					feature::getPosition(i-1, j+w-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j-1, 1,pf, count, g_count);

					feature::getPosition(i+2*h-1, j+w-1, -1, pf, count, g_count);
					feature::getPosition(i+2*h-1, j-1, 1, pf, count, g_count);
					//feature::getPosition(i+h-1, j+w-1, 1, pf, count, g_count);
					//feature::getPosition(i+h-1, j-1, -1, pf, count, g_count);

					pf[count].tp = 'c';
					count++;
				}
			}
		}
	}

	//step 4: get features of type (d)
	for(i = 0; i < DIM; i++)
	{
		for(j = 0; j < DIM; j++)
		{
			for(w = 1; w < 25-j; w++)
			{
				for(h = 1; 3*h < 25-i; h++)
				{
					g_count  = 0;
					feature::getPosition(i+h-1, j+w-1, 2, pf, count, g_count);
					feature::getPosition(i+h-1, j-1, -2, pf, count, g_count);
					feature::getPosition(i-1, j+w-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j-1, 1,pf, count, g_count);

					feature::getPosition(i+2*h-1, j+w-1, -2, pf, count, g_count);
					feature::getPosition(i+2*h-1, j-1, 2, pf, count, g_count);
					//feature::getPosition(i+h-1, j+w-1, 1, pf, count, g_count);
					//feature::getPosition(i+h-1, j-1, -1, pf, count, g_count);

					feature::getPosition(i+3*h-1, j+w-1, 1, pf, count, g_count);
					feature::getPosition(i+3*h-1, j-1, -1, pf, count, g_count);
					//feature::getPosition(i+2*h-1, j+w-1, -1, pf, count, g_count);
					//feature::getPosition(i+2*h-1, j-1, 1,pf, count, g_count);

					pf[count].tp = 'd';
					count++;
				}
			}
		}
	}

	//step 5: get features of type (e)
	for(i = 0; i < DIM; i++)
	{
		for(j = 0; j < DIM; j++)
		{
			for(w = 1; 2*w < 25-j; w++)
			{
				for(h = 1; 2*h < 25-i; h++)
				{
					g_count  = 0;
					feature::getPosition(i+h-1, j+w-1, 4, pf, count, g_count);
					feature::getPosition(i+h-1, j-1, -2, pf, count, g_count);
					feature::getPosition(i-1, j+w-1, -2, pf, count, g_count);
					feature::getPosition(i-1, j-1, 1, pf, count, g_count);

					feature::getPosition(i+2*h-1, j+w-1, -2, pf, count, g_count);
					feature::getPosition(i+2*h-1, j-1, 1, pf, count, g_count);
					//feature::getPosition(i+h-1, j+w-1, 1, pf, count, g_count);
					//feature::getPosition(i+h-1, j-1, -1, pf, count, g_count);

					feature::getPosition(i+h-1, j+2*w-1, -2, pf, count, g_count);
					//feature::getPosition(i+h-1, j+w-1, 1, pf, count, g_count);
					feature::getPosition(i-1, j+2*w-1, 1, pf, count, g_count);
					//feature::getPosition(i-1, j+w-1, -1,pf, count, g_count);

					feature::getPosition(i+2*h-1, j+2*w-1, 1, pf, count, g_count);
					//feature::getPosition(i+2*h-1, j+w-1, -1, pf, count, g_count);
					//feature::getPosition(i+h-1, j+2*w-1, -1, pf, count, g_count);
					//feature::getPosition(i+h-1, j+w-1, 1, pf, count, g_count);

					pf[count].tp = 'e';
					count++;
				}
			}
		}
	}
	//step 6: get features of type (f)
	for(i = 0; i < DIM; i++)
	{
		for(j = 0; j < DIM; j++)
		{
			for(w = 1; 3*w < 25-j; w++)
			{
				for(h = 1; 3*h < 25-i; h++)
				{
					g_count  = 0;
					feature::getPosition(i+3*h-1, j+3*w-1,1, pf, count, g_count);
					feature::getPosition(i+3*h-1, j-1, 1, pf, count, g_count);
					feature::getPosition(i-1, j+3*w-1, 1, pf, count, g_count);
					feature::getPosition(i-1, j-1, 1, pf, count, g_count);

					feature::getPosition(i+2*h-1, j+3*w-1, -2, pf, count, g_count);
					feature::getPosition(i+2*h-1, j+w-1, -2, pf, count, g_count);
					//feature::getPosition(i-1, j+3*w-1, 2, pf, count, g_count);
					feature::getPosition(i-1, j+w-1, -2, pf, count, g_count);

					feature::getPosition(i+3*h-1, j+2*w-1, -2, pf, count, g_count);
					//feature::getPosition(i+3*h-1, j-1, 2, pf, count, g_count);
					feature::getPosition(i+h-1, j+2*w-1, -2, pf, count, g_count);
					feature::getPosition(i+h-1, j-1, -2,pf, count, g_count);

					feature::getPosition(i+2*h-1, j+2*w-1, 4, pf, count, g_count);
					//feature::getPosition(i+2*h-1, j+w-1, -4, pf, count, g_count);
					//feature::getPosition(i+h-1, j+2*w-1, -4, pf, count, g_count);
					feature::getPosition(i+h-1, j+w-1, 4, pf, count, g_count);

					pf[count].tp = 'f';
					count++;
				}
			}
		}
	}

	//step 7: get features of type (g)
	for(i = 0; i < DIM; i++)
	{
		for(j = 0; j < DIM; j++)
		{
			for(w = 1; 3*w < 25-j; w++)
			{
				for(h = 1; 3*h < 25-i; h++)
				{
					g_count  = 0;
					feature::getPosition(i+3*h-1, j+3*w-1,-1, pf, count, g_count);
					feature::getPosition(i+3*h-1, j-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j+3*w-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j-1, -1, pf, count, g_count);

					//feature::getPosition(i+3*h-1, j+3*w-1, -2, pf, count, g_count);
					feature::getPosition(i+3*h-1, j+w-1, 2, pf, count, g_count);
					feature::getPosition(i+h-1, j+3*w-1, 2, pf, count, g_count);
					feature::getPosition(i+h-1, j+w-1, 2, pf, count, g_count);

					feature::getPosition(i+2*h-1, j+2*w-1, 2, pf, count, g_count);
					feature::getPosition(i+2*h-1, j-1, 2, pf, count, g_count);
					feature::getPosition(i-1, j+2*w-1, 2, pf, count, g_count);
					//feature::getPosition(i-1, j-1, -2,pf, count, g_count);

					//feature::getPosition(i+2*h-1, j+2*w-1, 4, pf, count, g_count);
					feature::getPosition(i+2*h-1, j+w-1, -4, pf, count, g_count);
					feature::getPosition(i+h-1, j+2*w-1, -4, pf, count, g_count);
					//feature::getPosition(i+h-1, j+w-1, 4, pf, count, g_count);

					pf[count].tp = 'g';
					count++;
				}
			}
		}
	}

	//step 8: get features of type (h)
	for(i = 0; i < DIM; i++)
	{
		for(j = 0; j < DIM; j++)
		{
			for(w = 1; 4*w < 25-j; w++)
			{
				for(h = 1; h < 25-i; h++)
				{
					g_count  = 0;
					feature::getPosition(i+h-1, j+4*w-1,1, pf, count, g_count);
					feature::getPosition(i+h-1, j-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j+4*w-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j-1, 1, pf, count, g_count);

					feature::getPosition(i+h-1, j+3*w-1, -2, pf, count, g_count);
					feature::getPosition(i+h-1, j+w-1, 2, pf, count, g_count);
					feature::getPosition(i-1, j+3*w-1, 2, pf, count, g_count);
					feature::getPosition(i-1, j+w-1, -2, pf, count, g_count);

					pf[count].tp = 'h';
					count++;
				}
			}
		}
	}

	//step 9: get features of type (i)
	for(i = 0; i < DIM; i++)
	{
		for(j = 0; j < DIM; j++)
		{
			for(w = 1; w < 25-j; w++)
			{
				for(h = 1; 4*h < 25-i; h++)
				{
					g_count  = 0;
					feature::getPosition(i+4*h-1, j+w-1,1, pf, count, g_count);
					feature::getPosition(i+4*h-1, j-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j+w-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j-1, 1, pf, count, g_count);

					feature::getPosition(i+3*h-1, j+w-1, -2, pf, count, g_count);
					feature::getPosition(i+3*h-1, j-1, 2, pf, count, g_count);
					feature::getPosition(i+h-1, j+w-1, 2, pf, count, g_count);
					feature::getPosition(i+h-1, j-1, -2, pf, count, g_count);

					pf[count].tp = 'i';
					count++;
				}
			}
		}
	}

	//step 10: get features of type (j)
	for(i = 0; i < DIM; i++)
	{
		for(j = 0; j < DIM; j++)
		{
			for(w = 1; 2*w < 25-j; w++)
			{
				for(h = 1; 2*h < 25-i; h++)
				{
					g_count  = 0;
					feature::getPosition(i+2*h-1, j+2*w-1,1, pf, count, g_count);
					feature::getPosition(i+2*h-1, j-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j+2*w-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j-1, 1, pf, count, g_count);

					feature::getPosition(i+h-1, j+w-1, -2, pf, count, g_count);
					feature::getPosition(i+h-1, j-1, 2, pf, count, g_count);
					feature::getPosition(i-1, j+w-1, 2, pf, count, g_count);
					feature::getPosition(i-1, j-1, -2, pf, count, g_count);

					pf[count].tp = 'j';
					count++;
				}
			}
		}
	}

	//step 11: get features of type (k)
	for(i = 0; i < DIM; i++)
	{
		for(j = 0; j < DIM; j++)
		{
			for(w = 1; 2*w < 25-j; w++)
			{
				for(h = 1; 2*h < 25-i; h++)
				{
					g_count  = 0;
					feature::getPosition(i+2*h-1, j+2*w-1,1, pf, count, g_count);
					feature::getPosition(i+2*h-1, j-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j+2*w-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j-1, 1, pf, count, g_count);

					feature::getPosition(i+h-1, j+2*w-1, -2, pf, count, g_count);
					feature::getPosition(i+h-1, j+w-1, 2, pf, count, g_count);
					feature::getPosition(i-1, j+2*w-1, 2, pf, count, g_count);
					feature::getPosition(i-1, j+w-1, -2, pf, count, g_count);

					pf[count].tp = 'k';
					count++;
				}
			}
		}
	}

	//step 12: get features of type (l)
	for(i = 0; i < DIM; i++)
	{
		for(j = 0; j < DIM; j++)
		{
			for(w = 1; 2*w < 25-j; w++)
			{
				for(h = 1; 2*h < 25-i; h++)
				{
					g_count  = 0;
					feature::getPosition(i+2*h-1, j+2*w-1,1, pf, count, g_count);
					feature::getPosition(i+2*h-1, j-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j+2*w-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j-1, 1, pf, count, g_count);

					feature::getPosition(i+2*h-1, j+2*w-1, -2, pf, count, g_count);
					feature::getPosition(i+2*h-1, j+w-1, 2, pf, count, g_count);
					feature::getPosition(i+h-1, j+2*w-1, 2, pf, count, g_count);
					feature::getPosition(i+h-1, j+w-1, -2, pf, count, g_count);

					pf[count].tp = 'l';
					count++;
				}
			}
		}
	}

	//step 13: get features of type (m)
	for(i = 0; i < DIM; i++)
	{
		for(j = 0; j < DIM; j++)
		{
			for(w = 1; 2*w < 25-j; w++)
			{
				for(h = 1; 2*h < 25-i; h++)
				{
					g_count  = 0;
					feature::getPosition(i+2*h-1, j+2*w-1,1, pf, count, g_count);
					feature::getPosition(i+2*h-1, j-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j+2*w-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j-1, 1, pf, count, g_count);

					feature::getPosition(i+2*h-1, j+w-1, -2, pf, count, g_count);
					feature::getPosition(i+2*h-1, j-1, 2, pf, count, g_count);
					feature::getPosition(i+h-1, j+w-1, 2, pf, count, g_count);
					feature::getPosition(i+h-1, j-1, -2, pf, count, g_count);

					pf[count].tp = 'm';
					count++;
				}
			}
		}
	}

	//step 14: get features of type (n)
	for(i = 0; i < DIM; i++)
	{
		for(j = 0; j < DIM; j++)
		{
			for(w = 1; 3*w < 25-j; w++)
			{
				for(h = 1; 3*h < 25-i; h++)
				{
					g_count  = 0;
					feature::getPosition(i+3*h-1, j+3*w-1,1, pf, count, g_count);
					feature::getPosition(i+3*h-1, j-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j+3*w-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j-1, 1, pf, count, g_count);

					feature::getPosition(i+2*h-1, j+2*w-1, -2, pf, count, g_count);
					feature::getPosition(i+2*h-1, j-1, 2, pf, count, g_count);
					feature::getPosition(i-1, j+2*w-1, 2, pf, count, g_count);
					feature::getPosition(i-1, j-1, -2, pf, count, g_count);

					pf[count].tp = 'n';
					count++;
				}
			}
		}
	}

	//step 15: get features of type (o)
	for(i = 0; i < DIM; i++)
	{
		for(j = 0; j < DIM; j++)
		{
			for(w = 1; 3*w < 25-j; w++)
			{
				for(h = 1; 3*h < 25-i; h++)
				{
					g_count  = 0;
					feature::getPosition(i+3*h-1, j+3*w-1,1, pf, count, g_count);
					feature::getPosition(i+3*h-1, j-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j+3*w-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j-1, 1, pf, count, g_count);

					feature::getPosition(i+2*h-1, j+3*w-1, -2, pf, count, g_count);
					feature::getPosition(i+2*h-1, j+w-1, 2, pf, count, g_count);
					feature::getPosition(i-1, j+3*w-1, 2, pf, count, g_count);
					feature::getPosition(i-1, j+w-1, -2, pf, count, g_count);

					pf[count].tp = 'o';
					count++;
				}
			}
		}
	}

	//step 16: get features of type (p)
	for(i = 0; i < DIM; i++)
	{
		for(j = 0; j < DIM; j++)
		{
			for(w = 1; 3*w < 25-j; w++)
			{
				for(h = 1; 3*h < 25-i; h++)
				{
					g_count  = 0;
					feature::getPosition(i+3*h-1, j+3*w-1,1, pf, count, g_count);
					feature::getPosition(i+3*h-1, j-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j+3*w-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j-1, 1, pf, count, g_count);

					feature::getPosition(i+3*h-1, j+3*w-1, -2, pf, count, g_count);
					feature::getPosition(i+3*h-1, j+w-1, 2, pf, count, g_count);
					feature::getPosition(i+h-1, j+3*w-1, 2, pf, count, g_count);
					feature::getPosition(i+h-1, j+w-1, -2, pf, count, g_count);

					pf[count].tp = 'p';
					count++;
				}
			}
		}
	}

	//step 17: get features of type (q)
	for(i = 0; i < DIM; i++)
	{
		for(j = 0; j < DIM; j++)
		{
			for(w = 1; 3*w < 25-j; w++)
			{
				for(h = 1; 3*h < 25-i; h++)
				{
					g_count  = 0;
					feature::getPosition(i+3*h-1, j+3*w-1,1, pf, count, g_count);
					feature::getPosition(i+3*h-1, j-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j+3*w-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j-1, 1, pf, count, g_count);

					feature::getPosition(i+3*h-1, j+2*w-1, -2, pf, count, g_count);
					feature::getPosition(i+3*h-1, j-1, 2, pf, count, g_count);
					feature::getPosition(i+h-1, j+2*w-1, 2, pf, count, g_count);
					feature::getPosition(i+h-1, j-1, -2, pf, count, g_count);

					pf[count].tp = 'q';
					count++;
				}
			}
		}
	}

	//step 18: get features of type (r)
	for(i = 0; i < DIM; i++)
	{
		for(j = 0; j < DIM; j++)
		{
			for(w = 1; 3*w < 25-j; w++)
			{
				for(h = 1; 3*h < 25-i; h++)
				{
					g_count  = 0;
					feature::getPosition(i+3*h-1, j+3*w-1,1, pf, count, g_count);
					feature::getPosition(i+3*h-1, j-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j+3*w-1, -1, pf, count, g_count);
					feature::getPosition(i-1, j-1, 1, pf, count, g_count);

					feature::getPosition(i+2*h-1, j+2*w-1, -2, pf, count, g_count);
					feature::getPosition(i+2*h-1, j+w-1, 2, pf, count, g_count);
					feature::getPosition(i+h-1, j+2*w-1, 2, pf, count, g_count);
					feature::getPosition(i+h-1, j+w-1, -2, pf, count, g_count);

					pf[count].tp = 'r';
					count++;
				}
			}
		}
	}

	//step 19: get features of type (s)
	for(i = 0; i < DIM; i++)
	{
		for(j = 0; j < DIM; j++)
		{
			for(w = 1; 3*w < 25-j; w++)
			{
				for(h = 1; 3*h < 25-i; h++)
				{
					g_count  = 0;
					feature::getPosition(i+3*h-1, j+3*w-1,-1, pf, count, g_count);
					feature::getPosition(i+3*h-1, j-1, 1, pf, count, g_count);
					feature::getPosition(i-1, j+3*w-1, 1, pf, count, g_count);
					feature::getPosition(i-1, j-1, -1, pf, count, g_count);

					feature::getPosition(i+h-1, j+w-1, -2, pf, count, g_count);
					feature::getPosition(i+h-1, j-1, 2, pf, count, g_count);
					feature::getPosition(i-1, j+w-1, 2, pf, count, g_count);
					//feature::getPosition(i-1, j-1, -2, pf, count, g_count);

					feature::getPosition(i+h-1, j+3*w-1, -2, pf, count, g_count);
					feature::getPosition(i+h-1, j+2*w-1, 2, pf, count, g_count);
					//feature::getPosition(i-1, j+3*w-1, 2, pf, count, g_count);
					feature::getPosition(i-1, j+2*w-1, -2, pf, count, g_count);

					feature::getPosition(i+3*h-1, j+w-1, -2, pf, count, g_count);
					//feature::getPosition(i+3*h-1, j-1, 2, pf, count, g_count);
					feature::getPosition(i+2*h-1, j+w-1, 2, pf, count, g_count);
					feature::getPosition(i+2*h-1, j-1, -2, pf, count, g_count);

					//feature::getPosition(i+3*h-1, j+3*w-1, -2, pf, count, g_count);
					feature::getPosition(i+3*h-1, j+2*w-1, 2, pf, count, g_count);
					feature::getPosition(i+2*h-1, j+3*w-1, 2, pf, count, g_count);
					feature::getPosition(i+2*h-1, j+2*w-1, -2, pf, count, g_count);

					pf[count].tp = 's';
					count++;
				}
			}
		}
	}

	have_feature = true;
	giveFeatures();
	return count;
}

bool VJdetector::giveFeatures()
{
	if(have_feature)
	{
		if(sam!=nullptr)
		{
			sam->pf = this->pf;
			sam->setFeatureFlag();
			return true;//success
		}	
	}
	return false;
}

int VJdetector::findBestStump(Classifier* clsfier)
{
	////paper[1]  Algorithm 1 Fast training a weak classifier
	int i;
	double z_p(0),z_n(0);
	cv::Mat1d m_p = cv::Mat1d::zeros(D,1);
	cv::Mat1d E_p = cv::Mat1d::zeros(D,D);
	cv::Mat1d m_n = cv::Mat1d::zeros(D,1);
	cv::Mat1d E_n = cv::Mat1d::zeros(D,D);

	//step 1: line 1 to line 5 in Algorithm 1
	for(i = 0; i < sam->NP; i++)
	{
		z_p += sam->pPos[i].w;
		m_p = m_p + (sam->pPos[i].inte_image)*(sam->pPos[i].w);
		E_p = E_p + (sam->pPos[i].inte_image)*(sam->pPos[i].inte_image.t())*(sam->pPos[i].w);
	}
	m_p = m_p/z_p;
	E_p = E_p/z_p - m_p*m_p.t();

	for(i = 0; i < sam->NN; i++)
	{
		z_n += sam->pNeg[i].w;
		m_n = m_n + (sam->pNeg[i].inte_image)*(sam->pNeg[i].w);
		E_n = E_n + (sam->pNeg[i].inte_image)*(sam->pNeg[i].inte_image.t())*(sam->pNeg[i].w);
	}
	m_n = m_n/z_n;
	E_n = E_n/z_n - m_n*m_n.t();

	//step 2: line 6 to line 12
	double e(2);
	double p_p = (double)(sam->NP)/(double)(sam->NP+sam->NN);
	double p_n = 1 - p_p;
	double u_p(0),sig_p(0);
	double u_n(0),sig_n(0);
	int count1(0),count2(0);
	double vt_in(0),er_in(0);
	int polarity_in(0);
	for(i = 0; i < NF; i++)
	{
		Classifier::mult(m_p, pf[i].G, u_p);
		Classifier::mult(E_p, pf[i].G, sig_p);;
		if(sig_p < 10e-4)
			continue;
		Classifier::mult(m_n, pf[i].G, u_n);
		Classifier::mult(E_n, pf[i].G, sig_n);
		if(sig_n < 10e-4) 
			continue;
		Classifier::findStump(p_p, u_p, sig_p, p_n, u_n, sig_n, vt_in, er_in, polarity_in);
		if(er_in < e)
		{
			e = er_in;
			clsfier->vt = vt_in;
			clsfier->index = i;
			clsfier->polarity = polarity_in;
		}
	}

	//step 3: line 12 to line 14
	//calculateEr(sam,clsfier);
	//e = clsfier->er;
	clsfier->er = e;
	clsfier->alpha = 1.0/2*log((1-e)/e);

	return 0;
}

int VJdetector::calculateEr(Sample* sam, Classifier* clsfier)
{
	double e(0);
	int i;
	for(i = 0; i < sam->NP; i++)
	{
		if((clsfier->makeDecision(sam->pPos[i],pf)) < 0)
			e += sam->pPos[i].w;
	}
	for(i = 0; i < sam->NN; i++)
	{
		if(clsfier->makeDecision(sam->pNeg[i],pf) > 0)
			e += sam->pNeg[i].w;
	}
	clsfier->er = e;
	return 0;
}

int VJdetector::adaBoost(std::list<Classifier*>& lis, int T, bool start_from_scratch)
{
	if(start_from_scratch)
	{
		sam->resetW();
	}
	int i;
	for(i = 0; i < T; i++)
	{
		Classifier* clsfier = new Classifier;
		findBestStump(clsfier);
		sam->updateW(clsfier);
		lis.push_back(clsfier);
	}
	return 0;
}

bool VJdetector::layerDecision2(Element& ele, const std::list<Classifier*>& lis, double bias)
{
	double result(0);
	for(auto ite = lis.begin(); ite!=lis.end(); ite++)
	{
		result += (*ite)->alpha * ((*ite)->makeDecision(ele,pf)+bias);
	}
	return result > 0;
}

bool VJdetector::layerDecision(Element& ele, const std::list<Classifier*>& lis, bool makeDecisionFromStart, double bias)
{
	double result(0);
	if(makeDecisionFromStart)
	{
		//makeDecisionFromStart = false;
		ele.probability = 0;
		ele.accumulatedBias = 0;
		for(auto ite = lis.begin(); ite!=lis.end(); ite++)
		{
			ele.probability += (*ite)->alpha * ((*ite)->makeDecision(ele,pf));
			ele.accumulatedBias += (*ite)->alpha;
		}
		result = ele.probability;
	}
	else
	{
		double accu;
		accu = ele.accumulatedBias * bias;
		result = ele.probability + accu;
	}
	return result > 0;
}

int  VJdetector::calculateFPR_and_DETR(const std::list<Classifier*>& lis, double& FPR, double& DETR,
											bool makeDecisionFromStart,double biasRate)
{
	FPR = 0;
	DETR = 0;
	double DETR2 = 0;
	int i;
	for(i = 0; i < sam->NN; i++)
	{
		if(layerDecision(sam->pNeg[i],lis,makeDecisionFromStart,biasRate))
			FPR++;
	}
	for(i = 0; i < sam->NP; i++)
	{
		if(layerDecision(sam->pPos[i],lis,makeDecisionFromStart,biasRate))
			DETR++;
	}
	for(i = sam->NP; i < sam->NP+500; i++)
	{
		if(layerDecision(sam->pPos[i],lis,makeDecisionFromStart,biasRate))
			DETR2++;
	}

	FPR /= (double)(sam->NN);
	DETR /= (double)(sam->NP);
	DETR2 /= 500.0;
	if(DETR2 < DETR) DETR = DETR2;
	return 0;
}

int VJdetector::getBaseNumberOfFeaturesInLayer(int layer)
{
	switch(layer)
	{
	case 1:
		return 2;
	case 2:
	case 3:
		return 5;
	case 4:
		return 20;
	case 5:
		return 30;
	default:
		return 40;
	}
}

int VJdetector::getNumberStepOfFeaturesInLayer(int layer)
{
	switch(layer)
	{
	case 1:
		return 1;
	case 2:
	case 3:
	case 4:
	case 5:
		return 3;
	case 6:
		return 3;
	default:
		return 3;
	}
}

double VJdetector::attentionalCascade(double alpha_all, double alpha_layer, double beta_layer, int numberOfLayer)
{
	//loadParameter("E:\\кув©\\face detection\\data\\parameters5_4_16_24.vj");
	const double room = 1e-5;
	double a0(1), a, b;
	int layer(0),T_layer,featureStep;
	double u(0), bias;
	//std::list<Classifier*>* lis(nullptr);
	ShiftedClassifier* shiftlis(nullptr);
	bool increase(false),decrease(false);
	bool relayer(false);
	bool newCycle(true),newAda(true),start_from_scratch(true);
	bool makeDecisionFromStart(true);
	while(a0 > alpha_all)
	{
		
		if(newCycle)
		{
			if(!relayer)
			{
				if(layer < numberOfLayer)
				{
					if((0 != layer) && newCycle)
					{
						int a = DrawNegatives(layer);
						a++;
					}
				}
				else
				{
					break;
				}
			}


			shiftlis = nullptr;
			//lis = new std::list<Classifier*>;
			shiftlis = new ShiftedClassifier;			
			layer++;			
			T_layer = getBaseNumberOfFeaturesInLayer(layer);
			featureStep = T_layer;
			start_from_scratch = true;
			newCycle = false;
			if (relayer) relayer = false;
		}
		if(newAda)
		{
			increase = false;
			decrease = false;
			u = 0.01;
			bias = 0;
			makeDecisionFromStart = true;
			shiftlis->s = 0;
			adaBoost(shiftlis->lis,featureStep,start_from_scratch);
			featureStep = getNumberStepOfFeaturesInLayer(layer);
			newAda = false;
		}
		
		calculateFPR_and_DETR(shiftlis->lis,a,b,makeDecisionFromStart,bias);
		if(makeDecisionFromStart) makeDecisionFromStart = false;
		if(a <= alpha_layer && b >= beta_layer)
		{
			a0 *= a;
			newCycle = true;
			newAda = true;
			shiftlis->FPR = a;
			shiftlis->DETR = b;
			cascadeLis.push_back(shiftlis);
			TRAINING_FPR = a0;
			saveToFile();
			//draw n training negatives
			continue;
		}
		else if(a <= alpha_layer && b < beta_layer && u > room)
		{
			double temp = bias;
			bias += u;
			increase = true;
			if(decrease)
			{
				u /= 2;
				bias -= u;
				decrease = false;
			}
			shiftlis->s = bias;
			continue;
		}
		else if(a > alpha_layer && b >= beta_layer && u > room)
		{
			double temp = bias;
			bias -= u;
			decrease = true;
			if(increase)
			{
				u /= 2;
				bias += u;
				increase = false;
			}
			shiftlis->s = bias;
			continue;
		}
		else
		{
			if(T_layer >= 300)
			{
				saveToFile(false);
				delete shiftlis;
				int b = DrawNegatives_over(--layer);
				relayer = true;
				newCycle = true;
				newAda = true;
				continue;
				//saveToFile();
				//return a0;
			}
			else
			{
				T_layer += featureStep;
				newAda = true;
				start_from_scratch = false;
				continue;
			}
		}
	}
	return a0;
}

double VJdetector::train(double alpha_all, double alpha_layer, double beta_layer, int numberOfLayer)
{
	int a(0);
	int b = DrawPositives(a);
	if(a > 0) return -1;
	if(NF != getFeatures())
	{
		return -1;
	}
	//loadParameter("C:\\Users\\buaa\\Desktop\\face detection\\parameters5_3_14_43.vj");////
	TRAINING_FPR = attentionalCascade(alpha_all, alpha_layer, beta_layer, numberOfLayer);
	saveToFile();
	return TRAINING_FPR;
}

int VJdetector::saveToFile(bool succ)
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	std::string time = std::to_string((long long)sys.wMonth) + "_" + std::to_string((long long)sys.wDay) + "_" 
		+ std::to_string((long long)sys.wHour) + "_" + std::to_string((long long)sys.wMinute);

	std::string filename = filespath+"\\parameters"+time+".vj";
	std::ofstream ofile(filename);
	if (!succ)
	{
		ofile << "Number of classifiers overrun." << std::endl;
		ofile.close();
		return 0;
	}
	if(cascadeLis.empty())
	{
		ofile<<"no parameters trained."<<std::endl;
		ofile.close();
		return 0;
	}
	int layer(0);
	ofile<<"False Positive Rate: "<<TRAINING_FPR<<std::endl<<std::endl;
	for(auto item = cascadeLis.begin(); item != cascadeLis.end(); item++)
	{
		layer++;
		ofile<<"Layer: "<<layer<<std::endl;
		ofile<<"\t"<<"number of Classifier: "<<(*item)->lis.size()<<std::endl;
		ofile<<"\t"<<"FALSE_POSITIVE_RATE: "<<(*item)->FPR<<std::endl;
		ofile<<"\t"<<"DETECTION_RATE: "<<(*item)->DETR<<std::endl;
		ofile<<"\t"<<"bias: "<<std::setprecision(10)<<((*item)->s)<<std::endl;
		int count(0);
		for(auto clsfier = (*item)->lis.begin(); clsfier != (*item)->lis.end(); clsfier++)
		{
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
	return 0;
}

int VJdetector::DrawPositives(int& index)
{
	int i;
	srand((unsigned)time(NULL));
	int file_min(0),file_max(1071);
	int file_index(0);

	int j;
	int a[1978];
	for(j=0; j<1978; ++j) a[j]=j;
	for(j=1977; j>=1; --j) std::swap(a[j], a[rand()%j]);
	for(i = 0; i < sam->NP+500; i++)
	{
		std::string filepath = filespath+"\\face2\\"+std::to_string((long long)(a[i]))+".jpg";
		cv::Mat image = cv::imread(filepath,0);
		if(-1 == sam->pPos[i].Calc_Integral(image))
		{
			index++;
		}
	}

	////draw negatives as well.
	int count(0);
	for(i = 0; i < sam->NN; i++)
	{
		std::string filepath = savepath+"\\layer0\\"+std::to_string((long long)i)+".jpg";
		//std::string filepath = "C:\\Users\\buaa\\Desktop\\face detection\\training negatives\\SIXTH TRAIN\\layer11\\"
		//+std::to_string((long long)i)+".jpg";
		cv::Mat image = cv::imread(filepath,0);
		if(-1 == sam->pNeg[i].Calc_Integral(image))
		{
			count++;
			//index = i;
		}
	}
	return count;





	//std::string filespath = "C:\\Users\\buaa\\Desktop\\face detection\\training negatives\\SIXTH TRAIN\\layer10\\";
	//std::string layer_savepath = "C:\\Users\\buaa\\Desktop\\face detection\\training negatives\\SIXTH TRAIN\\layer11";
	//_mkdir(layer_savepath.c_str());
	//srand((unsigned)time(NULL));
	//int file_min(0),file_max(1071);
	//int file_index(0),scale_index(0);
	//double scale;
	//int x,y;
	//int count(0);
	//for(int i = 0; i < sam->NN; )
	//{
	//	/*if(cascadeDecision(sam->pNeg[i]))
	//	count++;
	//	i++;*/
	//	std::string filepath = filespath+std::to_string((long long)i)+".jpg";
	//	std::string fsavepath = layer_savepath+"\\"+std::to_string((long long)i)+".jpg";
	//	cv::Mat image2 = cv::imread(filepath);
	//	sam->pNeg[i].Calc_Integral(image2);
	//	if(cascadeDecision(sam->pNeg[i]))
	//	{
	//		i++;
	//		cv::imwrite(fsavepath,image2);
	//		continue;
	//	}
	//	int success(0);
	//	do
	//	{
	//		count++;
	//		file_index = file_min+file_max*rand()/RAND_MAX;
	//		std::string filepath = "C:\\Users\\buaa\\Desktop\\face detection\\non_face\\"+std::to_string((long long)file_index)+".jpg";
	//		scale_index = 3*rand()/RAND_MAX;
	//		scale = pow(scale_step,scale_index);
	//		cv::Mat image = cv::imread(filepath);
	//		x = (image.rows-25*scale)*rand()/RAND_MAX;
	//		y = (image.cols-25*scale)*rand()/RAND_MAX;
	//		cv::Mat sub_image = image(cv::Rect(y,x,24*scale,24*scale)).clone();
	//		cv::resize(sub_image,sub_image,cv::Size(24,24));
	//		if(sam->pNeg[i].Calc_Integral(sub_image) > 1)
	//		{
	//			if(cascadeDecision(sam->pNeg[i]))
	//			{
	//				cv::imwrite(fsavepath,sub_image);
	//				i++;
	//				success = 1;
	//			}		
	//		}
	//	}while(0 == success);		
	//	
	//}
	//return count;


}

int VJdetector::DrawNegatives_over(int layer)
{
	//Negative neg;
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	std::string time2 = std::to_string((long long)sys.wHour) + "_" + std::to_string((long long)sys.wMinute);
	std::string layer_savepath = savepath + "\\relayer_"+time2 + std::to_string((long long)layer);
	int i;

	_mkdir(layer_savepath.c_str());
	srand((unsigned)time(NULL));
	int file_min(0), file_max(1071);
	int file_index(0), scale_index(0);
	double scale;
	int x, y;
	int count(0);
	for (i = 0; i < sam->NN;)
	{
		int success(0);
		do
		{
			count++;
			file_index = file_min + file_max*rand() / RAND_MAX;
			std::string filepath = filespath + "\\non_face\\" + std::to_string((long long)file_index) + ".jpg";
			scale_index = 3 * rand() / RAND_MAX;
			scale = pow(scale_step, scale_index);
			cv::Mat image = cv::imread(filepath, 0);
			x = (image.rows - 25 * scale)*rand() / RAND_MAX;
			y = (image.cols - 25 * scale)*rand() / RAND_MAX;
			cv::Mat sub_image = image(cv::Rect(y, x, 24 * scale, 24 * scale)).clone();
			cv::resize(sub_image, sub_image, cv::Size(24, 24));
			if (sam->pNeg[i].Calc_Integral(sub_image) > 1)
			{
				if (cascadeDecision(sam->pNeg[i]))
				{
					std::string savefilepath = layer_savepath + "\\" + std::to_string((long long)i) + ".jpg";
					cv::imwrite(savefilepath, sub_image);
					i++;
					success = 1;
				}
			}
		} while (0 == success);

	}
	return count;
}

int VJdetector::DrawNegatives(int layer)
{
	///draw positives as well
	int i;


	int j;
	int a[1978];
	for(j=0; j<1978; ++j) a[j]=j;
	for(j=1977; j>=1; --j) std::swap(a[j], a[rand()%j]);
	for(i = 0; i < sam->NP+500; i++)
	{
		std::string filepath = filespath+"\\face2\\"+std::to_string((long long)(a[i]))+".jpg";
		cv::Mat image = cv::imread(filepath,0);
		sam->pPos[i].Calc_Integral(image);
	}



	//Negative neg;
	std::string layer_savepath = savepath + "\\layer"+std::to_string((long long)layer);

	_mkdir(layer_savepath.c_str());
	srand((unsigned)time(NULL));
	int file_min(0),file_max(1071);
	int file_index(0),scale_index(0);
	double scale;
	int x,y;
	int count(0);
	for(i = 0; i < sam->NN; )
	{
		if(cascadeDecision(sam->pNeg[i]))
		{
			i++;
			continue;
		}
		int success(0);
		do
		{
			count++;
			file_index = file_min+file_max*rand()/RAND_MAX;
			std::string filepath = filespath+"\\non_face\\"+std::to_string((long long)file_index)+".jpg";
			scale_index = 3*rand()/RAND_MAX;
			scale = pow(scale_step,scale_index);
			cv::Mat image = cv::imread(filepath,0);
			x = (image.rows-25*scale)*rand()/RAND_MAX;
			y = (image.cols-25*scale)*rand()/RAND_MAX;
			cv::Mat sub_image = image(cv::Rect(y,x,24*scale,24*scale)).clone();
			cv::resize(sub_image,sub_image,cv::Size(24,24));
			if(sam->pNeg[i].Calc_Integral(sub_image) > 1)
			{
				if(cascadeDecision(sam->pNeg[i]))
				{
					std::string savefilepath = layer_savepath+"\\"+std::to_string((long long)i)+".jpg";
					cv::imwrite(savefilepath,sub_image);
					i++;
					success = 1;
				}		
			}
		}while(0 == success);		
		
	}
	return count;
}

bool VJdetector::cascadeDecision(Element& ele)
{
	if(cascadeLis.empty())
	{
		return true;//if cascadelis is empty , decide element is a face.
	}
	for(auto item = cascadeLis.begin(); item != cascadeLis.end(); item++)
	{
		if(!layerDecision2(ele,(*item)->lis,(*item)->s))
		{
			return false;
		}
	}
	return true;
}

int VJdetector::getNumberOfNegatives(int layer)
{
	if(layer > 6)
		return 600;
	else
		return 1000;
}

int VJdetector::loadParameter(std::string path)
{
	std::ifstream ifile(path);
	std::string strvalue;
	std::string str1;
	Classifier* clsifier(nullptr);
	ShiftedClassifier* shiflis(nullptr);
	while(!ifile.eof())
	{
		ifile>>str1;
		if("Rate:" == str1)
		{
			ifile>>strvalue;
			TRAINING_FPR = std::stod(strvalue);
		}
		else if("Layer:" == str1)
		{
			if(clsifier!=nullptr)
				shiflis->lis.push_back(clsifier);
			clsifier = nullptr;
			if(shiflis!=nullptr)
				cascadeLis.push_back(shiflis);
			shiflis = nullptr;
			shiflis = new ShiftedClassifier;
		}
		else if("bias:" == str1)
		{
			ifile>>strvalue;
			shiflis->s = std::stod(strvalue);
		}
		else if("FALSE_POSITIVE_RATE:" == str1)
		{
			ifile>>strvalue;
			shiflis->FPR = std::stod(strvalue);
		}
		else if("DETECTION_RATE:" == str1)
		{
			ifile>>strvalue;
			shiflis->DETR = std::stod(strvalue);
		}
		else if("index:" == str1)
		{
			ifile>>strvalue;
			if(clsifier!=nullptr)
				shiflis->lis.push_back(clsifier);
			clsifier = nullptr;
			clsifier = new Classifier;
			clsifier->index = std::stoi(strvalue);
		}
		else if("error:" == str1)
		{
			ifile>>strvalue;
			clsifier->er = std::stod(strvalue);
		}
		else if("threshold:" == str1)
		{
			ifile>>strvalue;
			clsifier->vt = std::stod(strvalue);
		}
		else if("polarity:" == str1)
		{
			ifile>>strvalue;
			clsifier->polarity = std::stoi(strvalue);
		}
		else if("alpha:" == str1)
		{
			ifile>>strvalue;
			clsifier->alpha = std::stod(strvalue);
		}
	}
	if(clsifier!=nullptr)
		shiflis->lis.push_back(clsifier);
	clsifier = nullptr;
	if(shiflis!=nullptr)
		cascadeLis.push_back(shiflis);
	shiflis = nullptr;
	ifile.close();
	return 0;
}

int VJdetector::detect(cv::Mat& image, cv::Mat& imageout)
{
	int i;
	int a(-1);
	imageout = image.clone();
	Element ele;
	cv::Scalar color(255,255,255);
	for(i = 2; i < 4; i++)
	{
		int w = 24 * pow(scale_step,i);
		for(int x = 0; x <= image.rows-w; x++)
		{
			for(int y = 0; y <= image.cols-w; y++)
			{
				cv::Mat sub_image = image(cv::Rect(y,x,w,w)).clone();
				cv::resize(sub_image,sub_image,cv::Size(24,24));
				ele.Calc_Integral(sub_image);
				if(cascadeDecision(ele))
				{
					a = 1;
					cv::rectangle(imageout,cv::Rect(y,x,w,w),color);
				}
			}
		}
	}
	return a;
	/*cv::rectangle(imageout,cv::Rect(298,22,81,81),color);
	cv::Mat sub_image = image(cv::Rect(298,22,81,81)).clone();
	cv::resize(sub_image,image,cv::Size(24,24));
	ele.Calc_Integral(image);
	if(cascadeDecision(ele))
		return 1;
	else
		return -1;*/
}
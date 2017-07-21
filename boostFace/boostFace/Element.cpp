#include "Element.h"
#include "Global.h"

int Element::Calc_Integral(cv::Mat& image)
{
	//inte_image.release();
	inte_image = cv::Mat1d(DIM,DIM);//cv::Mat::zeros(DIM,DIM,CV_32F);
	//inte_image = inte_image.reshape(DIM);
	//inte_imagesquare = cv::Mat::zeros(DIM,DIM,CV_32F);
	inte_image.at<double>(0,0) = image.at<uchar>(0,0);
	//inte_imagesquare.at<double>(0,0) = pow((double)(image.at<uchar>(0,0)),2);
	int i,j;
	double var = pow((double)(image.at<uchar>(0,0)),2);
	uchar* data_image = image.ptr<uchar>(0);
	double* data_inte = inte_image.ptr<double>(0);
	//double* data_intesquare = inte_imagesquare.ptr<double>(0);
	double* data_inte0(nullptr);
	//double* data_intesquare0(nullptr);
	for(j = 1; j < DIM; j++)
	{
		data_inte[j] = data_image[j] + data_inte[j-1];
		//data_intesquare[j] = pow((double)(data_image[j]),2)+data_intesquare[j-1];
		var += pow((double)(data_image[j]),2);
	}
	for(i = 1; i < DIM; i++)
	{
		inte_image.at<double>(i,0) = inte_image.at<double>(i-1,0)+image.at<uchar>(i,0);
		//inte_imagesquare.at<double>(i,0) = inte_imagesquare.at<double>(i-1,0)+pow((double)(image.at<uchar>(i,0)),2);
		var += pow((double)(image.at<uchar>(i,0)),2);
	}
	for(i = 1; i < DIM; i++)
	{
		data_image = image.ptr<uchar>(i);
		data_inte = inte_image.ptr<double>(i);
		data_inte0 = inte_image.ptr<double>(i-1);
		//data_intesquare = inte_imagesquare.ptr<double>(i);
		//data_intesquare0 = inte_imagesquare.ptr<double>(i-1);
		for(j = 1; j < DIM; j++)
		{
			data_inte[j] = data_image[j] + data_inte[j-1] + data_inte0[j] - data_inte0[j-1];
			//data_intesquare[j] = pow((double)(data_image[j]),2) + data_intesquare[j-1] + data_intesquare0[j] - data_intesquare0[j-1];
			var += pow((double)(data_image[j]),2);
		}
	}
	double m = inte_image.at<double>(23,23)/D;
	//double vari = inte_imagesquare.at<double>(23,23)/D - pow(m,2);
	var = var/D - pow(m,2);
	if(var<1)
	{
		inte_image = inte_image.reshape(D);
		return -1;//failed
	}
	for(i = 0; i < DIM; i++)
	{
		data_inte = inte_image.ptr<double>(i);
		for(j = 0; j < DIM; j++)
		{
			data_inte[j] -= m*(i+1)*(j+1);
		}
	}
	var = sqrt(var);
	inte_image = inte_image/var;
	inte_image = inte_image.reshape(D);
	return (int)var;//succeed
}

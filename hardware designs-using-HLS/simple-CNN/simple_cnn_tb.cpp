#include "simple_cnn.h"
#include<vector>
#include <cmath>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
int main()
{
	ifstream fetch_data;
	//ofstream rec_data;
	//rec_data.open("C:/Users/kinsh/AppData/Roaming/Xilinx/Vitis/Pulsar_detection_simple_NN_try_1/xtr.dat");
	fetch_data.open("F:/data-science-and-hardware-design--main/hardware-designs-using-HLS/simple-FC-NN-attempt#1/CNN/with-pooling-layer/in_data.dat");
	vector<vector<float>> out; int re = 1;
	float in[1][28][28];
	int temp = -1;
	if(fetch_data.is_open())
	{re = 0;}
	while(fetch_data)
	{


		re = 0;
		for(int i = 0; i < 28; i++)
		{
			for(int j = 0; j < 28; j++)
			{
				fetch_data >> in[0][i][j];
			}
		}
		//rec_data<<endl;
		//out.push_back(temp);
		//out[0] = temp;
		//<<out.size()<<endl;
		//vector<float> tr(temp,temp + 8);
		//out.push_back(tr);

	}
	model(in,&temp);
	fetch_data.close();
	//rec_data.close();
	//return(0);
	ofstream put_data;
	put_data.open("F:/data-science-and-hardware-design--main/hardware-designs-using-HLS/simple-FC-NN-attempt#1/CNN/with-pooling-layer/youtput.dat");
	if(!put_data.is_open())
		re = 1;
	/*for(int i = 0; i < out.size() - 1; i++)
	{
		//for(auto rr : out[i])
		//put_data << rr << endl;
	}
	for(int a = 0; a < 10; a++)
	{
		put_data << temp[a] <<" ";
	}*/
	put_data << temp <<endl;
	put_data.close();
	return (re);
}

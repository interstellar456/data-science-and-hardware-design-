#include "C:\Users\kinsh\AppData\Roaming\Xilinx\Vitis\NN_model.h"

int main()
{
	ifstream fetch_data;
	ofstream rec_data;
	rec_data.open("C:/Users/kinsh/AppData/Roaming/Xilinx/Vitis/Pulsar_detection_simple_NN_try_1/xtr.dat");
	fetch_data.open("C:/Users/kinsh/AppData/Roaming/Xilinx/Vitis/Pulsar_detection_simple_NN_try_1/xtrain.dat");
	vector<int> out; int re = 1;
	if(fetch_data.is_open())
	{re = 0;}
	while(fetch_data)
	{
		double in[8];
		int temp;
		re = 0;
		for(int i = 0; i < 8; i++)
		{
			fetch_data>>in[i];
			rec_data<<in[i]<<",";
		}
		rec_data<<endl;
		model(in,temp);
		out.push_back(temp);
		//<<out.size()<<endl;
	}
	fetch_data.close();
	rec_data.close();
	ofstream put_data;
	put_data.open("C:/Users/kinsh/AppData/Roaming/Xilinx/Vitis/Pulsar_detection_simple_NN_try_1/youtput.dat");
	if(!put_data.is_open())
		re = 1;
	for(int i = 0; i < out.size() - 1; i++)
	{
		put_data << out[i] << endl;
	}
	put_data.close();
	return (re);
}

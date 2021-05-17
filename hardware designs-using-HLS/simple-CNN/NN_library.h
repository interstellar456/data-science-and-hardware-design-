#include<math.h>
#ifndef  NN_LIBRARY_H_INCLUDED
#define NN_LIBRARY_H_INCLUDED
//int i = 0,j = 0,out_x = 0, out_y = 0, filter_c = 0, filter_x = 0, filter_y = 0, channel_c = 0;
//float storetemp = 0;
using namespace std;
float conv_res[32][26][26];
float maxpool_res[32][13][13];
float flattened[5408];
void FC_layer_ReLU(float *in_data,int in_dim1,int weight_dim2,float *weights,float *biases,float *out_data)
{
	int i = 0,j = 0;
    for(i = 0; i < in_dim1; i++)
    {
        for(j = 0; j < weight_dim2; j++)
        {
            *(out_data + i) += *((weights + j*in_dim1) + i)*(*(in_data + j));
        }
        *(out_data + i) += *(biases + i);
        if(*(out_data + i) < 0)
        {
        	*(out_data + i) = 0;
        }
    }
}
void sigmoid(float &in_val)
{
    in_val = 1/(1 + pow(2.71828182845,-1*in_val));
}
void predict(float &in_val)
{
    if(in_val < 0.5)
        in_val = 0;
    else in_val = 1;
}
void FC_layer_sigmoid_predict(float *in_data,int dim,float *weights,float bias,float &out_data)
{
	int i = 0;
    for(i = 0; i < dim; i++)
    {
        out_data += weights[i]*in_data[i];
    }
    out_data += bias;
    sigmoid(out_data);
    predict(out_data);
}
void Conv2D_ReLU(float *in_data,int n_channels,int in_dim1,int in_dim2,int out_dim1, int out_dim2, int n_filters,int filter_dim_x,int filter_dim_y,int stridex, int stridey, float *filters_weights, float *filter_biases, float *conv_res)
{
	//float conv_res_store[n_filters][out_dim1][out_dim2];
	//int flag = 0;
	int clk = 1;
	int filter_c,out_x,out_y,filter_x,filter_y,channel_c = 0;
	int a,b,c;
	float values[filter_dim_x*filter_dim_y*n_channels];
	int counter;
	float sum;
	float final_sum;
	Conv2D_ReLU_label0:for(filter_c = 0; filter_c < n_filters; filter_c++)
	{
		//flag = 1;

		clk = 1;
		for(out_x = 0; out_x < out_dim1; out_x++)
		{
			for(out_y = 0; out_y < out_dim2; out_y++)
			{
				//cout<<filter_c<<" "<<out_x<<" "<<out_y<<endl;
				*(conv_res + (filter_c)*(out_dim1*out_dim2) + (out_x*out_dim2) + out_y) =0;
				counter = 0;
				sum = 0;
				final_sum = 0;
				for(filter_x = 0; filter_x < filter_dim_x; filter_x++)
				{
					for(filter_y = 0; filter_y < filter_dim_y; filter_y++)
					{

						for(channel_c = 0; channel_c < n_channels; channel_c++)
						{
							/*if(filter_c == 1)
							{
								cout<<(*((in_data + ((channel_c)*(in_dim1*in_dim2)) + (stridex*out_x + filter_x)*(in_dim2) + (stridey*out_y + filter_y))))<<" ";
							}*/
							//*(conv_res + (filter_c)*(out_dim1*out_dim2) + (out_x*out_dim2) + out_y) += (*((in_data + ((channel_c)*(in_dim1*in_dim2)) + (stridex*out_x + filter_x)*(in_dim2) + (stridey*out_y + filter_y)))) * (*(filters_weights + ((filter_x)*(filter_dim_y)) + (filter_y)));
							//*((in_data + ((channel_c)*(in_dim1*in_dim2)) + (stridex*out_x + filter_x)*(in_dim2) + (stridey*out_y + filter_y))) = clk;
							//clk++;
							//cout<<*(conv_res + (filter_c)*(out_dim1*out_dim2) + (out_x*out_dim2) + out_y)<<" ";
							//*(conv_res + (filter_c)*(out_dim1*out_dim2) + (out_x*out_dim2) + out_y) += (*((in_data + ((channel_c)*(in_dim1*in_dim2)) + (stridex*out_x + filter_x)*(in_dim2) + (stridey*out_y + filter_y)))) * (*(filters_weights + (filter_c*filter_dim_x*filter_dim_y) + ((filter_x)*(filter_dim_y)) + (filter_y)));
							values[counter] = (*((in_data + ((channel_c)*(in_dim1*in_dim2)) + (stridex*out_x + filter_x)*(in_dim2) + (stridey*out_y + filter_y)))) * (*(filters_weights + (filter_c*filter_dim_x*filter_dim_y) + ((filter_x)*(filter_dim_y)) + (filter_y)));
							//cout<<*(conv_res + (filter_c)*(out_dim1*out_dim2) + (out_x*out_dim2) + out_y)<<endl;
							counter++;
						}
					}
					//if(filter_c == 1)
						//cout<<endl;
				}
				//if(filter_c == 1)
					//	cout<<endl;
				for(a = 0; a < counter; a++)
				{
					sum += values[a];
				}
				//*(conv_res + (filter_c)*(out_dim1*out_dim2) + (out_x*out_dim2) + out_y)
				final_sum = sum + *(filter_biases + filter_c);
				if(final_sum < 0)
					final_sum = 0;
				*(conv_res + (filter_c)*(out_dim1*out_dim2) + (out_x*out_dim2) + out_y) = final_sum;
				/*if(filter_c == 1)
				{
					cout<<*(conv_res + (filter_c)*(out_dim1*out_dim2) + (out_x*out_dim2) + out_y)<<" ";
				}*/
			}

			//cout<<endl;
		}

	}

}
void MaxPool2D(float *in_data,int n_channels,int in_dim1,int in_dim2,int out_dim1,int out_dim2,int sizex, int sizey,int stridex,int stridey,float *maxpool_res)
{
	//float maxpool_res[n_channels][out_dim1][out_dim2];
	float storetemp;
	int filter_c,out_x,out_y,filter_x,filter_y;
	MaxPool2D_label1:for(filter_c = 0; filter_c < n_channels; filter_c++)
	{
		for(out_x = 0; out_x < out_dim1; out_x++)
		{
			for(out_y = 0; out_y < out_dim2; out_y++)
			{
				storetemp = 0;
				for(filter_x = 0; filter_x < sizex; filter_x++)
				{
					for(filter_y = 0; filter_y < sizey; filter_y++)
					{
						if(*(in_data + ((filter_c)*(in_dim1*in_dim2)) + ((out_x*stridex + filter_x)*in_dim2) + (out_y*stridey + filter_y)) > storetemp)
							storetemp = *(in_data + ((filter_c)*(in_dim1*in_dim2)) + ((out_x*stridex + filter_x)*in_dim2) + (out_y*stridey + filter_y));
					}
				}
				//cout<<storetemp<<endl;
				*(maxpool_res + filter_c*(out_dim1*out_dim2) + out_x*out_dim2 + out_y)= storetemp;
				//cout<<*(maxpool_res + filter_c*(out_dim1*out_dim2) + out_x*out_dim2 + out_y)<<" ";
			}
			//cout<<endl;
		}
	}
	/*for(int a = 0; a < 13; a++)
	{
		for(int b = 0; b < 13; b++)
		{
			cout<<*(maxpool_res + a*13 + b)<<" "<<a<<" "<<b<<" ";
		}
		cout<<endl;
	}*/
	//*out_data = ***maxpool_res;
}
void Flatten(float *in_data,int n_channels,int dimx,int dimy,float *flattened)
{
	//float flattened[n_channels*dimx*dimy];
	int i = 0;
	int out_x,out_y,filter_c;
	for(out_x = 0; out_x < dimx; out_x++)
	{
		for(out_y = 0; out_y < dimy; out_y++)
		{
			for(filter_c = 0; filter_c < n_channels; filter_c++)
			{
				*(flattened + i) = *(in_data + (filter_c*(dimx*dimy)) + (out_x*(dimy)) + out_y);
				i++;
				//cout<<i<<" "<<out_x<<" "<<out_y<<" "<<filter_c<<endl;
			}
		}
	}
	//*out_data = *flattened;
}
void FC_layer_softmax_predict(float *in_data,int in_dim1,int weight_dim2,float *weights,float *biases,int *res)
{
	float p_array[in_dim1];
	float compare = 0;
	float storetemp = 0;
	storetemp = 0;
	int i,j;
    for(i = 0; i < in_dim1; i++)
    {
    	*(p_array + i) = 0;
        for(j = 0; j < weight_dim2; j++)
        {
            *(p_array + i) += *((weights + j*in_dim1) + i)*(*(in_data + j));
        }
        *(p_array + i) += *(biases + i);
        *(p_array + i) = pow(2.71828182845,*(p_array + i));
        storetemp += *(p_array + i);
    }

    for(i = 0; i < in_dim1; i++)
    {
    	p_array[i] = p_array[i]/storetemp;
    	if(compare < p_array[i])
    	{
    		compare = p_array[i];
    		*res = i;
    	}
    }
    //*out_data = *p_array;
}

#endif

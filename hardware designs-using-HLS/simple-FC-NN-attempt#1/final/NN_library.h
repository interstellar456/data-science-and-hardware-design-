#include<math.h>
#ifndef  NN_LIBRARY_H_INCLUDED
#define NN_LIBRARY_H_INCLUDED
int i = 0,j = 0;
void FC_layer_ReLU(float *in_data,int in_dim1,int weight_dim2,float *weights,float *biases,float *out_data)
{
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

    for(i = 0; i < dim; i++)
    {
        out_data += weights[i]*in_data[i];
    }
    out_data += bias;
    sigmoid(out_data);
    predict(out_data);
}
#endif

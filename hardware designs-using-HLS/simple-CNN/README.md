Lots of scope for optimization


Layer (type)                 Output Shape              Param #   
conv2d_14 (Conv2D)           (None, 13, 13, 32)        320       
flatten_10 (Flatten)         (None, 5408)              0         
dense_20 (Dense)             (None, 10)                54090     
dense_21 (Dense)             (None, 10)                110       
Total params: 54,520
Trainable params: 54,520
Non-trainable params: 0

performance comparison - Nvidia Tesla K80 - 35ms per frame, Xilinx Kintex 7 (xc7k420ti-ffg1156-2L) = 0.644us

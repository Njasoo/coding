import torch
import numpy as np

# Tensor: 高维数组
# shape: tensor的大小，非常重要
# dtype: 数据类型
# device: cpu或gpu或多gpu

data = [[1, 2], [3, 4]]
x_data = torch.tensor(data)
print(x_data)
x_ones = torch.ones_like(x_data)
x_ones = torch.zeros_like(x_data)
x_rand = torch.rand_like(x_data, dtype = torch.float)
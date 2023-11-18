import torch
from torch import autograd

x = torch.tensor(1.)  # 赋值为1
a = torch.tensor(1., requires_grad=True)  # 赋值为True代表需要求导,赋值为1
b = torch.tensor(2., requires_grad=True)  # 赋值为2
c = torch.tensor(3., requires_grad=True)  # 赋值为3

y = a**2 * x + b * x + c

print("before:", a.grad, b.grad, c.grad)
grads = autograd.grad(y, [a, b, c])
print("after:", grads[0], grads[1], grads[2])  # a,b,c的偏微分

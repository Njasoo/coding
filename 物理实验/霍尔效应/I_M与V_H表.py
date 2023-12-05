import numpy as np
import matplotlib.pyplot as plt
from pylab import mpl
mpl.rcParams['font.sans-serif'] = ['Microsoft YaHei'] # 指定默认字体：解决plot不能显示中文问题
mpl.rcParams['axes.unicode_minus'] = False # 解决保存图像是负号'-'显示为方块的问题

V_H=np.array([0.49,0.98,1.47,1.97,2.46,2.95,3.44,3.93,4.42,4.91])
I_M=np.array([0.100,0.200,0.300,0.400,0.500,0.600,0.700,0.800,0.900,1.000])
if len(V_H)==len(I_M):
    print("YES")
else:
    print("NO")

plt.title('V_H与I_M表')
plt.xlabel('I_M(mA)')
plt.ylabel('V_H(mV)')

plt.scatter(I_M,V_H)
plt.plot(I_M,V_H)
plt.show()
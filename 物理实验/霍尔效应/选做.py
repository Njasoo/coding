import numpy as np
import matplotlib.pyplot as plt
from pylab import mpl
mpl.rcParams['font.sans-serif'] = ['Microsoft YaHei'] # 指定默认字体：解决plot不能显示中文问题
mpl.rcParams['axes.unicode_minus'] = False # 解决保存图像是负号'-'显示为方块的问题

x = np.array([-60, -55, -50, -45, -40, -35, -30, -25, -22, -19, -16, -13, -10, -7, -4, -1, 0])
V_H = np.array([0.10, 0.12, 0.16, 0.23, 0.33, 0.53, 1.03, 2.08, 2.37, 2.38, 2.39, 2.39, 2.39, 2.39, 2.39, 2.39, 2.39])

print(len(x))
print(len(V_H))

plt.title('测量电磁铁磁感应强度 B 在 X 轴向上的分布')
plt.ylabel("V_H(mV)")
plt.xlabel('x(mm)')

plt.scatter(x, V_H)
plt.plot(x, V_H)
plt.show()
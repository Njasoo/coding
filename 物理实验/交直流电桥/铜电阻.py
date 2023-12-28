import numpy as np
import matplotlib.pyplot as plt
from pylab import mpl
mpl.rcParams['font.sans-serif'] = ['Microsoft YaHei']  # 指定默认字体：解决plot不能显示中文问题
mpl.rcParams['axes.unicode_minus'] = False  # 解决保存图像是负号'-'显示为方块的问题

t = np.array([float(x) for x in range(21, 49, 3)])
U_0 = np.array([-1.50, 7.01, 15.86, 24.70, 33.47,
               42.42, 51.03, 59.77, 68.44, 77.00])
U_0 *= 10 ** (-3)
delta_R = U_0 * 4 * 56 / 3.002
R_x = delta_R + 56
print(R_x)

plt.title('铜热电阻（卧式电桥)')
plt.xlabel('t(℃)')
plt.ylabel('R(t)(Ω)')
plt.scatter(t, R_x)
plt.plot(t, R_x)
slope, intercept = np.polyfit(t, R_x, 1)
print(slope, intercept)
plt.show()

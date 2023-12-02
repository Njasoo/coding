import numpy as np
import matplotlib.pyplot as plt
from pylab import mpl
mpl.rcParams['font.sans-serif'] = ['Microsoft YaHei'] # 指定默认字体：解决plot不能显示中文问题
mpl.rcParams['axes.unicode_minus'] = False # 解决保存图像是负号'-'显示为方块的问题

F = np.array([0.000, 4.897, 9.793, 14.690, 19.587, 24.483, 29.380, 34.277])
U = np.array([-0.6, 18.9, 38.7, 57.9, 78.6, 97.6, 110.7, 125.4])

slope, intercept = np.polyfit(F, U, 1)
print(slope, intercept)

plt.title('力敏传感器定标')
plt.xlabel('砝码重量(F/mN)')
plt.ylabel('电压(U/mV)')
plt.scatter(F, U)
plt.plot(F, slope * F + intercept, color = 'red')
# plt.show()
import numpy as np
import matplotlib.pyplot as plt
from pylab import mpl
mpl.rcParams['font.sans-serif'] = ['Microsoft YaHei']  # 指定默认字体：解决plot不能显示中文问题
mpl.rcParams['axes.unicode_minus'] = False  # 解决保存图像是负号'-'显示为方块的问题

V_H = np.array([0.49, 0.98, 1.48, 1.97, 2.46, 2.95, 3.44, 3.94, 4.43, 4.92])
I_S = np.array([1.000, 2.000, 3.000, 4.000, 5.000,
               6.000, 7.000, 8.000, 9.000, 10.000])
if len(V_H) == len(I_S):
    print("YES")
else:
    print("NO")

slope, intercept = np.polyfit(I_S, V_H, 1)
print(slope, intercept)

plt.title('V_H与I_S表')
plt.xlabel('I_S(mA)')
plt.ylabel('V_H(mV)')

plt.scatter(I_S, V_H)
plt.plot(I_S, V_H)
plt.show()

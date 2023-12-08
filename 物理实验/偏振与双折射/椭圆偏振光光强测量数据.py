import numpy as np
import matplotlib.pyplot as plt
from pylab import mpl
mpl.rcParams['font.sans-serif'] = ['Microsoft YaHei']  # 指定默认字体：解决plot不能显示中文问题
mpl.rcParams['axes.unicode_minus'] = False  # 解决保存图像是负号'-'显示为方块的问题

theta = np.arange(0, 370.0, 10)
theta[len(theta)-1] = 0.0
for i in range(len(theta)):
    theta[i] *= np.pi/180.0
print(theta)
print(len(theta))
print(np.pi)

I = np.array([59.3, 48.1, 40.3, 35.9, 36.8, 40.7, 50.4, 50.8, 63.1, 75.7, 88.5, 100.0, 107.1, 109.6, 107.6, 101.6, 91.4, 79.7,
             66.1, 54.2, 44.6, 37.9, 36.0, 39.1, 46.0, 56.2, 68.1, 83.2, 94.9, 102.5, 108.2, 108.9, 104.5, 97.2, 84.5, 72.0, 59.3])
print(len(I))

ax = plt.subplot(111, projection='polar')
plt.plot(theta, I, color='red')
ax.scatter(theta, I, color='red')
plt.show()

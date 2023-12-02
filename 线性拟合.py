import numpy as np
import matplotlib.pyplot as plt

# 先转成np.array，下面plt.plot()才能按照表达式绘图
x = np.array([0.000, 4.897, 9.793, 14.690, 19.587, 24.483, 29.380, 34.277])
y = np.array([-0.6, 18.9, 38.7, 57.9, 78.6, 97.6, 110.7, 125.4])

# polyfit(横坐标，纵坐标，自由度)
slope, intercept = np.polyfit(x, y, 1) # 斜率以及截距
print(slope, intercept)
plt.scatter(x, y)
plt.plot(x, slope * x + intercept, color = 'red')
plt.show()
import numpy as np
import matplotlib.pyplot as plt
from pylab import mpl
mpl.rcParams['font.sans-serif'] = ['Microsoft YaHei'] # 指定默认字体：解决plot不能显示中文问题
mpl.rcParams['axes.unicode_minus'] = False # 解决保存图像是负号'-'显示为方块的问题

cos_2_theta=np.array([0.00,0.03,0.12,0.25,0.41,0.59,0.75,0.88,0.97,1.00])
I_left=np.array([0.4,4.6,20.0,39.9,65.5,92.3,118.4,135.3,149.8,150.0])
I_right=np.array([0.4,5.2,18.6,38.4,63.5,92.4,116.8,134.8,147.6,150.8])

plt.title('透过两偏振器后的光强I与两周间夹角θ的关系测量数据')
plt.ylabel('I(10^-7A)')
plt.xlabel('cos^2(θ)')

plt.scatter(cos_2_theta,I_left,label='左旋')
plt.plot(cos_2_theta,I_left)
plt.scatter(cos_2_theta,I_right,marker=',',label='右旋')
plt.plot(cos_2_theta,I_right)
plt.legend()
plt.show()
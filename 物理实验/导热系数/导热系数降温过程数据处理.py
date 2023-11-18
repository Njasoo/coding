import matplotlib.pyplot as plt
from pylab import mpl
mpl.rcParams['font.sans-serif'] = ['Microsoft YaHei'] # 指定默认字体：解决plot不能显示中文问题
mpl.rcParams['axes.unicode_minus'] = False # 解决保存图像是负号'-'显示为方块的问题

plt.title('散热盘降温过程温度曲线')
plt.xlabel('t/s')
plt.ylabel('T/°C')

now = 0
cnt = 0
time_line = []
while cnt < 18:
    cnt += 1
    time_line.append(now)
    now += 30

t_C = [51.8, 51.4, 51.0, 50.5, 50.1, 49.7, 49.3, 48.9, 48.5, 48.1, 47.8, 47.4, 47.0, 46.7, 46.3, 46.0, 45.6, 45.2]
plt.plot(time_line, t_C)
plt.scatter(time_line, t_C)
plt.show()
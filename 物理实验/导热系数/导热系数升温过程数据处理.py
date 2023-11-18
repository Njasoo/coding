import matplotlib.pyplot as plt
from pylab import mpl
mpl.rcParams['font.sans-serif'] = ['Microsoft YaHei'] # 指定默认字体：解决plot不能显示中文问题
mpl.rcParams['axes.unicode_minus'] = False # 解决保存图像是负号'-'显示为方块的问题

now = 0
time_line = []
cnt = 0
while cnt < 35:
    cnt += 1
    time_line.append(now)
    now += 120

plt.title('升温过程温度变化曲线')
plt.xlabel('t/s')
plt.ylabel('T/°C')

t_A = [31.2, 38.3, 45.8, 52.2, 58.0, 57.5, 57.8, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0]
print(len(t_A))
t_C = [24.2, 24.8, 25.9, 27.4, 29.2, 31.4, 33.4, 35.2, 36.8, 38.2, 39.5, 40.6, 41.5, 42.3, 43.1, 43.7, 44.3, 44.8, 45.2, 45.7, 46.0, 46.3, 46.5, 46.8, 47.0, 47.2, 47.3, 47.4, 47.5, 47.7, 47.7, 47.8, 47.9, 47.9, 48.0]
print(len(t_C))
print(len(time_line))
plt.scatter(time_line, t_A, color = 'b', marker = ',', label = 'TA')
plt.plot(time_line, t_A, color = 'b')
plt.scatter(time_line, t_C, color = 'g', label = 'TC')
plt.plot(time_line, t_C, color = 'g')
plt.legend()
plt.show()
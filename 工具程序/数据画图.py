import matplotlib.pyplot as plt

x_values = [0,2,3,3,4,4,7,8,9,12,18]
y_values = [0,0.34,0.48,0.48,0.64,0.64,1.1,1.26,1.45,1.91,2.88]

plt.style.use('seaborn')
fig, ax = plt.subplots()
# ax.scatter(x_values, y_values, c = 'red', s = 10) # s 是点的尺寸 c for color
# ax.scatter(x_values, y_values, c = (0, 0.8, 0), s = 10) # 0.8那个位置的参数越接近0颜色越深, 越接近1越浅
ax.scatter(x_values, y_values, s = 25) # 以y为参照, y越大, 颜色越深
plt.plot(x_values, y_values, linewidth = 1)

ax.set_title("", fontsize = 14)
ax.set_xlabel("n", fontsize = 14)
ax.set_ylabel("q", fontsize = 14)

ax.tick_params(axis = 'both', which = 'major', labelsize = 14)
ax.axis([0,20,0,3]) # 设置x和y的范围

plt.show()
plt.savefig('squares_plot.png', bbox_inches = 'tight') # 自动保存图片到同级目录 第二个参数剪掉多余的空白区域
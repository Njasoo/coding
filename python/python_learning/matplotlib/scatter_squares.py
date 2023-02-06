import matplotlib.pyplot as plt

x_values = range(1, 1001)
y_values = [x ** 2 for x in x_values]

plt.style.use('seaborn')
fig, ax = plt.subplots()
# ax.scatter(x_values, y_values, c = 'red', s = 10) # s 是点的尺寸 c for color
# ax.scatter(x_values, y_values, c = (0, 0.8, 0), s = 10) # 0.8那个位置的参数越接近0颜色越深, 越接近1越浅
ax.scatter(x_values, y_values, c = y_values, cmap = plt.cm.Blues, s = 10) # 以y为参照, y越大, 颜色越深

ax.set_title("squares", fontsize = 14)
ax.set_xlabel("value", fontsize = 14)
ax.set_ylabel("square of value", fontsize = 14)

ax.tick_params(axis = 'both', which = 'major', labelsize = 14)
ax.axis([0, 1100, 0, 1100000]) # 设置x和y的范围

plt.show()
plt.savefig('squares_plot.png', bbox_inches = 'tight') # 自动保存图片到同级目录 第二个参数剪掉多余的空白区域
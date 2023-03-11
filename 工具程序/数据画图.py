import matplotlib.pyplot as plt

x_values = [-5.38, -5.35, -5.33, -5.32, -5.31, -5.29, -5.05, -4.41, -4, -3.53, -2, 0.501, 0.515, 0.565, 0.601, 0.651, 0.701, 0.73, 0.75, 0.769, 0.79, 0.795]
y_values = [-8.09, -5.99, -4.59, -2.9, -2.05, -0.89, -0.01, 0, 0, 0, 0, 0.4, 0.4, 0.42, 0.5, 0.6, 1.02, 1.98, 3.5, 6, 10.5, 12]

plt.style.use('seaborn')
fig, ax = plt.subplots()
# ax.scatter(x_values, y_values, c = 'red', s = 10) # s 是点的尺寸 c for color
# ax.scatter(x_values, y_values, c = (0, 0.8, 0), s = 10) # 0.8那个位置的参数越接近0颜色越深, 越接近1越浅
ax.scatter(x_values, y_values, s = 25) # 以y为参照, y越大, 颜色越深
plt.plot(x_values, y_values, linewidth = 1)

ax.set_title("", fontsize = 14)
ax.set_xlabel("U(V)", fontsize = 14)
ax.set_ylabel("I(mA)", fontsize = 14)

ax.tick_params(axis = 'both', which = 'major', labelsize = 14)
ax.axis([-6, 1, -15, 15]) # 设置x和y的范围

plt.show()
plt.savefig('squares_plot.png', bbox_inches = 'tight') # 自动保存图片到同级目录 第二个参数剪掉多余的空白区域
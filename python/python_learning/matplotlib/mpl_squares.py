import matplotlib.pyplot as plt

input_values = [1, 2, 3, 4, 5]
squares = [1, 4, 9, 16, 25]

plt.style.use('seaborn') # 设置风格
fig, ax = plt.subplots() # fig代表图片, ax代表图片中的各个图表
# ax.plot(input_values, squares, linewidth = 3) # (刻度, 数据来源, 线宽) 没有提供刻度的话将会自动假设刻度

# 设置图标标题并给坐标轴加上标签
ax.set_title("squares", fontsize = 24)
ax.set_xlabel("value", fontsize = 14)
ax.set_ylabel("square of value", fontsize = 14)

# 设置刻度标记的大小
ax.tick_params(axis = 'both', labelsize = 14)

plt.show()                                                                  
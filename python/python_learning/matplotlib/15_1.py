import matplotlib.pyplot as plt

x_values = range(0, 5001)
y_values = [x ** 3 for x in x_values]

fig, ax = plt.subplots()
ax.scatter(x_values, y_values, c = y_values, cmap = plt.cm.Reds, s = 10)

ax.set_title("cube", fontsize = 14)
ax.set_xlabel("value", fontsize = 14)
ax.set_ylabel("cube of value", fontsize = 14)

ax.axis([0, 5100, 0, 1.25e11])

plt.show()
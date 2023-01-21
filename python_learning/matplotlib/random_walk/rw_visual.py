import matplotlib.pyplot as plt
from random_walk import RandomWalk

while True:
  rw = RandomWalk()
  rw.fill_walk()

  plt.style.use('classic')
  fig, ax = plt.subplots(figsize = (10, 9), dpi = 128) # default dpi = 100

  point_numbers = range(rw.num_points)
  """
  ax.scatter(0, 0, c = 'green', edgecolors = 'none', s = 200)
  ax.scatter(rw.x_values[-1], rw.y_values[-1], c = 'red', edgecolor = 'none', s = 200)
  ax.scatter(rw.x_values, rw.y_values, c = point_numbers, cmap = plt.cm.Blues, edgecolors = 'none', s = 1)
  """

  ax.plot(rw.x_values, rw.y_values, c = 'blue', linewidth = 1)

  # make the axis invisible
  ax.get_xaxis().set_visible(False)
  ax.get_yaxis().set_visible(False)

  plt.savefig('random_walk.png') # this sentence must before plt.show()
  plt.show()

  keep_running = input("Make another walk? (y/n): ")
  if keep_running == 'n':
    break
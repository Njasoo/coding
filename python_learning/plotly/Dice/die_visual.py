from die import Die
from plotly.graph_objs import Bar, Layout
from plotly import offline

die_1 = Die()
die_2 = Die(10)

results = []
for roll_num in range(1000):
  result = die_1.roll() + die_2.roll()
  results.append(result)

# analysis of the results
frequencies = []
max_result = die_1.num_sides + die_2.num_sides
for value in range(2, max_result + 1):
  frequency = results.count(value)
  frequencies.append(frequency)
print(frequencies)

# make the results more visually
x_values = list(range(2, max_result + 1))
data = [Bar(x = x_values, y = frequencies)]

x_axis_config = {'title': 'result', 'dtick': 1} # dtick = the interval of xaxis
y_axis_config = {'title': 'frequency of result'}
my_layout = Layout(title = 'result of rolling a d6 and a d10 1000 times', xaxis = x_axis_config, yaxis  = y_axis_config)
offline.plot({'data': data, 'layout': my_layout}, filename = 'd6_d1.html')
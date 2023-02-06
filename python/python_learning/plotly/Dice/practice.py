from die import Die
from plotly.graph_objs import Bar, Layout
from plotly import offline

die_1 = Die(8)
die_2 = Die(8)

results = []
num_rolling = 10000
results = [die_1.roll() * die_2.roll() for roll_number in range(num_rolling)]

max_result = die_1.num_sides * die_2.num_sides

frequencies = [results.count(value) for value in range(1, max_result + 1)]

x_values = list(range(1, max_result + 1))
data = [Bar(x = x_values, y = frequencies)]

x_axis_config = {'title': 'result', 'dtick': 1}
y_axis_config = {'title': 'frequency of result'}
my_layout = Layout(title = f'results of rolling two d8 {num_rolling} times', xaxis = x_axis_config, yaxis = y_axis_config)
offline.plot({'data': data, 'layout': my_layout}, filename = 'd8_d8.html')
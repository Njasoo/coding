import numpy as np
import time
import sys
import tkinter as tk
import random
import numpy as np
import pandas as pd
pixel_unit = 80  # 像素
maze_height = 6  # 迷宫高度
maze_weight = 6  # 迷宫宽度


class Grid_Paint(tk.Tk, object):
    def __init__(self):
        super(Grid_Paint, self).__init__()
        # 初始化动作指令
        self.action_space = ['u', 'd', 'l', 'r']
        # 方便之后用0，1，2，3代表上下左右
        self.n_actions = len(self.action_space)
        self.title('Grid_Paint')
        # 设置窗口的宽和高
        self.geometry('{0}x{1}'.format(maze_height * pixel_unit, maze_weight * pixel_unit))
        # 调用构建迷宫函数来搭建迷宫
        self._build_maze()

    # 创造黑色的正方形方块
    # 输入分别为【一个网格的相对中心位置】，【障碍的横坐标】，【障碍的纵坐标】
    def creat_barrier(self, origin, x, y):
        # 计算出方块的中心位置
        center = origin + np.array([pixel_unit * x, pixel_unit * y])
        # 以该中心位置向四周进行黑色填充生成黑色方块
        self.barrier = self.canvas.create_rectangle(center[0] - 25, center[1] - 25, center[0] + 25, center[1] + 25,
                                                    fill='black')
        return self.barrier

    # 构建迷宫
    def _build_maze(self):
        # 画出白色背景
        self.canvas = tk.Canvas(self, bg='white', height=maze_height * pixel_unit, width=maze_weight * pixel_unit)

        # 通过画线来构建网格
        for c in range(0, maze_weight * pixel_unit, pixel_unit):
            x0, y0, x1, y1 = c, 0, c, maze_height * pixel_unit
            self.canvas.create_line(x0, y0, x1, y1)
        for r in range(0, maze_height * pixel_unit, pixel_unit):
            x0, y0, x1, y1 = 0, r, maze_weight * pixel_unit, r
            self.canvas.create_line(x0, y0, x1, y1)

        # 每个网格的相对中心位置
        origin = np.array([int(0.5 * pixel_unit), int(0.5 * pixel_unit)])

        # 创造障碍 黑色方块
        self.barrier1 = self.creat_barrier(origin, 0, 1)
        self.barrier2 = self.creat_barrier(origin, 2, 3)
        self.barrier3 = self.creat_barrier(origin, 3, 5)
        self.barrier4 = self.creat_barrier(origin, 3, 4)
        self.barrier5 = self.creat_barrier(origin, 5, 1)
        self.barrier6 = self.creat_barrier(origin, 4, 0)

        # 创造陷阱 红色方块
        center = origin + np.array([pixel_unit * 2, pixel_unit * 0])
        self.trap = self.canvas.create_rectangle(center[0] - 25, center[1] - 25, center[0] + 25, center[1] + 25,
                                                 fill='red')

        # 迷宫中的开始位置 蓝色圆形
        center = origin + np.array([pixel_unit * 0, pixel_unit * 0])
        self.start = self.canvas.create_oval(center[0] - 25, center[1] - 25, center[0] + 25, center[1] + 25,
                                             fill='blue')

        # 创造终点 绿色圆形
        center = origin + np.array([pixel_unit * 5, pixel_unit * 5])
        self.end = self.canvas.create_oval(center[0] - 25, center[1] - 25, center[0] + 25, center[1] + 25, fill='green')

        # 打包所有元素
        self.canvas.pack()

    # 重置玩家位置，使得每一次游戏结束后玩家回到初始位置便于下一轮游戏，即回到起始位置
    def reset(self):
        self.update()
        time.sleep(0.5)
        self.canvas.delete(self.start)
        origin = np.array([int(0.5 * pixel_unit), int(0.5 * pixel_unit)])
        center = origin + np.array([pixel_unit * 0, pixel_unit * 0])
        self.start = self.canvas.create_oval(center[0] - 25, center[1] - 25, center[0] + 25, center[1] + 25,
                                             fill='blue')
        self.update()
        return self.canvas.coords(self.start)

    # 玩家移动，输入为移动指令
    def step(self, action):
        # 记录当前的state，也就是玩家现在的位置，s是一个1x4的数组，分别代表其左上角像素位置，右上角像素位置，左下角像素位置，右下角像素位置
        s = self.canvas.coords(self.start)

        base_action = np.array([0, 0])
        # 向上
        if action == 0:
            base_action[1] -= pixel_unit
        # 向下
        elif action == 1:
            if s[1] < (maze_height - 1) * pixel_unit:
                base_action[1] += pixel_unit
        # 向右
        elif action == 2:
            if s[0] < (maze_weight - 1) * pixel_unit:
                base_action[0] += pixel_unit
        # 向左
        elif action == 3:
            if s[0] > pixel_unit:
                base_action[0] -= pixel_unit
        # 第一个参数是移动目标，第二个参数是到左上角的水平距离，第三个参数是距左上角的垂直距离。
        self.canvas.move(self.start, base_action[0], base_action[1])

        # 移动后的位置，也就是下一个state
        s_ = self.canvas.coords(self.start)

        # reward判断
        # 如果碰到了陷阱，游戏结束
        if s_ == self.canvas.coords(self.trap):
            reward = -15
            status = True
            s_ = 'End'
        # 如果碰到了障碍，游戏结束
        elif s_ == self.canvas.coords(self.barrier1) or s_ == self.canvas.coords(
                self.barrier2) or s_ == self.canvas.coords(self.barrier3) or s_ == self.canvas.coords(
                self.barrier4) or s_ == self.canvas.coords(self.barrier5) or s_ == self.canvas.coords(self.barrier6):
            reward = -5
            status = True
            s_ = 'End'
        # 如果到达了终点，则奖励为50，且游戏结束
        elif s_ == self.canvas.coords(self.end):
            reward = 25
            status = True
            s_ = 'End'
        # 如果都没有碰到，则游戏继续，但是奖励为-1，代表移动的步数，否则无法去寻找最低步数
        else:
            reward = -1
            status = False

        # 返回state s在经过action之后的下一个state s_，获得的奖励 reward，以及此时游戏状态 status
        return s_, reward, status

    def render(self):
        time.sleep(0.1)
        self.update()


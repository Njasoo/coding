import numpy as np
import time
import sys
import tkinter as tk
import random
import numpy as np
import pandas as pd


class QLearning:

    # 初始化，包括action列表，学习率，衰弱率，贪婪程度，以及Q-table
    def __init__(self, actions, alpha=0.01, gamma=0.9, epsilon=0.9):
        self.actions = actions
        self.alpha = alpha
        self.gamma = gamma
        self.epsilon = epsilon
        act = len(actions)
        self.q_table = pd.DataFrame(columns=self.actions, dtype=np.float32)

        # 选择action，输入参数为当前的state，输出的为在当前state的下一步action

    def choose_action(self, s):
        self.check_state_exist(s)
        # 首先判断该state在Q-table中是否存在，如果不存在则加入到Q-table

        # action 选择
        if np.random.rand() < self.epsilon:
            # 贪婪模式
            # 挑选最佳的action
            action = np.random.choice(self.actions)
            # 如果有多个action的value值都是最大，那就从这些中随机挑选

        # 非贪婪，探索模式
        # 随机挑选action
        else:
            state_action = self.q_table.loc[s, :]
            state_action = state_action.reindex(np.random.permutation(state_action.index))
            action = state_action.idxmax()
        return action

    # 学习以此不断更新Q-table，输入参数为一个state，做出的动作a，收获的奖励r，下一个state s_
    def learn(self, s, a, r, s_):
        # 首先判断下一个state s_在Q-table中是否存在，如果不存在则加入到Q-table
        self.check_state_exist(s_)

        # 先从Q-table中查询到Q(s,a)
        q_predict = self.q_table.loc[s, a]

        if s_ != 'End':  # 下个 state 不是 终止符
            q_target = r + self.gamma * self.q_table.loc[s_, :].max()
        else:
            q_target = r

        self.q_table.loc[s, a] += self.lr * (q_target - q_predict)

    # 检查state是否存在，输入为要检查的state
    def check_state_exist(self, s):
        if s not in self.q_table.index:
            # 插入一组全 0 数据
            self.q_table = self.q_table.append(
                pd.Series(
                    [0] * len(self.actions),
                    index=self.q_table.columns,
                    name=s,
                )
            )

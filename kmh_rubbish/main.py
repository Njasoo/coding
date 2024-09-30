# 应用上面实现的两个类
import env
import q_learning
grid = env.Grid_Paint()
RL = q_learning.QLearning(actions=list(range(grid.n_actions)))
EPOCH = 100
right = 0
wrong = 0
grid.mainloop()
for episode in range(EPOCH):
    print(episode)
    # 初始化玩家位置
    s = grid.reset()
    # 开始走迷宫
    while True:
        grid.render()

        # 基于当前状态s确定下一步的action
        action = RL.choose_action(str(s))

        # 当前state在采取行动a后的下一个state s_,获得的奖励 r，当前游戏状态status
        s_, reward, status = grid.step(action)

        # 开始学习，更新Q-table
        RL.learn(str(s), action, reward, str(s_))

        # 将这一轮的s替换为s_,作为下一次的state s
        s = s_

        # 如果当前游戏状态结束，则跳出循环结束此次迭代，并根据本次结果记录是成功还是失败
        if s == 'End':
            if s_ == grid.canvas.coords(grid.end):
                right += 1
            else:
                wrong += 1
            break

# 输出结果
print("right = ", right, "\nwrong = ", wrong)
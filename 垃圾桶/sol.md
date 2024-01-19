
$$
Z = \bar{Q_2} \bar{x_1}\\
T_1 = x_2 \quad T_2 = Q_1x_2\bar{x_1}
$$

所以这是一个Mealy型电路

次态真值表
输入<br>$x_2 \quad x_1$|现态<br>$Q_2\quad Q_1$|激励函数<br>$T_2 \quad T_1$|次态<br> $Q_2^{n+1} \quad Q_1^{n+1}$|输出<br>$Z$
---|---|---|---|---
$0 \quad 0$ | $0 \quad 0$ | $0 \quad 0$ | $0 \quad 0$ | 1
$0 \quad 0$ | $0 \quad 1$ | $0 \quad 0$ | $0 \quad 1$ | 1
$0 \quad 0$ | $1 \quad 0$ | $0 \quad 0$ | $1 \quad 0$ | 0
$0 \quad 0$ | $1 \quad 1$ | $0 \quad 0$ | $1 \quad 1$ | 0
$0 \quad 1$ | $0 \quad 0$ | $0 \quad 0$ | $0 \quad 0$ | 0
$0 \quad 1$ | $0 \quad 1$ | $0 \quad 0$ | $0 \quad 1$ | 0 
$0 \quad 1$ | $1 \quad 0$ | $0 \quad 0$ | $1 \quad 0$ | 0 
$0 \quad 1$ | $1 \quad 1$ | $0 \quad 0$ | $1 \quad 1$ | 0
$1 \quad 0$ | $0 \quad 0$ | $0 \quad 1$ | $0 \quad 1$ | 1
$1 \quad 0$ | $0 \quad 1$ | $1 \quad 1$ | $1 \quad 0$ | 1
$1 \quad 0$ | $1 \quad 0$ | $0 \quad 1$ | $1 \quad 1$ | 0
$1 \quad 0$ | $1 \quad 1$ | $1 \quad 1$ | $0 \quad 0$ | 0
$1 \quad 1$ | $0 \quad 0$ | $0 \quad 1$ | $0 \quad 1$ | 0
$1 \quad 1$ | $0 \quad 1$ | $0 \quad 1$ | $0 \quad 0$ | 0
$1 \quad 1$ | $1 \quad 0$ | $0 \quad 1$ | $1 \quad 1$ | 0
$1 \quad 1$ | $1 \quad 1$ | $0 \quad 1$ | $1 \quad 0$ | 0
















































































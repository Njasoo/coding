#ifndef LOCAL
#define debug printf
#else
#define debug(...) 
#endif

#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

int row_length[10] = {0, 5, 6, 7, 8, 9, 8, 7, 6, 5};
int col_length[10] = {0, 5, 6, 7, 8, 9, 8, 7, 6, 5};
int dig_length[15] = {0, 0, 0, 0, 0, 0, 5, 6, 7, 8, 9, 8, 7, 6, 5};
int screen_row_index[20][105];
char screen[105][105]; // 蜂窝数独的图像面板
int f[10][10]; // 蜂窝数独的逻辑面板
int random_switch; // 随机选取文件的开关
int dont_change[105][105]; // 标记初盘已经存在的点

// 编码方式ijn -> i * 100 + j * 10 + n, 1代表true, -1代表false
// ijn表示f[i][j]填入n, -ijn表示f[i][j]不填入n
int bool_value[100005]; // 记录变量正负值
int frequency[100005]; // 记录变量(不包含负值)出现频次, 所以其实是正负值频次之和
int possitive_frequency[100005]; // 正值变量频次
int negative_frequency[100005]; // 负值变量频次
int chosen_element[105]; // 记录选填数字
int vis[1005]; // 从区间里面选择选填数字时的标记
int g_num_clause; // 记录生成的子句句数
int g_num_var;
char g_cnf_string[1000005];
char temp_cnf_string[1000005];
int hs[105][105]; // 列坐标的映射
int game_start; // 检测游戏是否开始
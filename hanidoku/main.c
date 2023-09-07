#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "ClauseHead.h"
#include "dpll.h"

// #ifndef LOCAL
// #define debug printf
// #else
// #define debug(...) 
// #endif

// #define max(a, b) a > b ? a : b
// #define min(a, b) a < b ? a : b

// int row_length[10] = {0, 5, 6, 7, 8, 9, 8, 7, 6, 5};
// int col_length[10] = {0, 5, 6, 7, 8, 9, 8, 7, 6, 5};
// int dig_length[15] = {0, 0, 0, 0, 0, 0, 5, 6, 7, 8, 9, 8, 7, 6, 5};
// int screen_row_index[20][105];
// char screen[105][105]; // 蜂窝数独的图像面板
// int f[10][10]; // 蜂窝数独的逻辑面板
// int random_switch; // 随机选取文件的开关

// // 编码方式ijn -> i * 100 + j * 10 + n, 1代表true, -1代表false
// // ijn表示f[i][j]填入n, -ijn表示f[i][j]不填入n
// int bool_value[100005]; // 记录变量正负值
// int frequency[100005]; // 记录变量(不包含负值)出现频次, 所以其实是正负值频次之和
// int possitive_frequency[100005]; // 正值变量频次
// int negative_frequency[100005]; // 负值变量频次
// int chosen_element[105]; // 记录选填数字
// int vis[1005]; // 从区间里面选择选填数字时的标记
// int g_num_clause;
// int g_num_var;
// char g_cnf_string[1000005];
// char temp_cnf_string[1000005];
// int hs[105][105]; // 列坐标的映射

// typedef struct Location {
//     int x, y;
// } Location;
// Location hs2[105][105];

// typedef struct InterVal { // 数独每行每列可能选取的选填区间
//     int l, r;
// } InterVal;
// InterVal intervals[1005];
// int intervals_index;

// // 子句的头结点定义
// typedef struct ClauseHead {
//     int size; // 子句的变量个数
//     struct ClauseHead* next; // 连接到下一个子句
//     struct VarNode* var_list; // 子句里面的变量
// } ClauseHead;

// // ClauseHead* recycle_bin[100005]; // 存储DPLL过程中删掉的子句
// // int recycle_bin_index;
// int free_VarNode_in_ClauseHead(ClauseHead** node);

// // 子句的变量结点
// typedef struct VarNode {
//     int value;
//     struct VarNode* next;
// } VarNode;

// int VarNode_init(VarNode** node) {
//     // debug("enter VarNode_init\n");
//     // 创建新的结点并且初始化, 然后插入到当前链表尾端, 并且返回尾端结点以便于操作
//     assert(!(*node));
//     // if (*node) { // 已经被初始化
//     //     printf("VarNode_init: 0\n"); // 理论上程序中不应该返回0
//     //     return 0;
//     // }
//     *node = (VarNode*) malloc(sizeof(VarNode));
//     (*node)->next = NULL;
//     (*node)->value = 0;
//     // debug("VarNode_init: 1\n");
//     return 1;
// }

// int VarNode_length(VarNode* node) {
//     int length = 0;
//     VarNode* p = node;
//     while (p) {
//         length++;
//         p = p->next;
//     }
//     return length;
// }

// int VarNode_print(VarNode* node) {
//     debug("enter VarNode_print\n");
//     if (node == NULL) {
//         debug("node is empty!\n");
//         debug("VarNode_print: 0\n");
//         return 0;
//     }
//     VarNode* p = node;
//     while (p) {
//         printf("%d ", p->value);
//         p = p->next;
//     }
//     printf("\n");
//     debug("VarNode_print: 1\n");
//     return 1;
// }

// int VarNode_find(VarNode* node, int value) { // 查找变量链表中是否含有value这个变量
//     // debug("enter VarNode_find\n");
//     VarNode* p = node;
//     while (p) {
//         if (p->value == value) {
//             // debug("VarNode_find: 1\n");
//             return 1; // 找到
//         }
//         p = p->next;
//     }
//     // debug("VarNode_find: 0\n");
//     return 0; // 找不到
// }

// int VarNode_push(VarNode** head, VarNode* node) { // 插入新的VarNode带链表尾端
//     // debug("enter VarNode_push\n");
//     if (*head == NULL) {
//         *head = node;
//         // debug("VarNode_push: 1\n");
//         return 1;
//     }
//     VarNode* p = *head;
//     while (p->next) {
//         p = p->next;
//     }
//     p->next = node;
//     // debug("VarNode_push: 1\n");
//     return 1;
// }

// int VarNode_delete(VarNode** node, int value) { // 删掉变量值为value的结点
//     debug("enter VarNode_delete\n");
//     VarNode* p = (*node);
//     int cnt = 0; // 记录一下删除了多少个结点
//     // value可能不止一个, 所以需要while循环删除
//     assert(*node);
//     while (p) {
//         if (p->value == value) {
//             *node = (*node)->next;
//             // VarNode_print(*node);
//             debug("deleted1, p->value: %d\n", p->value);
//             // VarNode_print(*node);
//             free(p);
//             // p = NULL;
//             cnt++;
//             p = *node; // 指向新的头结点
//         } else {
//             break; // 第一个不需要删除了, 退出循环
//         }
//     }
//     if (!(*node)) { // 删完了, 头结点为空, 不需要再删
//         debug("\n");
//         debug("VarNode_delete: %d\n", cnt);
//         return cnt;
//     }
//     // 删除的是中间的结点
//     p = (*node)->next;
//     VarNode* pre = (*node);
//     while (p) {
//         VarNode* nex = p->next;
//         if (p->value == value) {
//             // VarNode_print(*node);
//             debug("deleted2, p->value: %d\n", p->value);
//             pre->next = nex;
//             // VarNode_print(*node);
//             free(p);
//             cnt++;
//             p = nex;
//             continue; // pre不需要改变
//         }
//         pre = p;
//         p = nex;
//     }
//     // debug("\n");
//     debug("VarNode_delete: %d\n", cnt);
//     return cnt;
// }

// int ClauseHead_init(ClauseHead** node) {
//     // debug("enter ClauseHead_init\n");
//     assert(!(*node)); // 保证结点为空
//     // if (*node) { // 结点不为空
//     //     debug("ClauseHead_init: 0\n");
//     //     return 0;
//     // }
//     *node = (ClauseHead*) malloc(sizeof(ClauseHead));
//     (*node)->var_list = NULL;
//     (*node)->next = NULL;
//     (*node)->size = 0; // 子句变量数初始化为0
//     // debug("ClauseHead_init: 1\n");
//     return 1;
// }

// int ClauseHead_push(ClauseHead** list, ClauseHead* node) {
//     // 不带头结点的链表, 所以第一个结点可能为空, 否则找到最后一个结点, 插入新节点到尾部
//     // debug("enter ClauseHead_push\n");
//     if (*list == NULL) {
//         (*list) = node;
//         debug("ClauseHead_push: 1\n");
//         return 1;
//     }
//     ClauseHead* p = (*list);
//     while (p->next) {
//         p = p->next;
//     }
//     p->next = node;
//     // debug("ClauseHead_push: 1\n");
//     return 1;
// }

// int ClauseHead_delete(ClauseHead** node, int value) { // 删除子句含有value这个变量的子句
//     debug("enter ClauseHead_delete\n");
//     ClauseHead* p = *node;
//     // 删掉第一个结点的情况
//     while (p) { // 可能需要不断地删除第一个结点, 所以使用while
//         int need_to_delete = VarNode_find(p->var_list, value);
//         if (!need_to_delete) {
//             break;
//         } else {
//             ClauseHead* pre_head = (*node); // 记录当前头结点
//             *node = (*node)->next;
//             p = *node; // 当前指针指向新的头结点
//             free_VarNode_in_ClauseHead(&pre_head); // 先把子句里的所有变量结点free掉
//             free(pre_head);
//             pre_head = NULL;
//             // recycle_bin[++recycle_bin_index] = pre_head;
//         }
//     }
//     // 是否被删完了
//     if ((*node) == NULL) {
//         debug("ClauseHead_delete: 1\n");
//         return 1;
//     }
//     // 删除中间的结点的情况
//     ClauseHead* pre = (*node); // 创建前驱结点以便于删除当前结点
//     ClauseHead* cur = (*node)->next;
//     while (cur) {
//         int need_to_delete = VarNode_find(cur->var_list, value); // 是否需要删除
//         if (!need_to_delete) {
//             pre = cur;
//             cur = cur->next;
//             continue;
//         }
//         ClauseHead* nex = cur->next;
//         pre->next = nex;
//         free_VarNode_in_ClauseHead(&cur);
//         free(cur);
//         cur = NULL;
//         // recycle_bin[++recycle_bin_index] = cur;
//         cur = nex; // 不需要指向NULL了, 直接指向下一个结点
//     }
//     debug("ClauseHead_delete: 1\n");
//     return 1;
// }

// ClauseHead* ClauseHead_copy(ClauseHead* node) { // 拷贝一份新的子句集
//     // debug("enter ClauseHead_copy\n");
//     ClauseHead* new_node = NULL;
//     ClauseHead* cur_node = node;
//     while (cur_node) {
//         ClauseHead* new_ClauseHead_node = NULL;
//         ClauseHead_init(&new_ClauseHead_node);
//         new_ClauseHead_node->size = cur_node->size;
//         VarNode* pp = cur_node->var_list;
//         while (pp) {
//             VarNode* new_VarNode = NULL;
//             VarNode_init(&new_VarNode);
//             new_VarNode->value = pp->value;
//             VarNode_push(&(new_ClauseHead_node->var_list), new_VarNode);
//             // new_ClauseHead_node->size++; // 每push一个新的VarNode, ClauseHead的size就会增加1 // 没有必要这句话
//             pp = pp->next;
//         }
//         ClauseHead_push(&new_node, new_ClauseHead_node);
//         cur_node = cur_node->next;
//     }
//     // debug("ClauseHead_copy: 1\n");
//     return new_node;
// }

// // ClauseHead* ClauseHead_init(ClauseHead** node) { // 创建新的子句结点并初始化, 插入到链表末端
// //     ClauseHead* new_ClauseHead = (ClauseHead*) malloc(sizeof(ClauseHead));
// //     ClauseHead* p = *node;
// //     new_ClauseHead->next = NULL;
// //     new_ClauseHead->var_list = NULL;
// //     new_ClauseHead->size = -1; // 子句变元数初始化为-1
// //     if (*node == NULL) { // 不带头节点
// //         *node = new_ClauseHead;
// //         return new_ClauseHead;
// //     }
// //     while (p->next) {
// //         p = p->next;
// //     }
// //     p->next = new_ClauseHead;
// //     return new_ClauseHead; // 返回当前插入的最新结点
// // }

// ClauseHead* isUnitClause(ClauseHead* node) { // 判断是否单子句
//     // debug("enter isUnitClause\n");
//     ClauseHead* p = node;
//     while (p) {
//         if (p->size == 1) {
//             debug("isUnitClause: finded\n");
//             return p;
//         }
//         p = p->next;
//     }
//     // debug("isUnitClause: NULL\n");
//     return NULL; // 找不到单子句
// }

// int free_VarNode_in_ClauseHead(ClauseHead** node) { // 将子句中的每一个变量释放
//     // debug("enter free_VarNode_in_ClauseHead\n");
//     VarNode* p = (*node)->var_list;
//     while (p) {
//         VarNode* nex = p->next;
//         free(p);
//         p = nex;
//     }
//     // debug("free_VarNode_in_ClauseHead: 1\n");
//     return 1;
// }

// int print_CNF(ClauseHead* head) {
//     ClauseHead* p = head;
//     while (p) {
//         debug("size: %d\n", p->size);
//         VarNode* pp = p->var_list;
//         while (pp) {
//             debug("pp->value: %d ", pp->value);
//             pp = pp->next;
//         }
//         debug("\n");
//         p = p->next;
//     }
//     // debug("printf_CNF: 1\n");
//     return 1;
// }

// int FULL_length(ClauseHead* head) {
//     ClauseHead* p = head;
//     long long cnt = 0;
//     while (p) {
//         cnt += p->size;
//         p = p->next;
//     }
//     return cnt;
// }

// // 简化子句集
// // 操作1: 判断子句集中是否有子句含有unit_value这个变量, 是则删除整个子句
// // 操作2: 删除子句集中-unit_value这个变量
// int simplification(ClauseHead** head, int unit_value) {
//     debug("enter simplification\n");
//     debug("hi1\n");
//     // 因为如果存在单子句, 则单子句里面的唯一变量必然为true, 所以整个子句可以删掉
//     ClauseHead_delete(head, unit_value);
//     debug("hi2\n");
//     // -unit必然为false, 所以删掉所有子句里面的-unit变量
//     ClauseHead* p = *head;
//     while (p) {
//         if (p->var_list && VarNode_find(p->var_list, -unit_value) == 1) {
//             int cnt = VarNode_delete(&(p->var_list), -unit_value);
//             p->size -= cnt; // 减去删除掉的结点个数
//             debug("p->size: %d, length of var_list: %d\n", p->size, VarNode_length(p->var_list));
//             // if (p->size != VarNode_length(p->var_list)) {
//             //     assert(0);
//             // }
//         }
//         // debug("hi\n");
//         p = p->next;
//     }
//     debug("simplification: 1\n");
//     return 1;
// }

// int existEmptyClause(ClauseHead* node) { // 查找是否存在空子句
//     // 看子句的size是否为0
//     debug("enter existEmptyClause\n");
//     ClauseHead* p = node;
//     while (p) {
//         if (p->size == 0) {
//             debug("existEmptyClause: 1\n");
//             return 1;
//         }
//         p = p->next;
//     }
//     debug("existEmptyClause: 0\n");
//     return 0;
// }

// // 选择出现频次最多的变量来赋值, 这样也许能够使子句集的长度缩小速度快一点
// // 然后再根据正值和负值的出现频次, 选择频次较高的作为优化
// int choose_unit_value(ClauseHead* node) {
//     debug("enter choose_unit_value\n");
//     int max_frequency = 0, most_frequent_value = 0;
//     ClauseHead* p = node;
//     while (p) {
//         VarNode* pp = p->var_list;
//         while (pp) {
//             if (frequency[abs(pp->value)] > max_frequency) { // 注意这里frequency统计的是正值
//                 max_frequency = frequency[pp->value];
//                 most_frequent_value = abs(pp->value);
//             }
//             pp = pp->next;
//         }
//         p = p->next;
//     }
//     if (possitive_frequency[most_frequent_value] > negative_frequency[most_frequent_value]) {
//         debug("choose_unit_value: %d\n", most_frequent_value);
//         return most_frequent_value;
//     } else {
//         debug("choose_unit_value: %d\n", -most_frequent_value);
//         return -most_frequent_value;
//     }
// }

// int add_unit_as_clause(ClauseHead** head, int unit_value) {
//     debug("enter add_unit_as_clause\n");
//     ClauseHead* new_ClauseHead_node = NULL;
//     ClauseHead_init(&new_ClauseHead_node);
//     new_ClauseHead_node->size = 1;
//     VarNode* new_VarNode = NULL;
//     VarNode_init(&new_VarNode);
//     new_VarNode->value = unit_value;
//     VarNode_push(&new_ClauseHead_node->var_list, new_VarNode);
//     ClauseHead_push(head, new_ClauseHead_node);
//     debug("add_unit_as_clause: 1\n");
//     return 1;
// }

// int tot;
// long long max_len;

// // long long max(long long a, long long b) {
// //     if (a > b) return a;
// //     return b;
// // }

// int DPLLsolve(ClauseHead** node) {
//     tot++;
//     debug("enter DPLLsolve\n");
//     ClauseHead* p = NULL;
//     int unit_value = 0;
//     // debug("*node: ");
//     // print_CNF(*node);
//     while ((p = isUnitClause(*node)) != NULL) { // 当子句集中存在单子句的时候
//         // print_CNF(*node);
//         assert(p);
//         debug("p->size: %d\n", p->size);
//         debug("length_of_var_list: %d\n", VarNode_length(p->var_list));
//         // printf("p->size: %d\n", p->size);
//         // printf("length_of_var_list: %d\n", VarNode_length(p->var_list));
//         // if (p->size != VarNode_length(p->var_list)) {
//         //     assert(0);
//         // }
//         assert(p->var_list);
//         unit_value = p->var_list->value; // var_list也就一个结点
//         bool_value[abs(unit_value)] = unit_value > 0 ? 1 : -1;
//         simplification(node, unit_value);
//         if (*node == NULL) {
//             debug("DPLLsolve: 1\n");
//             return 1; // 说明所有条件都已满足
//         } else if (existEmptyClause(*node)) { // 如果存在空子句, 那么这个空子句的值再不可能为true, 所以无解
//             debug("DPLLsolve: 0\n");
//             return 0;
//         }
//     }
//     unit_value = choose_unit_value(*node);
//     debug("unit_value: %d\n", unit_value);
//     bool_value[abs(unit_value)] = unit_value > 0 ? 1 : -1; // 第一个赋值选择, 正值为true, 赋值为false
//                                                             // 关键是正值为true的时候, 就已经可以知道这一个格子填什么数字, 所以先走这一条路
//     ClauseHead* original_copy1 = ClauseHead_copy(*node);
//     // max_len = max(FULL_length(original_copy1), max_len);
//     // debug("original_copy1:\n");
//     // print_CNF(original_copy1);
//     add_unit_as_clause(&original_copy1, unit_value); // 将变量作为单子句加入子句集中, 然后递归地解决这个问题
//     // debug("original_copy1(after adding unite_clause): \n");
//     // print_CNF(original_copy1);
//     if (DPLLsolve(&original_copy1)) {
//         // debug("DPLLsolve: 1\n");
//         return 1;
//     }
//     // int pre_last_index = recycle_bin_index;
//     // if (DPLLsolve(node)) {
//     //     return 1;
//     // }
//     // 选择1失败, 将变量反过来赋值
//     ClauseHead* original_copy2 = ClauseHead_copy(*node);
//     // for (int i = pre_last_index + 1; i <= recycle_bin_index; i++) {
//     //     ClauseHead_push(node, recycle_bin[i]);
//     // }
//     // recycle_bin_index = pre_last_index;
//     bool_value[abs(unit_value)] = unit_value < 0 ? -1 : 1; // 负值为true
//     // add_unit_as_clause(&original_copy2, -unit_value);
//     add_unit_as_clause(&original_copy2, -unit_value);
//     // max_len = max(FULL_length(original_copy2), max_len);
//     // return DPLLsolve(&original_copy2);
//     // int res = DPLLsolve(&original_copy2);
//     int res = DPLLsolve(&original_copy2);
//     if (res) {
//         debug("DPLLsolve: 1\n");
//     } else {
//         debug("DPLLsolve: 0\n");
//     }
//     return res;
// }

// int global_init() {
//     debug("enter global_init\n");
//     for (int i = 0; i < 10005; i++) {
//         frequency[i] = 0;
//         possitive_frequency[i] = 0;
//         negative_frequency[i] = 0;
//         bool_value[i] = 0;
//     }
//     for (int i = 1; i <= 5; i++) {
//         for (int j = 6 - i; j <= 9; j++) {
//             hs[i][j] = j - (9 - row_length[i]);
//         }
//     }
//     for (int i = 6; i <= 9; i++) {
//         for (int j = 1; j <= 14 - i; j++) {
//             hs[i][j] = j;
//         }
//     }
//     strcpy(screen[0], "         / \\ / \\ / \\ / \\ / \\");
//     strcpy(screen[1], "        | . | . | . | . | . |");
//     strcpy(screen[2], "       / \\ / \\ / \\ / \\ / \\ / \\");
//     strcpy(screen[3], "      | . | . | . | . | . | . |");
//     strcpy(screen[4], "     / \\ / \\ / \\ / \\ / \\ / \\ / \\");
//     strcpy(screen[5], "    | . | . | . | . | . | . | . |");
//     strcpy(screen[6], "   / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\");
//     strcpy(screen[7], "  | . | . | . | . | . | . | . | . |");
//     strcpy(screen[8], " / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\");
//     strcpy(screen[9], "| . | . | . | . | . | . | . | . | . |");
//     strcpy(screen[10], " \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / ");
//     strcpy(screen[11], "  | . | . | . | . | . | . | . | . |");
//     strcpy(screen[12], "   \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ /");
//     strcpy(screen[13], "    | . | . | . | . | . | . | . |");
//     strcpy(screen[14], "     \\ / \\ / \\ / \\ / \\ / \\ / \\ /");
//     strcpy(screen[15], "      | . | . | . | . | . | . |");
//     strcpy(screen[16], "       \\ / \\ / \\ / \\ / \\ / \\ /");
//     strcpy(screen[17], "        | . | . | . | . | . |");
//     strcpy(screen[18], "         \\ / \\ / \\ / \\ / \\ /");
//     hs2[1][1].y = 10;
//     hs2[2][1].y = 8;
//     hs2[3][1].y = 6;
//     hs2[4][1].y = 4;
//     hs2[5][1].y = 2;
//     hs2[6][1].y = 4;
//     hs2[7][1].y = 6;
//     hs2[8][1].y = 8;
//     hs2[9][1].y = 10;
//     for (int i = 1; i <= 9; i++) {
//         for (int j = 1; j <= row_length[i]; j++) {
//             hs2[i][j].x = 2 * i - 1;
//             hs2[i][j].y = hs2[i][1].y + 4 * (j - 1);
//         }
//     }
//     srand(time(NULL));
//     debug("hs2[1][1]: (%d, %d)\n", hs2[1][1].x, hs2[1][1].y);
//     debug("global_init: 1\n");
//     return 1;
// }

// int CNF_reader(char input_filename[], char output_filename[]) {
//     debug("enter CNF_reader\n");
//     FILE* fin = fopen(input_filename, "r");
//     if (!fin) {
//         printf("fail!\n");
//         debug("CNF_reader: -1\n");
//         return -1;
//     }
//     ClauseHead* head = NULL;
//     int num_word, num_clause; // 多少个文字, 多少个子句
//     fscanf(fin, "p cnf %d %d", &num_word, &num_clause);
//     for (int i = 0; i < num_clause; i++) {
//         int value;
//         ClauseHead* new_ClauseHead_node = NULL;
//         ClauseHead_init(&new_ClauseHead_node);
//         // debug("i: %d\n", i);
//         while (fscanf(fin, "%d", &value) != EOF) {
//             if (value == 0) break;
//             new_ClauseHead_node->size++;
//             // debug("new_ClauseHead_node->size == %d\n", new_ClauseHead_node->size);
//             VarNode* new_VarNode = NULL;
//             VarNode_init(&new_VarNode);
//             new_VarNode->value = value;
//             frequency[abs(value)]++;
//             if (value > 0) {
//                 possitive_frequency[value]++;
//             } else {
//                 negative_frequency[-value]++;
//             }
//             VarNode_push(&new_ClauseHead_node->var_list, new_VarNode);
//             assert(new_ClauseHead_node->var_list);
//         }
//         ClauseHead_push(&head, new_ClauseHead_node);
//     }
//     debug("head:\n");
//     print_CNF(head);
//     // int first_value;
//     // while (fscanf(fin, "%d", &first_value) != EOF) {
//     //     ClauseHead* new_ClauseHead_node = NULL;
//     //     ClauseHead_init(&new_ClauseHead_node);
//     //     new_ClauseHead_node->size = 1;
//     //     VarNode* temp_VarNode = NULL;
//     //     VarNode_init(&temp_VarNode);
//     //     temp_VarNode->value = first_value;
//     //     frequency[abs(first_value)]++;
//     //     if (first_value > 0) {
//     //         possitive_frequency[first_value]++;
//     //     } else {
//     //         negative_frequency[-first_value]++;
//     //     }
//     //     VarNode_push(&new_ClauseHead_node->var_list, temp_VarNode);
//     //     int value;
//     //     while (fscanf(fin, "%d", &value) != EOF) {
//     //         if (value == 0) break;
//     //         VarNode* new_VarNode = NULL;
//     //         VarNode_init(&new_VarNode);
//     //         new_VarNode->value = value;
//     //         new_ClauseHead_node->size++;
//     //         VarNode_push(&new_ClauseHead_node->var_list, new_VarNode);
//     //         frequency[abs(value)]++;
//     //         if (value > 0) possitive_frequency[value]++;
//     //         else negative_frequency[-value]++;
//     //     }
//     //     ClauseHead_push(&head, new_ClauseHead_node);
//     // }
//     // for (int i = 0; i <= 999; i++) {
//     //     if (frequency[i]) {
//     //         debug("frequency[%d]: %d ", i, frequency[i]);
//     //     }
//     // }
//     // debug("\n");
//     double start = clock();
//     FILE* fp = fopen(output_filename, "w");
//     if (!fp) {
//         debug("CNF_reader: 0\n");
//         return 0;
//     }
//     if (DPLLsolve(&head)) {
//         fprintf(fp, "1\n");
//         double end = clock();
//         double time_elapsed = end - start;
//         for (int i = 0; i < 100005; i++) {
//             if (bool_value[i]) {
//                 fprintf(fp, "%d ", bool_value[i] * i);
//             }
//         }
//         fprintf(fp, "\n");
//         fprintf(fp, "time elapsed: %.17lfms\n", time_elapsed);
//     } else {
//         fprintf(fp, "0\n");
//         fprintf(fp, "no solution!\n");
//         double end = clock();
//         double time_elapsed = end - start;
//         fprintf(fp, "time elapsed: %.17lfms\n", time_elapsed);
//     }
//     fclose(fin);
//     fclose(fp);
//     // printf("CNF_reader: 1\n");
//     return 1;
// }

void choose_element_from_each_interval_row(FILE* fout, int id, int pre_value, int row) { // 避免选择相同的子句, 所以选择的元素必须递增
    if (id == intervals_index + 1) {
        for (int i = 1; i <= id - 1; i++) {
            for (int j = 1; j <= row_length[row]; j++) {
                int value = row * 100 + j * 10 + chosen_element[i];
                // fprintf(fout, "%d ", value);
                char temp[15];
                sprintf(temp, "%d ", value);
                strcat(g_cnf_string, temp);
            }
        }
        strcat(g_cnf_string, "0\n");
        g_num_clause++;
        return;
    }
    for (int element = intervals[id].l; element <= intervals[id].r; element++) {
        // if (vis[element]) continue; // 避免选择相同的变量
        // vis[element] = 1;
        chosen_element[id] = element;
        choose_element_from_each_interval_row(fout, id + 1, element, row);
        // vis[element] = 0;
    }
}

void choose_element_from_each_interval_col(FILE* fout, int id, int pre_value, int col) {
    if (id == intervals_index + 1) {
        for (int j = 1; j <= id - 1; j++) {
            if (col <= 5) {
                for (int i = 6 - col; i <= 9; i++) {
                    int value = i * 100 + hs[i][col] * 10 + chosen_element[j];
                    char temp[15];
                    sprintf(temp, "%d ", value);
                    strcat(g_cnf_string, temp);
                }
            } else {
                for (int i = 1; i <= 14 - col; i++) {
                    int value = i * 100 + hs[i][col] * 10 + chosen_element[j];
                    char temp[15];
                    sprintf(temp, "%d ", value);
                    strcat(g_cnf_string, temp);
                }
            }
            // for (int i = 1; i <= 9; i++) {
            //     if (f[i][col] == -1) continue;
            //     int value = i * 100 + hs[i][col] * 10 + chosen_element[j];
            //     // fprintf(fout, "%d ", value);
            //     char temp[15];
            //     sprintf(temp, "%d ", value);
            //     strcat(g_cnf_string, temp);
            // }
        }
        // fprintf(fout, "0\n");
        strcat(g_cnf_string, "0\n");
        g_num_clause++;
        return;
    }
    for (int element = intervals[id].l; element <= intervals[id].r; element++) {
        // if (vis[element]) continue;
        // vis[element] = 1;
        chosen_element[id] = element;
        choose_element_from_each_interval_col(fout, id + 1, element, col);
        // vis[element] = 0;
    }
}

void choose_element_from_each_interval_dig(FILE* fout, int id, int pre_value, int sum) {
    if (id == intervals_index + 1) {
        for (int idx = 1; idx <= id - 1; idx++) {
            for (int i = 1; i <= 9; i++) {
                int j = sum - i;
                if (j <= 0) break;
                if (j > 9) continue;
                int value = i * 100 + hs[i][j] * 10 + chosen_element[idx];
                // fprintf(fout, "%d ", value);
                char temp[15];
                sprintf(temp, "%d ", value);
                strcat(g_cnf_string, temp);
            }
        }
        // fprintf(fout, "0\n");
        strcat(g_cnf_string, "0\n");
        g_num_clause++;
        return;
    }
    for (int element = intervals[id].l; element <= intervals[id].r; element++) {
        // if (vis[element]) continue;
        // vis[element] = 1;
        chosen_element[id] = element;
        choose_element_from_each_interval_dig(fout, id + 1, element, sum);
        // vis[element] = 0;
    }
}

int CNF_generator(char in_filename[], char out_filename[]) {
    FILE* fin = fopen(in_filename, "r");
    if (fin == NULL) {
        return 0;
    }
    memset(f, -1, sizeof(f));
    for (int i = 1; i <= 5; i++) {
        for (int j = 6 - i; j <= 9; j++) {
            fscanf(fin, "%d", &f[i][j]);
        }
    }
    for (int i = 6; i <= 9; i++) {
        for (int j = 1; j <= 14 - i; j++) {
            fscanf(fin, "%d", &f[i][j]);
        }
    }
    fclose(fin);
    FILE* fout = fopen(out_filename, "w");
    // 每个格子填且只能填一个数字
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= row_length[i]; j++) {
            for (int num1 = 1; num1 <= 9; num1++) {
                for (int num2 = num1 + 1; num2 <= 9; num2++) {
                    int value1 = i * 100 + j * 10 + num1;
                    int value2 = i * 100 + j * 10 + num2;
                    char temp[105];
                    sprintf(temp, "%d %d 0\n", -value1, -value2);
                    strcat(g_cnf_string, temp);
                    g_num_clause++;
                }
            }
        }
    }
    // 每个格子的可能性
    for (int i = 1; i <= 5; i++) {
        for (int j = 6 - i; j <= 9; j++) {
            for (int num = 1; num <= 9; num++) {
                int value = i * 100 + hs[i][j] * 10 + num;
                char temp[105];
                sprintf(temp, "%d ", value);
                strcat(g_cnf_string, temp);
            }
            strcat(g_cnf_string, "0\n");
            g_num_clause++;
        }
    }
    for (int i = 6; i <= 9; i++) {
        for (int j = 1; j <= 14 - i; j++) {
            for (int num = 1; num <= 9; num++) {
                int value = i * 100 + j * 10 + num;
                char temp[105];
                sprintf(temp, "%d ", value);
                strcat(g_cnf_string, temp);
            }
            strcat(g_cnf_string, "0\n");
            g_num_clause++;
        }
    }
    // 已经填上了的数字
    // 上半部分
    for (int i = 1; i <= 5; i++) {
        for (int j = 6 - i; j <= 9; j++) {
            if (f[i][j] != 0) {
                int value = i * 100 + (j - 5 + i) * 10 + f[i][j];
                // fprintf(fout, "%d 0\n", value);
                char temp[15];
                sprintf(temp, "%d 0\n", value);
                strcat(g_cnf_string, temp);
                g_num_clause++;
            }
        }
    }
    // 下半部分
    for (int i = 6; i <= 9; i++) {
        for (int j = 1; j <= 14 - i; j++) {
            if (f[i][j] != 0) {
                int value = i * 100 + j * 10 + f[i][j];
                char temp[15];
                // fprintf(fout, "%d 0\n", value);
                sprintf(temp, "%d 0\n", value);
                strcat(g_cnf_string, temp);
                g_num_clause++;
            }
        }
    }
    //// 行
    // 每一行的任意两个不能相等
    for (int i = 1; i <= 5; i++) { // 上梯形
        for (int j1 = 6 - i; j1 <= 9; j1++) {
            for (int j2 = j1 + 1; j2 <= 9; j2++) {
                for (int num = 1; num <= 9; num++) {
                    int value1 = i * 100 + (j1 - 5 + i) * 10 + num;
                    int value2 = i * 100 + (j2 - 5 + i) * 10 + num;
                    // fprintf(fout, "%d %d 0\n", -value1, -value2);
                    char temp[105];
                    sprintf(temp, "%d %d 0\n", -value1, -value2);
                    strcat(g_cnf_string, temp);
                    g_num_clause++;
                }
            }
        }
    }
    for (int i = 6; i <= 9; i++) {
        for (int j1 = 1; j1 <= 14 - i; j1++) {
            for (int j2 = j1 + 1; j2 <= 14 - i; j2++) {
                for (int num = 1; num <= 9; num++) {
                    int value1 = i * 100 + j1 * 10 + num;
                    int value2 = i * 100 + j2 * 10 + num;
                    // fprintf(fout, "%d %d 0\n", -value1, -value2);
                    char temp[105];
                    sprintf(temp, "%d %d 0\n", -value1, -value2);
                    strcat(g_cnf_string, temp);
                    g_num_clause++;
                }
            }
        }
    }
    // 每一行的选填, 首先就是找可能的区间
    // 上半部分
    for (int i = 1; i <= 5; i++) {
        // 找每一行的最大值和最小值
        int mx = 1;
        int mn = 9;
        for (int j = 6 - i; j <= 9; j++) {
            if (f[i][j] != 0) {
                mn = min(mn, f[i][j]);
                mx = max(mx, f[i][j]);
            }
        }
        intervals_index = 0;
        if (mn > mx) {
            for (int l = 1; l <= 9; l++) {
                int r = l + row_length[i] - 1;
                if (r > 9) break;
                intervals_index++;
                intervals[intervals_index].l = l;
                intervals[intervals_index].r = r;
            }
        } else {
            for (int l = 1; l <= 9; l++) {
                if (l > mn) break;
                int r = l + row_length[i] - 1;
                if (r > 9) break;
                if (l <= mn && r >= mx) {
                    intervals_index++;
                    intervals[intervals_index].l = l;
                    intervals[intervals_index].r = r;
                }
            }
        }
        // memset(vis, 0, sizeof(vis));
        debug("intervals_index: %d\n", intervals_index);
        choose_element_from_each_interval_row(fout, 1, 0, i);
    }
    // 下半部分
    for (int i = 6; i <= 9; i++) {
        int mx = 1;
        int mn = 9;
        for (int j = 1; j <= 14 - i; j++) {
            if (f[i][j] != 0) {
                mn = min(mn, f[i][j]);
                mx = max(mx, f[i][j]);
            }
        }
        intervals_index = 0;
        if (mn > mx) {
            for (int l = 1; l <= 9; l++) {
                int r = l + row_length[i] - 1;
                if (r > 9) break;
                intervals_index++;
                intervals[intervals_index].l = l;
                intervals[intervals_index].r = r;
            }
        } else {
            for (int l = 1; l <= 9; l++) {
                if (l > mx) break;
                int r = l + row_length[i] - 1;
                if (r > 9) break;
                if (l <= mn && mx <= r) {
                    intervals_index++;
                    intervals[intervals_index].l = l;
                    intervals[intervals_index].r = r;
                }
            }
        }
        // memset(vis, 0, sizeof(vis));
        choose_element_from_each_interval_row(fout, 1, 0, i);
    }
    //// 列(和行的情况几乎一样)
    for (int j = 1; j <= 5; j++) {
        for (int i1 = 6 - j; i1 <= 9; i1++) {
            for (int i2 = i1 + 1; i2 <= 9; i2++) {
                for (int num = 1; num <= 9; num++) {
                    int value1 = i1 * 100 + hs[i1][j] * 10 + num;
                    int value2 = i2 * 100 + hs[i2][j] * 10 + num;
                    // fprintf(fout, "%d %d 0\n", -value1, -value2);
                    char temp[105];
                    sprintf(temp, "%d %d 0\n", -value1, -value2);
                    strcat(g_cnf_string, temp);
                    g_num_clause++;
                }
            }
        }
    }
    for (int j = 6; j <= 9; j++) {
        for (int i1 = 1; i1 <= 14 - j; i1++) {
            for (int i2 = i1 + 1; i2 <= 14 - j; i2++) {
                for (int num = 1; num <= 9; num++) {
                    int value1 = i1 * 100 + hs[i1][j] * 10 + num;
                    int value2 = i2 * 100 + hs[i2][j] * 10 + num;
                    // fprintf(fout, "%d %d 0\n", -value1, -value2);
                    char temp[105];
                    sprintf(temp, "%d %d 0\n", -value1, -value2);
                    strcat(g_cnf_string, temp);
                    g_num_clause++;
                }
            }
        }
    }
    for (int j = 1; j <= 5; j++) {
        int mn = 9;
        int mx = 1;
        for (int i = 6 - j; i <= 9; i++) {
            if (f[i][j] != 0) {
                mn = min(mn, f[i][j]);
                mx = max(mx, f[i][j]);
            }
        }
        intervals_index = 0;
        if (mn > mx) {
            for (int l = 1; l <= 9; l++) {
                int r = l + col_length[j] - 1;
                if (r > 9) break;
                intervals_index++;
                intervals[intervals_index].l = l;
                intervals[intervals_index].r = r;
            }
        } else {
            for (int l = 1; l <= 9; l++) {
                if (l > mn) continue;
                int r = l + col_length[j] - 1;
                if (r > 9) continue;
                if (l <= mn && mx <= r) {
                    intervals_index++;
                    intervals[intervals_index].l = l;
                    intervals[intervals_index].r = r;
                }
            }
        }
        choose_element_from_each_interval_col(fout, 1, 0, j);
    }
    for (int j = 6; j <= 9; j++) {
        int mn = 9;
        int mx = 1;
        for (int i = 1; i <= col_length[j]; i++) {
            if (f[i][j] != 0) {
                mn = min(mn, f[i][j]);
                mx = max(mx, f[i][j]);
            }
        }
        intervals_index = 0;
        if (mx > mn) {
            for (int l = 1; l <= 9; l++) {
                int r = l + col_length[j] - 1;
                if (r > 9) break;
                intervals_index++;
                intervals[intervals_index].l = l;
                intervals[intervals_index].r = r;
            }
        } else {
            for (int l = 1; l <= 9; l++) {
                if (l > mn) break;
                int r = l + col_length[j] - 1;
                if (r > 9) break;
                if (l <= mn && mx <= r) {
                    intervals_index++;
                    intervals[intervals_index].l = l;
                    intervals[intervals_index].r = r;
                }
            }
        }
        choose_element_from_each_interval_col(fout, 1, 0, j);
    }
    // 对角线(行列坐标之和相等)
    for (int sum = 6; sum <= 14; sum++) {
        for (int i = 1; i <= 9; i++) {
            int j = sum - i;
            if (j <= 0 || j > 9) continue;
            for (int ii = 1; ii <= 9; ii++) {
                int jj = sum - ii;
                if (jj <= 0 || jj > 9) continue;
                if (i == ii && j == jj) continue;
                for (int num = 1; num <= 9; num++) {
                    int value1 = i * 100 + hs[i][j] * 10 + num;
                    int value2 = ii * 100 + hs[ii][jj] * 10 + num;
                    // fprintf(fout, "%d %d 0\n", -value1, -value2);
                    char temp[105];
                    sprintf(temp, "%d %d 0\n", -value1, -value2);
                    strcat(g_cnf_string, temp);
                    g_num_clause++;
                }
            }
        }
    }
    for (int sum = 6; sum <= 14; sum++) {
        int mn = 9;
        int mx = 1;
        for (int i = 1; i <= 9; i++) {
            int j = sum - i;
            if (j <= 0) break;
            if (j > 9) continue;
            if (f[i][j] != 0) {
                mn = min(mn, f[i][j]);
                mx = max(mx, f[i][j]);
            }
        }
        intervals_index = 0;
        if (mn > mx) {
            for (int l = 1; l <= 9; l++) {
                int r = l + dig_length[sum] - 1;
                if (r > 9) continue;
                intervals_index++;
                intervals[intervals_index].l = l;
                intervals[intervals_index].r = r;
            }
        } else {
            for (int l = 1; l <= 9; l++) {
                if (l > mn) continue;
                int r = l + dig_length[sum] - 1;
                if (r > 9) continue;
                if (l <= mn && mx <= r) {
                    intervals_index++;
                    intervals[intervals_index].l = l;
                    intervals[intervals_index].r = r;
                }
            }
        }
        debug("intervals_index: %d\n", intervals_index);
        choose_element_from_each_interval_dig(fout, 1, 0, sum);
    }
    // fclose(fin);
    fprintf(fout, "p cnf 549 %d\n", g_num_clause);
    fprintf(fout, "%s", g_cnf_string);
    fclose(fout);
    return 1;
}

int print_res(char filename[]) {
    FILE* fin = fopen(filename, "r");
    if (!fin) {
        printf("fail\n");
        return 0;
    }
    char ch;
    while ((ch = fgetc(fin)) != EOF) {
        putchar(ch);
    }
    system("pause");
    return 1;
}

void test01() {
    CNF_reader("matrix_1.cnf", "matrix_1.res");
}

void test02() {
    CNF_reader("problem_2.cnf", "problem_2.res");
}

void test03() {
    CNF_reader("problem_3.cnf", "problem_3.res");
}

void test04() {
    CNF_reader("ec-vda_gr_rcs_w9.shuffled-6498.cnf", "ec-vda_gr_rcs_w9.shuffled-6498.res");
}

void test05() {
    CNF_reader("problem_12.cnf", "problem_12.res");
}

void test06() {
    CNF_reader("eh-dp04s04.shuffled-1075.cnf", "eh-dp04s04.shuffled-1075.res");
}

void real_test01() {
    CNF_reader("1.cnf", "1.res");
    print_res("1.res");
}

void real_test02() {
    CNF_reader("2.cnf", "2.res");
    print_res("2.res");
}

void real_test03() {
    CNF_reader("3.cnf", "3.res");
    print_res("3.res");
}

void real_test04() {
    CNF_reader("4u.cnf", "4.res");
    print_res("4.res");
}

void real_test05() {
    CNF_reader("5.cnf", "5.res");
    print_res("5.res");
}

void real_test06() {
    CNF_reader("6.cnf", "6.res");
    print_res("6.res");
}

void real_test07() {
    CNF_reader("7u.cnf", "7.res");
    print_res("7.res");
}

void real_test08() {
    CNF_reader("8u.cnf", "8.res");
    print_res("8.res");
}

void real_test09() {
    CNF_reader("9u.cnf", "9.res");
    print_res("9.res");
}

void real_test10() {
    CNF_reader("10.cnf", "10.res");
    print_res("10.res");
}

void real_test11() {
    CNF_reader("11u.cnf", "11.res");
    print_res("11.res");
}

void real_test12() {
    CNF_reader("12.cnf", "12.res");
    print_res("12.res");
}

void CNF_translator(char in_filename[]) {
    FILE* fin = fopen(in_filename, "r");
    if (!fin) {
        return;
    }
    char ch = fgetc(fin);
    // debug("aaaaa %c\n", ch);
    ch = fgetc(fin);
    while (ch != EOF) {
        if (ch == 't') break;
        if (ch == '-') {
            for (int i = 1; i <= 4; i++) {
                ch = fgetc(fin);
            }
        } else if (ch == ' ' || ch == '\n') {
            ch = fgetc(fin);
        } else if (ch >= '0' && ch <= '9') {
            int cnt = ch - '0';
            // debug("cnt: %d ", cnt);
            for (int i = 1; i <= 2; i++) {
                ch = fgetc(fin);
                cnt = cnt * 10 + ch - '0';
                // debug("cnt: %d ", cnt);
            }
            // debug("\n");
            int row = cnt / 100 % 10;
            int col = cnt / 10 % 10;
            int num = cnt % 10;
            f[row][col] = num;
            ch = fgetc(fin);
        }
    }
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= row_length[i]; j++) {
            int x = hs2[i][j].x;
            int y = hs2[i][j].y;
            screen[x][y] = f[i][j] + '0';
            if (f[i][j] == 0) {
                screen[x][y] = '.';
            }
        }
    }
    // for (int i = 1; i <= 9; i++) {
    //     for (int j = 1; j <= row_length[i]; j++) {
    //         printf("%d ", f[i][j]);
    //     }
    //     printf("\n");
    // }
    fclose(fin);
}

void display(char in_filename[]) {
    // strcpy(screen[0], "         / \\ / \\ / \\ / \\ / \\");
    // strcpy(screen[1], "        | . | . | . | . | . |");
    // strcpy(screen[2], "       / \\ / \\ / \\ / \\ / \\ / \\");
    // strcpy(screen[3], "      | . | . | . | . | . | . |");
    // strcpy(screen[4], "     / \\ / \\ / \\ / \\ / \\ / \\ / \\");
    // strcpy(screen[5], "    | . | . | . | . | . | . | . |");
    // strcpy(screen[6], "   / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\");
    // strcpy(screen[7], "  | . | . | . | . | . | . | . | . |");
    // strcpy(screen[8], " / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\");
    // strcpy(screen[9], "| . | . | . | . | . | . | . | . | . |");
    // strcpy(screen[10], " \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / ");
    // strcpy(screen[11], "  | . | . | . | . | . | . | . | . |");
    // strcpy(screen[12], "   \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ /");
    // strcpy(screen[13], "    | . | . | . | . | . | . | . |");
    // strcpy(screen[14], "     \\ / \\ / \\ / \\ / \\ / \\ / \\ /");
    // strcpy(screen[15], "      | . | . | . | . | . | . |");
    // strcpy(screen[16], "       \\ / \\ / \\ / \\ / \\ / \\ /");
    // strcpy(screen[17], "        | . | . | . | . | . |");
    // strcpy(screen[18], "         \\ / \\ / \\ / \\ / \\ /");
    system("cls");
    // for (int i = 1; i <= 9; i++) {
    //     for (int j = 1; j <= row_length[i]; j++) {
    //         int x = hs2[i][j].x;
    //         int y = hs2[i][j].y;
    //         screen[x][y] = j + '0';
    //     }
    // }
    for (int i = 0; i <= 18; i++) {
        printf("%s\n", screen[i]);
    }
    printf("1. Load game\n");
    printf("2. Generate CNF\n");
    printf("3. Show CNF\n");
    printf("4. Start DPLL\n");
    printf("5. Show solution\n");
    printf("6. Input number\n");
    printf("7. Delete number\n");
    printf("8. exit\n");
    printf("9. check\n");
    int op;
    scanf("%d", &op);
    if (op == 1) {
        // char suffix[15];
        // strcpy(suffix, ".txt");
        // char now_in_filename[105];
        // strcpy(now_in_filename, in_filename);
        // strcat(now_in_filename, suffix);
        // FILE* fin = fopen(now_in_filename, "r");
        // for (int i = 1; i <= 9; i++) {
        //     for (int j = 1; j <= row_length[i]; j++) {
        //         int num;
        //         fscanf(fin, "%d", &num);
        //         int x = hs2[i][j].x;
        //         int y = hs2[i][j].y;
        //         if (num == 0) screen[x][y] = '.';
        //         else screen[x][y] = num + '0';
        //     }
        // }
        // fclose(fin);
        random_switch = 1;
    } else if (op == 2) {
        char suffix1[105];
        char suffix2[105];
        strcpy(suffix1, ".txt");
        strcpy(suffix2, ".cnf");
        char now_in_filename[105];
        strcpy(now_in_filename, in_filename);
        strcat(now_in_filename, suffix1);
        char now_out_filename[105];
        strcpy(now_out_filename, in_filename);
        strcat(now_out_filename, suffix2);
        // printf("%s %s\n", now_in_filename, now_out_filename);
        // assert(0);
        system("cls");
        printf("CNF is generating...\n");
        CNF_generator(now_in_filename, now_out_filename);
        printf("CNF generated successfully\n");
        system("pause");
        // char ch;
        // FILE* fin = fopen(now_out_filename, "r");
        // while ((ch = fgetc(fin)) != EOF) {
        //     putchar(ch);
        // }
        // system("pause");
        // fclose(fin);
    } else if (op == 3) {
        char suffix[15];
        strcpy(suffix, ".cnf");
        char now_in_filename[105];
        strcpy(now_in_filename, in_filename);
        strcat(now_in_filename, suffix);
        FILE* fin = fopen(now_in_filename, "r");
        char ch;
        while ((ch = fgetc(fin)) != EOF) {
            putchar(ch);
        }
        system("pause");
        fclose(fin);
    } else if (op == 4) {
        char suffix1[15];
        strcpy(suffix1, ".cnf");
        char suffix2[15];
        strcpy(suffix2, ".res");
        char now_in_filename[105];
        strcpy(now_in_filename, in_filename);
        strcat(now_in_filename, suffix1);
        char now_out_filename[105];
        strcpy(now_out_filename, in_filename);
        strcat(now_out_filename, suffix2);
        // printf("%s %s\n", now_in_filename, now_out_filename);
        // assert(0);
        system("cls");
        printf("DPLL is implementing...\n");
        CNF_reader(now_in_filename, now_out_filename);
        printf("DPLL implemented successfully\n");
        system("pause");
    } else if (op == 5) {
        char suffix[15];
        strcpy(suffix, ".res");
        char now_in_filename[105];
        strcpy(now_in_filename, in_filename);
        strcat(now_in_filename, suffix);
        CNF_translator(now_in_filename);
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= row_length[i]; j++) {
                int x = hs2[i][j].x;
                int y = hs2[i][j].y;
                screen[x][y] = f[i][j] + '0';
            }
        }
        display(in_filename);
        // random_switch = 1;
    } else if (op == 6) {
        printf("input row number: ");
        int row_number;
        scanf("%d", &row_number);
        printf("input column number: ");
        int col_number;
        scanf("%d", &col_number);
        int x = hs2[row_number][col_number].x;
        int y = hs2[row_number][col_number].y;
        printf("input number: ");
        int num;
        scanf("%d", &num);
        f[row_number][col_number] = num;
        screen[x][y] = f[row_number][col_number] == '0' ? '.' : f[row_number][col_number] + '0';
        display(in_filename);
    } else if (op == 7) {
        printf("input row number: ");
        int row_number;
        scanf("%d", &row_number);
        printf("input column number: ");
        int col_number;
        scanf("%d", &col_number);
        int x = hs2[row_number][col_number].x;
        int y = hs2[row_number][col_number].y;
        f[row_number][col_number] = 0;
        screen[x][y] = '.';
    } else if (op == 8) {
        system("cls");
        printf("bye bye\n");
        system("pause");
        exit(0);
    } else if (op == 9) {
        int g[10][10];
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= row_length[i]; j++) {
                g[i][j] = f[i][j];
            }
        }
        char suffix[15];
        strcpy(suffix, ".res");
        char now_in_filename[105];
        strcpy(now_in_filename, in_filename);
        strcat(now_in_filename, suffix);
        CNF_translator(now_in_filename);
        int flag = 1;
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= row_length[i]; j++) {
                if (g[i][j] != f[i][j]) {
                    flag = 0;
                }
            }
        }
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= row_length[i]; j++) {
                f[i][j] = g[i][j];
                int x = hs2[i][j].x;
                int y = hs2[i][j].y;
                screen[x][y] = (f[i][j] == 0 ? '.' : f[i][j] + '0');
            }
        }
        if (flag) {
            system("cls");
            printf("All correct\n");
            system("pause");
        } else {
            system("cls");
            printf("Wrong\n");
            system("pause");
        }
        display(in_filename);
    }
}

int main() {
    // real_test01(); // pass
    // real_test02(); // pass
    // real_test03(); // pass
    // real_test04(); // pass
    // real_test05(); // pass
    // real_test06(); // pass slow
    // real_test07(); // fail
    // real_test08(); // fail
    // real_test09(); // fail
    // real_test10(); // fail
    // real_test11(); // fail
    // real_test12(); // fail
    // test01();
    // CNF_generator("matrix_2.txt", "matrix_2.cnf");
    // CNF_reader("matrix_2.cnf", "matrix_2.res");
    // debug("hi\n");
    // CNF_translator("matrix_2.res");
    int random_number = 0;
    while (1) {
        global_init();
        system("cls");
        printf("1. Solve SAT\n");
        printf("2. Play game\n");
        int op;
        scanf("%d", &op);
        if (op == 1) {
            printf("input test number: ");
            int test;
            scanf("%d", &test);
            if (test == 1) {
                real_test01();
            } else if (test == 2) {
                real_test02();
            } else if (test == 3) {
                real_test03();
            } else if (test == 4) {
                real_test04();
            } else if (test == 5) {
                real_test05();
            } else if (test == 6) {
                real_test06();
            } else if (test == 7) {
                real_test07();
            } else if (test == 8) {
                real_test08();
            } else if (test == 9) {
                real_test09();
            } else if (test == 10) {
                real_test10();
            } else if (test == 11) {
                real_test11();
            } else if (test == 12) {
                real_test12();
            }
        } else {
            while (1) {
                global_init();
                char folder_name[105];
                strcpy(folder_name, "matrixs/");
                int range_l = 1, range_r = 20;
                if (random_switch == 1) {
                    random_number = rand() % (range_r - range_l + 1) + range_l;
                    random_switch = 0;
                }
                if (random_number == 0) {
                    display("matrixs/0");
                    continue;
                }
                char filename[105];
                if (random_number >= 10) {
                    filename[0] = random_number / 10 % 10 + '0';
                    filename[1] = random_number % 10 + '0';
                    filename[2] = '\0';
                } else {
                    filename[0] = random_number + '0';
                    filename[1] = '\0';
                }
                char real_filename[105];
                strcpy(real_filename, folder_name);
                strcat(real_filename, filename);
                char suffix[15];
                strcpy(suffix, ".txt");
                char now_in_filename[105];
                strcpy(now_in_filename, real_filename);
                strcat(now_in_filename, suffix);
                FILE* fin = fopen(now_in_filename, "r");
                for (int i = 1; i <= 9; i++) {
                    for (int j = 1; j <= row_length[i]; j++) {
                        int num;
                        fscanf(fin, "%d", &num);
                        f[i][j] = num;
                        int x = hs2[i][j].x;
                        int y = hs2[i][j].y;
                        if (num == 0) screen[x][y] = '.';
                        else screen[x][y] = num + '0';
                    }
                }
                display(real_filename);
            }
        }
    }
    // CNF_generator("matrixs/1.txt", "matrixs/1.cnf");
    // CNF_generator("matrixs/3.txt", "matrixs/3.cnf");
    // CNF_reader("matrixs/3.cnf", "matrixs/3.res");
    // CNF_translator("matrixs/2.res");
    // CNF_generator("matrixs/9.txt", "matrixs/9.cnf");
    // CNF_reader("matrixs/9.cnf", "matrixs/9.res");
    // CNF_translator("matrixs/9.res");
    // for (int i = 1; i <= 9; i++) {
    //     if (i <= 5) {
    //         for (int j = 1; j <= 9 - row_length[i]; j++) {
    //             printf("  ");
    //         }
    //     }
    //     for (int j = 1; j <= row_length[i]; j++) {
    //         int x = hs2[i][j].x;
    //         int y = hs2[i][j].y;
    //         printf("%c ", screen[x][y]);
    //     }
    //     puts("");
    // }
    return 0;
}

#include <stdio.h>
#include <string.h>

#ifdef LOCAL
#define debug printf
#else
#define debug(...) 114514
#endif

#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

int chosen_element[105]; // 记录选填数字
int g_num_clause;
int row_length[10] = {0, 5, 6, 7, 8, 9, 8, 7, 6, 5};
int col_length[10] = {0, 5, 6, 7, 8, 9, 8, 7, 6, 5};
int dig_length[15] = {0, 0, 0, 0, 0, 0, 5, 6, 7, 8, 9, 8, 7, 6, 5};
char g_cnf_string[1000005];
int hs[105][105];
typedef struct InterVal { // 数独每行每列可能选取的选填区间
    int l, r;
} InterVal;
InterVal intervals[1005];
int intervals_index;

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
            for (int i = 1; i <= col_length[col]; i++) {
                int value;
                if (i > 5) value = i * 100 + col * 10 + chosen_element[j];
                else value = i * 100 + (col - row_length[i] + 1) * 10 + chosen_element[j];
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
                if (i <= 5) {
                    j -= row_length[i] + 1;
                }
                int value = i * 100 + j * 10 + chosen_element[idx];
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

int CNF_generater(char in_filename[], char out_filename[]) {
    FILE* fin = fopen(in_filename, "r");
    if (fin == NULL) {
        return 0;
    }
    int f[10][10];
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
        // memset(vis, 0, sizeof(vis));
        choose_element_from_each_interval_row(fout, 1, 0, i);
    }
    //// 列(和行的情况几乎一样)
    for (int j = 1; j <= 5; j++) {
        for (int i1 = 6 - j; i1 <= 9; i1++) {
            for (int i2 = i1 + 1; i2 <= 9; i2++) {
                for (int num = 1; num <= 9; num++) {
                    int value1 = i1 * 100 + j * 10 + num;
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
                    int value1, value2;
                    if (i1 <= 5) value1 = i1 * 100 + (j - row_length[i1] + 1) * 10 + num;
                    else value1 = i1 * 100 + j * 100 + num;
                    if (i2 <= 5) value2 = i2 * 100 + (j - row_length[i2] + 1) * 10 + num;
                    else value2 = i2 * 100 + j * 100 + num;
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
        debug("col_length %d: %d\n", j, col_length[j]);
        for (int i = 6 - j; i <= 9; i++) {
            if (f[i][j] != 0) {
                mn = min(mn, f[i][j]);
                mx = max(mx, f[i][j]);
            }
        }
        debug("mn: %d, mx: %d\n", mn, mx);
        intervals_index = 0;
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
        if (j == 5) debug("j == 5, intervals_index: %d\n", intervals_index);
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
        choose_element_from_each_interval_col(fout, 1, 0, j);
    }
    // 对角线(行列坐标之和相等)
    for (int sum = 6; sum <= 14; sum++) {
        for (int i = 1; i <= 9; i++) {
            int j = sum - i;
            if (j <= 0 || j > 9) continue;
            if (i <= 5) {
                j -= row_length[i] + 1;
            }
            for (int ii = 1; ii <= 9; ii++) {
                int jj = sum - ii;
                if (jj <= 0 || jj > 9) continue;
                if (ii <= 5) {
                    jj -= row_length[ii] + 1;
                }
                if (i == ii && j == jj) continue;
                for (int num = 1; num <= 9; num++) {
                    int value1 = i * 100 + j * 10 + num;
                    int value2 = ii * 100 + jj * 10 + num;
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
        debug("mn: %d, mx: %d\n", mn, mx);
        intervals_index = 0;
        for (int l = 1; l <= 9; l++) {
            if (l > mn) continue;
            int r = l + dig_length[sum] - 1;
            if (r > mx) continue;
            if (l <= mn && mx <= r) {
                intervals_index++;
                intervals[intervals_index].l = l;
                intervals[intervals_index].r = r;
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

int main() {
    // strcpy(g_cnf_string, "p cnf ");
    CNF_generater("matrix_1.txt", "matrix_1.cnf");
    return 0;
}
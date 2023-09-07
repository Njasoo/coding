#include <stdio.h>
#include <string.h>

int f[105][105];

/*
        2 6 5 3 4       +4
      4 3 8 7 6 5       +3
    5 7 6 4 1 2 3       +2
  6 4 9 8 5 3 7 2       +1
3 8 7 2 9 1 4 5 6       +0
5 3 9 8 7 2 6 4         +0
4 5 3 6 1 7 2           +0
6 7 8 5 4 3             +0
2 4 6 3 5               +0
*/

/*
        2 6 5 3 4
      4 3 8 7 6 9
    5 7 6 4 1 2 3
  6 4 9 8 5 3 7 2
3 8 7 2 9 1 4 5 6
5 3 9 8 7 2 6 4
4 5 3 6 1 7 2
6 7 8 5 4 3
2 4 6 3 5
*/

/*
         / \ / \ / \ / \ / \
        | . | . | . | . | . |
       / \ / \ / \ / \ / \ / \
      | . | . | . | . | . | . |
     / \ / \ / \ / \ / \ / \ / \
    | . | . | . | . | . | . | . |
   / \ / \ / \ / \ / \ / \ / \ / \
  | . | . | . | . | . | . | . | . |
 / \ / \ / \ / \ / \ / \ / \ / \ / \
| . | . | . | . | . | . | . | . | . |
 \ / \ / \ / \ / \ / \ / \ / \ / \ / 
  | . | . | . | . | . | . | . | . |
   \ / \ / \ / \ / \ / \ / \ / \ / 
    | . | . | . | . | . | . | . |
     \ / \ / \ / \ / \ / \ / \ / 
      | . | . | . | . | . | . |
       \ / \ / \ / \ / \ / \ / 
        | . | . | . | . | . |
         \ / \ / \ / \ / \ /
*/

#define min(a, b) a < b ? a : b
#define max(a, b) a > b ? a : b

int chosen_element[105];
int chosen_element_index;

typedef struct InterVal { // 数独每行每列可能选取的选填区间
    int l, r;
} InterVal;
InterVal intervals[1005];
int intervals_index;
int row_length[10] = {0, 5, 6, 7, 8, 9, 8, 7, 6, 5};
int dig_length[15] = {0, 0, 0, 0, 0, 0, 5, 6, 7, 8, 9, 8, 7, 6, 5};
int vis[10];

void choose_element_from_each_interval_row(int id, int pre_value, int row) { // 避免选择相同的子句, 所以选择的元素必须递增
    if (id == intervals_index + 1) {
        for (int i = 1; i <= id - 1; i++) {
            for (int j = 1; j <= row_length[row]; j++) {
                int value = row * 100 + j * 10 + chosen_element[i];
                printf("%d ", value);
            }
        }
        printf("0\n");
        return;
    }
    for (int element = max(intervals[id].l, pre_value + 1); element <= intervals[id].r; element++) {
        if (vis[element]) continue; // 避免选择相同的变量
        vis[element] = 1;
        chosen_element[id] = element;
        choose_element_from_each_interval_row(id + 1, element, row);
        vis[element] = 0;
    }
}

void choose_element_from_each_interval_dig(int id, int pre_value, int sum) {
    if (id == intervals_index + 1) {
        for (int idx = 1; idx <= id - 1; idx++) {
            for (int i = 1; i <= 9; i++) {
                int j = sum - i;
                if (j <= 0) break;
                if (j > 9) continue;
                int value = i * 100 + j * 10 + chosen_element[idx];
                printf("%d ", value);
            }
        }
        printf("\n");
        return;
    }
    for (int element = max(intervals[id].l, pre_value + 1); element <= intervals[id].r; element++) {
        if (vis[element]) continue;
        vis[element] = 1;
        chosen_element[id] = element;
        choose_element_from_each_interval_dig(id + 1, element, sum);
        vis[element] = 0;
    }
}

int main() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 6 - i; j <= 9; j++) {
            scanf("%d", &f[i][j]);
        }
    }
    for (int i = 6; i <= 9; i++) {
        for (int j = 1; j <= 14 - i; j++) {
            scanf("%d", &f[i][j]);
        }
    }
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            printf("%d ", f[i][j]);
        }
        puts("");
    }
    // for (int i = 1; i <= 5; i++) {
    //     // 找每一行的最大值和最小值
    //     // if (i > 1) break;
    //     int mx = 1;
    //     int mn = 9;
    //     for (int j = 6 - i; j <= 9; j++) {
    //         if (f[i][j] != 0) {
    //             mn = min(mn, f[i][j]);
    //             mx = max(mx, f[i][j]);
    //         }
    //     }
    //     intervals_index = 0;
    //     for (int l = 1; l <= 9; l++) { // 枚举左端点
    //         if (l > mn) break;
    //         int r = l + row_length[i] - 1;
    //         if (r > 9) break;
    //         if (l <= mn && r >= mx) {
    //             intervals_index++;
    //             intervals[intervals_index].l = l;
    //             intervals[intervals_index].r = r;
    //         }
    //     }
    //     // memset(vis, 0, sizeof(vis));
    //     fprintf(stdout, "intervals_index: %d\n", intervals_index);
    //     choose_element_from_each_interval_row(1, 0, i);
    // }
    printf("\n");
    for (int sum = 6; sum <= 14; sum++) {
        printf("%d ", dig_length[sum]);
    }
    printf("\n");
    char str[105];
    sprintf(str, "%s", "12");
    strcat(str, "34\n");
    printf("%s", str);
    return 0;
}
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
        }
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
    fclose(fin);
}
int FULL_length(ClauseHead* head) {
    ClauseHead* p = head;
    long long cnt = 0;
    while (p) {
        cnt += p->size;
        p = p->next;
    }
    return cnt;
}

// 简化子句集
// 操作1: 判断子句集中是否有子句含有unit_value这个变量, 是则删除整个子句
// 操作2: 删除子句集中-unit_value这个变量
int simplification(ClauseHead** head, int unit_value) {
    debug("enter simplification\n");
    debug("hi1\n");
    // 因为如果存在单子句, 则单子句里面的唯一变量必然为true, 所以整个子句可以删掉
    ClauseHead_delete(head, unit_value);
    debug("hi2\n");
    // -unit必然为false, 所以删掉所有子句里面的-unit变量
    ClauseHead* p = *head;
    while (p) {
        if (p->var_list && VarNode_find(p->var_list, -unit_value) == 1) {
            int cnt = VarNode_delete(&(p->var_list), -unit_value);
            p->size -= cnt; // 减去删除掉的结点个数
            debug("p->size: %d, length of var_list: %d\n", p->size, VarNode_length(p->var_list));
            // if (p->size != VarNode_length(p->var_list)) {
            //     assert(0);
            // }
        }
        // debug("hi\n");
        p = p->next;
    }
    debug("simplification: 1\n");
    return 1;
}

int existEmptyClause(ClauseHead* node) { // 查找是否存在空子句
    // 看子句的size是否为0
    debug("enter existEmptyClause\n");
    ClauseHead* p = node;
    while (p) {
        if (p->size == 0) {
            debug("existEmptyClause: 1\n");
            return 1;
        }
        p = p->next;
    }
    debug("existEmptyClause: 0\n");
    return 0;
}

// 选择出现频次最多的变量来赋值, 这样也许能够使子句集的长度缩小速度快一点
// 然后再根据正值和负值的出现频次, 选择频次较高的作为优化
int choose_unit_value(ClauseHead* node) {
    debug("enter choose_unit_value\n");
    int max_frequency = 0, most_frequent_value = 0;
    ClauseHead* p = node;
    while (p) {
        VarNode* pp = p->var_list;
        while (pp) {
            if (frequency[abs(pp->value)] > max_frequency) { // 注意这里frequency统计的是正值
                max_frequency = frequency[pp->value];
                most_frequent_value = abs(pp->value);
            }
            pp = pp->next;
        }
        p = p->next;
    }
    if (possitive_frequency[most_frequent_value] > negative_frequency[most_frequent_value]) {
        debug("choose_unit_value: %d\n", most_frequent_value);
        return most_frequent_value;
    } else {
        debug("choose_unit_value: %d\n", -most_frequent_value);
        return -most_frequent_value;
    }
}

int add_unit_as_clause(ClauseHead** head, int unit_value) {
    debug("enter add_unit_as_clause\n");
    ClauseHead* new_ClauseHead_node = NULL;
    ClauseHead_init(&new_ClauseHead_node);
    new_ClauseHead_node->size = 1;
    VarNode* new_VarNode = NULL;
    VarNode_init(&new_VarNode);
    new_VarNode->value = unit_value;
    VarNode_push(&new_ClauseHead_node->var_list, new_VarNode);
    ClauseHead_push(head, new_ClauseHead_node);
    debug("add_unit_as_clause: 1\n");
    return 1;
}

int tot;
long long max_len;

// long long max(long long a, long long b) {
//     if (a > b) return a;
//     return b;
// }

int DPLLsolve(ClauseHead** node) {
    tot++;
    debug("enter DPLLsolve\n");
    ClauseHead* p = NULL;
    int unit_value = 0;
    // debug("*node: ");
    // print_CNF(*node);
    while ((p = isUnitClause(*node)) != NULL) { // 当子句集中存在单子句的时候
        // print_CNF(*node);
        assert(p);
        debug("p->size: %d\n", p->size);
        debug("length_of_var_list: %d\n", VarNode_length(p->var_list));
        // printf("p->size: %d\n", p->size);
        // printf("length_of_var_list: %d\n", VarNode_length(p->var_list));
        // if (p->size != VarNode_length(p->var_list)) {
        //     assert(0);
        // }
        assert(p->var_list);
        unit_value = p->var_list->value; // var_list也就一个结点
        bool_value[abs(unit_value)] = unit_value > 0 ? 1 : -1;
        simplification(node, unit_value);
        if (*node == NULL) {
            debug("DPLLsolve: 1\n");
            return 1; // 说明所有条件都已满足
        } else if (existEmptyClause(*node)) { // 如果存在空子句, 那么这个空子句的值再不可能为true, 所以无解
            debug("DPLLsolve: 0\n");
            return 0;
        }
    }
    unit_value = choose_unit_value(*node);
    debug("unit_value: %d\n", unit_value);
    bool_value[abs(unit_value)] = unit_value > 0 ? 1 : -1; // 第一个赋值选择, 正值为true, 赋值为false
                                                            // 关键是正值为true的时候, 就已经可以知道这一个格子填什么数字, 所以先走这一条路
    ClauseHead* original_copy1 = ClauseHead_copy(*node);
    // max_len = max(FULL_length(original_copy1), max_len);
    // debug("original_copy1:\n");
    // print_CNF(original_copy1);
    add_unit_as_clause(&original_copy1, unit_value); // 将变量作为单子句加入子句集中, 然后递归地解决这个问题
    // debug("original_copy1(after adding unite_clause): \n");
    // print_CNF(original_copy1);
    if (DPLLsolve(&original_copy1)) {
        // debug("DPLLsolve: 1\n");
        return 1;
    }
    // int pre_last_index = recycle_bin_index;
    // if (DPLLsolve(node)) {
    //     return 1;
    // }
    // 选择1失败, 将变量反过来赋值
    ClauseHead* original_copy2 = ClauseHead_copy(*node);
    // for (int i = pre_last_index + 1; i <= recycle_bin_index; i++) {
    //     ClauseHead_push(node, recycle_bin[i]);
    // }
    // recycle_bin_index = pre_last_index;
    bool_value[abs(unit_value)] = unit_value < 0 ? -1 : 1; // 负值为true
    // add_unit_as_clause(&original_copy2, -unit_value);
    add_unit_as_clause(&original_copy2, -unit_value);
    // max_len = max(FULL_length(original_copy2), max_len);
    // return DPLLsolve(&original_copy2);
    // int res = DPLLsolve(&original_copy2);
    int res = DPLLsolve(&original_copy2);
    if (res) {
        debug("DPLLsolve: 1\n");
    } else {
        debug("DPLLsolve: 0\n");
    }
    return res;
}

int global_init() {
    debug("enter global_init\n");
    for (int i = 0; i < 10005; i++) {
        frequency[i] = 0;
        possitive_frequency[i] = 0;
        negative_frequency[i] = 0;
        bool_value[i] = 0;
    }
    for (int i = 1; i <= 5; i++) {
        for (int j = 6 - i; j <= 9; j++) {
            hs[i][j] = j - (9 - row_length[i]);
        }
    }
    for (int i = 6; i <= 9; i++) {
        for (int j = 1; j <= 14 - i; j++) {
            hs[i][j] = j;
        }
    }
    strcpy(screen[0], "         / \\ / \\ / \\ / \\ / \\");
    strcpy(screen[1], "        | . | . | . | . | . |");
    strcpy(screen[2], "       / \\ / \\ / \\ / \\ / \\ / \\");
    strcpy(screen[3], "      | . | . | . | . | . | . |");
    strcpy(screen[4], "     / \\ / \\ / \\ / \\ / \\ / \\ / \\");
    strcpy(screen[5], "    | . | . | . | . | . | . | . |");
    strcpy(screen[6], "   / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\");
    strcpy(screen[7], "  | . | . | . | . | . | . | . | . |");
    strcpy(screen[8], " / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\");
    strcpy(screen[9], "| . | . | . | . | . | . | . | . | . |");
    strcpy(screen[10], " \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / ");
    strcpy(screen[11], "  | . | . | . | . | . | . | . | . |");
    strcpy(screen[12], "   \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ /");
    strcpy(screen[13], "    | . | . | . | . | . | . | . |");
    strcpy(screen[14], "     \\ / \\ / \\ / \\ / \\ / \\ / \\ /");
    strcpy(screen[15], "      | . | . | . | . | . | . |");
    strcpy(screen[16], "       \\ / \\ / \\ / \\ / \\ / \\ /");
    strcpy(screen[17], "        | . | . | . | . | . |");
    strcpy(screen[18], "         \\ / \\ / \\ / \\ / \\ /");
    hs2[1][1].y = 10;
    hs2[2][1].y = 8;
    hs2[3][1].y = 6;
    hs2[4][1].y = 4;
    hs2[5][1].y = 2;
    hs2[6][1].y = 4;
    hs2[7][1].y = 6;
    hs2[8][1].y = 8;
    hs2[9][1].y = 10;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= row_length[i]; j++) {
            hs2[i][j].x = 2 * i - 1;
            hs2[i][j].y = hs2[i][1].y + 4 * (j - 1);
        }
    }
    srand(time(NULL));
    debug("hs2[1][1]: (%d, %d)\n", hs2[1][1].x, hs2[1][1].y);
    debug("global_init: 1\n");
    return 1;
}

int CNF_reader(char input_filename[], char output_filename[]) {
    debug("enter CNF_reader\n");
    FILE* fin = fopen(input_filename, "r");
    if (!fin) {
        printf("fail!\n");
        debug("CNF_reader: -1\n");
        return -1;
    }
    ClauseHead* head = NULL;
    int num_word, num_clause; // 多少个文字, 多少个子句
    fscanf(fin, "p cnf %d %d", &num_word, &num_clause);
    for (int i = 0; i < num_clause; i++) {
        int value;
        ClauseHead* new_ClauseHead_node = NULL;
        ClauseHead_init(&new_ClauseHead_node);
        // debug("i: %d\n", i);
        while (fscanf(fin, "%d", &value) != EOF) {
            if (value == 0) break;
            new_ClauseHead_node->size++;
            // debug("new_ClauseHead_node->size == %d\n", new_ClauseHead_node->size);
            VarNode* new_VarNode = NULL;
            VarNode_init(&new_VarNode);
            new_VarNode->value = value;
            frequency[abs(value)]++;
            if (value > 0) {
                possitive_frequency[value]++;
            } else {
                negative_frequency[-value]++;
            }
            VarNode_push(&new_ClauseHead_node->var_list, new_VarNode);
            assert(new_ClauseHead_node->var_list);
        }
        ClauseHead_push(&head, new_ClauseHead_node);
    }
    debug("head:\n");
    print_CNF(head);
    // int first_value;
    // while (fscanf(fin, "%d", &first_value) != EOF) {
    //     ClauseHead* new_ClauseHead_node = NULL;
    //     ClauseHead_init(&new_ClauseHead_node);
    //     new_ClauseHead_node->size = 1;
    //     VarNode* temp_VarNode = NULL;
    //     VarNode_init(&temp_VarNode);
    //     temp_VarNode->value = first_value;
    //     frequency[abs(first_value)]++;
    //     if (first_value > 0) {
    //         possitive_frequency[first_value]++;
    //     } else {
    //         negative_frequency[-first_value]++;
    //     }
    //     VarNode_push(&new_ClauseHead_node->var_list, temp_VarNode);
    //     int value;
    //     while (fscanf(fin, "%d", &value) != EOF) {
    //         if (value == 0) break;
    //         VarNode* new_VarNode = NULL;
    //         VarNode_init(&new_VarNode);
    //         new_VarNode->value = value;
    //         new_ClauseHead_node->size++;
    //         VarNode_push(&new_ClauseHead_node->var_list, new_VarNode);
    //         frequency[abs(value)]++;
    //         if (value > 0) possitive_frequency[value]++;
    //         else negative_frequency[-value]++;
    //     }
    //     ClauseHead_push(&head, new_ClauseHead_node);
    // }
    // for (int i = 0; i <= 999; i++) {
    //     if (frequency[i]) {
    //         debug("frequency[%d]: %d ", i, frequency[i]);
    //     }
    // }
    // debug("\n");
    double start = clock();
    FILE* fp = fopen(output_filename, "w");
    if (!fp) {
        debug("CNF_reader: 0\n");
        return 0;
    }
    if (DPLLsolve(&head)) {
        fprintf(fp, "1\n");
        double end = clock();
        double time_elapsed = end - start;
        for (int i = 0; i < 100005; i++) {
            if (bool_value[i]) {
                fprintf(fp, "%d ", bool_value[i] * i);
            }
        }
        fprintf(fp, "\n");
        fprintf(fp, "time elapsed: %.17lfms\n", time_elapsed);
    } else {
        fprintf(fp, "0\n");
        fprintf(fp, "no solution!\n");
        double end = clock();
        double time_elapsed = end - start;
        fprintf(fp, "time elapsed: %.17lfms\n", time_elapsed);
    }
    fclose(fin);
    fclose(fp);
    // printf("CNF_reader: 1\n");
    return 1;
}
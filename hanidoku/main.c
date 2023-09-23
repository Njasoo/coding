#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "global_definition.h"
#include "data_structure.h"
#include "dpll.h"
#include "CNF_processor.h"

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

// void test01() {
//     CNF_reader("matrix_1.cnf", "matrix_1.res", 1);
// }

// void test02() {
//     CNF_reader("problem_2.cnf", "problem_2.res", 1);
// }

// void test03() {
//     CNF_reader("problem_3.cnf", "problem_3.res", 0);
// }

// void test04() {
//     CNF_reader("ec-vda_gr_rcs_w9.shuffled-6498.cnf", "ec-vda_gr_rcs_w9.shuffled-6498.res");
// }

// void test05() {
//     CNF_reader("problem_12.cnf", "problem_12.res");
// }

// void test06() {
//     CNF_reader("eh-dp04s04.shuffled-1075.cnf", "eh-dp04s04.shuffled-1075.res");
// }

void real_test01() {
    CNF_reader("1.cnf", "1.res", 1);
    print_res("1.res");
}

void real_test02() {
    CNF_reader("2.cnf", "2.res", 1);
    print_res("2.res");
}

void real_test03() {
    CNF_reader("3.cnf", "3.res", 0);
    print_res("3.res");
}

void real_test04() {
    CNF_reader("4u.cnf", "4.res", 0);
    print_res("4.res");
}

void real_test05() {
    CNF_reader("5.cnf", "5.res", 0);
    print_res("5.res");
}

void real_test06() {
    CNF_reader("6.cnf", "6.res", 0);
    print_res("6.res");
}

void real_test07() {
    CNF_reader("7-2.cnf", "7.res", 0);
    print_res("7.res");
}

void real_test08() {
    CNF_reader("8-2.cnf", "8.res", 0);
    print_res("8.res");
}

void real_test09() {
    CNF_reader("9u.cnf", "9.res", 0);
    print_res("9.res");
}

void real_test10() {
    CNF_reader("10.cnf", "10.res", 0);
    print_res("10.res");
}

void real_test11() {
    CNF_reader("11u.cnf", "11.res", 0);
    print_res("11.res");
}

void real_test12() {
    CNF_reader("12.cnf", "12.res", 0);
    print_res("12.res");
}

void display(char in_filename[]) {
    system("cls");
    for (int i = 0; i <= 18; i++) {
        printf("%s\n", screen[i]);
    }
    printf("----------------------------------------------------------------------\n");
    printf("\t1. Load game\t\t");
    printf("\t2. Generate CNF\n");
    printf("\t3. Show CNF\t\t");
    printf("\t4. Start DPLL\n");
    printf("\t5. Show solution\t");
    printf("\t6. Input number\n");
    printf("\t7. Delete number\t");
    printf("\t8. Exit\n");
    printf("\t9. Check\t\t");
    printf("\t10. Hint\n");
    printf("-----------------------------------------------------------------------\n");
    int op;
    scanf("%d", &op);
    if (op == 1) {
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
        system("cls");
        printf("CNF is generating...\n");
        CNF_generator(now_in_filename, now_out_filename);
        printf("CNF generated successfully\n");
        system("pause");
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
        system("cls");
        printf("DPLL is implementing...\n");
        CNF_reader(now_in_filename, now_out_filename, 0);
        FILE* fin = fopen(now_out_filename, "r");
        char ch;
        while ((ch = fgetc(fin)) != EOF) {
            putchar(ch);
        }
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
        if (dont_change[row_number][col_number] == 1) {
            // printf("Yes\n");
            // system("pause");
            display(in_filename);
            return;
        }
        // printf("No\n");
        // system("pause");
        f[row_number][col_number] = num;
        screen[x][y] = f[row_number][col_number] == 0 ? '.' : f[row_number][col_number] + '0';
        display(in_filename);
    } else if (op == 7) {
        printf("input row number: ");
        int row_number;
        scanf("%d", &row_number);
        printf("input column number: ");
        int col_number;
        scanf("%d", &col_number);
        if (dont_change[row_number][col_number] == 1) {
            display(in_filename);
            return;
        }
        int x = hs2[row_number][col_number].x;
        int y = hs2[row_number][col_number].y;
        f[row_number][col_number] = 0;
        screen[x][y] = '.';
        display(in_filename);
    } else if (op == 8) {
        system("cls");
        printf("bye bye\n");
        system("pause");
        game_start = 0;
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
    } else if (op == 10) {
        Location pos[105];
        int index = 0;
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= row_length[i]; j++) {
                if (f[i][j] == 0) {
                    index++;
                    pos[index].x = i;
                    pos[index].y = j;
                }
            }
        }
        if (index == 0) {
            display(in_filename);
        }
        int random_position = rand() % (index - 1 + 1) + 1;
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
        int x = pos[random_position].x;
        int y = pos[random_position].y;
        g[x][y] = f[x][y];
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= row_length[i]; j++) {
                f[i][j] = g[i][j];
                int x = hs2[i][j].x;
                int y = hs2[i][j].y;
                screen[x][y] = f[i][j] == 0 ? '.' : f[i][j] + '0';
            }
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
    // real_test06(); // pass slow about 2min
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
    // global_init();
    // CNF_reader("6.cnf", "6.res");

    // int random_number = 0;
    // while (1) {
    //     global_init();
    //     system("cls");
    //     printf("////////// HANIDOKU & SAT //////////\n");
    //     printf("---------------------------------\n");
    //     printf("\t1. Solve SAT\n");
    //     printf("\t2. Play game\n");
    //     printf("---------------------------------\n");
    //     int op;
    //     scanf("%d", &op);
    //     if (op == 1) {
    //         printf("input test number: ");
    //         int test;
    //         scanf("%d", &test);
    //         if (test == 1) {
    //             real_test01();
    //         } else if (test == 2) {
    //             real_test02();
    //         } else if (test == 3) {
    //             real_test03();
    //         } else if (test == 4) {
    //             real_test04();
    //         } else if (test == 5) {
    //             real_test05();
    //         } else if (test == 6) {
    //             real_test06();
    //         } else if (test == 7) {
    //             real_test07();
    //         } else if (test == 8) {
    //             real_test08();
    //         } else if (test == 9) {
    //             real_test09();
    //         } else if (test == 10) {
    //             real_test10();
    //         } else if (test == 11) {
    //             real_test11();
    //         } else if (test == 12) {
    //             real_test12();
    //         }
    //     } else if (op == 2) {
    //         game_start = 1;
    //         while (game_start) {
    //             global_init();
    //             char folder_name[105];
    //             strcpy(folder_name, "matrixs/");
    //             int range_l = 1, range_r = 20;
    //             if (random_switch == 1) {
    //                 random_number = rand() % (range_r - range_l + 1) + range_l;
    //                 random_switch = 0;
    //             }
    //             if (random_number == 0) {
    //                 display("matrixs/0");
    //                 continue;
    //             }
    //             char filename[105];
    //             if (random_number >= 10) {
    //                 filename[0] = random_number / 10 % 10 + '0';
    //                 filename[1] = random_number % 10 + '0';
    //                 filename[2] = '\0';
    //             } else {
    //                 filename[0] = random_number + '0';
    //                 filename[1] = '\0';
    //             }
    //             char real_filename[105];
    //             strcpy(real_filename, folder_name);
    //             strcat(real_filename, filename);
    //             char suffix[15];
    //             strcpy(suffix, ".txt");
    //             char now_in_filename[105];
    //             strcpy(now_in_filename, real_filename);
    //             strcat(now_in_filename, suffix);
    //             FILE* fin = fopen(now_in_filename, "r");
    //             for (int i = 1; i <= 9; i++) {
    //                 for (int j = 1; j <= row_length[i]; j++) {
    //                     int num;
    //                     fscanf(fin, "%d", &num);
    //                     f[i][j] = num;
    //                     if (f[i][j] != 0) dont_change[i][j] = 1;
    //                     int x = hs2[i][j].x;
    //                     int y = hs2[i][j].y;
    //                     if (num == 0) screen[x][y] = '.';
    //                     else screen[x][y] = num + '0';
    //                 }
    //             }
    //             fclose(fin);
    //             display(real_filename);
    //         }
    //     }
    // }
    global_init();
    // CNF_reader("M/tst_v200_c210.cnf", "M/tst_v200_c210.res", 0);
    // CNF_reader("L/ec-iso-ukn009.shuffled-as.sat05-3632-1584.cnf","L/ec-iso-ukn009.shuffled-as.sat05-3632-1584.res",0);
    return 0;
}

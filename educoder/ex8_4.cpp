#include <stdio.h>

int main() {
  int tt = 10;
  while (tt--) {
    float num;
    scanf("%f", &num);
    int ex = 0;
    if (num < 0) {
      printf("1");
      num = -num;
    } else {
      printf("0");
    }
    int int_part = (int) num;
    float dec_part = num - int_part;
    if (int_part) {
      while (int_part > 1) {
        int_part >>= 1;
        ex++;
      }
      int_part = (int) num;
    } else {
      int_part = 1;
      while ((int) dec_part != 1) {
        dec_part *= 2;
        ex--;
      }
      dec_part -= (int) dec_part;
    }
    int ans1[105], ans2[105];
    int k1 = 0, k2 = 0;
    while (int_part) {
      ans1[++k1] = int_part & 1;
      int_part >>= 1;
    }
    for (int i = 1, j = k1; i < j; i++, j--) {
      int temp = ans1[i];
      ans1[i] = ans1[j];
      ans1[j] = temp;
    }
    while (dec_part != 0.0) {
      dec_part *= 2;
      ans2[++k2] = (int) dec_part;
      dec_part -= (int) dec_part;
    }
    int exp_code = ex + 127;
    int bit_exp_code[105];
    int index_of_bit_exp_code = 0;
    while (exp_code) {
      bit_exp_code[++index_of_bit_exp_code] = exp_code & 1;
      exp_code >>= 1;
    }
    for (int i = 1, j = index_of_bit_exp_code; i < j; i++, j--) {
      int temp = bit_exp_code[i];
      bit_exp_code[i] = bit_exp_code[j];
      bit_exp_code[j] = temp;
    }
    for (int i = 1; i <= 8 - index_of_bit_exp_code; i++) {
      printf("0");
    }
//    printf("index_of_bit_exp_code: %d\n", index_of_bit_exp_code);
    for (int i = 1; i <= index_of_bit_exp_code; i++) {
      printf("%d", bit_exp_code[i]);
    }
    int bit_last_code[105];
    int index_of_last_code = 0;
    for (int i = 2; i <= k1; i++) {
      bit_last_code[++index_of_last_code] = ans1[i];
    }
    for (int i = 1; i <= k2; i++) {
      bit_last_code[++index_of_last_code] = ans2[i];
    }
    for (int i = 1; i <= index_of_last_code; i++) {
      printf("%d", bit_last_code[i]);
    }
    for (int i = 1; i <= 23 - index_of_last_code; i++) {
      printf("0");
    }
    printf("\n");
  }
  return 0;
}
#include <stdio.h>
#include <string.h>

const int N = 5;
char message[214];
struct student {
  char name[8];
  short age;         // sizeof(short) == 2
  float score;       // sizeof(float) == 4, 这里跳过两个字节
  char remark[200];  // 备注信息
} old_s[N], new_s[N];

int pack_stdent_bytebybyte(student* s, int sno, char* buf) { return 0; }

int pack_student_whole(student* s, int sno, char* buf) { return 0; }

int main() {
  strcpy(old_s[0].name, "王镇濠");
  old_s[0].score = 51;
  return 0;
}
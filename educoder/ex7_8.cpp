#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct c_node {
  char data;
  struct c_node *next;
} C_NODE;

void createLinkList(C_NODE** headp, char s[]) {
  *headp = (C_NODE*) malloc(sizeof(C_NODE*));
  C_NODE* cur = *headp;
  if (*s) {
    cur->data = *s++;
    while (*s) {
      cur->next = (C_NODE*) malloc(sizeof(C_NODE*));
      cur = cur->next;
      cur->data = *s++;
    }
    cur->next = NULL;
  }
}

C_NODE* reverse_list(C_NODE* head) {
  C_NODE* pre = NULL;
  C_NODE* cur = head;
  while (cur) {
    C_NODE* nex = cur->next;
    cur->next = pre;
    pre = cur;
    cur = nex;
  }
  return pre;
}

void judgePalindrome(C_NODE* head) {
  C_NODE* rhead = reverse_list(head);
  while (head) {
    if (head->data != rhead->data) {
      printf("false\n");
      return;
    }
    head = head->next;
    rhead = rhead->next;
  }
  printf("true\n");
}

int main() {
  char s[1000];
  C_NODE *head;
  scanf("%[^\n]", s); // read everything but '\n'
  createLinkList(&head, s);   
  judgePalindrome(head);
  return 1;
}
#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <cstring>
#include <windows.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

using namespace std;

typedef int status;
typedef int ElemType; //????????

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int ElemType;
typedef struct{  //???(????)???
		string name;
	      ElemType * elem;
	      int length;
	      int listsize;
         }SqList;

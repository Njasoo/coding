
void ShiftRightCircular(ElemType *A,int n,int k)
{
/************** begin *****************/
    ElemType *B = (int*)malloc(sizeof(n * sizeof(int)));
    for (int i = 0; i < n; i++) {
        int index = ((i + k) % n + n) % n;
        B[index] = A[i];
    }
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
/**************  end  *****************/
}
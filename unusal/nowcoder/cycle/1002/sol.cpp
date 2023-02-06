/**
 *    author:  Njaso
 *    created: 09.06.2022 00:12:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
//  ios::sync_with_stdio(false);
//  cin.tie(0);
  int n;
  scanf("%d", &n);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      printf("%4d", ++cnt);
    }
    printf("\n");
  }
  return 0;
}
/**
 *    author:  Njaso
 *    created: 03.06.2022 00:19:08
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  srand(time(NULL));
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  random_shuffle(a, a + 10);
  for (int i = 0; i < 10; i++) {
    cout << a[i] << " ";
  }
  cout << '\n';
  return 0;
}
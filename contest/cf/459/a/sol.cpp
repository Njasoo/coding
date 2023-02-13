/**
 *    author:  Njaso
 *    created: 03.07.2022 16:07:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  const int LEFT = -1000, RIGHT = 1000;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1 == x2) {
    int side = abs(y1 - y2);
    int x3 = x1 + side, y3 = y1;
    int x4 = x1 + side, y4 = y1 + side;
  } else if (y1 == y2) {
    int side = abs(x1 - x2);
    int x3 = x1, y3 = y1 + side;
    int x4 = 
  return 0;
}
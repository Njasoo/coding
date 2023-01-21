#include <bits/stdc++.h>

using namespace std;

char ch = ' ';
stack<int> st;
int now = 0;

int main() {
  while (ch != '@') {
    scanf("%c", &ch);
    if (ch >= '0' && ch <= '9') {
      now = now * 10 + ch - '0';
    } else if (ch == '.') {
      st.push(now);
      now = 0;
    } else if (ch != '@') {
      int b = st.top(); st.pop();
      int a = st.top(); st.pop();
      int ans = 0;
      if (ch == '+') {
        ans = a + b;
      } else if (ch == '-') {
        ans = a - b;
      } else if (ch == '*') {
        ans = a * b;
      } else {
        ans = a / b;
      }
      st.push(ans);
    }
  }
  printf("%d\n", st.top());
  return 0;
}
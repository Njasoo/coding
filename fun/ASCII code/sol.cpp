#include <iostream>
#include <conio.h>

using namespace std;

int main() {
  char ch;
  while (true) {
    if (kbhit()) {
      ch = (char) getch();
      cout << ch <<  " " << (int) ch << '\n';
    }
  }
  return 0;
}
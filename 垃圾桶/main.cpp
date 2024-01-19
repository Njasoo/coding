#include <iostream>

using namespace std;

const int ROW = 10, COL = 10;



int CreateHanidokuToFile() {
    int hanidoku[ROW][COL];
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            hanidoku[i][j] = -1;
        }
    }
    for (int i = 1; i <= 5; i++) {
        for (int j = 6 - i; j <= 9; j++) {
            cin >> hanidoku[i][j];
        }
    }
    for (int i = 6; i <= 9; i++) {
        for (int j = 1; j <= 14 - i; j++) {
            cin >> hanidoku[i][j];
        }
    }
}

int main() {
    CreateHanidokuToFile();
    return 0;
}
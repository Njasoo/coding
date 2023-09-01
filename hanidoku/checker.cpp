#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1e6 + 5;
int ans[N];

int main() {
    FILE* fp = fopen("eh-dp04s04.shuffled-1075.cnf", "r");
    int num_word, num_clause;
    fscanf(fp, "%d %d", &num_word, &num_clause);
    vector<vector<int>> clauses(num_clause);
    for (int i = 0; i < num_clause; i++) {
        int value;
        while (fscanf(fp, "%d", &value) != EOF) {
            if (value == 0) break;
            clauses[i].push_back(value);
        }
    }
    fclose(fp);
    fp = fopen("eh-dp04s04.shuffled-1075.res", "r");
    int value;
    while (fscanf(fp, "%d", &value) != EOF) {
        if (value > 0) ans[value] = 1;
        else ans[-value] = -1;
    }
    return 0;
}
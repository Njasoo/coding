#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
int n;
int x[N], y[N], w[N];
double ansx, ansy, mn_e;

double Rand() {
    return (double) rand() / RAND_MAX;
}

double calc(double x0, double y0) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        double dx = x0 - x[i];
        double dy = y0 - y[i];
        res += sqrt(dx * dx + dy * dy) * w[i];
    }
    return res;
}

void SA() {
    double T = 100000;
    double nowx = ansx, nowy = ansy;
    while (T > 0.0001) {
        double nx = nowx + (Rand() * 2 - 1) * T;
        double ny = nowy + (Rand() * 2 - 1) * T;
        double e_now = calc(nowx, nowy);
        double en = calc(nx, ny);
        double delta = en - e_now;
        if (en < mn_e) {
            mn_e = en;
            ansx = nx;
            ansy = ny;
        }
        if (delta < 0) {
            nowx = nx;
            nowy = ny;
        } else if (exp(-delta / T) > Rand()) {
            nowx = nx;
            nowy = ny;
        }
        T *= 0.97;
    }
    for (int i = 0; i < 100000; i++) {
        double nx = ansx + T * (Rand() * 2 - 1);
        double ny = ansy + T * (Rand() * 2 - 1);
        double en = calc(nx, ny);
        if (en < mn_e) {
            mn_e = en;
            ansx = nx;
            ansy = ny;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(NULL));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> w[i];
        ansx += x[i];
        ansy += y[i];
    }
    ansx /= n, ansy /= n;
    mn_e = calc(ansx, ansy);
    SA();
    cout << fixed << setprecision(3);
    cout << ansx << " " << ansy << '\n';
    return 0;
}
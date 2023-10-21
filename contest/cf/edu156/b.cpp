#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

double dis(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        double px, py, ax, ay, bx, by;
        cin >> px >> py >> ax >> ay >> bx >> by;
        // in the same circle
        double ans = 1e9;
        // lantern a
        double dis_a_o = dis(0, 0, ax, ay);
        double dis_a_p = dis(px, py, ax, ay);
        ans = min(ans, max(dis_a_p, dis_a_o));
        // lantern b
        double dis_b_o = dis(0, 0, bx, by);
        double dis_b_p = dis(px, py, bx, by);
        ans = min(ans, max(dis_b_p, dis_b_o));
        // in different circle
        // p in lantern a, o in lantern b
        double d = dis(ax, ay, bx, by);
        double r = d / 2;
        ans = min(ans, max(r, max(dis_a_p, dis_b_o)));
        // o in lanter a, o in lantern b
        ans = min(ans, max(r, max(dis_a_o, dis_b_p)));
        cout << fixed << setprecision(17) << ans << '\n';
    }   
    return 0;
}
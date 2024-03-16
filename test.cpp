#include <bits/stdc++.h>

using namespace std;

int bitMask(int highbit, int lowbit) {
    int t1 = -1;
    if (highbit < 31) t1 <<= (highbit + 1);
    else t1 = 0;
    int t2 = -1;
    t2 <<= lowbit;
    return t1 ^ t2;
}

int byteSwap(int x, int n, int m) {
    int r1 = bitMask(8 * n + 7, 8 * n);
    int r2 = bitMask(8 * m + 7, 8 * m);
    int rr1 = ~r1;
    int rr2 = ~r2;
    int t1 = x & r1;
    int t2 = x & r2;
    x &= rr1;
    x &= rr2;
    if (n > m) {
        t1 >>= (n - m) * 8;
        t2 <<= (n - m) * 8;
    }
    else {
        t1 <<= (m - n) * 8;
        t2 >>= (m - n) * 8;
    }
    return x ^ t1 ^ t2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << 0xDEADBEEF << endl;
    bitset<32> b = 0xDEADBEEF;
    cout << b << endl;
    bitset<32> b2 = byteSwap(0xDEADBEEF, 0, 2);
    cout << b2 << endl; 
    bitset<32> b3 = 0xDEEFBEAD;
    cout << b3 << endl;
    cout << (int)0xDEEFBEAD << endl;
    cout << byteSwap(0xDEADBEEF, 0, 2) << endl;    
    return 0;
}

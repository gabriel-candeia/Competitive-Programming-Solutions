#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    int ak, bk, ck; cin >> ak >> bk >> ck;

    int sum = 0;
    if(a < ak)
        sum += abs(a - ak);
    if(b < bk)
        sum += abs(b - bk);
    if(c < ck)
        sum += abs(c - ck);

    cout << sum << endl;   
}

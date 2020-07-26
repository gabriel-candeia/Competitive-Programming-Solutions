#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, y, k;

    cin >> k >> x >> y;
    cout << ((abs(x-y)>=k) ? "EH SUFICIENTE" : "NAO EH SUFICIENTE") << '\n';

    return 0;
}
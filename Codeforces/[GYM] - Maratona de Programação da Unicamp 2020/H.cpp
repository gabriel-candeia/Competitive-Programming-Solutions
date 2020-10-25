#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;

    cin >> n >> m >> k;
    vector<string> p(n), a(m), l(k);
    for(auto &x:p)
        cin >> x;
    for(auto &x:a)
        cin >> x;
    for(auto &x:l)
        cin >> x;

    sort(p.begin(),p.end());
    sort(a.begin(),a.end());
    sort(l.begin(),l.end());
    for(auto x:p)
        for(auto y:a)
            for(auto z:l)
                cout << "Foi " << x << ", com " << y << ", " << z <<'\n';

    return 0;
}

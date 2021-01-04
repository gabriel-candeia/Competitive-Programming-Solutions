#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> a, b;

    cin >> n;
    a.assign(n,0); b.assign(n,0);

    for(auto &x:a)
        cin >> x;

    for(auto &x:b)
        cin >> x;

    int answ = 0;
    for(int i=;i<n;i++){
        int dif = int(1e9+5);
        for(int j=0;j<n;j++){
            dif = min(dif,abs(a[i]-b[j]));
        }
        answ = max(answ,dif);
    }
    cout <<answ <<'\n';

    return 0;
}
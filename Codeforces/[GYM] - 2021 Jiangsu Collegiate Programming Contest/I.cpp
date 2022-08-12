#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll m, n;
        cin >> m >> n;
        ll answ = (1ll<<m);
        if(n!=0)
            answ--;
        if(m==1)
            answ = ((n==0) ? 1 : 2);
        cout << answ <<"\n";
    }
    return 0;
}

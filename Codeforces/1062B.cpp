#include<bits/stdc++.h>
using namespace std;

bool ehPot(int x){
    return (x==(x&(-x)));
}

int main(){
    int n, answ = 1, acm, turns=0, mx = -1, k, mn = 100;
    bool end=false;

    cin >> n;
    for(int i=2;i<=n;i++){
        acm = 0;
        while(n%i==0){
            n/=i;
            acm++;
        }
        if(acm!=0){
            mx = max(mx,acm);
            mn = min(mn,acm);
            answ*=i;
        }
    }
    
    turns = 0;
    if(mx>1 && (!ehPot(mx) || mx!=mn)){
        turns++;
    }
    k = 1;
    while(k<mx){
        turns++;
        k*=2;
    }

    cout << answ << " " << turns << '\n';

    return 0;
}
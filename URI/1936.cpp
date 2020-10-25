#include<bits/stdc++.h>
using namespace std;

int fat(int n){
    int acm=1;
    for(int i=1;i<=n;i++){
        acm*=i;
    }
    return acm;
}

int main(){
    int n, answ=0;
    cin >> n;

    for(int i=10;i>=0;i--){
        answ += n/fat(i);
        n %= fat(i);
    }

    cout << answ <<'\n';
    return 0;
}
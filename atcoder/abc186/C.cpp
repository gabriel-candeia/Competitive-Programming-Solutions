#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool teste(int x){
    int answ =0;
    for(int y=x;y;y/=10)
        answ += (y%10==7);
    for(int y=x;y;y/=8)
        answ += (y%8==7);
    return (answ!=0);
}

int main(){
    ll n, answ = 0;

    cin >> n;
    for(int i=1;i<=n;i++){
        answ += teste(i);
    }
    cout << n-answ <<'\n';
    return 0;
}
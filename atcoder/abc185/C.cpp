#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll l, answ=1, ptr = 2;
    cin >> l;
    
    for(ll i=l-12+11;i>l-12;i--){
        answ *= i;
        while(ptr<=11 && answ%ptr==0){
            answ/=ptr;
            ptr++;
        }
    }
    cout << answ <<"\n";
    return 0;
}
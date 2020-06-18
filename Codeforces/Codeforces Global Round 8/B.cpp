#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll pot(ll x, ll k){
    ll acm=1;
    while(k>0){
        acm*=x;
        k--;
    }
    return acm;
}


int main(){
    ll k;
    string s = "codeforces";
    int cnt1=0, cnt2=0;
    int qtd=1;

    cin >> k;
    while(pot(qtd,10)<k){
        qtd++;
    }
    
    qtd--;
    int answ=0;
    for(int i=0;i<=10;i++){
        if(pot(qtd+1,i)*pot(qtd,10-i)>=k){
            cnt1 = i;
            cnt2 = 10-i;
            break;
        }
    }

    for(int i=0;i<s.size();i++){
        if(cnt1){
            cout << string(qtd+1,s[i]);
            cnt1--;
        }
        else{
            cout << string(qtd,s[i]);
        }
    }
    cout << '\n';

    return 0;
}
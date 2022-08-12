#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll move(ll x){
    ll ox = x;
    ll primeiro = 0, pot = 1;
    while(x){
        primeiro = x%10;
        x/=10;
        pot = pot*10;
    }
    pot/=10;
    return (ox-pot*primeiro)*10+primeiro;
}

int main(){
    string s;
    ll x=0, sft = 0;

    cin >> s;
    for(auto c:s){
        sft = 10*sft;
        if(c=='.'){
            sft = 1;
        }
        else{
            x = 10*x + c-'0';
        }
    }

    ll lim = 1e8;
    if(x/sft >= 10)
        lim = 0;
    //cout << lim <<"\n";
    //cout << 10000000 <<"\n";
    ll cnt = 0;
    for(ll i=1;i<=lim;i++){
        if((i*x)%sft==0){
            ll num = (i*x)/sft;      
            if(move(i)==num){
                cnt = 1;
                cout << i <<"\n";
            }
        }
    }
    if(cnt==0)
        cout << "No solution\n";

    return 0;
}
#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int main(){
    fastio();
    int n;
    ll x;
    string s, answ;

    cin >> n >> x >> s;
    
    while(x){
        answ.push_back((x&1)+'0');
        x/=2;
    }
    
    reverse(answ.begin(),answ.end());
    
    for(auto c:s){
        if(c=='U' && answ.size()){
            answ.pop_back();
        }
        else if(c=='L'){
            answ.push_back('0');
        }
        else if(c=='R'){
            answ.push_back('1');
        }
    }

    ll val = 0;
    for(auto c:answ){
        val = 2*val + c-'0';
    }

    cout << val << "\n";

    return 0;
}
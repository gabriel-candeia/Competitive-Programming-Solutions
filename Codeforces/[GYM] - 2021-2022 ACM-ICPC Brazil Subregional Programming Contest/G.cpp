#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxn = 1e15+5;
ll QTD = 0;
ll fib[100];

void precomp(){
    ll i=0;
    fib[0] = fib[1] = 1;
    for(i = 2; fib[i-1] <= maxn; i++) fib[i] = fib[i-1] + fib[i-2], QTD++;
}

pair<bool,string> solve(ll i, ll j){
    if(i==1)
        return {true,""};
    if(fib[j]==1)
        return {false,""};
    pair<bool,string> p1;
    if(i%fib[j]==0){
        p1 = solve(i/fib[j],j);
        if(p1.first==1)
            return {1,string(j-1,'A')+"B"+p1.second};
    }
    return solve(i,j-1);
}

int main(){
    ll n;
    cin >> n;
    
    precomp();

    auto answ = solve(n,QTD);

    

    if(answ.first){
        cout << answ.second <<"\n";
    }
    else{
        cout << "IMPOSSIBLE" << "\n";
    }
    
    return 0;
}
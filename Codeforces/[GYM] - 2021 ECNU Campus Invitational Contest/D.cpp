#include<bits/stdc++.h>
#define maxn int(1e7+5)
#define ll long long
using namespace std;

int fatA[maxn], sieve[maxn], go[maxn], wt[maxn];

ll contar(int x, int l, int r){
    ll pot = x, answ = 0;
    while(pot<=r){
        answ += (r/pot - (l-1)/pot);
        pot = pot*x;
    }
    return answ;
}

int main(){
    vector<int> primes;
    int t;

    sieve[1] = 1;
    for(int i=2;i<maxn;i++){
        if(sieve[i]==0){
            primes.push_back(i);
            for(int j=i;j<maxn;j+=i){
                go[j] = j/i;
                sieve[j] = i;
            }
        }
    }

    cin >> t;
    while(t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        bool poss = true;
        for(auto x:primes)
            if(fatA[x]<0)
                poss = false;

        for(auto x:primes)
            if(contar(x,a,b) > contar(x,c,d))
                poss = false;
        
        if(poss==false)
            cout << "No\n";
        else   
            cout << "Yes\n";
        
    }

    return 0;
}
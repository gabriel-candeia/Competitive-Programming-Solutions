#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e6+5)
using namespace std;

int sieve[maxn];

void precomp(){
    memset(sieve,0,maxn);
    sieve[0] = sieve[1] = 1;
    for(ll i=2;i<maxn;i++){
        if(sieve[i]==0){
            for(ll j=i*i;j<maxn;j+=i){
                sieve[j] = 1;
            }
        }
    }
}

int main(){
    precomp();
    int t;
    cin >> t;
    while(t--){
        int n, e;
        vector<int> arr, nextPrime;
        cin >> n >> e;

        arr.assign(n,0);
        nextPrime.assign(n,0);
        for(auto &x:arr){
            cin >> x;
            if(sieve[x] && x!=1)
                x = 0;
        }
        
        ll answ = 0;
        for(int i=n-1;i>n-e-1;i--)
            if(sieve[arr[i]]==0 || arr[i]==1)
                nextPrime[i] = 1;
        
        for(int i=n-e-1;i>=0;i--){
            if(arr[i+e]!=1) nextPrime[i] = 1;
            else nextPrime[i] = nextPrime[i+e]+1;

            //cout << nextPrime[i] << " ";

            if(arr[i]==1){
                int proxPrimo = i + e*nextPrime[i];
                if(proxPrimo<n && arr[proxPrimo]!=0) answ += nextPrime[proxPrimo];
            }
            else if(arr[i]>1){
                int passos = nextPrime[i];
                answ += (passos-1);
            }
        }

        cout << answ <<"\n";

    }
    return 0;
}
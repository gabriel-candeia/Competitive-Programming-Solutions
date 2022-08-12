#include<bits/stdc++.h>
#define maxn int(1e4)
#define ll long long
using namespace std;

const ll mod = 1e9+9;
ll binpow(ll x, ll y){
    ll answ = 1;
    for(;y;y/=2){
        if(y&1){
            answ = (answ*x)%mod;
        }
        x = (x*x)%mod;
    }
    return answ;
}

vector<int> primes;
void precomp(){
    vector<int> marked(maxn,0);
    for(int i=2;i<maxn;i++){
        if(marked[i]==0){
            primes.push_back(i);
            for(int j=i*i;j<maxn;j+=i){
                marked[j] = i;
            }
        }
    }
}

int main(){
    precomp();

    int n;
    vector<int> answ;

    cin >> n;
    answ.assign(n+1,0);

    ll last, curr;
    cout << "? " << 1 << " " << n<< endl;
    cin >> last;
    
    for(int i=3-n%2;i<n;i+=2){
        cout << "? " << i << " " << n<< endl;
        cin >> curr;
        ll par = (last*binpow(curr,mod-2))%mod;
        if(i==2){
            answ[i-1] = par;
        }
        else{
            for(int j=0;j<primes.size();j++){
                if(par%primes[j]==0){
                    answ[i-2] = primes[j];
                    answ[i-1] = par/primes[j];
                    break;
                }
            }
        }
        last = curr;
    }

    for(int j=0;j<primes.size();j++){
        if(last%primes[j]==0){
            answ[n-1] = primes[j];
            answ[n] = last/primes[j];
            break;
        }
    }

    cout << "! ";
    for(int i=1;i<=n;i++){
        cout << answ[i] << " ";
    }cout<<endl;

    return 0;
}
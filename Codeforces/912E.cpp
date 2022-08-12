#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e18;

void brute(int i, const vector<ll>& primes, vector<ll>& answ, ll num){
    if(i==primes.size()){
        answ.push_back(num);
        return;
    }
    if(num<=inf/primes[i])
        brute(i,primes,answ,num*primes[i]);
    brute(i+1,primes,answ,num);
}

ll n, k;
vector<ll> mult1, mult2;
vector<ll> primes, odd, even;
int isok(ll x){
    int r = mult2.size()-1;
    ll pos = 0;
    for(int l=0;l<mult1.size();l++){
        while(r>=0 && mult2[r]>x/mult1[l]) r--;
        pos += (r+1);     
    }
    return pos;
}

int main(){
    

    cin >> n;
    primes.assign(n,0);
    for(auto &x:primes)
        cin >> x;
    cin >> k;

    sort(primes.begin(),primes.end());
    for(int i=0;2*i<n;i++)
        even.push_back(primes[2*i]);
    for(int i=0;2*i+1<n;i++)
        odd.push_back(primes[2*i+1]);

    brute(0,odd,mult1,1);
    brute(0,even,mult2,1);
    sort(mult1.begin(),mult1.end());
    sort(mult2.begin(),mult2.end());
    
    ll l = 1, r = 1e18, med, answ = -1;
    while(l<=r){
        med = (l+r)/2;
        if(isok(med)>=k){
            answ = med;
            r = med-1;
        }
        else{
            l = med+1;
        }
    }

    cout << answ <<"\n";
    return 0;
}
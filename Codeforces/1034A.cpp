/*
    in this problem we must find the prime factor that appears in the greatest number of elements of the
    array, arr/gcd(arr). Since factoring each one is expensive we count the number of times each element of
    arr/gcd(arr) appears, then, during the sieve, when we are considering a multiple j of a certain prime
    i we can see how many times it appears on arr/gcd(arr) by checking cnt[i]. By doing this for all multiples
    of i we can discover the number of elements of arr/gcd(arr) that have i as  prime factor.
*/

#include<bits/stdc++.h>
#define N int(1.5e7+5)
using namespace std;
int sieve[N], cnt[N];

int gcd(int x, int y){
    return y ? gcd(y,x%y) : x;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d, answ;
    vector<int> a;

    cin >> n;
    a.assign(n,0);
    for(int i=0;i<N;i++){
        sieve[i] = 1;
        cnt[i] = 0;
    }
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    d = a[0];
    for(int i=0;i<n;i++){
        d = gcd(d,a[i]);
    }

    for(int i=0;i<n;i++){
        a[i]/=d;
        cnt[a[i]]++;
    }
    
    answ = 0;
    for(int i=2;i<N;i++){
        if(sieve[i]){
            int siz = 0;
            for(int j=i;j<N;j+=i){
                sieve[j] = false;
                siz+=cnt[j];
            }
            answ = max(answ,siz);
        }  
    }
 
    cout << ((answ==0) ? -1 : n-answ) << '\n';
    return 0;
}
#include<bits/stdc++.h>
#define ll long long 
#define N 1e6+3
using namespace std;

int main(){
    int a, b, c, d;
    vector<ll> cnt(N,0);

    cin >> a >> b >> c >> d;

    /* 
        - Use offline preffix sum so that cnt[z] counts the number of ways to obtain
        z as a sum of two numbers x+y (a<=x<=b and b<=y<=c)
    */
    for(int i=a;i<=b;i++){
        cnt[i+b]++;
        cnt[i+c+1]--;
    }
    for(int i=1;i<N;i++){
        cnt[i]+=cnt[i-1];
    }

    /*
        - Use preffix sums again so that cnt[z] counts the number of ways to obtain a value
        less or equal to z as a sum of two numbers x+y (a<=x<=b and b<=y<=c).
        - After this cnt[z] will count the number of pairs (x, y), a<=x<=b and b<=y<=c, such that
        x+y<=z
    */
    for(int i=1;i<N;i++){
        cnt[i]+=cnt[i-1];
    }

    /*
            Given the existing conditions a triangle will exist for every triple (x, y, z) such 
        that z > x+y. 
            Since cnt[z]  counts the number of pairs x+y<=z then cnt[N-1] - cnt[z] counts the
        number of pairs z>x+y.
    */
    ll answ = 0;
    for(int i=c;i<=d;i++){
        answ += cnt[N-1]-cnt[i];
    }

    cout << answ << '\n';
    return 0;
}
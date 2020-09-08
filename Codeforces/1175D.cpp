#include<bits/stdc++.h>
#define ll long long
#define LOG 30
#define N int(3e5+3)
using namespace std;

ll n, k;
ll a[N];

int main(){
    cin >> n >> k;
    ll answ = 0;    
    for(int i=0;i<n;i++){
        cin >> a[i];
        answ+=a[i];
    }

    for(int i=n-2;i>=0;i--){
        a[i]+=a[i+1];
    }

    sort(a+1,a+n);
    for(int i=0;i<k-1;i++){
        answ +=a[n-1-i];
    }

    cout << answ << '\n';
    return 0;
}
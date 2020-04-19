#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll max(ll a, ll b){
    return (a>b) ? a : b;
}

int main(){
    ll n, m;
    ll answ=0, sum=0, lim=0;
    vector<int> a;

    cin >> n >> m;
    
    a.assign(n+1,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum+=a[i];
    }

    sort(a.rbegin(),a.rend());
    lim = a[0];
    for(int i=0;i<n;i++){
        //cout << lim << " " << answ << '\n';
        if(lim==0){
            answ += (a[i]!=0);
        }
        else if(a[i]!=0){
            if(a[i]>=lim){
                answ += max(1,lim-a[i+1]);
                lim -= max(1,lim-a[i+1]);
            }
            else{
                answ += max(1,a[i]-a[i+1]);
                lim = a[i];
            }
        }
    }
    cout << sum-answ <<'\n';
    return 0;
}
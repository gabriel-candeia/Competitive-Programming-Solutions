#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll formas(ll mid){
    ll acm=0;
    for(int k=2;1ll*k*k*k<=mid;k++){
        acm += (mid/(1ll*k*k*k));
    }
    return acm;
}

int main(){
    ll m, answ=-1, temp;

    cin >> m;

    ll l=0,r=1e16,mid;

    while(l<=r){
        mid = l + (r-l)/2;
        temp = formas(mid);
        if(temp >= m){
            if(temp==m){
                answ = mid;
            }
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }

    cout << answ <<'\n';

    return 0;
}
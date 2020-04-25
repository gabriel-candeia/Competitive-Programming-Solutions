#include<bits/stdc++.h>
#define N int(1e5+3)
#define ll long long
using namespace std;

ll ceil(ll a, ll b){
    return a/b + (a%b!=0);
}

int main(){
    ll n, m, k, p[N], i;
    ll cnt=0, acm=0, op=0;

    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        cin >> p[i];
    }

    i = 0;
    ll current = ceil(p[0],k);
    while(i<m){
        if(ceil((p[i]-cnt),(k))==current){
            acm++;
            i++;
        }
        else{
            cnt+=acm;
            acm = 0; op++;
            current = ceil((p[i]-cnt),(k));
        }
    }

    op += (acm!=0);
    cout << op <<'\n';

    return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e18;
int n;
vector<int> a;

ll teste(ll x){
    ll pow = 1, acm=0;
    for(int i=0;i<n;i++){
        acm += abs((a[i]-pow));
        pow*=x;
    }
    if(pow<0)
        return inf;
    return acm;
}

int main(){
    

    cin >> n;
    a.assign(n,0);
    bool ordered=true;
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=1;i<n;i++)
        ordered = (ordered && (a[i]>a[i-1]));

    ll answ = teste(a[1]);
    sort(a.begin(),a.end());

    ll lim = ceil(pow(1e10,1.0/(n-1)))+1;
    
    for(int i=1;i<=lim;i++){
        answ = min(answ,teste(i));
    }

    cout << answ <<'\n';

    return 0;
}
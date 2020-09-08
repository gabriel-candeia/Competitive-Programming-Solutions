#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll l, r, x, y;
    vector<ll> bp;
    cin >> x >> y >> l >> r;
    int c1 = log(r)/log(x)+1;
    for(ll i=1;c1--;i*=x){
        int c2 = log(r)/log(y)+1;
        for(ll j=1;c2--;j*=y){
            if(i+j>=l && i+j<=r){
                bp.push_back(i+j);
            }
        }
    }
    
    sort(bp.begin(),bp.end());
    if(bp.size()==0 || bp[0]!=l)
        bp.push_back(l-1);
    if(bp.size()==0 || bp[bp.size()-1]!=r)
        bp.push_back(r+1);
    sort(bp.begin(),bp.end());
    
    ll answ=0;
    for(int i=1;i<bp.size();i++){   
        //cout << bp[i] << ' ';
        answ = max(answ,bp[i]-bp[i-1]-1);
    }
    cout << answ << '\n';
    return 0;
}
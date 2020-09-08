#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool formTriangle(ll a, ll b, ll c){
    return abs(a-c)<b && abs(a-b)<c && abs(c-b)<a;
}

int main(){
    int n;
    vector<ll> l;

    cin >> n;
    l.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> l[i];
    }

    int answ = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(l[i]!=l[j] && l[i]!=l[k] && l[j]!=l[k])
                    answ+=formTriangle(l[i],l[j],l[k]);
            }
        }
    }

    cout << answ <<'\n';

    return 0;
}
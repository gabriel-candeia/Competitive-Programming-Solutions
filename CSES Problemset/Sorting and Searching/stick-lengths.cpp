#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    vector<int> p;

    cin >> n;
    p.assign(n,0);

    for(int i=0;i<n;i++){
        cin >> p[i];
    }

    sort(p.begin(),p.end());

    ll answ=0;
    for(int i=0;i<n/2;i++){
        answ += p[n-1-i]-p[i];
    }
    cout << answ <<'\n';

    return 0;
}
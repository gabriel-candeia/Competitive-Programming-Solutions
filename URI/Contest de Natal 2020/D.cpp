#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    map<int,int> mp;

    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        mp[x]++;
    }

    int cnt  = 0, answ=0;
    for(auto p:mp){
        answ += p.second*(++cnt);
    }

    cout<<answ<<'\n';

}
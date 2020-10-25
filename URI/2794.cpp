#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<pair<int,int>> c;

    cin >> n;
    c.assign(n,{0,0});
    for(auto &x:c){
        cin >> x.first >> x.second;
    }

    sort(c.begin(),c.end());
    bool cond = true;
    for(int i=1;i<n;i++){
        if(c[i-1].second<c[i].second){
            cond = false;
        }
    }

    cout << ((cond) ? "S" : "N") <<'\n';
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int sum, n;
    vector<pair<int,int>> val;
    vector<int> answ;

    cin >> sum >> n;

    for(int i=1;i<=n;i++){
        val.push_back({i&(-i),i});
    }

    sort(val.rbegin(),val.rend());
    for(auto p : val){
        if(p.first<=sum){
            sum-=p.first;
            answ.push_back(p.second);
        }
    }

    if(sum==0){
        cout << answ.size() << '\n';
        for(auto x : answ){
            cout << x << ' ';
        }
        cout << '\n';
    }
    else{
        cout << -1 << '\n';
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<pair<int,string>> duendes;
    vector<vector<pair<int,string>>> answ;

    cin >> n;
    for(int i=0;i<n;i++){
        string s; int x;
        cin >> s >> x;
        duendes.push_back({-x,s});
    }

    answ.assign(n/3,vector<pair<int,string>>());    
    sort(duendes.begin(),duendes.end());
    for(int i=0;i<n;i++){
        answ[i%(n/3)].push_back(duendes[i]);
    }

    for(int i=0;i<n/3;i++){
        cout << "Time " << i+1 <<'\n';
        for(auto p:answ[i]){
            cout << p.second << " " << -p.first <<'\n';
        }
        cout<<'\n';
    }

    return 0;
}
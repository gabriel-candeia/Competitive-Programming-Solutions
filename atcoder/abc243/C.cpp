#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    const int inf = 1e9;
    map<int,pair<int,int>> line;
    vector<pair<int,int>> arr;
    string s;

    cin >> n;
    arr.assign(n,{0,0});
    for(auto &p:arr)
        cin >> p.first >> p.second;
    cin >> s;

    for(int i=0;i<n;i++){
        int a = arr[i].first, b = arr[i].second;
        char dir = s[i];
        if(line.find(b)==line.end()){
            line[b] = {inf,-inf};
        }
        if(dir=='L'){
            line[b].second = max(line[b].second,a);
        }
        else{
            line[b].first = min(line[b].first,a);
        }
    }

    bool ok = false;
    for(auto p:line){
        ok = ok || (p.second.first<p.second.second);
    }

    cout << ((ok) ? "Yes" : "No") << "\n";

    return 0;
}
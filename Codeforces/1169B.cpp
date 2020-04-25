#include<bits/stdc++.h>
using namespace std;

bool tentativa(vector<pair<int,int>>& p, int x){
    map<int,int> cnt;
    int invalid=0, n = p.size();

    for(int i=0;i<n;i++){
        if(p[i].first!=x && p[i].second!=x){
            invalid++;
            cnt[p[i].first]++;
            if(p[i].first!=p[i].second){
                cnt[p[i].second]++;
            }
        }
    }

    for(auto i:cnt){
        if(i.second>=invalid){
            return true;
        }
    }
    return (invalid==0);
}

int main(){
    int n, m, x, y;
    vector<pair<int,int>> p;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        p.push_back({x,y});
    }

    if(tentativa(p,p[0].first)||tentativa(p,p[0].second)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

    return 0;
}
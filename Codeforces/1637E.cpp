#include<bits/stdc++.h>
#define maxn int(3e5+5)
#define fastio()  ios_base::sync_with_stdio(false), cin.tie(NULL)
#define ll long long
using namespace std;

vector<ll> ls[maxn];

int main(){
    fastio();
    int t;

    cin >> t;
    while(t--){
        int n, m;
        map<int,int> freq;
        set<pair<int,int>> rest;

        cin >> n >> m;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            freq[x]++;
            rest.insert({x,x});
        }

        for(int i=0;i<m;i++){
            int a, b;
            cin >> a >> b;
            rest.insert({min(a,b),max(a,b)});
        }

        vector<int> id;
        for(auto p:freq){
            ls[p.second].push_back(p.first);
            id.push_back(p.second);
        }

        sort(id.begin(),id.end());
        id.erase(unique(id.begin(),id.end()),id.end());

        ll answ = 0;
        for(int iaux = 0;iaux<id.size();iaux++){
            for(int jaux=0;jaux<=iaux;jaux++){
                ll i = id[iaux], j = id[jaux];
                for(int k=0;k<ls[i].size();k++){
                    int l = ls[j].size()-1;
                    while(l>=0 && rest.find({min(ls[j][l],ls[i][k]),max(ls[j][l],ls[i][k])})!=rest.end()){
                        l--;
                    }
                    if(l>=0){
                        answ = max(answ,(i+j)*(ls[i][k]+ls[j][l]));
                    }
                }
            }
        }

        cout << answ << "\n";
        for(auto x:id){
            ls[x].clear();
        }

    }

    return 0;
}
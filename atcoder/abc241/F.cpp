#include<bits/stdc++.h>
using namespace std;

int main(){
    int h, w, n;
    pair<int,int> fst, last;
    map<pair<int,int>,int> dist;
    map<int,set<int>> line, column;


    cin >> h >> w >> n;
    cin >> fst.first  >> fst.second;
    cin >> last.first  >> last.second;

    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        line[a].insert(b);
        column[b].insert(a);
    }

    queue<pair<int,int>> q;
    q.push(fst), dist[fst] = 0;
    pair<int,int> u;

    while(q.size()){
        u = q.front(), q.pop();
        int x = u.first, y = u.second;
        vector<pair<int,int>> options;

        auto it = line[x].upper_bound(y);
        if(it!=line[x].end()){
            options.push_back({x,(*it)-1});
        }
        it = line[x].lower_bound(y);
        if(it!=line[x].begin()){
            it--;
            options.push_back({x,(*it)+1});
        }

        it = column[y].upper_bound(x);
        if(it!=column[y].end()){
            options.push_back({(*it)-1,y});
        }
        it = column[y].lower_bound(x);
        if(it!=column[y].begin()){
            it--;
            options.push_back({(*it)+1,y});
        }

        for(auto p:options){
            if(dist.find(p)==dist.end()){
                dist[p] = dist[u]+1;
                q.push(p);
            }
        }
    }

    int answ = ((dist.find(last)==dist.end()) ? -1 : dist[last]);

    cout << answ <<"\n";

    return 0;
}
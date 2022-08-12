#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    vector<array<int,3>> orcs, axes;

    cin >> n;
    orcs.assign(n,{0,0});
    int id = 0;
    for(auto &p:orcs)
        cin >> p[0]>> p[1], p[2] = ++id;
    sort(orcs.rbegin(),orcs.rend());

    cin >> m;
    axes.assign(m,{0,0});
    id = 0;
    for(auto &p:axes)
        cin >> p[0]>> p[1], p[2] = ++id;
    sort(axes.rbegin(),axes.rend());

    bool poss = true;
    vector<int> match(n+1,-1);
    int ptr = 0; //[0,ptr-1]
    set<pair<int,int>> st;
    for(int i=0;i<n;i++){
        while(ptr<axes.size() && axes[ptr][0]>=orcs[i][0]){
            st.insert({axes[ptr][1],axes[ptr][2]});
            ptr++;
        }
        auto it = st.lower_bound({orcs[i][1],-1});
        if(it!=st.end()){
            match[orcs[i][2]] = (*it).second;
            st.erase(it);
        }
        else{
            poss = false;
        }
    }

    if(poss){
        for(int i=1;i<=n;i++){
            cout << match[i] <<" ";
        }
        cout <<"\n";
    }
    else{
        cout << -1 <<"\n";
    }

    return 0;
}
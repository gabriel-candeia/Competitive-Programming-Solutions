#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    vector<pair<int,int>> item, box;

    cin >> n >> m;
    item.assign(n,{0,0});
    box.assign(m,{0,0});

    for(auto &x:item)
        cin >> x.first;
    for(auto &x:item)
        cin >> x.second;

    for(auto &x:box)
        cin >> x.first;
    for(auto &x:box)
        cin >> x.second;

    sort(item.begin(),item.end());
    sort(box.begin(),box.end());

    bool ok = true;
    multiset<int> st;

    int ptr = m;
    for(int i=n-1;i>=0;i--){
        while(ptr-1>=0 && box[ptr-1].first>=item[i].first){
            st.insert(box[ptr-1].second);
            ptr--;
        }
        auto it = st.lower_bound(item[i].second);

        if(it==st.end()){
            ok = false;
        }
        else{
            st.erase(it);
        }
    }

    cout << ((ok) ? "Yes" : "No") <<"\n";

    return 0;
}
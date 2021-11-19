#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t, caso = 0;
    cin >> t;
    while(t--){
        set<pair<ll,ll>> st;
        vector<pair<ll,ll>> arr;
        ll m, sum = 0;

        cin >> m; arr.assign(m,{0,0});
        for(auto &p:arr)
            cin >> p.first >> p.second, sum += p.first*p.second;
        st.insert({1,sum});

        for(int i=0;i<m;i++){
            set<pair<ll,ll>> add;
            for(auto p:st)
                for(ll acm=p.first, j=0;acm<=sum && j<=arr[i].second;j++, acm = acm*arr[i].first)
                    add.insert({acm,p.second-arr[i].first*j});
            st.insert(add.begin(),add.end());
        }

        ll answ = 0;
        for(auto p:st)
            if(p.first==p.second)
                answ = p.first;
        cout << st.size() << "\n";
        cout << "Case #" << ++caso << ": " << answ << '\n';
    }
    return 0;
}
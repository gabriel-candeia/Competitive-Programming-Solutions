#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> ranges;
        set<pair<int,int>> st;

        for(int i=0;i<n;i++){
            int a, b;
            cin >> a >> b;
            ranges.push_back({b,a});
        }
        st.insert({1,1e9});
        bool ok = true;
        sort(ranges.begin(),ranges.end());
        for(int i=0;i<n;i++){
            if(st.size()==0){
                ok = false;
                break;
            }

            auto it = st.lower_bound({ranges[i].second,0});
            if(it==st.begin()){
                if(ranges[i].first>=((*it)).first){
                    int mid = ((*it)).first;
                    if((*it).first+1<=(*it).second)
                        st.insert({(*it).first+1,(*it).second});
                    st.erase((*it));
                }
                else{
                    ok = false;
                    break;
                }
            }
            else{
                auto prev = st.lower_bound({ranges[i].second,0}); prev--;
                if(ranges[i].second<=(*prev).second){
                    int mid = max(ranges[i].second,(*prev).first);
                    if((*prev).first<=mid-1)
                        st.insert({(*prev).first,mid-1});
                    if((*prev).second>=mid+1)
                        st.insert({mid+1,(*prev).second});
                    st.erase(prev);
                }
                else if(it!=st.end() && ranges[i].first>=(*it).first){
                    int mid = (*it).first;
                    if((*it).first+1<=(*it).second)
                        st.insert({(*it).first+1,(*it).second});
                    st.erase((*it));
                }
                else{
                    ok = false;
                    break;
                }
            }
        }

        if(ok)
            cout << "Yes\n";
        else
            cout << "No\n";
        
    }

    return 0;
}
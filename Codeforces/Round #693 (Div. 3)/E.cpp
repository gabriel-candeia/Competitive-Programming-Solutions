#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n, x, y;
        vector<array<int,3>> arr;
        set<pair<int,int>> st;
        vector<int> answ;

        cin >> n;
        answ.assign(n,-1);
        for(int i=0;i<n;i++){
            cin >> x >> y;
            arr.push_back({x,y,i});
            arr.push_back({y,x,i});
        }

        st.insert({-1,-2});
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(i && arr[i][0]!=arr[i-1][0]){
                for(int j = i-1, cmp = arr[j][0];j>=0 && arr[j][0]==cmp;j--){
                    st.insert({arr[j][1],arr[j][2]});
                }
            }
            auto it = st.lower_bound({arr[i][1],-2}); it--;
            answ[arr[i][2]] = max((*it).second+1,answ[arr[i][2]]);
        }

        for(int i=0;i<n;i++){
            cout << answ[i] << " ";
        }cout<<'\n';

    }

    return 0;
}
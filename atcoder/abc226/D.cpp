#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<pair<int,int>> arr;
    set<pair<int,int>> st;

    cin >> n;
    for(int i=0;i<n;i++){
        int a, b, d;
        cin >> a >> b;
        arr.push_back({a,b});
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            int d = __gcd(abs(arr[i].first-arr[j].first),abs(arr[i].second-arr[j].second));
            st.insert({(arr[i].first-arr[j].first)/d,(arr[i].second-arr[j].second)/d});
        }
    }

    cout << st.size() <<"\n";   

    return 0;
}
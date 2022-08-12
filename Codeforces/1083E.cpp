#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

double tempo(const pair<ll,ll>& a, const pair<ll,ll>& b){
    return (b.second-a.second)*1.0/(a.first-b.first);
}

int main(){
    fastio();
    int n;
    vector<array<ll,3>> arr;

    cin >> n;
    arr.assign(n,{0,0,0});
    for(auto &p:arr)
        cin >> p[0] >> p[1] >> p[2];

    sort(arr.begin(),arr.end());
    int fptr = 0;
    
    vector<pair<ll,ll>> st;
    vector<ll> dp(n,0);
    dp[0] = arr[0][0]*arr[0][1] - arr[0][2];
    st.push_back({-arr[0][0],dp[0]});

    for(int i=1;i<n;i++){
        /*for(auto p:st)
            cout << p.first << " " << p.second << "| ";
        cout <<"\n";*/
        for(;fptr+1<st.size() && st[fptr].first*arr[i][1]+st[fptr].second < st[fptr+1].first*arr[i][1]+st[fptr+1].second;fptr++);
        dp[i] = arr[i][0]*arr[i][1] - arr[i][2] + st[fptr].first*arr[i][1] + st[fptr].second;
        dp[i] = max(dp[i],arr[i][0]*arr[i][1] - arr[i][2]);
        //cout << dp[i] << "\n";
        pair<ll,ll> novo = {-arr[i][0],dp[i]};
        while(st.size()>=2 && tempo(st.back(),st[st.size()-2])<=tempo(novo,st[st.size()-2])){
            st.pop_back();
        }
        st.push_back(novo);
    }

    ll answ = 0;
    for(int i=0;i<n;i++)
        answ = max(answ,dp[i]);

    cout << answ <<"\n";

    return 0;
}

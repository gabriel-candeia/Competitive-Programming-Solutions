#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll min(ll a, ll b){
    return (a>b) ? b : a;   
}

vector<ll> cnt1, cnt2;

int main(){
    ll q, n, c, f;

    cin >> q;
    while(q--){
        cin >> n;

        vector<pair<ll,ll>> s;
        cnt1.assign(n+1,0);
        cnt2.assign(n+1,0);

        for(int i=0;i<n;i++){
            cin >> c >> f;
            cnt1[c]++;
            cnt2[c]+=f;
        }

        for(int i=0;i<=n;i++){
            if(cnt1[i]){
                s.push_back({cnt1[i],cnt2[i]});
            }
        }
        
        ll curr = 0, answ = 0, lost = 0, l = s.size()-1;
        priority_queue<ll> h;
        sort(s.begin(),s.end());
        curr = s.back().first;
        
        /*for(auto x:s){
            cout << x.second << " ";
        }cout << '\n';*/

        while((l>=0 || h.size()) && curr>0){
            while(l>=0 && s[l].first>=curr){
                h.push(s[l--].second);
            }
            answ += curr;
            lost += min(h.top(),curr); h.pop();

            if(h.size()==0 && l>=0){
                curr = s[l].first;
            }
            else{
                curr--;
            }
        }
        
        cout << answ << " " << lost << "\n";
    }

    return 0;
}
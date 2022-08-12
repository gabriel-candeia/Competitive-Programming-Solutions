#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e17;

int tempo(pair<ll,ll> a, pair<ll,ll> b){
    return (b.second-a.second)/(a.first-b.first) + (((b.second-a.second)%(a.first-b.first))!=0);
}

int main(){
    int n;
    vector<ll> a, b;

    cin >> n;
    a.assign(n,0), b.assign(n,0);
    for(auto &x:a)
        cin >> x;
    for(auto &x:b)
        cin >> x;

    vector<ll> answ(n+1,inf);
    int fptr = 0;
    vector<pair<ll,ll>> st;
    answ[0] = 0, st.push_back({b[0],answ[0]});

    for(int i=1;i<n;i++){
        while(fptr+1!=st.size() && st[fptr].first*a[i]+st[fptr].second > st[fptr+1].first*a[i]+st[fptr+1].second){
            fptr++;
        }

        answ[i] = st[fptr].first*a[i]+st[fptr].second;
        pair<ll,ll> novo = {b[i],answ[i]};
        while(st.size()>=2 && (tempo(st[st.size()-2],st[st.size()-1]) >= tempo(st[st.size()-2],novo))){
            st.pop_back();
        }
        st.push_back(novo);
    }

    cout << answ[n-1] <<"\n";

    return 0;
}
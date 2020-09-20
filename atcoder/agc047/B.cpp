#include<bits/stdc++.h>
#define ll long long
using namespace std;
//C A G A D A
const ll p = 31, m = 18014398241046527;
unordered_map<ll,ll> cnt;

ll compute_hash(string& s){
    vector<int> letras(27,0);
    ll pref = 0;
    int n = s.size();
    for(int i=0;i<n;i++){
        letras[s[i]-'a'+1]++;
    }

    for(int j=1;j<27;j++){
        if(letras[j]){
            cnt[(pref*p+j)%m]++;
        }
    }
    for(int i=n-1;i>=0;i--){
        pref = ((pref*p)%m+(s[i]-'a'+1))%m;
        letras[s[i]-'a'+1]--;
        for(int j=1;j<27;j++){
            if(letras[j]){
                cnt[((pref*p)%m+j)%m]++;
            }
        }
    }
    return pref;
}

int main(){
    int n;
    vector<string> arr;
    vector<ll> hs;

    cin >> n;
    arr.assign(n,string());
    hs.assign(n,0);
    cnt.reserve(int(26*1e6)+5);
    for(int i=0;i<n;i++){
        cin >> arr[i];
        hs[i] = compute_hash(arr[i]);
    }

    ll answ = 0;
    for(int i=0;i<n;i++){
        answ += cnt[hs[i]]-1;
    }

    cout << answ << '\n';

    

    return 0;
}
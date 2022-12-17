#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n,0);
        for(auto&x:arr)
            cin >> x;
        map<int,ll> freq;
        for(auto x:arr)
            freq[x]++;

        ll answ = 0, acm = 0;
        for(auto p:freq){
            acm +=p.second;
            answ = max(answ,(n-acm)*acm);
        }

        if(freq.size()==1){
            answ = max(answ,freq[arr[0]]/2);
        }

        cout << answ <<"\n";
    }

    return 0;
}
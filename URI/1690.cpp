#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int main(){
    fastio();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> arr(n,0);
        for(auto &x:arr)
            cin >> x;

        sort(arr.begin(),arr.end());
        pair<ll,ll> rng = {0,0}, aux;
        ll answ = -1;

        for(int i=0;i<n;i++){
            aux = {rng.first+arr[i],rng.second+arr[i]};
            if(aux.first-rng.second>1)
                answ = rng.second+1;
            else
                rng.second = aux.second;
        }

        if(answ==-1)
            answ = rng.second+1;

        cout << answ <<"\n";
    }

    return 0;
}
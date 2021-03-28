#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        vector<ll> answ;
        vector<pair<ll,ll>> arr;

        cin >> n;
        arr.assign(n,{0,0}), answ.assign(n,0);

        ll sum =  0;
        for(int i=0;i<n;i++){
            cin >> arr[i].first;
            arr[i].second = i;
            sum += arr[i].first;
        }

        sort(arr.begin(),arr.end());
        answ[arr[n-1].second] = 1;
        sum -= arr[n-1].first;
        for(int i=n-2;i>=0;i--){
            answ[arr[i].second] = ((sum>=arr[i+1].first) ? answ[arr[i+1].second] : 0);
            sum-=arr[i].first;
        }
        cout << accumulate(answ.begin(),answ.end(),0) << "\n";
        for(int i=0;i<n;i++)
            if(answ[i])
                cout << i+1 << " ";
        cout<<'\n';
    }

    return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int mod;

vector<ll> subsets(vector<ll> arr){
    int n = arr.size();
    vector<ll> answ;
    for(int msk=0;msk<(1<<n);msk++){
        ll acm = 0;
        for(int i=0;i<n;i++)
            if(msk&(1<<i))
                acm = (acm+arr[i])%mod;
        answ.push_back(acm);
    }
    return answ;
}

int main(){
    int n;
    vector<ll> arr1, arr2;

    cin >> n >> mod;
    arr1.assign(n/2,0);
    arr2.assign(n-n/2,0);

    for(auto &x:arr1)   
        cin >> x;
    for(auto &x:arr2)   
        cin >> x;

    ll answ = 0;
    auto sub1 = subsets(arr1), sub2 = subsets(arr2);
    sort(sub1.begin(),sub1.end());
    sort(sub2.begin(),sub2.end());

    for(int i=0;i<sub1.size();i++){
        int j = (lower_bound(sub2.begin(),sub2.end(),mod-sub1[i])-sub2.begin())-1;
        j = max(j,0);
        answ = max(answ,sub1[i]+sub2[j]);
    }

    cout << answ <<"\n";

    return 0;
}
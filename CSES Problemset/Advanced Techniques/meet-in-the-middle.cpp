#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> merge(vector<ll> a, vector<ll> b){
    vector<ll> answ;
    while(a.size() && b.size()){
        if(a.back()>b.back())
            answ.push_back(a.back()), a.pop_back();
        else
            answ.push_back(b.back()), b.pop_back();
    }

    while(a.size())
        answ.push_back(a.back()), a.pop_back();

    while(b.size())
        answ.push_back(b.back()), b.pop_back();

    reverse(answ.begin(),answ.end());
    return answ;
}

vector<ll> subsets(vector<ll> arr){
    int n = arr.size();
    vector<ll> answ = {0};
    for(auto x:arr){
        vector<ll> temp;
        for(auto y:answ)
            temp.push_back(x+y);
        answ = merge(answ,temp);
    }
    return answ;
}

int main(){
    int n;
    ll x;
    vector<ll> arr1, arr2;

    cin >> n >> x;
    arr1.assign(n/2,0);
    arr2.assign(n-n/2,0);
    
    for(auto &x:arr1)
        cin >> x;
    for(auto &x:arr2)
        cin >> x;

    auto sub1 = subsets(arr1), sub2 = subsets(arr2);

    ll answ = 0, rhi = sub2.size()-1, rlo = sub2.size()-1;
    for(int l=0;l<sub1.size();l++){
        while(rhi>=0 && sub1[l]+sub2[rhi]>x) rhi--;
        while(rlo>=0 && sub1[l]+sub2[rlo]>=x) rlo--;
        answ += (rhi-rlo);
    }

    cout << answ <<"\n";

    return 0;
}
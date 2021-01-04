#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, t;
vector<ll> arr;

vector<ll> merge(vector<ll>& a, vector<ll>& b){
    vector<ll> c;
    int i=0,j=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j])
            c.push_back(a[i++]);
        else
            c.push_back(b[j++]);
    }

    while(i<a.size())
        c.push_back(a[i++]);

    while(j<b.size())
        c.push_back(b[j++]);

    return c;
}

vector<ll> solve(int first, int last){
    vector<ll> answ(1,0);
    for(int i=first;i<last;i++){
        vector<ll> copia;
        for(auto p:answ)
            copia.push_back(p+arr[i]);
        answ = merge(answ,copia);
    }
    return answ;
}

int main(){ 
    cin >> n >> t;
    arr.assign(n+1,0);
    for(auto &x:arr)
        cin >> x;

    vector<ll> s1 = solve(0,n/2), s2 = solve(n/2,n);
    ll i=0, j = s2.size()-1, answ=0;
    for(;i<s1.size();i++){
        while(j>=0 && s1[i]+s2[j]>t)
            j--;
        if(j>=0 && s1[i]+s2[j]<=t)
            answ = max(answ,s1[i]+s2[j]);
    }
    cout << answ <<'\n';
    return 0;
}
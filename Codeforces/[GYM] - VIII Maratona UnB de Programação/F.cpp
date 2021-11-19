#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> arr, lst, nxt;

bool solve(int l, int r){
    if(r<=l) return true;
    for(int l1=l,r1=r;l1<=r1;l1++,r1--){
        if(lst[l1]<l && r<nxt[l1])
            return (solve(l,l1-1)&&solve(l1+1,r));
        if(lst[r1]<l && r<nxt[r1])
            return (solve(l,r1-1)&&solve(r1+1,r));
    }
    return false;
}

int main(){
    cin >> n;

    arr.assign(n,0), lst.assign(n,-1), nxt.assign(n,n+1);
    for(auto &x:arr)
        cin >> x;

    map<int,int> mp;
    for(int i=0;i<n;i++){
        if(mp.find(arr[i])!=mp.end())
            lst[i] = mp[arr[i]];
        mp[arr[i]] = i;
    }
    mp.clear();
    for(int i=n-1;i>=0;i--){
        if(mp.find(arr[i])!=mp.end())
            nxt[i] = mp[arr[i]];
        mp[arr[i]] = i;
    }

    cout << (solve(0,n-1) ? "Y" : "N") << '\n';

    return 0;
}


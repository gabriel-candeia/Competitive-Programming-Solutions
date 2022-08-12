#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n, k;
    vector<int> arr, nxt, seq;
    map<int,int> mp;

    cin >> n >> k;
    arr.assign(n,0);
    nxt.assign(n,n);
    seq.assign(n+1,0);
    for(auto &x:arr)
        cin >> x;

    for(int i=n-1;i>=0;i--){
        if(mp.find(arr[i])!=mp.end()){
            nxt[i] = mp[arr[i]];
            seq[nxt[i]] = 0;
        }
        seq[i] = 1;
        mp[arr[i]] = i;
    }
    
    seq[n] = n;
    ll answ = 0;    
    int l = 0, somaL=0, r=0, somaR=0;
    for(int i=0;somaL<k;i++)
        l++, somaL+=seq[i];

    for(int i=0;somaR<=k;i++)
        r++, somaR+=seq[i];
    l--, r--;
    for(int i=0;i<n;i++){
        //cout << i << " " << l << " "  << r <<" ";
        answ += r-l;
        seq[i] = 0;
        if(nxt[i]<n) seq[nxt[i]] = 1;
        somaL += (nxt[i]<=l) - 1; 
        somaR += (nxt[i]<=r) - 1;
        //cout << somaL << " " << somaR <<"\n";
        while(r<n && somaR<=k){
            r++;
            somaR += seq[r];
        }
        while(l<n && somaL<k){
            l++;
            somaL += seq[l];
        }
    }

    cout << answ << "\n";

    return 0;
}
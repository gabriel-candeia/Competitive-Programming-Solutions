#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

int arr[maxn], n;
int best[2];
int val = -1;
int cnt(int i,bool flag=false){
    map<int,int> mp;
    for(;i<n;i+=2){
        mp[arr[i]]++;
    }
    int mx=0, total=0;
    for(auto p:mp){
        total+=p.second;
        if(p.second>mx && (!flag || p.first!=val)){
            mx = p.second;
            if(flag==false) 
                val = p.first;
        }
    }
    return total-mx;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << min(cnt(0)+cnt(1,true),cnt(1)+cnt(0,true)) <<'\n';
    return 0;
}
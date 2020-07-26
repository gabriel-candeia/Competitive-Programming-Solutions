#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int n, mn = 0;
    vector<int> arr;

    cin >> n >> s;
    arr.assign(n,0);
    for(int i=1;i<n;i++){
        arr[i] = ((s[i-1]=='A') ? 1 : -1);
        arr[i]+=arr[i-1];
        mn = min(arr[i],mn);
    }

    for(int i=0;i<n;i++){
        arr[i]-=mn;
    }

    for(auto x:arr){
        cout << x << " ";
    }cout << '\n';

    return 0;
}
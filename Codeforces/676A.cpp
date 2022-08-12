#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> arr;

    cin >> n;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    int mn = 0, mx = 0;
    for(int i=0;i<n;i++){
        if(arr[mn]>arr[i]) mn = i;
        if(arr[mx]<arr[i]) mx = i;
    }
    
    int answ = abs(mx-mn);
    for(int i=0;i<n;i++){
        if(i==mx) continue;
        answ = max(abs(mx-i),answ);
    }

    for(int i=0;i<n;i++){
        if(i==mn) continue;
        answ = max(abs(mn-i),answ);
    }

    cout << answ <<"\n";

    return 0;
}
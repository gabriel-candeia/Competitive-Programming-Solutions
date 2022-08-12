#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, wt;
    vector<int> arr;

    cin >> n >> wt;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;
    
    set<int> answ;
    
    for(int i=0;i<n;i++){
        if(arr[i]<=wt) answ.insert(arr[i]);
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]<=wt) answ.insert(arr[i]+arr[j]);
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k]<=wt) answ.insert(arr[i]+arr[j]+arr[k]);
            }
        }
    }
    cout << answ.size() <<"\n";
    return 0;
}
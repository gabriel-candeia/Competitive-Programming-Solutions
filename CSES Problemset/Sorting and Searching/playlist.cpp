#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, l=0, r=0;
    vector<int> arr;
    set<int> seen;

    cin >> n;
    arr.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int answ = 0;
    while(r<n){
        if(seen.count(arr[r])==0){
            seen.insert(arr[r++]);
            answ = max(answ,r-l);
        }
        else{
            seen.erase(arr[l++]);
        }
    }

    cout << answ <<'\n';

    return 0;
}
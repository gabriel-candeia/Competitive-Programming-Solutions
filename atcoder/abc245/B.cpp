#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> arr;

    cin >> n;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    sort(arr.begin(),arr.end());

    int answ = 0;
    for(int i=0;i<n;i++){
        if(answ==arr[i]){
            answ++;
        }
        else if(answ<arr[i]){
            break;
        }
    }

    cout << answ <<"\n";

    return 0;
}
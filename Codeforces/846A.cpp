#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, cnt1=0, answ=0, cnt0=0;
    vector<int> arr;

    cin >> n;
    arr.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
        cnt1+=arr[i];
    }

    answ = cnt1;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            cnt0++;
        }
        else{
            cnt1--;
        }
        answ = max(answ,cnt0+cnt1);
    }

    cout << answ << '\n';

    return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll a, b;

    cin >> a >> b;

    vector<ll> nums = {2,5};
    vector<vector<ll>> arr(2,vector<ll>(100,0));
    for(int k=0;k<2;k++){
        ll pot = nums[k];
        for(int i=0;pot <= b;i++){
            arr[k][i] = b/pot - (a-1)/pot;
            pot = pot*nums[k];
        }
    }
    int answ = 0;
    for(int i=0;i<100;i++){
        if(arr[0][i]>0 && arr[1][i]>0){
            answ = i+1;
        }
    }

    cout << answ <<"\n";

    return 0;
}
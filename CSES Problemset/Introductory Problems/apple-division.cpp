#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll calc(vector<int>& arr, int i, ll acm){
    if(i==arr.size()){
        return abs(acm);
    }
    return min(calc(arr,i+1,acm+arr[i]),calc(arr,i+1,acm-arr[i]));
}

int main(){
    int n;
    vector<int> arr;

    cin >> n;
    arr.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << calc(arr,0,0) << '\n';

    return 0;
}
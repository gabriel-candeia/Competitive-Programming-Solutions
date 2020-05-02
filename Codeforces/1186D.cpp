#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    int n;
    ll sum=0;
    double x;
    vector<bool> isInteger;
    vector<int> arr;
    
    cin >> n;
    isInteger.assign(n,false);
    for(int i=0;i<n;i++){
        cin >> x;
        sum += floor(x);
        isInteger[i] = (floor(x) == x);
        arr.push_back(floor(x));
    }

    for(int i=0;i<n;i++){
        if(sum<0 && isInteger[i]==false){
            cout << arr[i]+1 << '\n';
            sum++;
        }
        else{
            cout << arr[i] << '\n';
        }
    }

    return 0;
}
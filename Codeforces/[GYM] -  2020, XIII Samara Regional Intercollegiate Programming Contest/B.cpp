#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n, t; 
    vector<vector<ll>> arr;

    cin >> n >> t;
    arr.assign(2,vector<ll>());
    for(int i=0;i<n;i++){
        ll x;
        cin >> x;
        if(x>0)
            arr[0].push_back(x);
        else
            arr[1].push_back(-x);
    }
    
    sort(arr[1].begin(),arr[1].end());
    
    int answ = 0;
    for(int curr=0;curr<2;curr++){
        int prox = 1-curr;
        for(int i=0, j=arr[prox].size()-1;i<arr[curr].size();i++){
            while(j>=0 && 2*arr[curr][i]+arr[prox][j]>t){
                j--;
            }
            if(j>=0 && 2*arr[curr][i]+arr[prox][j]<=t){
                answ = max(answ,i+1+j+1);
                
            }
            else if(arr[curr][i]<=t){
                answ = max(answ,i+1);
            }

        }
    }
    
    cout << answ << "\n";

    return 0;
}
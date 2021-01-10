#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n[3], sum=0, answ = 0;
    vector<vector<ll>> arr;
    vector<ll> soma;
    for(int i=0;i<3;i++)
        cin >> n[i];

    ll x;
    arr.assign(3,vector<ll>()); soma.assign(3,0);
    for(int i=0;i<3;i++){
        for(int j=0;j<n[i];j++){
            cin >> x;
            arr[i].push_back(x);
            sum+=x;
            soma[i]+=x;
        }
        sort(arr[i].begin(),arr[i].end());
    }

    for(int i=0;i<3;i++)
        for(int j=i+1;j<3;j++)
            answ = max(answ,sum-2*arr[i][0]-2*arr[j][0]);
    
    for(int i=0;i<3;i++){
        if(arr[i].size()>1){
            answ = max(answ,sum-2*arr[i][0]-2*arr[i][1]-2*min(arr[(i+1)%3][0],arr[(i+2)%3][0])*(arr[i].size()>2));
            answ = max(answ,sum-2*soma[i]);
        }
        if(arr[i].size()==1){
            answ = max(answ,sum-2*arr[i][0]);
        }
    }

    cout << answ <<'\n';

    return 0;
}
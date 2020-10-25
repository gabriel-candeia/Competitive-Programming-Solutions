#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    vector<pair<ll,ll>> arr;

    cin >> n;
    arr.assign(n,{0,0});
    for(int i=0;i<n;i++)
        cin >> arr[i].first >> arr[i].second;

    int answ=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        ll mn = 1e15, mx = -1e15;
        for(int j=i+1;j<n;j++){
            if(arr[j].second<=arr[i].second && mx<arr[j].second){
                answ++;
            }
            if(arr[j].second>arr[i].second && mn>arr[j].second){
                answ++;
            }
            if(arr[j].second<=arr[i].second){
                mx = max(arr[j].second,mx);
            }
            if(arr[j].second>=arr[i].second){
                mn = min(arr[j].second,mn);
            }
        }
    }

    cout << answ <<'\n';

    return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    map<pair<int,int>, int>  freq;
    vector<pair<int,int>> arr;

    cin >> n;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        arr.push_back({a,b});
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            freq[{arr[i].first+arr[j].first,arr[i].second+arr[j].second}]++;
        }
    }

    ll answ = 0;
    for(auto p:freq){
        answ += p.second*(p.second-1);
    }

    answ/=2;
    cout  << answ <<"\n";

    return 0;
}
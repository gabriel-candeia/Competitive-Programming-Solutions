#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool teste(pair<ll,ll> a, pair<ll,ll> b, pair<ll,ll> c){
    return (b.first+c.first <= a.first && max(b.second,c.second) <= a.second);
}

int main(){
    vector<pair<ll,ll>> arr(3);

    bool answ = 0;
    for(int i=0;i<3;i++)
        cin >> arr[i].first >> arr[i].second;

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                answ |= teste(arr[0],arr[1],arr[2]);
                swap(arr[2].first,arr[2].second);
            }
            swap(arr[1].first,arr[1].second);
        }
        swap(arr[0].first,arr[0].second);
    }

    cout << (answ ? "YES" : "NO") << '\n';


    return 0;
}
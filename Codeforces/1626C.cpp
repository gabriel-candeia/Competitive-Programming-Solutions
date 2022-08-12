#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        cin >> n;

        ll answ = 0;
        vector<pair<ll,ll>> arr;
        arr.assign(n,{0,0});
        for(int i=0;i<n;i++)
            cin >> arr[i].first;

        for(int i=0;i<n;i++){
            cin >> arr[i].second;
            arr[i].first=arr[i].first-arr[i].second+1;
        }

        sort(arr.begin(),arr.end());
        pair<ll,ll> last = {0,0};
        for(auto p:arr){
            //cout << last.first << " " << last.second <<"\n";
            if(p.first>last.first+last.second-1){
                answ += (last.second*(last.second+1))/2;
                last = {p.first,p.second};
            }
            else{
                last = max(last,{last.first,p.first+p.second-last.first});
            }
        }
        //cout << last.first << " " << last.second <<"\n";
        //cout <<"\n";

        answ += (last.second*(last.second+1))/2;

        cout << answ <<"\n";
    }

    return 0;
}
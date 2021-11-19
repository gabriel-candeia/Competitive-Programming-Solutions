#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);
        for(auto &x:arr)
            cin >> x;

        
        map<int,int> mp;
        ll answ = 0;
        for(int i=0;i<n;i++){
            answ += mp[arr[i]-i];
            mp[arr[i]-i]++;
        }

        cout << answ << "\n";   
    }

    return 0;
}
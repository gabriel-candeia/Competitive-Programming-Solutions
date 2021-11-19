#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        string s;
        map<int,int> mp;

        cin >> n >>  s;
        int acm = 0;
        pair<int,int> answ = {-1,-1};
        mp[0] = -1;
        for(int i=0;i<n;i++){
            acm += (s[i]=='a') ? 1 : -1;
            if(mp.find(acm)!=mp.end()){
                answ = {mp[acm]+2,i+1};
                break;
            }
            mp[acm] = i;
        }

        cout << answ.first << " " << answ.second <<"\n";

    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        map<int,int> mp;
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            mp[abs(x)]++;
        }

        int answ = 0;
        for(auto &p:mp){
            if(p.first!=0)
                answ += min(p.second,2);
            else
                answ ++;
        }

        cout << answ <<"\n";

    }

    return 0;
}
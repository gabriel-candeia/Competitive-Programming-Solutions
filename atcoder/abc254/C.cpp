#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    map<int,multiset<int>> mp;

    cin >> n >> k;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        mp[x].insert(i%k);
    }

    int cnt = 0;

    bool ok = true;
    for(auto &p:mp){
        while(p.second.size()){
            if(p.second.find(cnt)==p.second.end()){
                ok = false;
                break;
            }
            p.second.erase(p.second.find(cnt));
            cnt = (cnt+1)%k;
        }
    }

    cout << ((ok) ? "Yes" : "No") <<"\n";

    return 0;
}
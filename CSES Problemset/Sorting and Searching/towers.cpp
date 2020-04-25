#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> k;
    multiset<int> tops;

    cin >> n;
    k.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> k[i];
    }

    for(int i=0;i<n;i++){
        auto it = tops.upper_bound(k[i]);
        if(it!=tops.end()){
            tops.erase(it);
        }
        tops.insert(k[i]);
    }

    cout << tops.size() <<'\n';

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    map<int,int> mp;

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> x;
        mp[x] = i;
    }

    for(int i=1;i<=n;i++){
        cout << mp[i] << ' ';
    }
    cout << '\n';

    return 0;
}
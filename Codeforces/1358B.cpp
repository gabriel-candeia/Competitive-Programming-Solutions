#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    vector<int> a;

    cin >> t;
    while(t--){
        cin >> n;
        a.assign(n,0);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        sort(a.rbegin(),a.rend());
        int answ = n+1;
        for(int i=0;i<n && a[i]>=answ;i++, answ--);

        cout << answ << '\n';
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &x:a)
            cin >> x;
        int last = n+1, answ = 0;
        for(int i=0;i<n;i++){
            if(a[i]){
                answ += max(i-1-last,0);
                last = i;
            }
        }
        cout << answ <<'\n';
    }

    return 0;
}
#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

int main(){
    fastio();
    int t;

    cin >> t;
    while(t--){
        int n;
        vector<int> mn, arr;
        string s;

        cin >> s;
        n = s.size();
        mn.assign(n+1,0), arr.assign(n+1,0);

        for(int i=n-1;i>=0;i--){
            arr[i] = (s[i]=='B' ? 1 : -1) + arr[i+1];
            mn[i] = min((s[i]=='B' ? 1 : -1),(s[i]=='B' ? 1 : -1)+mn[i+1]);
        }

        int answ = -1, acm = 0, minimo=0;
        for(int i=0;i<n;i++){
            acm += (s[i]=='B' ? 1 : -1);
            minimo = min(acm,minimo);
            if(minimo+arr[i+1]>=0 && mn[i+1]>=0){
                answ = i+1;
                break;
            }
        }

        if(minimo>=0)
            answ = 0;

        cout << answ <<"\n";
    }

    return 0;
}
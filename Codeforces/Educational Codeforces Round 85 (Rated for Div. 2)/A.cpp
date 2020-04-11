#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    int lp, lc, p, c;
    bool poss;
    cin >> t;
    while(t--){
        cin >>  n;
        
        lp = 0;
        lc = 0;
        poss = true;

        while(n--){
            cin >> p >> c;
            poss *= (lp<=p && lc <= c && c<=p && c-lc <= p-lp);
            lp = p;
            lc = c;
        }

        cout << ((poss) ? "YES" : "NO") <<'\n';
    }
    return 0;
}
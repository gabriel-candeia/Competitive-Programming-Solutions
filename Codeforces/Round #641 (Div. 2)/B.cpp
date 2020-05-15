#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, lim, ot;
    vector<int> s;
    vector<int> best;

    cin >> t;
    while(t--){
        cin >> n;
        s.assign(n+1,0);
        best.assign(n+1,1);
        for(int i=1;i<=n;i++){
            cin >> s[i];
        }

        for(int i=n;i>=1;i--){
            lim = sqrt(i)+1;
            for(int j=1;j<=lim;j++){
                if(i%j==0){
                    ot = i/j;
                    if(s[i]>s[j]){
                        best[j] = max(best[j],1+best[i]);    
                    }
                    if(s[i]>s[ot]){
                        best[ot] = max(best[ot],1+best[i]);    
                    }
                }
            }
        }

        int answ=0;
        for(int i=0;i<=n;i++){
            answ = max(answ,best[i]);
        }

        cout << answ << '\n';
    }
    return 0;
}
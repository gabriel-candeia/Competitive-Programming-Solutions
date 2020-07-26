#include<bits/stdc++.h>
#define N 100
using namespace std;

int main(){ 
    int n, k, b[N], cnt[N];

    while(cin >> n >> k){
        if(n==0 && k==0) break;
        for(int i=0;i<k;i++) cin >> b[i];

        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                cnt[abs(b[i]-b[j])]++;
            }    
        }

        bool poss = true;
        for(int i=0;i<=n;i++){
            poss *= (cnt[i]!=0);   
        }
        
        cout << ((poss) ? "Y" : "N" ) << '\n';
    }

    return 0;
}
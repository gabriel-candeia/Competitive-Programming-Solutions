#include<bits/stdc++.h>
#define N int(1e5)+3
using namespace std;

int main(){
    int t, n, a[N], b[N];
    int cntPlus=0, cntMinus=0;
    bool flag;
    cin >> t;
    while(t--){
        cin >> n;
        cntPlus=0; cntMinus=0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            cntPlus+=(a[i]==1);
            cntMinus+=(a[i]==-1);
        }

        for(int i=0;i<n;i++){
            cin >> b[i];
        }

        flag = true;
        for(int i=n-1;i>=0 && flag;i--){
            cntPlus-=(a[i]==1);
            cntMinus-=(a[i]==-1);
            if((a[i] < b[i] && !cntPlus) || (a[i] > b[i]  && !cntMinus)){
                flag = false;
            }
        }
        cout << ((flag) ? "YES" : "NO") << '\n';
    }

    return 0;
}
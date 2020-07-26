#include<bits/stdc++.h>
#define N 20
using namespace std;

int main(){
    int cnt[N], k;
    char a;

    cin >> k;
    for(int i=0;i<=9;i++){
        cnt[i] = 0;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin >> a;
            if('0'<=a && a<='9'){
                cnt[a-'0']++;
            }
        }
    }

    bool poss = true;
    for(int i=0;i<=9;i++){
        poss *= (cnt[i]<=2*k);
    }

    cout << ((poss) ? "YES" : "NO") << '\n';

    return 0;
}
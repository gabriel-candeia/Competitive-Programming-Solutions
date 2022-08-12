#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n, m, r, c, answ = 3;

        cin >> n >> m >> r >> c;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char a;
                cin >> a;
                if(a=='B'){
                    answ = min(answ,2);
                    if(i==r && j==c){
                        answ = min(answ,0);
                    }
                    else if(i==r || j==c){
                        answ = min(answ,1);
                    }
                }
            }
        }
        if(answ==3) answ = -1;
        cout << answ <<"\n";
    }

    return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int mat[2][3];

int det(){
    return (mat[0][0]*mat[1][1] - mat[1][0]*mat[0][1]);
}

int main(){
    int t;
    cin >> t;

    while(t--){
        ll dx[6] = {1,0,-1,-1,0,1}, dy[6] = {1,1,0,-1,-1,0}, c[6];
        ll x, y, answ = LLONG_MAX, dirx, diry;
        cin >> x >> y;
        for(int i=0;i<6;i++)
            cin >> c[i];
    
        for(int i=0;i<6;i++){
            for(int j=0;j<6;j++){
                ll r, t, d;
                mat[0][0] = dx[i]; mat[0][1] = dx[j];
                mat[1][0] = dy[i]; mat[1][1] = dy[j];
                d = det();
                
                mat[0][0] = x; mat[0][1] = dx[j];
                mat[1][0] = y; mat[1][1] = dy[j];
                r = det();

                mat[0][0] = dx[i]; mat[0][1] = x;
                mat[1][0] = dy[i]; mat[1][1] = y;
                t = det();
                if(d && t/d>=0 && r/d>=0){
                    t/=d;
                    r/=d;
                    answ = min(answ,r*c[i]+t*c[j]);
                }
            }
        }
        cout << answ <<'\n';

    }
    



    return 0;
}
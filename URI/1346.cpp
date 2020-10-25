#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define maxn 405
#define maxm int(4e5+5)
using namespace std;

int dp[2][maxm][2], n, arr[maxn], aux[maxn], arrx[maxn], arry[maxn];

int main(){
    fastio();
    while(cin >> n){
        if(n==0)
            break;
        int x, y, total=0;
        for(int i=0;i<n;i++){
            cin >> x >> y;
            arrx[i] = x; arry[i] = y;
            arr[i] = abs(x-y);
            aux[i] = x+y;
            total += x+y;
        }

        memset(dp,0,sizeof(dp));
        dp[0][0][0] = 1;

        for(int i=0;i<n;i++){
            int atual = i%2, prox = (i+1)%2;
            for(int j=0;j<maxm;j++){
                if(dp[atual][j][0]){
                    if(j+arr[i]<maxm)
                        dp[prox][j+arr[i]][0] = 1;
                    dp[prox][abs(j-arr[i])][0] = 1;

                    if(!dp[prox][j][1])
                        dp[prox][j][1] = aux[i];
                    else
                        dp[prox][j][1] = min(aux[i],dp[prox][j][1]);
                }
                dp[atual][j][0] = 0;
            }
            for(int j=0;j<maxm;j++){
                if(dp[atual][j][1]){
                    if(dp[prox][j+arr[i]][1]==0)
                        dp[prox][j+arr[i]][1] = dp[atual][j][1];
                    dp[prox][j+arr[i]][1] = min(dp[prox][j+arr[i]][1],dp[atual][j][1]);

                    if(dp[prox][abs(j-arr[i])][1]==0)
                        dp[prox][abs(j-arr[i])][1] = dp[atual][j][1];
                    dp[prox][abs(j-arr[i])][1] = min(dp[prox][abs(j-arr[i])][1],dp[atual][j][1]);
                    
                }
                dp[atual][j][1] = 0;
            }
        }
        
        if(dp[n%2][0][0]){
            cout << total/2 << " discard none\n";
        }
        else if(dp[n%2][0][1]){        
            cout << (total-dp[n%2][0][1])/2 << " discard ";
            for(int i=0;i<maxn;i++){
                if(aux[i]==dp[n%2][0][1]){
                    cout << min(arrx[i],arry[i]) << " " << max(arrx[i],arry[i]) << "\n";
                    break;
                }
            }
        }
        else{
            cout << "impossible\n";
        }
    }
    return 0;
}

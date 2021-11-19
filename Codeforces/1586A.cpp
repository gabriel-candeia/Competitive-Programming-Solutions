#include<bits/stdc++.h>
#define maxn int(2e4+5)
#define maxm 101
using namespace std;

int dp[maxm][maxn], parent[maxm][maxn], prime[maxn];

int main(){
    int t;

    cin >> t;
    prime[0] = prime[1] = 0;
    for(int i=2;i<maxn;i++){
        if(prime[i]==0){
            for(int j=2*i;j<maxn;j+=i){
                prime[j] = 1;
            }
        }
    }
    
    while(t--){
        int n;
        vector<int> arr;

        cin >> n;
        arr.assign(n,0);
        for(auto &x:arr)
            cin >> x;
        memset(dp,0,sizeof(dp));
        memset(parent,0,sizeof(parent));
    
        dp[0][0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<maxn;j++){
                dp[i][j] = dp[i-1][j];
                if(j-arr[i-1]>=0 && dp[i-1][j-arr[i-1]]>=dp[i][j] && dp[i-1][j-arr[i-1]]!=0){
                    dp[i][j] = dp[i-1][j-arr[i-1]]+1;
                    parent[i][j] = 1;
                }
            }
        }

        int answ = -1;
        for(int j=maxn-1;j>=0;j--){       
            if(dp[n][j] && prime[j]){
                if(answ==-1 || dp[n][answ]<dp[n][j]){
                    answ = j;
                }
            }
        }

        vector<int> resp;
        for(int i=n, j = answ;i>0;i--){
            if(parent[i][j]==1){
                resp.push_back(i);
                j = j-arr[i-1];
            }
        }
        
        cout << resp.size() << "\n";
        for(auto x:resp)
            cout << x <<" ";
        cout<<"\n";
    }

    return 0;
}
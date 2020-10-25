#include<bits/stdc++.h>
#define maxn 4005
using namespace std;

int dp1[maxn][maxn], dp2[maxn][maxn];
string s;
vector<int> arr;
int m, n, x;

int solve(int l, int r){
    if(dp1[l][r]!=-1){
        return dp1[l][r];
    }
    if(r-l+1==1){
        dp2[l][r] = 1;
        return dp1[l][r] = arr[l];
    }
    if(r-l+1==2 && s[l]==s[r]){
        dp2[l][r] = 2;
        return dp1[l][r] = arr[l]+arr[r];
    }
    if(s[l]==s[r]){
        dp1[l][r] = solve(l+1,r-1)+arr[l]+arr[r];
        dp2[l][r] = dp2[l+1][r-1]+2;
    }
    if(l+1<=r && solve(l+1,r)>=dp1[l][r]){
        if(dp1[l+1][r]==dp1[l][r]){
            dp2[l][r] = max(dp2[l][r],dp2[l+1][r]);
        }
        else{
            dp2[l][r] = dp2[l+1][r];
        }
        dp1[l][r] = dp1[l+1][r];
    }
    if(l<=r-1 && solve(l,r-1)>=dp1[l][r]){
        if(dp1[l][r-1]==dp1[l][r]){
            dp2[l][r] = max(dp2[l][r],dp2[l][r-1]);
        }
        else{
            dp2[l][r] = dp2[l][r-1];
        }
        dp1[l][r] = dp1[l][r-1];
    }
    return dp1[l][r];
}


int main(){
    cin >> s >> m;

    n = s.size();
    arr.assign(n+1,0);
    for(int i=0;i<m;i++){
        cin >> x;
        arr[x-1]++;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp1[i][j] = -1;
            dp2[i][j] = -1;
        }
    }

    solve(0,n-1);

    /*for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << dp2[i][j] << ' ';
        }
        cout<<'\n';
    }*/
    cout << dp2[0][n-1] <<'\n';
    return 0;
}
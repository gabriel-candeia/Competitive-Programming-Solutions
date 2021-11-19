#include<bits/stdc++.h>
#define maxn int(9e6+1)
#define maxm int(3e3+1)
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

int n, m;
char mat[maxm][maxm];

bool isok(int i, int j){
    return (i>=0 && j>=0 && i<n && j<m && mat[i][j]!='.');
}

int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
int bfs(int i, int j){
    int acm = 0;
    queue<tuple<int,int>> q;
    q.push({i,j});
    mat[i][j] = '.';
    while(q.size()){
        acm++;
        tie(i,j) = q.front(), q.pop();
        for(int k=0;k<4;k++)
            if(isok(i+dx[k],j+dy[k]))
                q.push({i+dx[k],j+dy[k]}), mat[i+dx[k]][j+dy[k]] = '.';
    }
    return acm;
}

vector<int> precomp(){
    vector<int> answ;    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(mat[i][j]!='.')
                answ.push_back(bfs(i,j));
    return answ;
}   

bool solve(vector<int> &arr, vector<int> &mult, int k){
    if(k>=maxn) return false;
    bitset<maxn> dp;
    dp[0] = 1;

    for(int i=0;i<arr.size();i++){
        for(int x=0;(1<<x)<mult[i];x++){
            dp |= (dp << (arr[i]*(1<<x)));
            mult[i] -= (1<<x);
        }
        dp |= (dp << (arr[i]*(mult[i])));
    }

    return dp[k];
}

int main(){
    fastio();
    int k;
    cin >> n >> m >> k;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> mat[i][j];

    auto rep = precomp();
    sort(rep.begin(),rep.end());

    vector<int> arr, mult;
    for(int i=0;i<rep.size();i++){
        if(arr.size()==0 || rep[i]!=arr.back()){
            arr.push_back(rep[i]);
            mult.push_back(1);
        }
        else{
            mult[mult.size()-1]++;
        }
    }

    for(int i=0;i<arr.size();i++){
        mult[i] = min(mult[i],k/arr[i]);
    }


    cout << (solve(arr,mult,k) ? "sim" : "nao") <<"\n";

    return 0;
}
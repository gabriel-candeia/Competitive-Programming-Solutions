#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;

int n, m;
int parent[maxn], rnk[maxn];
char mat[maxn];

int find(int x){
    return ((parent[x]==x) ? x : parent[x]=find(parent[x]));
}

void _union(int i, int j){
    i = find(i), j = find(j);
    if(i!=j){
        if(rnk[i]>rnk[j]){
            parent[j] = i;
        }
        else{
            parent[i] = j;
            rnk[j] += (rnk[i]==rnk[j]);
        }
    }
}

int main(){

    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> mat[i*m+j], parent[i*m+j] = i*m+j;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i*m+j]=='.'){
                if(i<n-1 && mat[(i+1)*m+j]=='.') _union(i*m+j,(i+1)*m+j);
                if(j<m-1 && mat[i*m+j+1]=='.') _union(i*m+j,i*m+j+1);
            }
        }
    }

    int answ = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            answ += (mat[i*m+j]=='.' && (parent[i*m+j] == i*m+j));
    cout << answ << "\n";
    return 0;
}
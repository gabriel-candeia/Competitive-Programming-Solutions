#include<bits/stdc++.h>
using namespace std;

pair<int,bool> dfsCycleSize(vector<vector<char>>& mat, vector<vector<char>>& color, vector<vector<bool>>& visited, int i,int j){
    int blacks=0;
    int cnt = 0;
    while(visited[i][j]==false){
        cnt++;
        if(color[i][j]=='0'){
            blacks++;
        }  
        visited[i][j] = true;

        if(mat[i][j]=='L'){
            j--;
        }
        else if(mat[i][j]=='R'){
            j++;
        }
        else if(mat[i][j]=='U'){
            i--;
        }
        else if(mat[i][j]=='D'){
            i++;
        }
    }
    return make_pair(cnt,blacks);
}

void dfsOrder(vector<vector<char>>& mat, vector<vector<char>>& color, vector<vector<bool>>& visited, int i,int j, stack<pair<int,int>>& st){
    int n = mat.size(), m = mat[0].size();
    visited[i][j] = true;
    if(j<m-1 && !visited[i][j+1] && mat[i][j+1]=='L'){
        dfsOrder(mat,color,visited,i,j+1,st);
    }
    if(1<=j && !visited[i][j-1] && mat[i][j-1]=='R'){
        dfsOrder(mat,color,visited,i,j-1,st);
    }
    if(i<n-1 && !visited[i+1][j] && mat[i+1][j]=='U'){
        dfsOrder(mat,color,visited,i+1,j,st);
    }
    if(1<=i && !visited[i-1][j] && mat[i-1][j]=='D'){
        dfsOrder(mat,color,visited,i-1,j,st);
    }
    st.push(make_pair(i,j));
}

int main(){
    int t, n, m;

    cin >> t;
    while(t--){
        cin >> n >> m;
        int acm=0, blacks=0, noBlacksCycles=0;
        vector<vector<char>> mat(n+1,vector<char>(m+1,0));
        vector<vector<char>> color(n+1,vector<char>(m+1,0));
        vector<vector<bool>> visited(n+1,vector<bool>(m+1,false));
        stack<pair<int,int>> st;
        pair<int,bool> wp;
        pair<int,int> u;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> color[i][j];
                blacks += (color[i][j]=='0');
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> mat[i][j];
            }
        }
                

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==false){
                    dfsOrder(mat,color,visited,i,j,st);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                visited[i][j] = false;
            }
        }

        while(st.size()){
            u = st.top(); st.pop();
            if(!visited[u.first][u.second]){
                //cout << "t:"<< u.first << ' ' << u.second << '\n';
                wp = dfsCycleSize(mat,color,visited,u.first,u.second);
                if(wp.first>1){
                    acm+=wp.first;
                }
                else{
                    blacks-=(color[u.first][u.second]=='0');
                }
            }
        }

        cout << acm << ' ' << blacks << '\n';

    }


    return 0;
}
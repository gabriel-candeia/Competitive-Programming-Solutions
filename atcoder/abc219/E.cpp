#include<bits/stdc++.h>
#define maxn 4
using namespace std;

int mat[4][4], color[4][4];

int fillcolor(int msk){
    int acm = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            color[i][j] = ((msk&1<<(4*i+j))!=0);
            acm += color[i][j];
        }
    }
    return acm;
}

bool isok(int i, int j){
    return i>=0 && j>=0 && i<4 && j<4;
}

int dx[4] = {1,-1,0,0}, dy[4] = {0,0,-1,1};

bool isok(int msk){
    int acm = fillcolor(msk);
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(mat[i][j]==1 && color[i][j]==0)
                return false;

    queue<tuple<int,int>> q;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(color[i][j]==1){
                color[i][j] = 2;
                q.push({i,j});
                break;
            }
        }
        if(q.size())
            break;
    }

    int i, j;
    while(q.size()){
        tie(i, j) = q.front(), q.pop(), acm--;
        for(int k=0;k<4;k++){
            if(isok(i+dx[k],j+dy[k]) && color[i+dx[k]][j+dy[k]]==1){
                color[i+dx[k]][j+dy[k]] = 2;
                q.push({i+dx[k],j+dy[k]});
            }
        }
        for(int k1=0;k1<2;k1++){
            for(int k2=2;k2<4;k2++){
                if(isok(i+dx[k1],j+dy[k2])){
                    int i1 = i+dx[k1], j1 = j+dy[k2];
                    bool ok = ((color[i1][j]!=0) || (color[i][j1]!=0));
                    /*if(color[i1][j1]!=0 && ok==false){
                        for(int l=0;l<4;l++){
                            for(int k=0;k<4;k++){
                                cout << color[l][k] << " ";
                            }
                            cout << "\n";
                        }
                        cout<<'\n';
                    }*/
                    if(color[i1][j1]!=0 && ok==false){
                        return false;
                    }
                }
            }
        }
    }

    for(int f=1;f<=2;f++){
        for(int l=1;l<=2;l++){
            if(color[1][1]==0)
                q.push({1,1});
            else if(color[1][2]==0)
                q.push({1,2});
            else if(color[2][2]==0)
                q.push({2,2});
            else if(color[2][1]==0)
                q.push({2,1});

            tie(i,j) = q.front();
            color[i][j] = 1;

            bool teste = false;
            if(q.size()==0)
                teste = true;

            while(q.size()){
                tie(i, j) = q.front(), q.pop();
                if(i==0 || i==3 || j==0 || j==3)
                    teste = true;
                for(int k=0;k<4;k++){
                    if(isok(i+dx[k],j+dy[k]) && color[i+dx[k]][j+dy[k]]==0){
                        color[i+dx[k]][j+dy[k]] = 1;
                        q.push({i+dx[k],j+dy[k]});
                    }
                }
            }


            if(teste==false)
                return false;
        }
    }


    return (acm==0);
}

int main(){

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin >> mat[i][j];
        }
    }

    int answ = 0;
    for(int msk=0;msk < (1<<16);msk++){
        answ += isok(msk);
    }
    
    cout << answ <<"\n";

    return 0;
}
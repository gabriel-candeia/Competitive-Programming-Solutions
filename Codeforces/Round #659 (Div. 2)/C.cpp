#include<bits/stdc++.h>
using namespace std;

int grid[30][30];

int main(){
    int t, n;
    string a, b;

    cin >> t;
    while(t--){
        cin >> n >> a >> b;
        bool poss = true;
        memset(grid,0,sizeof(grid));
        vector<int> letra[30];

        for(int i=0;i<n;i++){
            if(b[i]<a[i]){
                poss = false;
            }
            else if(b[i]!=a[i]){
                letra[a[i]-'a'].push_back(b[i]-'a');
            }
        }        

        for(int i=0;i<30;i++){
            letra[i].push_back(i);
            sort(letra[i].begin(),letra[i].end());
        }

        for(int i=0;i<30;i++){
            for(int j=1;j<letra[i].size();j++){
                grid[letra[i][j-1]][letra[i][j]]++;
            }
        }
        
        int answ=0;
        for(int i=0;i<30;i++){
            /*for(int j=0;j<30;j++){
                if(i!=j){
                    answ += (grid[i][j]!=0);
                }
            }*/
            if(letra[i].size()>1){
                answ++;
            }
        }
        if(poss==false){
            answ = -1;
        }
        cout << answ << '\n';
    }

    return 0;
}
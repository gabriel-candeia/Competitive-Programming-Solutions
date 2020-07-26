#include<bits/stdc++.h>
#define N 4005
using namespace std;

bool mat[N][N];

int main(){
    int t, n, mx, mn;
    vector<int> p;

    cin >> t;
    while(t--){
        cin >> n;
        p.assign(2*n,0);
        for(int i=0;i<2*n;i++){
            cin >> p[i];
        }

        int mx = 0;
        vector<int> pos;
        for(int i=0;i<2*n;i++){
            mx = max(mx,p[i]);
            if(mx==p[i]){
                pos.push_back(i);
            }
        }
        pos.push_back(2*n);

        for(int i=0;i<2*n;i++){
            for(int j=0;j<2*n;j++){
                mat[i][j] = false;
            }    
        }

        
        for(int i=0;i<pos.size()-1;i++){
            pos[i]=pos[i+1]-pos[i];
        }
        pos.pop_back();

        mat[0][0] = true;
        for(int i=0;i<pos.size();i++){
            for(int j=0;j<=n;j++){
                if(mat[i][j]==true){
                    if(j+pos[i]<=n){
                        mat[i+1][j+pos[i]] = true;
                    }
                    mat[i+1][j] = true;
                }
            }    
        }

        cout << ((mat[pos.size()][n]==true) ? "YES" :  "NO") << '\n';
        
    }

    return 0;
}
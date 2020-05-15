#include<bits/stdc++.h>
#define N 1003
using namespace std;

int main(){
    int n, sqr, a;
    vector<int> cnt(1001,0);
    vector<int> odd, even, mult4;
    int mat[N][N];


    cin >> n;
    sqr = n*n;
    for(int i=0;i<sqr;i++){
        cin >> a;
        cnt[a]++;
    }
    
    for(int i=1;i<=1000;i++){
        if(cnt[i]%2==1){
            odd.push_back(i);
            cnt[i]--;
        }
        if(cnt[i]){   
            vector<int> temp(cnt[i]/4,i);
            mult4.insert(mult4.end(),temp.begin(),temp.end());
            cnt[i]%=4;
        }
        if(cnt[i]){
            vector<int> temp(cnt[i]/2,i);
            even.insert(even.end(),temp.begin(),temp.end());
            cnt[i]%=2;
        }
    }
    
    bool poss = false;
    if(n%2==0 && odd.size()==0 && even.size()==0){
        poss = true;

        int cnt = 0;
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                mat[i][j] = mult4[cnt++];
                mat[n-1-i][j] = mat[i][j];
                mat[i][n-1-j] = mat[i][j];
                mat[n-1-i][n-1-j] = mat[i][j];
            }
        }
    }
    else if(n%2==1 && odd.size()==1 && mult4.size()>=(n/2)*(n/2)){
        poss = true;

        int cnt = 0;
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                mat[i][j] = mult4[cnt++];
                mat[n-1-i][j] = mat[i][j];
                mat[i][n-1-j] = mat[i][j];
                mat[n-1-i][n-1-j] = mat[i][j];
            }
        }

        mat[n/2][n/2] = odd[0];

        while(cnt<mult4.size()){
            even.push_back(mult4[cnt]);
            even.push_back(mult4[cnt++]);
        }

        cnt = 0;
        for(int i=0;i<n/2;i++){
            mat[n/2][n-1-i] = even[cnt];
            mat[n/2][i] = even[cnt++];
        }

        for(int i=0;i<n/2;i++){
            mat[n-1-i][n/2] = even[cnt];
            mat[i][n/2] = even[cnt++];
            
        }
    }

    if(poss){
        cout << "yes\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << mat[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    else{
        cout << "no\n";
    }

    return 0;
}
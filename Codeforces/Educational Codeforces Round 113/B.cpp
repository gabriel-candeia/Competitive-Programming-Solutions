#include<bits/stdc++.h>
#define maxn 51
using namespace std;

char answ[maxn][maxn];

int main(){ 
    int t;

    cin >> t;

    while(t--){
        int n;
        vector<char> arr;
        cin >> n;

        arr.assign(n,0);
        for(auto &x:arr)
            cin >> x, x-='0';

        memset(answ,0,sizeof(answ));

        int cnt = 0;
        for(int i=0;i<n;i++){
            cnt += (arr[i]==2);
            if(arr[i]==1){
                for(int j=0;j<n;j++){
                    answ[i][j] = answ[j][i] = '=';
                }
            }
        }
        
        if(cnt==1 || cnt==2){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            if(cnt){
                for(int i=0;i<n;i++){
                    if(arr[i]==2){
                        for(int j=i+1;j<2*n;j++){
                            if(arr[j%n]==2){
                                answ[i][j%n]='+';
                                answ[j%n][i]='-';
                                break;
                            }
                        }
                    }
                }
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(answ[i][j]==0)
                            answ[i][j] = answ[j][i] = '=';
                    }
                }
            }
            for(int i=0;i<n;i++)
                answ[i][i] = 'X';
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
                    cout << answ[i][j];
                cout <<"\n";
            }
        }
    
    }


    return 0;
}
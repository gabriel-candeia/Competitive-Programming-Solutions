#include <bits/stdc++.h>
#define maxm int(1e5+5)
using namespace std;

int t, n, m, notas[5] = {1,5,10,20,50}, temp[5], answ[5], items[maxm];

void teste(int n){
    //cout<< n << ": ";
    for(int i=4;i>=0;i--){
        temp[i] = n/notas[i];
        n %= notas[i];
      //  cout << temp[i] << " ";
    }//cout<<'\n';
}

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        items[0] = n;
        for(int i=1;i<=m;i++)
            cin >> items[i];

        for(int i=0;i<5;i++){
            int mx = 0;
            for(int j=0;j<=m;j++){
                teste(items[j]);
                mx = max(mx,temp[i]);
            }
            answ[i] = mx;
            for(int j=0;j<=m;j++)
                items[j]=max(items[j]-notas[i]*mx,0);
            cout << answ[i] << " ";
        }
        cout<<'\n';
    }    
}
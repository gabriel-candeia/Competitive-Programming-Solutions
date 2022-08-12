#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, b, r, bestR, bestB;
        cin >> n >> r >> b;
        string answ = "";
        bestR = bestB = n;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=b;j++){
                int x = (r/i+(r%i!=0)), y = (b/j+(b%j!=0));
                if( abs(x-y)<=1  && max(i,j)<=min(bestB,bestR)){
                    bestR = i;
                    bestB = j;
                }
            }
        }
        while(r+b){
            
            int qtd = min(bestR,r);
            r-=qtd;
            answ += string(qtd,'R');
            
            qtd = min(bestB,b);
            b -= qtd;
            answ += string(qtd,'B');
            
        }

        cout << answ <<"\n";
    }

    

    return 0;
}
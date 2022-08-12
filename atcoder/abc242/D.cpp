#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    string s;
    int q;

    cin >> s;
    cin >> q;
    while(q--){
        ll t, k;
        cin >> t >> k;
        if(t==0)
            cout << s[k-1] <<"\n";
        else{
            int root = 0;
            
            if(t<60){
                ll qtd = (1ll<<t);
                root = k/qtd;
                k%=qtd;
                if(k==0) k+= qtd, root--;
            }
            //cout << root <<"\n";
            int ones = 0, moves;
            
            while(k%2==0){
                ones++;
                k/=2;
            }
            
            while(k>1){
                ones+=k%2;
                k/=2;
            }
            
            moves = (2*ones + t-ones)%3;
            cout << ((char) ((s[root]-'A'+moves)%3+'A')) <<"\n";
        }
    }

    return 0;
}
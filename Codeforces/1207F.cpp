#include<bits/stdc++.h>
#define ll long long
#define maxn int(5e5+5)
#define maxm 800
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

ll arr[maxn];
ll soma[maxm][maxm];

int main(){ 
    fastio();
    int q;
    cin >> q;


    while(q--){
        int t, a, b;
        cin >> t >> a >> b;

        if(t==1){
            for(int i=1;i<maxm;i++){
                soma[i][a%i]-=arr[a];
            }
            arr[a]+=b;
            for(int i=1;i<maxm;i++){
                soma[i][a%i]+=arr[a];
            }
        }
        else{
            if(a<maxm){
                cout << soma[a][b] << "\n";
            }
            else{
                ll answ = 0;
                for(int i=b;i<maxn;i+=a){
                    answ += arr[i];
                }
                cout << answ <<"\n";
            }
        }
    }


    return 0;
}
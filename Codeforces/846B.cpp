#include<bits/stdc++.h>
#define ll long long
#define N 2500
using namespace std;

ll t[N], n, k, m, total, answ, rem;

int main(){
    cin >> n >> k >> m;
    
    for(int i=0;i<k;i++){
        cin >> t[i];
        total+=t[i];
    }
    answ = 0;
    for(int i=0;i<=n;i++){
        rem = m-total*i;
        if(rem>=0){
            vector<ll> h;
            for(int j=i;j<n;j++){
                for(int l=0;l<k;l++){
                    h.push_back(t[l]);
                }
            }
            sort(h.begin(),h.end());
            
            ll pt=0, pontos=i*(k+1);
            while(rem>=0 && pt<h.size()){
                rem-=h[pt++];
                pontos++;
            }
            if(rem<0){
                pontos--;
            }
            answ = max(answ,pontos);
        }
    }

    cout << answ << '\n';
    return 0;
}
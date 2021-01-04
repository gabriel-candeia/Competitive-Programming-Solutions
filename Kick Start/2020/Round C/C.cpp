#include<bits/stdc++.h>
#define maxn int(1e7+5)
#define ll long long
using namespace std;

ll square[maxn], cnt[maxn], arr[maxn];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int caso = 0, t;

    for(int i=0;i<maxn;i++)
        square[i] = i*i;

    cin >> t;
    while(t--){
        ll n, answ = 0, sum=0, x, lim, menor = 0;
        
        cin >> n; 
        lim = max(int(sqrt(100*n)),100);
        memset(cnt,0,sizeof(cnt));

        
        for(int i=0;i<n;i++){
            cin >> arr[i];
            sum+=arr[i];
            menor = min(menor,sum);
        }
        cnt[0-menor] = 1; 
        sum = 0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            for(int j=0;j<=lim;j++)
                if(sum-square[j]-menor>=0)
                    answ += cnt[sum-square[j]-menor];
            cnt[sum-menor]++;
        }

        cout << "Case #" << ++caso << ": " << answ << '\n';
    }

    return 0;
}

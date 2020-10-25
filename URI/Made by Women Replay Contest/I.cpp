#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main(){
    fastio();
    int t;
    cin >> t;
    while(t--){
        int cnt=0, n;
        cin >> n;
        vector<int> cc(n,0), arr(n,0), visited(n,0), dist(n,0), tam(n,0);
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        
        for(int i=0;i<n;i++){
            int j = i, acm=0;
            if(visited[j]==false){
                cnt++;
                while(visited[j]==false){
                    visited[j] = true;
                    cc[j] = cnt;
                    dist[j] = acm++;
                    j = arr[j];
                }
                tam[cnt] = acm;
            }
        }

        int q, j, k;
        cin >> q;
        for(int i=0;i<q;i++){
            cin >> j >> k;
            if(cc[j]!=cc[(j+k)%n])
                cout << "-1\n";
            else
                cout << ((dist[j]-dist[(j+k)%n])%tam[cc[j]]+tam[cc[j]])%tam[cc[j]] <<'\n';
        }
    }

    return 0;
}
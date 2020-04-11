#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, cc;
    vector<int> arr(1001,0);
    vector<int> visited;

    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }

        visited.assign(1001,0);

        cc = 0;
        for(int i=2;i<=1000;i++){
            if(!visited[i]){
                cc++;
                for(int j=i;j<=1000;j+=i){
                    if(!visited[j]){
                        visited[j] = cc;
                    }
                }
            }
        }

        unordered_map<int,int> f;
        int cnt = 1;
        for(int i=0;i<n;i++){
           if(f[visited[arr[i]]]==0){
               f[visited[arr[i]]] = cnt++;
           }
        }
        cout << cnt-1 << '\n';
        for(int i=0;i<n;i++){
           cout << f[visited[arr[i]]] << " ";
        }
        cout << '\n';
    }

    return 0;
}
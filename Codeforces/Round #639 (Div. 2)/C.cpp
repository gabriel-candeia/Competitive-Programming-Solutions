#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n;
    vector<int> a;
    vector<int> visited;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--){
        cin >> n;

        a.assign(n,0);
        visited.assign(n,0);

        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        bool poss = true;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int curr = i;
                while(visited[curr]==0){
                    visited[curr] = i+1;
                    curr = (curr+a[curr])%n;
                    if(curr<0){
                        curr+=n;
                    }
                }
                if(curr!=i){
                    poss =false;
                    break;
                }
            }
        }

        if(poss){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}
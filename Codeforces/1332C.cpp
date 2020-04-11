#include<bits/stdc++.h>

using namespace std;

int main(){
    int t, n, k, answ, mx = 0, tot = 0;
    vector<bool> visited;
    string s;

    cin >> t;
    while(t--){
        cin >> n >> k;
        cin >> s;

        visited.assign(n+1,false);
        answ = 0;
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                tot = 0; mx = 0;
                unordered_map<char,int> cnt;

                for(int j=i;j<n;j+=k){
                    if(!visited[j]){
                        tot += 1 + 1*(j!=n-1-j);
                        visited[j] = true;
                        visited[n-1-j] = true;
                        mx = max(mx,++cnt[s[j]]);
                        if(j!=n-1-j){
                            mx = max(mx,++cnt[s[n-1-j]]);                         
                        }   
                    }
                }
                answ += tot-mx;
            }
        }

        cout << answ << '\n';
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t, n, m, a;
    vector<int> pos, b;

    cin >> t;
    while(t--){
        cin >> n >> m;
        pos.assign(n+1,0);
        b.assign(m,0);

        for(int i=1;i<=n;i++){
            cin >> a;
            pos[a] = i;
        }

        for(int i=0;i<m;i++){
            cin >> b[i];
        }

        ll last = 0, answ=0, cnt=0;
        for(int i=0;i<m;i++){
            if(pos[b[i]]>last){
                answ+=2ll*(pos[b[i]]-1-cnt)+1;
                last = pos[b[i]];
                cnt++;
            }
            else{
                answ++;
                cnt++;
            }
        }
        cout << answ << '\n';
    }

    return 0;
}
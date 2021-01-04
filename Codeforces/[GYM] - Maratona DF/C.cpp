#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

int main(){
    int x, y, z, m, n;
    string s;
    vector<int> cost;
    queue<int> cupims[3];

    cin >> x >> y >> z;
    cin >> m >> n;
    cin >> s;

    cost.push_back(x); cost.push_back(y); cost.push_back(z);
    for(int i=0;i<n;i++){
        if(s[i]=='F')
            cupims[0].push(i);
        else if(s[i]=='A')
            cupims[1].push(i);
        else
            cupims[2].push(i);
    }
    
    int ans = 1, rem=0, capacidade=m;
    while(rem<n){
        int nxt = n+10, lugar=-1;
        for(int j=0;j<3;j++){
            if(cupims[j].size()==0) continue;
            if(capacidade>=cost[j] && nxt>cupims[j].front()){
                nxt = cupims[j].front();
                lugar = j;
            }
        }
        if(lugar==-1){
            ans++, capacidade = m;
        }
        else{
            cupims[lugar].pop(); capacidade-=cost[lugar]; rem++;
        }
    }

    cout << ans <<'\n';

    return 0;
}
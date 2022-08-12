#include<bits/stdc++.h>
using namespace std;


int n,turn=0,t[3],pos[3],flag[3];

int main() {
    cin>>n>>t[0]>>t[1]>>t[2]; n++;

    int ans=1;
    vector<int> v(n,-1);
    while(true) {
        if(flag[0] && flag[1] && flag[2]) return cout<<"3000000000\n", 0;
        while(flag[turn]) turn = (turn+1)%3, ans++;
        pos[turn] = (pos[turn]+t[turn])%n;

        if(!pos[turn] || v[pos[turn]] == turn)
            flag[turn] = 1;
        else if(v[pos[turn]] == -1)
            v[pos[turn]] = turn;
        else if(v[pos[turn]] != turn)
            return cout<<ans<<"\n",0;

        turn = (turn+1)%3;
        ans++;
    }
}
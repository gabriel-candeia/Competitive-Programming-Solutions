#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll answ=0, n, pot=0;
    vector<ll> visited;

    cin >> n;
    visited.assign(n+1,false);
    
    int cnt=0, temp=n;
    while(temp!=0){
        cnt++;
        temp/=2;
    }

    pot = (1<<cnt)-1;
    
    for(int i=n;i>=0;i--){
        if(!visited[i] && i){
            visited[i] = (i^pot);
            visited[(i^pot)] = i;
            answ+=pot;
            if(i!=i^pot){
                answ+=pot;
            }
        }
        if((i&(-i))==i){
            pot /= 2;
        }
    }

    cout << answ <<"\n";
    for(int i=0;i<=n;i++){
        cout << visited[i] << ' ';
    }
    cout << '\n';
    return 0;
}
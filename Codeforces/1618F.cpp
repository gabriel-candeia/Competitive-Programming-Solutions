#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll reverse(ll x){
    ll acm = 0;
    while(x){
        acm = 2*acm + x%2;
        x/=2;
    }
    return acm;
}

int main(){
    ll a, b;
    set<ll> todos;
    cin >> a >> b;

    
    queue<ll> q;
    q.push(a);
    todos.insert(a);
    while(q.size()){
        ll x = q.front(); q.pop();
        if(reverse(x)>=0 && todos.find(reverse(x))==todos.end()){
            todos.insert(reverse(x));
            q.push(reverse(x));
        }
        if(2*x+1>=0 && reverse(2*x+1)>=0 && todos.find(reverse(2*x+1))==todos.end()){
            todos.insert(reverse(2*x+1));
            q.push(reverse(2*x+1));
        }
    }

    bool ok = (todos.find(b)!=todos.end());
    cout << ((ok) ? "YES" : "NO") <<"\n";

    return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9;
int main(){
    int t, caso=0;
    string s;

    cin >> t;
    while(t--){
        stack<ll> stx, sty, stmul;
        ll dx=0,dy=0;
        stx.push(0); sty.push(0); stmul.push(1);
        cin >> s;
        for(auto c:s){
            if(c==')'){
                dx = stx.top()*stmul.top(); 
                dy = sty.top()*stmul.top(); 
                stx.pop(); sty.pop(); stmul.pop();
                stx.top()=((stx.top()+dx)%mod+mod)%mod;
                sty.top()=((sty.top()+dy)%mod+mod)%mod;
            }
            else if('0'<=c && c<='9'){
                stmul.push(c-'0');
                stx.push(0);
                sty.push(0);
            }
            else if(c!='('){
                stx.top()+=-(c=='N')+(c=='S');
                stx.top() = (stx.top()%mod+mod)%mod;
                sty.top()+=(c=='E')-(c=='W');
                sty.top() = (sty.top()%mod+mod)%mod;
            }
        }
        cout << "Case #"<< ++caso <<": "<<(((sty.top()%mod)+mod)%mod+1)<< " "<<(((stx.top()%mod)+mod)%mod+1)<<'\n';
    }

    return 0;
}
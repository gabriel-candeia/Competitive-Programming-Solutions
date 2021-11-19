#include <bits/stdc++.h>

using namespace std;

#define maxn ll(1e6+10)

typedef long long int ll;

ll n, tot, x, y;
string c;
ll v[maxn], p[maxn];


bool ok(ll r){
    //p[r] - p[l-r-1] >= tot
    int pos;
    for(int i = 1; i <= n; i++){    
        pos = i-r-1;
        if(pos >= 0 && p[i]-p[pos] >= tot){
            y = i;
            x = pos+1;
            return true;
        }
    }
    return false;
}

ll bb(){
    ll l = 0, r = n+1, mid;
    while(r > l+1){
        mid = (l+r)>>1;
        if(ok(mid))
            l = mid;
        else
            r = mid;
    }
    return l;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> c;
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(unsigned int i = 0; i < c.size(); i++){
        if(s[i] >= '0' && s[i] <= '9') tot = tot*10 + ll(s[i]-'0');
        else break;
    }
    if(c[c.size()-2] == 'G'){
        tot *= 1024;
    }else if(c[c.size()-2] == 'T'){
        tot *= 1024*1024;
    }
    for(int i = 1; i <= n; i++) p[i] = p[i-1] + v[i];
    ll r = bb();
    ll l = -1;
    for(int i = 1, pos; i <= n; i++){
        pos = i-r;
        if(pos >= 0 && p[i]-p[pos] < tot){
            l = pos+1;
            break;
        }
    }
    cout << r << " " << l << "\n";
    return 0;
}
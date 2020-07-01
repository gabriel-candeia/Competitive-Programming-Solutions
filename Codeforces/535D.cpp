#include<bits/stdc++.h>
#define N int(1e6+1)
#define ll long long
using namespace std;

const int mod = 1000000007;
int z[N];

void z_function(string s){
    int n = s.length();
    memset(z,n+1,0);
    for(int i=1,l=0,r=0;i<n;i++){
        /* if i is inside the current rightmost matched intervale compare it to the corresponding (in
            the same position relative to the start of the interval) element of the interval [0,r-l].
        */
        if(i<=r){
            z[i] = min(z[i-l],r-i+1);
        }
        //try to "expand the border"
        while(i+z[i]<n && s[i+z[i]]==s[z[i]]){
            z[i]++;
        }
        //expand the border
        if(i+z[i]-1>r){
            l = i;
            r = i+z[i]-1;
        }
    }
}

int main(){
    int n, m;
    string s;
    vector<int> y;

    cin >> n >> m >> s;
    y.assign(m,0);
    for(int i=0;i<m;i++){
        cin >> y[i];
    }
    int cnt;
    bool poss=true;
    if(m>0){
        z_function(s);
        int l = s.size(); 
        cnt=y[0]-1;

        for(int i=0;i<m-1;i++){
            int start = y[i+1]-y[i], len = l-start;
            if(start>=0 && z[start]<len){
                poss = false;
            }
            else{
                cnt+=max(0,y[i+1]-y[i]-l);
            }
        }
        cnt+=max(0,n-y[m-1]+1-l);
    }
    else{
        cnt = n;
    }
    ll answ=1;
    while(cnt--){
        answ = (1ll*answ*26)%mod;
    }
    cout << poss*answ << '\n';
    return 0;
}
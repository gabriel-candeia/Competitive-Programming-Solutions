#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(vector<ll> a, vector<ll> b){
    
    if(a.size()==0 || b.size()==0){
        ll sum = 0;
        for(auto &x:b)
            sum += x;
        for(auto &x:a)
            sum += x;
        return sum;
    }
    ll answ = ((a.size()>0) ? a.back() : 0);
    int l = 0, r = 0;
    bool last = true;
    while((!last && (l<a.size()-1)) || (last && r<b.size())){
        if(last){
            answ += 2*b[r++];
            last = false;
        }
        else{
            answ += 2*a[l++];
            last = true;
        }
    }

    while(l<a.size()-1)
        answ += a[l++];
    while(r<b.size())
        answ += b[r++];
    return answ;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        vector<ll> types;
        vector<ll> fire, ice;

        cin >> n;
        
        types.assign(n,0);
        for(auto &x:types){
            cin >> x;
            
        }

        for(int i=0;i<n;i++){
            int x;
            
            cin >> x;
            
            if(types[i]){
                fire.push_back(x);
            }
            else{
                ice.push_back(x);
            }
        }

        sort(fire.rbegin(),fire.rend());
        sort(ice.rbegin(),ice.rend());
        
        cout << max(solve(fire,ice),solve(ice,fire)) <<"\n";
    }
    return 0;
}
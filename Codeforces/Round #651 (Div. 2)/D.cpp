#include<bits/stdc++.h>
#define INF 1000000007
using namespace std;

bool check(vector<int>& a, int x, int k){
    int cnt[2] = {0,0}, turno;
    for(int par=0;par<=1;par++){
        turno = 0;
        for(int i=0;i<a.size();i++){
            if(turno%2==par && a[i]<=x){
                cnt[par]++;
                turno ^= 1;
            }  
            else if(turno%2!=par){
                cnt[par]++;
                turno ^= 1;
            }
        }
    }
    return cnt[0]>=k || cnt[1]>=k;
}



int main(){
    int n, k;
    vector<int> a;    

    cin >> n >> k;
    a.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int l=1, r=INF, answ=0, med;
    while(l<=r){
        med = l + (r-l)/2;
        if(check(a,med,k)){
            answ = med;
            r = med-1;
        }
        else{
            l = med+1;
        }
    }
    cout << answ << '\n';
    
    return 0;
}
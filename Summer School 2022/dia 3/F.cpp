#include<bits/stdc++.h>
#define ll long long
#define ld double
using namespace std;

vector<int> proxMaior(const vector<pair<ll,ll>>& arr){
    int n = arr.size();
    vector<int> nxt(n,n);
    for(int i=n-1, j;i>=0;i--){
        for(j=i+1;j<n && arr[j].second<arr[i].second;j=nxt[j]);
        nxt[i] = j;
    }
    return nxt;
}

double calculaArea(const vector<pair<ll,ll>>& arr, int l, int r){
    if(l+1==r)  return 0;
    ll teto = min(arr[l].second,arr[r].second);
    ld answ = 0;
    for(int i=l+1;i<r-1;i++){
        answ += (arr[i+1].first-arr[i].first)*(2*teto-arr[i].second-arr[i+1].second)*1.0/2.0;
    }
    ld lx=arr[l].first, rx=arr[r].first;
    if(teto!=arr[l].second){
        lx -= (arr[l].second-teto)*(arr[l].first-arr[l+1].first)*1.0/(arr[l].second-arr[l+1].second);
    }
    if(teto!=arr[r].second){
        rx -= (arr[r].second-teto)*(arr[r].first-arr[r-1].first)*1.0/(arr[r].second-arr[r-1].second);
    }
    answ += (arr[l+1].first-lx)*(teto-arr[l+1].second)/2.0;
    answ += (rx-arr[r-1].first)*(teto-arr[r-1].second)/2.0;
    return answ;
}

int main(){
    int n;
    vector<pair<ll,ll>> arr;
    vector<int> nxt, lst;

    cin >> n;

    arr.assign(n,{0,0});
    for(auto &p:arr)
        cin >> p.first >> p.second;

    nxt = proxMaior(arr);
    reverse(arr.begin(),arr.end());
    lst = proxMaior(arr);
    reverse(arr.begin(),arr.end());
    reverse(lst.begin(),lst.end());
    for(auto &x:lst)
        x = n-x-1;

    ld answ = 0;
    int l = 0, r = n-1;
    while(l<r){
        if(nxt[l]!=n){
            ld inc = calculaArea(arr,l,nxt[l]);
            answ += inc;
            l = nxt[l];
        }
        else{
            ld inc = calculaArea(arr,lst[r],r);
            answ += inc;
            r = lst[r];
        }
    }

    cout << fixed << setprecision(10) << answ << "\n";

    return 0;
}
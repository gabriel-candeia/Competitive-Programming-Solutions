#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const ld eps = 1e-9;

int cmp(ld a, ld b){
    return ((a>b+eps) ? 1 : ((a<b-eps) ? -1 : 0));
}

int n;
vector<array<pair<ll,ll>,2>> arr;
bool isok(ld med){
    ld acm = 0;
    for(int i=0;i<n;i++)
        acm += max(arr[i][0].second-arr[i][0].first*med,arr[i][1].second-arr[i][1].first*med);
    return (cmp(acm,0)>=0);
}

int main(){
    cin >> n;
    arr.assign(n,array<pair<ll,ll>,2>());
    for(int i=0;i<n;i++)
        for(auto &p:arr[i])
            cin >> p.first >> p.second;

    ld l=0, r=1e9, med, answ = -1;
    for(int iter=0;iter<100;iter++){
        med = (l+r)/2;
        if(isok(med)){
            answ = med;
            l = med;
        }
        else{
            r = med;
        }
    }

    cout << fixed << setprecision(10) << answ <<"\n";

    return 0;
}
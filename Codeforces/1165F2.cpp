#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

int n, m, lim;
vector<int> arr;
set<int> offers[maxn];

bool isok(int x){
    vector<int> aux(arr.begin(),arr.end());
    vector<pair<int,int>> datas;
    for(int i=0;i<n;i++){
        auto it = offers[i].lower_bound(x);
        if(it!=offers[i].begin()){
            it--;
            datas.push_back({(*it),i});
        }
    }
    sort(datas.begin(),datas.end());
    int acm = 0, last = -1;
    for(auto p:datas){
        acm += p.first-last;
        int dec = min(aux[p.second],acm);
        acm -= dec;
        aux[p.second] -= dec;
        last = p.first;
    }
    acm += (x-1)-last;
    for(int i=0;i<n;i++){
        acm -= 2*aux[i];
    }
    //cout << acm <<"\n";
    return acm>=0;
}

int bb(){
    int l = 1, r = 2*lim+1, med, answ=-1;
    while(l<=r){
        med = l + (r-l)/2;
        if(isok(med)){
            answ = med;
            r = med-1;
        }
        else{
            l = med+1;
        }
    }
    return answ;
}

int main(){
    cin >> n >> m;

    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x, lim+=x;

    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        offers[b-1].insert(a-1);
    }
    
    cout << bb() <<"\n";
    //cout << isok(8) <<"\n";

    return 0;
}
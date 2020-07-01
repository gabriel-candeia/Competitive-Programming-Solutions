#include<bits/stdc++.h>
using namespace std;


set<int> aux;
int is_good(int x, vector<int>& a, int n, int p){
    vector<int> cnt(2001,0);
    for(auto y:a){
        cnt[max(y-x,0)]++;
    }
    for(int i=1;i<n;i++){
        cnt[i] += cnt[i-1]-1;
    }
    bool poss = true;
    for(int i=0;i<n;i++){
        aux.insert(cnt[i]%p);
    }
    return poss;
}

int main(){
    int p, n;
    int l=1e9, r=0;
    vector<int> a, answ;

    cin >> n >> p;
    a.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
        r = max(r,a[i]);
        l = min(l,a[i]);
    }

    l = max(l,max(r-n,1));
    sort(a.begin(),a.end());
    is_good(l,a,n,p);
    int cnt=0;

    cout << aux.size() << '\n';
    for(auto y:aux){
        cout << y << " ";
    }
    cout << \n\n";

    for(int i=l;i<=r;i++){
        if(aux.find(cnt)==aux.end()){
            answ.push_back(i);
        }
        cnt++;
        cnt = cnt%p;
    }
    cout << answ.size() << '\n';
    for(auto y:answ){
        cout << y << " ";
    }
    cout << '\n';

    return 0;
}
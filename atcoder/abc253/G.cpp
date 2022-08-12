#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, l, r;
pair<int,int> get(ll x){
    pair<int,int> answ;
    for(int i=1;i<=n;i++){
        if(n-i<x){
            x-=(n-i);
        }
        else{
            answ = {i,i+x};
            break;
        }
    }
    return answ;
}

pair<int,int> prox(pair<int,int> p){
    if(p.second==n)
        return {p.first+1,p.first+2};
    return {p.first,p.second+1};
}

int main(){
    cin >> n >> l >> r;
    vector<int> arr(n+1,0);
    for(int i=1;i<=n;i++)
        arr[i] = i;

    pair<int,int> fst = get(l), lst = get(r);

    if(fst.first==lst.first || fst.first+1==lst.first){
        for(pair<int,int> p=fst;p<=lst;p=prox(p)){
            swap(arr[p.first],arr[p.second]);
            //cout << p.first << " " <<p.second <<"\n";
        }
    }
    else{
        pair<int,int> p = fst;
        for(p;p.first==fst.first;p=prox(p))
            swap(arr[p.first],arr[p.second]);

        int qtd = lst.first-p.first-1;
        vector<int> novo;
        novo.push_back(0);
        for(int i=1;i<p.first;i++)
            novo.push_back(arr[i]);
        for(int i=n;i>=n-qtd;i--)
            novo.push_back(arr[i]);
        for(int i=p.first;i<n-qtd;i++)
            novo.push_back(arr[i]);
        swap(novo,arr);

        p = {lst.first,lst.first+1};
        for(p;p<=lst;p=prox(p))
            swap(arr[p.first],arr[p.second]);
    }

    for(int i=1;i<=n;i++)
        cout << arr[i] << " ";
    cout<<"\n";

    return 0;
}
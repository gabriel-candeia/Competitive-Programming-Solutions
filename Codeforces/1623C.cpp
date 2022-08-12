#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;

int teste(int x){
    vector<int> aux(arr.begin(),arr.end());
    for(int i=n-1;i>=2;i--){
        int d = min(max(aux[i]-x,0),arr[i]);
        d = (d-d%3)/3;
        aux[i]-=3*d;
        aux[i-1]+=d;
        aux[i-2]+=2*d;
    }
    for(int i=0;i<n;i++){
        //cout << aux[i] << " ";
        if(aux[i]<x){
            return false;
        }
    }
    return true;
}

int bb(){
    int l = 0, r = 1e9, med, answ;
    while(l<=r){
        med = l + (r-l)/2;
        if(teste(med)){
            answ = med;
            l = med+1;
        }
        else{
            r = med-1;
        }
    }
    return answ;
}

int main(){
    int t;

    cin >> t;
    while(t--){
        cin >> n;
        arr.assign(n,0);
        for(auto &x:arr)
            cin >> x;
        //cout << teste(15) <<"\n";
        cout << bb() <<"\n";

        arr.clear();
    }

    return 0;
}
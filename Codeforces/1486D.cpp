#include<bits/stdc++.h>
using namespace std;

bool isok(vector<int> &arr, int x, int k){
    vector<int> p(arr);

    for(int i=0;i<p.size();i++)
        p[i] = (p[i]<x) ? -1 : (p[i] >= x);

    for(int i=1;i<p.size();i++)
        p[i] += p[i-1];

    int mn = 0, mx = 0;
    bool poss = false;
    for(int i=k-1;i<p.size();i++){
        if(p[i]-mn>0)
            poss = true;
        mn = min(mn,p[i-k+1]);
    }   

    return poss;
}

int main(){
    int n, k;
    vector<int> arr, x;

    cin >> n >> k;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    x = vector<int>(arr);
    sort(x.begin(),x.end());
    int l = 0, r = n-1, med, answ = -1;
    while(l<=r){
        med = l + (r-l)/2;
        if(isok(arr,x[med],k)){
            answ = x[med];
            l = med+1;
        }
        else{
            r = med-1;
        }
    }
    
    cout << answ << '\n';

    return 0;
}
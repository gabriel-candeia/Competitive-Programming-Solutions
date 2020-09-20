#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<int> arr;
void combine(int l, int med, int r){
    k-=2; 
    int mn  = arr[l], mx = arr[r-1];
    for(int i=l;i<med-1;i++)
        arr[i] = arr[i+1];
    for(int i=r-1;i>med;i--)
        arr[i] = arr[i-1];

    arr[med-1] = mx;
    arr[med] = mn;
}

void mergesort(int l, int r){
    if(r-l>1 && k){
        int med = l + (r-l)/2; 
        combine(l, med, r);
        mergesort(l,med);
        mergesort(med,r);
    }
}

int main(){
    cin >> n >> k;
    arr.assign(n,0);
    for(int i=0;i<n;i++)
        arr[i] = i+1;
    k--;
    mergesort(0,n);
    if(k==0)
        for(auto x:arr)
            cout << x << ' ';
    else
        cout << -1;
    cout <<'\n';
    return 0;
}
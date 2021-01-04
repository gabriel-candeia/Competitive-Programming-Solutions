#include<bits/stdc++.h>
#define maxn int(1e6+6)
using namespace std;

int freq[maxn];

int main(){
    int n, m, r;
    vector<int> arr, even, odd;

    cin >> n >> m >> r;
    arr.assign(n,0), odd.assign(m,0);
    for(auto &x : arr){ 
        cin >> x;
        freq[x]++;
    }

    int total = n;
    for(int i=0;i<m;i++){
        odd[i] = total;
        total-=freq[i+1];
    }
    sort(arr.rbegin(),arr.rend());
    if(r%2){
        for(auto x: odd)
            cout << x << " ";
        cout<<'\n';
    }
    else{
        for(auto x: arr)
            cout << x << " ";
        cout<<'\n';
    }

    return 0;
}
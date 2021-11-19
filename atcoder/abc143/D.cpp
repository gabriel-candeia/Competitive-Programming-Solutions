#include<bits/stdc++.h>
#define maxn int(2e3+5)
#define ll long long
using namespace std;

int freq[maxn];

int main(){
    int n;
    vector<int> arr;

    cin >> n;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    ll answ = 0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        for(int j=arr[i]+1;j<maxn;j++)
            answ += freq[j];
        for(int j=i-1;j>=0;j--){
            freq[arr[i]+arr[j]]++;
        }
    }

    cout << answ << "\n";

    return 0;
}
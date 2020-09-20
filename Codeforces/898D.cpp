#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k, a;
    vector<int> arr(int(1e6)+1,0);

    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        cin >> a;
        arr[a]++;
    }

    int answ=0, curr=0;
    for(int i=0;i<=int(1e6);i++){
        curr+=arr[i];
        if(i>=m)
            curr-=arr[i-m];
        if(curr>=k){
            answ += (curr-(k-1));
            arr[i]-=(curr-(k-1));
            curr = k-1;
        }
    }
    cout << answ <<'\n';


    return 0;
}
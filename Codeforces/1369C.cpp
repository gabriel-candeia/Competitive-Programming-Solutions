#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t, n, k;

    cin >> t;
    while(t--){
        cin >> n >> k;

        vector<int> arr(n,0), w(k,0);
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        for(int i=0;i<k;i++){
            cin >> w[i];
        }

        ll sum=0, qtd=0;
        sort(arr.begin(),arr.end());
        sort(w.rbegin(),w.rend());
        for(int i=0;i<k;i++){
            if(w[i]==1){
                sum+=2*arr[--n];
                qtd++;
            }
        }
        k-=qtd;
        int ptr = 0;
        for(int i=0;i<k;i++){
            //cout << ptr << " " << ptr+w[i]-1 << '\n';
            sum+=arr[ptr]+arr[n-i-1];
            ptr+=w[i]-1;
        }   
        cout << sum << '\n';
    }
    return 0;
}
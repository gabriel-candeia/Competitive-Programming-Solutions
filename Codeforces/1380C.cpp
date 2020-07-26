#include<bits/stdc++.h>
#define ll long long
using namespace std;

int ceil(int a, int b){
    return a/b + (a%b!=0);
}

int main(){
    int t, n, x;

    cin >> t;
    while(t--){
        cin >> n >> x;
        vector<int> a(n,0), best(n+1,0);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        for(int i=n-1;i>=0;i--){
            int p = ceil(x,a[i]);
            if(i+p<n){
                best[i] = best[i+p]+1;
            }
            else{
                best[i] = (i+p==n);
            }
            best[i] = max(best[i],best[i+1]);
        }

        cout << best[0] << '\n';

    }

    return 0;
}
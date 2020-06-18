#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, x;
    vector<int> a;

    cin >> t;
    while(t--){
        cin >> n >> x;
        a.assign(n,0);
        int sum=0,l,r;
        for(int i=0;i<n;i++){
            cin >> a[i];
            sum+=a[i];
        }
        int answ = -1;
        if(sum%x){
            answ = n;
        }
        else{
            l = 0;
            while(l<n && a[l]%x==0){
                l++;
            }
            if(l<n){
                answ = max(n-l-1,l+1);
            }
            r = n-1;
            while(r>=0 && a[r]%x==0){
                r--;
            }
            if(r>=0){
                answ = max({answ,n-r,r});
            }
        }
        cout << answ << '\n';
    }

    return 0;
}
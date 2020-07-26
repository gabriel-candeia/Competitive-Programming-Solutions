#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> a(n,0);
        for(int i=0;i<n;i++){
            cin >> a[i];
            if(a[i]<0){
                a[i]*=-1;
            }
        }
        int sign=1;
        for(int i=0;i<n;i++){
            cout << a[i]*sign << ' ';
            sign*=-1;
        }
        cout << '\n';

    }

    return 0;
}
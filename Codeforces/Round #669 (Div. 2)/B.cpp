#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    return (b==0) ? a : gcd(b,a%b);
}

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        vector<int> a(n,0);
        int last = 0;        
        for(auto &p:a){
            cin >> p;
            last = max(last,p);
        }
        vector<int> b(n,0);
        for(int i=0;i<n;i++){
            int mx = -1, cmp = -1;
            for(int j=0;j<n;j++){
                if(a[j]!=0 && gcd(a[j],last)>cmp){
                    mx = j;
                    cmp = gcd(a[j],last);
                }
            }
            last = cmp;
            b[i] = a[mx];
            a[mx] = 0;
        }

        for(int i=0;i<n;i++){
            cout << b[i] << ' ';
        }cout <<'\n';
   }

    return 0;
}
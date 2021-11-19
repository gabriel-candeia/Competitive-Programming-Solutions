#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string a, b;
        int zeros=0,ones=0;
        cin >> n >> a >> b;
        for(int i=0;i<a.size();i++){
            zeros += a[i]=='0';
            ones += a[i]=='1';
        }
        bool eq = true, ok = true;
        for(int i=a.size()-1;i>=0;i--){
            if((a[i]==b[i])!=eq)
                eq = !eq, ok = ok && (ones==zeros);
            zeros -= a[i]=='0';
            ones -= a[i]=='1';
        }
        cout << ((ok) ? "YES" : "NO") << "\n";

    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x, dg=0;
    int a, b, t;
    cin >> t;
    while(t--){
        cin >> n >> x;
        dg = 0;
        for(int i=0;i<n-1;i++){
            cin >> a >> b;
            dg += (a==x || b==x);
        }

        
        if(dg<=1){
            cout << "Ayush\n";
        }
        else{
            cout << (((n-2)%2) ? "Ashish" : "Ayush") << '\n';
        }
    }
    return 0;
}
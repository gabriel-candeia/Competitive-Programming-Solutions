#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, mx;
        cin >> n >> k;

        mx = n/2 + n%2;
        if(k<=mx){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j && i%2==0 && k){
                        cout << "R";
                        k--;
                    }
                    else{
                        cout << ".";
                    }
                }
                cout <<'\n';
            }
        }
        else{
            cout << "-1" <<"\n";
        }
    }

    return 0;
}
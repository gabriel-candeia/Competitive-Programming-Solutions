#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        int curr = 0, size = n/m, prox = 0;
        for(int i=0;i<k;i++){
            for(int j=0;j<m;j++){
                int tam = size + (j<n%m);
                if(j==n%m)
                    prox = curr;
                cout << tam << " ";
                while(tam--){
                    cout << curr+1 << " ";
                    curr = (curr+1)%n;
                }
                cout <<"\n";
            }
            curr = prox;
        }
        cout << "\n";
    }

    return 0;
}

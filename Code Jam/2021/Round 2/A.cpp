#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;

    cin >> t >> n;
    while(t--){
        int x;
        for(int i=1;i<n;i++){
            cout << "M" << " " << i << " " << n << endl;
            int j;
            cin >> j;
            if(j==-1) return 0;
            if(i!=j){
                cout << "S" << " " << i << " " << j <<endl;
                cin >> x;
            }
            if(x==-1) return 0;
        }
        cout << "D" << endl ;
        cin >> x;
        if(x==-1) return 0;
    }

    return 0;
}
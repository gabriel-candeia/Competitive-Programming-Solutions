#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;

    cin >> n >> m >> k;

    if(k > min(n,m)){
        cout << "Impossible" <<"\n";
    }
    else{
        cout << "Possible" <<"\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                if(i==j && i<k)
                    cout << "*";
                else
                    cout << ".";
            cout <<"\n";
        }
    }

    return 0;
}
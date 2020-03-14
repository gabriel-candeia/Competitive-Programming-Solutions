#include<bits/stdc++.h>
#define N 1000+3
using namespace std;

int main(){
    int p[N], n, w;
    vector<bool> v;

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> p[i];
    }

    for(int i=1;i<=n;i++){
        w = i;
        v.assign(n+3,false);
        do{
            v[w] = true;
            w = p[w];
        }while(v[w]==false);
        cout << w << ' ';
    }
    cout << '\n';
    return 0;
}
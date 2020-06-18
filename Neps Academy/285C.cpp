#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    vector<int> L(100,0), R(100,0);
    char l;

    cin >> n;
    while(n--){
        cin >> m >> l;
        if(l=='E'){
            L[m]++;
        }
        else{
            R[m]++;
        }
    }

    int cnt = 0;
    for(int i=0;i<=100;i++){
        cnt += min(L[i],R[i]);
    }
    cout << cnt << '\n';

    return 0;
}
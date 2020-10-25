#include<bits/stdc++.h>
using namespace std;

int main(){
    int cnt=1;
    vector<int> c(4,0);

    for(auto &x:c){
        cin >> x;
    }

    for(int i=0;c[i]==0;i++){
        cnt++;
    }

    cout << cnt <<'\n';
    return 0;
}
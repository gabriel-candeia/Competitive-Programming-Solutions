#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,ptr=2;
    vector<int> k;

    cin >> n;
    cout << 2*(n/2)+(n-n/2) <<'\n';
    for(int i=2;i<=n;i+=2){
        cout << i << " ";
    }
    for(int i=1;i<=n;i+=2){
        cout << i << " ";
    }
    for(int i=2;i<=n;i+=2){
        cout << i << " ";
    }
    cout<<'\n';
    return 0;
}
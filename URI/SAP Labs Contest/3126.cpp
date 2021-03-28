#include<bits/stdc++.h>
using namespace std;

int main(){ 
    int n, acm=0, x;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        acm+=x;
    }

    cout << acm <<'\n';
    
    return 0;
}
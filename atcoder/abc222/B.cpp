#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, p;

    cin >> n >> p;
    int acm = 0;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        acm += (x<p);
    }

    cout << acm <<"\n";

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, x, s;

    cin >> t >> s >> x;

    if((x>=s+t && (x-t)%s <= 1)||(x==t)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

    return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, prev, x=1, curr;

    cin >> n;
    cout << 1 << endl;
    cin >> prev;
    for(int i=0;i<n-1 && prev!=0;i++){
        cout << 2*x << endl;
        cin >> curr;

        if(curr<prev)
            x = 2*x;
        else
            x = 2*x+1;
        prev--;
    }

    cout << "! " << x <<endl;

    return 0;
}
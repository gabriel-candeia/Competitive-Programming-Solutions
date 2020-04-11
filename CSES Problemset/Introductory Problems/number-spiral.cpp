#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, x, y;
    long long int answ, k, diff;

    cin >> t;
    while(t--){
        cin >> y >> x;

        k = max(x,y);
        diff = min(x,y);
        answ = k*k - diff + 1;
        if((k%2==0 && x>y) || (k%2==1 && x<y)){
            answ = (k-1)*(k-1) + diff;
        }
       cout << answ << '\n';
    }   

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    int x, n, p, odd, even, a;

    cin >> t;
    while(t--){
        cin >> n >> x;
        odd = 0;
        for(int i=0;i<n;i++){
            cin >> a;
            odd+=a%2;
        }
        even = n-odd;
        bool poss = false;
        for(int i=1;i<=min(odd,x);i+=2){
            if(i+even>=x){
                poss = true;
                break;
            }
        }

        if(poss){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }

    }

    return 0;
}
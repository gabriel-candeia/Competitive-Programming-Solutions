#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    int x, n, a, p, odd, even;

    cin >> t;
    while(t--){
        cin >> n >> x;
        odd = 0;
        for(int i=0;i<n;i++){
            cin >> a;
            odd+=a%2;
        }
        even = n-odd;

        if((x%2 && (odd-(odd%2==0)+even-(even%2==1))>=x) || (x%2==0 && odd>=1 && even>=1 && (odd-(odd%2==0)+even-(even%2==0))>=x)){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }

    }

    return 0;
}
/*
se i for impapar 
    tu soma i a resposta e para
se não
    soma n a resposta e ai faz i = teto(i/2) n = teto(n/2)
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, x; cin >> n >> x;
        if(x % 2 == 1) {
            cout << x/2+1 << endl;
            continue;
        }

        int v = 1;

        int ans = 0;

        while(1) {
            int oldn = n;
            int before = (x-1)/2; 
            if(v==1 and x % 2 == 1) {
                cout << ans + x/2+1 << endl;
                break;
            }
            else if(v==0 and x % 2 == 0) {
                cout << ans + x/2 << endl;
                break;
            }
            ans += ((v==1) ? n/2+n%2 : n/2); // 3 saem 
            n = ((v==1) ? n/2 : n-n/2);         // 3 ficam
            x = before+1;   
            v = ((oldn % 2 == 0) ? v : 1-v);
        }
    }
}


//1 x 3 4 5 6 -> saem 3

//x 4 6 ->

//x 6


// n = 9
// x = 6
// 1 2 3 4 5 x 7 8 9

// n - n/2 = 5, quantidade de caras que saíram.

// --> n = par, então v = 1

// -> array resultante: 2 4 x 8

// x tá numa pos impar, então ans = caras_que_sairam + x/2



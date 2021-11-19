#include <bits/stdc++.h>

using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'

typedef pair <int, int> ii;
typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n > 12)
            cout << "0" << endl;
        else{
            if(n <= 7)
                cout << (n/2) << endl;
            else if(n == 8)
                cout << "3" << endl;
            else if(n == 9 or n == 10)
                cout << "2" << endl;
            else
                cout << "1" << endl;
        }
    }
    return 0;
}
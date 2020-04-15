#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, a, b;
    int cnt;
    char next;

    cin >> t;
    while(t--){
        cin >> n >> a >> b;
        cnt=0;
        next = 'a';

        while(cnt<n){
            cout << char('a' + cnt%b);
            cnt++;
        }
        cout << '\n';

    }


}
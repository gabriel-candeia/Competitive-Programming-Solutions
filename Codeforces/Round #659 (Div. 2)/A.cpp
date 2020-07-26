#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, x;
    string s;

    cin >> t;
    while(t--){
        cin >> n;
        s = string(200,'a');
        cout << s << '\n';
        while(n--){
            cin >> x;
            for(int i=x;i<200;i++){
                s[i] = ((s[i]=='a') ? 'b' : 'a');
            }
            cout << s << '\n';
        }
    }

    return 0;
}
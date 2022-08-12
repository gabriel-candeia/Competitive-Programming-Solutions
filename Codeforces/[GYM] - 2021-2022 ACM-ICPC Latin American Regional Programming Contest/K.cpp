#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int main(){
    fastio();
    int n;
    vector<string> arr;
    vector<int> ok(300,0);

    cin >> n;
    arr.assign(n,"");
    for(auto &x:arr)
        cin >> x, ok[x[0]-'A'] = 1;

    bool answ = false;
    for(auto &x:arr){
        bool temp = true;
        for(auto c:x){
            temp = temp && ok[c-'A'];
        }
        answ = answ || temp;
    }

    cout << ((answ) ? "Y" : "N") <<"\n";

    return 0;
}
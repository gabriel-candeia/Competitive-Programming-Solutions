#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        cin >> n;

        string base = "";
        for(int i=0;i<n;i++)
            base +="()";
        string pref = "", suff = "";
        for(int i=0;i<n;i++){
            cout <<pref << base << suff << "\n";
            base.pop_back();
            base.pop_back();
            pref.push_back('(');
            suff.push_back(')');
        }

    }

    return 0;
}
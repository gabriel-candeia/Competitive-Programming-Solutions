#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;

    cin >> s;
    while(s.size() && s.back()=='0') s.pop_back();
    bool poss = true;
    for(int i=0;i<s.size();i++)
        if(arr[i]!=arr[s.size()-1-i])
            poss = false;

    cout << ((poss) ? "Yes" : "No") << "\n";

    return 0;
}


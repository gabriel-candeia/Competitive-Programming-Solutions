#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        string s;
        vector<int> last(300,-1);
        bool ok = true;

        cin >> n >> s;
        for(int i=0;i<s.size();i++){
            if(last[s[i]]!= -1 && last[s[i]]!= i-1)
                ok = false;
            last[s[i]] = i;
        }

        cout << ((ok) ? "YES" : "NO") << "\n";
    }

    return 0;
}
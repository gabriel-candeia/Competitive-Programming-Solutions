#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        int cnt[2] = {0,0}, n;
        cin >> n >> s;
        for(int i=0;i<n-1;i++)
            if(s[i]==s[i+1])
                cnt[s[i]-'0']++;

        cout << max(cnt[0],cnt[1]) << '\n';
    }

    return 0;
}
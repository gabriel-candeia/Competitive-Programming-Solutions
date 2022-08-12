#include<bits/stdc++.h>
using namespace std;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s, t;

        cin >> s;
        t = string(s.rbegin(),s.rend());

        auto z1 = z_function(s+"#"+t), z2 = z_function(t+"#"+s);

        string answ = "simple";

        n = s.size();
        for(int i=0;i<n;i++){
            if(z1[i+n+1]==(n-i)){
                if(i==0){   
                    answ = "palindrome";
                }
                else{
                    int j = n-(i-1)-1;
                    if(z2[j+n+1]==n-j){
                        answ = "alindrome";
                        break;
                    }
                }
            }
        }

        cout << answ <<"\n";

    }

    return 0;
}
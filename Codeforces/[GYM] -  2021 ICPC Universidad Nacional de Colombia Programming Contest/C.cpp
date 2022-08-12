#include <bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

vector<int> prefix(const string& s) {
    int len = s.size();
    vector<int> pi(len);
    for(int i = 1; i < len; i++) {
        int j = pi[i-1];
        while(j > 0 && s[len-j-1] != s[len-i-1])
            j = pi[j-1];
        if(s[len-j-1] == s[len-i-1])
            pi[i] = j+1;
    }
    return pi;
}

ll sum(string& s) {
	string aux;
	ll ans = 0;
	reverse(s.begin(),s.end());
    while(s.size()){
        auto arr = prefix(s);
        for(auto &x:arr)
            ans += x;
        s.pop_back();
    }

	return ans;
}

int main() {
	string s;
	while(cin >> s) {
		cout << sum(s) << endl;
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
	string s1, s2; cin >> s1 >> s2;

	if(s1.size() != s2.size()) {
		cout << "NO" << endl;
		return 0;
	}

	if(s1 == s2) {
		cout << "YES" << endl;
		return 0;
	}

	int pre_idx = 0;
	int suf_idx = s1.size()-1;

	for(int i = 0; i < s1.size(); i++) {
		if(s1[i] != s2[i]) {
			pre_idx = i;
			break;
		}
	}

	for(int i = s1.size()-1; i >= 0; i--) {
		if(s1[i] != s2[i]) {
			suf_idx = i;
			break;
		}
	}

	string sub = s1.substr(pre_idx, suf_idx-pre_idx+1);
    
	reverse(sub.begin(), sub.end());

	for(int i = pre_idx; i <= suf_idx; i++) {
		s1[i] = sub[i-pre_idx];
	}

	if(s1 == s2) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}
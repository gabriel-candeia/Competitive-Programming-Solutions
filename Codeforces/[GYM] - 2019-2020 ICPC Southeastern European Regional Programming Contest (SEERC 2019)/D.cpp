#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;  

string s, ans;
int freq[26];

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);		
	char ch;
	cin >> s;
	int ate = s.size()-2, n = s.size()/2;
	for(int i = 0; i < s.size(); i++){
		ch = s[i]-'a';
		++freq[ch];
	}
	int letra1 = 0, letra2 = 0;
	int maiorFreq = 0, maiorFreq2 = 0, distintos = 0;
	for(int i = 0; i < 26; i++){
		if(freq[i] > maiorFreq){
			letra1 = i;
			maiorFreq = freq[i];
		}
		distintos += (freq[i] != 0);
	}
	for(int i = 0; i < 26; i++){
		if(i != letra1 && freq[i] > maiorFreq2){
			letra2 = i;
			maiorFreq2 = freq[i];
		}
	}
	ans = "";	
	if(maiorFreq <= n){
		cout << "YES\n";
		for(int i = 0; i < 26; i++){
			ans += string(freq[i], i+'a');
		}
		cout << ans << "\n";
	}else if(maiorFreq == ate && distintos-1 >= 2){
		cout << "YES\n";
		ans += string(n, char(letra1+'a')); freq[letra1] -= n;
		for(int i = 0; i < 26; i++){
			if(i != letra1 && freq[i]){
				ans += char(i+'a');
				--freq[i];
				break;
			}
		}
		ans += string(freq[letra1], char(letra1+'a')); freq[letra1]=0;
		for(int i = 0; i < 26; i++){
			if(i != letra1 && freq[i]){
				ans += string(freq[i], char(i+'a'));
			}
		}
		cout << ans << "\n";
	}else if(maiorFreq < ate && (maiorFreq2 >= 3 || distintos-1 >= 2)){
		cout << "YES\n";
		ans += string(n, char(letra1+'a')); freq[letra1] -= n;
		for(int i = 0; i < 26; i++){
			if(i != letra1 && freq[i]){
				ans += char(i+'a');
				--freq[i];
				break;
			}
		}
		ans += string(freq[letra1], char(letra1+'a')); freq[letra1]=0;
		for(int i = 0; i < 26; i++){
			if(i != letra1 && freq[i]){
				ans += string(freq[i], char(i+'a'));
			}
		}
		cout << ans << "\n";

	}else{
		cout << "NO\n";
	}
	return 0;
}

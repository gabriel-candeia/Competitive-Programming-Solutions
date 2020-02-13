#include<bits/stdc++.h>

using namespace std;

int main(){
	int T;
	string ent, answ;

	cin >> T;
	while(T--){
		char alphabet[26];
		for(int i=0;i<26;i++) alphabet[i] = 0;
		cin >> ent;
		answ = "";
		for(int i=0;i<ent.size();i++){
			alphabet[ent[i]-'a']++;
		}
		string odd = "";
		string even = "";
		for(int i=1;i<26;i+=2) odd += string(alphabet[i],i+'a');
		for(int i=0;i<26;i+=2) even += string(alphabet[i],i+'a');
		bool isgood=true;
		answ = odd+even;
		for(int i=0;i<ent.size()-1;i++){
			isgood *= (abs(answ[i]-answ[i+1])!=1);
		}
		if(isgood){
			cout << answ << '\n';
		}
		else{
			answ = even+odd;
			isgood = true;
			for(int i=0;i<ent.size()-1;i++){
				isgood *= (abs(answ[i]-answ[i+1])!=1);
			}
			if(isgood) cout << answ << '\n';
			else cout << "No answer\n";
		}
	}
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

char find_candidate(char a, char b){
	for(char i='a';i<='z';i++){
		if(i!=a && i!=b){
			return i;
		}
	}
}

int main(){
	int n, t, r;
	string s1, s2;
	int baixa1, baixa2;
	string answ = "";

	cin >> n >> t;
	cin >> s1 >> s2;

	r=0;
	for(int i=0;i<n;i++){
		r+=(s1[i]==s2[i]);
	}
	baixa1 = n-t-r;
	baixa2 = n-t-r;

	if(baixa1+baixa2+r<=n){
		int cont = n-t;
		for(int i=0;i<n;i++){
			if(s1[i]!=s2[i]){
				if(baixa1>0){
					answ +=s1[i];
					baixa1--;
				}
				else if(baixa2>0){
					answ +=s2[i];
					baixa2--;
				}
				else{
					answ += find_candidate(s1[i],s2[i]);
				}
			}
			else if(cont){
				answ += s1[i];
				cont--;
			}
			else{
				answ += find_candidate(s1[i],s2[i]);
			}
		}
		cout << answ << '\n';
	}
	else{
		cout << "-1\n";
	}

	return 0;
}
#include<iostream>
#include<string>
#define ll long long int

using namespace std;

int main(){
	ll letras[30];
	string ent;
	int poss = 0;
	cin >> ent;


	for(ll i=0;i<26;i++){
		letras[i]=0;
	}

	for(ll i=0;i<ent.size();i++){
		letras[ent[i]-'a']++;
	}
	for(ll i=0;i<26;i++){
		poss+=(letras[i]%2);
	}
	if((poss<=1)||(ent.size()%2==1)){
		cout << "First\n";
	}
	else{
		cout << "Second\n";	
	}
	return 0;
}
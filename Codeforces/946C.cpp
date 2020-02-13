#include<bits/stdc++.h>
#define N 100100
using namespace std;

int main(){
	string ent;
	int top=0;

	cin >> ent;

	for(int i=0;i<ent.size()&(top<26);i++){
		if(ent[i]-'a'<=top){
			top++;
			ent[i]='a'+top-1;
		}
	}

	if(top==26){
		cout << ent << "\n";
	}
	else{
		cout << "-1\n";
	}

	return 0;
}
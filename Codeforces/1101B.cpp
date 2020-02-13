#include<iostream>

using namespace std;

int main(){
	int l, r;
	bool lB = false, rB = false;
	int acm=0;
	string ent;

	cin >> ent;

	for(l=0;l<ent.size();l++){
		if(ent[l]=='['){
			lB = true;
		}
		if(ent[l]==':'&&lB){
			break;
		}
	}

	for(r=ent.size()-1;r>=0;r--){
		if(ent[r]==']'){
			rB = true;
		}
		if(ent[r]==':'&&rB){
			break;
		}
	}

	if(l<r&&l>=0){
		acm+=4;
		for(l;l<r;l++){
			if(ent[l]=='|'){
				acm++;
			}
		}
	}
	else{
		acm = -1;
	}

	cout << acm << '\n';

	return 0;
}
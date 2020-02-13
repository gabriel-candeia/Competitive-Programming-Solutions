#include<bits/stdc++.h>

using namespace std;

int minmoves(char a, char b){
	if(a>b){
		return min(b-a+26,a-b);
	}
	else{
		return min(b-a,a-b+26);
	}
}

int main(){
	int n;
	int operations=0;
	string ent;
	int mint;
	int curr;
	cin >> n >> ent;

	mint = -1;
	for(int i=0;i<=n-4;i++){
		curr = minmoves('A',ent[i])+minmoves('C',ent[i+1])+minmoves('T',ent[i+2])+minmoves('G',ent[i+3]);
		if(curr<mint||mint==-1){
			mint=curr;
		}
	}

	cout <<  mint << '\n';

	return 0;
}

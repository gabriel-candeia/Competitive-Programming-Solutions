#include<bits/stdc++.h>

using namespace std; 

int compute_moves(string ent, char start){
	int moves = 0;
	int aux = 'b'^'r';
	int wb=0	, wr=0;
	for(int i=0;i<ent.size();i++){
		if(ent[i]!=start){
			wr+=(ent[i]=='r');
			wb+=(ent[i]=='b');
		}
		start ^= aux;	
	}
	moves = min(wb,wr)+abs(wb-wr);
	return moves;
}


int main(){
	int n;
	string ent;

	cin >> n >> ent;

	cout << min(compute_moves(ent,'r'),compute_moves(ent,'b')) << '\n';

	return 0;
}
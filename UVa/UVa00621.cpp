#include<bits/stdc++.h>

using namespace std;

int main(){
	string ent;
	int len;
	int n;
	cin >> n;
	for(;n;n--){
		// leitura
		cin >> ent;
		len = ent.size();
		//exec
		if(ent=="1"||ent=="4"||ent=="78"){
			cout << "+\n";
		}
		else if(ent[len-1]=='5'&&ent[len-2]=='3'){
			cout << "-\n";
		}
		else if(ent[len-1]=='4'&&ent[0]=='9'){
			cout << "*\n";
		}
		else if(ent[0]=='1'&&ent[1]=='9'&&ent[2]=='0'){	
			cout << "?\n";
		}
	}

	return 0;
}

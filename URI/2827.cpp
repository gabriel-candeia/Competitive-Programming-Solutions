#include<bits/stdc++.h>

using namespace std;

int main(){
	map<string,int> tokens;
	string ent;
	string temp;

	cin >> ent;

	for(int i=0;i<ent.size();i++){
		if(ent[i]<97) ent[i] = ent[i]+32;		
	}

	cout << ent << endl;

	for(int i=0;i<ent.size()-1;i++){
		temp = ent[i]+ent[i+1];
		if(tokens.count(temp)==0){
			tokens[temp]=1;
		}
		else{
			tokens[temp]+=1;	
		}
	}
	int maior=0;
	string maiorT;
	for(auto const& x : tokens){
		if(x.second>maior){
			maiorT = x.first;
			maior = x.second;
		}
		else if(x.second==maior){
			
		}
	}

	return 0;
}
#include<iostream>
#include<string>

#define N 300100

using namespace std;

int main(){
	int n;
	string ent;
	string answ;
	char stack[N];
	int indices[N];
	int topoI=0;
	int topo=0;

	cin >> n >> ent;
	if(ent[0]==')'){
		topo = 100;
	}
	else{
		ent[0] = '(';
		for(int i=0;i<n;i++){
			if(topo==0||ent[i]=='('){
				stack[topo++] = ent[i];
			}
			else if(stack[topo-1]=='('&&ent[i]=='?'){
				stack[topo++] = ent[i];
				indices[topoI++] = i;
			}
			else if(stack[topo-1]=='('&&ent[i]==')'){
				topo--;
			}
			else if(stack[topo-1]=='?'&&(ent[i]==')')){
				topo--;
				ent[indices[topoI-1]]='(';
				topoI--;
			}
			else if(stack[topo-1]=='?'&&(ent[i]=='?')){
				topo--;
				ent[i]=')';
				ent[indices[topoI-2]]='(';
				topoI-=2;
			}
		}	
	}
	
	if(topo==0){
		cout << ent << '\n';
	}
	else{
		cout << ":(\n";
	}

	return 0;
}
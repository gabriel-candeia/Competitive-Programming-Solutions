#include<iostream>
#include<string>

#define N 300100

using namespace std;

int main(){
	int n;
	string ent;
	string answ;
	char stack[N];
	int topo=0;

	cin >> n >> ent;
	for(int i=0;i<n;i++){
		if(ent[i]=='?'){
			if(topo<=1&&i!=n-1){
				ent[i]='(';
			}
			else{
				ent[i]=')';
			}
		}

		if(topo==0||ent[i]=='('){
			stack[topo++] = ent[i];
		}
		else if(stack[topo-1]=='('&&ent[i]==')'){
			topo--;
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
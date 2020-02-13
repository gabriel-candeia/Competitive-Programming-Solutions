#include<iostream>
#include<string>
#define N 200100
using namespace std;

int main(){
	int n, k;
	int complete;
	char stack[N];
	int top=0;
	string ent;

	cin >> n >> k;
	cin >> ent;

	complete = n-k;
	for(int i=0;i<ent.size();i++){
		if(ent[i]=='('||complete==0){
			stack[top++]=ent[i];
		}
		else if(stack[top-1]=='(' && ent[i]==')'){
			complete-=2;
			top--;
		}
	}

	for(int i=0;i<top;i++){
		cout << stack[i];
	}
	cout << "\n";
	return 0;
}
#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;



int main(){
	ll n, x, y;
	ll stack[200100], top;
	ll kids[200100][2], current;
	cin >> n;

	for(int i=0;i<n;i++){
		cin >> kids[i][0] >> kids[i][1];
	}

	top = 0;
	current = 0;

	//put 2 kids in the stack
	stack[top++]=1;
	x = kids[0][0]; y = kids[0][1];
	if(x!=kids[y-1][0]&&x!=kids[y-1][1]){
		stack[top++] = x;
	}
	else{
		stack[top++] = y;	
	}

	//decide next kid seeing top kid and previous kid
	while(top!=n){
		x = kids[stack[top-1]-1][0];
		y = kids[stack[top-1]-1][1];
		if(y==kids[stack[top-2]-1][0]||y==kids[stack[top-2]-1][1]){
			stack[top++] = y;
		}
		else{
			stack[top++] = x;	
		}		
	}

	//print
	for(int i=0;i<n;i++){
		cout << stack[i] << " ";
	}
	cout << '\n';
	return 0;
}

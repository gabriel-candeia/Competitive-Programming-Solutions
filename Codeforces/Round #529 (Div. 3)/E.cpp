//O(n^2)

#include<iostream>
#include<string>
#define ll long long int
using namespace std;

int regular(string input, ll n){
	ll stack[1000010], top;
	top = 0;
	for(int i=0;i<n;i++){
		if(top){
			if(input[i]=='('){
				stack[top++] = input[i];
			}
			else if(input[i]==')'){
				top--;
			}
		}
		else{
			stack[top++] = input[i];
			if(input[i]==')'){
				break;
			}
		}
	}

	return (top==0) ? 1 : 0;
}

int main(){
	string input;
	ll n,counter;

	cin >> n >> input;
	counter = 0;
	for(int i=0;i<n;i++){
		input[i] = ((input[i]=='(') ? (')') : ('('));
		counter+=regular(input,n);
		input[i] = ((input[i]=='(') ? (')') : ('('));
	}	

	
	
	cout << counter <<'\n';
	return 0;
}

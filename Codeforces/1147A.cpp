#include<iostream>
#include<string.h>
#define N int(1e5)+10
using namespace std;

int main(){
	int n, k;
	int last[N], first[N], x[N]; 
	bool appeared[N];
	int parescont = 0;
	cin >> n >> k;

	memset(last,-1,sizeof(last));
	memset(first,-1,sizeof(first));
	memset(appeared,false,sizeof(appeared));

	for(int i=0;i<k;i++){
		cin >> x[i];
		if(appeared[x[i]] == false){
			appeared[x[i]] = true;
			first[x[i]] = i;
		}
		last[x[i]] = i;
	}

	for(int i=1; i<n; i++){
		if(first[i]==-1){
			parescont++;
		}
		if(last[i+1] < first[i] ||last[i+1]==-1||first[i]==-1){
			parescont++;
		}
		if(last[i] < first[i+1] ||last[i]==-1||first[i+1]==-1){
			parescont++;
		}
	}
	if(first[n]==-1){
		parescont++;
	}
	cout << parescont << '\n';

	return 0;
}
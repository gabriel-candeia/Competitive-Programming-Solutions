#include<iostream>
#include<string>
#define N 500001
using namespace std;

int main(){
	char rotina[N];
	int valor[N] = {0};
	int n;
	int i, j;
	int max;

	cin >> n;

	for(i = 0;i<n;i++){
		cin >> rotina[i];
	}

	for(i = 0;i<n;i++){
		if(rotina[i]=='0'){
			valor[i] = 0;
			for(j=(i-1)%n+((i-1)<0)*n;rotina[j]!='0';j=(j-1)%n+((j-1)<0)*n){
				valor[j] = valor[(j+1)%n]+1;
			}
			//cout << j << "aux\n";
		}
	}

	max = 0;
	for(i=0;i<n;i++){
		if(max<valor[i]){
			max = valor[i];
		}
	}
	cout << max << "\n";
	return 0;
}

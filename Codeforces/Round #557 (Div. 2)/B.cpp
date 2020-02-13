#include<iostream>
using namespace std;

int main(){		
	int matA[100][100], matB[100][100];
	int n, m;
	bool poss = true;

	cin >> n >> m;

	for(int i=0;i<n;i++){		
		for(int j=0;j<m;j++){
			cin >> matA[i][j];
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> matB[i][j];
			if(matB[i][j] < matA[i][j]){
				swap(matB[i][j],matA[i][j]);
			}
		}
	}

	for(int i=1;i<m;i++){
		if(matA[0][i] <= matA[0][i-1]) poss = false;
		if(matB[0][i] <= matB[0][i-1]) poss = false;
	}

	for(int i=1;i<n;i++){
		if(matA[i][0] <= matA[i-1][0]) poss = false;
		if(matB[i][0] <= matB[i-1][0]) poss = false;
	}

	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(matA[i][j] <= matA[i][j-1] || matA[i][j] <= matA[i-1][j]) poss = false;
			if(matB[i][j] <= matB[i][j-1] || matB[i][j] <= matB[i-1][j]) poss = false;
		}	
	}		

	if(poss){
		cout << "Possible\n";
	}
	else{
		cout << "Impossible\n";	
	}

	return 0;
}
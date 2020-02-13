#include<bits/stdc++.h>
#define N int(1e4)+10
using namespace std;

int main(){
	int n;
	bool poss;
	int stackI[N], stackJ[N];
	int topI, topJ, x, y;
	int mapa[7][7];

	cin >> n;
	for(int i=0;i<7;i++){
		mapa[0][i] = 1;
		mapa[6][i] = 1;
		mapa[i][0] = 1;
		mapa[i][6] = 1;
	}
	while(n--){
		for(int i=1;i<6;i++){
			for(int j=1;j<6;j++){
				cin >> mapa[i][j];
			}
		}	
		poss =false;
		topI = 0;
		stackI[topI++] = 1;
		topJ = 0;
		stackJ[topJ++] = 1;
		while(topI){
			x = stackI[--topI];
			y = stackJ[--topJ];
			if(x==5&&y==5){
				poss = true;
				break;
			}
			if(mapa[x][y+1]==0){
				mapa[x][y+1] = 1;
				stackI[topI++] = x;
				stackJ[topJ++] = y+1;
			}
			if(mapa[x+1][y]==0){
				mapa[x+1][y] = 1;
				stackI[topI++] = x+1;
				stackJ[topJ++] = y;
			}
			if(mapa[x-1][y]==0){
				mapa[x-1][y] = 1;
				stackI[topI++] = x-1;
				stackJ[topJ++] = y;
			}
			if(mapa[x][y-1]==0){
				mapa[x][y-1] = 1;
				stackI[topI++] = x;
				stackJ[topJ++] = y-1;
			}
		}
		if(poss){
			printf("COPS\n");
		}
		else{
			printf("ROBBERS\n");
		}
	}

	return 0;
}
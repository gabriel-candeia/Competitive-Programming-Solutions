#include<iostream>
#include<map>
#define N 300100
using namespace std;

int main(){
	int n, temp;
	map<int,int> colors;
	int menor[N];
	int maior[N];
	cin >> n;

	int c=0;
	int index;
	int answ = -1;

	for(int i = 0; i < n; i++){
		maior[i] = -1;
		menor[i] = N+1;
	}

	for(int i=0;i<n;i++){
		cin >> temp;
		if(colors[temp]==0){
			colors[temp] = ++c;
		}
		index = colors[temp]-1;
		menor[index] = min(i,menor[index]);
		maior[index] = max(i,maior[index]);
	}

	for(int i=0;i<c-1;i++){
		for(int j=i+1;j<c;j++){
			answ = max(answ,max(abs(maior[i]-menor[j]),abs(maior[j]-menor[i])));
		}
	}

	cout << answ << "\n";

	return 0;
}
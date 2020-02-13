#include<iostream>
#define N 1000
using namespace std;

int main(){
	int n, m, h;
	int maxrows[N], maxcolumns[N];
	int t;
	cin >> n >> m >> h;

	for(int i=0;i<m;i++){
		cin >> maxcolumns[i];
	}

	for(int i=0;i<n;i++){
		cin >> maxrows[i];
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> t;
			if(t==1){
				cout << min(maxrows[i],maxcolumns[j])<<' ';
			}
			else{
				cout << 0 <<' ';
			}
		}
		cout << "\n";
	}

	return 0;
}

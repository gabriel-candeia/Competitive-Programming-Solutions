#include<iostream>

using namespace std;

int main(){
	int n;
	int columns;
	int dist, y1, y2;
	bool imprimir;

	cin >> n;

	for(;n;n--){
		cin >> columns;
		cin >> y1 >> y2;
		dist = (y1-y2);
		imprimir = true;

		for(int i=0;i<columns-1;i++){
			cin >> y1 >> y2;
			if(y1-y2 != dist){
				imprimir = false;
			}	
		}

		if(imprimir) cout << "yes\n";
		else cout << "no\n";	
		if(n-1) cout << "\n";
	}

	return 0;
}




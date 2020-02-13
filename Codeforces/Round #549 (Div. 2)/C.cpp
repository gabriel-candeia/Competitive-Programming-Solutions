#include<bits/stdc++.h>
#define N 100100

using namespace std;

int main(){
	vector<int> adj[N];
	int parrents[N];
	int c[N];
	int parrent, ci;
	int root;
	int n;

	cin >> n;

	for(int i=0;i<n;i++){
		cin >> parrent >> ci;
		if(parrent==-1){
			root = i;
		}
		else{
			adj[parrent-1].push_back(i);
		}
			parrents[i] = parrent-1;
			c[i] = ci;
	}

	bool aux;
	bool isFirst = true;
	int tempParrent;
	for(int i=0;i<n;i++){
		if(c[i]==1){
			aux = true;
			//ve se tem que remover
			for(int j=0;j<adj[i].size();j++){
				if(c[adj[i][j]]==0){
					aux = false;
					break;
				}
			}
			//remove
			if(aux){
				tempParrent = parrents[i];
				/*for(int j=0;j<adj[i].size();j++){
					adj[tempParrent].push_back(adj[i][j]);
					parrents[adj[i][j]] = tempParrent;
				}*/
				//adj[i].clear();
				if(isFirst){
					cout << i+1;
					isFirst= false;
				}
				else{
					cout << ' ' << i+1 ;	
				}
			}
		}
	}
	if(isFirst){
		cout << "-1";
	}
	cout << endl;
	return 0;
}

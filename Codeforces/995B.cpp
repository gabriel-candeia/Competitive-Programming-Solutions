#include<iostream>

using namespace std;

int main(){
	int n, aux;
	bool ispresent[110] = {false};
	int stack[300];
	int topo=0;
	int swaps=0;
	int pivot;
	int j;

	cin >> n;

	for(int i=0;i<2*n;i++){
		cin >> aux;
		stack[topo++]=aux;
		if(ispresent[aux]){
			for(j=topo-2;j>=0;j--){
				if(stack[j]!=aux){
					stack[j+1]=stack[j];
					swaps++;
				}
				else{
					break;
				}
			}
			stack[j+1]=aux;
		}
		else{
			ispresent[aux]=true;
		}
	}
	cout << swaps << '\n';
	return 0;
}
#include<bits/stdc++.h>
#define N int(1e5)+10
using namespace std;

int main(){
	int n, total_diff, cont[1000], diff, l;
	int size;
	string ent;

	cin >> n >> ent;
	total_diff = 0;
	for(int i=0;i<='z';i++){cont[i] = 0;}
	for(int i=0;i<n;i++){
		total_diff += (cont[ent[i]]==0);
		cont[ent[i]]++;
	}
	//
	l = 0;
	diff=0;
	size = n;
	for(int i=0;i<='z';i++){cont[i] = 0;}
	for(int i=0;i<n;i++){
		diff += (cont[ent[i]]==0);
		cont[ent[i]]++;
		//pop first element
		while(diff==total_diff){
			size = min(size,i-l+1);
			cont[ent[l]]--;
			if(cont[ent[l]]==0){
				diff--;
			}
			l++;
		}
	}

	cout << size << '\n';
	return 0;
}
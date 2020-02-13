#include<bits/stdc++.h>
#define N 1000+10
using namespace std;

int main(){
	int n, m;
	int lines[N], columns[N];
	int l=0, c=0, l1=0,c1=0;;
	int x=0, y=0;
	char temp;

	cin >> n >> m;

	for(int i=0;i<m;i++){ columns[i] = 0;}
	for(int i=0;i<n;i++){
		lines[i]=0;
		for(int j=0;j<m;j++){
			cin >> temp;
			lines[i]+=(temp=='*');
		}		
	}

	for(int i=0;i<n;i++){
		l += (lines[i]>=2);
		l1 += (lines[i]==1);
		if(lines[i]>lines[x]){
			x = i;
		}
	}

	for(int i=0;i<m;i++){
		c += (columns[i]>=2);
		c1 += (columns[i]==1);
		if(columns[i]>columns[y]){
			y = i;
		}
	}

	if(c>=2||l>=2){
		cout << "NO\n";
	}
	else{
		if(c1==1&&){
			cout << "NO\n";		
		}
		else{
			cout << "YES\n";
			cout << x << y;
		}
	}

	return 0;
}
#include<iostream>
#define N 1001
using namespace std;

int main(){
	int n, m;
	int sections[N], t[N];
	int c[N];
	int l[N], r[N];
	int x, y;



	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> l[i] >> r[i] >> t[i] >> c[i];
		l[i]--;
		r[i]--;
	}

	for(int i=0;i<n;i++){
		sections[i]=-1;
	}

	for(int i=0;i<m;i++){
		for(int j=l[i];j<=r[i];j++){
			if(sections[j]==-1){
				sections[j] = i;
			}
			else if(t[i]<t[sections[j]]){
				sections[j] = i;
			}
		}
	}

	int acm = 0;
	for(int i=0;i<n;i++){
		if(sections[i]!=-1){
			acm+=c[sections[i]];
		}
	}

	cout << acm << endl;

	return 0;
}
#include<bits/stdc++.h>

using namespace std;
int main(){
	int A[7], temp, acm;
	int a12, a34, a56, a53;
	int num[6] = [4,8,15,16,23,42];

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << "? 1 2" << endl;
	cin >> a12;
	cout << "? 3 4" << endl;
	cin >> b34;
	cout << "? 5 5" << endl;
	cin >> c;
	cout << "? 5 3" << endl;
	cin >> a53;

	acm = 4*8*15*16*23*42;
	a56 = acm/(a12*a34);
	
	A[5] = sqrt(c);
	A[6] = a56/A[5];
	A[3] = a53/A[5];
	A[4] = a34/A[3];



	for(int i=0;i<6;i++){
		if(a*b*c*num[0]==acm){
			A[6] = num[0];
		}
	}
	return 0;
}

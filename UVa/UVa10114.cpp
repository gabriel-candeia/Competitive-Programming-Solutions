#include<bits/stdc++.h>
#define N 1000

using namespace std;

int main(){
	double carValue;
	double time, downPayment, loan;
	double depreciation[N];
	double parcel;
	int temp, cont, records;

	//input
	while(true){
		cin >> time >> downPayment >> loan >> records;
		if(time < 0){
			break;
		}
		for(int i=0;i<=time;i++){
			depreciation[i]=0;
		}
		for(int i=0;i<records;i++){ 
			cin >> temp;
			cin >> depreciation[temp];
		}
		for(int i=0;i<=time;i++){
			if(depreciation[i]==0&&i>=1) depreciation[i] = depreciation[i-1];
		}
		/*for(int i=0;i<time;i++){
			cout << depreciation[i] << ' ';
		}
		cout << '\n';*/
		//

		carValue = downPayment + loan;
		parcel = loan/time;
		loan += parcel;
		cont = 0;
		for(int i=0;i<=time;i++){
			carValue = carValue*(1-depreciation[i]);
			loan -= parcel;
			//cout << i << "| car value: " << carValue << "|| loan : " << loan << "\n";
			if(carValue>loan){
				cout << i << ((i==1) ? " month\n" : " months\n");
				break;
			}
		}
	}

	return 0;
}

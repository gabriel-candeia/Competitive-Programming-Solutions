#include<iostream>

using namespace std;

int main(){
	int n, farmers;
	double area, animals, env;
	double sum; 

	cin >> n;

	for(;n;n--){
		cin >> farmers;
		sum = 0;
		for(int i=0;i<farmers;i++){
			cin >> area >> animals >> env;
			sum += (area*env);
		}

		cout << sum << '\n';
	}
	return 0;
}

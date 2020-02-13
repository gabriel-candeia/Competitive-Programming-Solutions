#include<iostream>
#include<vector>
#include<algorithm>
#define N 1100
using namespace std;

int comparator(int a, int b){
	return a > b;
}

int main(){
	int n, temp;
	int mult[N] = {0};
	int cont;
	vector<int> s;

	cin >> n;

	for(int i=0;i<n;i++){
		cin >> temp;
		mult[temp]++;
	}

	for(int i=0;i<N;i++){
		if(mult[i]){
			s.push_back(mult[i]);
		}
	}
	cont = 0;
	sort(s.begin(),s.end(),comparator);
	while(s.size()){
		if(s.back()){
			cont+=s.back()*(s.size()-1);
			temp = s.back();
			for(int i=0;i<s.size();i++){
				s[i]-=temp;
			}
		}
		else{
			s.pop_back();
		}
	}
	cout << cont << "\n";
	return 0;
}
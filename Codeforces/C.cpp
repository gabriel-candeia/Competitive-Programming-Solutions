#include<bits/stdc++.h>
#define N 100100

using namespace std;

int main(){
	int n;
	vector<int> a;
	vector<int> b;
	int scoreA,scoreB;
	int temp;
	int atual, inimigo;

	cin >> n;
	for(int i=0;i<n;i++){
		cin >> temp;
		a.push_back(temp);
	}
	for(int i=0;i<n;i++){
		cin >> temp;
		b.push_back(temp);
	}

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	scoreA=0;
	scoreB=0;
	for(int i=0;b.size()||a.size();i++){
		if(i%2){
			if((b.size()!=0&&a.size()!=0)&&b.back()>a.back()){
				scoreA += a.back();
				a.pop_back();
			}
			else if(b.size()!=0){
				b.pop_back();
			}
		}
		else{
			if((a.size()!=0&&b.size()!=0)&&a.back()>b.back()){
				scoreB += b.back();
				b.pop_back();
			}
			else if(a.size()!=0){
				a.pop_back();
			}
		}
	}

	cout << scoreA - scoreB << '\n';

	return 0;
}
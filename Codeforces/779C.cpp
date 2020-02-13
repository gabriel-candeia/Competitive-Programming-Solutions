#include<iostream>
#include<algorithm>
#define N 200100
using namespace std;

int comparator(pair<int,int> a,pair<int,int> b){
	return((a.first-a.second)<(b.first-b.second));
}

int main(){
	int n, k;
	int a[N];
	int b[N];
	pair<int,int> resto[N];
	int top=0;
	int sum=0;
	int kaux;

	cin >> n >> k;

	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	for(int i=0;i<n;i++){
		cin >> b[i];
		if(a[i]<b[i]){
			k--;
			sum+=a[i];
		}
		else{
			resto[top++]=pair<int,int>(a[i],b[i]);
		}
	}

	sort(resto,resto+top,comparator);
	for(int i=0;i<top;i++){
		if(k>0){
			sum+=resto[i].first;
			k--;
		}
		else{
			sum+=resto[i].second;	
		}
	}

	cout << sum << "\n";
	return 0;
}
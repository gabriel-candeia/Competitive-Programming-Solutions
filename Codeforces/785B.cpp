#include<iostream>
#include<algorithm>
#define N 200100
using namespace std;

int endingfirst(pair<int,int> a,pair<int,int> b){
	return a.second < b.second;
}

bool startinglast(pair<int,int> a,pair<int,int> b){
	return a.first > b.first;
}

 int main(){
 	int n, m;
 	int l, r;
 	int time = 0;
 	pair<int,int> chess[N];
 	pair<int,int> comp[N];

 	cin >> n;
 	for(int i=0;i<n;i++){
 		cin >> l >> r;
 		chess[i] = pair<int,int>(l,r);
 	}
 	cin >> m;
 	for(int i=0;i<m;i++){
 		cin >> l >> r;
 		comp[i] = pair<int,int>(l,r);
 	}

 	sort(chess,chess+n,endingfirst);
 	sort(comp,comp+m,startinglast);
 	if(chess[0].second<comp[0].first){
 		time = max(comp[0].first-chess[0].second,0);
 	}

 	sort(chess,chess+n,startinglast);
 	sort(comp,comp+m,endingfirst);
 	
 	if(comp[0].second<chess[0].first){
 		time = max(chess[0].first-comp[0].second,time);	
 	}	
 	cout << time << "\n";
 	return 0;
 }	
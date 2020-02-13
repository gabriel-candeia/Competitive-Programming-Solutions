#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int x, y;
vector<int> arr;
vector<pair<int, int>> hor, vert;
ll h, v, intersection=0;

void merge(int l,int med,int r){
	int n1 = med+1, n2 = r+1;
	int i=l+0, j=med+1;
    vector<int> answ;
	while(i<n1 && j<n2){
		if(arr[i]<=arr[j]){
            answ.push_back(arr[i++]);
		}
		else{
            answ.push_back(arr[j++]);
			intersection += n1-i;
		}
	}
	while(i<n1){ answ.push_back(arr[i++]);}
	while(j<n2){ answ.push_back(arr[j++]);}
    j=0;
    for(i=l;i<r+1;i++){
        arr[i] = answ[j++];
    }
}

ll mergesort(int l, int r){
	if(l!=r){
    	int med =  l +(r-l)/2;
    	mergesort(l,med);
        mergesort(med+1,r);
        merge(l,med,r);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> x >> y;
	cin >> h >> v;

	for(int i=0;i<h;i++){
		cin >> x >> y;
        hor.push_back(make_pair(x,y));
	}
	for(int i=0;i<v;i++){
		cin >> x >> y;
        vert.push_back(make_pair(x,y));
	}
    sort(hor.begin(),hor.end());
    sort(vert.begin(),vert.end());

	for(int i=0;i<h;i++){arr.push_back(hor[i].second);}
	mergesort(0,h-1);
	
	for(int i=0;i<v;i++){arr.push_back(vert[i].second);}
	mergesort(h,h+v-1);

	cout << (h+1)*(v+1)+intersection << '\n';

	return 0;
}

#include<bits/stdc++.h>
#define N int(1e5)+3
#define ll long long int
using namespace std;

ll merge(int arr[],int L[],int l,int med,int r){
	int n1 = (med-l+1), n2 = (r-med);
	int i, j, top=0;
	ll acm = 0;
	for(i=0;i<n1;i++){
		L[i] = arr[l+i];
	}
	i=0;j=0;
	while(i<n1 && j<n2){
		if(L[i]<=arr[med+1+j]){
			arr[l+top] = L[i++];
			top++;
		}
		else{
			arr[l+top] = arr[med+1+j];
			j++;
			acm += n1-i;
			top++;
		}
	}
	while(i<n1){
		arr[l+top] = L[i++];
		top++;
	}
	while(j<n2){
		arr[l+top] = arr[med+1+j];
		j++;
		top++;
	}
	return acm;
}

ll mergesort(int arr[N],int l, int r,int L[]){
	if(l==r){ return 0;}
	int med =  l +(r-l)/2;
	return mergesort(arr,l,med,L)+mergesort(arr,med+1,r,L)+merge(arr,L,l,med,r);
}

int main(){
	int x, y;
	ll h, v, acm;
	pair<int, int> hor[N], vert[N];
	int arr[N], L[N];

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> x >> y;
	cin >> h >> v;

	for(int i=0;i<h;i++){
		cin >> hor[i].first >> hor[i].second;
	}
	for(int i=0;i<v;i++){
		cin >> vert[i].first >> vert[i].second;
	}

	acm = (h+1)*(v+1);
	sort(hor,hor+h);
	for(int i=0;i<h;i++){
		arr[i] = hor[i].second;
	}
	acm += mergesort(arr,0,h-1,L);

	sort(vert,vert+v);
	for(int i=0;i<v;i++){
		arr[i] = vert[i].second;
	}
	acm += mergesort(arr,0,v-1,L);
	cout << acm << '\n';

	return 0;
}

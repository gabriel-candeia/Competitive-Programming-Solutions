#include<bits/stdc++.h>
#define N 1000
#define M int(3e6)+3
using namespace std;
int arr[M];

int main(){
	int freq[N], nc, n, a, topo;
	for(int i=0;i<N;i++){ freq[i] = 0;}
	scanf("%d",&nc);
	while(nc--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a);
			freq[a]++;
		}
		topo = 0;
		for(int i=20;i<=230;i++){
			while(freq[i]){
				arr[topo++]=i;
				freq[i]--;
			}
		}
		printf("%d",arr[0]);
		for(int i=1;i<topo;i++){
			printf(" %d",arr[i]);
		}
	}
	return 0;
}

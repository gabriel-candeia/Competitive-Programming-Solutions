#include <bits/stdc++.h>

using namespace std;

#define maxn int(2e5+10)

int hor[maxn], ver[maxn];

int main(){
    int n, i, j;
    cin >> n;
    int ansh = 0, ansv = 0;
    for(int k = 0; k < n; k++){
        cin >> i >> j;
        ++hor[j]; //hor.emplace_back(j);
		ansh += 4;
		if(hor[j] != 1) ansh -= 2;
        if(j-1 >= 1 && hor[j-1] >= hor[j]) ansh -=2;
        if(j+1 <= int(2e5) && hor[j+1] >= hor[j]) ansh -= 2;  
		
        ++ver[i]; //ver.emplace_back(i);
		ansv += 4;
		if(ver[i] != 1) ansv -= 2;
        if(i-1 >= 1 && ver[i-1] >= ver[i]) ansv -= 2;
        if(i+1 <= int(2e5) && ver[i+1] >= ver[i]) ansv -= 2;

		cout << ansv << " " << ansh << "\n";
    }
    return 0;
}
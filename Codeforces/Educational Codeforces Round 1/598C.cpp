#include<iostream>
#define _USE_MATH_DEFINES
#include<cmath>
#define N int(1e5)+10

using namespace std;

int dot_product(pair<int,int> a, pair<int,int> b){
	return a.first*b.first + a.second*b.second;	
}

double lenght(pair<int,int> a){
	return sqrt(a.first*a.first + a.second*a.second);
}

double alpha(pair<int,int> a, pair<int,int> b){
	if(a.first==-b.first&&a.second==-b.second){
		return M_PI;
	}
	double cosalpha = dot_product(a,b)/(lenght(a)*lenght(b));
	cosalpha = acos(cosalpha);
	return min(cosalpha,2*M_PI-cosalpha);
}

int main(){
	pair<int,int> pares[N];
	int n, f, s;
	long double melhor=1000, temp;
	int a, b;

	cin >> n;
	for(int i=0;i<n;i++){
		cin >> f >> s;
		pares[i] = make_pair(f,s);
	}

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			temp = alpha(pares[i],pares[j]);
			if(temp<melhor){
				melhor= temp;
				a = i;
				b = j;
			}
		}
	}

	cout << a+1 << ' ' << b+1 << '\n';

	return 0;
}
#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>

using namespace std;

int main(){
	string en1, en2, en3, en4;
	string s1, s2;
	float a, b;
	double c, d;	
	char signA, signB, signD, signC;

	cin >> en1 >> en2;
	cin >> en3 >> en4;

	signA = (en1[0]!='-') ? '\0' : '-';
	signB = (en2[0]!='-') ? '\0' : '-';
	signC = (en3[0]!='-') ? '\0' : '-';
	signD = (en4[0]!='-') ? '\0' : '-';

	a = stof(en1);
	b = stof(en2);
	c = stod(en3);
	d = stod(en4);

	printf("A = %f, B = %f\n",a,b);
	printf("C = %lf, D = %lf\n",c,d);

	printf("A = %.1f, B = %.1f\n",a,b);
	printf("C = %.1lf, D = %.1lf\n",c,d);

	printf("A = %.2f, B = %.2f\n",a,b);
	printf("C = %.2lf, D = %.2lf\n",c,d);

	printf("A = %.3f, B = %.3f\n",a,b);
	printf("C = %.3lf, D = %.3lf\n",c,d);

	printf("A = %.3E, B = %.3E\n",a,b);
	printf("C = %.3E, D = %.3E\n",c,d);

	printf("A = %.f, B = %.f\n",a,b);
	printf("C = %.lf, D = %.lf\n",c,d);
}

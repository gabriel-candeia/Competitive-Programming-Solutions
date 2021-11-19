#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll a, b, c, d, zeros, ones;
    bool poss = true;

    cin >> a >> c >> b >> d;
    for(zeros=0;zeros*(zeros-1)<2*a;zeros++);
    for(ones=0;ones*(ones-1)<2*d;ones++);
    if(b || c) ones = max(ones,1ll), zeros = max(zeros,1ll);
    poss =  poss && (zeros*(zeros-1)==2*a) && (ones*(ones-1)==2*d) && (b+c == ones*zeros);
    if(a+b+c+d==0)
        cout << "0" << "\n";
    else if(!poss)
        cout << "Impossible" << "\n";
    else{
        /*string answ = string(ones,'1') + string(zeros,'0');
        for(int i=ones-1,iter=0;i>=0 && iter < c ;i--)
            for(int j=i;j< answ.size()-1 && answ[j+1]!='1' && iter < c;j++, iter++)
                swap(answ[j],answ[j+1]);*/
        string answ;
        if(zeros){
            answ = string(ones-c/zeros,'1') + string(zeros,'0') + string((c)/zeros,'1');
            if(c%zeros) swap(answ[ones-c/zeros-1],answ[ones-c/zeros-1+c%zeros]);
        }
        else{
            answ = string(ones,'1');
        }

        cout << answ << "\n";
    }

    return 0;
}
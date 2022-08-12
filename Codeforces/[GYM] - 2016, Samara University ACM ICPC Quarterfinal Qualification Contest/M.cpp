#include<bits/stdc++.h>
using namespace std;
int qtd = 0;
char query(int a, int b){
    assert(qtd<=1023);
    char answ;
    cout <<"?" << " " << a << " " << b << endl;
    cin >> answ;
    qtd++;
    return answ;
}

pair<int,int> combine(pair<int,int> a, pair<int,int> b, pair<int,int> c){
    char x = query(a.second,b.second);
    pair<int,int> answ;
    vector<int> v = {a.second,b.second,c.second};
    if(x=='<')
        swap(a,b);
    answ.second = a.second;
    if(a.first!=-1){
        x = query(a.first,b.second);
        if(x=='>')
            answ.first = a.first;
        else
            answ.first = b.second;
        }
    else{
        answ.first = b.second;
    }
    return answ;
}

pair<int,int> solve(int l, int r){
    if(l==r)
        return {-1,l};
    int med1 = l + (r-l)/3, med2 = r - (r-l)/3;
    auto p = combine(solve(l,med1),solve(med1+1,med2),solve(med2+1,r));
    //cout << l << " " << r <<" "<< p.first  << " " << p.second <<"\n";
    return p;
}

int main(){
    int n;

    cin >> n;
    int answ = solve(1,n).first;
    cout <<"! " << answ << endl;

    return 0;
}
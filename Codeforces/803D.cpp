#include<bits/stdc++.h>
using namespace std;

void parse(string& s){
    for(auto &y: s){
        if(y=='-'){
            y = ' ';
        }
    }
}

bool is_possible(string& s, int w,int k){
    int cnt=1, last=-1, size=1, n = s.size(), start=0;
    //cout << start << " ";
    for(int i=0;i<n;i++,size++){
        if(s[i]== ' '){
            last = i;
        }
        if(size==w && i!=n-1){
            if(last<start){
                return false;
            }
            else{
                
                start = last+1;
                size = max(i-start+1,0);
                cnt++;
                /*cout << start << ":";
                cout << i << ":";
                cout << size << " ";*/
            }
        }
    }
    //cout << (cnt<=k) << '\n';
    return (cnt<=k);
}

int main(){
    int k;
    string s;

    cin >> k;
    cin.ignore();
    getline(cin,s);
    parse(s);
    int l=1, r = s.size(), answ = s.size(), med;
    while(l<=r){ 
        med = l+ (r-l)/2;
        if(is_possible(s,med,k)){
            answ = med;
            r = med-1;
        }
        else{
            l = med+1;
        }
    }
    cout << answ << '\n';
    //cout << is_possible(s,10,k) << '\n';
    return 0;
}
/*
Edu-ca-
tion-al 
Ro-unds 
are so fun
*/
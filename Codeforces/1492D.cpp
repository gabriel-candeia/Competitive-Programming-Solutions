#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, k;
    bool poss = true;
    string s="1", t="1";

    cin >> a >> b >> k;

    if(k){
        if(b>=2 && a>0 && a+b-2>=k){
            int a1, b1 = b-2;

            a--;
            k--;
            b--;

            string x = string(min(k,a),'0');
            a1 = a-k;
            k -= a;
            a = max(a1,0);

            if(k>0){
                x += string(k,'1');
                b-=k;
                b1-=k;
            }
            
            t+=string(1,'0')+x +string(1,'1');
            s+=string(1,'1')+x+string(1,'0');
            
            s.pop_back();
            s.push_back('0');

            for(int i=0;i<b1;i++)
                s.push_back('1'), t.push_back('1');
            for(int i=0;i<a1;i++)
                s.push_back('0'), t.push_back('0');
        }
        else{
            poss = false;
        }
    }
    else{
        for(int i=0;i<b-1;i++)
            s.push_back('1'), t.push_back('1');
        for(int i=0;i<a-k;i++)
            s.push_back('0'), t.push_back('0');
    } 

    if(poss){
        cout << "Yes\n";
        cout << s << '\n';
        cout << t <<'\n';
    }
    else{
        cout << "No\n";
    }

    return 0;
}
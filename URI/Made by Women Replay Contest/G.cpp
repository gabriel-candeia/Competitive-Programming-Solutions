#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, book;
    while(cin >> n){
        map<int,bool> cnt;
        deque<int> dq;
        int answ=0;
        for(int i=0;i<n;i++){
            cin >> book;
            if(cnt[book]==0){
                if(dq.size()==4){
                    cnt[dq.back()] = 0;
                    dq.pop_back();
                } 
                dq.push_front(book);
                cnt[book] = 1;
                answ++;
            }
        }
        cout <<answ <<'\n';
    }
    return 0;
}
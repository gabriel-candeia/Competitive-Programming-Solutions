#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e17;

vector<ll> ultMaior(const vector<pair<ll,ll>>& arr){
    ll n = arr.size();
    vector<ll> lst(n,-1);

    for(ll i=0, j; i<n; i++){
        for(j=i-1;j>=0 && arr[j].second <= arr[i].second;j = lst[j]);
        lst[i] = j;
    }

    return lst;
}

double tempo(pair<ll,ll> a, pair<ll,ll> b){
    return (b.second-a.second)*1.0/(a.first-b.first); 
}

int main(){
    ll n;
    vector<pair<ll,ll>> arr;

    cin >> n;
    arr.assign(n,{0,0});
    for(auto &p:arr){
        cin >> p.first >> p.second;
    }
    
    sort(arr.rbegin(),arr.rend());
    auto lst = ultMaior(arr);

    vector<ll> answ(n,inf);
    vector<pair<ll,ll>> st;
    vector<ll> pos, ller;
    answ[0] = arr[0].first*arr[0].second;
    pos.push_back(0);
    ller.push_back(-inf);
    st.push_back({arr[0].first,0});
    
    for(ll i=1;i<n;i++){
        /*cout << i << ": ";
        for(ll i=0;i<st.size();i++){
            cout << st[i].first << " " << st[i].second << " "  << pos[i] << " " << ller[i] <<  "| ";
        }cout<<"\n";*/

        ll op1 = inf, op2 = inf;

        if(lst[i]!=-1)
            op1 = answ[lst[i]];

        ll inc = (lower_bound(pos.begin(),pos.end(),lst[i]+1) - pos.begin());
        
        if(pos.begin()+inc!=pos.end()){
            ll inc2 = upper_bound(ller.begin()+inc,ller.end(),arr[i].second)-ller.begin()-1;
            //cout <<"teste: "<< arr[i].second <<"  " << inc2 <<"\n";
            //inc2 = max(inc2,0);
            if(inc2>=inc && ller[inc2]<=arr[i].second){
                op2 = st[inc2].first*arr[i].second + st[inc2].second;
            }
        }
        
        ll op3 = arr[i].first*arr[i].second+answ[i-1];
        //cout << op1 << " " << op2 << " "<<op3 <<"\n";
        answ[i] = min({op1,op2,op3});
        //if(answ[i]==op1) continue;
        pair<ll,ll> novo = {arr[i].first,answ[i-1]};

        if(st.size()>=1 && novo.first==st.back().first){
            if(novo.second<st.back().second){
                st.pop_back();
                ller.pop_back();
                pos.pop_back();
            }
            else{
                continue;
            }
        }

        if(st.size()==0){
            ller.push_back(-inf);
            st.push_back(novo);
            pos.push_back(i);
        }
        else{
            while(st.size()>=2 && tempo(st[st.size()-2],st[st.size()-1])>=tempo(st[st.size()-2],novo)){
                ller.pop_back();
                st.pop_back();
                pos.pop_back();
            }
            ll temporario = tempo(st.back(),novo);
            ller.push_back(temporario);
            st.push_back(novo);
            pos.push_back(i);
        }
    }

    cout << answ[n-1] << "\n";

    return 0;
}
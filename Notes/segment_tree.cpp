#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    private:
        vector<int> st, A;
        int n;
        //o array será indexado a partir do 1
        int left(int i){return (2*i);}

        int right(int i){return (2*i)+1;}

        void build(int p, int L, int R){ // p é o nó [L,R] é o intervalo de p
            if(L==R){
                //st[p] = L; //answer range minimum queries
                st[p] = A[L]; //answer range sum queries
            }
            else{
                build(left(p),L,(L+R)/2);
                build(right(p),(L+R)/2+1,R);

                int p1 = st[left(p)], p2 = st[right(p)];

                st[p] = max(p1,p2); //answer range minimum queries
                //st[p] = p1+p2; //answer range sum queries
            }
        }

        int update(int p, int L, int R, int i){
            if(L==R){
                st[p] = A[L];
            }
            else{
                int M = (R+L)/2;
                if(i<=M){
                    update(left(p),L,M,i);
                }
                else{
                    update(right(p),M+1,R,i);
                }

                int p1 = st[left(p)], p2 = st[right(p)];

                st[p] = max(p1,p2);
                //st[p] = ((A[p1] <= A[p2]) ? p1 : p2); //answer range minimum queries
                //st[p] = p1+p2; //answer range sum queries
            }
        }

        // queremos o máximo do intervalor [i,j] do array A (que foi usado pra construir a arvore)
        int query(int p, int L, int R, int i, int j){
            if(i>R || j<L){
                return -1;
            }
            else if(L>=i && R<=j){
                return st[p];
            }
            else{
                int p1 = query(left(p),L,(L+R)/2,i,j);
                int p2 = query(right(p),(L+R)/2+1,R,i,j);

                if(p1==-1) return p2;
                if(p2==-1) return p1;

                return max(p1,p2);
                //return ((A[p1]<=A[p2]) ? p1 : p2); //answer range minimum queries
                //return p1+p2; //answer range sum queries
            }
        }

    public:
        SegmentTree(const vector<int>& _A){
            A = _A;
            n = A.size();
            st.assign(4*n,0);
            build(1,0,n-1);
        }

        int query(int i,int j){
            //return A[query(1,0,n-1,i,j)]; // rmq
            return query(1,0,n-1,i,j); // rsq
        }

        void update(int i, int k){
            A[i] = k;
            update(1, 0, n-1, i);
        }
};


int maior(vector<int>& arr, int i, int j){
    int mx = arr[i];
    for(i;i<=j;i++){
        mx = max(arr[i],mx);
    }
    return mx;
}

int main(){
    vector<int> arr = {10,2,47,3,7,9,1,98,21};
    int n = arr.size();
    SegmentTree t = SegmentTree(arr);

    cout << t.query(0,3) << '\n';

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
                cout << t.query(i,j) << ' ' << maior(arr,i,j) << '\n';
        }
    }

    return 0;
}

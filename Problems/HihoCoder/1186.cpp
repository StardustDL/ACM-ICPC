#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int p,q;
vector<int> P,Q;
inline void getD(int p,vector<int> &ans){
    int u=sqrt(p);
    ans.clear();
    for(int i=1;i<=u;i++){
        if(p%i==0){
            ans.push_back(i);
            int k=p/i;if(k!=i)ans.push_back(k);
        }
    }
    sort(ans.begin(),ans.end());
}
typedef vector<int>::iterator IT;
int main(){
    cin>>p>>q;
    getD(p,P);getD(q,Q);
    for(IT i=P.begin();i!=P.end();i++){
        for(IT j=Q.begin();j!=Q.end();j++){
            cout<<*i<<" "<<*j<<endl;
        }
    }
    return 0;
}
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const long long MOD=19999997;
struct matrix{
    long long a[2][2];
    void init(){
        a[0][0]=a[0][1]=a[1][0]=a[1][1]=0;
    }
    void I(){
        init();
        a[0][0]=a[1][1]=1;
    }
};
matrix mul(matrix &a,matrix &b){
    matrix c;c.init();
    for(int k=0;k<2;k++){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++)
                (c.a[k][i]+=a.a[k][j]*b.a[j][i]%MOD)%=MOD;
        }
    }
    return c;
}
matrix qpow(matrix a,int n){
    matrix ans,tmp;ans.I();
    while(n){
        if(n&1)
            ans=mul(a,ans);
        a=mul(a,a);
        n>>=1;
    }
    return ans;
}
int main(){
    int n;cin>>n;
    matrix base;base.init();base.a[0][1]=base.a[1][1]=base.a[1][0]=1;
    // base.out();
    matrix e=qpow(base,n);
    //e.out();
    cout<<e.a[1][1]%MOD<<endl;
    return 0;
}
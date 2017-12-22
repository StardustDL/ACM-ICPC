/*
[Noi2012]随机数生成器
分析：给X0,计算Xn，Xn+1=(a*Xn+c)mod m 
		快速幂优化矩阵乘+快速加防爆longlong 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL; 
LL n,m,a,c,g,x0;
LL mulply(LL x,LL y){
    LL z=0;
    while(y){
    	if(y&1)(z+=x)%=m;
    	(x+=x)%=m;
    	y>>=1;
    }
    return z;
}
struct matrix{
    LL d[3][3];
	matrix(){memset(d,0,sizeof(d));}
    matrix friend operator *(matrix &a,matrix &b){
        matrix c;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    (c.d[i][j]+=mulply(a.d[i][k],b.d[k][j]))%=m;
                }
            }
        }
        return c;
    }
}f,t;
void qpow(matrix x,LL n,matrix &out){
	for(int i=0;i<2;i++)out.d[i][i]=1;
    while(n){
        if(n&1)out=out*x;
        x=x*x;
        n>>=1;
    }
}
int main(){
    scanf("%lld%lld%lld%lld%lld%lld",&m,&a,&c,&x0,&n,&g);
    t.d[0][0]=a;t.d[0][1]=0;t.d[1][0]=c;t.d[1][1]=1;
    qpow(t,n,f);
    printf("%lld",((mulply(x0,f.d[0][0])+f.d[1][0])%m)%g);
    return 0;
}

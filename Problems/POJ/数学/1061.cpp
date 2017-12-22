/*

���⣺���������ڳ������Ծ���߻�·����ʼλ�÷ֱ�Ϊx��y��ÿ����Ծ����ֱ�Ϊm��n���������ΪL����������Ծ�����������ͬ������£����������Ƿ��з�����Ծ��ͬһ�㡣���������Ծ������
��������չŷ����¡�������������s�����з��̣�(x+n*s)-(y+m*s)=k*L������ã�(n-m)*s+L*(-k)=y-x
	  ��ʱ�����Ѿ�������չŷ����µ���ʽ:a*x+b*y=gcd(a,b)�ˡ���Ҫ����⼴�ɡ�
	  ���㷨ͬ�����������a*x+b*y=c����ʽ�ķ��̡������������a*x+b*y=gcd(a,b)��Ȼ������ͬʱ����gcd(a,b)�ٳ���c���������ԭ���̵Ľ⡣��a*(x*c/g)+b*(y*c/g)=c���÷����н��������c�ܱ�gcd(a,b)������
	  ����֪��һ�´�������ġ� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
typedef long long LL;
LL x,y,m,n,l;
LL gcd(LL a,LL b){
	return a%b==0?b:gcd(b,a%b); 
}
void extendGcd(LL a,LL b,LL &d,LL &x,LL &y){
	if(!b){d=a;x=1;y=0;}
	else{extendGcd(b,a%b,d,x,y);y-=x*(a/b);} 
}
LL solve(LL a,LL b,LL n){
	LL x,y,d;
	if(n%gcd(a,b)!=0)return -1;
	extendGcd(a,b,d,x,y);
	int t=(n*x/d+b/d)%(b/d);//����b/d����֤��������ȡģ 
	return t;
}
int main(){
	scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
	if(m<n)swap(m,n),swap(x,y);
	LL ans=solve(m-n,l,(y-x+l)%l);
	if(ans==-1)printf("Impossible\n");
	else printf("%lld\n",ans); 
	return 0;
}
/*
AC
__int64 exgcd(__int64 a,__int64 b,__int64 &x,__int64 &y){
    __int64 r,t;
    if(b==0){x=1;y=0;return a;}
    r=exgcd(b,a%b,x,y);t=x;x=y; y=t-a/b*y;
    return r;
}
int main(){
    __int64 x,y,m,n,l,xx,yy,d,r;
    scanf("%I64d%I64d%I64d%I64d%I64d",&x,&y,&m,&n,&l);
    d=exgcd(n-m,l,xx,yy);
    if((x-y)%d!=0) printf("Impossible\n");
    else{
		xx=xx*((x-y)/d);
		r=l/d;
		xx=(xx%r+r)%r;//�����С�Ǹ�������
		printf("%I64d\n",xx);
	}
    return 0;
}
*/

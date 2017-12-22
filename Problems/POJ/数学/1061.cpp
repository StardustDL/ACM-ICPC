/*

题意：两个青蛙在赤道上跳跃，走环路。起始位置分别为x，y。每次跳跃距离分别为m，n。赤道长度为L。两青蛙跳跃方向与次数相同的情况下，问两青蛙是否有方法跳跃到同一点。输出最少跳跃次数。
分析：扩展欧几里德。设两青蛙跳了s步。有方程：(x+n*s)-(y+m*s)=k*L。整理得：(n-m)*s+L*(-k)=y-x
	  此时方程已经符合扩展欧几里德的形式:a*x+b*y=gcd(a,b)了。按要求求解即可。
	  该算法同样可用于求解a*x+b*y=c的形式的方程。方法是先求解a*x+b*y=gcd(a,b)。然后两端同时除以gcd(a,b)再乘以c即可整理出原方程的解。即a*(x*c/g)+b*(y*c/g)=c。该方程有解的条件是c能被gcd(a,b)整除。
	  但不知道一下代码错在哪。 
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
	int t=(n*x/d+b/d)%(b/d);//加上b/d，保证是正整数取模 
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
		xx=(xx%r+r)%r;//求出最小非负整数解
		printf("%I64d\n",xx);
	}
    return 0;
}
*/

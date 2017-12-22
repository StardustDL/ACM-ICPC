/*
[HAOI2008]圆上的整点
分析：一道数学题：
	  x^2+y^2=r^2
	=>y=sqrt((r+x)(r-x)) 
	=>d=gcd(r+x,r-x),A=(r+x)/d,B=(r-x)/d
	=>y^2=d^2*A*B
	=>∵A!=B
	=>A=a*a,B=b*b
	=>a^2+b^2=2*R/d
	则要求d|2*R
	=>枚举d
	=>枚举a
	=>求出b=sqrt(2*R/d-a^2)，A=a*a,B=b*b
	=>check: gcd(A,B)==1&&A!=B ? ans++:___ 
	=>得到第一象限的解（不含坐标轴）
	=>ans=ans*4+4 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long LL;
const int MAXN=1000,INF=0x3f3f3f3f;
LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}
bool check(LL x,double y){
	if(y==floor(y)){
		LL y1=(LL)floor(y);
		if(gcd(x*x,y1*y1)==1&&x!=y1)return true; 
	}
	return false;
}
LL r,ans=0; 
int main(){
	cin>>r;
	for(LL d=1,mx=(LL)sqrt(2*r);d<=mx;d++){
		if(2*r%d!=0)continue;
		for(LL a=1,p=(LL)sqrt(r/d);a<=p;a++){//2*a^2<2*r/d
			double b=sqrt(2*r/d-a*a);
			ans+=check(a,b); 
		} 
		if(d==2*r/d)continue;
		for(LL a=1,p=(LL)sqrt(d/2);a<=p;a++){//2*a^2<d
			double b=sqrt(d-a*a);
			ans+=check(a,b);
		}
	}
	cout<<(ans+1LL)*4LL<<endl;
	return 0;
}


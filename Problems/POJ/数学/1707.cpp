/*
Sum of powers
题意：令自然数幂和为S(k,n)=1^k+2^k+...+n^k，S(k,n)可以表述成：
		S(k,n)=1/M*(a[k+1]*n^(k+1)+a[k]*n^k+...+a[1]*n+a[0])
  		给出k，求最小的正整数M，使得a[0]...a[k+1]都为整数。1 <= k <=20
分析：伯努利数
 		S(k,n)=1/(k+1) * ( C(k+1,k)*B[k]*(n+1)^1 + C(k+1,k-1)*B[k-1]*(n+1)^2 + ... + C(k+1,0)*B[0]*(n+1)^(k+1) )
 	  又因为：
 		S(k,n)=S(k,n-1) + n^k
          =1/(k+1) * ( C(k+1,k)*B[k]*n^1 + C(k+1,k-1)*B[k-1]*n^2 + ... + C(k+1,0)*B[0]*n^(k+1) ) + n^k
 		求一下a[0]...a[k+1]分母的最小公倍数，然后化简即可。
		注意最后加了一项n^k 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=20,INF=0x3f3f3f3f;
typedef long long LL;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
LL lcm(LL a,LL b){return a/gcd(a,b)*b;}
struct Q{
	LL s,f;
	Q(){s=0,f=1;}
	void simply(){
		if(s==0)f=1;
		else {
			if(f<0)f=-f,s=-s;
			LL g=gcd(s,f);
			s/=g,f/=g;
		}
	}
	void set(LL a,LL b){s=a,f=b;simply();}
	Q operator +(const Q &t)const{
		Q ans;
		ans.f=lcm(f,t.f);
		ans.s=s*(ans.f/f)+t.s*(ans.f/t.f);
		ans.simply();
		return ans;
	}
	Q operator *(const LL t)const{
		Q ans=*this;
		ans.s*=t;
		ans.simply();
		return ans;
	}
};
Q B[MAXN+3];
LL C[MAXN+3][MAXN+3];
void initC(int n){
	n++;
	for(int i=0;i<=n;i++)C[i][0]=C[i][i]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<n;j++)C[i][j]=C[i-1][j]+C[i-1][j-1];
}
void initB(int n){
	B[0].set(1,1);
	Q s[2];
	for(int m=1;m<=n;m++){
		s[0].set(1,1);//cal the i=0
		for(int i=1;i<m;i++){
			s[1].set(C[m+1][i]*B[i].s,B[i].f);
			s[0]=s[0]+s[1];
		}
		B[m].set(-s[0].s,s[0].f*C[m+1][m]);
	}
}
LL ans[MAXN+3];
Q f[MAXN+3];
void solve(int m){
	for(int i=0;i<=m;i++)f[i]=B[i]*C[m+1][i];
	LL l=f[0].f;
	for(int i=1;i<=m;i++)l=lcm(l,f[i].f);
	if(l<0)l=-l;
	for(int i=0;i<=m;i++)ans[i+1]=f[i].s*l/f[i].f;
	ans[2]+=l*(m+1);
	ans[0]=l*(m+1);
}
inline void output(int m){for(int i=0;i<=m+1;i++)printf("%lld ",ans[i]);puts("0");}
int m;
int main(){
	initC(20);initB(20); 
	scanf("%d",&m);
	solve(m);
	output(m);
	return 0;
}


/*

*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
namespace Matrix {
	struct matrix {
		int n,m,d[50][50];
		matrix operator *(const matrix &t)const {
			matrix ans;
			ans.n=n;
			ans.m=t.m;
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=t.m; j++) {
					for(int k=1; k<=m; k++) {
						ans.d[i][j]+=d[i][k]*t.d[k][j];
					}
				}
			}
			return ans;
		}
	};
}
namespace Quick_Mod {
	int quick_pow(int a,int n,int mod) {
		int ans=1;
		while(n) {
			if(n&1)(ans*=a)%=mod;
			(a*=a)%=mod;
			n>>=1;
		}
		return ans;
	}
	int quick_plus(int a,int n,int mod) {
		int ans=0;
		while(n) {
			if(n&1)(ans+=a)%=mod;
			(a+=a)%=mod;
			n>>=1;
		}
		return ans;
	}
}
typedef int arr[MAXN+3][MAXN+3];
namespace PrifixSum {
	int oneD[MAXN+3],twoD[MAXN+3][MAXN+3];
	void pre_1D(int *a,int n) {
		oneD[0]=0;
		for(int i=1; i<=n; i++)oneD[i]=a[i]+oneD[i-1];
	}
	int getsum_1D(int l,int r) {
		return oneD[r]-oneD[l-1];
	}
	void pre_2D(arr a,int n,int m) {
		memset(twoD,0,sizeof(twoD));
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				twoD[i][j]=twoD[i][j-1]+twoD[i-1][j]-twoD[i-1][j-1]+a[i][j];
			}
		}
	}
	int getsum_2D(int l,int r,int x,int y) {
		return twoD[x][y]-twoD[x][r-1]-twoD[l-1][y]+twoD[l-1][r-1];
	}
}
namespace Gauss {
	double D[MAXN+3][MAXN+3],dans[MAXN+3];
	void solve_double(int n) {
		for(int i=1; i<n; i++) {
			int r=i;
			for(int j=i+1; j<=n; j++)if(fabs(D[j][i])>fabs(D[r][i]))r=j;
			if(r!=i)for(int j=1; j<=n+1; j++)swap(D[r][j],D[i][j]);
			for(int j=i+1; j<=n; j++) {
				double t=D[j][i]/D[i][i];
				for(int k=i+1; k<=n+1; k++) {
					D[j][k]-=D[i][k]*t;
				}
			}
		}
		for(int i=n; i>=1; i--) {
			double sum=0;
			for(int j=n; j>i; j--)sum+=D[i][j]*dans[j];
			dans[i]=(D[i][n+1]-sum)/D[i][i];
		}
	}
	int I[MAXN+3][MAXN+3],ians[MAXN+3];
	void solve_int(int n){
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(j==i)continue;
				int a=I[i][i],b=I[j][i];
				while(b) {
					int t=a/b;
					a%=b;
					swap(a,b);
					for(int k=i; k<=n; k++)
						I[i][k]-=t*I[j][k];
					for(int k=i; k<=n; k++)swap(I[i][k],I[j][k]);
				}
			}
		}
		for(int i=1;i<=n;i++)ians[i]=I[i][i];
	}
}
namespace NumberTheroy {
	vector<int> pris;
	int mindiv[MAXN+3];
	void get_primes(int UP) {
		pris.clear();
		memset(mindiv,0,sizeof(mindiv));
		for(int i=2; i<=UP; i++) {
			if(mindiv[i]==0) {
				mindiv[i]=i;
				pris.push_back(i);
			}
			for(int j=0; j<pris.size(); j++) {
				int k=i*pris[j];
				if(k>UP)break;
				mindiv[k]=pris[j];
				if(i%pris[j]==0)break;
			}
		}
	}
	int phi[MAXN+3];
	void calc_phi(int UP) {
		pris.clear();
		memset(mindiv,0,sizeof(mindiv));
		for(int i=2; i<=UP; i++) {
			if(mindiv[i]==0) {
				mindiv[i]=i;
				pris.push_back(i);
				phi[i]=i-1;
			}
			for(int j=0; j<pris.size(); j++) {
				int k=i*pris[j];
				if(k>UP)break;
				mindiv[k]=pris[j];
				if(i%pris[j]==0) {
					phi[k]=phi[i]*(pris[j]);
					break;
				} else phi[k]=phi[i]*(pris[j]-1);
			}
		}
	}
	typedef long long LL;
	LL gcd(LL a,LL b) {
		return b?gcd(b,a%b):a;
	}
	LL exgcd(LL a,LL b,LL &x,LL &y) {
		if(b==0) {
			x=1;
			y=0;
			return a;
		}
		LL d=exgcd(b,a%b,x,y);
		int t=x;
		x=y;
		y=t-(a/b)*y;
		return d;
	}
	LL get_inv(LL a,LL mod) {
		LL x,y;
		LL d=exgcd(a,mod,x,y);//ax+ymod=1
		return d==1?(x+mod)%mod:-1;
	}
	LL q_pow(LL a,LL b,LL c) {
		LL ans=1;
		while(b) {
			if(b&1)(ans*=a)%=c;
			(a*=a)%=c;
			b>>=1;
		}
		return ans;
	}
	LL solve(LL A,LL B,LL C) { //A^x=B(modC)
		static map<LL,LL> mp;
		mp.clear();
		LL m=ceil(sqrt((double)C));
		LL v=get_inv(q_pow(A,m,C),C),e=1;
		mp[1]=0;
		for(LL i=1; i<m; i++) {
			e=(e*A)%C;
			if(!mp.count(e))mp[e]=i;
		}
		for(LL i=0; i<m; i++) {
			if(mp.count(B))return i*m+mp[B];
			B=(B*v)%C;
		}
		return -1;
	}
	//x=a[i](mod m[i]) 0<=i<n
	LL china(int n,int *a,int *m) {
		LL M=1,d,y,x=0;
		for(int i=0; i<n; i++)M*=m[i];
		for(int i=0; i<n; i++) {
			LL w=M/m[i];
			exgcd(m[i],w,d,y);//y=get_inv(w,m[i]);
			x=(x+y*w*a[i])%M;
		}
		return (x+M)%M;
	}
	LL calc_phi(LL n) {
		LL m=ceil(sqrt((double)n));
		LL ans=n;
		for(int i=2; i<=m; i++) {
			if(n%i)continue;
			ans=ans/i*(i-1);
			while(n%i==0)n/=i;
		}
		if(n>1)ans=ans/n*(n-1);
	}
	void get_sub_primes(LL x,vector<pair<int,int> > &ans){
		int m=sqrt(x)+1;
		for(int i=2;i<=m;i++){
			if(x%i)continue;
			int t=0;
			while(x%i==0)x/=i,t++;
			ans.push_back(make_pair(i,t));
		}
		if(x>1){
			ans.push_back(make_pair(x,1));
		}
	}
}
namespace FFT{
	const int MAXN=300000;
	struct complex{
		double a,b;
		complex(double a=0,double b=0):a(a),b(b){}
		complex operator +(const complex &t)const{
			return complex(a+t.a,b+t.b);
		}
		complex operator -(const complex &t)const{
			return complex(a-t.a,b-t.b);
		}
		complex operator *(const complex &t)const{
			return complex(a*t.a-b*t.b,b*t.a+a*t.b);
		}
	};
	complex w[MAXN+3],A[MAXN+3],B[MAXN+3];
	int rev[MAXN+3],bit;
	int getrev(int x){
		int ans=0;
		for(int i=0;i<bit;i++){
			(ans<<=1)|=(x&1);
			x>>=1;
		}
		return ans;
	}
	const double PI=acos(-1);
	void FFT(complex *F,int bit,int op){
		for(int i=0;i<(1<<bit);i++)if(rev[i]>i)swap(F[i],F[rev[i]]);
		for(int i=1;i<=bit;i++){
			for(int j=0;j<(1<<bit);j+=(1<<i)){
				int pos=0;
				for(int k=j;k<j+(1<<i-1);k++){
					complex t=w[pos]*F[k+(1<<i-1)];
					F[k]=F[k]+t;
					F[k+(1<<i-1)]=(F[k]-t)-t;
					pos+=op*(1<<bit-i);
					if(pos<0)pos+=(1<<bit); 
				}
			}
		}
	}
	void solve(int n,double *a,double *b,double *ans){
		int len=n<<1;bit=0;
		while(1<<bit <= len)bit++;
		w[0].a=1;w[1]=complex(cos(2.0*PI/(1<<bit)),sin(2.0*PI/(1<<bit)));
		for(int i=2;i<(1<<bit);i++)w[i]=w[i-1]*w[1];
		for(int i=0;i<(1<<bit);i++)rev[i]=getrev(i);
		for(int i=1;i<=n;i++){
			A[i].a=a[i],A[i].b=0;
			B[i].a=b[i],B[i].b=0;
		}
		FFT(A,bit,1);
		FFT(B,bit,1);
		for(int i=0;i<(1<<bit);i++)A[i]=A[i]*B[i];
		FFT(A,bit,-1);
		for(int i=0;i<(1<<bit);i++)A[i].a/=(1<<bit);
		for(int i=0;i<=len;i++)ans[i]=A[i].a;
	}
}
namespace Simpson{
	double (*F)(double x);
	double simpson(double a,double b){
		double c=a+(b-a)/2;
		return (F(a)+4*F(c)+F(b))*(b-a)/6;
	}
	double asr(double a,double b,double eps,double A){
		double c=a+(b-a)/2;
		double l=simpson(a,c),r=simpson(c,b);
		if(fabs(l+r-A)<=15*eps)return l+r+(l+r-A)/15.0;
		return asr(a,c,eps/2,l)+asr(c,b,eps/2,r);
	}
	double asr(double a,double b,double eps,double (*f)(double x)){
		F=f;
		return asr(a,b,eps,simpson(a,b));
	}
}
double trichotomy(double l,double r,double (*f)(double t)){
	while(l+1e-8<=r){
		double ml=l+(r-l)/3.0,mr=r-(r-l)/3.0;
		if(f(ml)<f(mr))r=mr;
		else l=ml;
	}
	return l;
}
int main() {

	return 0;
}


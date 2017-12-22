/*
钉子和小球
分析：题意很好懂，
	  首先从最上面的点开始考虑，因为球一定是从最上面开始往下掉，
	  所以球经过最上面的点的概率是1，然后他会有1/2的几率向左，1/2的几率向右，也就是下面的两个点均分上面点的几率。
	  当然这是所有的点都存在的情况。如果有哪里的点不存在了，那么球落到这个点的几率不变，
	  然后它的所有几率都会加在在它下面两行且在正下方的点。
	  注意开longlong和分数计算 
*/
#include<iostream>
using namespace std;
const int MAXN=50; 
typedef long long LL;
LL gcd(LL a,LL b){return a%b==0?b:gcd(b,a%b);}
LL lcm(LL a,LL b){return a/gcd(a,b)*b;}
struct fs{
	LL s,f;
	fs(){s=0,f=1;}
	fs(int a,int b){s=a,f=b;}
	
	void output(){cout<<s<<"/"<<f;}
	void clear(){LL t=gcd(s,f);s/=t;f/=t;}
	fs operator += (const fs &t){
		LL e=lcm(f,t.f);
		s=s*(e/f)+t.s*(e/t.f);f=e;clear();
		return *this;
	}
	fs operator *(const fs &t){
		fs r;r.s=t.s*s;r.f=t.f*f;r.clear();
		return r;
	}
}opt[MAXN+3][MAXN+3];
const fs half=fs(1,2);
int n,m;
bool a[MAXN+7][MAXN+7];
void input(){
	cin>>n>>m;
	char c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>c;
			if(c=='*')a[i][j]=1;
			else a[i][j]=0;
		}
	}
	//for(int i=1;i<=n;i++){for(int j=1;j<=i;j++)cout<<a[i][j];cout<<endl;}
}
fs dp(){
	opt[1][1]=fs(1,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(a[i][j]){
				opt[i+1][j]+=opt[i][j]*half;
				opt[i+1][j+1]+=opt[i][j]*half;
			}
			else opt[i+2][j+1]+=opt[i][j];
		}
	}
	//for(int i=1;i<=n;i++){for(int j=1;j<=i;j++)opt[i][j].output();cout<<endl;}
	return opt[n+1][m+1];
}
int main(){
	input();
	dp().output();
	return 0;
}

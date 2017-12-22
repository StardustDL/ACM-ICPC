/*
FFT快速傅立叶
分析：转成多项式直接做，注意最后进位处理 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=60000*3,INF=0x3f3f3f3f;
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
		return complex(a*t.a-b*t.b,a*t.b+b*t.a);
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
double PI=acos(-1);
void FFT(complex *F,int bit,int op){
	for(int i=0;i<(1<<bit);i++)if(rev[i]>i)swap(F[i],F[rev[i]]);
	for(int i=1;i<=bit;i++){
		for(int j=0;j<(1<<bit);j+=(1<<i)){
			int pos=0;
			for(int k=j;k<j+(1<<i-1);k++){
				F[k]=F[k]+w[pos]*F[k+(1<<i-1)];
				F[k+(1<<i-1)]=(F[k]-w[pos]*F[k+(1<<i-1)])-w[pos]*F[k+(1<<i-1)];
				pos+=op*(1<<bit-i);
				if(pos<0)pos+=(1<<bit);
			}
		}
	}
}
int n,ans[MAXN+3],len;
char ch[60000+3];
int main(){
	scanf("%d",&n);n--;len=2*n;
    scanf("%s",ch);
	for(int i=0;i<=n;i++)A[i].a=ch[n-i]-'0';
	scanf("%s",ch);
	for(int i=0;i<=n;i++)B[i].a=ch[n-i]-'0';
	while(1<<bit <= len)bit++;
	w[0].a=1;
	w[1]=complex(cos(2.0*PI/(1<<bit)),sin(2.0*PI/(1<<bit)));
	for(int i=2;i<(1<<bit);i++)w[i]=w[i-1]*w[1];
	for(int i=0;i<(1<<bit);i++)rev[i]=getrev(i);
	FFT(A,bit,1);
	FFT(B,bit,1);
	for(int i=0;i<(1<<bit);i++)A[i]=A[i]*B[i];
	FFT(A,bit,-1);
	for(int i=0;i<(1<<bit);i++)A[i].a/=(1<<bit);
	for(int i=0;i<=len;i++)ans[i]=(int)(A[i].a+0.1);//int 是下取整，+0.1 
	for(int i=0;i<=len;i++)
		if(ans[i]>=10){
			ans[i+1]+=ans[i]/10,ans[i]%=10;
			if(i==len)len++;
		}
	for(int i=len;i>=0;i--)printf("%d",ans[i]);
	puts("");
	return 0;
}


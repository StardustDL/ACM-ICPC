/*
[HNOI2007]�λõ�����
���������ǵ�ÿ��weight����д��a*2^b����ʽ����Ȼ����Ҫ����b�ֲ������б���
	  ��ô��f[i][j]�洢��i��ı��� ����f[i][j]��ʾ��j*2^i�Ŀռ�ʱ��ֻʹ������Ϊa*2^i����Ʒ������ֵ
	  ���������������ת�ƣ����¶���״̬����f[i][j]��ʾ��j*2^i+(w&(1<<i)-1)�Ŀռ�ʱ������ֵ����������W���Ӳ� 
	  ö�ٵ�ǰ�����¶��ٿռ����һ�㣬���������һ�����k����ô��һ���״̬����[2*k+(w��i-1λ�Ƿ�Ϊ1)] 
	  ����ת�ƣ�f[i][j]=max(f[i][j-k]+f[i-1][k*2+(w>>(i-1)&1)]) 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100,INF=0x3f3f3f3f;
typedef long long LL;
const LL UP=MAXN*10;
int n; 
LL f[33][UP+3],ans=0,W;
int main(){
	while(scanf("%d%lld",&n,&W)){
		if(n==-1&&W==-1)break;
		memset(f,0,sizeof(f));
		ans=0;
		for(int w,v,i=1;i<=n;i++){
			scanf("%d%d",&w,&v);
			int b=0;while(!(w&1))++b,w>>=1;
			for(int j=UP;j>=w;j--)f[b][j]=max(f[b][j],f[b][j-w]+v);
		}
		ans=f[0][UP];
		for(int i=1;i<=30&&(1LL<<i)<=W;i++){
			for(int j=min(W>>i,UP);~j;j--){
				for(int k=0;k<=j;k++)f[i][j]=max(f[i][j],f[i][j-k]+f[i-1][min(k*2+((W>>i-1)&1),UP)]);
				ans=max(ans,f[i][j]);
			}
		}
		printf("%lld\n",ans); 
	}
	return 0;
}


/*
[ZJOI2007]棋盘制作
分析：可以先对棋盘01染色，将所有染1的位置的原值取反，转成全0或全1子矩形
	  或直接在全0子矩阵上加一个判断=>异或，因为已经保证了小区间的可行性，只要新区间两段点异或满足条件即可 
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
#define sqr(x) ((x)*(x))
const int MAXN=2000,INF=0x3f3f3f3f;
bool mp[MAXN+3][MAXN+3];
int l[MAXN+3],r[MAXN+3],d[MAXN+3],n,m,ans1=0,ans2=0;
void work(bool K){
	int k;
	memset(d,0,sizeof(d)); 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			l[j]=r[j]=j;
			if(mp[i][j]==K)d[j]++;
			else d[j]=0;
		}
		for(int j=1;j<=m;j++)if(d[j])while(d[l[j]-1]>=d[j])l[j]=l[l[j]-1];
		for(int j=m;j>=1;j--)if(d[j])while(d[r[j]+1]>=d[j])r[j]=r[r[j]+1];
		for(int j=1;j<=m;j++){
			k=r[j]-l[j]+1;
			ans1=max(ans1,sqr(min(k,d[j])));
			ans2=max(ans2,k*d[j]);
		}
	}
}
int main(){
	int t;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&t);
			if(((i+j)&1)==0)mp[i][j]=!t;
			else mp[i][j]=t;
		}
	work(0);
	work(1);
	printf("%d\n%d",ans1,ans2);
	return 0;
}
/*
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 2000+50;
int map[N];
int b[N];
int l[N],r[N];
int main(){
	int n,m;
	int maxj=1,maxz=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1,t;j<=m;j++){
			scanf("%d",&t);
			if(t!=map[j] || i==1)b[j]++;else b[j]=1;
			map[j]=t;
			l[j]=j;
			while(l[j]-1 >=1 && b[j] <= b[l[j]-1] && (map[j]^map[ l[j]-1 ]^(l[j]-1-j)^1)&1){
				l[j]=l[ l[j]-1 ];
			}
		}
		for(int j=m;j>=1;j--){
			r[j]=j;
			while(r[j]+1<=m && b[j] <= b[ r[j]+1 ] && (map[j]^map[ r[j]+1 ]^(r[j]+1-j)^1)&1){
				r[j]=r[ r[j]+1 ];
			}
			maxj=max( maxj,b[j]*(r[j]-l[j]+1) );
			maxz=max( maxz,min(b[j],r[j]-l[j]+1) * min(b[j],r[j]-l[j]+1) );
		}
	}
	printf("%d\n%d\n",maxz,maxj);
	return 0;
}
*/ 

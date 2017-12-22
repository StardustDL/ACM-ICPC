/*
[Usaco2005 nov]Grazing on the Run 边跑边吃草
分析：容易证明任何时刻吃掉的草都是一个区间。
		因此令f[i,j,k]表示已经吃掉了以i开头的j坨草，当前在左端点/右端点的最小腐败值之和(包括被吃掉的和未被吃掉的，当然被吃掉的腐败值就不会再涨了) 
		容易想到的是f[l][r][0..1]表示区间被吃完，然后在左右，但是直接这样空间会爆，而上面的，先枚举区间长度，这样可以滚动数组 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=3000,INF=0x3f3f3f3f;
int opt[MAXN+3][2][2];
int n,p,a[MAXN+3];
int main(){
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	a[++n]=p;
	sort(a+1,a+n+1);
	p=lower_bound(a+1,a+n+1,p)-a;
	memset(opt,INF,sizeof(opt));
	opt[p][1][0]=opt[p][1][1]=0;
	for(int len=2;len<=n;len++){
		for(int i=1;i<=n;i++)opt[i][len&1][0]=opt[i][len&1][1]=INF;
		for(int l=max(p-len+1,1);l<=min(p,n-len+1);l++){//必须要跨越p 
			int r=l+len-1;
			if(l!=p)//l在p时只能在右端点 
                opt[l][len&1][0]=min(opt[l+1][~len&1][0]+(n-len+1)*abs(a[l]-a[l+1]),opt[l+1][~len&1][1]+(n-len+1)*abs(a[l]-a[r]));
            if(r!=p)//r在p时只能在左端点 
                opt[l][len&1][1]=min(opt[l][~len&1][0]+(n-len+1)*abs(a[l]-a[r]),opt[l][~len&1][1]+(n-len+1)*abs(a[r-1]-a[r]));
        }
    }
    printf("%d",min(opt[1][n&1][0],opt[1][n&1][1]));
	return 0;
}


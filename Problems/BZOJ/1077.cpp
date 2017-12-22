/*
[SCOI2008]天平
分析：一道差分约束好题。 
	  首先通过差分约束系统建图，用Floyed算法求出任意两个砝码差值的上下界。
	  然后暴力枚举放在右边的砝码C,D，通过与A,B差值的上下界分类讨论统计方案。
	  注意mn是下界，mx是上界，由差分约束的特点，d[i][j]为i->j的最短路，则意味着A[j]-A[i]=d[i][j]，最后枚举的时候不要搞反了 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=50,INF=0x3f3f3f3f;
int mn[MAXN+3][MAXN+3],mx[MAXN+3][MAXN+3];
int n,A,B,c1,c2,c3;
char s[MAXN+3][MAXN+3];
int main(){
	scanf("%d%d%d",&n,&A,&B);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	//求两点最小差值，权值是-1 ，因为后面是取min，这样不会被mn[i][0]=mn[n+1][i]=0的条件限制 
	for(int i=0;i<=n+1;i++)for(int j=0;j<=n+1;j++)if(i!=j)mn[i][j]=INF;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s[i][j]=='-')//i<=j-1,i-j<=-1 j->i w=-1
				mn[j][i]=-1;
			else if(s[i][j]=='=')mn[i][j]=0; //后面也会枚举到s[j][i] 
		}
	}
	for(int i=1;i<=n;i++)mn[i][0]=mn[n+1][i]=0;
	mn[0][n+1]=2,mn[n+1][0]=-2;//规定最大差值
	for(int k=0;k<=n+1;k++)
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=n+1;j++)
				mn[i][j]=min(mn[i][j],mn[i][k]+mn[k][j]);
	//求两点最大差值，权值是1 ，因为后面是取max ，这样不会被mx[0][i]=mx[i][n+1]=0的条件限制 
	for(int i=0;i<=n+1;i++)for(int j=0;j<=n+1;j++)if(i!=j)mx[i][j]=-INF;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s[i][j]=='-')//i<=j-1,i-j<=-1 i->j w=1
				mx[i][j]=1;
			else if(s[i][j]=='=')mx[i][j]=0; 
		}
	}
	for(int i=1;i<=n;i++)mx[0][i]=mx[i][n+1]=0;
	mx[0][n+1]=2,mx[n+1][0]=-2;//规定最大差值
	for(int k=0;k<=n+1;k++)
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=n+1;j++)
				mx[i][j]=max(mx[i][j],mx[i][k]+mx[k][j]);
		
	for(int C=1;C<=n;C++){
		if(C==A || C==B)continue;
		for(int D=1;D<C;D++){//D<C防止重复计数 
			if(D==A || D==B)continue;
			if(mx[C][A]>mn[B][D]||mx[D][A]>mn[B][C])c1++;
    		if((mx[C][A]==mn[C][A]&&mx[B][D]==mn[B][D]&&mx[C][A]==mx[B][D])||
    		   (mx[D][A]==mn[D][A]&&mx[B][C]==mn[B][C]&&mx[D][A]==mx[B][C]))c2++;
    		if(mn[C][A]<mx[B][D]||mn[D][A]<mx[B][C])c3++;
			/*if(mx[A][C]>mn[D][B] || mx[A][D]>mn[C][B])c1++;
			if((mn[A][C]==mx[A][C]&&mn[D][B]==mx[D][B]&&mn[A][C]==mn[D][B])
				||(mn[A][D]==mx[A][D]&&mn[C][B]==mx[C][B]&&mn[A][D]==mn[C][B]))c2++;
			if(mx[D][B]>mn[A][C] || mx[C][B]>mn[A][D])c3++;*/
			/*if(mn[A][C]>mx[D][B] || mn[A][D]>mx[C][B])c1++;
			if((mn[A][C]==mx[A][C]&&mn[B][D]==mx[B][D]&&mn[A][C]==mn[B][D])
				||(mn[A][D]==mx[A][D]&&mn[B][C]==mx[B][C]&&mn[A][D]==mn[B][C]))c2++;
			if(mn[D][B]>mx[A][C] || mn[C][B]>mx[A][D])c3++;*/
		}
	}
	printf("%d %d %d\n",c1,c2,c3);
	return 0;
}


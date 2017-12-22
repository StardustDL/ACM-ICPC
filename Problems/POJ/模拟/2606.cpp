/*
Rabbit hunt
题意：给若干个点求含最多点的直线含点数
分析：暴力，用叉积判，先枚举原点，然后二重循环扫一遍 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=200;
struct point{
	int x,y;
	point(int x,int y):x(x),y(y){}
	point(){}
	point operator -(const point &t)const{return point(x-t.x,y-t.y);}
};
int Cross(const point &a,const point &b){return a.x*b.y-a.y*b.x;}
int n,ans=0;
point ps[MAXN+3];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&ps[i].x,&ps[i].y);
	for(int i=1;i<n;i++){
		int t=0,e;
		for(int j=1;j<=n;j++){
			if(j==i)continue;
			e=1;
			for(int k=j+1;k<=n;k++){
				//if(k==j)continue;
				if(Cross(ps[j]-ps[i],ps[k]-ps[i])==0)e++;
			}
			t=max(t,e);
		}
		ans=max(ans,t);
	}
	printf("%d",ans); 
	return 0;
}


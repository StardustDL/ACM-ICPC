/*
Linearity
题意：给若干个点求含最多点的直线含点数
分析：用叉积超时了，改用斜率的方法（解析几何） 
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
int cmp(double a,double b){return a>b;}
struct point{int x,y;}node[MAXN+3];
double k[MAXN+3];
int main(){
    int n,a,b,ans,p,t;
    while(~scanf("%d",&n)){
        ans=0;
        for(int i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            node[i].x=a,node[i].y=b;p=0;
            for(int j=0;j<i;j++,p++){
                if(a==node[j].x)k[p]=INF;
                else k[p]=(double)(b-node[j].y)/(a-node[j].x);
            }
            sort(k,k+p,cmp);
            for(int j=0;j<p;j++){
                int count=1;
                while(j+1<p&&k[j]==k[j+1]){count++;j++;}
                ans=max(ans,count);
            }
        }
        printf("%d\n",ans+1);
    }
    return 0;
}
/*
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
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
	while(scanf("%d",&n)){
		ans=0;
		for(int i=1;i<=n;i++)scanf("%d%d",&ps[i].x,&ps[i].y);
		for(int i=1;i<n;i++){
			int t=0,e;
			for(int j=1;j<=n;j++){
				//if(j==i)continue;
				e=1;
				for(int k=j+1;k<=n;k++){
					//if(k==j)continue;
					if(Cross(ps[j]-ps[i],ps[k]-ps[i])==0)e++;
				}
				t=max(t,e);
			}
			ans=max(ans,t);
		}
		printf("%d\n",ans+1);
	}
	return 0;
}*/

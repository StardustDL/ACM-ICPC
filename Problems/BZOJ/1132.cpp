/*
分析：枚举每一个点，计算以这个点为坐标原点，在第一象限的所有点与原点组成的三角形的面积和。计算面积可以用叉积
	  利用叉积的性质，设原点为O，枚举到的两个点为AB，向量OA = (x1,y1),向量OB = (x2,y2)，则
	  S-OAB = |x1 * y2 - y2 * x2|
	  按照极角或者斜率排序一下，就可以去掉绝对值 
	  对于固定的一个点A来说，线段OA与其他所有点的面积和就是ΣS = x1 * Σy2 - y1 * Σx2
*/
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
const int MAXN=3000; 
using namespace std;
struct Point{
    long long x,y;
}now,p[MAXN+3],tp[MAXN+3];
inline long long xmul(Point B,Point C,Point A=now){return (C.y-A.y)*(B.x-A.x)-(B.y-A.y)*(C.x-A.x);}
bool cmpxy(Point A,Point B){return A.x==B.x?A.y<B.y:A.x<B.x;}
bool cmpmu(Point A,Point B){return xmul(A,B)>0;}
int n;
long long ans;
long long sumx[MAXN+3],sumy[MAXN+3];
int main(){
    scanf("%d",&n);sumx[n+1]=sumy[n+1]=0;
    for(int i=1;i<=n;i++)scanf("%lld%lld",&p[i].x,&p[i].y);
    sort(p+1,p+n+1,cmpxy);//先按坐标排一遍序 
    for(int i=1;i<=n-2;i++){
		now=p[i];
        for(int j=i+1;j<=n;j++)tp[j]=p[j];
		sort(tp+i+1,tp+n+1,cmpmu);
        for(int j=n;j>i;j--){
            sumx[j]=sumx[j+1]+tp[j].x-now.x;
            sumy[j]=sumy[j+1]+tp[j].y-now.y;
        }
        for(int j=i+1;j<n;j++){
            ans+=(tp[j].x-now.x)*sumy[j+1]-(tp[j].y-now.y)*sumx[j+1];//和其后的点构成三角形（防止重复） 
        }
    }
    if(ans&1)printf("%lld.5\n",ans>>1);//讨论精度 
    else printf("%lld.0\n",ans>>1);
    return 0;
}

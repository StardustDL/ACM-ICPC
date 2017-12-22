/*
������ö��ÿһ���㣬�����������Ϊ����ԭ�㣬�ڵ�һ���޵����е���ԭ����ɵ������ε�����͡�������������ò��
	  ���ò�������ʣ���ԭ��ΪO��ö�ٵ���������ΪAB������OA = (x1,y1),����OB = (x2,y2)����
	  S-OAB = |x1 * y2 - y2 * x2|
	  ���ռ��ǻ���б������һ�£��Ϳ���ȥ������ֵ 
	  ���ڹ̶���һ����A��˵���߶�OA���������е������;��Ǧ�S = x1 * ��y2 - y1 * ��x2
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
    sort(p+1,p+n+1,cmpxy);//�Ȱ�������һ���� 
    for(int i=1;i<=n-2;i++){
		now=p[i];
        for(int j=i+1;j<=n;j++)tp[j]=p[j];
		sort(tp+i+1,tp+n+1,cmpmu);
        for(int j=n;j>i;j--){
            sumx[j]=sumx[j+1]+tp[j].x-now.x;
            sumy[j]=sumy[j+1]+tp[j].y-now.y;
        }
        for(int j=i+1;j<n;j++){
            ans+=(tp[j].x-now.x)*sumy[j+1]-(tp[j].y-now.y)*sumx[j+1];//�����ĵ㹹�������Σ���ֹ�ظ��� 
        }
    }
    if(ans&1)printf("%lld.5\n",ans>>1);//���۾��� 
    else printf("%lld.0\n",ans>>1);
    return 0;
}

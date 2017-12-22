/*
[Tjoi 2013]����ۻ�
����������ת�����������⣬���ǿ��Եõ�d(i,j)=max(|xi-xj|,|yi-yj|)��
		��x��=(x+y)/2,y��=(x-y)/2
		��ôd(i,j)=|xi��-xj��|+|yi��-yj��|
		x��y����Էֿ�ͳ��
		����ͳ��x�ᣬ�����������x������
		��ǰ׺�ͺͺ�׺�����ĳ���������������X�����
		Xi*(i-1)-sum(1..i-1)+sum(i+1..n)-(n-i)*Xi
		y��ͬ��
*/ 
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=100000;
struct point{
	LL x,y;int tox;
}ps[MAXN+3];
LL xsuml[MAXN+3],xsumr[MAXN+3];
LL ysuml[MAXN+3],ysumr[MAXN+3];
bool cmpx(point a,point b){
	return a.x<b.x;
}
bool cmpy(point a,point b){
	return a.y<b.y;
}
int n;
LL ans=1LL<<60;
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		ps[i].x=x+y,ps[i].y=x-y;
	}
	sort(ps+1,ps+n+1,cmpx);
	for(int i=1;i<=n;i++){xsuml[i]=xsuml[i-1]+ps[i].x;ps[i].tox=i;}
	for(int i=n;i>=1;i--)xsumr[i]=xsumr[i+1]+ps[i].x;
	sort(ps+1,ps+n+1,cmpy);
	for(int i=1;i<=n;i++)ysuml[i]=ysuml[i-1]+ps[i].y;
	for(int i=n;i>=1;i--)ysumr[i]=ysumr[i+1]+ps[i].y;
	for(int i=1;i<=n;i++){
		LL tmp=0;
		tmp+=ps[i].y*(i-1)-ysuml[i-1]+ysumr[i+1]-ps[i].y*(n-i);
		int l=ps[i].tox;tmp+=ps[i].x*(l-1)-xsuml[l-1]+xsumr[l+1]-ps[i].x*(n-l);
		ans=min(ans,tmp);
	}
	printf("%lld\n",ans>>1);
	return 0;
}


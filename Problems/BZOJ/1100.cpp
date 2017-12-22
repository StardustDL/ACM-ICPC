/*
[POI2007]�Գ���osi
����������˼����Ŀ�����㼸�ε�ζ�����Ũ�����ȴ�õ����ַ����㷨�������
	  ������һ��������ж������Գ��ᣬ���ǿ��԰Ѷ���α�ʾ��һ���ɱ߳��ͽǶ���ɵ����У������������
	  ������� i �� j ��һ���Գ���Ļ�����ô��������ָ�ɵ���������������Ӧ����һ�����Ĵ������巽��������
	  ����һ������Ϊ 2n �����У���һ���Ǳ߳����ڶ����ǽǶȣ��������Ǳ߳����������ơ��ǵõ��������Ϊ S��
	  ���Ǹ��� S �õ� SS���� S �ķ���Ϊ S������ԭ����ͱ���� S���� SS �г����˶��ٴΣ���������� kmp �����ע��
	  ����ǶȻ�Ҿ��ȵĻ�����ֱ���ò�������棬��Ϊ����߳����ȵĻ��϶��Ͳ����ˣ�����߳���ȵĻ������
	  �ȣ���˵���˽ǶȲ��ȡ�
	  ������һ����Ҳ����ֱ����manacher������ʵ����û��������ֺ�д
	  ע��ÿ���Գ������������㣬����/2 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define sqr(x) ((x)*(x))
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
struct data{
	bool isp;int val;
	bool operator ==(const data &d)const{
		return isp==d.isp&&val==d.val;
	}
}ds[2*2*MAXN+3];
int x[MAXN+3],y[MAXN+3],n,p[2*2*MAXN+3];
int dist(int i,int j){
	return sqr(x[i]-x[j])+sqr(y[i]-y[j]);
}
int cross(int i,int j,int k){
	return (x[j]-x[i])*(y[k]-y[i])-(x[k]-x[i])*(y[j]-y[i]);
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d%d",&x[i],&y[i]);
		for(int i=0;i<n;i++){
			ds[i<<1|1].isp=1;
			ds[i<<1|1].val=dist(i,(i+1)%n);
		}
		for(int i=0;i<n;i++){
			ds[i<<1].isp=0;
			ds[i<<1].val=cross(i,(i-1+n)%n,(i+1)%n);
		}
		int len=n<<1;
		for(int i=0;i<len;i++)ds[i+len]=ds[i];
		len<<=1;
		int mx=0,id=0;memset(p,0,sizeof(p));
		for(int i=0;i<len;i++){
			if(mx>i)p[i]=min(mx-i,p[2*id-i]);
			for(;i-p[i]>=0&&i+p[i]<len&&ds[i-p[i]]==ds[i+p[i]];p[i]++);
			if(i+p[i]>mx)mx=i+p[i],id=i;
		}
		int ans=0;
		for(int i=0;i<len;i++)if(p[i]-1>=n)ans++;//p[i]-1���ų��Լ��Ļ��İ뾶 
		printf("%d\n",ans>>1);
	}
	return 0;
}

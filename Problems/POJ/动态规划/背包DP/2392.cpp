/*
Space Elevator
���⣺��һȺţҪ��̫��,���Ǽƻ���һ��̫����(��һЩʯͷ��),������k�ֲ�ͬ���͵�ʯͷ,ÿһ��ʯͷ�ĸ߶�Ϊh,����Ϊc,���ڻ��ܵ�̫�շ���,ÿһ��ʯͷ���ܳ�������ʯͷ�������߶�a,���������Щʯͷ�����޽���̫���ݵ���ߵĸ߶�.
�������ȶ����߶���������Ȼ��ͱ�ɶ��ر����������жϣ�����ȫ����+�����ɽ� 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=400,MAXH=40000,INF=0x3f3f3f3f;
struct thing{
	int n,h,mxh;
	bool operator <(const thing &t)const{
		return mxh<t.mxh;
	}
	void input(){scanf("%d%d%d",&h,&mxh,&n);}
}ds[MAXN+3];
bool can[MAXH+3];
int n,cnt[MAXH+3],ans=0; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)ds[i].input();
	sort(ds+1,ds+n+1);
	can[0]=1;
	for(int i=1;i<=n;i++){
		memset(cnt,0,sizeof(cnt));
		for(int j=ds[i].h;j<=ds[i].mxh;j++)//ע��Ҫ�ж�!can[j]��������֤cnt[j]��С������� 
			if(!can[j]&&can[j-ds[i].h]&&cnt[j-ds[i].h]<ds[i].n)can[j]=1,cnt[j]=cnt[j-ds[i].h]+1;
	} 
	for(int i=ds[n].mxh;i>=0&&ans==0;i--)if(can[i])ans=i;
	printf("%d",ans);
	return 0;
}


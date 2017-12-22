/*
[HEOI2012]�ɻ�
����������1878��������ķ��� 
	  �Ƚ�ÿ�ֵڶ������ֵļӽ�ȥ��ÿ��ֻά����һ��-1������һ��+1
	  ��������ɲ�������չ������3���ģ��ȼӽ�ȥ���������ֵģ�����ͬ�� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define lowbit(x) (x&-x)
using namespace std;
int n,c,m;
int a[1000005],next[1000005],t[1000005],p[1000005],ans[1000005];
struct data{int l,r,id;}q[1000005];
bool cmp(data a,data b){return a.l<b.l;}
void update(int x,int v){
	for(int i=x;i<=n;i+=lowbit(i))t[i]+=v;
}
int ask(int x){
	int tmp=0;
	for(int i=x;i>0;i-=lowbit(i))tmp+=t[i];
	return tmp;
}
int main(){
	scanf("%d%d%d",&n,&c,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]); 
	for(int i=n;i>0;i--)
	    next[i]=p[a[i]],p[a[i]]=i;
	for(int i=1;i<=c;i++)
		if(next[p[i]])update(next[p[i]],1);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&q[i].l,&q[i].r);
	    q[i].id=i;
	}
	sort(q+1,q+m+1,cmp);
	for(int i=1,l=1;i<=m;i++){
		while(l<q[i].l){
			if(next[l])update(next[l],-1);
			if(next[next[l]])update(next[next[l]],1);
			l++;
		}
		ans[q[i].id]=ask(q[i].r)-ask(q[i].l-1);
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}

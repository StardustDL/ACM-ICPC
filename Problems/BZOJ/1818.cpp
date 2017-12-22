/*
[Cqoi2010]�ڲ��׵�
����������֤�������ܳ������-1�����������ʵ�ڵ������ֻ�ᷢ���ڵ�һ�룩
		����׵�i�ڵ�һ��ʱ����ĳ��������Ϊ�Ϸ���û�кڵ㣬��û�б�ɺڵ㣬���ں����ֳ�Ϊ�˺ڵ㡣
		��ʱ��i���Ϸ������˺ڵ�j����jҪ��Ϊ�ڵ㣬j���Ϸ��ش���һ���ڵ㣬���Ǹ��ڵ�ͬʱҲ��i���Ϸ���
		����iһ��ʼ����Ϊ�ڵ㣬ì�ܣ�
	  ��ô����ֻ������ж��ٸ����������������Ҷ����ںڵ㡣
		��ɢ��+��״����
		x,y����ֱ�����ɨһ�飬�ҳ����еĺ��ߺ����ߣ�ͳ�Ƴ����ߡ������϶˵㡢�����¶˵㡣
		��ͳ�Ƴ������ݽ������򣬹ؼ���Ϊy����yֵ��ͬʱ���϶˵������ں����������¶˵㡣
		������������ɨ�裬ɨ������ʱͳ�ƺ������Ҷ˵��ڣ������䣩������������ɨ�������¶˵�ʱ��������+1��ɨ���϶˵�ʱ��������-1���ϱߵ����ȼ����ȷ������
		�������û��ͳ��ԭ�ȴ��ڵĺڵ㣬�ټ��ϼ��ɡ�
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100000;
struct point{
	int x,y;
}a[MAXN+3];
struct line{
	int l,r,y,k;//k=0 ����,k=1 �����¶˵�,k=-1 �����϶˵� 
}s[MAXN*3+3];
int hash[MAXN+3],c[MAXN+3],n,cnt,ans;
inline int gethash(int x){
	return lower_bound(hash+1,hash+1+n,x)-hash;
}
bool cmp1(point a,point b){//����ͳ�� 
	return a.y<b.y || a.y==b.y&&a.x<b.x;
}
bool cmp2(point a,point b){//����ͳ�� 
	return a.x<b.x || a.x==b.x&&a.y<b.y;
}
bool cmp3(line a,line b){
	return a.y<b.y || a.y==b.y&&a.k<b.k;
}
void pre(){
	sort(a+1,a+1+n,cmp1);
	for(int i=2;i<=n;i++)
		if(a[i].y==a[i-1].y){
			s[++cnt].l=gethash(a[i-1].x);
			s[cnt].r=gethash(a[i].x);
			s[cnt].y=a[i].y;
			s[cnt].k=0;
		}
	sort(a+1,a+1+n,cmp2);
	for(int i=2;i<=n;i++)
		if(a[i].x==a[i-1].x){
			int tmp=gethash(a[i].x);
			s[++cnt].y=a[i-1].y;
			s[cnt].l=tmp;
			s[cnt].k=1;
			s[++cnt].y=a[i].y;
			s[cnt].l=tmp;
			s[cnt].k=-1;
		}
}
#define lowbit(x) (x&-x) 
void add(int x,int v){
	for(;x<=n;x+=lowbit(x))c[x]+=v;
}
int sum(int x){
	int ret=0;
	for(;x>0;x-=lowbit(x))ret+=c[x];
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		hash[i]=a[i].x;
	}
	sort(hash+1,hash+1+n);
	pre();
	sort(s+1,s+1+cnt,cmp3);
	for(int i=1;i<=cnt;i++)
		if(s[i].k)add(s[i].l,s[i].k);
		else ans+=sum(s[i].r-1)-sum(s[i].l);//ȥ�����˵�Ĳ��� 
	printf("%d\n",ans+n);
	return 0;
}

/*
[Usaco2008 Open]Cow Neighborhoods ��ţ���ھ�
������һ���ǳ�����ķ����������پ��룺
	  ���ԭ��������(x, y)�����µ�����Ϊ(X, Y), ����X = x + y, Y = x - y
	  ��ô�������پ��� = |x1 - x2| + |y1 - y2| = max(|X1 - X2|, |Y1 - Y2|)
	  ���������Ƚ�������任����X����
	  Ȼ����һ�����������������βX - ����X < c��
	  �����������ÿ�����Yά��һ��ƽ����������¼���Ԫ�ص�ǰ�����������Yֵ��ֵ������c�����ò��鼯����������һ��
	  ����ʵ��������kruskal�ĸĽ��汾��
	  ʹ����STL��multiset
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
typedef long long LL;
const int MAXN=100000;
const LL INF=1LL<<56;
struct point{
	LL x,y;int p;
	bool operator <(const point &p)const{
		return y<p.y;
	}
	point(){}
	point(LL x,LL y,int p):x(x),y(y),p(p){}
}ps[MAXN+3];
set<point>::iterator it;
int n,c,pa[MAXN+3],cur,cnt[MAXN+3],ans;
multiset<point> S;
bool cmp(const point &a,const point &b){
	return a.x<b.x;
}
int find(int x){
	return pa[x]==x?x:pa[x]=find(pa[x]);
}
void unite(int a,int b){
	if(find(a)!=find(b)){
		pa[find(a)]=find(b);
		ans--;
	}
}
int main(){
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)pa[i]=i;
	for(int i=1,a,b;i<=n;i++){
		scanf("%d%d",&a,&b);
		ps[i].x=a+b,ps[i].y=a-b;ps[i].p=i;
	}
	ans=n;
	sort(ps+1,ps+n+1,cmp);
	S.insert(point(0,-INF,0));
	S.insert(point(0,INF,0));
	S.insert(ps[1]);
	cur=1;
	point l,r;
	for(int i=2;i<=n;i++){
		while(ps[i].x-ps[cur].x>c){
			S.erase(S.find(ps[cur++]));
		}
		//cout<<ps[i].p<<" "<<i<<endl;
		it=S.lower_bound(ps[i]);
		r=*it;l=*--it;
		if(ps[i].y-l.y<=c)unite(ps[i].p,l.p);
		if(r.y-ps[i].y<=c)unite(ps[i].p,r.p);
		S.insert(ps[i]);
	}
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++)++cnt[find(i)];
	printf("%d %d\n",ans,*max_element(cnt+1,cnt+n+1));
	return 0;
}


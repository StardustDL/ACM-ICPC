/*
Parity game
���⣺һ����0,1��ɵ����ִ�~~����������һ���ˣ���iλ����jλ��1�ĸ���Ϊ��������ż����һ��������㼸������������Ҫ���ж�ǰk������˻ش�Ķ�����ȷ�ģ�����k+1�飬�����˵���Ǵ�ģ�Ҫ��������k��Ҫ������˻ش�Ķ�����ȷ�ģ����������
������������������ģ���΢ת��һ�¡�[l,r]��1���������Ա�ʾΪsum[r]-sum[l-1]������ĿֻҪ������ż��Ҳ��ȷ����sum[r]��sum[l-1]��ż�Ƿ���ͬ
		Ȩֵ���鼯��д��Ҫע�⣬����Ҫ��ɢ�� 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5000,INF=0x3f3f3f3f;
struct uniset{
	int fa[2*MAXN+3];
	bool v[2*MAXN+3];
	void init(int n){for(int i=1;i<=n;i++)fa[i]=i,v[i]=0;}
	int find(int x){
		if(fa[x]!=x){
			int p=fa[x];
			fa[x]=find(fa[x]);
			v[x]=v[x]^v[p];
		}
		return fa[x];
	}
	bool same(int a,int b){return find(a)==find(b);}
	void unions(int a,int b,int d){//d=0��ʾ����������ͬ��1��ʾ��ͬ 
		int pa=find(a),pb=find(b);
		if(pa!=pb)fa[pa]=pb,v[pa]=v[a]^v[b]^d;
	}
}S;
char temp[5];
struct query{
	int u,v;bool d;
	void input(){
		scanf("%d %d %s",&u,&v,temp);getchar();
		d=temp[0]=='o';u--;
	}
}qs[MAXN+3];
int n,q,a[2*MAXN+3],cnt=0,ans=0;
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++)
		qs[i].input(),a[++cnt]=qs[i].u,a[++cnt]=qs[i].v;
	sort(a+1,a+cnt+1);cnt=unique(a+1,a+cnt+1)-a;
	S.init(cnt);
	for(int i=1;i<=q;i++){
		int u=lower_bound(a+1,a+cnt+1,qs[i].u)-a,v=lower_bound(a+1,a+cnt+1,qs[i].v)-a;
		if(S.same(u,v)&&S.v[u]^S.v[v]^qs[i].d)break; 
		else S.unions(u,v,qs[i].d);
		ans++;
	}
	printf("%d",ans);
	return 0;
}


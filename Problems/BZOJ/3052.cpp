/*
[wc2013]�ǹ���԰
���������޸�����Ī��
	  1.�����ֿ飺
	  	���֣�һ������ͨ��״���ķֿ飬����dfs�򰴱�����˳��������һ�����ӽ�㣬����block֮���¿顣�����ӵĻ���ֳ��ϸ�block�Ŀ������֦Ҷ�ϲ���block�Ŀ顣�������ڵĿ������ϵ�λ�ò�һ��������
		��һ�ַ�����bzoj1086�ķֿ鷽ʽ����Ŀ�Ѿ�˵�ú�����ˡ��ֿ�Ľ���ǿ��Էֳ�[block,3*block]�Ŀ顣��Щ���ڵĽ����ܲ�����ͨ�����������������ǿ��Խ�ͨ��һ������������ͨ�� �����ӷֿ�Ļ���֤���ڵĿ������ϵ�λ���ǰ��ŵġ� 
	  2. ���û���޸ģ�����B = sqrt(n)������ѯ��(v, u)������v��u���ڿ�ı������v���ڿ�ı��Ϊ��һ�ؼ��֣�u���ڿ�ı��Ϊ�ڶ��ؼ����Ÿ���Ȼ���Ī���㷨����˳��ɨѯ�ʣ���������һ����������O(n * sqrt(n))����n��q��ͬ�׵ģ�
	  3.���������޸ģ�����ʱ����һά�ȣ�
	  	��ɣ�(v, u, ti)��ti��ѯ��ʱ��ʱ�䣬�����ѯ���ǵڼ��β�����
		Ȼ��v���ڿ�ı��Ϊ��һ�ؼ��֣�u���ڿ�ı��Ϊ�ڶ��ؼ��֣�tiΪ�����ؼ��֡�
		Ȼ���Ī���㷨����˳��ɨѯ�ʣ���������һ����ʱ����ʱ��ǰ��ʱ������������B = n ^ (2 / 3)����ʱ�临�Ӷ���O(n ^ (5 / 3))����n��q��ͬ�׵ģ� 
	  4.������δ�һ��(v,u,ti)ת�Ƶ�(v',u',t')
	  5.��ת��t��Ԥ���������ÿ���޸� �����޸�ǰӦ��ʲô��ɫ�������Ϳ��Գ����޸��ˡ�
	  	�ı�ķ�ʽ���������㱻ͳ�Ƶ������ˣ���ô���ų����޸ģ�����ͳ�Ƶ����С����û�У���ֱ�Ӹ�
	  6.ת�ƽڵ㣺
	  	��S(v, u)���� v��u��·���ϵĽ��ļ��ϡ���root���������㣬��lca(v, u)������v��u������������ȡ�
		��ôS(v, u) = S(root, v) xor S(root, u) xor lca(v, u)
		����xor�Ǽ��ϵĶԳƲ����˵���ǽڵ��������������
		�����ʲô����= = ���Ȳ�����lca����Ϊ������һ���㣬���Ե�������
		����T(v, u) = S(root, v) xor S(root, u)
		�۲콫curV�ƶ���targetVǰ��T(curV, curU)�仯��
		T(curV, curU) = S(root, curV) xor S(root, curU)
		T(targetV, curU) = S(root, targetV) xor S(root, curU)
		ȡ�ԳƲ
		T(curV, curU) xor T(targetV, curU)= (S(root, curV) xor S(root, curU)) xor (S(root, targetV) xor S(root, curU))
		���ڶԳƲ�Ľ����ɡ�����ɣ�
		T(curV, curU) xor T(targetV, curU)= S(root, curV) xor S(root, targetV)
		����ͬʱxor T(curV, curU)��
		T(targetV, curU)= T(curV, curU) xor S(root, curV) xor S(root, targetV)
		��������������T(curV, targetV)
		T(targetV, curU)= T(curV, curU) xor T(curV, targetV)
		��ʵ���Ƕ�curV��targetV·��(����lca(curV, targetV))�ϵĽ�㣬�����ǵĴ�����ȡ�����ɡ�
		��������Ҫ��һ����������ȡ���Ĳ�����reverse�� 
	  7.��������������������ʵ��ת���ˣ�����ת�Ƹ��Ӷ�����ά�������پ��룬��Ī�Ӹ�һ�¾ͺ��� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath> 
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
typedef long long LL;
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
LL ans,res[MAXN+3];
int bin[21];
int n,m,Q,cnt;
int blo,blonum;
LL V[MAXN+3],W[MAXN+3],C[MAXN+3],pre[MAXN+3];
int pa[MAXN+3][17];
int q[MAXN+3],top,dep[MAXN+3],belong[MAXN+3],dfn[MAXN+3],tme;
int num[MAXN+3];
bool vis[MAXN+3];
struct edge{int to,next;}e[MAXN*2+3];
int last[MAXN+3];
struct query{int x,y,t,id;}qs[MAXN+3];
struct change{int x,y,t,pre;}cs[MAXN+3];
bool operator <(query a,query b){
	if(belong[a.x]==belong[b.x]&&belong[a.y]==belong[b.y])return a.t<b.t;
	else if(belong[a.x]==belong[b.x])return belong[a.y]<belong[b.y];
	else return belong[a.x]<belong[b.x];
}
void addedge(int u,int v){
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}
int dfs(int u,int fa){
	int sz=0;dfn[u]=++tme;
	pa[u][0]=fa;dep[u]=dep[fa]+1;
	for(int i=1;i<17;i++)if(dep[u]>=bin[i])pa[u][i]=pa[pa[u][i-1]][i-1];else break;
	for(int i=last[u];i;i=e[i].next){
		if(e[i].to==fa)continue;
		sz+=dfs(e[i].to,u);
		if(sz>=blo){
			blonum++;
			for(int j=1;j<=sz;j++)belong[q[top--]]=blonum;
			sz=0;
		}
	}
	q[++top]=u;
	return sz+1;
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	int t=dep[x]-dep[y];
	for(int i=0;t>=bin[i];i++)if(bin[i]&t)x=pa[x][i];
	for(int i=16;i>=0;i--)if(pa[x][i]!=pa[y][i])x=pa[x][i],y=pa[y][i];
	return x==y?x:pa[x][0];
}
void reverse(int x){
	if(vis[x])ans-=W[num[C[x]]]*V[C[x]],num[C[x]]--;
	else num[C[x]]++,ans+=W[num[C[x]]]*V[C[x]];
	vis[x]^=1;
}
void change(int x,int val){
	if(vis[x]){reverse(x);C[x]=val;reverse(x);}
	else C[x]=val;
}
void moveto(int x,int y){
	while(x!=y){
		if(dep[x]>dep[y])reverse(x),x=pa[x][0];
		else reverse(y),y=pa[y][0];
	}
}
int main(){
	bin[0]=1;for(int i=1;i<20;i++)bin[i]=bin[i-1]<<1;
	n=read();m=read();Q=read();blo=pow(n,2.0/3)*0.5;
	for(int i=1;i<=m;i++)V[i]=read();
	for(int i=1;i<=n;i++)W[i]=read();
	for(int i=1;i<n;i++)addedge(read(),read());
	for(int i=1;i<=n;i++)pre[i]=C[i]=read();
	dfs(1,0);
	while(top)belong[q[top--]]=blonum;
	int c1=0,c2=0;
	for(int i=1,type,x,y;i<=Q;i++){
		type=read(),x=read(),y=read();
		if(!type){//change
			c1++;
			cs[c1].x=x,cs[c1].y=y,cs[c1].pre=pre[x];pre[x]=y;
		}
		else{//query
			c2++;
			if(dfn[x]>dfn[y])swap(x,y);
			qs[c2].x=x;qs[c2].y=y;qs[c2].id=c2;qs[c2].t=c1;
		}
	}
	sort(qs+1,qs+c2+1);ans=0;
	for(int i=1;i<=qs[1].t;i++)change(cs[i].x,cs[i].y);
	
	moveto(qs[1].x,qs[1].y);
	int t=lca(qs[1].x,qs[1].y);
	reverse(t);res[qs[1].id]=ans;reverse(t);
	for(int i=2;i<=c2;i++){
		for(int j=qs[i-1].t+1;j<=qs[i].t;j++)change(cs[j].x,cs[j].y);
		for(int j=qs[i-1].t;j>qs[i].t;j--)change(cs[j].x,cs[j].pre);
		moveto(qs[i-1].x,qs[i].x);
		moveto(qs[i-1].y,qs[i].y);
		int t=lca(qs[i].x,qs[i].y);
		reverse(t);res[qs[i].id]=ans;reverse(t);
	}
	for(int i=1;i<=c2;i++)printf("%lld\n",res[i]);
	return 0;
}


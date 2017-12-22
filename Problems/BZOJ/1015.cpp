/*
[JSOI2008]星球大战starwar
分析：逆向做，并查集，注意很多细节处理，错了好几回，要维护当前存在的点 
*/
#include<cstdio>
#include<bitset>
#include<cstring>
using namespace std;
const int N=500000,M=500000;
int key[M+3],head[N+3],next[M+3],a[N+3],p[N+3],ans[N+3],n,m,k,cnt;
bitset<N+3> v; 
inline void add (const int &x, const int &y){
    key[cnt]=y;next[cnt]=head[x];head[x]=cnt++;
}
inline int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
int main(){
	memset(head,-1,sizeof head);
    scanf("%d%d",&n,&m);
    for(int i=1,a,b;i<=m;i++)
        scanf("%d%d",&a,&b),add(a,b),add(b,a);
    scanf("%d",&k);
    for(int i=1;i<=k;i++)scanf("%d",&a[i]),v[a[i]]=1;
    for(int i=1;i<=n;i++)p[i]=i;
    cnt=n-k;
    for(int i=0;i<n;i++)
        if(!v[i])for(int j=head[i];~j;j=next[j])
			if(!v[key[j]]&&find(i)!=find(key[j]))
				p[find(i)]=find(key[j]),cnt--;
    ans[k+1]=cnt;
    for(int i=k;i>=1;i--){
        v[a[i]]=0;cnt++;
        for(int j=head[a[i]];~j;j=next[j])
            if(!v[key[j]]&&find(a[i])!=find(key[j]))
				p[find(a[i])]=find(key[j]),cnt--;
        ans[i]=cnt;
    }
    for(int i=1;i<=k+1;i++)printf("%d\n",ans[i]);
    return 0;
}

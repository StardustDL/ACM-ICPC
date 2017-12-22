/*
[Sdoi2014]数表
分析：见http://blog.csdn.net/iamzky/article/details/40376189
	  不断转化，最后得到一个与a有关的式子，最后离线处理，解决a的限制 ，好题 
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cctype>
#include<vector>
#define lowbit(x) ((x)&-(x))
using namespace std;
const int MAXN=1e5;
int c[MAXN+3],clen;
int sum(int x){
	int ans=0;
	while(x)ans+=c[x],x-=lowbit(x);
	return ans;
}
void updata(int x,int f){
	while(x<=clen)c[x]+=f,x+=lowbit(x);
}
struct qes{int n,m,a,id;bool operator<(const qes oth)const{return a<oth.a;}}Q[MAXN+3];
int anss[MAXN+3],mindiv[MAXN+3],miu[MAXN+3];
vector<int> pris;
pair<int,int> sig[MAXN+3];
void init(int size){
	miu[1]=1;
	for(int i=2;i<=size;i++){
		if(!mindiv[i]){pris.push_back(i);mindiv[i]=i;miu[i]=-1;}
		for(int j=0,k;j<pris.size()&&(k=i*pris[j])<=size;j++){
			mindiv[k]=pris[j];
			if(mindiv[i]==pris[j]){miu[k]=0;break;}
			miu[k]=-miu[i];
		}
	}
	for(int i=1;i<=size;i++)
		for(int j=i;j<=size;j+=i)sig[j].first+=i;
	for(int i=1;i<=size;i++)sig[i].second=i;
	sort(sig+1,sig+size);
}
int main(){
	int T;scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d%d%d",&Q[i].n,&Q[i].m,&Q[i].a);
		if(Q[i].n>Q[i].m)swap(Q[i].n,Q[i].m);
		Q[i].id=i;
		clen=max(clen,Q[i].n);
	}
	init(clen+1);
	sort(Q+1,Q+T+1);
	for(int i=1,newa,lasta=1;i<=T;i++,lasta=newa+1){
		newa=upper_bound(sig+1,sig+clen,make_pair(Q[i].a+1,-1))-sig-1;
		for(int j=lasta;j<=newa;j++)
			for(int k=sig[j].second;k<=clen;k+=sig[j].second)
				updata(k,sig[j].first*miu[k/sig[j].second]);	
		for(int j=1,k;j<=Q[i].n;j=k+1){
			k=min(Q[i].n/(Q[i].n/j),Q[i].m/(Q[i].m/j));
			anss[Q[i].id]+=(sum(k)-sum(j-1))*(Q[i].n/j)*(Q[i].m/j);
		}
	}
	for(int i=1;i<=T;i++)printf("%d\n",anss[i]&0x7fffffff);
	return 0;
} 
/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int N=100010;
const long long modi=1LL<<31;
int t,n,i,j,k,l,last_a,next,vec[N];
long long c[N],ans[N],r,f[N];
int prime[N],mindiv[N],minp[N],miu[N],tot;
void add(int a,int b){for(int i=a;i<=n;i+=i&-i)c[i]+=b;}
long long search(int a){long long r=0;for(int i=a;i;i-=i&-i)r+=c[i];return r;}
struct question{int n,m,a,id;}q[N];
int cmp(question a,question b){return a.a<b.a;}
int cmp2(int a,int b){return f[a]<f[b];}
int main()
{
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d%d",&q[i].n,&q[i].m,&q[i].a);
        if(q[i].n>q[i].m)swap(q[i].n,q[i].m);
        n=max(n,q[i].n);
        q[i].id=i;
    }
    miu[1]=f[1]=minp[1]=mindiv[1]=1;
    for(i=2;i<=n;i++)
    {
        if(!mindiv[i])
        {
            minp[i]=mindiv[i]=prime[++tot]=i;
            miu[i]=-1;
            f[i]=i+1;
        }
        for(j=1;j<=tot&&prime[j]*i<=n&&prime[j]<=mindiv[i];j++)
        {
            k=prime[j]*i;
            mindiv[k]=prime[j];
            if(prime[j]==mindiv[i])
            {
                minp[k]=minp[i]*prime[j];
                miu[k]=0;
            }
            else
            {
                minp[k]=prime[j];
                miu[k]=-miu[i];
            }
            if(minp[k]==k)f[k]=f[i]+k;
            else f[k]=f[k/minp[k]]*f[minp[k]];
        }
    }
    for(i=1;i<=n;i++)vec[i]=i;
    sort(q+1,q+t+1,cmp);
    sort(vec+1,vec+n+1,cmp2);
    for(last_a=k=1;k<=t;k++)
    {
        for(;f[vec[last_a]]<=q[k].a&&last_a<=n;last_a++)
        {
            l=vec[last_a];
            for(j=l;j<=n;j+=l)add(j,f[l]*miu[j/l]);
        }
        r=0;
        for(i=1;i<=q[k].n;i=next)
        {
            next=min(q[k].n/(q[k].n/i),q[k].m/(q[k].m/i))+1;
            r+=(long long)(q[k].n/i)*(q[k].m/i)*(search(next-1)-search(i-1));
        }
        ans[q[k].id]=r;
    }
    for(i=1;i<=t;i++)printf("%lld\n",ans[i]%modi);
    return 0;
}
*/ 

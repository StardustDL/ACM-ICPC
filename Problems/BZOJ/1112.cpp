/*

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
typedef long long LL;
#define LINF 9223372036854775807LL
using namespace std;
inline int read(){
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int n,K,m,root,sz;
LL tmp;
LL ans=LINF,sum1,sum2;
LL sum[100005],v[100005];
int h[100005];
int rnd[100005],size[100005],l[100005],r[100005],w[100005];
void update(int k){
     size[k]=size[l[k]]+size[r[k]]+w[k];
     sum[k]=sum[l[k]]+sum[r[k]]+v[k]*w[k];
}
void rturn(int &k){
	int t=l[k];l[k]=r[t];r[t]=k;update(k);update(t);k=t;
}
void lturn(int &k){
	int t=r[k];r[k]=l[t];l[t]=k;update(k);update(t);k=t;
}
void insert(int &k,int val){
	if(!k){k=++sz;sum[k]=v[k]=val;w[k]=size[k]=1;rnd[k]=rand();return;}
    size[k]++;sum[k]+=val;
    if(val==v[k])w[k]++;
    else if(val<v[k]){
		insert(l[k],val);
		if(rnd[l[k]]<rnd[k])rturn(k);
	}
    else {
		insert(r[k],val);
		if(rnd[r[k]]<rnd[k])lturn(k);
	}
}
void del(int &k,int val){
	if(!k)return;
	if(val==v[k]){
        if(w[k]>1){w[k]--;sum[k]-=val;size[k]--;return;}
		if(l[k]*r[k]==0)k=l[k]+r[k];
		else if(rnd[l[k]]<rnd[r[k]]){rturn(k);del(k,val);}
		else {lturn(k);del(k,val);}
	}
	else if(val<v[k]){
		size[k]--;sum[k]-=val;del(l[k],val);
	}
	else{
		size[k]--;sum[k]-=val;del(r[k],val);
	}
}
void find(int k,int rank){
    if(!k)return;    
	if(rank>size[l[k]]&&rank<=size[l[k]]+w[k]){
		sum1+=(sum[l[k]]+(rank-size[l[k]]-1)*v[k]);
        sum2+=(sum[r[k]]+(size[l[k]]+w[k]-rank)*v[k]);
		tmp=v[k];
	}
	else if(rank<=size[l[k]]){
	    sum2+=(v[k]*w[k]+sum[r[k]]);
	    find(l[k],rank);
    }
    else{
	    sum1+=(v[k]*w[k]+sum[l[k]]);
	    find(r[k],rank-size[l[k]]-w[k]);
    }
}  
void getans(){
	sum1=sum2=0;
	find(root,m);
	LL sum=(m-1)*tmp-sum1+sum2-(K-m)*tmp;
	if(sum<ans)ans=sum;
}
int main(){
	n=read(),K=read();m=((K+1)>>1);
	for(int i=1;i<=n;i++)
	    h[i]=read();
	for(int i=1;i<=K;i++)
	    insert(root,h[i]);
	getans();
	for(int i=K+1;i<=n;i++){
		del(root,h[i-K]);
		insert(root,h[i]);
		getans();
	}
	printf("%lld",ans);
	return 0;
}

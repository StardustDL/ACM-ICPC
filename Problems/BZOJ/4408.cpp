/*
[Fjoi 2016]神秘数
分析：同BZOJ4299 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
int ch[MAXN*40+5][2],sum[MAXN*40+5],a[MAXN+5],root[MAXN+5];
int n,m,mx,cnt;
int scan(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
void add(int pre,int &x,int l,int r,int v){
    if(!x)x=++cnt;
    sum[x]=sum[pre]+v;
    if(l==r)return;
    int mid=l+r>>1;
    if(v<=mid)
        ch[x][1]=ch[pre][1],
        add(ch[pre][0],ch[x][0],l,mid,v);
    else
        ch[x][0]=ch[pre][0],
        add(ch[pre][1],ch[x][1],mid+1,r,v);
}
int query(int pre,int x,int l,int r,int E){
    if(E>=r)return sum[x]-sum[pre];
    int mid=l+r>>1;
    if(E>mid)return sum[ch[x][0]]-sum[ch[pre][0]]+query(ch[pre][1],ch[x][1],mid+1,r,E);
    else  return query(ch[pre][0],ch[x][0],l,mid,E);
}   
int main(){
    n=scan();
    for(int i=1;i<=n;i++)mx=max(mx,a[i]=scan());
    for(int i=1;i<=n;i++)add(root[i-1],root[i],1,mx,a[i]);
    m=scan();
    for(int i=1;i<=m;i++){
        int l=scan()-1,r=scan(),ans=1;
        while(1){
            int sum=query(root[l],root[r],1,mx,ans);
            if(sum<ans)break;
            ans=sum+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}

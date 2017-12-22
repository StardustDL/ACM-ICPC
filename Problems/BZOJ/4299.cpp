/*
Codechef FRBSUM
分析：很有意思的一道题。很容易发现假如已经构造出来了1,2...max再插入一个数x，假如x≤max+1那么现在就可以构造出1,2...max,max+1...max+x 
		于是我们可以这样做，先建立可持久化线段树。对于询问区间[l,r],当前的max=0,然后不断查询区间[l,r]中1到max+1所有数的和来更新max 
		如果区间[l,r]中1到max+1所有数的和>max，那么肯定可以构造出1到这个所有数的和之间的数，然后一直更新，直到不能更新为止。 
		可以发现更新这个过程max是成倍增长的，然后每次询问的复杂度都是log的，所以总的复杂度就是mlog^2n的 
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

/*
permu
分析：区间查询，支持离线，莫队，根据L分块
	  如果只考虑不删数的情况，每加入一个数可以直接用并查集维护。
	  用莫队分块后，对于左端点在同一个块的询问，右端点是从小到大排的，于是对于左端点那块后面的数就可以只加入不删除， 
	  然后考虑如果左端点所属的那块改变了，暴力统计。 
*/
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=50000,BS=300;
int m,n,a[MAXN+3],blo[MAXN+3],fa[MAXN+3],sz[MAXN+3],rk[MAXN+3],pos[MAXN+3],Ans[MAXN+3];
struct query{int l,r,id;bool operator <(const query&b)const{return(blo[l]<blo[b.l])||(blo[l]==blo[b.l])&&(r<b.r);}}q[MAXN+3];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void unite(int l,int r){
	l=find(l),r=find(r);
	fa[r]=l,sz[l]+=sz[r];
}
int main(){
	scanf("%d%d",&n,&m); 
    for(int i=1;i<=n;++i)scanf("%d",&a[i]); 
    for(int i=1;i<=m;++i){scanf("%d%d",&q[i].l,&q[i].r);q[i].id=i;}
    for(int i=1;i<=n;++i)blo[i]=i/BS;
    sort(q+1,q+m+1);
    for(int curb=-1,curr=0,L,R,ans,i=1;i<=m;++i){//ans维护使用[R+1..q[i].r]这段区间能得到的最大连续长度  
    	int &qans=Ans[q[i].id]; 
        if(blo[q[i].l]!=curb){//左端点所属块变更 
            memset(fa,0,sizeof(fa));memset(sz,0,sizeof(sz));
            L=blo[q[i].l]*BS+1,R=min(n,L+BS-1);//处理左端点所属块的信息，这里的处理方式是暴力，并没有加到并查集中，并查集只维护这个块之外的值 
            for(int j=L;j<=R;++j)pos[a[j]]=j,rk[j]=a[j];//pos[i]维护i这个数出现在a中的位置，rk[i]表示排第i位的数是几 
            curr=R;sort(rk+L,rk+R+1);ans=0;//curR维护当前维护到的右端点 
        }
        curb=blo[q[i].l];
        if(q[i].r<=R){//q[i].l与q[i].r属于同一块 
            for(int cnt=0,last=-1,j=L;j<=R;++j){
                int k=rk[j];
                if(pos[k]>=q[i].l&&pos[k]<=q[i].r){ 
					cnt=1+(last==k-1?cnt:0);
                	qans=max(qans,cnt);
					last=k;
				}
            }
			continue;
        }
        while(curr<q[i].r){//处理右端点的增加 
            int k=a[++curr];
			fa[k]=k,sz[k]=1;
            if(find(k+1))unite(k,k+1);
            if(find(k-1))unite(k,k-1);
            ans=max(ans,sz[k]);//维护ans，它对下次循环可能仍有用（只要左端点所在块不变） 
        }
		qans=ans;
        for(int cnt=0,last=-1,j=L;j<=R;++j){//考虑将左端点所在块[L..R]并上[R+1..q[i].r]这段区间能得到的最大连续长度 
            int k=rk[j];
            if(pos[k]>=q[i].l){//要求这个点要在询问区间内 
            	//这是一个排列，以下三种情况只会有一种成立 
                if(find(k-1))cnt=find(last+1)==fa[k-1]?cnt+1:sz[fa[k-1]]+1;//下一个相邻的(last+1)与k-1所在联通块相同（即它们连在一起），长度能扩大1(增加了一个k) 
                else if(last==k-1)++cnt;//不通过并查集，直接就是挨着的，cnt增加1 
				else cnt=1;
                if(find(k+1))cnt+=sz[fa[k+1]];
				last=k;
                qans=max(qans,cnt);
            }
        }
    }
    for(int i=1;i<=m;++i)printf("%d\n",Ans[i]);
}

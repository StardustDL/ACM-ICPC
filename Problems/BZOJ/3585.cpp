/*
mex
分析：同3339，先离散化，注意这题离散化有特殊的地方，因为是mex 
*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=200000;
typedef int arr[MAXN+3];
arr a,v,last,mex,next,ans;
int n,q,cnt;
struct query{int l,r,id;}qs[MAXN+3];
struct number{int x,id;}ns[MAXN+3];
bool cmp1(query x,query y){return x.l<y.l;}
bool cmp2(number x,number y){return x.x<y.x;}
arr t1,t2;
void init(){//离散化 
	sort(ns+1,ns+n+1,cmp2);
	cnt=0;t1[cnt]=0;t2[0]=cnt;
	for(int i=1;i<=n;i++){
		if(ns[i].x!=t1[cnt]){t1[++cnt]=ns[i].x;}
		t2[ns[i].id]=cnt;
	}
	for(int cur=0,i=1;i<=n;i++){
    	v[t2[i]]=1;
        while(v[cur]!=0&&t1[cur+1]==t1[cur]+1)cur++;//注意这两句 
        if(v[cur]!=0&&t1[cur+1]!=t1[cur]+1)mex[i]=t1[cur]+1;
        else mex[i]=t1[cur];
    }
    for(int i=1;i<=n;i++){
        next[last[t2[i]]]=i;
        next[i]=n+1;
        last[t2[i]]=i;
    }
}
void change(int x){
	int ed=next[x]?next[x]:(n+1);
    mex[x]=0;
    for(int i=ed-1;i>x;i--){//这里倒着更新， 降低复杂度 
        if(mex[i]<=a[x])break;
        mex[i]=a[x];
    }
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){scanf("%d",&a[i]);ns[i].x=a[i],ns[i].id=i;}
    init();
    for(int i=1;i<=q;i++){
        scanf("%d%d",&qs[i].l,&qs[i].r);
        qs[i].id=i;
    }
    sort(qs+1,qs+1+q,cmp1);
    int curl=1;
    for(int i=1;i<=q;i++){
    	for(int j=curl;j<qs[i].l;j++)change(j);
        ans[qs[i].id]=mex[qs[i].r];
        curl=qs[i].l;
    }
    for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
    return 0;
}

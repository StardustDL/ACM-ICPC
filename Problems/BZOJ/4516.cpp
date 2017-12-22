/*
[Sdoi2016]生成魔咒
分析：后缀自动机，类似幻想乡那个 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;
const int MAXN=1000000,INF=0x3f3f3f3f;
typedef long long LL;
struct SAM{
	struct node{
		map<int,int> ch;
		int pa,len;
	}ns[MAXN+3];
	int root,tot,last;
	LL cnt;
	int newnode(int l){
		tot++;
		ns[tot].len=l;
		ns[tot].pa=0;
		return tot;
	}
	void clear(){
		tot=0;cnt=0;
		root=newnode(0);last=root;
	}
	inline int get_cnt(int x){
		return ns[x].len-ns[ns[x].pa].len;
	}
	void append(int x){
		int p=last,np=newnode(ns[p].len+1);
		for(;p && ns[p].ch[x]==0;p=ns[p].pa)ns[p].ch[x]=np;
		if(p==0){ns[np].pa=root;cnt+=get_cnt(np);}
		else{
			int q=ns[p].ch[x];
			if(ns[q].len==ns[p].len+1){ns[np].pa=q;cnt+=get_cnt(np);}
			else{
				int nq=newnode(ns[p].len+1);
				ns[nq].ch=ns[q].ch;
				ns[nq].pa=ns[q].pa;cnt+=get_cnt(nq);
				ns[np].pa=nq;cnt+=get_cnt(np);
				cnt-=get_cnt(q);ns[q].pa=nq;cnt+=get_cnt(q);
				for(;p && ns[p].ch[x]==q;p=ns[p].pa)ns[p].ch[x]=nq;
			}
		}
		last=np;
	}
}S;
int n;
int main(){
	S.clear();
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		S.append(x);
		/*LL ans=0;
		for(int i=1;i<=S.tot;i++)ans+=S.ns[i].len-S.ns[S.ns[i].pa].len;
		cout<<ans<<endl;*/
		printf("%lld\n",S.cnt);
	}
	return 0;
}


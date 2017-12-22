/*
[Ctsc2012]Cheat
分析： 后缀自动机 
		* 首先数据很大。注意L满足二分性，所以可以二分L，判断是否存在一种满足条件的划分。假如我们知道str[i]向前最长能匹配到多长，那么可以DP出最长的匹配长度：
		* opt[i]表示[0..i]的最长匹配字符数，有opt[i]=max{opt[j]+(i-j)|L<=i-j<=最长匹配[i]}
		* 转化一下，提取参数：opt[i]=max{opt[j]-j|i-match[i]<=j<=i-L}，注意i-match[i]是单调不降的（因为match[i]随着i的移动，最多减少1），这个方程可以O(n)求解：维护opt[j]-j的单调队列即可。
		* 接下来就剩下求match数组了：首先先将输入的多个串拼成一个串，相邻两串之间用没有出现过的数隔开，建立后缀自动机，那么拿询问串在后缀自动机上匹配，对于匹配到了状态x，则这个位置的答案就等于这个状态的right集合长度上限（根据Max(s)的定义）。
		* 那如果没有匹配呢，沿着parent树向上爬，直到爬到一个可以转移的，注意这里的最长匹配长度=Max(找到的状态)+1，而不是找到的状态转移了一步后的Max(s)，因为走了一步之后最大长度可能就会变化，变得不是i位置能匹配的最长了。
		* 然后注意：后缀自动机节点一定要开2N，还有不要到处memset(0)，因为每次dp都全部初始化，TLE了好几次= =，
		* 还有记得这句话：nq.fa=q.fa
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=2*1100000+100,INF=0x3f3f3f3f;
const int NS=3;
struct SAM{
	#define idx(x) ((x)-'0')
	struct node{
		int ch[NS],len,pa;
	}ns[MAXN+3];
	int root,last,tot;
	int newnode(int le){
		tot++;
		memset(ns[tot].ch,0,sizeof(ns[tot].ch));
		ns[tot].pa=0;
		ns[tot].len=le;
		return tot;
	}
	void clear(){
		tot=0;
		root=last=newnode(0);
	}
	void append(int x){
		int p=last,np=newnode(ns[p].len+1);
		for(;p && ns[p].ch[x]==0;p=ns[p].pa)ns[p].ch[x]=np;
		if(p==0)ns[np].pa=root;
		else{
			int q=ns[p].ch[x];
			if(ns[q].len==ns[p].len+1)ns[np].pa=q;
			else{
				int nq=newnode(ns[p].len+1);
				memcpy(ns[nq].ch,ns[q].ch,sizeof(ns[q].ch));
				ns[nq].pa=ns[q].pa; 
				ns[q].pa=ns[np].pa=nq;
				for(;ns[p].ch[x]==q;p=ns[p].pa)ns[p].ch[x]=nq;
			}
		}
		last=np;
	}
	void match(char *x,int len,int *mat){
		int cur=root,ans=0;
		for(int i=1;i<=len;i++){
			int t=idx(x[i]);
			if(ns[cur].ch[t]){cur=ns[cur].ch[t];ans++;}
			else{
				while(cur && ns[cur].ch[t]==0)cur=ns[cur].pa;
				if(cur==0){ans=0;cur=root;}
				else{
					ans=ns[cur].len+1;
					cur=ns[cur].ch[t];
				}
			}
			mat[i]=ans;
		}
	}
}sam;
struct queue{
	pair<int,int> d[MAXN+3];
	int head,tail;
	void init(){
		head=1;tail=0;//memset(d,0,sizeof(d));
	}
	void push(pair<int,int> x){
		while(head<=tail&&d[tail].first<x.first)tail--;
		d[++tail]=x;
	}
	void pop(int val){
		while(head<=tail && d[head].second < val)head++;
	}
	int top(){
		return (head<=tail)?d[head].first:(-INF);
	}
}Q;
int opt[MAXN+3],mat[MAXN+3];
int f[MAXN+3];
int dp(int len,int LANS){
	//memset(opt,0,sizeof(opt));
	Q.init();
	opt[0]=0;
	for(int i=1;i<=len;i++){
		if(i-LANS>=0)Q.push(make_pair(opt[i-LANS]-(i-LANS),i-LANS));
		Q.pop(i-mat[i]);
		opt[i]=max(opt[i-1],Q.top()+i);
	}
	//cout<<"#"<<opt[len]<<endl;
	/*for(int i=1;i<=len;i++){
		f[i]=f[i-1];
		for(int j=i-mat[i];j<=i-LANS;j++){
			f[i]=max(f[i],f[j]+i-j);
		}
	}
	return f[len];*/
	return opt[len];
}
bool check(int len,int L){
	int t=dp(len,L);
	//cout<<t<<endl;
	return t*10>=len*9;
}
int bits(int l,int r,int len){
	int ans=l;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(len,mid)){
			ans=mid;l=mid+1;
		}
		else r=mid-1;
	}
	return ans;
}
char T[MAXN+3];
int tlen;
int solve(){
	scanf("%s",T+1);
	tlen=strlen(T+1);
	sam.match(T,tlen,mat);
	//for(int i=1;i<=tlen;i++)cout<<mat[i]<<"";
	return bits(0,tlen,tlen);
}
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	sam.clear();
	int len=0;
	for(int i=1;i<=m;i++){
		scanf("%s",T);
		len=strlen(T);
		for(int i=0;i<len;i++)sam.append(T[i]-'0');
		sam.append(2);
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",solve());
		//cout<<"##"<<endl;
	}
	return 0;
}


/*

*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
typedef long long LL;
const int MAXN=1000,INF=0x3f3f3f3f;
const int NS=26;
struct Trie{
	int ch[MAXN+3][NS],tag[MAXN+3],tot,root;
	void init(){
		tot=0;root=newnode();
	}
	int newnode(){
		tag[tot]=0;memset(ch[tot],0,sizeof(tot));
		return tot++;
	}
	inline int idx(char c){
		return c-'a';
	}
	void insert(char *s,int len,int val){
		int cur=root;
		for(int i=0;i<len;i++){
			if(ch[cur][idx(s[i])]==0)ch[cur][idx(s[i])]=newnode();
			cur=ch[cur][idx(s[i])]; 
		}
		tag[cur]=val;
	}
	bool has_string(char *s,int len){
		int cur=root;
		for(int i=0;i<len;i++){
			if(ch[cur][idx(s[i])]==0)return false;
			cur=ch[cur][idx(s[i])]; 
		}
		return tag[cur]>0;
	}
	bool has_prefix(char *s,int len){
		int cur=root;
		for(int i=0;i<len;i++){
			if(ch[cur][idx(s[i])]==0)return false;
			cur=ch[cur][idx(s[i])]; 
		}
		return true;
	}
};
namespace KMP{
	int fail[MAXN+3],lenS;
	char *S;
	void pre(char *s,int n){
		S=s;lenS=n;
		fail[0]=fail[1]=0;
		for(int i=1;i<n;i++){
			int j=fail[i];
			while(s[i]!=s[j] && j)j=fail[j];
			fail[i+1]=s[i]==s[j]?j+1:0;
		}
	}
	int kmp(char *t,int n){
		int j=0;
		for(int i=0;i<n;i++){
			while(t[i]!=S[j] && j)j=fail[j];
			if(t[i]==S[j])j++;
			if(j==lenS)return i-j+1;
		}
		return -1;
	}
}
namespace StringHash{
	const LL MOD=1000000007,P=13331;
	LL hash[MAXN+3],ps[MAXN+3],invps[MAXN+3];
	LL qpow(LL a,LL b){
		LL ans=1;
		while(b){
			if(b&1)ans=ans*a%MOD;
			a=a*a%MOD;
			b>>=1;
		}
		return ans;
	}
	void pre(char *s,int n){//s=str[1..n]
		ps[0]=1;invps[0]=1;invps[1]=qpow(P,MOD-2);hash[0]=0;
		for(int i=1;i<=n;i++){ps[i]=ps[i-1]*P%MOD,invps[i]=invps[i-1]*invps[1]%MOD;}
		for(int i=1;i<=n;i++){
			hash[i]=(hash[i-1]+ps[i]*(s[i]-'a'+1)%MOD)%MOD;
		}
	}
	LL get_hash(int l,int r){
		return ((hash[r]-hash[l-1])+MOD)%MOD*invps[l]%MOD;
	}
}
namespace Manacher{
	int p[2*MAXN+9],_s[2*MAXN+9],len;
	void pre(char *t,int n){
		_s[0]='#';len=1;
		for(int i=0;i<n;i++){
			_s[len++]=t[i];
			_s[len++]='#';
		}
	}
	int manacher(){
		int id=0,mx=0;
		memset(p,0,sizeof(p));
		for(int i=0;i<len;i++){
			if(mx>i)p[i]=min(mx-i,p[2*id-i]);
			for(;i-p[i]>=0&&i+p[i]<len&&_s[i-p[i]]==_s[i+p[i]];)p[i]++;
			if(i+p[i]>mx)mx=i+p[i],id=i;
		}
		int ans=0;
		for(int i=0;i<len;i++)ans=max(ans,2*(p[i]-1)+1);
		return ans/2;
	}
};
struct ACAutomation{
	int ch[MAXN+3][NS],tag[MAXN+3],fail[MAXN+3],last[MAXN+3],tot,root;
	void init(){
		tot=0;root=newnode();//root=0;
	}
	int newnode(){
		tag[tot]=0;memset(ch[tot],0,sizeof(tot));
		return tot++;
	}
	inline int idx(char c){
		return c-'a';
	}
	void insert(char *s,int len,int val){
		int cur=root;
		for(int i=0;i<len;i++){
			if(ch[cur][idx(s[i])]==0)ch[cur][idx(s[i])]=newnode();
			cur=ch[cur][idx(s[i])]; 
		}
		tag[cur]=val;
	}
	void build(){
		static queue<int> q;
		while(!q.empty())q.pop();
		for(int i=0;i<NS;i++){
			int u=ch[root][i];
			if(u){
				fail[u]=0;last[u]=0;
				q.push(u);
			}
		}
		while(!q.empty()){
			int u=q.front();q.pop();
			//cout<<u<<endl;
			for(int i=0;i<NS;i++){
				int v=ch[u][i];
				if(!v){ch[u][i]=ch[fail[u]][i];continue;}
				q.push(v);
				
				int t=fail[u];
				while(t&&ch[t][i]==0)t=fail[t];
				
				fail[v]=ch[t][i];
				last[v]=tag[fail[v]]?fail[v]:last[fail[v]];
			}
		}
	}
	void search(char *s,int n,vector<int> &ans){
		int cur=root;
		for(int i=0;i<n;i++){
			cur=ch[cur][idx(s[i])];
			if(tag[cur])putans(cur,ans);
			else if(last[cur])putans(last[cur],ans);
		}
	}
	void putans(int x,vector<int> &ans){
		if(x){
			ans.push_back(tag[x]);
			if(last[x])putans(last[x],ans);
		}
	}
};
struct SuffixAutomation{
	struct node{
		int len,pa,ch[NS];
	}ns[MAXN+3];
	int tot,last,root;
	void init(){
		tot=0;root=newnode(0);last=root;
	}
	int newnode(int len){
		tot++;
		memset(ns[tot].ch,0,sizeof(ns[tot].ch));
		ns[tot].pa=0;
		ns[tot].len=len;
		return tot;
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
				for(;p && ns[p].ch[x]==q;p=ns[p].pa)ns[p].ch[x]=nq;
			}
		}
		last=np;
	}
	bool has_string(int* a,int n){
		int cur=root;
		for(int i=0;i<n;i++)if(ns[cur].ch[a[i]])cur=ns[cur].ch[a[i]];else return false;
		return true;
	}
};
namespace SuffixArray{
	int wa[MAXN+3],sa[MAXN+3],wb[MAXN+3],wv[MAXN+3],wt[MAXN+3];
	int height[MAXN+3],rank[MAXN+3];
	bool cmp(int *t,int a,int b,int l){
		return t[a]==t[b]&&t[a+l]==t[b+l];
	}
	void da(int* str,int *sa,int n,int m){
		int *x=wa,*y=wb,i,j,p,*t;
		for(i=0;i<m;i++)wt[i]=0;
		for(i=0;i<n;i++)wt[x[i]=str[i]]++;
		for(i=1;i<m;i++)wt[i]+=wt[i-1];
		for(i=n-1;i>=0;i--)sa[--wt[x[i]]]=i;
		for(j=1,p=1;p<n;j<<=1,m=p){
			for(p=0,i=n-j;i<n;i++)y[p++]=i;
			for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;
			for(i=0;i<m;i++)wt[i]=0;
			for(i=0;i<n;i++)wt[wv[i]=x[y[i]]]++;
			for(i=1;i<m;i++)wt[i]+=wt[i-1];
			for(i=n-1;i>=0;i--)sa[--wt[wv[i]]]=y[i];
			swap(x,y);
			for(p=1,x[sa[0]]=0,i=1;i<n;i++)
				x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++; 
		}
	}
	void calc_height(int* str,int n){
		int i,j,k=0;
		for(i=0;i<=n;i++)rank[sa[i]]=i;
		for(i=0;i<n;i++){
			if(k)k--;
			j=sa[rank[i]-1];
			while(str[i+k]==str[j+k])k++;
			height[rank[i]]=k;
		}
	}
	void init(int* str,int n,int m){
		str[n]=0;
		da(str,sa,n+1,m);
		calc_height(str,n);
	}
}
/*
	ac.init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		ac.insert(s,strlen(s),i);
	}
	ac.build();
	for(int i=1;i<=ac.tot;i++)cout<<ac.fail[i]<<" ";
	vector<int> ans;
	for(int i=1;i<=n;i++){
		scanf("%s",s);ans.clear();
		ac.search(s,strlen(s),ans);
		for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
		cout<<endl;
	}
*/
using namespace SuffixArray;

int n,a[MAXN+3];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	init(a,n,200);
	for(int i=0;i<=n+1;i++)cout<<sa[i]<<" ";
	return 0;
}


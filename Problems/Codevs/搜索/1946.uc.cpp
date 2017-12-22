/*
阿狸的打字机
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define lowbit(x) (x&-x)
using namespace std;
const int MAXN=10000,INF=1<<30,NODESIZE=26,ROOT=0;
typedef long long LL;
typedef char str[1001];
struct BIT{
	int n,c[MAXN+3];
	void init(){
		memset(c,0,sizeof(c));
		n=0;
	}
	int sum(int x){
		int ans=0;
		while(x>0){
			ans+=c[x];x-=lowbit(x);
		}
		return ans;
	}
	void add(int i,int ad){
		while(i<=n){
			c[i]+=ad;i+=lowbit(i);
		}
	}
	void build(int *a,int n){
		init();
		this->n=n;
		for(int i=1;i<=n;i++){
			add(i,a[i]);
		}
	}
};
struct Trie{	
	int ch[MAXN+3][NODESIZE+1],val[MAXN+3],noden,strn;
	
	void init(){
		noden=strn=0;
		memset(ch,0,sizeof(ch));
		memset(val,0,sizeof(val));
	}
	
	int idx(char c){
		return c-'a';
	}
	
	int add(str s){
		int len=strlen(s);
		int curn=ROOT;
		for(int i=0;i<len;i++){
			int &e=ch[curn][idx(s[i])];
			if(e==0){
				e=++noden;
			}
			curn=e;
		}
		val[curn]=++strn;
		return curn;
	}
};
struct AhoCorasick{
	Trie tre;
	vector<int> to[MAXN+3];
	int f[MAXN+3];
	
	void addedge(int u,int v){
		to[u].push_back(v);
	}

	void buildFail(){
		queue<int> q;
		f[0]=0;
		for(int c=0;c<NODESIZE;c++){
			int u=tre.ch[ROOT][c];
			if(u){f[u]=0;q.push(u);addedge(0,u);}
		}
		while(!q.empty()){
			int r=q.front();q.pop();
			for(int c=0;c<NODESIZE;c++){
				int u=tre.ch[r][c];
				if(!u)continue;
				q.push(u);
				int v=f[r];
				while(v&&!tre.ch[v][c])v=f[v];
				f[u]=tre.ch[v][c];
				addedge(tre.ch[v][c],u);
			}
		}
	}
};
AhoCorasick ac;
BIT bit;
int in[MAXN+3],out[MAXN+3],dfstime=0,m;
vector<str> strs;
vector<int> word[MAXN+3];//以i节点结尾的单词 
vector<int> ques[MAXN+3];//关于y串的询问 
int quex[MAXN+3],quey[MAXN+3],queans[MAXN+3],tail[MAXN+3];

void loadstr(){
	char c;str s;int len=0;
	cin>>c;
	while(c!='\n'){
		if(c=='P'){
			s[len]='\0';
			strs.push_back(s);
			int k=ac.tre.add(s);
			word[k].push_back(ac.tre.strn);
			tail[ac.tre.strn]=k;
		}
		else if(c=='B'){len--;}
		else{s[len++]=c;}
		cin>>c;
	}
}
void loadque(){
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>quex[i]>>quey[i];
		ques[quey[i]].push_back(i);
	}
} 
void dfs(int u){
	in[u]=++dfstime;
	for(int i=0;i<ac.to[u].size();i++){
		dfs(ac.to[u][i]);
	}
	out[u]=++dfstime;
}
void solve(int t){
	bit.add(in[t],1);
	vector<int> *V=&word[t];
	for(int i=0;i<V->size();i++){
		vector<int> *T=&ques[(*V)[i]];
		for(int j=0;j<T->size();j++){
			queans[(*T)[j]]=bit.sum(out[t])-bit.sum(in[t]-1);
		}
		for(int j=0;j<NODESIZE;i++){
			if(ac.tre.ch[t][j]){
				solve(ac.tre.ch[t][j]);
			} 
		}
	}
	bit.add(out[t],-1);
}
int main(){
	ios::sync_with_stdio(false);
	ac.tre.init();bit.init();
	loadstr();loadque();
	ac.buildFail();
	dfs(ROOT);
	solve(ROOT);
	for(int i=1;i<=m;i++)cout<<queans[i]<<endl;
	return 0;
}

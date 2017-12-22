/*
[Ctsc2012]Cheat
������ ��׺�Զ��� 
		* �������ݺܴ�ע��L��������ԣ����Կ��Զ���L���ж��Ƿ����һ�����������Ļ��֡���������֪��str[i]��ǰ���ƥ�䵽�೤����ô����DP�����ƥ�䳤�ȣ�
		* opt[i]��ʾ[0..i]���ƥ���ַ�������opt[i]=max{opt[j]+(i-j)|L<=i-j<=�ƥ��[i]}
		* ת��һ�£���ȡ������opt[i]=max{opt[j]-j|i-match[i]<=j<=i-L}��ע��i-match[i]�ǵ��������ģ���Ϊmatch[i]����i���ƶ���������1����������̿���O(n)��⣺ά��opt[j]-j�ĵ������м��ɡ�
		* ��������ʣ����match�����ˣ������Ƚ�����Ķ����ƴ��һ��������������֮����û�г��ֹ�����������������׺�Զ�������ô��ѯ�ʴ��ں�׺�Զ�����ƥ�䣬����ƥ�䵽��״̬x�������λ�õĴ𰸾͵������״̬��right���ϳ������ޣ�����Max(s)�Ķ��壩��
		* �����û��ƥ���أ�����parent����������ֱ������һ������ת�Ƶģ�ע��������ƥ�䳤��=Max(�ҵ���״̬)+1���������ҵ���״̬ת����һ�����Max(s)����Ϊ����һ��֮����󳤶ȿ��ܾͻ�仯����ò���iλ����ƥ�����ˡ�
		* Ȼ��ע�⣺��׺�Զ����ڵ�һ��Ҫ��2N�����в�Ҫ����memset(0)����Ϊÿ��dp��ȫ����ʼ����TLE�˺ü���= =��
		* ���мǵ���仰��nq.fa=q.fa
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


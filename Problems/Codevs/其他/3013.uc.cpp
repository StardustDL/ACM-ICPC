/*
���ʱ���
�������������m���ַ���ת����������һЩ����������г��ȣ�
	  ��������ɨһ��m���У�ά��ÿ�������ֵ����λ��mn[]��ÿ��ȡmn[1..n]�е���Сֵt��ans=min{i-t+1} 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
const int LEN=10,MAXN=1000*LEN,MAXM=100000,INF=0x3f3f3f3f,MN=1000;
typedef char str[LEN+3];
struct Trie{
	int ch[MAXN+3][26],val[MAXN+3],cnt;
	inline int id(char c){return c-'a';}
	void init(){
		cnt=0;
	}
	int newnode(){
		cnt++;
		memset(ch[cnt],0,sizeof(cnt));
		val[cnt]=0;
		return cnt;
	}
	void insert(str s,int v){
		int len=strlen(s),cur=0;
		for(int i=0;i<len;i++){
			if(ch[cur][id(s[i])]==0)ch[cur][id(s[i])]=newnode();
			cur=ch[cur][id(s[i])];
		}
		val[cur]=v;
	}
	int search(str s){
		int len=strlen(s),cur=0;
		for(int i=0;i<len;i++){
			if(ch[cur][id(s[i])]==0)return 0;
			cur=ch[cur][id(s[i])];
		}
		return val[cur];
	}
}T;
int d[MAXN+3],n,mn[MN+3],m;
bitset<MN+3> has;
void input(){
	str s;
	cin>>n;
	has=0;
	for(int i=1;i<=n;i++){
		cin>>s;T.insert(s,i);
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>s;d[i]=T.search(s);
		has[d[i]]=1;
	}
	has[0]=0;
	cout<<has.count()<<endl;
}
int getmin(int l,int r){
	int t=INF;
	for(int i=l;i<=r;i++)if(has[i])t=min(mn[i],t);//������i�ַ��������� 
	return t;
}
int ans=INF;
void solve(){
	for(int i=1;i<=n;i++)mn[i]=-INF;
	ans=INF;
	for(int i=1;i<=m;i++){
		if(d[i]==0)continue;
		mn[d[i]]=i;//�ȸ��� 
		int t=getmin(1,n);
		ans=min(i-t+1,ans);
		
		//for(int i=1;i<=n;i++)cout<<mn[i]<<" ";cout<<endl;
	}
}
int main(){
	input();
	solve();
	cout<<ans;
	return 0;
}


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=1000000,INF=0x3f3f3f3f;
const int NS=26;
struct Trie{
	int ch[MAXN+3][NS],cnt[MAXN+3],tot,root;
	void init(){
		tot=0;root=newnode();
	}
	int newnode(){
		cnt[tot]=0;memset(ch[tot],0,sizeof(tot));
		return tot++;
	}
	inline int idx(char c){
		return c-'a';
	}
	void insert(char *s,int len){
		int cur=root;
		for(int i=0;i<len;i++){
			if(ch[cur][idx(s[i])]==0)ch[cur][idx(s[i])]=newnode();
            cur=ch[cur][idx(s[i])];
            cnt[cur]++;
		}
	}
	int query(char *s,int len){
		int cur=root;
		for(int i=0;i<len;i++){
			if(ch[cur][idx(s[i])]==0)return 0;
			cur=ch[cur][idx(s[i])]; 
		}
		return cnt[cur];
	}
}T;
char s[20];
int n,m;
int main(){
    T.init();
    cin>>n;
    while(n--){cin>>s;T.insert(s,strlen(s));}
    cin>>m;
    while(m--){cin>>s;cout<<T.query(s,strlen(s))<<endl;}
    return 0;
}
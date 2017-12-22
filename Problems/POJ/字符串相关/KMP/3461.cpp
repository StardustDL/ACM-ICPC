/*
Oulipo
分析：KMP，但是自己的代码超时了 
*/
/*
#include<cstdio>
#include<cstring>
#define maxn1 (10000+100)
#define maxn2 (1000000+100)
using namespace std;

int p[maxn1],n,m;
char b[maxn1],a[maxn2];
inline void readdata(){
  	b[0]=' ',a[0]=' ';
  	scanf("%s%s",b+1,a+1);
  	p[1]=0;
  	int j=0,i;  m=strlen(b)-1;
	for(i=2;i<=m;i++){
      	while(j>0 && b[j+1]!=b[i])j=p[j];
      	if(b[j+1]==b[i])j++;
      	p[i]=j;
    }
}
inline void work(){
	int j=0,i,ans=0; n=strlen(a)-1;
	for(i=1;i<=n;i++){
		while(j>0 && b[j+1]!=a[i])j=p[j];
		if(b[j+1]==a[i])j++;
		if(j==m){ans++;j=p[j];}
    }
	printf("%d\n",ans);
}
int main(){
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){readdata();work();}
	return 0;
}
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000000;
typedef char charstring[MAXN+3];
int fail[MAXN+3],L;
charstring s,t;
void load(){
	fail[0]=fail[1]=0;
	L=strlen(s);
	for(int i=1;i<L;i++){
		int j=fail[i];
		while(j&&s[i]!=s[j])j=fail[j];
		fail[i+1]=s[i]==s[j]?j+1:0;
	}
}
int kmp(charstring t){
	int len=strlen(t);
	int j=0;
	for(int i=0;i<len;i++){
		while(j&&t[i]!=s[j])j=fail[j];
		j+=t[i]==s[j];
		if(j==L)return i-L+1;
	}
	return -1;
}
int ans,n;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%s%s",s,t);
		//cout<<s<<" "<<t<<endl;
		load();
		int cur=0;
		ans=0;
		while(1){
			int e=kmp(t+cur);
			//cout<<e<<endl;
			//cout<<e<<endl;
			if(e==-1)break;
			ans++;cur+=e+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}


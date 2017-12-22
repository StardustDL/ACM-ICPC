/*
SGU505 Prefixes and suffixes（询问在线版）
分析：Hash+暴力判断
		一个更快的方法对输入串排序，然后对所有串的逆序建立可持久化Trie 
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define M 2000010
#define P 1000000007
using namespace std;
typedef unsigned long long ULL;
string s[2010];
char a[M],b[M];
vector<ULL> l[2010],r[2010];
int n,m,ans;
void hash() {
	for (int i=1; i<=n; i++) {
		ULL x(17),x2(17);int len=s[i].length();
		for (int j=0; j<len; j++) {
			x=x*P+s[i][j];
			l[i].push_back(x);
		}
		for (int j=0; j<len; j++) {
			x2=x2*P+s[i][len-j-1];
			r[i].push_back(x2);
		}
	}
}
int main() {
	scanf("%d",&n);
	for (int i=1; i<=n; i++)cin>>s[i];
	hash();
	scanf("%d",&m);ans=0;
	for (int i=1; i<=m; i++) {
		ULL aa(17),bb(17);
		int len1,len2;
		scanf("%s",a);
		len1=strlen(a);
		for (int j=0; j<len1; j++) a[j]=(a[j]-'a'+ans)%26+'a';
		for (int j=0; j<len1; j++) aa=aa*P+a[j];
		scanf("%s",b);
		len2=strlen(b);
		for (int j=0; j<len2; j++) b[j]=(b[j]-'a'+ans)%26+'a';
		for (int j=0; j<len2; j++) bb=bb*P+b[len2-j-1];
		ans=0;
		for (int j=1; j<=n; j++)
			if (l[j][len1-1]==aa&&r[j][len2-1]==bb) ans++;
		printf("%d\n",ans);
	}
}

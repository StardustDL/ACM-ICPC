/*
STR
分析：首先，这个题如果想要求出从每个位置开始的字串的匹配长度，那么O(n^2)以内的算法应该是很难的。但是，这个题要求的并不是“每个位置的长度”，而是“具有这样长度的位置数”。因而，灵活使用KMP算法自我匹配的性质，就能够解决这个问题。
	  考虑下面的例子：
		A串：abbabbabababbababba
		B串：abbabababba
		应用KMP算法，很容易得到B串的自我匹配是
		元素 a b b a b a b a b b  a
		位置 1 2 3 4 5 6 7 8 9 10 11
		长度 0 0 0 1 2 1 2 1 2 3  4
		这个数组记为kmp[位置] = 匹配长度。
		由此求得到A串的各个元素尾部的匹配长度是
		a b b a b b a b a b a b b  a  b a b b a
		1 2 3 4 5 3 4 5 6 7 8 9 10 11 5 6 7 3 4
		统计出各个长度的出现频数
		长度 0 1 2 3 4 5 6 7 8 9 10 11
		频数 0 1 1 3 3 3 2 2 1 1 1  1
		这个数组记作cnt[长度] = 频数。
		<重点>
		根据KMP自我匹配数组的性质，如果以A串某个元素结尾有一个长度为11的字串可以与B串匹配的话，以该元素结尾的长度为kmp[11] = 4的字串也是可以匹配的。所以说cnt[4] += cnt[11]。也就是说，进行这样的操作
		for (i = N; i >= 1; i--)
		    cnt[kmp[i]] += cnt[i];
		
		之后，cnt[i]中保存的就应该是所有长度为i的匹配字串了。这时cnt数组的状态是
		长度 0  1 2 3 4 5 6 7 8 9 10 11
		频数 19 8 7 4 4 3 2 2 1 1 1  1
		
		然而题中要求的是“长度恰好为i”的子串的个数，也就是这些字串的下一个字符是不能匹配的。然而，cnt数组中存储的cnt[i]，必然包含了cnt[i + 1]及以上的情况。然而这很简单，“长度恰好为i”的字串数量就是cnt[i] - cnt[i + 1]，因为cnt[i]中可以扩展的字串必然都包含于cnt[i + 1]。
		
		时间复杂度O(M + N)。 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=200000,INF=0x3f3f3f3f;
int fail[MAXN+3],L,pt[MAXN+3];
char* str;
void load(char* s){//预处理模式串
	fail[0]=fail[1]=0;
	L=strlen(s);
	for(int i=1;i<L;i++){
		int j=fail[i];
		while(j&&s[i]!=s[j])j=fail[j];
		fail[i+1]=s[i]==s[j]?j+1:0;
	}
	str=s;
}
void kmp(char* t){
	int len=strlen(t),j=0;
	for(int i=0;i<len;i++){
		while(j&&t[i]!=str[j])j=fail[j];
		j+=t[i]==str[j];
		pt[i+1]=j;
		if(j==L)j=fail[j];
	}
}
char S[MAXN+3],T[MAXN+3];
int n,m,k,ans[MAXN+3],x;
int main(){
	cin>>n>>m>>k>>S>>T;
	load(T);
	//for(int i=1;i<=n;i++)cout<<fail[i]<<" ";cout<<endl;
	kmp(S);
	//for(int i=1;i<=n;i++)cout<<pt[i]<<" ";
	//cout<<endl;
	for(int i=1;i<=n;i++)ans[pt[i]]++;
	for(int i=n;i>=1;i--)ans[fail[i]]+=ans[i];//cout<<"!!!"<<endl;
	//for(int i=0;i<=n;i++)cout<<ans[i]<<" ";
	
	while(k--){
		cin>>x;
		cout<<ans[x]-ans[x+1]<<endl;
	}
	return 0;
}


/*
DNA
分析：相当于每个字符有对应字符，求最长回文子串，可以枚举子串中间点，然后向两边尽可能扩展。
	  注意这里不存在一个字符也为回文子串的情况
	  并且注意，不要转成最长公共子串，那样不一定正确，具体内容要继续研究 
	  还有一种O(n)方法：Manacher算法 
*/
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=50000;
typedef char str[MAXN+3];
int n,ans; 
str s;
char getn(char x){
	switch(x){
		case 'A':return 'T';
		case 'G':return 'C';
		case 'T':return 'A';
		case 'C':return 'G'; 
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	cin>>s;
	for(int i=1;i<n;i++){
		int len=0,l=i,r=i+1;
		while(s[l]==getn(s[r]))len++,l--,r++;
		ans=max(ans,len);
	}
	cout<<2*ans;
	return 0;
}

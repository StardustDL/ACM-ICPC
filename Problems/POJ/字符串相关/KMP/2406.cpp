/*
Power Strings
题意：给定一个字符串，让你求出他最多由几个相同的连续子串连接而成。
分析：求出这个字符串的最小周期，然后用总长度/最小周期长度即是解。
	  思考1：把该字符串增长一倍，然后拿原来的字符串做模式，增长后的字符串做主串，用KMP求模式在主串第1个位置（下标为0，包含第一个位置）之后的第一个匹配位置，就是最小周期长度。
	  思考2：由于我们知道next数组中存的是一个位置(假设next[j]的值为k，对应的字符串为M,如果k>0,那么M[0....k-1]和M[j-k.....j-1]是相同的，
	  	并且0...k-1这个序列一定是最长的)，比如a b c a b c d(next值：-1 0 0 0 1 2 3 )，由next[6]=3可知，M[0..2]=M[3..6]，这就找到了循环节，于是我们思考从next数组作为切入点，来找到一种方法来求得循环节的个数。
　　  	看看next数组的一个性质：next始终是从-1开始增加(在变为0之前)。
		这会导致一个有趣的现象：指针回溯的位置，最远都是在一个完整的循环节之后。
		其实由定义也能发现，如果最远回溯到了字符串开头，就会导致j=k,与next数组的定义中的0<k<j矛盾。
		这样，就留出来了一个循环节的长度，如果总长度是这个循环节长度的整数倍，那么循环节的个数就是这个倍数。
		反之，说明这个字符串并不是在不停地循环，而是在某些位置加入了一个或几个不"和谐"的字符，导致指针无法回溯到第一个循环节之后，这样，输出1就可以了。
	  可以这样想：求nxt数组实际上在做自己匹配自己，这样next[n]表示后缀[(n-next[n])..n]与前缀（模式串的）[1..next[n]]的最长匹配长度 
*/
#include<cstdio>
#include<cstring>
using namespace std; 
const int MAXN=1000000;
int nxt[MAXN+3];
char str[MAXN+3];
void getnext(char* str,int len){
	nxt[0]=0;nxt[1]=0;
	for(int i=1;i<len;i++){
		int j=nxt[i];
		while(j&&str[i]!=str[j])j=nxt[j];
		nxt[i+1]=str[i]==str[j]?j+1:0;
	}
}
int main(){
	while(gets(str),str[0]!='.'){
		int len=strlen(str);
		getnext(str,len);
		if(len%(len-nxt[len])==0)printf("%d\n",len/(len-nxt[len]));
		else puts("1");
	}
}

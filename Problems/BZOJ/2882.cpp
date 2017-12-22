/*
工艺
分析：输出最小表示
	  如何计算循环数组的最小表示起点：
	  (1)  利用两个指针i，j。初始化时i指向0, j指向1。
	  (2)  k = 0开始，检验s[i+k] 与 s[j+k] 对应的字符是否相等，如果相等则k++，一直下去，直到找到第一个不同，若k试了一个字符串的长度也没找到不同，则那个位置就是最小表示位置，算法终止并返回。则该过程中，s[i+k] 与 s[j+k]的大小关系，有三种情况：
  		证明的时候假设（i<j）的，无伤大雅 ；
     		(A). s[i+k] > s[j+k]，则i滑动到i+k+1处 --- 即s1[i->i+k]不会是该循环字符串的“最小表示”的前缀。k清零 
			(B). s[i+k] < s[j+k]，则j滑动到j+k+1处，原因同上。k清零
			(C). s[i+k] = s[j+k]，则 k++； if (k == len) 返回结果。 
		    注:这里滑动方式有个小细节，若滑动后i == j，将正在变化的那个指针再+1。直到p1、p2把整个字符串都检验完毕，返回两者中小于 len 的值。 
		i,j 都可能存有ans 两者互相更新，直到有一个更新后超过了len（包括len） 的时候 另一个即为正解，代码中直接取min(i,j)即可 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=300000,INF=0x3f3f3f3f;
int n,a[MAXN+3];
int getmn(){
	int i=0,j=1,k=0;
	while(i<n&&j<n){
		while(k<n&&a[(i+k)%n]==a[(j+k)%n])k++;
		if(k==n)break;
		if(a[(i+k)%n]>a[(j+k)%n])i+=k+1;else j+=k+1;
		if(i==j)j++;
		k=0;
	}
	return min(i,j); 
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int pos=getmn();
	//cout<<pos<<endl;
	printf("%d",a[pos]);
	for(int i=1;i<n;i++){
		printf(" %d",a[(pos+i)%n]);
	}
	return 0;
}


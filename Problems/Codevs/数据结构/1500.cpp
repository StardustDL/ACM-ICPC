/*
后缀排序
*/
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=15000;
int str[MAXN+3];
int wa[MAXN+3],sa[MAXN+3],wb[MAXN+3],wv[MAXN+3],ws[MAXN+3],n;
int height[MAXN+3],rank[MAXN+3];
bool cmp(int *t,int a,int b,int l){
	return t[a]==t[b]&&t[a+l]==t[b+l];
}
void SuffixSort(int* str,int *sa,int n,int m){
	int *x=wa,*y=wb,i,j,p,*t;
	for(i=0;i<m;i++)ws[i]=0;
	for(i=0;i<n;i++)ws[x[i]=str[i]]++;
	for(i=1;i<m;i++)ws[i]+=ws[i-1];
	for(i=n-1;i>=0;i--)sa[--ws[x[i]]]=i;
	for(j=1,p=1;p<n;j<<=1,m=p){
		for(p=0,i=n-j;i<n;i++)y[p++]=i;//将第二关键字超出边界的（值为0），应该在前面 
		for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;//sa[i]-j，将这个第二关键字所对应的第一关健字 
		for(i=0;i<m;i++)ws[i]=0;
		for(i=0;i<n;i++)wv[i]=x[y[i]];//注意这里 
		for(i=0;i<n;i++)ws[wv[i]]++;
		for(i=1;i<m;i++)ws[i]+=ws[i-1];
		for(i=n-1;i>=0;i--)sa[--ws[wv[i]]]=y[i];//注意这里 
		swap(x,y);
		for(p=1,x[sa[0]]=0,i=1;i<n;i++)//x[sa[0]]=0等价于rank[sa[0]]=0，但有不同！ 
			x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;//x:sa对应的排名 
		//rank和x的区别：rank是一一对应，x是多对一，
		//若末尾没有0，令x[sa[0]]=0意味着此程序将认为Suffix(sa[0])的排名应为0，这导致程序排序时认为Suffix(sa[0])和超出边界等价，导致混乱
		//0的意义：字符串中不存在的字符，并且要在排序中认定其小于所有其他字符（利用int的比较，选<Min{字符集}的数即可，注意不要爆了基数排序 
	}
}
int main(){
	scanf("%d\n",&n);
	char c;
	for(int i=1;i<=n;i++){
		scanf("%c",&c);
		str[i]=c-'a'+1;
	}
	str[0]=0;
	SuffixSort(str,sa,n+1,27);
	//cout<<n<<endl; 
	for(int i=1;i<=n;i++)printf("%d\n",sa[i]);
	return 0;
}


/*
最长公共子串
分析：只要将串A串B合并，并在接口处加上一个特殊字符（串A串B中都没有即可）然后跑后缀数组并计算height
	  最后更新ans的时候需要判断 名词 sa[i]<len1&&sa[i-1]>len1||sa[i-1]<len1&&sa[i]>len1即可 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=2*100000;
int str[MAXN+3],sa[MAXN+3],wt[MAXN+3],wa[MAXN+3],wb[MAXN+3],wv[MAXN+3],height[MAXN+3],rank[MAXN+3];
bool cmp(int *t,int a,int b,int l){
	return t[a]==t[b] && t[a+l]==t[b+l];
}
void da(int* str,int* sa,int n,int m){
	int *x=wa,*y=wb,i,j,p;
	for(i=0;i<m;i++)wt[i]=0;
	for(i=0;i<n;i++)wt[x[i]=str[i]]++;
	for(i=1;i<m;i++)wt[i]+=wt[i-1];
	for(i=n-1;i>=0;i--)sa[--wt[x[i]]]=i;
	for(p=1,j=1;p<n;j<<=1,m=p){
		for(p=0,i=n-j;i<n;i++)y[p++]=i;
		for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;
		for(i=0;i<m;i++)wt[i]=0;
		for(i=0;i<n;i++)wt[wv[i]=x[y[i]]]++;
		for(i=1;i<m;i++)wt[i]+=wt[i-1];
		for(i=n-1;i>=0;i--)sa[--wt[wv[i]]]=y[i];
		swap(x,y);
		for(p=1,x[sa[0]]=0,i=1;i<n;i++)
			x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;
	}
}
void calheight(int *str,int n){
	int i,j,k=0;
	for(i=0;i<n;i++)rank[sa[i]]=i;
	for(i=1;i<=n;i++){
		if(k)k--;
		j=sa[rank[i]-1];
		while(str[i+k]==str[j+k])k++;
		height[rank[i]]=k;
		//cout<<k<<endl;
	}
}
char s[MAXN+3],t[MAXN+3];
int main(){
	/*scanf("%s",s);
	for(int i=0;i<strlen(s);i++)str[i]=s[i]-'a'+1;
	str[strlen(s)]=0; 
	da(str,sa,strlen(s)+1,100);
	calheight(str,strlen(s));
	for(int i=0;i<=strlen(s);i++)cout<<sa[i]<<" ";puts("");
	for(int i=0;i<=strlen(s);i++)cout<<height[i]<<" ";*/
	scanf("%s\n%s",s,t);
	//cout<<s<<endl<<t<<endl;
	int len1=strlen(s),len2=strlen(t);
	for(int i=0;i<len1;i++)str[i]=s[i]-'a'+1;
	str[len1+1]=27;
	for(int i=0;i<len2;i++)str[i+len1+1]=t[i]-'a'+1;
	str[len1+len2+1]=0;
	da(str,sa,len1+len2+2,100);//printf("!!!");
	//for(int i=1;i<=len1+len2+1;i++)cout<<sa[i]<<" ";puts(""); 
	calheight(str,len1+len2);
	int ans=0;
	for(int i=1;i<=len1+len2;i++){
		//cout<<(str[i]==0?'0':(char(str[i]+'a'-1)));
		//cout<<height[i]<<" "; 
		if( sa[i]<len1 && sa[i-1]>len1 || sa[i-1]<len1 && sa[i]>len1){
			ans=max(ans,height[i]);
		}
	}
	printf("%d",ans); 
	return 0;
}


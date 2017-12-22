/*
Long Long Message
题意：最长公共字串
分析：只要将串A串B合并，并在接口处加上一个特殊字符（串A串B中都没有即可）然后跑后缀数组并计算height
	  最后更新ans的时候需要判断 sa[i]<len1&&sa[i-1]>len1||sa[i-1]<len1&&sa[i]>len1即可（保证不在一个串里） 
	  height数组计算错了。。。 
*/ 
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=2*100000+50;
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
void calHeight(int *str,int n){
	int i,j,k=0;
	for(i=0;i<=n;i++)rank[sa[i]]=i;
	for(i=0;i<n;i++){
		if(k)k--;
		j=sa[rank[i]-1];
		while(str[i+k]==str[j+k])k++;
		height[rank[i]]=k;
	}
}
char s[MAXN+3],t[MAXN+3];
int main(){
	scanf("%s\n%s",s,t);
	int len1=strlen(s),len2=strlen(t),n=0;
	for(int i=0;i<len1;i++)str[n++]=s[i]-'a'+2;
	str[n++]=28;
	for(int i=0;i<len2;i++)str[n++]=t[i]-'a'+2;
	str[n]=0;
	da(str,sa,n+1,30);
	calHeight(str,n);
	int ans=0;
	for(int i=1;i<=n;i++)
		if((sa[i]<len1 && sa[i-1]>len1)||(sa[i-1]<len1 && sa[i]>len1))
			ans=max(ans,height[i]);
	printf("%d\n",ans);
	return 0;
}
/*void calheight(int *r,int n){            //  求height数组
    int i,j,k=0;
    for(i=1;i<=n;i++) rank[sa[i]]=i;
    for(i=0;i<n;height[rank[i++]]=k)
        for(k?k --:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
}*/
/*int main(){
    int i,k,l1,l2,num[MAXN];
    char str[MAXN];
    scanf("%s",str);
    l1=strlen(str);
    for(k=i=0;i<l1;i++)num[k++]=str[i]-'a'+2;
    num[k++]=1;                       //  相当于论文中的'$'分隔符。
    scanf("%s",str);
    l2=strlen(str);
    for(i=0;i<l2;i++)num[k++]=str[i]-'a'+2;
    int n=l1+l2;
    da(num,sa,n+1,30);
    //calheight(num,n);
    //for(int i=2;i<k;i++)cout<<height[i]<<" ";
    calHeight(num,n);//puts("");
    //for(int i=2;i<k;i++)cout<<height[i]<<" ";
    int ans=0;
    for(i=2;i<k;i++)
        if((sa[i]<l1&&sa[i-1]>l1)||(sa[i-1]<l1&&sa[i]>l1))
            ans=max(ans,height[i]);
    printf("%d\n", ans);
    return 0;
}*/


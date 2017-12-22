/*
Safecracker
题意：输入一个数target 和一个字符串 s，在字符串 s 找出一个由5个字符组成的最大字符串使得v - w^2 + x^3 - y^4 + z^5 = target ； 
分析：排个序+暴力枚举 
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int cmp(int i,int j){return i>j;}
int n,a[15];
bool solve(int len){
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			if(i==j)continue;
			for(int k=0;k<len;k++){
				if(k==i||k==j)continue;
				for(int l=0;l<len;l++){
					if(l==k||l==i||l==j)continue;
					for(int m=0;m<len;m++){
						if(m==l||m==i||m==j||m==k)continue;
						if(a[i]-a[j]*a[j]+a[k]*a[k]*a[k]-a[l]*a[l]*a[l]*a[l]+a[m]*a[m]*a[m]*a[m]*a[m]==n){
							printf("%c%c%c%c%c\n",a[i]+'A'-1,a[j]+'A'-1,a[k]+'A'-1,a[l]+'A'-1,a[m]+'A'-1);
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}
int main(){
    char s[15];
    while(cin>>n>>s){
        if(n==0&&!strcmp(s,"END"))break;
        for(int i=0;s[i]!='\0';i++)a[i]=s[i]-'A'+1;
        sort(a,a+strlen(s),cmp);
        if(!solve(strlen(s)))printf("no solution\n");
    }
    return 0;
}

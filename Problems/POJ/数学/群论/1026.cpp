/*
Cipher
���⣺��һ�����У�a0,a1,a2...an-1���ٸ�һ���ַ�����s0, s1, s2,...,sn-1(���Ȳ������ÿո���)��s[i]��a[i]λ������õ�һ���µĴ����ظ��������k�Σ������Ĵ���
�����������Ե��û��⣬�����ÿ��λ�õĺ�ȱ任���ȣ�ѭ���ڣ���Ȼ��ֱ���𰸣�ֻ���k%len����ģ�⣩ 
	  �������������û���ѭ���ڣ�������TLE 
	  ������������� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=200;
int a[MAXN+3],n,k,cnt[MAXN+3];
char str[MAXN+3],ans[MAXN+3];
void init(){
	memset(cnt,0,sizeof(cnt));
	for(int i=0,t;i<n;i++){
		cnt[i]++;t=a[i];
		while(t!=i){
			cnt[i]++;
			t=a[t];
		}
	}
}
void solve(int k){
	for(int i=0,t,p;i<n;++i){
		p=a[i];
		t=k%cnt[p];
		while(t--)p=a[p];
		ans[p]=str[i];
	}
	ans[n]='\0';
}
int main(){
	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++){scanf("%d",&a[i]);a[i]--;}
		init();
		while(scanf("%d",&k),k){
			getchar();//������getchar��������scanf("\n") 
			gets(str);
			for(int i=strlen(str);i<n;i++)str[i]=' ';
			solve(--k);
			puts(ans);
		}
		puts("");
	}
	return 0;
}


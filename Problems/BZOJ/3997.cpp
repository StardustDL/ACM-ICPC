/*
���⣺����һ������ͼ��ÿ�δ����Ͻǳ�����ֻ�����һ������ߣ���󵽴����½ǣ�ÿ����������;����������������߼��� 
������Dilworth����DAG����С������=��������� 
		��С������ָѡ�����ٵ���(�����ظ�)ʹ��ÿ���㶼������һ������ 
		���������ָ���ļ���ʹ�������������㲻�ɴ� 
		�����������������Ȼ��һ���������㼯�����������㶼������-���ϵĹ�ϵ 
		DPһ����ܳ��� ���Ӷ�O(Tmn) 
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m;
int a[1005][1005];
long long f[1005][1005];
int main(){
	for(int T=read();T;T--){
		n=read();m=read();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)a[i][j]=read();
		for(int i=1;i<=n;i++)
			for(int j=m;j;j--)
				f[i][j]=max(f[i-1][j+1]+a[i][j],max(f[i-1][j],f[i][j+1]));
		printf("%lld\n",f[n][1]);
	}
	return 0;
}

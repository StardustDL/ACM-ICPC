/*
[Poi2010]Intelligence test
�����������ж�һ�������Ƿ�����һ���������У�����O(nm)��
		���ڲ���ֱ�Ӷ���ȷ��λ�ã���ôÿ�����ֽ�vector��ÿ��ѯ�ʣ����δ���ÿ�����֣�����vector�ж��ֳ���Ӧλ�� ��ֻҪÿ�ζ����ҵ�ƥ��ľ��С�
		�����������Թ�= = 
*/
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std; 
const int MAXN=1000000;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
vector<int>	a[MAXN+3];
int b[MAXN+3],p[MAXN+3],n,m;
bool check(){
	int L=read(),now=0;
	for(int i=1;i<=L;i++)p[b[i]=read()]=0;
	for(int i=1;i<=L;i++){
		p[b[i]]=upper_bound(a[b[i]].begin()+p[b[i]],a[b[i]].end(),now)-a[b[i]].begin();
		if(p[b[i]]==a[b[i]].size())return false;
		now=a[b[i]][p[b[i]]];
	}
	return true;
}
int main(){
	m=read();
	for(int i=1;i<=m;i++)a[read()].push_back(i);
	n=read();
	while(n--){
		if(check())puts("TAK");
		else puts("NIE");
	}
	return 0;
}

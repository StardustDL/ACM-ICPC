/*
DNA Sorting
���⣺��DNA���У�������Դ�С�����ȶ�����
������ע��ֻ��4���ַ�������ɨһ�鼴�ɵõ�����ԣ�����ֱ�ӵ�sort��ע��cmp��������i==jӦ����false�����������ȶ����� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXM=100,MAXN=50;
char strs[MAXM+3][MAXN+3];
int n,m,d[MAXM+3],r[MAXM+3];
int get(char* str){
	int la=strlen(str),A,C,G,T,xa=0;
	A=C=G=T=0;
	for(int i=la-1;i>=0;i--){
		switch(str[i]){
			case 'A':A++;break;
			case 'C':xa+=A;C++;break;
			case 'G':xa+=A+C;G++;break;
			case 'T':xa+=A+C+G;T++;break;
		}
	}
	return xa;
}
bool cmp(int i,int j){
	return d[i]<d[j];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){scanf("\n%s",strs[i]);d[i]=get(strs[i]);r[i]=i;}
	sort(r+1,r+m+1,cmp);
	for(int i=1;i<=m;i++)printf("%s\n",strs[r[i]]);
	return 0;
}


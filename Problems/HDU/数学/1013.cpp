/*
Digital Roots
���⣺������ÿ��λ����ӣ����Ƿ�С��10���Ǿ��������������� 
���������Ա�����Ҳ���Ը������½��ۣ�n������k=(n-1)%9+1;
	  ԭ�򣺸���9Ϊѭ����
	  ע����������ֺܴ���Ҫ�ַ������룬�Ƚ��а�λ��ͣ��ټ��� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
char s[MAXN+3];
int main(){
	while(gets(s),s[0]!='0'){
		int n=0; 
		for(int i=0;s[i]!='\0';i++)n+=s[i]-'0';
		printf("%d\n",(n-1)%9+1);
	}
	return 0;
}


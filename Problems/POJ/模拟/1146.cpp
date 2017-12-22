/*
ID Codes
���⣺��һ����Сд��ĸ��ɵ����е���һ������
������ʹ��next_permutation������ע��û�к�̵�������˺�����õ���һ�����У��ж�����һ�����У��ַ�����ȫ���� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=50;
char str[MAXN+3];
int main(){
	while(scanf("%s",str),str[0]!='#'){
		int flag=0,len=strlen(str);
		for(int i=0;i<len-1;i++){
			if(str[i]<str[i+1]){flag=1;break;}
		}
		if(flag){
			next_permutation(str,str+len);
			printf("%s\n",str); 
		}
		else puts("No Successor"); 
	}
	return 0;
}


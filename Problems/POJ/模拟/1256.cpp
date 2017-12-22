/*
Anagram
���⣺���ַ���ȫ���У�ע���ֵ���Ķ��壺'A'<'a'<'B'<'b'<...<'Z'<'z' 
�������Ƚ��ַ�������������ת�����֣�Ȼ�����next_permutation��ע����sort 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=13;
char str[MAXN+3];
int val[MAXN+3];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("\n%s",str);
		int len=strlen(str);
		for(int i=0;i<len;i++){
			if(str[i]<'a')val[i]=(str[i]-'A')<<1;
			else val[i]=((str[i]-'a')<<1)+1;
		}
		sort(val,val+len);//for(int i=0;i<len;i++)printf("%d ",val[i]);puts(""); 
		do{
			for(int i=0;i<len;i++){
				if(val[i]&1)printf("%c",'a'+(val[i]>>1));
				else printf("%c",'A'+(val[i]>>1));
			}
			puts("");
		}while(next_permutation(val,val+len));
	}
	return 0;
}


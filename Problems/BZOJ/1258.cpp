/*
[CQOI2007]������tri
��������һ�������Σ�˳ʱ����߱��1��2��3
	  ����������һλ��4����ôֱ�Ӱ����һλ�ĳ�1��2��3�������
	  ���򣬿��Է�����һ����һ���߰��ź���ͬ���ģ����һλΪ4�������� 
	  	���һλ=��
		  1����2����T..4  2����1����T..1   3����3����T..4 
	  ��ǰö�٣�ʣ�µ�����������һ����T....4����ʽ�����������߻ᰤ�ŵ�ǰ�������μ��ɡ� 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char ch[100];
int n,m,l;
bool f[5];
void out(int x,int d){
    for(int i=0;i<=x;i++)printf("%c",ch[i]);
    printf("%d\n",d);
}
int main(){
    scanf("%s",&ch);
    l=strlen(ch);l--;
	if(ch[l]=='4'){
		for(int i=1;i<=3;i++)out(l-1,i);
        return 0;
	}
	switch(ch[l]-'0'){
		case 1:f[1]=f[3]=1;break;
		case 2:f[2]=f[3]=1;break;
		case 3:f[1]=f[2]=1;break;
	}
	out(l-1,4);// ��lͬ����������
	for(int i=l-1;i>=1;i--){
		switch(ch[i]-'0'){//��iͬ���������� 
			case 1:if(f[2]){out(i-1,4);f[2]=0;}break;
			case 2:if(f[1]){out(i-1,4);f[1]=0;}break;
			case 3:if(f[3]){out(i-1,4);f[3]=0;}break;
		}
	}
	return 0;
}

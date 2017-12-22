/*
�༭��������
���������ⲻ̫����DP�����ǿ��ܻ��뵽����������У�
	  �����ת�Ʒ��̺�LCS�ͺ���
	  opt[i][j]��ʾA[0..i-1]ת����B[0..j-1]�����Ž�
	  ����opt[i][j]=	β�ַ�����ʱ�����ʱopt[i][j]=opt[i-1][j-1] 
	  	min{opt[i-1][j]		Aĩβɾ��һ���ַ� 
	  		,opt[i][j-1]	Aĩβ����һ���ַ� 
			,opt[i-1][j-1]} Aĩβ�ı�һ���ַ�
	   ���о��ǳ�ʼ����
		opt[i=1..strlen(A)][0]=i;
		opt[0][i=1..strlen(B)]=i;
		������A��ת�մ�ΪA�����ȣ��մ�תB��ΪB������ 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=4000;
int opt[MAXN+3][MAXN+3],n;
char sa[MAXN+3],sb[MAXN+3];
int dp(){
	int la=strlen(sa),lb=strlen(sb);
	for(int i=1;i<=la;i++)opt[i][0]=i;
	for(int i=1;i<=lb;i++)opt[0][i]=i;
	for(int i=1;i<=la;i++){
		for(int j=1;j<=lb;j++){
			if(sa[i-1]==sb[j-1])opt[i][j]=opt[i-1][j-1];
			else opt[i][j]=min(min(opt[i-1][j],opt[i][j-1]),opt[i-1][j-1])+1;
		}
	}
	return opt[la][lb];
}
int main(){
	cin>>sa>>sb;
	cout<<dp();
	return 0;
}

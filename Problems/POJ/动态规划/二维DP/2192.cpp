/*
Zipper
���⣺���������ַ���A��B��C���ж�C�ܷ���AB�е��ַ���ɣ�ͬʱ�����Ϻ���ַ�˳�������A��B��ԭ����˳�򣬲����������磺A��mnl��B��xyz�����CΪmnxylz���ͷ������⣻���CΪmxnzly���Ͳ��������⣬ԭ����z��y˳����B��˳��
������DP��dp[i][j]��ʾA��ǰi���ַ���B��ǰj���ַ��Ƿ������C�е�ǰ (i+j) ���ַ�������ܱ��true��������ܱ��false��
	  dp[i][j] = 1 ��� dp[i-1][j] == 1 && C[i+j-1] == A[i-1]
	  dp[i][j] = 1 ��� dp[i][j-1] == 1 && C[i+j-1] == B[j-1]
	  dp[0][0]=1 
 
*/
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=200,INF=0x3f3f3f3f;
const char OUT[2][5]={"no","yes"};
bool can[MAXN+3][MAXN+3];
char a[MAXN+3],b[MAXN+3],c[2*MAXN+3];
int T,la,lb;
int main(){
	scanf("%d",&T);
	for(int k=1;k<=T;k++){
		memset(can,0,sizeof(can));
		scanf("%s %s %s",a,b,c);
		la=strlen(a),lb=strlen(b);
		can[0][0]=1;
		for(int i=0;i<=la;i++)
			for(int j=0;j<=lb;j++)//use |= not =,because = makes can[0][0]=0
				can[i][j]|=(i>0&&can[i-1][j]&&c[i+j-1]==a[i-1])||(j>0&&can[i][j-1]&&c[i+j-1]==b[j-1]);
		printf("Data set %d: %s\n",k,OUT[can[la][lb]]);
	}
	return 0;
}


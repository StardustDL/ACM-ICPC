/*
Zipper
题意：给定三个字符串A，B，C；判断C能否由AB中的字符组成，同时这个组合后的字符顺序必须是A，B中原来的顺序，不能逆序；例如：A：mnl，B：xyz；如果C为mnxylz，就符合题意；如果C为mxnzly，就不符合题意，原因是z与y顺序不是B中顺序。
分析：DP，dp[i][j]表示A中前i个字符与B中前j个字符是否能组成C中的前 (i+j) 个字符，如果能标记true，如果不能标记false；
	  dp[i][j] = 1 如果 dp[i-1][j] == 1 && C[i+j-1] == A[i-1]
	  dp[i][j] = 1 如果 dp[i][j-1] == 1 && C[i+j-1] == B[j-1]
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


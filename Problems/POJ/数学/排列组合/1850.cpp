/*
Code
题意：指定a:1,b:2...aa:27,...,注意一定是升序的串，求指定串的标号
分析：先求出长度为1的（C(26,1)），再求长度为2的（C(26,2)，因为C(m,n)=sigma{C(i,m-1)|i=1..n-1}），...，最后枚举长度等于当前串的 
	  注意：本题只要求输入错误一次就允许结束程序 
*/
#include<iostream>
#include<cstring>
using namespace std;
int c[27][27]={0}; 
//打表，利用杨辉三角计算每一个组合数nCm
void play_table(){
	for(int i=0;i<=26;i++)
		for(int j=0;j<=i;j++)
			if(!j || i==j)c[i][j]=1;
			else c[i][j]=c[i-1][j-1]+c[i-1][j];
	c[0][0]=0;
	return;
}
int main(){
	play_table();
	char str[11];
	while(cin>>str){
		int len=strlen(str);
		for(int i=1;i<len;i++)//检查str是否符合升序排列 
			if(str[i-1]>=str[i]){
				printf("0");
				return 0;
			}
		int sum=0;  //str的值，初始为0
		//计算长度比str小的字符串个数
		for(int i=1;i<len;i++)sum+=c[26][i];//c[26][i]表示 长度为i的字符串的个数
		//计算长度等于len，但值比str小的字符串个数
		for(int i=0;i<len;i++){//i为str的指针，对每一个位置枚举 允许选择的字符ch
			char ch= (!i)?'a':str[i-1]+1;//ch = str[i-1]+1 根据升序规则当前位置的ch至少要比str前一位置的字符大1
			while(ch<=str[i]-1){//ch<=str[i]-1 根据升序规则，当前位置的ch最多只能比 str这个位置实际上的字符 小1
				sum+=c['z'-ch][len-1-i];  //'z'-ch ： 小于等于ch的字符不允许再被选择，所以当前能够选择的字符总数为'z'-ch
				ch++;                     //len-1-i  ： ch位置后面（不包括ch）剩下的位数，就是从'z'-ch选择len-1-i个字符
			}
		}
		printf("%d\n",++sum);// 此前的操作都是寻找比str小的所有字符串的个数，并不包括str本身，因此这里要+1
	}
	return 0;
}

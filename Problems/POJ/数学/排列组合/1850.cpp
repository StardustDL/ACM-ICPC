/*
Code
���⣺ָ��a:1,b:2...aa:27,...,ע��һ��������Ĵ�����ָ�����ı��
���������������Ϊ1�ģ�C(26,1)�������󳤶�Ϊ2�ģ�C(26,2)����ΪC(m,n)=sigma{C(i,m-1)|i=1..n-1}����...�����ö�ٳ��ȵ��ڵ�ǰ���� 
	  ע�⣺����ֻҪ���������һ�ξ������������ 
*/
#include<iostream>
#include<cstring>
using namespace std;
int c[27][27]={0}; 
//�������������Ǽ���ÿһ�������nCm
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
		for(int i=1;i<len;i++)//���str�Ƿ������������ 
			if(str[i-1]>=str[i]){
				printf("0");
				return 0;
			}
		int sum=0;  //str��ֵ����ʼΪ0
		//���㳤�ȱ�strС���ַ�������
		for(int i=1;i<len;i++)sum+=c[26][i];//c[26][i]��ʾ ����Ϊi���ַ����ĸ���
		//���㳤�ȵ���len����ֵ��strС���ַ�������
		for(int i=0;i<len;i++){//iΪstr��ָ�룬��ÿһ��λ��ö�� ����ѡ����ַ�ch
			char ch= (!i)?'a':str[i-1]+1;//ch = str[i-1]+1 �����������ǰλ�õ�ch����Ҫ��strǰһλ�õ��ַ���1
			while(ch<=str[i]-1){//ch<=str[i]-1 ����������򣬵�ǰλ�õ�ch���ֻ�ܱ� str���λ��ʵ���ϵ��ַ� С1
				sum+=c['z'-ch][len-1-i];  //'z'-ch �� С�ڵ���ch���ַ��������ٱ�ѡ�����Ե�ǰ�ܹ�ѡ����ַ�����Ϊ'z'-ch
				ch++;                     //len-1-i  �� chλ�ú��棨������ch��ʣ�µ�λ�������Ǵ�'z'-chѡ��len-1-i���ַ�
			}
		}
		printf("%d\n",++sum);// ��ǰ�Ĳ�������Ѱ�ұ�strС�������ַ����ĸ�������������str�����������Ҫ+1
	}
	return 0;
}

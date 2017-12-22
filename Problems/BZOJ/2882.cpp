/*
����
�����������С��ʾ
	  ��μ���ѭ���������С��ʾ��㣺
	  (1)  ��������ָ��i��j����ʼ��ʱiָ��0, jָ��1��
	  (2)  k = 0��ʼ������s[i+k] �� s[j+k] ��Ӧ���ַ��Ƿ���ȣ���������k++��һֱ��ȥ��ֱ���ҵ���һ����ͬ����k����һ���ַ����ĳ���Ҳû�ҵ���ͬ�����Ǹ�λ�þ�����С��ʾλ�ã��㷨��ֹ�����ء���ù����У�s[i+k] �� s[j+k]�Ĵ�С��ϵ�������������
  		֤����ʱ����裨i<j���ģ����˴��� ��
     		(A). s[i+k] > s[j+k]����i������i+k+1�� --- ��s1[i->i+k]�����Ǹ�ѭ���ַ����ġ���С��ʾ����ǰ׺��k���� 
			(B). s[i+k] < s[j+k]����j������j+k+1����ԭ��ͬ�ϡ�k����
			(C). s[i+k] = s[j+k]���� k++�� if (k == len) ���ؽ���� 
		    ע:���ﻬ����ʽ�и�Сϸ�ڣ���������i == j�������ڱ仯���Ǹ�ָ����+1��ֱ��p1��p2�������ַ�����������ϣ�����������С�� len ��ֵ�� 
		i,j �����ܴ���ans ���߻�����£�ֱ����һ�����º󳬹���len������len�� ��ʱ�� ��һ����Ϊ���⣬������ֱ��ȡmin(i,j)���� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=300000,INF=0x3f3f3f3f;
int n,a[MAXN+3];
int getmn(){
	int i=0,j=1,k=0;
	while(i<n&&j<n){
		while(k<n&&a[(i+k)%n]==a[(j+k)%n])k++;
		if(k==n)break;
		if(a[(i+k)%n]>a[(j+k)%n])i+=k+1;else j+=k+1;
		if(i==j)j++;
		k=0;
	}
	return min(i,j); 
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int pos=getmn();
	//cout<<pos<<endl;
	printf("%d",a[pos]);
	for(int i=1;i<n;i++){
		printf(" %d",a[(pos+i)%n]);
	}
	return 0;
}


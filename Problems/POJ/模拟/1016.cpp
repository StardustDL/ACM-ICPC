/*
Numbers That Count
�����������
	һ����5553141����������2��1��1��3��1��4��3��5�� 
	��ô������д��21131435����5553141��Inventory ���� 
	Ȼ����ĿҪ�󣬸���һ����n( ���80λ)�������Ա��鵽�������ࣺ 
	1��n is self-inventorying��n�ø����Ǹ���������ͬ��  
	���Ը����������������Inventory ��������Ǳ�����������У� 
	���磺31123314��Inventory����Ȼ��31123314�����: 31123314 is self-inventorying  
	2) n is self-inventorying after j steps   
	��һ����������Inventory ����Ȼ���ٶ�����Inventory����������ʵ���ǿ��Եõ�һ�����У�n[0]->n[1]->n[2]��n[j]��. �����������1<=j<=15ʱ�����n[j]��Inventory��������������������У� 
	����: 21221314 -> 31321314 -> (31321314)�����: 21221314 is self-inventorying after 2 steps  
	3) n enters an inventory loop of length k   
	��Ȼ��n������˵��: n[0]->n[1]->n[2]��n[j]��n[i]��. (0<=j<i<=15)����n[i]��Inventory��(����n[k]) ����n[0]��n[i-1]����n[j]ʱ����ô����Ȼ�������»��γ�һ��ѭ�����������Ҫ�ҳ��Ƿ������С(k>=1)ʹ��n���й���ѭ����������k;  
	����: 314213241519 --> 412223241519 -->314213241519����Ӧ������n[j] --> n[i] -> (n[k])   
	4) n can not be classified after 15 iterations  
	������ҳ�15������û�������������κ�һ������ô��������У� 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;
string change(string s){
	string output="";
	int len=s.length(),count[10]={};
	for(int i=0;i<len;i++)count[s[i]-'0']++;
	for(int i=0;i<10;i++){
		if(count[i]>0){
			char temp[33];
			sprintf(temp,"%d",count[i]);
			output+=temp;
			output+=char('0'+i);
		}
	}
	return output;
}
int main(){
	string str[16];
	while(cin>>str[0]){
		if(str[0]=="-1")break;
		bool flag=false;
		for(int i=1;i<=15;i++){
			str[i]=change(str[i-1]);
			int m;
			for(m=0;m<i;m++){
				if(str[m]==str[i]){
					flag=true;break;
				}
			}
			if(m==i-1){
				if(m==0)cout<<str[0]<<" is self-inventorying "<<endl;
				else cout<<str[0]<<" is self-inventorying after "<<i-1<<" steps "<<endl;
			}
			else if(m<i-1)cout<<str[0]<<" enters an inventory loop of length "<<i-m<<" "<<endl;
			if(flag)break;
		}
		if(!flag)cout<<str[0]<<" can not be classified after 15 iterations"<<endl;
	}	
	return 0;
}


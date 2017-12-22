/*
Numbers That Count
题意与分析：
	一个数5553141：他包含了2个1，1个3，1个4，3个5； 
	那么和起来写：21131435就是5553141的Inventory 数； 
	然后题目要求，给出一个数n( 最多80位)，他可以被归到如下四类： 
	1）n is self-inventorying（n用给出那个数代，下同）  
	即对给出的数，求出他的Inventory 数，如果是本身，则输出该行； 
	例如：31123314的Inventory数仍然是31123314，输出: 31123314 is self-inventorying  
	2) n is self-inventorying after j steps   
	对一个数求他的Inventory 数，然后再对他的Inventory数继续求，如实我们可以得到一个序列：n[0]->n[1]->n[2]…n[j]…. 如此往复，当1<=j<=15时。如果n[j]的Inventory数等于他本身，则输出该行； 
	例如: 21221314 -> 31321314 -> (31321314)，输出: 21221314 is self-inventorying after 2 steps  
	3) n enters an inventory loop of length k   
	仍然用n的序列说明: n[0]->n[1]->n[2]…n[j]…n[i]…. (0<=j<i<=15)，当n[i]的Inventory数(记作n[k]) 等于n[0]…n[i-1]的中n[j]时，那么很显然，再求下会形成一个循环；因此我们要找出是否存在最小(k>=1)使得n序列够成循环，输出这个k;  
	例如: 314213241519 --> 412223241519 -->314213241519，对应上述的n[j] --> n[i] -> (n[k])   
	4) n can not be classified after 15 iterations  
	如果在找出15个数后，没有满足上述的任何一条，那么就输出该行； 
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


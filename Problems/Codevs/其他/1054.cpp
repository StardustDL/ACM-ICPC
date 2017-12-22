/*
µçÌİ
*/
#define up 6
#define down 4
#define stop 5
#include<iostream>
using namespace std;
int sum=0,cur=0,k;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k;
		if(k>cur)sum+=(k-cur)*up+stop;
		else if(k<cur)sum+=(cur-k)*down+stop;
		cur=k;
	}
	cout<<sum;
	return 0;
}

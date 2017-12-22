/*
求合数和
*/
#include<iostream>
using namespace std;
bool a[1001];
int main(){
	int n,i,j,sum=0;
	cin>>n;
	for(i=1;i<=n;i++)a[i]=true;
	for(i=2;i<=n;i++){
		if(a[i]){
			j=i+i;
			while(j<=n){
				a[j]=false;j=j+i;
			}
		}
	}
	for(i=2;i<=n;i++)
		if(!a[i])sum+=i;
	cout<<sum;
    return 0;
}

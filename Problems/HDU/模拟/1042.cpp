/*
N!
���⣺��N!
�������߾��� 
*/
#include<iostream>
using namespace std;
const int MAXN=100000; 
int n,a[MAXN];
int main(){
    int k,count,temp;
    while(~scanf("%d",&n)){
        a[0]=1;
        count=1;
        for(int i=1;i<=n;i++){
            k=0;
			for(int j=0;j<count;j++){
                temp=a[j]*i+k;
                a[j]=temp%10;
                k=temp/10;
            }
            while(k){//��¼��λ
                a[count++]=k%10;
                k/=10;
            }
        } 
        for(int i=count-1;i>=0;i--)printf("%d",a[i]);
        puts("");
    }
    return 0;
}

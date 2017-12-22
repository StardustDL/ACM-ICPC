/*
连续整数和
*/
#include<cstdio>
using namespace std;
int main(){
    int n,k,i,a;
    scanf("%d %d",&n,&k);
    a=(2*n+k-k*k)/(2*k);
    printf("%d",a);
    for(i=1;i<k;i++)
        printf(" %d",++a);
    return 0;
}

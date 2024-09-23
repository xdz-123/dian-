#include <stdio.h>

int main()
{

    char sort[4];
    int lanes,unit_price,number;//通道，单价，个数
    scanf("%s",&sort);
    scanf("%d%d%d",&lanes,&unit_price,&number);
    printf("%d: ",lanes);
    for(int i=1;i<=number;i++) printf("%c",sort[0]);
    printf(" %d\n",unit_price);
    return 0;
}
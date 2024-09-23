#include <stdio.h>

int main()
{
    int total_price;//总价
    int coin,total_amount=0;//投币，总金额
    scanf("%d",&total_price);
    while(1)
    {
        scanf("%d",&coin);
        total_amount+=coin;
        if(total_amount>=total_price) break;
    }
    printf("%d\n",total_amount-total_price);
    return 0;
}
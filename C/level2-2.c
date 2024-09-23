#include <stdio.h>

int main()
{
    int lanes_number[6];//各通道货物数量
    int lanes_unit_price[6];//各通道单价
    char goods_kind[6];//各通道货物种类

    char sort[4];
    int lanes,unit_price,number;//通道，单价，个数

    int total_price;//总价

    int coin,total_amount;//投币，总金额

    int back_number[4],back_lanes[4];//回退个数，回退通道
    while(1)//存货
    {
        scanf("%s",&sort);
        if(sort[0]=='E'&&sort[1]=='N') break;
        scanf("%d%d%d",&lanes,&unit_price,&number);
        lanes_number[lanes]+=number;
        goods_kind[lanes]=sort[0];
        lanes_unit_price[lanes]=unit_price;
    }
    while(1)
    {
        back_lanes[1]=0;
        total_price=0;
        total_amount=0;
        while(1)//购买
        {
            scanf("%s",&sort);
            if(sort[0]=='E'&&sort[1]=='N') break;
            if(sort[0]=='b'&&sort[1]=='a')//输入back回退
            {
                if(back_lanes[1]==0)
                {
                    printf("无法回退，请重新输入\n");
                    continue;
                }
                total_price-=lanes_unit_price[back_lanes[1]]*back_number[1];
                lanes_number[back_lanes[1]]+=back_number[1];
                back_lanes[1]=back_lanes[2];
                back_lanes[2]=back_lanes[3];
                back_number[1]=back_number[2];
                back_number[2]=back_number[3];
                continue;
            } 
            scanf("%d%d",&lanes,&number);
            if(lanes>5||lanes<1)
            {
                printf("没有该通道，请重新输入\n");
                continue;
            }
            if(sort[0]!=goods_kind[lanes])
            {
                printf("该通道不售卖此类物品，请重新输入\n");
                continue;
            }
            if(number>lanes_number[lanes])
            {
                printf("该通道此类物品不足，请重新输入\n");
                continue;
            }
            back_lanes[3]=back_lanes[2];
            back_lanes[2]=back_lanes[1];
            back_lanes[1]=lanes;
            back_number[3]=back_number[2];
            back_number[2]=back_number[1];
            back_number[1]=number;
            total_price+=number*lanes_unit_price[lanes];
            lanes_number[lanes]-=number;
        }
        
        while(1)//投币
        {
            scanf("%d",&coin);
            total_amount+=coin;
            if(total_amount>=total_price) break;
        }
        printf("%d",total_amount-total_price);
    }
    return 0;
}
#include <stdio.h>

#define M 50005 /*�ռ�Ҫ�㹻��*/


struct node

{

    int l,r,c;

};


int total,times,data[M];

struct node arr[M*3];  /*���ڵ�*/


int Construct(int l,int r,int k)  /*�����߶���*/

{

    int mid;

    if(l==r)

    {

        arr[k].l=arr[k].r=r;

        return arr[k].c=data[l];

    }

    mid=(l+r)/2;

    arr[k].l=l;

    arr[k].r=r;

    return (arr[k].c=Construct(l,mid,2*k)+Construct(mid+1,r,2*k+1));

}



void Deal(int l,int r,int k,int loc,int num)   /*��ǰ�ڵ�locȨֵ��num �ӵ�ʱ��numΪ��ֵ������ʱ��numΪ����*/

{

    int mid;

    if(arr[k].l==arr[k].r&&arr[k].l==loc)   /*�ҵ�Ҫ���µĽڵ�*/



    {

        arr[k].c=arr[k].c+num;    /*Ȩֵ��num*/

        return;

    }

     mid=(l+r)/2;



    arr[k].c+=num;  /*k������Ҫ�ҵĽڵ㣬��ôҪ�ҵ�Ӧ�������������ϣ���������ȨֵҲҪ����num*/





    if(loc<=mid)  /*��Ҫ�ҵĽڵ㣬�����*/

    {

        Deal(l,mid,2*k,loc,num);

    }

    else

    {

        Deal(mid+1,r,2*k+1,loc,num);


    }

}



int Query(int l,int r,int k)

{

    int mid;

    if(arr[k].l==l&&arr[k].r==r)

    {

        return arr[k].c;

    }

    mid=(arr[k].l+arr[k].r)/2;

    if(r<=mid)

    {

        return Query(l,r,2*k);


    }

    else if(l>mid)

    {

        return Query(l,r,2*k+1);

    }

    else

    {

        return Query(l,mid,2*k)+Query(mid+1,r,2*k+1);

    }


}




int main()

{

    int m,n,i, count=0;

    scanf("%d",&times);

    while(times--)

    {

        printf("Case %d:\n",++count);

        scanf("%d",&total);

        for(i=1;i<=total;i++)

        {

            scanf("%d",&data[i]);

        }

        Construct(1,total,1);

        while(1)

        {

            char temp[10];

            scanf("%s",temp);

            if(temp[0]=='E')

                break;



            scanf("%d%d",&m,&n);

            if(temp[0]=='Q')

            {

                printf("%d\n",Query(m,n,1));


            }

            else if(temp[0]=='A')

                Deal(1,total,1,m,n);

            else if(temp[0]=='S')

                Deal(1,total,1,m,-n);

        }

    }

return 0;

}

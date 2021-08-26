#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct mynode
{
    char item_name[50];
    float price;
    int stock,quantity;
    int mm[2],dd[2],yy[2];
    struct mynode *left;
    struct mynode *right;
}node;
node* find(char name[],node *t)
{
if (t==NULL)
return NULL;
if(strcmp(name,t->item_name)<0)
return find(name,t->left);
else if(strcmp(name,t->item_name)>0)
return find(name,t->right);
else
return t;
}
node* insert(char name[],float cost,int stock,int mm[2],int dd[2],int yy[2],node *t)
{
if(t==NULL)
{
t=(node*)malloc(sizeof(node));
strcpy(t->item_name,name);
t->price=cost;
t->stock=stock;
t->mm[0]=mm[0];t->mm[1]=mm[1];
t->dd[0]=dd[0];t->dd[1]=dd[1];
t->yy[0]=yy[0];t->yy[1]=yy[1];
t->left=t->right=NULL;
printf("\nThe Item has been successfully added");

}
else if(strcmp(name,t->item_name)<0)
t->left=insert(name,cost,stock,mm,dd,yy,t->left);
else if(strcmp(name,t->item_name)>0)
t->right=insert(name,cost,stock,mm,dd,yy,t->right);
return t;
}
node* insert1(char name[],float cost,int stock,int quantity,int mm[2],int dd[2],int yy[2],node *t)
{
if(t==NULL)
{
t=(node*)malloc(sizeof(node));
strcpy(t->item_name,name);
t->price=cost;
t->stock=stock;
t->quantity=quantity;
t->mm[0]=mm[0];t->mm[1]=mm[1];
t->dd[0]=dd[0];t->dd[1]=dd[1];
t->yy[0]=yy[0];t->yy[1]=yy[1];
t->left=t->right=NULL;
printf("The Item has been successfully added\n\n");

}
else if(strcmp(name,t->item_name)<0)
t->left=insert1(name,cost,stock,quantity,mm,dd,yy,t->left);
else if(strcmp(name,t->item_name)>0)
t->right=insert1(name,cost,stock,quantity,mm,dd,yy,t->right);
return t;
}
void inorder(node *t)
{
    if(t!=NULL){
    inorder(t->left);
        printf("\n");
        printf("Item name                      :%s\n",t->item_name);
        printf("The price                      :%f\n",t->price);
        printf("The stock                      :%d\n",t->stock);
        printf("Date of manufacture            :%d / %d / %d\n",t->dd[0],t->mm[0],t->yy[0]);
        printf("Date of expiry                 :%d / %d / %d\n",t->dd[1],t->mm[1],t->yy[1]);
        printf("________________________________________________________________________");
        inorder(t->right);
    }
}
void inorder1(node *t)
{
    if(t!=NULL){
        inorder1(t->left);
        printf("________________________________________________________________________");
        printf("\nItem name                      :%s\n",t->item_name);
        printf("The price                      :%f\n",t->price);
        printf("The quantity                   :%d\n",t->quantity);
        printf("Date of manufacture            :%d / %d / %d\n",t->dd[0],t->mm[0],t->yy[0]);
        printf("Date of expiry                 :%d / %d / %d\n",t->dd[1],t->mm[1],t->yy[1]);
        printf("________________________________________________________________________");
        inorder1(t->right);
    }
}
float total=0.0;
float calculateBILL(node *t)
{
     if(t!=NULL)
     {
         calculateBILL(t->left);
         printf("%s\t%f\t%d\t%f\n",t->item_name,t->price,t->quantity,(t->price*t->quantity));
         total+=(t->price*t->quantity);
         calculateBILL(t->right);
     }
    return total;
}
int main()
{
    node *t=NULL;
    node *t1=NULL;
    int choice;
    char name[50];
    float price;int stock;
    int mm[2],dd[2],yy[2];
    printf("**********************************************\n");
    printf("            online department store       \n");
    printf("**********************************************\n");
    do{
            printf("\n\n__________________________________________\n");
             printf("1.add an item\n2.list all items\n3.search for specific item\n4.buy items\n5.Bill\n");
            printf("____________________________________________");

          printf("\n\nenter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:{
                printf("enter name                              :");scanf("%s",name);
                printf("enter price                             :");scanf("%f",&price);
                printf("enter the stock                         :");scanf("%d",&stock);
                printf("enter the date of manufacture(dd mm yy) :");scanf("%d %d %d",&dd[0],&mm[0],&yy[0]);
                printf("enter the date of expiry(dd mm yy)      :");scanf("%d %d %d",&dd[1],&mm[1],&yy[1]);
                t=insert(name,price,stock,mm,dd,yy,t);
                }break;
            case 2:{
                printf("**************************************");
                printf("      The list of items available     ");
                printf("**************************************");
                inorder(t);break;
            }
            case 3:{
                char name[50];
                printf("\nenter the item to search ");
                scanf("%s",name);
                printf("\n");
                node *p=find(name,t);
                if(p!=NULL){
                printf("Item name                      :%s\n",p->item_name);
                printf("The price                      :%f\n",p->price);
                printf("The stock                      :%d\n",p->stock);
                printf("Date of manufacture            :%d / %d / %d\n",p->dd[0],p->mm[0],p->yy[0]);
                printf("Date of expiry                 :%d / %d / %d\n",p->dd[1],p->mm[1],p->yy[1]);}
                else
                {
                    printf("The item is not available\n");

                }
            }break;
            case 4:{
                int n;char item[50];
                int ch;int opt;
                printf("enter no of items you want to buy\n");
                scanf("%d",&n);
                for(int i=0;i<n;i++)
                {
                   a: printf("\nenter the item %d you want to buy\n",i+1);
                    scanf("%s",item);
                    node *p=find(item,t);
                    if(p!=NULL)
                    {
                        printf("The item name                  :%s\n",p->item_name);
                        printf("The price                      :%f\n",p->price);
                        printf("The stock                      :%d\n",p->stock);
                        printf("Date of manufacture            :%d / %d / %d\n",t->dd[0],t->mm[0],t->yy[0]);
                        printf("Date of expiry                 :%d / %d / %d\n\n",t->dd[1],t->mm[1],t->yy[1]);
                        printf("The item is available \n\n");
                        printf("Enter the quantity                                :");
                        scanf("%d",&(p->quantity));
                        if(p->quantity>p->stock)
                        {
                            printf("The stock is not available\n");
                            printf("\nThe stock available for %s is only %d\n",p->item_name,p->stock);
                            printf("\nEnter a valid quantity you want to buy                     :");
                            scanf("%d",&(p->quantity));
                             t1=insert1(p->item_name,p->price,p->stock,p->quantity,p->mm,p->dd,p->yy,t1);
                             p->stock=p->stock-p->quantity;
                             printf("\nThe item has been bought\n\n");
                        }
                        else
                        {

                                t1=insert1(p->item_name,p->price,p->stock,p->quantity,p->mm,p->dd,p->yy,t1);
                                p->stock=p->stock-p->quantity;
                                printf("\nThe item has been bought\n\n");


                        }

                    }
                    else
                    {
                        printf("The item is not available\n");
                        printf("\nDo you want to buy any other item(press 1 for yes)\n");
                        scanf("%d",&opt);
                        if(opt==1)
                        {
                            goto a;

                        }

                    }

                }
                 printf("\nThe list of bought items\n");
                    inorder1(t1);


            }break;
            case 5:{
                    printf("********************************");
                    printf("        CUSTOMER BILL          ");
                    printf("*******************************\n\n");
                    printf("ITEM NAME\tPRICE\tQUANTITY\tTOTAL\n");
                    float total=calculateBILL(t1);
                      printf("\n\n");
                    printf("The Total   :%f",total);

            }
            default:exit(0);

        }
    }while(choice==1||choice==2||choice==3||choice==4||choice==5);
    return 0;
}

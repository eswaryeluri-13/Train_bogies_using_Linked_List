#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char data[10];
    struct node *next;
};
int i,trainno;
char coach[10];

struct node *createlist();
struct node *insertatbegin(struct node *head);
struct node *insertatend(struct node *head);
struct node *insertkth(struct node*head);
struct node *delbegin(struct node *head);
struct node *delend(struct node *head);
struct node *delselect(struct node *head);
void display(struct node*);
int search(struct node*);

int main()
{
    struct node *head;
    int num;
    printf("*******welcome to train simulation*******\n");
    printf("You can see the sequence and position of coaches. \n");
    printf("Enter train no :");
    scanf("%d",&trainno);
    head=createlist();

    while(1)
    {
        printf("**********************************************************************************************************************\n");
        printf("\t\t\t 1 - insert the coach at beginning\n");
        printf("\t\t\t 2 - insert the coach at end\n");
        printf("\t\t\t 3 - insert after selected coach\n");
        printf("\t\t\t 4 - delete the coach at beginning\n");
        printf("\t\t\t 5 - delete the coach at end\n");
        printf("\t\t\t 6 - delete the selected coach\n");
        printf("\t\t\t 7 - display the train\n");
        printf("\t\t\t 0 - exit\n");

        printf("\tenter your choice :");
        scanf("%d",&num);
        switch(num)
        {
            case 1:head=insertatbegin(head);break;
            case 2:head=insertatend(head);break;
            case 3:head=insertkth(head);break;
            case 4:head=delbegin(head);break;
            case 5:head=delend(head);break;
            case 6:head=delselect(head);break;
            case 7:display(head);break;
            case 0:return 0;
            default:printf("Invalid number . please enter again.\n");break;
        }
    }
}

struct node *createlist()
{
    struct node *head=NULL,*p;
    int n,i;
    printf("enter number of coaches :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            head=(struct node*)malloc(sizeof(struct node));
            p=head;
        }
        else
        {
            p->next=(struct node*)malloc(sizeof(struct node));
            p=p->next;
        }
        printf("coach %d :",i+1);
        scanf("%s",&p->data);
        p->next=NULL;
    }
    return head;
}

void display(struct node *head)
{
    struct node *p;
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    printf("TRAIN :\t\t %d ",trainno);
    for(p=head;p!=NULL;p=p->next)
    {
        printf("<----  %s  ",p->data);
    }
    printf("\n\n------------------------------------------------------------------------------------------------------------------------\n");
}

int search(struct node *head)//position 
{
    struct node *p;
    int n,key,i=0;
    printf("enter the coach name :");
    scanf("%s",&coach);
    for(p=head;p!=NULL;p=p->next)
    {
        if(strcmp(p->data,coach)==0)
        {
            return i+1;//position
        }
        else
        {
            i++;//position
        }
    }

}

struct node *insertatbegin(struct node *head)
{
    struct node *newnode,*p;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter coach name to add :");
    scanf("%s",&newnode->data);
    newnode->next=head;
    head=newnode;
    return head;
}
struct node *insertatend(struct node *head)
{
    struct node *newnode,*p;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the coach name to add at end :");
    scanf("%s",&newnode->data);
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
    }
    p->next=newnode;
    return head;
}
struct node *insertkth(struct node*head)
{
    struct node *newnode,*p;
    int k,i=1,c;
    p=head;

    k=search(head);//position 
  //  printf("k=%d\n",k);

   /* while(p->next!=NULL || c!=k)
    {
        p=p->next;
        c=c+1;
    }*/
    if(k==0)
    {
        printf("Given coach is not found in the train.please check it again \n");
        return head;
    }
    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the new coach(number) to add :");
        scanf("%s",&newnode->data);
        while(i<k)//traveses until the position 
        {
            p=p->next;
            i++;
        }
        newnode->next=p->next;
        p->next=newnode;
        return head;
    }

    /*for(i=0;i<k-1;i++)
    {
        p=p->next;
    }*/

}
struct node *delbegin(struct node *head)
{
    if(head==NULL)
    {
        printf("There are no coaches to delete.\n");
        printf("Train is empty\n");
        return head;
    }
    else
    {
        head=head->next;
        return head;
    }
}
struct node *delend(struct node *head)
{
    struct node *p=head;
    if(head==NULL)
    {
        printf("There are no coaches to delete.\n");
        printf("Train is empty\n");
        return head;
    }
    else
    {
        while(p->next->next!=NULL)//accessing last but one node
        {
            p=p->next;
        }
        p->next=NULL;
        return head;
    }

}
struct node *delselect(struct node *head)
{
    struct node *temp,*nextnode,*p;
    char co[10];
    int k,i=1;
    p=head;
    /*printf("enter the coach to delete :");
    scanf("%s",&co);*/
    k=search(head);
    if(k==0)
    {
        printf("Given coach is not found in the train.please check it again \n");
        return head;
    }
    else
    {
        while(i<k-1)
        {
            p=p->next;
            i++;
        }
        nextnode=p->next;
        p->next=nextnode->next;
        return head;
    }
}










    /*while(i<k-1)
    {
        p=p->next;
        i++;
    }
    nextnode=p->next;
    p->next=nextnode->next;

    return (head);*/

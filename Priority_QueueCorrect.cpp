# include<stdio.h>
# include<stdlib.h>

struct node 
{
	int priority;
	int info;
	struct node *nxt;
}*front = NULL;

void insert(int item,int priority);
int isEmpty();
int del();
void display();

int main()
{
	int ch,prio,item;
	
	while(1)
	{
		printf(" 1.Insert \n 2.Delete \n 3.Display \n 4.Quit\n\n");
		printf("Enter Your Choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1 : printf("\n\nEnter the item to be added ");
			         scanf("%d",&item);
			         printf("\nEnter the Priority : ");
			         scanf("%d",&prio);
			         insert(item,prio);
			         break;
			         
			case 2 : printf("Item Deleted is : %d\n",del());
			         break;
			         
			case 3 : display();
			         break;
			         
			case 4 : exit(1);
			
		}
	}
	
	return 0;
}


void insert(int item,int prio)
{
	struct node *tmp,*p;
	
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info = item;
	tmp->priority = prio;
	
	if(isEmpty() || prio < front->priority)
	{
		tmp->nxt = front;
		front = tmp;
	}
	else
	{
		p = front;
		
		while(p->nxt!=NULL && prio > p->nxt->priority)
		{
			p = p->nxt;
		}
		tmp->nxt = p->nxt;
		p->nxt = tmp;
	}
}

int del()
{
	struct node *tmp;
	int item;
	if(isEmpty())
	{
		printf("Queue Empty\n");
		exit(1);
	}
	else
	{
		tmp = front;
		front = front->nxt;
		item = tmp->info;
		free(tmp);
	}
	return item;
}


int isEmpty()
{
	if(front==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void display()
{
	struct node *tmp;
	tmp = front;
	
	if(isEmpty())
	{
		printf("Empty Queue\n");
	}
	else
	{
		while(tmp->nxt!=NULL)
	    {
	    	printf("Content : %d  Priority : %d \n",tmp->info,tmp->priority);
		    tmp = tmp->nxt;
	    }
	    printf("Content : %d  Priority : %d \n",tmp->info,tmp->priority);
	}
}


# include<stdio.h>
# include<conio.h>
# define max 10

int front,rear;
int value,N,skips,Killed;
int i,j,k;
int Circular_Queue[max] = {0};
void enQueue();
int deQueue();

int main()
{
	rear = -1;
	front = -1;
	
	printf("Enter the Total No. Of Soldiers : ");
	scanf("%d",&N);
	
	printf("Enter the Soldier Numbers Now : \n\n");
	for(i=0;i<N;i++)
	{
		printf("Enter the value of the %d Soldier : ",i+1);
		scanf("%d",&value);
		enQueue();
		printf("\n");
	}
	
	printf("The Queue After Adding Soldiers : ");
	for(k=0;k<max;k++)
	{
		printf("%d ",Circular_Queue[k]);
	}
	printf("\n\n");
	
	printf(">> Now Checking for the Soldier that lives >>\n\n");
	printf("Enter the Number of skips : ");
	scanf("%d",&skips);
	
	for(j=0;j<N;j++)
	{
		Killed = deQueue();
	    printf("\nThe Soldier Killed is : %d",Killed);
	}
	return 0;
}

void enQueue()
{
	if(front==(rear+1) % max)
	{
		printf("Circular Queue is Full\n");
	}
	else
	{
		if(rear==-1)
		{
			rear = 0;
			front = 0;
			Circular_Queue[rear] = value;
		}
		else
		{
			rear = (rear + 1) % max;
			Circular_Queue[rear] = value;
		}
	}
}

int deQueue()
{
	int x;
	if(front==-1)
	{
		printf("The Circular Queue is Empty\n");
	}
	else
	{
		if(front==0)
		{
			front = (front + skips) % max;
			x = Circular_Queue[front];
			Circular_Queue[front] = 0;
		}
		else if(front==rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
			front = (front + skips) % max;
			if(Circular_Queue[front]==0)
			{
			while(Circular_Queue[front]==0)
	        {
		        front = (front + 1) % max;
		        if(Circular_Queue[front]!=0)
		        {
			        x = Circular_Queue[front];
		        }
		        else
		        {
			        front = (front + 1) % max;
			        x = Circular_Queue[front];
		        }
	        }
	        }
	        else
	        {
	        	x = Circular_Queue[front];
			    Circular_Queue[front] = 0;
			}
		}
	}
	
	return x;
}

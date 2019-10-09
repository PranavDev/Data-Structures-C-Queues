// Q) Write a program to implement circular double ended queue where user can add and remove the elements from both front and rear of the queue.


# include<stdio.h>
# include<conio.h>
# define max 20

//Global Declaration

int front,rear;                                
int value,i,j,l,N,ch1;
char ch2,ch;
int Circular_Queue[max] = {0};
int deQueue_Front();
int deQueue_Rear();
void enQueue_Rear();
void enQueue_Front();
void display();

//main opens

int main()
{
	rear = -1;
	front = -1;
	printf(">>> Implementing Circular Double Ended Queue >>>\n\n");
	printf("Enter the Total number of Inputs : ");
	scanf("%d",&N);
	printf("\n\n");
	
	printf("We Set The Queue to be 0 Initially\n\n");
	
	do //For Continuing the Choice Again
	{
		printf("\n 1. Input From Front\n");
		printf("\n 2. Input From Rear\n");
		printf("\n 3. Output From Front\n");
		printf("\n 4. Output Front Rear\n\n");
		
		printf("Enter Your Choice : ");
		scanf("%d",&ch1);
		printf("\n\n");
		
		do //for repeating the same operation again
		{
			switch(ch1)
		    {
		    	case 1 : printf("You Have Selected To Input From Front\n\n");
			         for(j=0;j<N;j++)
			         {
			         	printf("Enter the Number to be Added to Queue : ");
			         	scanf("%d",&value);
			         	enQueue_Front();
			         	printf("\n");
					 }
					 printf("The Queue After Input from Front : ");
					 display();
					 printf("\nDo you want to do the same operation again (Y/N) : ");
		             ch = getch();
					 break;
					 
			    case 2 : printf("You Have Selected To Input From Rear\n\n");
			         for(j=0;j<N;j++)
			         {
			         	printf("Enter the Number to be Added to Queue : ");
			         	scanf("%d",&value);
			         	enQueue_Rear();
			         	printf("\n");
					 }
					 printf("The Queue After Input from Rear : ");
					 display();
					 printf("\nDo you want to do the same operation again (Y/N) : ");
		             ch = getch();
					 break;
					 
			    case 3 : printf("You Have Selected To Output From Front\n\n");
			         int a;
			         for(j=0;j<N;j++)
			         {
			         	a = deQueue_Front();
			         	printf("\nThe Element removed is : %d",a);
					 }
					 printf("\n");
					 printf("The Queue After Output from Front : ");
					 display();
					 printf("\nDo you want to do the same operation again (Y/N) : ");
		             ch = getch();
					 break;
					 
		     	case 4 : printf("You Have Selected To Output From Rear\n\n");
			         int b;
			         for(j=0;j<N;j++)
			         {
			         	b = deQueue_Rear();
			         	printf("\nThe Element removed is : %d",b);
					 }
					 printf("\n");
					 printf("The Queue After Output from Rear : ");
					 display();
					 printf("\nDo you want to do the same operation again (Y/N) : ");
		             ch = getch();
					 break;
					 
			    default : printf("You Have Entered A Wrong Choice\n");
			          break;
			          
		    }//switch closes
		    
		} while(ch=='Y'||ch=='y'); //internal d0-while closes
		
		printf("\n\n Do you wish to continue (Y/N) : ");
		ch2 = getch();
		
	} while(ch2=='Y' || ch2=='y'); //external do-while closes
	
	return 0;
}  
//main closes


//Function for Adding Elements from Rear
void enQueue_Rear()
{
	if(front==(rear+1) % max)
	{
		printf("The Circular Queue is Full And Cannot Enqueue\n");
	}
	else
	{
		if(rear==-1)
		{
			//front = 0;
			rear = 0;
			if(Circular_Queue[rear]==0)
			{
				Circular_Queue[rear] = value;
		    }
		    else
		    {
		    	rear = (rear + 1) % max;
		    	Circular_Queue[rear] = value;
			}
		}
		else
		{
			rear = (rear + 1) % max;
            Circular_Queue[rear] = value;
		}
	}
} 
//Closing of Function Enqueue from Rear



//Function for Adding the Elements from Front
void enQueue_Front()
{
	if(rear==(front + 1 ) % max)
	{
		printf("The Circular Queue is Full And Cannot Enqueue\n");
	}
	else
	{
		if(front==-1)
		{
			front = 0;
			//front = (front+max-1)%max;
			if(Circular_Queue[front]!=0)
			{
				front = (front+max-1) % max;
				Circular_Queue[front] = value;
			}
			else
			{
				Circular_Queue[front] = value;
			}
		}
		else
		{
			front = (front+max-1) % max;
			Circular_Queue[front] = value;
		}
	}
}
//Closing Function Enqueue from Front



//Function Dequeue from Front
int deQueue_Front()
{
	int x;
	if(front==-1)
	{
		printf("The Circular Queue is Empty\n");
		return 0;
	}
	else
	{
		x = Circular_Queue[front];
		Circular_Queue[front] = 0;
		if(front==rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
		    front = (front + 1) % max;
		}
	}
	return x;
}
//Closing Function Dequeue from Front



//Function Dequeue from Rear
int deQueue_Rear()
{
	int m;
	if(rear==-1)
	{
		printf("The Circular Queue is Empty\n");
		return 0;
	}
	else
	{
		m = Circular_Queue[rear];
		Circular_Queue[rear] = 0;
		if(front==rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
			rear = (rear+max-1) % max;
		}
	}
	return m;
}
//Closing Function Dequeue from Rear



//Display Function
void display()
{
	int z;
	for(z=0;z<max;z++)
	{
		printf("%d ",Circular_Queue[z]);
	}
}
//Closing Display


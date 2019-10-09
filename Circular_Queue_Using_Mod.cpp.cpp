# include<stdio.h>
# include<conio.h>
# include<string.h>
# define max 10


int Circular_Queue[max];
int front,rear;
int value;
void Circular_Queue_Enqueue();
int Circular_Queue_Dequeue();

int main()
{
	int i,j,k,l,N,p,c_dq;
	front = -1,rear = -1;
	printf("Enter the No. of Elements : ");
	scanf("%d",&N);
	
	//Setting the array as NULL
	
	printf("We have initially set the Queue to be 0\n\n");
	for(p=0;p<N;p++)
	{
		Circular_Queue[p] = 0;
	}
	
	//Enqueue Operation
	
	for(i=0;i<N;i++)
	{
		printf("Enter the Element %d : ",i+1);
		scanf("%d",&value);
		Circular_Queue_Enqueue();
		printf("\n");
	}
	printf("\n\n");
	
	//Display Enqueue Array
	
	printf("The Queue after Enqueue Operation is : \n");
	for(k=0;k<max;k++)
	{
		printf("%d ",Circular_Queue[k]);
	}
	printf("\n\n");
	
	//Dequeue Operation
	
	printf("Dequeue Operation : \n\n");
	for(j=0;j<N;j++)
	{
		c_dq = Circular_Queue_Dequeue();
		printf("Number Removed is : %d",c_dq);
		printf("\n");
	}
	
	//Display Dequeue Array
	
	printf("The Queue after Dequeue Operation is : \n");
	for(l=0;l<max;l++)
	{
		printf("%d ",Circular_Queue[l]);
	}
	return 0;
}



void Circular_Queue_Enqueue()
{
	if(front==(rear+1) % max)
	{
		printf("Our Circular Queue is Full\n");
	}
	else
	{
		if(front==-1)
	    {
	    	rear = 0;
	    	front = 0;
	    	Circular_Queue[rear] = value;
		}
		else
		{
			rear = (rear+1) % max;
		    Circular_Queue[rear] = value;
		}
	}
	
}

int Circular_Queue_Dequeue()
{
	int x;
	
	if(front==-1)
	{
		printf("Our Circular Queue is Empty\n");
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
		    front = (front+1)%max;
	    }
	    return x;
	}
}

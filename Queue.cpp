# include<stdio.h>
# include<conio.h>
# include<string.h>
# define max 50

int Queue[max];
int front,rear;
void Enqueue(int value);
int Dequeue();

int main()
{
	 
	int i,N,j,q,d,value,dq,a;
	front = -1,rear = -1;
	printf("Enter the no. of Elements : ");
	scanf("%d",&N);
	
	printf("Enter the Elements to be Added in a Queue\n\n");
	for(i=0;i<N;i++)
	{
		printf("Enter Element %d : ",i+1);
		scanf("%d",&value);
		Enqueue(value);
		printf("\n");
	}
	
	printf("The Queue After Enqueue Operation is : \n");
	for(q=0;q<N;q++)
	{
		printf("%d ",Queue[q]);
	}
	printf("\n\n");
	
	printf("Now we Perform Dequeue Operation : \n");
	for(a=0;a<N;a++)
	{
		dq = Dequeue();
	    printf("Element Removed is : %d",dq);
	    printf("\n");
	}
	printf("\n\n");
	
	printf("The Queue After Dequeue Operation is : \n");
	for(d=0;d<N;d++)
	{
		printf("%d ",Queue[d]);
	}
	printf("\n\n");
	
	return 0;
}

void Enqueue(int value)
{
	if(rear==max-1)
	{
		printf("Queue Full\n");
	}
    else if(front==-1 && rear==-1)
	{
		rear++;
		front++;
		Queue[rear] = value;
	}
	else
	{
		rear++;
		Queue[rear] = value;
	}
}

int Dequeue()
{
	int x;
	if(rear==-1 && front==-1)
	{
		printf("Queue Empty\n");
	}
	else if(front==rear)
	{
		x = Queue[front];
		front=-1;
		rear=-1;
	}
	else
	{
		x = Queue[front];
		front++;
	}
	return x;
}



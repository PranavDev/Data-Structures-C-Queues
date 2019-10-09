# include<stdio.h>
# include<conio.h>
# define max 10

int Priority_Queue[max] = {0};
int front,rear;
int pos;
int N,i,j,k,value;
void display();
void Insert_By_Priority();
//int Remove_By_Priority();


int main()
{
	front = -1;
	rear = -1;
	
	printf("Enter the number of Elements : ");
	scanf("%d",&N);
	printf("\n\n");
	
	printf("Creating a Priority Queue\n\n");
	printf("Adding Elements : \n\n");
	for(i=0;i<N;i++)
	{
		printf("Enter the Value to be Inserted : ");
		scanf("%d",&value);
		Insert_By_Priority();
	}
	
	printf("The Priority Queue is : ");
	display();
	printf("\n\n");
	
/*	printf("Remove the Elements : \n\n");
	for(j=0;j<N;j++)
	{
		int val = Remove_By_Priority();
		printf("The %d Least Priority : %d",j+1,val);
		printf("\n");
	}*/
	return 0;
}

void Insert_By_Priority()
{
	int temp;
	
	if(rear==max-1)
	{
		printf("Queue is Empty\n");
	}
	else
	{
		if(front==-1 && rear==-1)
		{
			front = 0;
			rear = 0;
			Priority_Queue[rear] = value;
		}
		else
		{
			rear = rear + 1;
			pos = rear;
			if(value > Priority_Queue[pos-1])
			{
				while(pos>0 && value > Priority_Queue[pos-1])
				{
					temp = Priority_Queue[pos-1];
					Priority_Queue[pos-1] = value;
					Priority_Queue[pos] = temp;
					pos--;
				}
			}
			else
			{
				Priority_Queue[pos] = value;
			}
		}
	}
}

void display()
{
	for(k=0;k<N;k++)
	{
		printf("%d ",Priority_Queue[k]);
	}
}

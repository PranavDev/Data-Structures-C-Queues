# include<stdio.h>
# include<conio.h>
# include<string.h>
# define max 20

int JS_Queue[max];
int N,ch,k,i;
int front,rear,pos;
int MovDPrio,SongDPrio,LisMusPrio,GamePrio;
void enQueue(int value);
int deQueue();
void display();


int main()
{
	front = -1;
	rear = -1;
	
	printf("Enter the Number Of Inputs : ");
	scanf("%d",&N);
	printf("\n\n");
	
	printf("The Below Choices Selection would be displayed %d times\n\n",N);
	
	for(i=0;i<N;i++)
    {
	    printf("The Below is the List of Operations to be Performed : \n\n");
	    printf("1. Downloading a movie.\n");
	    printf("2. Downloading a song.\n");
	    printf("3. Listening to Audio music.\n");
	    printf("4. Playing A Game.\n\n");
	    printf("Enter Your Choice Of Operation : ");
	    scanf("%d",&ch);
	    printf("\n\n");
	    
	    switch(ch)
	    {
	    	case 1 : printf("You have chosen to Download a Movie..\n\n");
	    	         printf("Enter the priority number for Downloading A Movie : ");
	    	         scanf("%d",&MovDPrio);
	    	         enQueue(MovDPrio);
	    	         break;
	    	        
	    	case 2 : printf("You have chosen to Download a Song..\n\n");
	    	         printf("Enter the priority number for Downloading A Song : ");
	    	         scanf("%d",&SongDPrio);
	    	         enQueue(SongDPrio);
	    	         break;
	    	         
	    	case 3 : printf("You have chosen to Listen to Audio music..\n\n");
	    	         printf("Enter the priority number for Listening to a music : ");
	    	         scanf("%d",&LisMusPrio);
	    	         enQueue(LisMusPrio);
	    	         break;
	    	         
	    	case 4 : printf("You have chosen to Play a Game..\n\n");
	    	         printf("Enter the priority number for Playing Games : ");
	    	         scanf("%d",&GamePrio);
	    	         enQueue(GamePrio);
	    	         break;
	    	         
	    	default : printf("Wrong Choice ");
	    	          break;
		}
		
	} 
	
	printf("The Queue After Entering Choices With Their Priority Order is : ");
	display();
	printf("\n\n");
}


void enQueue(int value)
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
			JS_Queue[rear] = value;
		}
		else
		{
			rear = (rear + 1) % 10;
			pos = rear;
			if(value > JS_Queue[pos-1])
			{
				while(pos>0 && value > JS_Queue[pos-1])
				{
					temp = JS_Queue[pos-1];
					JS_Queue[pos-1] = value;
					JS_Queue[pos] = temp;
					pos--;
				}
			}
			else
			{
				JS_Queue[pos] = value;
			}
		}
	}
}


void display()
{
	for(k=0;k<N;k++)
	{
		printf("%d ",JS_Queue[k]);
	}
}

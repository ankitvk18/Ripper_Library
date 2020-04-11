#include <stdio.h>
struct studentinfo
{
    int StudID;
    int Foodtime;
    int WT;
    int TAT;
};
void input(struct studentinfo list[],int x);
void SchedulingProcess(struct studentinfo list[],int x);
void waitingtime(struct studentinfo list[],int y);
void turnAroundTime(struct studentinfo list[],int y);
void display(struct studentinfo list[],int x);
void input(struct studentinfo list[100], int x)
{
    int i;
    for (i=0;i<x;i++)
    {
        printf("Enter the students info -",i+1);       
        printf("Student ID - ");
        scanf("%d",&list[i].StudID);
        printf("Time Taken for the food in minutes - ");
        scanf("%d",&list[i].Foodtime);
    } 
}
void display(struct studentinfo list[100],int x)
{
    int i,AWT=0,ATAT=0;
	int TWT=0,TTAT=0;
    printf("\n\n\t\t LRTF based Output\n");
    printf("\n\t\tStudent Id\tFood Taken Time\tWaiting Time\tTurn Around Time");
    for(i=0;i<x;i++)
    {
        printf("\n\t\t%d\t\t%d\t\t%d\t\t%d\t\t",list[i].StudID,list[i].Foodtime,list[i].WT,list[i].TAT);
		TWT= TWT+list[i].WT;
		TTAT=TTAT+list[i].TAT;
	} 
	printf("\n\n\t\tTotal Waiting Time = %d",TWT);
	printf("\n\t\tTotal Turn around Time = %d\n\n",TTAT);
	printf("\n\n\t\t\tAverage Waiting Time = %d",TWT/x);
	printf("\n\t\tAverage Turn around Time = %d\n\n",TTAT/x);
}

void SchedulingProcess(struct studentinfo list[100],int x)
{
    int i,j;
    struct studentinfo temp;
    for (i=0;i<x-1;i++)
    {
        for(j=0;j<(x-1-i);j++)
        {
            if(list[j].Foodtime<list[j+1].Foodtime)
            {
                temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            } 
            else if(list[j].Foodtime==list[j+1].Foodtime)
            {
            	if(list[j].StudID>list[j+1].StudID)
            	{
            	temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
                }
			}
        }
    }
}
void WT(struct studentinfo list[100],int y)
{
	int j,total;
    list[0].WT=0;
    for(j=1;j<y;j++)
    {list[j].WT=list[j-1].WT+list[j-1].Foodtime;}
}
void TAT(struct studentinfo list[100],int y)
{
	int j,total;
    for(j=0;j<y;j++)
    { list[j].TAT=list[j].WT+list[j].Foodtime; }
}
int main()
{
    struct studentinfo data[100];
    int y,i;
    char c='n';
    do
	{
   		printf("Enter the no. of Students - ");
    	scanf("%d",&y);
    	input(data,y);
    	SchedulingProcess(data,y);
    	WT(data,y);
    	TAT(data,y);
    	display(data,y);
    	printf("Press 'y' to continue -");
    	scanf("%s",&c);
    }
	while(c=='y');
    return 0;
} 


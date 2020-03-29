#include<stdio.h>
struct process
{
	int pid,burst_time,arrival_time;
	int turnaround_time,waiting_time,completion_time;
	float priority;
}a,p[20];
void main()
{
	int n,i,j,sum,sum2;
	printf("\t\tEnter no of processes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("\t\tFor process p[%d],\n \t\tEnter burst_time:   ",i+1);
		scanf("%d",&p[i].burst_time);
		printf("\t\tEnter arrival_time: ");
		scanf("%d",&p[i].arrival_time);
		p[i].pid=i+1;
	}
	printf("\n\t\t\tEntered Values Are: \n");
	printf("\n\t\tProcess	 Burst time 	Arrival time  \n\n");
	for(i=0;i<n;i++)
	{
	
	printf("  \t\t  P[%d] 		%d 		%d     \n",p[i].pid,p[i].burst_time,p[i].arrival_time);
	}

	for(i=0;i<n;i++)//sorting acc to arrival time
	{
		for(j=0;j<n-1;j++)
		{
			if(p[j].arrival_time>p[j+1].arrival_time)
			{
				a=p[j];
				p[j]=p[j+1];
				p[j+1]=a;
			}
		}
	}
   printf("\n\t\tAfter Sorting According To Arrival Time: \n\n\t\tProcess	 Burst time 	Arrival time  \n\n");
	for(i=0;i<n;i++)
	{
		printf("  \t\t  P[%d] 		%d 		%d     \n",p[i].pid,p[i].burst_time,p[i].arrival_time);
	}
	
	//checking for duplicate values of Arrival time
	int c=0,k,min_arrival_time;
	for(k=0;k<n;k++)
	{	c=0;
		min_arrival_time=p[k].arrival_time;
		for(i=k+1;i<n;i++)
		{
			if(p[i].arrival_time == min_arrival_time)
				c++;
			else
				break;
		}
		if(c>0)
		{
			for(i=k;i<k+c+1;i++)
			{
				for(j=i+1;j<k+c+1;j++)
				{
					if(p[i].burst_time>p[j].burst_time)
					{
						a=p[i];
						p[i]=p[j];
						p[j]=a;
					}
				}
			}
		}
	}

	int wait_final, turnaround_final,min;
	float wait_avg,turnaround_avg;


	
	 printf("\n\t\tAfter Sorting According To Arrival Time And Burst Time:\n\n\t\tProcess	 Burst time 	Arrival time  \n\n");
	for(i=0;i<n;i++)
	{
		printf("  \t\t  P[%d] 		%d 		%d     \n",p[i].pid,p[i].burst_time,p[i].arrival_time);//,p[i].waiting_time,p[i].turnaround_time);
	}
	long int q = 1;
  	double b_time = 0;
  	for(j=0;j<n;j++)
  	{
    	b_time = b_time + p[j].burst_time;
    	min = p[q].burst_time;

    	for(i=k;i<n;i++)
   		 {
      		if((b_time >= p[i].arrival_time)&&(p[i].burst_time<min))
      		{
        		a=p[q];
        		p[q]=p[i];
        		p[i]=a;
      		}
    		}
    		q++;
  	}
 	p[0].completion_time = p[0].arrival_time+p[0].burst_time;
  	for(i=1;i<n;i++)
  	{
    	p[i].completion_time = p[i-1].completion_time + p[i].burst_time;
  	}
  	for(i=0;i<n;i++)
  	{
    	p[i].turnaround_time=p[i].completion_time-p[i].arrival_time;
    	turnaround_final+=p[i].turnaround_time;
  	}
  	turnaround_avg=turnaround_final/n;
  
   	for(i=0;i<n;i++)
 	{
    	p[i].waiting_time=p[i].turnaround_time-p[i].burst_time;
    	wait_final += p[i].waiting_time; 
  	}
  	wait_avg = wait_final/n;
	printf("\n\n\t\t\t On Performing SJF:\n\n");
 	printf("\t\t Process  Arrival Time  Burst Time  Completion Time    Waiting Time    Turn Around Time  \n");
  	for(i=0;i<n;i++)
  	{
    	printf("\t\t  P[%d]          %d           %d           %d               %d                %d          \n",p[i].pid,p[i].arrival_time,p[i].burst_time,p[i].completion_time,p[i].waiting_time,p[i].turnaround_time);
  	}
  	//Calculating priority 
	for(i=0;i<n;i++)
  	{
  		float h=(float)p[i].waiting_time/p[i].completion_time;
    	p[i].priority = 1+h;
  	}

	for(i=0;i<n;i++)//sorting acc to priority
	{
		for(j=0;j<n-1;j++)
		{
			if(p[j].priority>p[j+1].priority)
			{
				a=p[j];
				p[j]=p[j+1];
				p[j+1]=a;
			}
		}
	}
	printf("\n\n\t\t\tOn Arranging According To Priority: //priority=1+waiting time/completion time\n\n");
 
	printf("\t\t Process  Arrival Time  Burst Time  Completion Time    Waiting Time    Turn Around Time    Priority  \n");
  		for(i=0;i<n;i++)
  		{
    		printf("\t\t  P[%d]          %d           %d           %d               %d                %d             %f  \n",p[i].pid,p[i].arrival_time,p[i].burst_time,p[i].completion_time,p[i].waiting_time,p[i].turnaround_time,p[i].priority);
  		}
}


/*PROGRAM TO IMPLEMENT SCHEDULING USING
  "ROUND ROBIN" TECHNIQUE*/

main()
{
 /*VARIABLE DECLARATIONS*/
 struct process
 {
  char name[8];
  int at,set,st,ft,tat,rt;
  float tar;
 }p[10],t[10],temp;

 int i,j,k,n,ts,f,count,carry=0,curr_time=0;
 float ttt=0,ttr=0;

 clrscr();

 /*GETTING THE DETAILS AS INPUT*/
 printf("ENTER THE NO. OF PROCESSES: ");
 scanf("%d",&n);

 printf("ENTER THE TIME-STAMP OF SCHEDULING: ");
 scanf("%d",&ts);

 clrscr();
 printf("ENTER THE FOLLOWING DETAILS FOR %d PROCESSES\n",n);
 printf("NOTE: USE TABS BETWEEN DETAILS AND RETURNS BETWEEN PROCESSES\n\n");
 printf("PROCESS\tARRIVAL\tSERVICE\nNAME\tTIME\tTIME\n");

 for(i=0;i<n;i++)
 {
  scanf("%s%d%d",p[i].name,&p[i].at,&p[i].set);
  p[i].rt=p[i].set;
 }

 /*SAVING A COPY OF INPUT*/
 for(i=0;i<n;i++)
 t[i]=p[i];

 /*SORTING THE PROCESSES ACCORDING TO ARRIVAL TIME*/
 for(i=0;i<n;i++)
 {
  k=i;

  for(j=i+1;j<n;j++)
  if(p[j].at<p[k].at)
  k=j;

  temp=p[i];
  p[i]=p[k];
  p[k]=temp;
 }

 /*THE ACTUAL PROCESS OF SCHEDULING*/

 while(1)
 {
  count=0;
  for(i=0;i<n;i++)
  {
   if(p[i].at<=curr_time && p[i].rt!=0)
   {
    f=ts;
    ts+=carry;

    if(p[i].rt==p[i].set)
    p[i].st=curr_time;

    if(p[i].rt<ts || p[i].rt==ts)
    {
     curr_time+=p[i].rt;
     carry += ts-p[i].rt;
     p[i].rt=0;
     p[i].ft=curr_time;
     p[i].tat=p[i].ft-p[i].at;
     p[i].tar=p[i].tat*1.0/p[i].set;

     ttt+=p[i].tat;
     ttr+=p[i].tar;
    }
    else
    {
     curr_time+=ts;
     carry=0;
     p[i].rt-=ts;
    }
    ts=f;
   }
   else
   count++;
  }

  if(count==n)
  curr_time+=1;

  for(i=0;i<n;i++)
  if(p[i].rt!=0)
  break;

  if(i==n)
  break;
 }


 /*DISPLAYING THE RESULTS OF SCHEDULING IN THE ORDER OF INPUT*/
 clrscr();
 printf("DETAILS COMPUTED AFTER SCHEDULING USING FCFS\n\n");
 printf("PROCESS\tARRIVAL\tSERVICE\tSTART\tFINISH\tTURN-AROUND\tTURN-AROUND\n");
 printf("NAME\tTIME\tTIME\tTIME\tTIME\tTIME\t\tRATIO\n");

 for(i=0;i<n;i++)
 for(j=0;j<n;j++)
 if( !strcmp(t[i].name,p[j].name) )
 printf("%-8s%-8d%-8d%-8d%-8d%-8d\t%-8.2f\n",p[j].name,p[j].at,p[j].set,p[j].st,p[j].ft,p[j].tat,p[j].tar);
 printf("\n\nMEAN TURN-AROUND TIME  = %-4.2f\nMEAN TURN-AROUND RATIO = %-4.2f",ttt/n,ttr/n);
 getch();
}
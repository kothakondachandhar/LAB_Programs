/*PROGRAM TO IMPLEMENT SCHEDULING USING
  "PRIORITY" TECHNIQUE WITH PRE-EMPTION*/

main()
{
 /*VARIABLE DECLARATIONS*/
 struct process
 {
  char name[8];
  int at,set,pr,st,ft,tat,rt;
  /*HERE rt & pr ARE USED TO STORE REMAINING TIME AND PRIORITY RESPECTIVELY*/
  float tar;
 }p[10],t[10],temp;

 int i,j,k,l,n,curr_time=0;
 float ttt=0,ttr=0;

 clrscr();

 /*GETTING THE DETAILS AS INPUT*/
 printf("ENTER THE NO. OF PROCESSES: ");
 scanf("%d",&n);

 clrscr();
 printf("ENTER THE FOLLOWING DETAILS FOR %d PROCESSES\n",n);
 printf("NOTE: USE TABS BETWEEN DETAILS AND RETURNS BETWEEN PROCESSES\n\n");
 printf("PROCESS\tARRIVAL\tSERVICE\tPRIORITY\nNAME\tTIME\tTIME\n");

 for(i=0;i<n;i++)
 {
 printf("enter the details of process %d",i+1);
  scanf("%s%d%d%d",p[i].name,&p[i].at,&p[i].set,&p[i].pr);
  p[i].rt=p[i].set;
 }

 /*SAVING A COPY OF THE INPUT*/
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
  for(i=0;i<n;i++)
  if(p[i].at<=curr_time && p[i].rt!=0)
  break;

  if(i==n)
  break;

  for(j=i+1;j<n;j++)
  if( p[j].at<=curr_time && p[j].rt!=0 )
  if( p[j].pr>p[i].pr || ( p[j].pr==p[i].pr && p[j].rt<p[i].rt ) )
  i=j;

  if(p[i].rt==p[i].set)
  p[i].st=curr_time;

  --p[i].rt;
  curr_time++;

  if(p[i].rt==0)
  {
   p[i].ft=curr_time;
   p[i].tat=p[i].ft-p[i].at;
   p[i].tar=p[i].tat*1.0/p[i].set;
   ttt+=p[i].tat;
   ttr+=p[i].tar;
  }
 }


 /*DISPLAYING THE RESULTS OF SCHEDULING IN THE ORDER OF INPUT*/
 clrscr();
 printf("DETAILS COMPUTED AFTER SCHEDULING USING PRIORITY ( PRE-EMPTIVE )\n\n");
 printf("PROCESS\tARRIVAL\tSERVICE\tPRIORITY START\tFINISH\tTURN-AROUND\tTURN-AROUND\n");
 printf("NAME\tTIME\tTIME\t\t TIME\tTIME\tTIME\t\tRATIO\n");

 for(i=0;i<n;i++)
 for(j=0;j<n;j++)
 if( !strcmp(p[j].name,t[i].name) )
 printf("%-8s%-8d%-8d%-8d %-7d%-8d%-8d\t%-8.2f\n",p[j].name,p[j].at,p[j].set,p[j].pr,p[j].st,p[j].ft,p[j].tat,p[j].tar);

 printf("\n\nMEAN TURN-AROUND TIME  = %-4.2f\nMEAN TURN-AROUND RATIO = %-4.2f",ttt/n,ttr/n);
 getch();

}
/*PROGRAM TO IMPLEMENT SCHEDULING USING
  "SHORTEST JOB FIRST" TECHNIQUE WITHOUT PRE-EMPTION*/

main()
{
 /*VARIABLE DECLARATIONS*/
 struct process
 {
  char name[8];
  int at,set,st,ft,tat;
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
 printf("PROCESS\tARRIVAL\tSERVICE\nNAME\tTIME\tTIME\n");

 for(i=0;i<n;i++)
 {
 printf("\nenter the details of process %d",i+1);
 scanf("%s%d%d",p[i].name,&p[i].at,&p[i].set);
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
 for(i=0;i<n;i++)
 {
  /*ADJUSTING THE CURRENT TIME FOR LATE PROCESSES*/
  if(p[i].at>curr_time)
  curr_time = p[i].at;

  /*FINDING THE POINT UPTO WHICH PROCESSES HAVE ARRIVED*/
  for(j=i+1;j<n;j++)
  if(p[j].at>curr_time)
  break;

  /*FINDING THE SHORTEST PROCESS BY*/
  /*COMPARING SERVICE TIMES AND IF THEY ARE EQUAL, ARRIVAL TIMES*/
  for(k=i+1,l=i;k<j;k++)
  if( (p[i].set > p[k].set) || ( (p[i].set==p[k].set) && (p[i].at >p[k].at) ))
  l=k;

  temp=p[i];
  p[i]=p[l];
  p[l]=temp;

  /*FINISHING THE SHORTEST PROCESS*/
  p[i].st = curr_time;
  p[i].ft = p[i].set + p[i].st;
  p[i].tat = p[i].ft - p[i].at;
  p[i].tar = p[i].tat * 1.0 / p[i].set;
  curr_time = p[i].ft;

  ttt += p[i].tat;
  ttr += p[i].tar;
 }

 /*DISPLAYING THE RESULTS OF SCHEDULING IN THE ORDER OF INPUT*/
 clrscr();
 printf("DETAILS COMPUTED AFTER SCHEDULING USING SJF ( NON PRE-EMPTIVE )\n\n");
 printf("PROCESS\tARRIVAL\tSERVICE\tSTART\tFINISH\tTURN-AROUND\tTURN-AROUND\n");
 printf("NAME\tTIME\tTIME\tTIME\tTIME\tTIME\t\tRATIO\n");

 for(i=0;i<n;i++)
 for(j=0;j<n;j++)
 if( !strcmp(p[j].name,t[i].name) )
 printf("%-8s%-8d%-8d%-8d%-8d%-8d\t%-8.2f\n",p[j].name,p[j].at,p[j].set,p[j].st,p[j].ft,p[j].tat,p[j].tar);

 printf("\n\nMEAN TURN-AROUND TIME  = %-4.2f\nMEAN TURN-AROUND RATIO = %-4.2f",ttt/n,ttr/n);
 getch();

}
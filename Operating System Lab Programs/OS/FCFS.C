/*PROGRAM TO IMPLEMENT SCHEDULING USING
  "FIRST COME FIRST SERVED" TECHNIQUE*/

main()
{
 /*VARIABLE DECLARATIONS*/
 struct process
 {
  char name[8];
  int at,set,st,ft,tat;
  float tar;
 }p[10],t[10],temp;

 int i,j,k,n;
 float ttt,ttr;

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
 printf("\nenter the details of %d",i+1);
 scanf("%s%d%d",p[i].name,&p[i].at,&p[i].set);
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

 /*SCHEDULING THE FIRST PROCESS*/
 p[0].st = p[0].at;
 p[0].ft = p[0].st + p[0].set;
 p[0].tat = p[0].ft - p[0].at;
 p[0].tar = p[0].tat*1.0/p[0].set;

 ttt = p[0].tat;
 ttr = p[0].tar;

 /*SCHEDULING THE REMAINING PROCESSES*/
 for(i=1;i<n;i++)
 {
  p[i].st = p[i-1].ft > p[i].at ? p[i-1].ft : p[i].at;
  p[i].ft = p[i].st + p[i].set;
  p[i].tat = p[i].ft - p[i].at;
  p[i].tar = p[i].tat * 1.0 / p[i].set;

  ttt+=p[i].tat;
  ttr+=p[i].tar;
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
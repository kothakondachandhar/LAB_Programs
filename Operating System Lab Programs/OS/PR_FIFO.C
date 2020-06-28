/*PROGRAM TO IMPLEMENT 'FIFO' PAGE REPLACEMENT ALGORITHM*/
main()
{
 static int a[3],b[20];
 int i,j,n,p,fault;

 clrscr();

 printf("'FIFO' PAGE REPLACEMENT TECHNIQUE WITH BUFFER SIZE AS 3\n");
 printf("ENTER NO. OF PAGES (MAX. OF 20) : ");
 scanf("%d",&n);

 clrscr();
 printf("ENTER %d PAGE NO.S:\n",n);

 for(i=0;i<n && i<20;i++)
 scanf("%d",&b[i]);

 clrscr();
 printf("PAGE NO:     BUFFER   PAGE FAULT:\n");
 printf("            1  2  3\n\n");

 for(i=0,p=0;i<n;i++)
 {
  for(j=0;j<3;j++)
  if(a[j]==0 || a[j]==b[i])
  break;

  if(j==3)
  {
   fault=1;
   a[p++]=b[i];
   if(p==3)
   p=0;
  }
  else
  {
   fault=0;
   if(a[j]!=b[i])
   a[j]=b[i];
  }
  printf("%4d\t  ",b[i]);

  for(j=0;j<3;j++)
  if(a[j]==0)
  printf("   ");
  else
  printf("%c%c%3d",a[j]);

  if(fault==0)
  printf("       NO\n");
  else
  printf("       YES\n");
 }
 getch();
}
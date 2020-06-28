/*PROGRAM TO IMPLEMENT 'LRU' PAGE REPLACEMENT ALGORITHM*/
main()
{
 static int a[3],b[20],c[2];
 int i,j,n,fault;

 clrscr();

 printf("'LRU' PAGE REPLACEMENT TECHNIQUE WITH BUFFER SIZE AS 3");
 printf("\nENTER NO. OF PAGES (MAX. OF 20) :  ");
 scanf("%d",&n);

 clrscr();
 printf("ENTER %d PAGE NO.S:\n",n);

 for(i=0;i<n && i<20;i++)
 scanf("%d",&b[i]);

 clrscr();
 printf("PAGE NO:     BUFFER   PAGE FAULT:\n");
 printf("            1  2  3\n\n");

 for(i=0;i<n;i++)
 {
  for(j=0;j<3;j++)
  if(a[j]==0 || a[j]==b[i])
  break;

  if(j==3)
  {
   fault=1;
   for(j=0;j<3;j++)
   if( a[j]!=c[0] && a[j]!=c[1] )
   a[j]=b[i];
  }
  else
  {
   fault=0;
   a[j]=b[i];
  }
  printf("%4d\t  ",b[i]);

  for(j=0;j<3;j++)
  if(a[j]==0)
  printf("   ");
  else
  printf("%3d",a[j]);

  if(fault==0)
  printf("       NO\n");
  else
  printf("       YES\n");

  if( (c[1]==b[i]) || ( c[0]!=b[i] && c[1]!=b[i] ) )
  {
   c[1]=c[0];
   c[0]=b[i];
  }
 }
 getch();
}
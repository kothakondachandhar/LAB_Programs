/*PROGRAM TO IMPLEMENT 'CLOCK' PAGE REPLACEMENT ALGORITHM*/
main()
{
 static int a[3][2],b[20],c[2];
 int i,j,n,p=0,fault;

 clrscr();

 printf("'CLOCK' PAGE REPLACEMENT TECHNIQUE WITH BUFFER SIZE AS 3");
 printf("\nENTER NO. OF PAGES (MAX. OF 20) :  ");
 scanf("%d",&n);

 clrscr();
 printf("ENTER %d PAGE NO.S:\n",n);

 for(i=0;i<n && i<20;i++)
 scanf("%d",&b[i]);

 clrscr();
 printf("PAGE NO:          BUFFER   PAGE FAULT:\n");
 printf("              1     2     3\n\n");

 for(i=0;i<n;i++)
 {
  fault=0;
  if(a[p][0]==0)
  {
   a[p++][0]=b[i];
   if(p==3)
   p=0;
  }
  else
  {
   for(j=0;j<3;j++)
   if(a[j][0]==b[i])
   break;

   if(j<3)
   a[j][1]=1;
   else
   {
    j=p;
    fault=1;

    while(1)
    {
     if(a[j][1]==0)
     {
      a[j][0]=b[i];
      break;
     }
     else
     a[j][1]=0;

     if(j==3)
     j=0;
     else
     j++;
    }
    if(j<2)
    p=j+1;
    else
    p=0;
   }
  }

  printf("%4d\t  ",b[i]);

  for(j=0;j<3;j++)
  if(a[j]==0)
  printf("   ");
  else
  printf("%c%c%3d%c",p==j?'-':' ',p==j?'>':' ',a[j][0],a[j][1]==0?' ':'*');

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
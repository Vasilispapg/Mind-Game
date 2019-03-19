#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int counter=0;

int pin(int size,int count);
int main(void)
{
  int x=0,size=4,level=2,count=0,plays=0;
  while(x!=4)
  {
    do {
      printf("\nMEMORY GAME MENU\n---------------------------\n");
      printf("\n1.Play\t2.Level\t3.Statistics\t4.Exit\nEnter Choise: ");
      scanf("%d",&x);
    } while(x<1 || x>4);
    switch(x)
    {
      case 1:
      {
        plays=pin(size,count); /* ektelesi programmatos kai metrisi poses fores epaijes*/
        counter++;
        break;
      }
      case 2:
      {
        printf("\nLEVEL MENUS\n---------------------------\n1.Easy <2x2>\t2.Medium <4x4>\t3.Hard <6x6>\n");
        do
        {
          printf("\nSelect level: ");
          scanf("%d",&level); /*epilogi level diskolias*/
        }while(level<0 || level>4);
        if(level==1)
        {
          size=2;
          counter--;
        }
        else if (level==2)
        {
          size=4;
          counter--;
        }
        else
        {
          size=6;
          counter--;
        }
      break;
      }
      case 3: /*statistika paixnidiou*/
      {
        if(counter<=0)
          printf("\n0 games played\n\n");
        else
        {
          if(level==1)
              printf("\nLevel = Easy\n\nCongrats!!! You have done it after %d tries!!\n",plays-1);
          if(level==2)
              printf("\nLevel = Medium\n\nCongrats!!! You have done it after %d tries!!\n",plays-1);
          if(level==3)
              printf("\nLevel = Hard\n\nCongrats!!! You have done it after %d tries!!\n",plays-1);
        }
        break;
      }
      case 4:
      {
        printf("\nThank you for playing with us!! :D\n"); /*klisimo paixnidiou*/
        break;
      }
    }
  }
  return 0;
}

int pin(int size,int count) /*arxi paixnidiou*/
{
  int i,j,z,l,x[size][size],flag[size][size],allflag=0,row1,row2,column1,column2,k=1,kflag=0,temp;
  count=0;
  counter=1;
  srand(time(NULL));
  for(i=0;i<size;i++)
  {
    for(j=0;j<size;j++)
    {
      x[i][j]=k;
      flag[i][j]=0;
      k++;
      if(k==(size*size/2)+1)
      {
        k=1; //ekxwrisei timwn
      }
    }
  }
  for(i=0;i<size;i++)
  {
    for(j=0;j<size;j++)
    {
      z=rand() % size;
      l=rand() % size;
      temp=x[i][j];
      x[i][j]=x[z][l]; //allagi thesewn
      x[z][l]=temp;
    }
  }
  for(i=0;i<size;i++)
  {
    printf("\n");
    for (j=0;j<size;j++)
    {
      printf("%d\t",x[i][j]); //emfanisei toy pinaka
    }
  }
  do
  {
    for(i=0;i<size;i++)
    {
      if(size==4 && i==0)
      {
        printf("\n\n\t1\t2\t3\t4");
        printf("\n  --------------------------------");
      }
      else if(size==2 && i==0)
      {
        printf("\n\n\t1\t2\n");
        printf("  ----------------");
      }
      else if(size==6 && i==0)
      {
        printf("\n\n\t1\t2\t3\t4\t5\t6\n");
        printf("  ------------------------------------------------");
      }
      printf("\n%d|\t\b",i+1);
      for(j=0;j<size;j++)
      {
        if(flag[i][j]==0)
          printf("*\t");
        else
          printf("%d\t",x[i][j]);
      }
    }
    if(allflag==0)
    {
      do
      {
      printf("\n\nPlease insert the first card row and column: ");
      scanf("%d%d",&row1,&column1);
      printf("\n\nPlease insert the second card row and column: ");
      scanf("%d%d",&row2,&column2);
      if((row1>15 && row2>15) || (column1>15 || column2>15)) // gia na vgaineis ektos programmatos
        goto OUT;
      }while((row1==row2 && column1==column2) || (row1>size || column1>size || row2>size || column2>size));
          row1--;
          row2--;
          column1--;
          column2--;
          counter+=2;
        if(flag[row1][column1]!=1 && flag[row2][column2]!=1) //gia tis kartes poy einai idi anoigmenes
        {
          flag[row2][column2]=1;
          flag[row1][column1]=1;
        if(x[row1][column1]!=x[row2][column2])
        {
          flag[row2][column2]=0;
          flag[row1][column1]=0;
        }
        else
        {
          printf("\nCards Matched!!!!\n");
            count+=2;
        }
      }
    if(count>=size*size) //klisimo paixnidiou
    {
        OUT:
        allflag=1;
        printf("\n\nCongratulations!!! You won!!\n\n");
    }
  }
  }while(allflag==0);
  return counter;
}

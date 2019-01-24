#include<stdio.h>
#include<math.h>
#include<string.h>
#include<conio.h>
char a[23][72];
int pos1,pos2,z[4][2];
void printMaze()
{	
	int i;
	for(int k=0;k<30;k++)
		printf("\n");
	for(i=0;i<23;i++)
	printf("%s",a[i]);
}
void randompos()
{
	int b=1,i;
	for(i=0;i<=3;i++)
	{
		do
		{
				z[i][0]=rand()%22;
				z[i][1]=rand()%71;
				if(a[z[i][0]][z[i][1]]=='#')
					b=0;
				else if(z[i][0]==22&&z[i][1]==1)
					b=0;
				else
					b=1;
		}
		while(b==0);
		a[z[i][0]][z[i][1]]="&";
	}
}
void main()
{
	int b=1,p=1,c=1;
	do
	{
		pos1=rand()%22;
		pos2=rand()%71;
		if(a[pos1][pos2]=='#')
		b=0;
		else if(pos1==22&&pos2==1)
			b=0;
		else
			b=1;
	}
	while(b==0);
	a[pos1][pos2]="@";
	randompos();
	printMaze();
	printf("If you want to give up, at any point of the game press \"p\" or \"P\"\n");
	char m='h';
	do
	{
		
		if(m=='p'||m=='P')
		{
			p=0;
			break;
		}
		a[pos1][pos2]=" ";
		if(m=='w'||m=='W')
		{
			if(a[pos1-1][pos2]=='#');
			else
				pos1--;
		}
		else if(m=='s'||m=='S')
		{
			if(a[pos1+1][pos2]=='#');
			else
				pos1++;
		}
		else if(m=='d'||m=='D')
		{
			if(a[pos1][pos2+1]=='#');
			else 
				pos2++;
		}
		else if(m=='a'||m=='A')
		{
			if(a[pos1][pos2-1]=='#');
			else
				pos2--;
		}
		a[pos1][pos2]="@";
		printMaze();
		m='\0';
		do
		{
			for(int j=0;j<3;j++)
			{
				int d=rand()%3;
				if(d==0)
				{
					if(a[z[j][0]-1][z[j][1]]=='@')
					{	p=0;break; }
					else if(a[z[j][0]-1][z[j][1]]=='#');
					else
						z[j][0]--;
				}
				else if(d==1)
				{
					if(a[z[j][0]+1][z[j][1]]=='@')
					{	p=0;break; }
					else if(a[z[j][0]+1][z[j][1]]=='#');
					else
						z[j][0]++;
					}
				else if(d==2)
				{
					if(a[z[j][0]][z[j][1]+1]=='@')
					{	p=0;break; }
					else if(a[z[j][0]][z[j][1]+1]=='#');
					else
						z[j][1]++;
				}
				else 
				{	
					if(a[z[j][0]][z[j][1]-1]=='@')
					{	p=0;break; }
					else if(a[z[j][0]][z[j][1]-1]=='#');
					else
						z[j][1]--;		
				}
				for(int j=0;j<1000000;j++);
			}
			m=getchar();
			if(m=='\0')
				continue;
		}
		while(p==1&&m=='\0');
		printMaze();
		if(p==0)
			break;
	}		
	while(!(pos1==22&&pos2==1));
	if(p==1)
		printf("YOU WIN\n");
	else
		printf("YOU LOSE!!!\n");
}	
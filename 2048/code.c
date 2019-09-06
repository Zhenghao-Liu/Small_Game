//i代表行 j代表列
#include"stdio.h"
#include "stdlib.h"
#include "time.h"
#include "ctype.h"
#include "conio.h"
void suijiweizhi(int num[4][4]);//产生随机的2
void inw(int num[4][4]);
void ina(int num[4][4]);
void ins(int num[4][4]);
void ind(int num[4][4]);
void shuchu(int num[4][4]);//输出游戏界面
int main()
{
	int num[4][4],i,j;
	char shuru;
	for (i=0;i<4;i++)//游戏置零
		for (j=0;j<4;j++)
			num[i][j]=0;
	while(1)//游戏开始
	{
		printf("-------------------------\n");
		printf(" welcome to 4x4 2048 game\n");
		printf("     made by Yves\n");
		printf("1.输入wasd来决定移动方向(大小写都可以)\n");
		printf("2.若多次提示错误先输入回车再输入方向\n");
		printf("3.一次只能输入一个字母多了有奇怪的bug\n");
		printf("-------------------------\n");
		printf("      after move\n");
		shuchu(num);
		printf("      new number\n");
		suijiweizhi(num);//随机地方出现2
		shuchu(num);//输出游戏界面
		printf("-------------------------\n");
		loop:printf("your direction is(wasd):");
		shuru=getche();
		switch(tolower(shuru))
		{
			case 'w':inw(num);	break;
			case 'a':ina(num);	break;
			case 's':ins(num);	break;
			case 'd':ind(num);	break;
			default :printf("\nwrong,please press again\n");	goto loop;	break;
		}	
		system("cls");
	}
	return 0;
}

void shuchu(int num[4][4])//输出游戏界面
{
	int i,j;
	for (i=0;i<(4);i++)
	{
		for (j=0;j<(4);j++)
			if (num[i][j]==0)
				printf("    _");
			else
				printf("%5d",num[i][j]);
		printf("\n");
	}
}

void suijiweizhi(int num[4][4])//生成随机
{
	int i,j,k,panduan,max=0;
	panduan=0;
	srand((unsigned)time( NULL ));
	for (i=0;i<4;i++)//检查是否没有地方生成新数字
		for (j=0;j<4;j++)
			if (num[i][j]==0)
				panduan=1;
	if (panduan!=1)
	{
		printf(".........................\n");
		printf("       game over\n");
		for (i=0;i<4;i++)
			for (j=0;j<4;j++)
				if	(max<(num[i][j]))
					max=num[i][j];
		printf("the Biggest number is %d\n",max);
		system("pause");
		exit(0);
	}
	else//随机生成2 4
	{
		again:i=rand()%(4+1)+0;
		j=rand()%(4+1)+0;
		k=rand()%2+1;
		if (num[i][j]==0)
			num[i][j]=k*2;
		else goto again;
	}		
}

void inw(int num[4][4])
{
	int i,j,a;
	for (a=0;a<4;a++)//先移动
		for(j=0;j<4;j++)
			for(i=0;i<4;i++)
				if (num[i][j]==0)
					if (i==3)
						continue;
					else	
					{
						num[i][j]=num[i+1][j];
						num[i+1][j]=0;
					}
	for(j=0;j<4;j++)//求和
	{
		a=0;
		for(i=0;i<3;i++)
			if(num[i][j]!=num[i+1][j])
				a=1;//a=0代表这列1234行全相等
		if (a==0)//4个数全相等
		{
			num[0][j]=num[0][j]*2;
			num[1][j]=num[0][j];
			num[2][j]=num[3][j]=0;
			continue;
		}
		if (num[0][j]==num[1][j] && num[2][j]==num[3][j] && num[1][j]!=num[2][j])//1和2相等 3和4相等
		{
			num[0][j]=num[0][j]*2;
			num[1][j]=num[2][j]*2;
			num[2][j]=num[3][j]=0;
			continue;
		}
		if (num[0][j]==num[1][j])//1和2相等
		{
			num[0][j]=num[0][j]*2;
			num[1][j]=num[2][j];
			num[2][j]=num[3][j];
			num[3][j]=0;
			continue;
		}
		if (num[1][j]==num[2][j])//2和3相等
		{
			num[1][j]=num[1][j]*2;
			num[2][j]=num[3][j];
			num[3][j]=0;
			continue;
		}
		if (num[2][j]==num[3][j])//3和4相等
		{
			num[2][j]=num[2][j]*2;
			num[3][j]=0;
			continue;
		}
	}
}
	
void ina(int num[4][4])
{
	int i,j,a;
	for (a=0;a<4;a++)//先移动
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				if (num[i][j]==0)
					if (j==3)
						continue;
					else	
					{
						num[i][j]=num[i][j+1];
						num[i][j+1]=0;
					}

	for(i=0;i<4;i++)//求和
	{
		a=0;
		for(j=0;j<3;j++)
			if(num[i][j]!=num[i][j+1])
				a=1;//a=0代表这列1234列全相等
		if (a==0)//4个数全相等
		{
			num[i][0]=num[i][0]*2;
			num[i][1]=num[i][0];
			num[i][2]=num[i][3]=0;
			continue;
		}
		if (num[i][0]==num[i][1] && num[i][2]==num[i][3] && num[i][1]!=num[i][2])//1列和2列相等 3列和4列相等
		{
			num[i][0]=num[i][0]*2;
			num[i][1]=num[i][2]*2;
			num[i][2]=num[i][3]=0;
			continue;
		}
		if (num[i][0]==num[i][1])//1和2相等
		{
			num[i][0]=num[i][0]*2;
			num[i][1]=num[i][2];
			num[i][2]=num[i][3];
			num[i][3]=0;
			continue;
		}
		if (num[i][1]==num[i][2])//2和3相等
		{
			num[i][1]=num[i][1]*2;
			num[i][2]=num[i][3];
			num[i][3]=0;
			continue;
		}
		if (num[i][2]==num[i][3])//3和4相等
		{
			num[i][2]=num[i][2]*2;
			num[i][3]=0;
			continue;
		}
	}
}

void ins(int num[4][4])
{
	int i,j,a;
	for (a=0;a<4;a++)//先移动
		for(j=0;j<4;j++)
			for(i=3;i>=0;i--)
				if (num[i][j]==0)
					if (i==0)
						continue;
					else	
					{
						num[i][j]=num[i-1][j];
						num[i-1][j]=0;
					}
	for(j=0;j<4;j++)//求和
	{
		a=0;
		for(i=0;i<3;i++)
			if(num[i][j]!=num[i+1][j])
				a=1;//a=0代表这列1234行全相等
		if (a==0)//4个数全相等
		{
			num[3][j]=num[3][j]*2;
			num[2][j]=num[3][j];
			num[1][j]=num[0][j]=0;
			continue;
		}
		if (num[0][j]==num[1][j] && num[2][j]==num[3][j] && num[1][j]!=num[2][j])//1和2相等 3和4相等
		{
			num[3][j]=num[3][j]*2;
			num[2][j]=num[1][j]*2;
			num[0][j]=num[1][j]=0;
			continue;
		}
		if (num[2][j]==num[3][j])//3和4相等
		{
			num[3][j]=num[3][j]*2;
			num[2][j]=num[1][j];
			num[1][j]=num[0][j];
			num[0][j]=0;
			continue;
		}
		if (num[1][j]==num[2][j])//2和3相等
		{
			num[2][j]=num[2][j]*2;
			num[1][j]=num[0][j];
			num[0][j]=0;
			continue;
		}
		if (num[0][j]==num[1][j])//1和2相等
		{
			num[1][j]=num[1][j]*2;
			num[0][j]=0;
			continue;
		}
	}
}

void ind(int num[4][4])
{
	int i,j,a;
	for (a=0;a<4;a++)//先移动
		for(i=0;i<4;i++)
			for(j=3;j>=0;j--)
				if (num[i][j]==0)
					if (j==0)
						continue;
					else	
					{
						num[i][j]=num[i][j-1];
						num[i][j-1]=0;
					}

	for(i=0;i<4;i++)//求和
	{
		a=0;
		for(j=0;j<3;j++)
			if(num[i][j]!=num[i][j+1])
				a=1;//a=0代表这列1234列全相等
		if (a==0)//4个数全相等
		{
			num[i][3]=num[i][3]*2;
			num[i][2]=num[i][2];
			num[i][0]=num[i][1]=0;
			continue;
		}
		if (num[i][0]==num[i][1] && num[i][2]==num[i][3] && num[i][1]!=num[i][2])//1列和2列相等 3列和4列相等
		{
			num[i][3]=num[i][3]*2;
			num[i][2]=num[i][1]*2;
			num[i][0]=num[i][1]=0;
			continue;
		}
		if (num[i][2]==num[i][3])//3和4相等
		{
			num[i][3]=num[i][3]*2;
			num[i][2]=num[i][1];
			num[i][1]=num[i][0];
			num[i][0]=0;
			continue;
		}
		if (num[i][1]==num[i][2])//2和3相等
		{
			num[i][2]=num[i][2]*2;
			num[i][1]=num[i][0];
			num[i][0]=0;
			continue;
		}
		if (num[i][0]==num[i][1])//1和2相等
		{
			num[i][1]=num[i][1]*2;
			num[i][0]=0;
			continue;
		}
	}	
}

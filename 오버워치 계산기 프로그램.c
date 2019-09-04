/*
오버워치 점수 계산 프로그램
작성자: 김준우
*/

#include <stdio.h>
#include <windows.h>

int p0to2000;   
int p2000to2500;
int p2500to3000;
int p3000to3250;
int p3250to3500;
int p3500to3750;
int p3750to4000;
int p4000to4100;
int p4100to4200;
int p4200to4300;
int p4300to4400;
int p4400to4450;
int p4450to4500;
int p4500to4550;
int p4550to4600;

void set_price_team()
{
	p0to2000=4500;
	p2000to2500=5500;
	p2500to3000=6000;
	p3000to3250=7000;
	p3250to3500=8500;
	p3500to3750=12000;
	p3750to4000=16000;
	p4000to4100=25000;
	p4100to4200=40000;
	p4200to4300=70000;
	p4300to4400=100000;
	p4400to4450=110000;
	p4450to4500=120000;
	p4500to4550=240000;
	p4550to4600=400000;
}

void set_price_team_duo()
{
	p0to2000=6000;
	p2000to2500=7500;
	p2500to3000=8000;
	p3000to3250=10000;
	p3250to3500=12000;
	p3500to3750=19000;
	p3750to4000=27000;
}

void set_price_not_team()
{
	p0to2000=3000;
	p2000to2500=3500;
	p2500to3000=4000;
	p3000to3250=5500;
	p3250to3500=6500;
	p3500to3750=9000;
	p3750to4000=12000;
	p4000to4100=18000;
	p4100to4200=30000;
	p4200to4300=50000;
	p4300to4400=65000;
	p4400to4450=80000;
	p4450to4500=90000;

}
int calculate(int startscore,int finishscore,int check_team)
{
	int price=0;

	if (check_team==3)
	{
		while(startscore!=finishscore)
	{
		if(startscore<2000)
		{
			price=price+(p0to2000/50);
		}
		else if(startscore<2500)
		{
			price=price+(p2000to2500/50);
		}
		else if(startscore<3000)
		{
			price=price+(p2500to3000/50);
		}	
		else if(startscore<3250)
		{
			price=price+(p3000to3250/50);
		}
		else if(startscore<3500)
		{
			price=price+(p3250to3500/50);
		}
		else if(startscore<3750)
		{
			price=price+(p3500to3750/50);
		}
		else if(startscore<4000)
		{
			price=price+(p3750to4000/50);
		}
		else
		{
			printf("ERROR: 계산허용범위 초과\n");
			printf("4000까지 계산된 가격을 반환합니다\n");
			return price;

		}
		startscore++;
	}
		return price;
	}
	else
	{
	while(startscore!=finishscore)
	{
		if(startscore<2000)
		{
			price=price+(p0to2000/50);
		}
		else if(startscore<2500)
		{
			price=price+(p2000to2500/50);
		}
		else if(startscore<3000)
		{
			price=price+(p2500to3000/50);
		}	
		else if(startscore<3250)
		{
			price=price+(p3000to3250/50);
		}
		else if(startscore<3500)
		{
			price=price+(p3250to3500/50);
		}
		else if(startscore<3750)
		{
			price=price+(p3500to3750/50);
		}
		else if(startscore<4000)
		{
			price=price+(p3750to4000/50);
		}
		else if(startscore<4100)
		{
			price=price+(p4000to4100/50);
		}
		else if(startscore<4200)
		{
			price=price+(p4100to4200/50);
		}
		else if(startscore<4200)
		{
			price=price+(p4100to4200/50);
		}
		else if(startscore<4300)
		{
			price=price+(p4200to4300/50);
		}
		else if(startscore<4400)
		{
			price=price+(p4300to4400/50);
		}
		else if(startscore<4450)
		{
			price=price+(p4400to4450/50);
		}
		else if(startscore<4500)
		{
			price=price+(p4450to4500/50);
		}
		else
		{
			if(check_team!=1) //기사
			{
				printf("ERROR: 계산허용범위 초과\n");
				printf("4500까지 계산된 가격을 반환합니다\n");
				return price;
			}
			else //팀장
			{
				if(startscore<4550)
				{
					price=price+(p4500to4550/50);
				}
				else if(startscore<4600)
				{
					price=price+(p4550to4600/50);
				}
				else
				{
					printf("ERROR: 계산허용범위 초과\n");
					printf("4600까지 계산된 가격을 반환합니다\n");
					return price;
				}
				
			}
		}
		startscore++;
	}

	return price;
	}
}
void simple_introduce()
{
	printf("오버워치 점수 계산기\n");
	printf("\n팀장용,기사용 계산 선택\n");
	printf("1번을 입력하시면 팀장용\n2번을 입력하시면 기사용입니다.\n3번을 입력하시면 팀장용듀오가격입니다.\n");

}

void simple_example()
{
	printf("\n입력 예시\n3500 4000\n\n");
	printf("출력 예시\n3500점에서 4000점 계산을 시작합니다.\n\n");	
}
void main()
{
 
   int startscore;
   int finishscore;
   int check_team;
   int price;
	
   simple_introduce();

	printf("숫자 입력:");
	scanf("%d",&check_team);
		
   while(1)
   {
	   if(check_team==1)
	   {
		   set_price_team();
	   }
	   else if(check_team==2)
	   {
		   set_price_not_team();
	   }
	   else
	   {
		   set_price_team_duo();
	   }
		
		simple_example();
		printf("시작점수와 마지막점수를 입력해주세요:");
		scanf("%d %d",&startscore ,&finishscore);

		printf("\n%d점에서 %d점 계산을 시작합니다\n\n\n",startscore, finishscore);

		price=calculate(startscore,finishscore,check_team);				
		printf("계산 가격 : %d",price);
		printf("\n");
   }
   

}


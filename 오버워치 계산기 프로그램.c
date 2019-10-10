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
void set_price_not_team_duo()
{
	p0to2000=3900;
	p2000to2500=4550;
	p2500to3000=5200;
	p3000to3250=7150;
	p3250to3500=8450;
	p3500to3750=13500;
	p3750to4000=18000;
}
void batch_calculate(int startscore,int win_count)
{
	int result=0;
	printf("배치계산을 시작합니다.\n");
	if(startscore< 3000)
  {
    result= 3000* win_count;
  }
  else if(startscore<3250)
  {
    result= 3500* win_count;
  }
  else if(startscore<3500)
  {
    result= 4000* win_count;
  }
  else if(startscore<3750)
  {
    result= 5000* win_count;
  }
  else if(startscore<4000)
  {
    result= 6000* win_count;
  }
  else if(startscore<4100)
  {
    result= 9000* win_count;
  }
  else if(startscore<4200)
  {
    result= 10000* win_count;
  }
  else if(startscore<4300)
  {
    result= 12000* win_count;
  }
  else if(startscore<4400)
  {
    result= 13000* win_count;
  }
  else if(startscore<4450)
  {
    result= 14000* win_count;
  }
  else if(startscore<4500)
  {
    result= 16000* win_count;
  }
  else
  {
    printf("ERROR : 4500 이하까지만 계산 가능합니다.");
	printf("계산된 가격: %d\n",result);
    return;
  }
  SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE), 4 ) ;
  printf("계산된 가격: %d\n",result);
  SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE), 7 ) ;				
}

void seungmu_calculate(int startscore,int count)
{
	int result=0;
	printf("승무계산을 시작합니다.\n");
	if(startscore< 3000)
  {
    result= 2000* count;
  }
  else if(startscore<3250)
  {
    result= 3000* count;
  }
  else if(startscore<3500)
  {
    result= 3000* count;
  }
  else if(startscore<3750)
  {
    result= 3000* count;
  }
  else if(startscore<4000)
  {
    result= 3000* count;
  }
  else if(startscore<4100)
  {
    result= 4000* count;
  }
  else if(startscore<4200)
  {
    result= 4000* count;
  }
  else if(startscore<4300)
  {
    result= 4500* count;
  }
  else if(startscore<4400)
  {
    result= 4500* count;
  }  
  else
  {
    printf("ERROR : 4400 이하까지만 계산 가능합니다.");
	printf("계산된 가격: %d\n",result);
    return;
  }
  SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE), 4 ) ;
  printf("계산된 가격: %d\n",result);
  SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE), 7 ) ;				
}

int calculate(int startscore,int finishscore,int check_team)
{
	int price=0;

	if (check_team==3 || check_team==4) /*듀오가격일 경우 4000까지 계산가능 조건문*/
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
	printf("1번을 입력하시면 팀장용\n2번을 입력하시면 기사용입니다.\n3번을 입력하시면 팀장용듀오가격입니다.\n4번을 입력하시면 기사용듀오가격입니다.\n5번을 입력하시면 기사용승무가격입니다.\n");

}

void simple_example()
{
	printf("\n입력 예시\n3500 4000\n\n");
	printf("출력 예시\n3500점에서 4000점 계산을 시작합니다.\n\n");	

	printf("\n입력 예시\n3500 10\n\n");
	printf("출력 예시\n배치계산을 시작합니다.\n\n");	
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
	   else if(check_team==3)
	   {
		   set_price_team_duo();
	   }
	   else if(check_team==4)
	   {
		   set_price_not_team_duo();
	   }
	   else
	   {

	   }
		
		simple_example();								
		if(check_team==5)
		{			
			printf("시작점수와 판수를 입력해주세요:");
			scanf("%d %d",&startscore ,&finishscore);
			seungmu_calculate(startscore,finishscore);
			continue;
		}
		else
		{
			printf("시작점수와 마지막점수를 입력해주세요:");
			scanf("%d %d",&startscore ,&finishscore);
		}
		if(finishscore <= 10 && finishscore>0 &&check_team==2) /* 기사용계산기이며 마무리점수가 0~10 사이일때는 배치계산적용*/
		{				
			batch_calculate(startscore,finishscore);
			continue;
		}		
		if(finishscore < startscore)
		{
			printf("\nERROR:마지막점수보다 시작점수가 더 큽니다\n");
			continue;
		}
		
		printf("\n%d점에서 %d점 계산을 시작합니다\n\n\n",startscore, finishscore);

		price=calculate(startscore,finishscore,check_team);		
		SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE), 4 ) ;
		printf("계산 가격 : %d",price);
		SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE), 7 ) ;
		printf("\n");
   }
   

}


/**********************************
 **   볼링 점수 계산 프로그램   ***
 **   작성자 : 문진석           ***
 **   작성일 : 2016년 4월 30일  ***

 **********************************/
#include <stdio.h>
int main(void)
{
	int k, n;
	int f1, f2, f3;		//각 프레임 입력값
	int s1, s2, s3;		//10프레임 입력값
	int bonus, total;	//보너스점수 유무, 총 점수
	
	bonus = 0;			//bonus ~ 1:스페어, 2:스트라이크
	n = 1;				//n번째 프레임
	k = 1;				//곱 상수

	while(n < 10)		//1~9프레임 반복문
	{
		printf("%d번째 프레임 1 번째 처리 핀 수 : ", n);
		scanf("%d", &f1);		//1번째 처리 핀 수 입력
		total = total + f1*k; 	//1번째 처리 후 점수

		if(bonus != 2) k=1;		//이전 프레임 스트라이크 여부 파악

		printf("**** 현재까지 점수 : %d\n", total);	//현재까지 점수 출력

		if(f1 != 10)	//스트라이크? 아니라면 2프레임 2번째로
		{	
			printf("%d번째 프레임 2 번째 처리 핀 수 : ", n);
			scanf("%d", &f2);		//2번째 처리 핀 수 입력
			if( k == 3 ) k=2;
			total = total + f2*k;	//2번째 처리 후 점수
			f3 = f1 + f2;			//현재 프레임 점수 합 > 스페어 여부 확인
			printf("**** 현재까지 점수 : %d\n", total);
			if( f3 == 10 )	//스페어? > bonus 표시, 곱 상수 적용
			{	bonus = 1;
				k=2;		}
			else
			{	bonus = 0;
				k=1;		}
		}
		else 			
		{	bonus = 2;		//스트라이크인 경우 이므로 bonus = 2로 지정
			k++;		}	//이전 프레임도 스트라이크 였으면 보너스 점수가 두번이므로 k=3
	
		n++;	//n번째 프레임
		if(k > 3)	k = 3;	//한 프레임에 얻을 수 있는 점수는 최대 30점(보너스점수 포함)
	}
	
	if(bonus == 0) k=1;		//9프레임이 아무것도 아닐경우
	if(bonus == 1) k=2;		//9프레임이 스페어일 경우 보너스 점수
							//9프레임이 스트라이크 였을 경우 k=2 혹은 3으로 지정되어 있음

	printf("10번째 프레임 1 번째 처리 핀수 : ");
	scanf("%d", &s1);		//10프레임 1번째 처리 핀 수 입력
	total = total + s1*k;	//1번째 처리 후 점수
	printf("**** 현재까지 점수 : %d\n", total);	//현재까지 점수 출력
	if(k == 3) k--;		//더블(스트라이크2번연속)이었을 경우 k값을 줄여야함

	printf("10번째 프레임 2 번째 처리 핀수 : ");
	scanf("%d", &s2);		//10프레임 2번째 처리 핀 수 입력
	if(bonus == 1) k=1;		//이전 프레임이 스페어일 경우 10-2에서는 보너스 점수가 없음
	total = total + s2*k;	//2번째 처리 후 점수

	if(s1 != 10 && (s1+s2) != 10)	//스트라이크 혹은 스페어가 나온경우 1회 더 가능
	{	printf("**** 최종 점수 : %d\n", total);	//아닐 경우 최종 점수 출력
		return 0; }			//종료
	else printf("**** 현재까지 점수 : %d\n", total);	//현재 점수 출력
	k=1;
	
	printf("10번째 프레임 3 번째 처리 핀수 : ");	//1회 보너스게임
	scanf("%d", &s3);
	total = total + s3*k;
	printf("**** 최종 점수 : %d\n", total);		//최종점수 출력

	return 0;	//종료
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int menu();
void monty_open(int sel, int *com, int *open);
void monty_result(int sel, int *com, double *cnt, double *wcnt);

int main() {
	srand(time(NULL));
	
	int com, sel, try, open, change, mode = menu();
	double cnt = 0, wcnt = 0, prob =0;
	
	//수동모드 선택시
	if(mode == 1) { 
		while(1) {
			system("cls");
			
			//랜덤으로 차가 있는 문 선택
			com = rand()%3 + 1;
			
			printf("시도 횟수 : %.0lf\n맞춘 횟수 : %.0lf\n맞춘 확률 : %.2lf%%\n", cnt, wcnt, prob);
			
			printf("		   문 선택\n1번문 | 2번문 | 3번문\n");
			
			while(1) {
				scanf("%d", &sel);
				
				if(sel == 1 || sel == 2 || sel ==3) {
					break;
				}
				printf("잘못된 숫자를 입력하였습니다.\n");
			}
			
			printf("\n\n");
			
			//open 함수 실행
			monty_open(sel, &com, &open);
			
			//바꿀 기회 제공
			printf("문을 바꾸시겠습니까?(이전 선택 :  %d번문, 염소가 있는 문 : %d번문)\n",sel, open);
			printf("1번문 | 2번문 | 3번문\n");
			while(1) {
				scanf("%d", &sel);
				if(sel == 1 || sel == 2 || sel ==3) {
					break;
				}
				printf("잘못된 숫자를 입력하였습니다.\n");
			}
			
			monty_result(sel, &com, &cnt, &wcnt);
			
			prob = wcnt/cnt *100;
		}
	}
	//자동 모드 선택시
	else if (mode == 2) {
		while (1) {
			system("cls");
			printf("실행 횟수 : ");
			
			scanf("%d", &try);
			
			while(1) {
				if(try >= 1) {
					break;
				}
				printf("잘못된 값을 입력했습니다");
			}
			for(int i = 0; i < try; i++) {
				system("cls");
				
				com = rand() % 3 + 1;
				
				printf("시도 횟수 : %.0lf\n맞춘 횟수 : %.0lf\n맞춘 확률 : %.2lf%%\n", cnt, wcnt, prob);
				printf("		   문 선택\n");
				printf("1번문 | 2번문 | 3번문\n");
				Sleep(10);
				
				sel = rand()%3 + 1;
				printf("%d\n\n", sel);
				
				monty_open(sel, &com, &open);
				
				//바꿀 기회 제공
				printf("문을 바꾸시겠습니까?(이전 선택 :  %d번문, 염소가 있는 문 : %d번문)\n",sel, open);
				printf("1번문 | 2번문 | 3번문\n");
				Sleep(10);
				
				//무조건 바꾸는 경우
				for(int i = 1; i <= 3; i++) {
					if(i != sel && i != open) {
						change = i;
						break;
					}
				}
				
				monty_result(change, &com, &cnt, &wcnt);
				
				prob = wcnt/cnt *100;
			}
			
			char anw;
			printf("계속 하시겠습니까?(y/n)");
			while (1) {
				scanf(" %c", &anw);
				if(anw == 'y' || anw == 'Y') {
					break;
				}
				else if (anw == 'n' || anw == 'N') {
					return 1;
				}
				printf("잘못 입력하였습니다");
			}
		}
	}
	
	return 0;
}

int menu() {
	int m_sel;
	
	printf("    몬티홀의 딜레마\n1.수동모드\n2.자동모드\n");
	while(1) {
		scanf("%d", &m_sel);
		if(m_sel == 1 || m_sel == 2) {
			return m_sel;
		}
		printf("잘못된 숫자를 입력하였습니다.\n");
	}
}


void monty_open(int sel, int *com, int *open) {		
	// 문 열기
	while(1) {
		(*open) = rand()%3 + 1;
		if ((*open) != sel && (*open) != com) {
			printf("염소가 있는 문은 %d번 문 입니다.\n\n", *open);
			break;
		}
	}
}

void monty_result(int sel, int *com, double *cnt, double *wcnt) {
	
	//선택한 문에 차가 있는경우
	if(sel == (*com)) {
		printf("자동차를 획득하셨습니다!\n");
		(*wcnt)++;
	}
	//선택한 문에 염소가 있는 경우
	else if(sel != (*com)) {
		printf("염소를 획득 하셨습니다.ㅠ\n");
	}
	
	(*cnt)++;
	
	Sleep(50);
}
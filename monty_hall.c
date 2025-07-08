#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define GOAT 1
#define CAR 2

int mix();
int comp(int num, int arr1[][3], int arr2[]);
void print_arr(int arr[]);
void mont();

int main() {
	mont();
	
	return 0;
}

void mont() {
	srand(time(NULL));
	int num, sel;
	int at_sel;
	double cnt, wcnt,prob;
	int door[3][3] = {
								{1, 1, 2},
								{1, 2, 1},
								{2, 1, 1}
								};
	int select[3];
	
	while(1) {
		system("cls");
		printf("시도 횟수 : %.0lf\n맞춘 횟수 : %.0lf\n맞춘 확률 : %.2lf%%\n", cnt, wcnt, prob);
	
	select[0] = 1;
	select[1] = 1;
	select[2] = 1;
	
	num = mix();	//어느 문에 차가 있를지 고르기
	
	printf("		   문 선택\n");
	printf("1번문 | 2번문 | 3번문\n");
	scanf("%d", &sel);
	
	select[sel - 1]++;
	
	printf("\n\n");
	
	int open;
	
	while(1) {
		open = rand()%3;
		if (open + 1 != sel && door[num][open] != 2) {
			printf("염소가 있는 문은 %d번 문 입니다.\n\n", open+1);
		break;
		}
	}
	
	printf("문을 바꾸시겠습니까?(이전 선택 :  %d번문, 염소가 있는 문 : %d번문)\n",sel, open+1);
	printf("1번문 | 2번문 | 3번문\n");
	scanf("%d", &sel);
	
	select[0] = 1;
	select[1] = 1;
	select[2] = 1;
	select[sel - 1]++;
	
	if(comp(num,door,select) == 1) {
		printf("자동차를 획득하셨습니다!\n");
		wcnt++;
	}
	else if(comp(num,door,select) == 0) {
		printf("염소를 획득 하셨습니다.ㅠ\n");
	}
	cnt++;
	
	prob = (wcnt/cnt)*100;
	
	Sleep(1000);
	}
	}

int mix() {
	int num = rand() % 3;
	return num;
}

//고른 문이 맞으면 1, 아니면 0 반환
int comp(int num, int arr1[][3], int arr2[]) {
	for(int i = 0; i <3; i++) {
		if(arr1[num][i] != arr2[i])
		return 0;
	}
	return 1;
}


void print_arr(int arr[]) {
	for(int i = 0; i < 3; i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
}
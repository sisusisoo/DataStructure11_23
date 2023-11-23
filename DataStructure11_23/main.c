#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20


int compare_count, move_count;
int c_total, m_total;
int once;//처음 한번의 싸이클에서만 출력되게 





void print_all(int list[]) {
	for (int i = 0; i < MAX; i++) {
		printf("%d->", list[i]);

	}
	printf("\n");
}

//삽입정렬 
void insertion_sort(int list[], int first, int last, int gap) {
	int i, j, key;
//	printf("gap:%d\n", gap);
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
	
		for (j = i - gap; j >= first && key < list[j]; j = j - gap) {
			
			list[j + gap] = list[j];
			//비교,이동 카운트 
			compare_count++;
			move_count++;
		}
	
		//key를 빠뀔자리에 삽입 카운트 제자리를 옮기는건 카운트 하지 않는다.
		if (list[j + gap] != key) {
			list[j + gap] = key;
			move_count++;
		}
	

	}
}

//쉡정렬 
void shell_sort(int list[], int n) {
	int i, gap;
	for (gap = n / 2; gap > 0; gap = gap / 2) {//n 이 20이니까 처음에 10부터 5->2->1
		if ((gap) % 2 == 0) gap++;//gap에서2나누고 나머지가 0일경우 +1 짝수 x?
		for (i = 0; i < gap; i++) {//gap값은 10->5->3->1
			insertion_sort(list, i, n - 1, gap);
			if (once == 0)print_all(list);
		}
	}
}

void shell_sort_cycle() {
	//카운트 횟수 초기화
	compare_count = 0;
	move_count = 0;



	int i;

	int n = MAX;
	int list[MAX];

	if (once == 0)printf("초기값\n");
	for (i = 0; i < n; i++) {
		list[i] = rand() % 100;
		if (once == 0)printf("%d->", list[i]);

	}
	if (once == 0) {
		printf("\n");
		printf("\n");
	}
	shell_sort(list, MAX);
	

	if (once == 0) {
		printf("compare count : %d\n", compare_count);
		printf("move count : %d\n", move_count);
	}
	//printf("rand %d", rand() % 100);
	c_total += compare_count;
	m_total += move_count;

}


void main() {
	srand(time(NULL));
	shell_sort_cycle();

	once = 1;//뒤에 싸이클에서는 출력 x
	for (int i = 0; i < 19; i++) {
		shell_sort_cycle();
	
	
	}

	
	printf(" compare count avg:%f\n ", (float)c_total / (float)20);
	printf("move count avg:%f\n ", (float)m_total / (float)20);


}
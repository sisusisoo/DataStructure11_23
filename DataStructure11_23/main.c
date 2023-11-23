#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20


int compare_count, move_count;
int c_total, m_total;
int once;//ó�� �ѹ��� ����Ŭ������ ��µǰ� 





void print_all(int list[]) {
	for (int i = 0; i < MAX; i++) {
		printf("%d->", list[i]);

	}
	printf("\n");
}

//�������� 
void insertion_sort(int list[], int first, int last, int gap) {
	int i, j, key;
//	printf("gap:%d\n", gap);
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
	
		for (j = i - gap; j >= first && key < list[j]; j = j - gap) {
			
			list[j + gap] = list[j];
			//��,�̵� ī��Ʈ 
			compare_count++;
			move_count++;
		}
	
		//key�� �����ڸ��� ���� ī��Ʈ ���ڸ��� �ű�°� ī��Ʈ ���� �ʴ´�.
		if (list[j + gap] != key) {
			list[j + gap] = key;
			move_count++;
		}
	

	}
}

//�v���� 
void shell_sort(int list[], int n) {
	int i, gap;
	for (gap = n / 2; gap > 0; gap = gap / 2) {//n �� 20�̴ϱ� ó���� 10���� 5->2->1
		if ((gap) % 2 == 0) gap++;//gap����2������ �������� 0�ϰ�� +1 ¦�� x?
		for (i = 0; i < gap; i++) {//gap���� 10->5->3->1
			insertion_sort(list, i, n - 1, gap);
			if (once == 0)print_all(list);
		}
	}
}

void shell_sort_cycle() {
	//ī��Ʈ Ƚ�� �ʱ�ȭ
	compare_count = 0;
	move_count = 0;



	int i;

	int n = MAX;
	int list[MAX];

	if (once == 0)printf("�ʱⰪ\n");
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

	once = 1;//�ڿ� ����Ŭ������ ��� x
	for (int i = 0; i < 19; i++) {
		shell_sort_cycle();
	
	
	}

	
	printf(" compare count avg:%f\n ", (float)c_total / (float)20);
	printf("move count avg:%f\n ", (float)m_total / (float)20);


}
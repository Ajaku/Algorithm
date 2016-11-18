#include <stdi
#define MAX_QUEUE 100

int enqueue(int Q[], int *tail, int *n, int value){
	*tail = *tail + 1;
	if (*tail>=MAX_QUEUE){
		*tail = 0;
	}

	*n = *n + 1;
	Q[*tail] = value;
	return 0;
}

int get_f(int Q[], int head){
	if (head+1<MAX_QUEUE){
		return Q[head + 1];
	}
	else{
		return Q[0];
	}
}

int dequeue(int Q[], int *head, int *n){
	*head = *head + 1;
	if(*head>=MAX_QUEUE){
		*head = 0;
	}

	*n = *n - 1;
	return 0;
}

int main(void){
	int Q[MAX_QUEUE];
	int a, i, head=0, tail=0, n=0;
	for (i=0; i<10; i++){
		printf("整数を入力：");
		scanf("%d", &a);
		enqueue(Q, &tail, &head, a);
	}

	head = 0;

	for (i=0; i<10; i++){
		printf("整数：%d\n", get_f(Q,head));
		dequeue(Q, &head, &tail);
	}
		return 0;

}
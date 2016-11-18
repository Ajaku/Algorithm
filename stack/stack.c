#include <stdio.h>
#define MAX_STACK 100

int pushidown(int S[], int *t, int value){
	*t = *t + 1;
	S[*t] = value;
	return 0;
}

int get_top(int S[], int t){
	return S[t];
}

int popup(int S[], int *t){
	*t = *t - 1;
}

int main(void){
	int S[MAX_STACK];
	int a, i, top=0;
	for(i=0;i<10;i++){
		printf("®”‚ð“ü—Í:");
		scanf("%d",&a);
		pushidown(S, &top, a);
	}

	for(i=0;i<10;i++){
		printf("’l:%d\n",get_top(S,top));
		popup(S, &top);
	}

	return 0;
}

#include <stdio.h>

void swap(int *mas, int i, int j){
	int k;
	k = mas[i];
	mas[i] = mas[j];
	mas[j] = k;
}

int partition(int *mas, int n){
	int pivot = mas[n / 2];
	int i, j;
	j = n;
	while(i != j){
		if(mas[i] < pivot){
			i++;
		}
		if(mas[j] > pivot){
			j--;
		}
		swap(mas, i, j);
	}
	return i;
}

void qsort(int *mas, int n){
	int k = partition(mas, n);
	if(k >= 1){
		qsort(mas, k);
		qsort(mas, k + 1);
	}	
}

int main(){
	
}

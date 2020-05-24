#include <stdio.h>

void swap(int *mas, int i, int j){
	int k;
	k = mas[i];
	mas[i] = mas[j];
	mas[j] = k;
}

int partition(int *mas, int s, int n){
	int pivot = mas[n / 2];
	int i, j;
	j = n;
	i = s;
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

void qsort(int *mas, int s, int n){
	int k = partition(mas, s, n);
	if(k >= 1){
		qsort(mas, s, k);
		qsort(mas, k + 1, n);
	}	
}

int main(){
	
}

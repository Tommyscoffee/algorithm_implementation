#include <stdio.h>
//二分探索法ではあらかじめソートされたデータを使う。
//データを２等分して探索範囲の中央値のデータと探索データを比較して、小さかったら前半、大きかったら後半と調べていくのを繰り返す。
//中央値を比較することで、もしデータが奇数だった場合は２等分されない中央値で判断するため？
//https://dev.grapecity.co.jp/support/powernews/column/clang/054/page03.htm
void	*asort(int *a,int idx);
int	binary_SM(int *a, int idx, int target);
int	main()
{
	int	A[11]={1,3,7,2,5,12,42,57,32,21,10};
	int	i;
	int	ans = 0;

	asort(A,11);
	for (i = 0; i < 11;i++)
		printf("%d ,",A[i]);//{1 ,2 ,3 ,5 ,7 ,10 ,12 ,21 ,32 ,42 ,57}
	
	ans = binary_SM(A,11,2);
	printf("\n-----------target is \n%d でidx=[%d]\n",A[ans],ans);
	return (0);
}

void	*asort(int *a, int idx){
	int	i =0;
	int	j =0;
	for (i = 0; i < idx;i++){
		for(j = i+1; j < idx; j++){
			int tmp =0;
			if (a[i] > a[j]){
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
		
	}
	return (NULL);
}

int	binary_SM(int *a, int idx, int target){
	int	i=0;
	int	low = 0;
	int	high = idx -1;//
	int	median = 0;
	while (low < high){
		median = (low + high)/2;
		printf("\n%d番目のmedianは[%d]で値は{%d}\n",++i,median,a[median]);
		if (a[median] == target)
			break;
		else if (a[median] > target){
			high = median - 1;
		}
		else{
			low = median + 1;
		}
		// printf("%d回目\n",i);
	}

	return (median);
}
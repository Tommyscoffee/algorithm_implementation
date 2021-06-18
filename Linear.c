#include <stdio.h>
int linear(int *a,int x);
//線形探索法は、配列の最後の後ろに、探索データを追加しておくことで、その配列内だけを調べることができる。このデータを「番兵」と呼ぶ。
int	main()
{
	int	A[6]={1,4,5,3,2};//探す配列
	int	x = 10;//探索データ
	A[5] = x;//番兵として配列の最後に追加しておく。
	int	ans=0;

	ans = linear(A,x);

	printf("%d\n",ans);//
	
	return (0);
	
}
int linear(int *a,int x)
{
	int i=0;
	// int j=0;

	// while (1){
	// 	if (a[i] == x)
	// 		break;
	// }
	for (i = 0; a[i] != x;i++);

	return (i);

}
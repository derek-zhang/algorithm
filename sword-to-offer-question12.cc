#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <memory.h>


using namespace std;

#if 0
int main(){
	int a[] = {1,2,3};
	do{
		     cout << a[0] << " " << a[1] << " " << a[2] << endl;
	}
	while (next_permutation(a,a+3));
	return 0;
}
#endif
void myprint(char *a, int n)
{
	int i = 0;
	while(a[i] == '0') i++;
	while(i<n)
	printf("%c", (a[i++]));
	putchar('\n');
}

void permute(char *a, int n, int index)
{
	if (index == n) {
		myprint(a, n);
		return;
	}

	int i;
	for (i = 0; i < 10; i++) {
		a[index] = '0' + i;
		permute(a, n, index+1); 

	}
}

int main()
{
	int n;
	scanf("%d", &n);
	char *a = (char *)new char(n+1);
	memset(a, 0, n+1);
	int i;
	//for (i = 0; i < n; i++) {
	//	a[0] = '0' + i;
	//	permute(a, n, i);
	//}
	permute(a, n, 0);
	delete[] a ;
}

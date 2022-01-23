#include "allhead.h"
using namespace std;

int main()
{
	char pp[100];					//输入的字符数组
	int ii = -1;							//输入字符数组计数

	while (pp[ii] != '\n') {
		ii++;
		pp[ii] = getchar();
	}

	count1(pp,ii);


	//system("pause");
	return 0;
}
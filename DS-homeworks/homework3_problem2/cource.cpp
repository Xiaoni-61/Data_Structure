#include "allhead.h"
using namespace std;

int main()
{
	char pp[100];					//������ַ�����
	int ii = -1;							//�����ַ��������

	while (pp[ii] != '\n') {
		ii++;
		pp[ii] = getchar();
	}

	count1(pp,ii);


	//system("pause");
	return 0;
}
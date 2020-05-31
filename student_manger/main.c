#include "student.h"

int main(void)
{
	system("color f0\n");//°×µ×ºÚ×Ö
	int n;
	menu();
	scanf("%d",&n);
	while(n) {
		switch (n) {
			case 1:
				in();
				break;
			case 2:
				search();
				break;
			case 3:
				del();
				break;
			case 4:
				modify();
				break;
			case 5:
				insert();
				break;
			case 6:
				order();
				break;
			case 7:
				total();
				break;
			case 8:
				show();
				break;
			default:
				break;
			
		}
		fflush(stdin);
		//getchar();
		menu();
		scanf("%d",&n);
	}
	return 0;
}
#include "menu.h"
#include "game.h"
#include <stdio.h>

//������

int main() {

	int choice;
	do {
		menu();
		printf("��ѡ��>>> ");
		scanf("%d", &choice);
		printf("\n");
		switch (choice) {
			case 0:
				//�˳�cmd����
				break;
			case 1:
				game();
				break;
			default:
				printf("�������������\n");
				break;
		}
	} while (choice);
	return 0;
}
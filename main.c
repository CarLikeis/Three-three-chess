#include "menu.h"
#include "game.h"
#include <stdio.h>

//主程序

int main() {

	int choice;
	do {
		menu();
		printf("请选择>>> ");
		scanf("%d", &choice);
		printf("\n");
		switch (choice) {
			case 0:
				//退出cmd界面
				break;
			case 1:
				game();
				break;
			default:
				printf("输入错误，请重试\n");
				break;
		}
	} while (choice);
	return 0;
}
#include<stdio.h>
#include<Windows.h>
#include"snake.h"

void main() {
	int ekey = 75;
	init();				// ������ �ʱ�ȭ �Լ�

	while (1) {

		if (_kbhit()) {			// Ű���� �Է��� ������ 1, ������ 0�� ����
			ekey = _getch();	// �Է¹��� Ű ���� ����
			_flushall();
		}
		update(ekey);			// ���� ������Ʈ
		draw();					// ȭ�鿡 ���
		if (result == 1) {
			printf("Lose!\n");
			break;
		}
		if (result == 2) {
			printf("Win!\n");
			break;
		}
		Sleep(50);
	}
	release();
}

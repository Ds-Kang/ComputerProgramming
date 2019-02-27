#include<stdio.h>
#include<Windows.h>
#include"snake.h"

void main() {
	int ekey = 75;
	init();				// 변수값 초기화 함수

	while (1) {

		if (_kbhit()) {			// 키보드 입력이 있으면 1, 없으면 0을 리턴
			ekey = _getch();	// 입력받은 키 값을 받음
			_flushall();
		}
		update(ekey);			// 변수 업데이트
		draw();					// 화면에 출력
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

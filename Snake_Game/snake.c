#include"snake.h"
#include <stdlib.h>
#include <time.h>

void init() {
	sInit();
	result = 0;
	printf("Enter the number of items: ");
	scanf("%d", &obj.num);
	srand(time(NULL));
	for (int i = 0; i < obj.num; i++) {
		obj.item[i].x = rand() % 40  + 1;
		obj.item[i].y = rand() % 20 + 1;
	}
	sn.ht[0].x = rand() % 34 + 1;
	sn.ht[0].y = rand() % 20 + 1;
	for (int i = 0; i < obj.num;i++) {
		if (sn.ht[0].x == obj.item[i].x && sn.ht[0].y == obj.item[i].y) init();
	}
	for (int i = 1; i <= 5; i++) {
		sn.ht[i].x = sn.ht[0].x + i;
		sn.ht[i].y = sn.ht[0].y;
	}
}

void update(int way) {

	sntmp = sn;
	if (way == 75) {
		if (sn.ht[0].x != 1) sn.ht[0].x -= 1;
		else return;
	}
	if (way == 77) {
		if (sn.ht[0].x != 40) sn.ht[0].x += 1;
		else return;
	} 
	if (way == 80) {
		if (sn.ht[0].y != 20) sn.ht[0].y += 1;
		else return;
	} 
	if (way == 72) {
		if (sn.ht[0].y != 1) sn.ht[0].y -= 1;
		else return;
	} 
	for (int i = 0; i < 5; i++) {
		sn.ht[i + 1].x = sntmp.ht[i].x;
		sn.ht[i + 1].y = sntmp.ht[i].y;
	}
	//move
	for (int i = 2; i < 6; i++) {
		if (sn.ht[0].x == sn.ht[i].x && sn.ht[0].y == sn.ht[i].y) {
			result = 1;
		}
	}
	for (int i = 0; i < obj.num; i++) {
		if (sn.ht[0].x == obj.item[i].x && sn.ht[0].y == obj.item[i].y) {
			obj.item[i].x = -1;
		}
	}
	//collision
}
 


void draw() {
	sClear();
	for (int i = 0; i < 42; i++) {
		for (int j = 0; j < 22; j++) {
			if (i == 0 || i == 41 || j == 0 || j == 21) {
				sPrint(2*i, j, "¡à");
			}
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < obj.num; i++) {
		if (obj.item[i].x == -1) {
			cnt++;
			if (cnt == obj.num) {
				result = 2;
			}
			continue;
		}
		else {
			sPrint(2*obj.item[i].x, obj.item[i].y, "¢½");
		}
	}
	sPrint(2*sn.ht[0].x, sn.ht[0].y, "¡Ý");
	for (int i = 1; i < 6; i++) {
		sPrint(2*sn.ht[i].x, sn.ht[i].y, "¡Þ");
	}
	sFlipping();
}

void release() {
	sRelease();
}

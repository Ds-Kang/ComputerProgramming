#pragma once
#ifndef _SNAKE_H
#define _SNAKE_H

#include<stdio.h>
#include<conio.h>

#include"screen.h"


typedef struct _pos {
	int x, y;
}pos;

typedef struct _object {
	int num;
	pos item[10];
}object;

typedef struct _snake {
	pos ht[6];
}snake;

int result;
snake sn,sntmp;
object obj;


void init();
void update(int);
void draw();
void release();


#endif
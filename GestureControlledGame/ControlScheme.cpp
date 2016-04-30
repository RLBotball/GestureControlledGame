#include "stdafx.h"
#define WINVER 0x0500
#include <windows.h>
#include "GameControl.h"

const int SCREEN_WIDTH = 100;
const int SCREEN_HEIGHT = 100;

void executeControl(handInfo in, int type) {
	if (type == 1) {
		convertSwipeHold(in);
	} else if (type == 2) {
		convertSwipeTap(in);
	} else if (type == 3) {
		convertLinear(in);
	} else if (type == 4) {
		convert1to1(in);
	}
}

struct handInfo {
	int x;
	int y;
	int maxx;
	int maxy;

	int startx; //hand starting pos
	int starty;

};

struct handInfo a;

void convert1to1(handInfo in) {
	struct handInfo out;
	out.x = in.x;
	out.y = in.y;
}

int boxx = 20;
int boxy = 25;

void convertSwipeHold(handInfo in) {
	int topBound = in.starty - boxy;
	int bottomBound = in.starty + boxy;
	int leftBound = in.startx - boxx;
	int rightBound = in.startx + boxx;

	if (in.y < topBound) { pressUp(); }
	else if (in.y > bottomBound) { pressDown(); }
	else if (in.x < leftBound) { pressLeft(); }
	else if (in.x > rightBound) { pressRight(); }
	else { unPressAll(); }
}

void convertSwipeTap(handInfo in) {
	int topBound = in.starty - boxy;
	int bottomBound = in.starty + boxy;
	int leftBound = in.startx - boxx;
	int rightBound = in.startx + boxx;

	if (in.y < topBound) { tapUp(); }
	else if (in.y > bottomBound) { tapDown(); }
	else if (in.x < leftBound) { tapLeft(); }
	else if (in.x > rightBound) { tapRight(); }
	else { unPressAll(); }
}

void convertLinear(handInfo in) {
	int lockX = 50;	
	
	INPUT buffer;
	MouseSetup(&buffer);
	MouseMoveAbsolute(&buffer, lockX, in.y/in.maxy*SCREEN_HEIGHT);
}

auto kappa = convert1to1;

void test() {
	struct handInfo a;
	a.x = 10;
	a.y = 10;

	kappa(a);
}
#pragma once
#include "stdafx.h"
void pressUp();
void pressDown();
void pressLeft();
void pressRight();

void tapKeys(int key1, int key2);
void unPressKeys(int key1, int key2);
void pressKeys(int key1, int key2);
void pressKey(int key);
void unPressAll();

void tapUp();
void tapLeft();
void tapRight();
void tapDown();

void MouseSetup(INPUT *buffer);
void MouseMoveAbsolute(INPUT *buffer, int x, int y);
void MouseClick(INPUT *buffer);
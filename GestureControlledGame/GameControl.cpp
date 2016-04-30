#include "stdafx.h"
#define WINVER 0x0500
#include <windows.h>

const int SCREEN_WIDTH = 100;
const int SCREEN_HEIGHT = 100;

void pressKey(int key) {
	keybd_event(key, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
	Sleep(100);
	keybd_event(key, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
}

void pressKeys(int key1, int key2) {
	keybd_event(key1, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
	keybd_event(key2, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
}

void unPressKeys(int key1, int key2) {
	keybd_event(key1, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
	keybd_event(key2, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
}

void tapKeys(int key1, int key2) {
	pressKeys(key1, key2);
	Sleep(100);
	unPressKeys(key1, key2);
}

void pressUp() {
	pressKeys(0x57, VK_UP);
}

void pressLeft() {
	pressKeys(0x41, VK_LEFT);
}

void pressDown() {
	pressKeys(0x53, VK_DOWN);
}

void pressRight() {
	pressKeys(0x44, VK_RIGHT);
}

void unPressUp() {
	unPressKeys(0x57, VK_UP);
}

void unPressLeft() {
	unPressKeys(0x41, VK_LEFT);
}

void unPressDown() {
	unPressKeys(0x53, VK_DOWN);
}

void unPressRight() {
	unPressKeys(0x44, VK_RIGHT);
}

void tapUp() {
	tapKeys(0x57, VK_UP);
}

void tapLeft() {
	tapKeys(0x41, VK_LEFT);
}

void tapDown() {
	tapKeys(0x53, VK_DOWN);
}

void tapRight() {
	tapKeys(0x44, VK_RIGHT);
}

void unPressAll() {
	unPressRight();
	unPressLeft();
	unPressDown();
	unPressUp();
}

void WSADTest() {
	Sleep(1000);
	pressDown();
	Sleep(500);
	pressUp();
	Sleep(500);
	pressRight();
	Sleep(500);
	pressLeft();
}

void MouseSetup(INPUT *buffer)
{
	buffer->type = INPUT_MOUSE;
	buffer->mi.dx = (0 * (0xFFFF / SCREEN_WIDTH));
	buffer->mi.dy = (0 * (0xFFFF / SCREEN_HEIGHT));
	buffer->mi.mouseData = 0;
	buffer->mi.dwFlags = MOUSEEVENTF_ABSOLUTE;
	buffer->mi.time = 0;
	buffer->mi.dwExtraInfo = 0;
}


void MouseMoveAbsolute(INPUT *buffer, int x, int y)
{
	buffer->mi.dx = (x * (0xFFFF / SCREEN_WIDTH));
	buffer->mi.dy = (y * (0xFFFF / SCREEN_HEIGHT));
	buffer->mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE);

	SendInput(1, buffer, sizeof(INPUT));
}


void MouseClick(INPUT *buffer)
{
	buffer->mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN);
	SendInput(1, buffer, sizeof(INPUT));

	Sleep(10);

	buffer->mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTUP);
	SendInput(1, buffer, sizeof(INPUT));
}

void MouseTest() {

	INPUT buffer;

	Sleep(2000);
	MouseSetup(&buffer);
	MouseMoveAbsolute(&buffer, 10, 10);
	Sleep(1000);
	//MouseSetup(&buffer);
	MouseMoveAbsolute(&buffer, 10, 90);
	Sleep(1000);
	//MouseSetup(&buffer);
	MouseMoveAbsolute(&buffer, 90, 10);
	Sleep(1000);
	//MouseSetup(&buffer);
	MouseMoveAbsolute(&buffer, 90, 90);
	Sleep(1000);


	MouseClick(&buffer);
	Sleep(500);
}
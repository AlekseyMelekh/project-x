//Этот класс помогает нам двигать камеру происходящего на карте, эту камеру мы закрепили за главным персонажем

#pragma once

#include <SDL.h>

#include "Define.h"

enum {
	TARGET_MODE_NORMAL = 0,
	TARGET_MODE_CENTER
};

class Camera {
public:
	static Camera CameraControl;

private:
	int X;
	int Y;

	int* TargetX;
	int* TargetY;

public:
	int TargetMode;

public:
	Camera();

public:
	void OnMove(int MoveX, int MoveY);

public:
	int GetX();
	int GetY();

public:
	void SetPos(int X, int Y);

	void SetTarget(int* X, int* Y);
};

#include "stdafx.h"
#include "gameChara.h"

gameChara::gameChara()
{
	pos = { 10,20 };
	speed = 50;
	moveDir = { 1, 0 };
	std::cout << "私は生まれた" << std::endl;
}

gameChara::gameChara(Vec2 _pos, double _speed,
		Vec2 _dir, String _tex, bool _isAI)
{
	pos = _pos;
	speed = _speed;
	moveDir = _dir;
	tex = TextureAsset(_tex);
	isAI = _isAI;
	std::cout << "私はパラメータ付きで生まれた" << std::endl;
}

direction gameChara::GetDirection()
{
	if ((KeyUp | KeyW).pressed())
	{
		return UP;
	}
	else if ((KeyLeft | KeyA).pressed())
	{
		return LEFT;
	}
	else if ((KeyDown | KeyS).pressed())
	{
		return DOWN;
	}
	else if ((KeyRight | KeyD).pressed())
	{
		return RIGHT;
	}
	else
		return NONE;
}

void gameChara::UpdateByAI()
{
	int d = rand() % 4;
	switch (d)
	{
	case direction::UP:
		moveDir = { 0, -1 };
		break;
	case direction::LEFT:
		moveDir = { -1, 0 };
		break;
	case direction::DOWN:
		moveDir = { 0, 1 };
		break;
	case direction::RIGHT:
		moveDir = { 1, 0 };
		break;
	default:
		moveDir = { 0, 0 };
		break;
	}
	pos = pos + speed * moveDir * Scene::DeltaTime();
	pos.x = Clamp(pos.x, 0.0 + CHR_SIZE, (double)(Scene::Width() - CHR_SIZE));
	pos.y = Clamp(pos.y, 0.0 + CHR_SIZE, (double)(Scene::Height() - CHR_SIZE));
}

void gameChara::UpdateByHuman()
{
	direction d = GetDirection();
	switch (d)
	{
	case direction::UP:
		moveDir = { 0, -1 };
		break;
	case direction::LEFT:
		moveDir = { -1, 0 };
		break;
	case direction::DOWN:
		moveDir = { 0, 1 };
		break;
	case direction::RIGHT:
		moveDir = { 1, 0 };
		break;
	default:
		moveDir = { 0, 0 };
		break;
	}
	pos = pos + speed * moveDir * Scene::DeltaTime();
	pos.x = Clamp(pos.x, 0.0 + CHR_SIZE, (double)(Scene::Width() - CHR_SIZE));
	pos.y = Clamp(pos.y, 0.0 + CHR_SIZE, (double)(Scene::Height() - CHR_SIZE));
}

void gameChara::Update()
{
	if (isAI)
		UpdateByAI();
	else
		UpdateByHuman();
}

void gameChara::ShowMe()
{
	std::cout << "    pos = ("
		<< pos.x << ", " << pos.y << ")" << std::endl;
	std::cout << "  speed = ("
		<< speed << ")" << std::endl;
	std::cout << "moveDir = ("
		<< moveDir.x << ", " << moveDir.y << ")" << std::endl;
}

void gameChara::Draw()
{
	tex.resized(CHR_SIZE).drawAt(pos);
}

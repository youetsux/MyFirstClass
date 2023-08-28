# include <Siv3D.hpp> // OpenSiv3D v0.6.10
#include "gameChara.h"

void Main()
{
	// 背景の色を設定する | Set the background color
	Scene::SetBackground(Palette::Mintcream);
	// 太文字のフォントを作成する | Create a bold font with MSDF method
	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };
	TextureAsset::Register(U"HERO", U"🐧"_emoji);
	TextureAsset::Register(U"ENEMY", U"👺"_emoji);

	//Console.open();

	srand((unsigned int)time(nullptr));
	gameChara hero({400,300},200, {0,-1.0},U"HERO", false);
	gameChara enemy({ 0,100 }, 250, { 1, 0 }, U"ENEMY", true);

	//hero.pos = { 10,20 };
	//hero.speed = 50;
	//hero.moveDir = { 1, 0 };
	
	

	while (System::Update())
	{

		hero.Update();
		hero.Draw();
		//hero.tex.draw(hero.pos);
		//メンバ関数
		//hero.Draw(); => これが実行されるように　hero.tex.draw(hero.pos);
		enemy.Update();
		//enemy.Draw(); => enemy.tex.draw(enemy.pos);
		enemy.Draw();
		//hero.ShowMe();
	}
}



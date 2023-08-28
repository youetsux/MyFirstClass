#pragma once

const int CHR_SIZE = 64;

enum direction
{
	UP,LEFT,DOWN,RIGHT,NONE
};

class gameChara
{
private: //データの隠蔽
	//クラス内（関数定義では使える）
	Vec2 pos;
	double speed;
	Vec2 moveDir;
	Texture tex;
    direction GetDirection();
	bool isAI;
	//画面から出ないように工夫してねー
	void UpdateByAI(); //画面内をランダムで動く
	void UpdateByHuman();//キーボード入力

public://公開メンバ
	gameChara();
	gameChara(Vec2 _pos, double _speed,
		        Vec2 _dir, String _tex, bool _isAI);
	void Update();//AIと人の入力をisAIで切り替える
	void ShowMe();
	void Draw();
};


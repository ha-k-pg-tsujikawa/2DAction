#include "Src/Engine/Engine.h"
#include "GameScene.h"
#include "Scene.h"

extern SceneKind g_CurrentSceneKind;
extern SceneStep g_CurrentSceneStep;

int alpha1 = 0;
bool IsFadeIn_g, IsFadeOut_g;

#define width 10
#define hight 8

int map[hight][width] =
{
	{15, 14, 13, 12, 11, 10,  9,  8,  7,  1},
	{11, 10,  9,  8,  7,  0,  0,  0,  0,  1},
	{ 7,  6,  5,  4,  3,  0,  0,  0,  0,  1},
	{ 3,  2,  1,  0,  1,  0,  0,  0,  0,  1},
	{ 1,  2,  3,  4,  5,  0,  0,  0,  0,  1},
	{ 1,  0,  0,  0,  0,  0,  0,  0,  0,  1},
	{ 1,  0,  0,  0,  0,  0,  0,  0,  0,  1},
	{ 1,  1,  1,  1 , 1 , 1,  1,  1,  1,  1}
};

struct Slider
{
	Vec2 Position;
	Size Size;
	float MinValue;
	float MaxValue;
	float CurrentValue;
	float TargetValue;
	float Speed;
};

Slider g_Slider =
{
	Vec2(50, 0), Size(200, 50), 0.0f, 100.0f, 0.0f, 100.0f, 0.055f
};

//void UpdateSlider();

void InitGameScene()
{
	alpha1 = 255;
	IsFadeIn_g = true;
	IsFadeOut_g = false;
	Engine::LoadTexture("Game1", "Res/IMG_0155.JPG");
	Engine::LoadTexture("Tile1", "Res/MapChip.png");
	Engine::LoadTexture("slider", "Res/Slider01.png");
	g_CurrentSceneStep = SceneStep::Run;
}

void RunGameScene()
{
	Engine::StartDrawing(0);

	//Engine::DrawTexture(-50, 30, "Game1", 255, 0, 0.3, 0.3);
	//Engine::DrawFont(260.0f, 220.0f, "ÉQÅ[ÉÄ", Large, White);

	Vec2 tex_pos;
	Vec2 pos;
	Vec2 chip_size(64, 64);

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < hight; j++)
		{
			tex_pos.X = map[j][i] % 4 * chip_size.X;
			tex_pos.Y = map[j][i] / 4 * chip_size.Y;

			pos = Vec2(i * chip_size.X, j * chip_size.X);

			Engine::DrawTextureUV(pos.X, pos.Y, "Tile1", tex_pos.X, tex_pos.Y, chip_size.X, chip_size.Y);
			if (map[j][i] == 0)continue;		
		}
	}

	float vector = g_Slider.TargetValue - g_Slider.CurrentValue;

	float sign = 1.0f;

	if (vector == 0.0f) return;

	if (vector < 0)
	{
		sign *= -1.0f;
	}

	g_Slider.CurrentValue += sign * g_Slider.Speed;

	if (g_Slider.Speed >= abs(vector))
	{
		g_Slider.CurrentValue = g_Slider.TargetValue;

		if (g_Slider.TargetValue == 0.0f)
		{
			g_Slider.TargetValue = 100.0f;
		}
		else
		{
			g_Slider.TargetValue = 0.0f;
		}
	}

	float percent = (g_Slider.CurrentValue - g_Slider.MinValue) / (g_Slider.MaxValue - g_Slider.MinValue);

	Engine::DrawTextureUV(0, 0, "slider", g_Slider.Position.X, g_Slider.Position.Y, g_Slider.Size.Width * percent, g_Slider.Size.Height);

	
	Engine::DrawRect(0, 0, 640, 480, 0x000000, alpha1);

	if (IsFadeIn_g == true) alpha1 -= 5;
	if (alpha1 <= 0) IsFadeIn_g = false;

	if (IsFadeOut_g == true && IsFadeIn_g == false) alpha1 += 5;

	if (Engine::IsKeyboardKeyPushed(DIK_RETURN))
	{
		IsFadeOut_g = true;
	}

	if (alpha1 >= 255)
	{
		g_CurrentSceneKind = SceneKind::TitleScene;
		g_CurrentSceneStep = SceneStep::Init;
	}

	Engine::FinishDrawing();
}

void FinishGameScene()
{

}

void UpdateGameScene()
{
	switch (g_CurrentSceneStep)
	{
	case SceneStep::Init:
		InitGameScene();
		break;
	case SceneStep::Run:
		RunGameScene();
		break;
	case SceneStep::Finish:
		FinishGameScene();
		break;
	}

	//DrawGameScene();
}

//void UpdateSlider()
//{
//	Engine::Update();
//
//	float vector = g_Slider.TargetValue - g_Slider.CurrentValue;
//
//	float sign = 1.0f;
//
//	if (vector == 0.0f) return;
//
//	if (vector < 0)
//	{
//		sign *= -1.0f;
//	}
//
//	g_Slider.CurrentValue += sign * g_Slider.Speed;
//
//	if (g_Slider.Speed >= abs(vector))
//	{
//		g_Slider.CurrentValue = g_Slider.TargetValue;
//
//		if (g_Slider.TargetValue == 0.0f)
//		{
//			g_Slider.TargetValue = 100.0f;
//		}
//		else
//		{
//			g_Slider.TargetValue = 0.0f;
//		}
//	}
//}

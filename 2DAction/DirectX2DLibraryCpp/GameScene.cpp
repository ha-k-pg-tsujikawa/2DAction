#include "Src/Engine/Engine.h"
#include "GameScene.h"
#include "Scene.h"

extern SceneKind g_CurrentSceneKind;
extern SceneStep g_CurrentSceneStep;

int alpha1 = 0;
bool IsFadeIn_g, IsFadeOut_g;

void InitGameScene()
{
	alpha1 = 0;
	IsFadeIn_g = true;
	IsFadeOut_g = false;
	Engine::LoadTexture("Game1", "Res/IMG_0155.JPG");
	g_CurrentSceneStep = SceneStep::Run;
}

void RunGameScene()
{
	Engine::StartDrawing(0);

	Engine::DrawTexture(-50, 30, "Game1", alpha1, 0, 0.3, 0.3);
	//Engine::DrawFont(260.0f, 220.0f, "ƒQ[ƒ€", Large, White);

	if (IsFadeIn_g == true) alpha1 += 5;
	if (alpha1 >= 255) IsFadeIn_g = false;

	if (IsFadeOut_g == true && IsFadeIn_g == false) alpha1 -= 5;

	if (Engine::IsKeyboardKeyPushed(DIK_RETURN))
	{
		IsFadeOut_g = true;
	}

	if (alpha1 <= 0)
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
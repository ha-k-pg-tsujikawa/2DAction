#include "Src/Engine/Engine.h"
#include "TitleScene.h"
#include "Scene.h"

extern SceneKind g_CurrentSceneKind;
extern SceneStep g_CurrentSceneStep;

int alpha = 255;
bool IsFadeIn_t, IsFadeOut_t;

void InitTitleScene()
{
	alpha = 0;
	IsFadeIn_t = true;
	IsFadeOut_t = false;
	g_CurrentSceneStep = SceneStep::Run;
}

void RunTitleScene()
{
	Engine::StartDrawing(0);

	Engine::DrawRect(0, 0, 640, 480, 0xffffff, alpha);
	Engine::DrawFont(260.0f, 220.0f, "ƒ^ƒCƒgƒ‹", Large, Black);

	Engine::FinishDrawing();

	if (IsFadeIn_t == true) alpha += 5;
	if (alpha >= 255) IsFadeIn_t = false;

	if (IsFadeOut_t == true && IsFadeIn_t == false) alpha -= 5;

	if (Engine::IsKeyboardKeyPushed(DIK_RETURN))
	{
		IsFadeOut_t = true;
	}

	if (alpha <= 0)
	{
		g_CurrentSceneKind = SceneKind::GameScene;
		g_CurrentSceneStep = SceneStep::Init;
	}
}

void FinishTitleScene()
{

}


void UpdateTitleScene()
{
	switch (g_CurrentSceneStep)
	{
	case SceneStep::Init:
		InitTitleScene();
		break;
	case SceneStep::Run:
		RunTitleScene();
		break;
	case SceneStep::Finish:
		FinishTitleScene();
		break;
	}
}

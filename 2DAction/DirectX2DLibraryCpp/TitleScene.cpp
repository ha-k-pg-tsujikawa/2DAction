#include "Src/Engine/Engine.h"
#include "TitleScene.h"
#include "Scene.h"
#include "Button.h"

extern SceneKind g_CurrentSceneKind;
extern SceneStep g_CurrentSceneStep;
ButtonStatus g_Mousestep;

int alpha = 255;
int count = 0;
float RightUp = 0.0f;
float LeftUp = 0.0f;
bool IsFadeIn_t, IsFadeOut_t;

void InitTitleScene()
{
	alpha = 255;
	IsFadeIn_t = true;
	IsFadeOut_t = false;
	RightUp = 0.0f;
	LeftUp = 0.0f;
	Engine::LoadTexture("Button01", "Res/SampleButton.png");
	g_CurrentSceneStep = SceneStep::Run;
}

void RunTitleScene()
{
	Engine::StartDrawing(0);

	Engine::DrawRect(0, 0, 640, 480, 0xffffff);
	Engine::DrawTextureUV(200.0f, 160.0f, "Button01", RightUp, LeftUp, 256.0f, 128.0f);
	Engine::DrawRect(0, 0, 640, 480, 0x000000, alpha);
	//Engine::DrawFont(260.0f, 220.0f, "ƒ^ƒCƒgƒ‹", Large, Black);
	
	Engine::FinishDrawing();

	if (IsFadeIn_t == true) alpha -= 5;

	if (alpha <= 0)
	{
		IsFadeIn_t = false;
		g_Mousestep = ButtonStatus::Active;
	}

	if (IsFadeOut_t == true && IsFadeIn_t == false)
	{
		alpha += 5;
		g_Mousestep = ButtonStatus::NotActive;
	}

	if (g_Mousestep == ButtonStatus::Active)
	{
		count++;
		if (OnCursor() == true)
		{
			RightUp = 256.0f;
			LeftUp = 0.0f;
		}
		else
		{
			RightUp = 0.0f;
			LeftUp = 0.0f;
		}

		if (Engine::IsMouseButtonPushed(MouseButton::Left))
		{
			RightUp = 256.0f;
			LeftUp = 128.0f;
			count = 0;
			IsFadeOut_t = true;
		}
	}
	else
	{
		RightUp = 0.0f;
		LeftUp = 128.0f;
	}

	if (Engine::IsKeyboardKeyPushed(DIK_RETURN))
	{
		IsFadeOut_t = true;
	}

	if (alpha >= 255)
	{
		g_CurrentSceneStep = SceneStep::Finish;
	}
}

void FinishTitleScene()
{
	g_CurrentSceneKind = SceneKind::GameScene;
	g_CurrentSceneStep = SceneStep::Init;
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

	switch (g_Mousestep)
	{
	case ButtonStatus::NotActive:
		break;
	case ButtonStatus::Active:
		break;
	}
}

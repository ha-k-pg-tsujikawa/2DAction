#include "Src/Engine/Engine.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "Scene.h"

SceneKind g_CurrentSceneKind = SceneKind::TitleScene;
SceneStep g_CurrentSceneStep = SceneStep::Init;

void UpdateScene()
{
	Engine::Update();

	switch (g_CurrentSceneKind)
	{
	case SceneKind::TitleScene:
		UpdateTitleScene();
		break;
	case SceneKind::GameScene:
		UpdateGameScene();
		break;
	}
}

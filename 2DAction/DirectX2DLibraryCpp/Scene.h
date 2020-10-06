#ifndef SCENE_H_
#define SCENE_H_

enum SceneKind
{
	TitleScene,
	GameScene,
};

enum SceneStep
{
	Init,
	Run,
	Finish
};

void UpdateScene();

#endif // !SCENE_H_

#include "Button.h"
#include "Src/Engine/Engine.h"

struct Button
{
	ButtonStatus CurrentStatus;	// ���
	Vec2 Position;				// ���W
	int PushedInterval;			// �����Ԃ̃C���^�[�o��
};

static Button g_Button;

bool OnCursor()
{
	Vec2 Mouse_Pos(Engine::GetMousePos());

	Size Button_size = Size(256.0f, 128.0f);

	if (200 < Mouse_Pos.X && 160 < Mouse_Pos.Y && 200 + Button_size.Width > Mouse_Pos.X && 160 + Button_size.Height > Mouse_Pos.Y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
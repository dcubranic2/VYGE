#include "TestState.h"

TestState::TestState(unsigned long id):State(id)
{
	
}

void TestState::Load()
{
	m_font = new Font("Arial", 10, FW_BOLD);
}

void TestState::Close()
{
	SAFE_DELETE(m_font);
}

void TestState::RequestViewer(ViewerSetup* viewer)
{
}

void TestState::Update(float elapsed)
{
	
}

void TestState::Render()
{
	g_engine->GetDevice()->Clear( 0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0, 1.0f, 0 );
	sprintf(m_message, "");
	sprintf(str_temp, "Joystick 1 pos X: %d\n", g_engine->GetInput()->GetGamePadJoy1PosX());
	strcat(m_message, str_temp);
	sprintf(str_temp, "Joystick 1 pos Y: %d\n", g_engine->GetInput()->GetGamePadJoy1PosY());
	strcat(m_message, str_temp);
	sprintf(str_temp, "Joystick 2 pos X: %d\n", g_engine->GetInput()->GetGamePadJoy2PosX());
	strcat(m_message, str_temp);
	sprintf(str_temp, "Joystick 2 pos Y: %d\n", g_engine->GetInput()->GetGamePadJoy2PosY());
	strcat(m_message, str_temp);
	sprintf(str_temp, "D pad Left: %d\n", g_engine->GetInput()->GetGamePadDPadPosLeft());
	strcat(m_message, str_temp);
	sprintf(str_temp, "D pad Right: %d\n", g_engine->GetInput()->GetGamePadDPadPosRight());
	strcat(m_message, str_temp);
	sprintf(str_temp, "D pad Up: %d\n", g_engine->GetInput()->GetGamePadDPadPosUp());
	strcat(m_message, str_temp);
	sprintf(str_temp, "D pad Down: %d\n", g_engine->GetInput()->GetGamePadDPadPosDown());
	strcat(m_message, str_temp);
	sprintf(str_temp, "D pad Up Left: %d\n", g_engine->GetInput()->GetGamePadDPadPosUpLeft());
	strcat(m_message, str_temp);
	sprintf(str_temp, "D pad Up Right: %d\n", g_engine->GetInput()->GetGamePadDPadPosUpRight());
	strcat(m_message, str_temp);
	sprintf(str_temp, "D pad Down Left: %d\n", g_engine->GetInput()->GetGamePadDPadPosDownLeft());
	strcat(m_message, str_temp);
	sprintf(str_temp, "D pad Down Right: %d\n", g_engine->GetInput()->GetGamePadDPadPosDownRight());
	strcat(m_message, str_temp);
	sprintf(str_temp, "Left Slider: %d\n", g_engine->GetInput()->GetGamePadSliderLeft());
	strcat(m_message, str_temp);
	sprintf(str_temp, "Right Slider: %d\n", g_engine->GetInput()->GetGamePadSliderRight());
	strcat(m_message, str_temp);
	for (int i = 0; i < 16; i++) {
		sprintf(str_temp, "Button %d %d\n", i, g_engine->GetInput()->GetGamePadButtonPress(i, true));
		strcat(m_message, str_temp);
	}
	m_font->Render(m_message, 100, 50, 0x00ff0000L );
	sprintf(m_message, "");
	for (int i = 16; i < 32; i++) {
		sprintf(str_temp, "Button %d %d\n", i, g_engine->GetInput()->GetGamePadButtonPress(i, true));
		strcat(m_message, str_temp);
	}
	m_font->Render(m_message, 300, 50, 0x00ff0000L);
}

//-----------------------------------------------------------------------------
// A wrapper class for handling input via DirectInput. Both the keyboard and
// mouse devices are supported through this class.
//
// Programming a Multiplayer First Person Shooter in DirectX
// Copyright (c) 2004 Vaughan Young
//-----------------------------------------------------------------------------
#ifndef INPUT_H
#define INPUT_H

//-----------------------------------------------------------------------------
// Input Class
//-----------------------------------------------------------------------------
class Input
{
public:
	Input( HWND window );
	virtual ~Input();

	void Update();

	bool GetKeyPress( char key, bool ignorePressStamp = false );

	bool GetButtonPress( char button, bool ignorePressStamp = false );
	long GetPosX();
	long GetPosY();
	long GetDeltaX();
	long GetDeltaY();
	long GetDeltaWheel();

	long GetGamePadJoy1PosX();
	long GetGamePadJoy1PosY();
	long GetGamePadJoy2PosX();
	long GetGamePadJoy2PosY();
	long GetGamePadSliderLeft();
	long GetGamePadSliderRight();
	bool GetGamePadDPadPosUp();
	bool GetGamePadDPadPosDown();
	bool GetGamePadDPadPosLeft();
	bool GetGamePadDPadPosRight();
	bool GetGamePadDPadPosUpRight();
	bool GetGamePadDPadPosUpLeft();
	bool GetGamePadDPadPosDownRight();
	bool GetGamePadDPadPosDownLeft();
	bool GetGamePadButtonPress( char button, bool ignorePressStamp = false );


private:
	HWND m_window; // Handle of the parent window.
	IDirectInput8 *m_di; // DirectInput object.
	unsigned long m_pressStamp; // Current press stamp (incremented every frame).

	IDirectInputDevice8 *m_keyboard; // DirectInput keyboard device.
	char m_keyState[256]; // Stores the state of the keyboard keys.
	unsigned long m_keyPressStamp[256]; // Stamps the last frame each key was preseed.

	IDirectInputDevice8 *m_mouse; // DirectInput mouse device.
	DIMOUSESTATE m_mouseState; // Stores the state of the mouse buttons.
	unsigned long m_buttonPressStamp[3]; // Stamps the last frame each button was preseed.
	POINT m_position; // Stores the position of the mouse cursor on the screen.

	//XBOX 360 compatibile device - 2 analog sticks, 1 dpad, 10 buttons, 2 range sliders
	GUID m_gamepadGUID;
	IDirectInputDevice8 *m_gamepad = NULL;
	DIJOYSTATE m_gamepadState;
	unsigned long m_gamepadButtonPressStamp[32];
	static BOOL CALLBACK EnumGamepads( LPCDIDEVICEINSTANCE lpDIDE, LPVOID self );
	static BOOL CALLBACK EnumGamepadObjects( LPCDIDEVICEOBJECTINSTANCE lpddoi, LPVOID self );
 
};

#endif
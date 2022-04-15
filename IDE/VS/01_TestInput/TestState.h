#pragma once
#include<Main.h>

#define TEST_STATE 1

class TestState : public State
{
public:
	TestState(unsigned long id);
	virtual void Load();
	virtual void Close();

	virtual void RequestViewer(ViewerSetup* viewer);
	virtual void Update(float elapsed);

	virtual void Render();
private:
	char m_message[512];
	char str_temp[512];
	Font *m_font;
};


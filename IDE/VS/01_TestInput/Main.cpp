#include<Main.h>

void StateSetup()
{
	g_engine->AddState(new TestState(TEST_STATE), true);
}

//-----------------------------------------------------------------------------
// Entry point for the application.
//-----------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE instance, HINSTANCE prev, LPSTR cmdLine, int cmdShow)
{
	EngineSetup setup;
	setup.instance = instance;
	setup.name = "Test Input";
	setup.StateSetup = StateSetup;

	// Create the engine (using the setup structure), then run it.
	new Engine(&setup);
	g_engine->Run();

	return true;
}
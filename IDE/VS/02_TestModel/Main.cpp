//-----------------------------------------------------------------------------
// System Includes
//-----------------------------------------------------------------------------
#include <windows.h>

//-----------------------------------------------------------------------------
// Engine Includes
//-----------------------------------------------------------------------------
#include "..\..\..\Code\Engine\Engine.h"

//-----------------------------------------------------------------------------
// Test State Class
//-----------------------------------------------------------------------------
class TestState : public State
{
public:
	//-------------------------------------------------------------------------
	// Allows the test state to preform any pre-processing construction.
	//-------------------------------------------------------------------------
	virtual void Load()
	{
		m_mesh = new Mesh( "vrc.x", "./Assets/" );

		cameraScript = new Script("Camera.txt", "./Assets/");
		pos = D3DXVECTOR3() = *cameraScript->GetVectorData("pos");
		at  = D3DXVECTOR3() = *cameraScript->GetVectorData("at");
		up  = D3DXVECTOR3() = *cameraScript->GetVectorData("up");

		// Set a suitable view matrix for viewing the test mesh.
		D3DXMatrixLookAtLH( &view, &pos, &at, &up );
		g_engine->GetDevice()->SetTransform( D3DTS_VIEW, &view );	
	};

	//-------------------------------------------------------------------------
	// Allows the test state to preform any post-processing destruction.
	//-------------------------------------------------------------------------
	virtual void Close()
	{
		SAFE_DELETE( m_mesh );
		SAFE_DELETE(cameraScript);
	};

	//-------------------------------------------------------------------------
	// Returns the view setup details for the given frame.
	//-------------------------------------------------------------------------
	virtual void RequestViewer( ViewerSetup *viewer )
	{
		viewer->viewClearFlags = D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER;
	}

	//-------------------------------------------------------------------------
	// Renders the test state.
	//-------------------------------------------------------------------------
	virtual void Render()
	{
		m_mesh->Render();
	};

	//-------------------------------------------------------------------------
	// Update the render state
	//-------------------------------------------------------------------------
	virtual void Update(float pelapsed)
	{
		m_mesh->Update(); // calculate mesh transformations before rendering
		bool xchanged = false;
		if (g_engine->GetInput()->GetKeyPress(DIK_A,true) == true)
		{
			pos.x += -1;
			xchanged = true;
		}
		if (g_engine->GetInput()->GetKeyPress(DIK_D,true) == true)
		{
			pos.x += +1;
			xchanged = true;
		}
		if (g_engine->GetInput()->GetKeyPress(DIK_W,true) == true)
		{
			pos.y += +1;
			xchanged = true;
		}
		if (g_engine->GetInput()->GetKeyPress(DIK_S,true) == true)
		{
			pos.y += -1;
			xchanged = true;
		}
		if (g_engine->GetInput()->GetKeyPress(DIK_R, true) == true)
		{
			pos.z += +1;
			xchanged = true;
		}
		if (g_engine->GetInput()->GetKeyPress(DIK_F, true) == true)
		{
			pos.z += -1;
			xchanged = true;
		}
		if (xchanged == true) {
			D3DXMatrixLookAtLH(&view, &pos, &at, &up);
			//D3DXMatrixLookAtLH(&view, &pos, &D3DXVECTOR3(pos.x-at.x,pos.y-at.y,pos.z-at.z), &up);
			g_engine->GetDevice()->SetTransform(D3DTS_VIEW, &view);
		}
	};

private:
	Mesh *m_mesh; // The test mesh.
	Script* cameraScript; // Camera Script
	D3DXVECTOR3 pos; // Position
	D3DXVECTOR3 at; // Look At
	D3DXVECTOR3 up; // Look Up
	D3DXMATRIX view; // View

};

//-----------------------------------------------------------------------------
// Application specific state setup.
//-----------------------------------------------------------------------------
void StateSetup()
{
	g_engine->AddState( new TestState, true );
}

//-----------------------------------------------------------------------------
// Entry point for the application.
//-----------------------------------------------------------------------------
int WINAPI WinMain( HINSTANCE instance, HINSTANCE prev, LPSTR cmdLine, int cmdShow )
{
	// Create the engine setup structure.
	EngineSetup setup;
	setup.instance = instance;
	setup.name = "Mesh/Material Test";
	setup.scale = 0.01f;
	setup.StateSetup = StateSetup;

	// Create the engine (using the setup structure), then run it.
	new Engine( &setup );
	g_engine->Run();

	return true;
}
/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#include "Genesis.h"
#include "GenLogger.h"

Genesis::Genesis(GenWindow* window)
{
	_window = window;
	currentLevel = new GenLevel(&_window->Gfx());
	DeltaTime = new GenTimer();
}

void Genesis::Start()
{
	ClearGfx();
	SetDefaultShaders();
	GenLogger::Info("Genesis starting");
	currentLevel->LoadLevel("Test");	
}

void Genesis::Update()
{
	float dt = DeltaTime->Mark() * 1000;
	ClearGfx();	
	SetDefaultShaders();
	InputHandler(dt);		

	// DrawWorld
	SetDefaultShaders();
	currentLevel->GetWorld()->DrawWorld(_window, currentLevel);
}

void Genesis::SetDefaultShaders()
{
	_window->Gfx().deviceContext->VSSetShader(currentLevel->assetMng->vertexShaders["vs_default"]->GetShader(), NULL, 0);
	_window->Gfx().deviceContext->PSSetShader(currentLevel->assetMng->pixelShaders["ps_default"]->GetShader(), NULL, 0);
	_window->Gfx().deviceContext->IASetInputLayout(currentLevel->assetMng->vertexShaders["vs_default"]->GetInputLayout());
	//_window->Gfx().deviceContext->OMSetDepthStencilState(_window->Gfx().depthStencilState.Get(), 0); // depthStencilState_applyMask.Get()
}

void Genesis::ClearGfx()
{
	float bgcolor[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	_window->Gfx().deviceContext->ClearRenderTargetView(_window->Gfx().renderTargetView.Get(), bgcolor);
	_window->Gfx().deviceContext->ClearDepthStencilView(_window->Gfx().depthStencilView.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

	_window->Gfx().deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	_window->Gfx().deviceContext->RSSetState(_window->Gfx().rasterizerState.Get());
	_window->Gfx().deviceContext->OMSetBlendState(NULL, NULL, 0xFFFFFFFF);
	_window->Gfx().deviceContext->PSSetSamplers(0, 1, _window->Gfx().samplerState.GetAddressOf());
}

void Genesis::ImGuiHandler()
{
	// FPS
	static int fpsCounter = 0;
	static std::string fpsString = "FPS: 0";
	fpsCounter += 1;
	if (_window->Gfx().fpsTimer.Peek() * 1000 > 1000.0)
	{
		fpsString = "FPS: " + std::to_string(fpsCounter) + "\n";
		fpsCounter = 0;
		_window->Gfx().fpsTimer.Mark();
	}
	
	// Start the Dear ImGui frame
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	//Create ImGui Test Window
	ImGui::Begin("App info");
	//GenTile* tile = currentLevel->GetWorld()->chunk->   //GetTile("Cube_50");
	//ImGui::Text(tile->test.c_str());
	ImGui::Text(fpsString.c_str());
	ImGui::DragFloat3("Ambient Light Color", &currentLevel->assetMng->GetAmbientLight("al1")->ambientLightColor.x, 0.01f, 0.0f, 1.0f);
	ImGui::DragFloat("Ambient Light Strength", &currentLevel->assetMng->GetAmbientLight("al1")->ambientLightStrength, 0.01f, 0.0f, 1.0f);
	//ImGui::DragFloat("Alpha", &alpha, 0.1f, 0.0f, 1.0f);
	ImGui::NewLine();
	ImGui::DragFloat3("Dynamic Light Color", &currentLevel->assetMng->GetPointLight("pl1")->lightColor.x, 0.01f, 0.0f, 10.0f);
	ImGui::DragFloat("Dynamic Light Strength", &currentLevel->assetMng->GetPointLight("pl1")->lightStrength, 0.01f, 0.0f, 10.0f);
	ImGui::DragFloat("Dynamic Light Attenuation A", &currentLevel->assetMng->GetPointLight("pl1")->attenuation_a, 0.01f, 0.1f, 10.0f);
	ImGui::DragFloat("Dynamic Light Attenuation B", &currentLevel->assetMng->GetPointLight("pl1")->attenuation_b, 0.01f, 0.0f, 10.0f);
	ImGui::DragFloat("Dynamic Light Attenuation C", &currentLevel->assetMng->GetPointLight("pl1")->attenuation_c, 0.01f, 0.0f, 10.0f);
	ImGui::End();
	//Assemble Together Draw Data
	ImGui::Render();
	//Render Draw Data
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}

void Genesis::Render()
{
	ImGuiHandler();
	_window->Gfx().RenderFrame();
}

void Genesis::UpdateSound()
{

}

void Genesis::InputHandler(float dt)
{
	bool upDown = false;
	bool downDown = false;
	bool leftDown = false;
	bool rightDown = false;
	if (_window->kbd.KeyIsPressed('W'))
	{
		upDown = true;
	}
	else
	{
		upDown = false;
	}
	if (_window->kbd.KeyIsPressed('A'))
	{
		leftDown = true;
	}
	else
	{
		leftDown = false;
	}
	if (_window->kbd.KeyIsPressed('S'))
	{
		downDown = true;
	}
	else
	{
		downDown = false;
	}
	if (_window->kbd.KeyIsPressed('D'))
	{
		rightDown = true;
	}
	else
	{
		rightDown = false;
	}

	const float cameraSpeed = 0.006f;
	_window->mouse.EnableRaw();
	if (_window->mouse.RightIsPressed())
	{
		auto raw = _window->mouse.ReadRawDelta();
		if (_window->mouse.RawEnabled() && raw)
		{
			currentLevel->assetMng->camera.AdjustRotation((float)raw->y * 0.01f, (float)raw->x * 0.01f, 0);
		}
		else
		{
			float mposX = (float)_window->mouse.GetPosX() - 400.0f;
			float mposY = (float)_window->mouse.GetPosY() - 300.0f;
			float x = 0.0f;
			float y = 0.0f;
			x = -(float)(mposX * cameraSpeed * dt) / 8.0f;
			y = -(float)(mposY * cameraSpeed * dt) / 8.0f;
			currentLevel->assetMng->camera.AdjustRotation(y * 0.01f, x * 0.01f, 0); // #TODO: Mouse is all over the place	
		}
	}

	if (upDown)
	{
		currentLevel->assetMng->camera.AdjustPosition(currentLevel->assetMng->camera.GetForwardVector() * cameraSpeed * dt);
	}
	if (_window->kbd.KeyIsPressed('C'))
	{
		XMVECTOR lightPosition = currentLevel->assetMng->camera.GetPositionVector();
		lightPosition += currentLevel->assetMng->camera.GetForwardVector();
		currentLevel->assetMng->GetPointLight("pl1")->SetPosition(lightPosition);
		currentLevel->assetMng->GetPointLight("pl1")->SetRotation(currentLevel->assetMng->camera.GetRotationFloat3());
	}
}

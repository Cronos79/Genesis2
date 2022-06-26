#include "GenWorld.h"
#include "GenLevel.h"
#include "GenWindow.h"

GenWorld::GenWorld(class GenLevel* currentLevel)
{
	InitChunks(currentLevel);
}

void GenWorld::InitChunks(GenLevel* currentLevel)
{
	chunk = new GenChunk();
	chunk->InitChunk(currentLevel);
}

GenChunk* GenWorld::GetChunk(int x, int y)
{
	return chunk;
}

void GenWorld::DrawWorld(GenWindow * wnd, GenLevel* currentLevel)
{
	// PointLight
	{
		currentLevel->assetMng->GetPointLight("pl1")->SetConstantBuffers(&wnd->Gfx());
		currentLevel->assetMng->GetPointLight("pl1")->SetPosition(500.0f, 350.0f, 500.0f);
		currentLevel->assetMng->GetPointLight("pl1")->Draw(currentLevel->assetMng->camera.GetViewMatrix() * currentLevel->assetMng->camera.GetProjectionMatrix());
	}
	// Ambient light
	{
		currentLevel->assetMng->GetAmbientLight("al1")->SetConstantBuffers(&wnd->Gfx());
		currentLevel->assetMng->GetAmbientLight("al1")->Draw(currentLevel->assetMng->camera.GetViewMatrix() * currentLevel->assetMng->camera.GetProjectionMatrix());
	}
	GetChunk(0, 0)->DrawChunk();
}

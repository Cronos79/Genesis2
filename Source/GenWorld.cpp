#include "GenWorld.h"
#include "GenLevel.h"
#include "GenWindow.h"

GenWorld::GenWorld(class GenLevel* currentLevel)
{
	InitChunks(currentLevel);
}

void GenWorld::InitChunks(GenLevel* currentLevel)
{
	int count = 0;
	for (int y = 0; y <= 2; y++)
	{
		for (int x = 0; x <= 2; x++)
		{
			chunks.push_back(new GenChunk());
			chunks[count]->InitChunk(currentLevel);
			chunks[count]->SetPosition(x * (float)chunks[count]->GetChunkWidth(), 0.0f, y * (float)chunks[count]->GetChunkWidth());
			count++;
		}
	}
}

GenChunk* GenWorld::GetChunk(int x, int y)
{
	return chunks[0]; // #TODO: Fix me
}

void GenWorld::DrawWorld(GenWindow * wnd, GenLevel* currentLevel)
{
	// PointLight
	{
		currentLevel->assetMng->GetPointLight("pl1")->SetConstantBuffers(&wnd->Gfx());
		currentLevel->assetMng->GetPointLight("pl1")->SetPosition(100.0f, 350.0f, 100.0f);
		currentLevel->assetMng->GetPointLight("pl1")->Draw(currentLevel->assetMng->camera.GetViewMatrix() * currentLevel->assetMng->camera.GetProjectionMatrix());
	}
	// PointLight
	/*{
		currentLevel->assetMng->GetPointLight("pl2")->SetConstantBuffers(&wnd->Gfx());
		currentLevel->assetMng->GetPointLight("pl2")->SetPosition(1600.0f, 350.0f, 1600.0f);
		currentLevel->assetMng->GetPointLight("pl2")->Draw(currentLevel->assetMng->camera.GetViewMatrix() * currentLevel->assetMng->camera.GetProjectionMatrix());
	}*/
	// Ambient light
	{
		currentLevel->assetMng->GetAmbientLight("al1")->SetConstantBuffers(&wnd->Gfx());
		currentLevel->assetMng->GetAmbientLight("al1")->Draw(currentLevel->assetMng->camera.GetViewMatrix() * currentLevel->assetMng->camera.GetProjectionMatrix());
	}
	int x = 0;
	for (auto c : chunks)
	{
		chunks[x++]->DrawChunk(); // #TODO: Draw correct chunks
	}
}

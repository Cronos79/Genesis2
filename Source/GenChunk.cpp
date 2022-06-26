#include "GenChunk.h"

void GenChunk::InitChunk(GenLevel* currentLevel)
{
	this->currentLevel = currentLevel;
	std::string name = "Cube_";
	if (currentLevel->assetMng->assetsLoaded)
	{
		int counter = 0;
		for (int y = 0; y <= 15; y++)
		{
			for (int x = 0; x <= 15; x++)
			{
				std::string name1 = name + std::to_string(counter++);
				GenTile* object = currentLevel->assetMng->GetTile(name1);				
				object->SetPosition(100.0f * x, 0.0f, 100.0f * y);
				tiles.push_back(object);
			}
		}
	}
}

void GenChunk::AddTile(GenTile* tile)
{
	tiles.push_back(tile);
}

void GenChunk::DrawChunk()
{
	for (auto t : tiles)
	{
		DrawTile(t);
	}
}

void GenChunk::DrawTile(GenTile* tile)
{
	if (currentLevel->assetMng->assetsLoaded)
	{
		tile->Draw(currentLevel->assetMng->camera.GetViewMatrix() * currentLevel->assetMng->camera.GetProjectionMatrix());
	}
}

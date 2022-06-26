#include "GenChunk.h"
#include "GenLevel.h"

void GenChunk::InitChunk(GenLevel* currentLevel)
{
	this->currentLevel = currentLevel;
	std::string name = "Cube_";
	if (currentLevel->assetMng->assetsLoaded)
	{
		int counter = 0;
		for (int y = 0; y <= chunkSize - 1; y++)
		{
			for (int x = 0; x <= chunkSize - 1; x++)
			{
				std::string name1 = name + std::to_string(counter++);
				GenTile* tile = currentLevel->assetMng->GetTile(name1);	
				tile->x = x;
				tile->y = y;
				tile->SetPosition(tile->GetSize() * x, 0.0f, tile->GetSize() * y);
				AddTile(tile);
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
		t->SetPosition(GetPositionFloat3().x + t->GetSize() * t->x, 0.0f, t->GetSize() * t->y);
		DrawTile(t);
	}
}

int32_t GenChunk::GetChunkWidth()
{
	return chunkSize * GenTile::GetSize();
}

int32_t GenChunk::GetChunkHeight()
{
	return chunkSize * GenTile::GetSize();
}

void GenChunk::DrawTile(GenTile* tile)
{
	if (currentLevel->assetMng->assetsLoaded)
	{
		tile->Draw(currentLevel->assetMng->camera.GetViewMatrix() * currentLevel->assetMng->camera.GetProjectionMatrix());
	}
}

void GenChunk::UpdateMatrix()
{
	this->worldMatrix = XMMatrixRotationRollPitchYaw(this->rot.x, this->rot.y, this->rot.z) * XMMatrixTranslation(this->pos.x, this->pos.y, this->pos.z);
	this->UpdateDirectionVectors();
}

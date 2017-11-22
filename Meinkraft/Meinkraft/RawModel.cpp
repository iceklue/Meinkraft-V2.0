#include "stdafx.h"
#include "RawModel.h"

RawModel::RawModel(int vaoID, int vertexCount)
{
	this->vaoID = vaoID;
	this->vertexCount = vertexCount;
}

int RawModel::GetVaoID() const
{
	return vaoID;
}

int RawModel::GetVertexCount() const
{
	return vertexCount;
}

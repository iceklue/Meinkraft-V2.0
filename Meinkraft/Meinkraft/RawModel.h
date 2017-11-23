#pragma once
class RawModel
{
public:
public:
	RawModel(int vaoID, int vertexCount);

	int GetVaoID() const;
	int GetVertexCount() const;
private:
	int vaoID;
	int vertexCount;

};


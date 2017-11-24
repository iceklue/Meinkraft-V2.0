#pragma once

#include "RawModel.h"
#include "ModelLoader.h"
using namespace Loader;
class PrimitiveShapes
{
public:
	static RawModel Triangle(ModelLoader& loader);;

	static RawModel Triangle(ModelLoader& loader, int w, int h);;

	static RawModel Rect(ModelLoader& loader);

	static RawModel Rect(ModelLoader& loader, int w, int h);;

private:
	static std::vector<float> verticesTriangle;
	static std::vector<int> indicesTriangle;
	static std::vector<float> colorTriangle;
	static std::vector<float> verticesRect;
	static std::vector<int> indicesRect;
	static std::vector<float> colorRect;

};

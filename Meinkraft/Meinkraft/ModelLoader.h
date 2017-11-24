#pragma once
#include "RawModel.h"
#include <GL/glew.h>

namespace Loader
{
	class ModelLoader
	{
	public:
		~ModelLoader();
		RawModel LoadToVAO(std::vector<float> positions, std::vector<int> indices, std::vector<float> colours);

	private:
		int CreateVAO();
		void UnbindVAO();
		void StoreDatainAttributeArray(int AttribIndex, std::vector<float> data);

		void BindIndicesBuffer(std::vector<int> indices);

		void Cleanup();
		std::vector<GLuint> vaos;
		std::vector<GLuint> vbos;

	};
}


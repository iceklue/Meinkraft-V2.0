#include "stdafx.h"
#include "MSG.h"


MSG::MSG(MSGType _type, void* _data)
{
	type = _type;
	data = _data;
}


MSG::~MSG()
{
	switch (type)
	{
		case MSG_NULL:
			break;
		case MSG_BOOL_PTR:
			delete reinterpret_cast<bool*>(data);
			break;
		case MSG_DOUBLE_PTR:
			delete reinterpret_cast<double*>(data);
			break;
		case MSG_FLOAT_PTR:
			delete reinterpret_cast<float*>(data);
			break;
		case MSG_INT_PTR:
			delete reinterpret_cast<int*>(data);
			break;
		case MSG_CHAR_PTR:
			delete reinterpret_cast<char*>(data);
			break;
		default:
			break;

	}
}

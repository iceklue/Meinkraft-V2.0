#pragma once
enum MSGType
{
	MSG_NULL,
	MSG_UPDATE,
	MSG_LATEUPDATE,
	MSG_START,
	MSG_QUIT,
	MSG_RENDER,
	MSG_RESIZE,
	MSG_BOOL_PTR,
	MSG_INT_PTR,
	MSG_DOUBLE_PTR,
	MSG_FLOAT_PTR,
	MSG_CHAR_PTR
};

class MSG
{
public:
	MSGType type = MSG_NULL;
	void* data = nullptr;
	MSG(MSGType _type, void* _data = nullptr);
	~MSG();
};


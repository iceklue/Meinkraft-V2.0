#pragma once
#include "stdafx.h"
#include <list>
namespace ListHelper
{
	template <typename T>
	T GetElementAtIndex(std::list<T>& _list, int _index)
	{
		std::list<T>::iterator it = _list.begin();
		for (auto i = 0; i < _index; i++) {
			++it;
		}
		return *it;
	}

	template <typename T>
	bool Contains(std::list<T>& _list, T _check)
	{
		return std::find(_list.begin(), _list.end(), _check) != _list.end();
	}
}


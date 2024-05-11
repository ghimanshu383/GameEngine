#pragma once

#include "Core.h"

namespace hazel {
	class Object : public std::enable_shared_from_this<Object> {
	public:
		weak<Object> getWeakRef()  { return weak_from_this(); };
	};
}
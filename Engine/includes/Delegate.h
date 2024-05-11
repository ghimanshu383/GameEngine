#pragma once
#include <functional>
#include "Core.h"
#include "Object.h"

namespace hazel {
	template<typename... Args>
	class Delegate {
	private:
		List<std::function<bool(Args...)>> functionList;
	public:

		template<typename T>
		void RegisterFunction(weak<Object> t, void(T::*callback)(Args...)) {
			std::function<bool(Args...)> delFunction = [t, callback](Args... args) ->bool {
				if (!t.expired()) {
					(static_cast<T*>(t.lock().get())->*callback)(args...);
					return true;
				}
				else {
					return false;
				}
				};
			functionList.push_back(delFunction);
		}

		void BroadCast(Args... args) {
			List<std::function<bool(Args...)>>::iterator iter = functionList.begin();
			while (iter != functionList.end()) {
				if ((*iter)(args...)) {
					iter++;
				}
				else {
					iter = functionList.erase(iter);
				}
			}
		}
	};
}
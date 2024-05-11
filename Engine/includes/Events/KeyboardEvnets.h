#pragma once

namespace hazel {
	class KeyboardEvents {
	public:
		template<typename T, typename... Args>
		void handleKeyEvent(T* t,  bool* keys, int key, void(T::*callback)(Args...), Args... args) {
			if (keys[key]) {
				(t->*callback)(args...);
			}
		}
	};
}
#pragma once

#include <Windows.h>

namespace engine {
	namespace utility {

		class Timer {

			LARGE_INTEGER start;
			float frequency;

		public:
			Timer();

			void reset();

			float elapsed();
		};

	}
}
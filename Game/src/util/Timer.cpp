#include "Timer.h"

namespace engine { namespace utility {

	Timer::Timer() {
		QueryPerformanceCounter(&start);
		LARGE_INTEGER frequency;
		QueryPerformanceFrequency(&frequency);
		this->frequency = frequency.QuadPart;
	}

	void Timer::reset() {
		QueryPerformanceCounter(&start);
	}

	float Timer::elapsed() {
		LARGE_INTEGER current;
		QueryPerformanceCounter(&current);
		return (current.QuadPart - start.QuadPart) / frequency;
	}

}}
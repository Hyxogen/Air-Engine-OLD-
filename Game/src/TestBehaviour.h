#pragma once

#include <iostream>
#include "entity\EntityBehaviour.h"

namespace engine {
	namespace entity {

		struct TestBehaviour : EntityBehaviour {

			virtual void tickBehaviour();

		};

	}
}
#pragma once

#include <iostream>
#include "entity\EntityBehaviour.h"

namespace engine {
	namespace entity {

		struct TestBehaviour : public EntityBehaviour {

			virtual void tickBehaviour();

		};

	}
}
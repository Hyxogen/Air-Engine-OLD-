#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include "StringUtils.h"
#include "..\math\Math.h"
#include "..\io\FileUtils.h"
#include "..\geometry\Mesh.h"

namespace engine { namespace utility {

	geometry::Mesh* loadOBJModel(char* path);

}}
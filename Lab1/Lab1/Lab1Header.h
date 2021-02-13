#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

enum class arrayIndices {
	programName            = 0,
	inputFileName          = 1,
	expectedArgumentNumber = 2
};

enum class result {
	success             = 0,
	fileNonexisted      = 1,
	wrongArgumentNumber = 2
};

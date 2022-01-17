#include "common.hpp"

namespace util
{
	static bool does_file_exist(std::string path)
	{
		struct stat buffer;
		return (stat(path.c_str(), &buffer) == 0);
	}
}
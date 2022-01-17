#pragma once

#include "common.hpp"
#include "natives.hpp"
#include <imgui.h>

namespace big
{
	void set_bitset_one(int value);
	void set_bitset(int value);
	void set_stat(Hash stat, int value);

	class diamond_casino_heist
	{
	public:
		static void do_presentation_layer();
	};
};
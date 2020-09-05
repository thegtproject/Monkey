#pragma once
#include "Base.hpp"

namespace Monkey {

	Interface VirtualMachine {
	public:
		~VirtualMachine() = default;
		virtual int Init() = 0;
	};

}
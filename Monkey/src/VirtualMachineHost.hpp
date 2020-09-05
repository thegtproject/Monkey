#pragma once

#include "VirtualMachine.hpp"
#include <functional>

namespace Monkey {
	using VMFactoryFunc = std::function<Monkey::VirtualMachine*()>;

	class VirtualMachineHost
	{
	public:
		void SetCPU(int i);
		int  GetCPU() const;
		void SetVirtualMachine(VMFactoryFunc vmfactory);
		Monkey::VirtualMachine* VirtualMachine() const;
	public:
		VirtualMachineHost();
		~VirtualMachineHost();
	private:
		int m_cpu;
		Scope<Monkey::VirtualMachine*>	  m_virtualmachine;
	};
}
 
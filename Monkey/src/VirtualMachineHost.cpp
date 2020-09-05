#include "Base.hpp"
#include "VirtualMachineHost.hpp"
#include <functional>

namespace Monkey {

	

	void VirtualMachineHost::SetCPU(int i) {
		m_cpu = i;
		TRACE();
	}

	int VirtualMachineHost::GetCPU() const
	{
		return m_cpu;
	}
	
	void VirtualMachineHost::SetVirtualMachine(VMFactoryFunc vmfactory) {
		TRACE(); 
		m_virtualmachine = CreateScope<Monkey::VirtualMachine*>(vmfactory());
		//vm.swap(m_virtualmachine);
		//auto a = *m_virtualmachine.get();
		//a.Init();
	}

	VirtualMachine* VirtualMachineHost::VirtualMachine() const
	{
		return *m_virtualmachine.get();
	}

	VirtualMachineHost::VirtualMachineHost()
		: m_cpu(0) {
		TRACE();
	}

	VirtualMachineHost::~VirtualMachineHost() {
		TRACE();
	}
}
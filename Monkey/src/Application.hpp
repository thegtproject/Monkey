#pragma once 

namespace Monkey {
	class VirtualMachineHost;
	class VirtualMachine;
}

struct Options {
	enum class VM {
		XTulator,
		MXVM
	} a;
};

class Application
{
public:
	static Scope<Application> Setup(Options options);
	int Run();

public:
	Application();
	~Application();

private:
	Scope<Monkey::VirtualMachineHost> m_vmhost;
	
};


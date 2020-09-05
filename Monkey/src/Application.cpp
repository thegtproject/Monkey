#include "Base.hpp"
#include "Application.hpp"
#include "VirtualMachineHost.hpp"
#include "../XTulator.hpp"

Monkey::VirtualMachine* XTulatorFactory() {
    return (Monkey::VirtualMachine*)new XTulator::XTulator();
}

Monkey::VirtualMachine* MXVM1029() {
    return nullptr;
}

Scope<Application> Application::Setup(Options options) {
    TRACE();
    
    auto app      = CreateScope<Application>();
    app->m_vmhost = CreateScope<Monkey::VirtualMachineHost>();
    app->m_vmhost-> SetCPU(35);

    switch (options.a)
    {
    case Options::VM::XTulator:
        printf("vm option: XTulator\n");
        app->m_vmhost->SetVirtualMachine(XTulatorFactory);
        break;
    case Options::VM::MXVM:
        printf("vm option: MXVM\n");
        break;
    default:
        break;
    }

    return app;
}

int Application::Run() {
    TRACE();
    
    auto a = m_vmhost->VirtualMachine();

    a->Init();
    
    return m_vmhost->GetCPU();
}

Application::Application() {
    TRACE();
}

Application::~Application() {
    TRACE();
}

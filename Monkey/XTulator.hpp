#pragma once
#include "src/Application.hpp"
#include "src/VirtualMachine.hpp"

namespace XTulator {
	
	class XTulator : public Monkey::VirtualMachine
	{
	public:
		virtual int Init() override;
	public:
		XTulator();
		~XTulator()  ;
	};

	

}
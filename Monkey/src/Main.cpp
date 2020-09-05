#include <iostream>
#include "Base.hpp"
#include "Application.hpp"

int main(int argc, char* argv[]/*, char* envp[]*/) {
	//printf("main() argc: %i\n", argc);
	//for (int i = 0; i < argc; i++) {
	//	printf("[%i] \"%s\"\n", i, argv[i]);
	//}

	//for (int i = 0; envp[i] != NULL; ++i) { 
	//	std::cout << i << ": " << envp[i] << "\n";
	//}

	TRACE();

	auto app = Application::Setup(
		Options{
				Options::VM::XTulator,
			}
	);

	auto ret = app->Run();
	
	PRINT("finish code: %i\n", ret);

	return ret;
}
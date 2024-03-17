#include <iostream>
#include <main.hpp>

int main(int argc, char *argv[]) {
// TARGET ARCHITECTURE
#ifdef TARGET_IS_64_BIT
			std::cout << "64 bit." << std::endl;
#endif
#ifdef TARGET_IS_32_BIT
			std::cout << "32 bit." << std::endl;
#endif

// TARGET MODE
#ifdef DEBUG_MODE
			std::cout << "Debug mode." << std::endl;
#endif

#ifdef RELEASE_MODE
			std::cout << "Release mode." << std::endl;
#endif

#ifdef RELEASE_WITH_DEBUGINFO_MODE
			std::cout << "Release with debug mode." << std::endl;
#endif
#ifdef RELEASE_MINSIZE_MODE
			std::cout << "Release minsize mode." << std::endl;
#endif

// TARGET PLATFORM
#ifdef TARGET_IS_LINUX
			std::cout << "Linux." << std::endl;
#endif

#ifdef TARGET_IS_APPLE
			std::cout << "Apple." << std::endl;
#endif

#ifdef TARGET_IS_WINDOWS
			std::cout << "Windows." << std::endl;
#endif
			return (0);
}

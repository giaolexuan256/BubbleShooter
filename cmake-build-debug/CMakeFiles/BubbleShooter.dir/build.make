# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Dev\Projects\CLion\BubbleShooter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Dev\Projects\CLion\BubbleShooter\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BubbleShooter.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BubbleShooter.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BubbleShooter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BubbleShooter.dir/flags.make

CMakeFiles/BubbleShooter.dir/src/main.cpp.obj: CMakeFiles/BubbleShooter.dir/flags.make
CMakeFiles/BubbleShooter.dir/src/main.cpp.obj: CMakeFiles/BubbleShooter.dir/includes_CXX.rsp
CMakeFiles/BubbleShooter.dir/src/main.cpp.obj: ../src/main.cpp
CMakeFiles/BubbleShooter.dir/src/main.cpp.obj: CMakeFiles/BubbleShooter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Dev\Projects\CLion\BubbleShooter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BubbleShooter.dir/src/main.cpp.obj"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BubbleShooter.dir/src/main.cpp.obj -MF CMakeFiles\BubbleShooter.dir\src\main.cpp.obj.d -o CMakeFiles\BubbleShooter.dir\src\main.cpp.obj -c C:\Dev\Projects\CLion\BubbleShooter\src\main.cpp

CMakeFiles/BubbleShooter.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BubbleShooter.dir/src/main.cpp.i"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Dev\Projects\CLion\BubbleShooter\src\main.cpp > CMakeFiles\BubbleShooter.dir\src\main.cpp.i

CMakeFiles/BubbleShooter.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BubbleShooter.dir/src/main.cpp.s"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Dev\Projects\CLion\BubbleShooter\src\main.cpp -o CMakeFiles\BubbleShooter.dir\src\main.cpp.s

CMakeFiles/BubbleShooter.dir/src/TextureAlpha.cpp.obj: CMakeFiles/BubbleShooter.dir/flags.make
CMakeFiles/BubbleShooter.dir/src/TextureAlpha.cpp.obj: CMakeFiles/BubbleShooter.dir/includes_CXX.rsp
CMakeFiles/BubbleShooter.dir/src/TextureAlpha.cpp.obj: ../src/TextureAlpha.cpp
CMakeFiles/BubbleShooter.dir/src/TextureAlpha.cpp.obj: CMakeFiles/BubbleShooter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Dev\Projects\CLion\BubbleShooter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BubbleShooter.dir/src/TextureAlpha.cpp.obj"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BubbleShooter.dir/src/TextureAlpha.cpp.obj -MF CMakeFiles\BubbleShooter.dir\src\TextureAlpha.cpp.obj.d -o CMakeFiles\BubbleShooter.dir\src\TextureAlpha.cpp.obj -c C:\Dev\Projects\CLion\BubbleShooter\src\TextureAlpha.cpp

CMakeFiles/BubbleShooter.dir/src/TextureAlpha.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BubbleShooter.dir/src/TextureAlpha.cpp.i"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Dev\Projects\CLion\BubbleShooter\src\TextureAlpha.cpp > CMakeFiles\BubbleShooter.dir\src\TextureAlpha.cpp.i

CMakeFiles/BubbleShooter.dir/src/TextureAlpha.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BubbleShooter.dir/src/TextureAlpha.cpp.s"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Dev\Projects\CLion\BubbleShooter\src\TextureAlpha.cpp -o CMakeFiles\BubbleShooter.dir\src\TextureAlpha.cpp.s

CMakeFiles/BubbleShooter.dir/src/Bubble.cpp.obj: CMakeFiles/BubbleShooter.dir/flags.make
CMakeFiles/BubbleShooter.dir/src/Bubble.cpp.obj: CMakeFiles/BubbleShooter.dir/includes_CXX.rsp
CMakeFiles/BubbleShooter.dir/src/Bubble.cpp.obj: ../src/Bubble.cpp
CMakeFiles/BubbleShooter.dir/src/Bubble.cpp.obj: CMakeFiles/BubbleShooter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Dev\Projects\CLion\BubbleShooter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/BubbleShooter.dir/src/Bubble.cpp.obj"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BubbleShooter.dir/src/Bubble.cpp.obj -MF CMakeFiles\BubbleShooter.dir\src\Bubble.cpp.obj.d -o CMakeFiles\BubbleShooter.dir\src\Bubble.cpp.obj -c C:\Dev\Projects\CLion\BubbleShooter\src\Bubble.cpp

CMakeFiles/BubbleShooter.dir/src/Bubble.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BubbleShooter.dir/src/Bubble.cpp.i"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Dev\Projects\CLion\BubbleShooter\src\Bubble.cpp > CMakeFiles\BubbleShooter.dir\src\Bubble.cpp.i

CMakeFiles/BubbleShooter.dir/src/Bubble.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BubbleShooter.dir/src/Bubble.cpp.s"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Dev\Projects\CLion\BubbleShooter\src\Bubble.cpp -o CMakeFiles\BubbleShooter.dir\src\Bubble.cpp.s

CMakeFiles/BubbleShooter.dir/src/Game.cpp.obj: CMakeFiles/BubbleShooter.dir/flags.make
CMakeFiles/BubbleShooter.dir/src/Game.cpp.obj: CMakeFiles/BubbleShooter.dir/includes_CXX.rsp
CMakeFiles/BubbleShooter.dir/src/Game.cpp.obj: ../src/Game.cpp
CMakeFiles/BubbleShooter.dir/src/Game.cpp.obj: CMakeFiles/BubbleShooter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Dev\Projects\CLion\BubbleShooter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/BubbleShooter.dir/src/Game.cpp.obj"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BubbleShooter.dir/src/Game.cpp.obj -MF CMakeFiles\BubbleShooter.dir\src\Game.cpp.obj.d -o CMakeFiles\BubbleShooter.dir\src\Game.cpp.obj -c C:\Dev\Projects\CLion\BubbleShooter\src\Game.cpp

CMakeFiles/BubbleShooter.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BubbleShooter.dir/src/Game.cpp.i"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Dev\Projects\CLion\BubbleShooter\src\Game.cpp > CMakeFiles\BubbleShooter.dir\src\Game.cpp.i

CMakeFiles/BubbleShooter.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BubbleShooter.dir/src/Game.cpp.s"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Dev\Projects\CLion\BubbleShooter\src\Game.cpp -o CMakeFiles\BubbleShooter.dir\src\Game.cpp.s

CMakeFiles/BubbleShooter.dir/src/Arrow.cpp.obj: CMakeFiles/BubbleShooter.dir/flags.make
CMakeFiles/BubbleShooter.dir/src/Arrow.cpp.obj: CMakeFiles/BubbleShooter.dir/includes_CXX.rsp
CMakeFiles/BubbleShooter.dir/src/Arrow.cpp.obj: ../src/Arrow.cpp
CMakeFiles/BubbleShooter.dir/src/Arrow.cpp.obj: CMakeFiles/BubbleShooter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Dev\Projects\CLion\BubbleShooter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/BubbleShooter.dir/src/Arrow.cpp.obj"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BubbleShooter.dir/src/Arrow.cpp.obj -MF CMakeFiles\BubbleShooter.dir\src\Arrow.cpp.obj.d -o CMakeFiles\BubbleShooter.dir\src\Arrow.cpp.obj -c C:\Dev\Projects\CLion\BubbleShooter\src\Arrow.cpp

CMakeFiles/BubbleShooter.dir/src/Arrow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BubbleShooter.dir/src/Arrow.cpp.i"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Dev\Projects\CLion\BubbleShooter\src\Arrow.cpp > CMakeFiles\BubbleShooter.dir\src\Arrow.cpp.i

CMakeFiles/BubbleShooter.dir/src/Arrow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BubbleShooter.dir/src/Arrow.cpp.s"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Dev\Projects\CLion\BubbleShooter\src\Arrow.cpp -o CMakeFiles\BubbleShooter.dir\src\Arrow.cpp.s

CMakeFiles/BubbleShooter.dir/src/Point.cpp.obj: CMakeFiles/BubbleShooter.dir/flags.make
CMakeFiles/BubbleShooter.dir/src/Point.cpp.obj: CMakeFiles/BubbleShooter.dir/includes_CXX.rsp
CMakeFiles/BubbleShooter.dir/src/Point.cpp.obj: ../src/Point.cpp
CMakeFiles/BubbleShooter.dir/src/Point.cpp.obj: CMakeFiles/BubbleShooter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Dev\Projects\CLion\BubbleShooter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/BubbleShooter.dir/src/Point.cpp.obj"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BubbleShooter.dir/src/Point.cpp.obj -MF CMakeFiles\BubbleShooter.dir\src\Point.cpp.obj.d -o CMakeFiles\BubbleShooter.dir\src\Point.cpp.obj -c C:\Dev\Projects\CLion\BubbleShooter\src\Point.cpp

CMakeFiles/BubbleShooter.dir/src/Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BubbleShooter.dir/src/Point.cpp.i"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Dev\Projects\CLion\BubbleShooter\src\Point.cpp > CMakeFiles\BubbleShooter.dir\src\Point.cpp.i

CMakeFiles/BubbleShooter.dir/src/Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BubbleShooter.dir/src/Point.cpp.s"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Dev\Projects\CLion\BubbleShooter\src\Point.cpp -o CMakeFiles\BubbleShooter.dir\src\Point.cpp.s

CMakeFiles/BubbleShooter.dir/src/Utility.cpp.obj: CMakeFiles/BubbleShooter.dir/flags.make
CMakeFiles/BubbleShooter.dir/src/Utility.cpp.obj: CMakeFiles/BubbleShooter.dir/includes_CXX.rsp
CMakeFiles/BubbleShooter.dir/src/Utility.cpp.obj: ../src/Utility.cpp
CMakeFiles/BubbleShooter.dir/src/Utility.cpp.obj: CMakeFiles/BubbleShooter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Dev\Projects\CLion\BubbleShooter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/BubbleShooter.dir/src/Utility.cpp.obj"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BubbleShooter.dir/src/Utility.cpp.obj -MF CMakeFiles\BubbleShooter.dir\src\Utility.cpp.obj.d -o CMakeFiles\BubbleShooter.dir\src\Utility.cpp.obj -c C:\Dev\Projects\CLion\BubbleShooter\src\Utility.cpp

CMakeFiles/BubbleShooter.dir/src/Utility.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BubbleShooter.dir/src/Utility.cpp.i"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Dev\Projects\CLion\BubbleShooter\src\Utility.cpp > CMakeFiles\BubbleShooter.dir\src\Utility.cpp.i

CMakeFiles/BubbleShooter.dir/src/Utility.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BubbleShooter.dir/src/Utility.cpp.s"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Dev\Projects\CLion\BubbleShooter\src\Utility.cpp -o CMakeFiles\BubbleShooter.dir\src\Utility.cpp.s

CMakeFiles/BubbleShooter.dir/src/Cannon.cpp.obj: CMakeFiles/BubbleShooter.dir/flags.make
CMakeFiles/BubbleShooter.dir/src/Cannon.cpp.obj: CMakeFiles/BubbleShooter.dir/includes_CXX.rsp
CMakeFiles/BubbleShooter.dir/src/Cannon.cpp.obj: ../src/Cannon.cpp
CMakeFiles/BubbleShooter.dir/src/Cannon.cpp.obj: CMakeFiles/BubbleShooter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Dev\Projects\CLion\BubbleShooter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/BubbleShooter.dir/src/Cannon.cpp.obj"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BubbleShooter.dir/src/Cannon.cpp.obj -MF CMakeFiles\BubbleShooter.dir\src\Cannon.cpp.obj.d -o CMakeFiles\BubbleShooter.dir\src\Cannon.cpp.obj -c C:\Dev\Projects\CLion\BubbleShooter\src\Cannon.cpp

CMakeFiles/BubbleShooter.dir/src/Cannon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BubbleShooter.dir/src/Cannon.cpp.i"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Dev\Projects\CLion\BubbleShooter\src\Cannon.cpp > CMakeFiles\BubbleShooter.dir\src\Cannon.cpp.i

CMakeFiles/BubbleShooter.dir/src/Cannon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BubbleShooter.dir/src/Cannon.cpp.s"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Dev\Projects\CLion\BubbleShooter\src\Cannon.cpp -o CMakeFiles\BubbleShooter.dir\src\Cannon.cpp.s

CMakeFiles/BubbleShooter.dir/src/RandomBubbleColorGenerator.cpp.obj: CMakeFiles/BubbleShooter.dir/flags.make
CMakeFiles/BubbleShooter.dir/src/RandomBubbleColorGenerator.cpp.obj: CMakeFiles/BubbleShooter.dir/includes_CXX.rsp
CMakeFiles/BubbleShooter.dir/src/RandomBubbleColorGenerator.cpp.obj: ../src/RandomBubbleColorGenerator.cpp
CMakeFiles/BubbleShooter.dir/src/RandomBubbleColorGenerator.cpp.obj: CMakeFiles/BubbleShooter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Dev\Projects\CLion\BubbleShooter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/BubbleShooter.dir/src/RandomBubbleColorGenerator.cpp.obj"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BubbleShooter.dir/src/RandomBubbleColorGenerator.cpp.obj -MF CMakeFiles\BubbleShooter.dir\src\RandomBubbleColorGenerator.cpp.obj.d -o CMakeFiles\BubbleShooter.dir\src\RandomBubbleColorGenerator.cpp.obj -c C:\Dev\Projects\CLion\BubbleShooter\src\RandomBubbleColorGenerator.cpp

CMakeFiles/BubbleShooter.dir/src/RandomBubbleColorGenerator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BubbleShooter.dir/src/RandomBubbleColorGenerator.cpp.i"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Dev\Projects\CLion\BubbleShooter\src\RandomBubbleColorGenerator.cpp > CMakeFiles\BubbleShooter.dir\src\RandomBubbleColorGenerator.cpp.i

CMakeFiles/BubbleShooter.dir/src/RandomBubbleColorGenerator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BubbleShooter.dir/src/RandomBubbleColorGenerator.cpp.s"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Dev\Projects\CLion\BubbleShooter\src\RandomBubbleColorGenerator.cpp -o CMakeFiles\BubbleShooter.dir\src\RandomBubbleColorGenerator.cpp.s

CMakeFiles/BubbleShooter.dir/src/BubbleColorConverter.cpp.obj: CMakeFiles/BubbleShooter.dir/flags.make
CMakeFiles/BubbleShooter.dir/src/BubbleColorConverter.cpp.obj: CMakeFiles/BubbleShooter.dir/includes_CXX.rsp
CMakeFiles/BubbleShooter.dir/src/BubbleColorConverter.cpp.obj: ../src/BubbleColorConverter.cpp
CMakeFiles/BubbleShooter.dir/src/BubbleColorConverter.cpp.obj: CMakeFiles/BubbleShooter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Dev\Projects\CLion\BubbleShooter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/BubbleShooter.dir/src/BubbleColorConverter.cpp.obj"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BubbleShooter.dir/src/BubbleColorConverter.cpp.obj -MF CMakeFiles\BubbleShooter.dir\src\BubbleColorConverter.cpp.obj.d -o CMakeFiles\BubbleShooter.dir\src\BubbleColorConverter.cpp.obj -c C:\Dev\Projects\CLion\BubbleShooter\src\BubbleColorConverter.cpp

CMakeFiles/BubbleShooter.dir/src/BubbleColorConverter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BubbleShooter.dir/src/BubbleColorConverter.cpp.i"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Dev\Projects\CLion\BubbleShooter\src\BubbleColorConverter.cpp > CMakeFiles\BubbleShooter.dir\src\BubbleColorConverter.cpp.i

CMakeFiles/BubbleShooter.dir/src/BubbleColorConverter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BubbleShooter.dir/src/BubbleColorConverter.cpp.s"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Dev\Projects\CLion\BubbleShooter\src\BubbleColorConverter.cpp -o CMakeFiles\BubbleShooter.dir\src\BubbleColorConverter.cpp.s

CMakeFiles/BubbleShooter.dir/src/BubbleGridManager.cpp.obj: CMakeFiles/BubbleShooter.dir/flags.make
CMakeFiles/BubbleShooter.dir/src/BubbleGridManager.cpp.obj: CMakeFiles/BubbleShooter.dir/includes_CXX.rsp
CMakeFiles/BubbleShooter.dir/src/BubbleGridManager.cpp.obj: ../src/BubbleGridManager.cpp
CMakeFiles/BubbleShooter.dir/src/BubbleGridManager.cpp.obj: CMakeFiles/BubbleShooter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Dev\Projects\CLion\BubbleShooter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/BubbleShooter.dir/src/BubbleGridManager.cpp.obj"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BubbleShooter.dir/src/BubbleGridManager.cpp.obj -MF CMakeFiles\BubbleShooter.dir\src\BubbleGridManager.cpp.obj.d -o CMakeFiles\BubbleShooter.dir\src\BubbleGridManager.cpp.obj -c C:\Dev\Projects\CLion\BubbleShooter\src\BubbleGridManager.cpp

CMakeFiles/BubbleShooter.dir/src/BubbleGridManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BubbleShooter.dir/src/BubbleGridManager.cpp.i"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Dev\Projects\CLion\BubbleShooter\src\BubbleGridManager.cpp > CMakeFiles\BubbleShooter.dir\src\BubbleGridManager.cpp.i

CMakeFiles/BubbleShooter.dir/src/BubbleGridManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BubbleShooter.dir/src/BubbleGridManager.cpp.s"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Dev\Projects\CLion\BubbleShooter\src\BubbleGridManager.cpp -o CMakeFiles\BubbleShooter.dir\src\BubbleGridManager.cpp.s

CMakeFiles/BubbleShooter.dir/src/RandomNumberGenerator.cpp.obj: CMakeFiles/BubbleShooter.dir/flags.make
CMakeFiles/BubbleShooter.dir/src/RandomNumberGenerator.cpp.obj: CMakeFiles/BubbleShooter.dir/includes_CXX.rsp
CMakeFiles/BubbleShooter.dir/src/RandomNumberGenerator.cpp.obj: ../src/RandomNumberGenerator.cpp
CMakeFiles/BubbleShooter.dir/src/RandomNumberGenerator.cpp.obj: CMakeFiles/BubbleShooter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Dev\Projects\CLion\BubbleShooter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/BubbleShooter.dir/src/RandomNumberGenerator.cpp.obj"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BubbleShooter.dir/src/RandomNumberGenerator.cpp.obj -MF CMakeFiles\BubbleShooter.dir\src\RandomNumberGenerator.cpp.obj.d -o CMakeFiles\BubbleShooter.dir\src\RandomNumberGenerator.cpp.obj -c C:\Dev\Projects\CLion\BubbleShooter\src\RandomNumberGenerator.cpp

CMakeFiles/BubbleShooter.dir/src/RandomNumberGenerator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BubbleShooter.dir/src/RandomNumberGenerator.cpp.i"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Dev\Projects\CLion\BubbleShooter\src\RandomNumberGenerator.cpp > CMakeFiles\BubbleShooter.dir\src\RandomNumberGenerator.cpp.i

CMakeFiles/BubbleShooter.dir/src/RandomNumberGenerator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BubbleShooter.dir/src/RandomNumberGenerator.cpp.s"
	C:\Users\giaol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Dev\Projects\CLion\BubbleShooter\src\RandomNumberGenerator.cpp -o CMakeFiles\BubbleShooter.dir\src\RandomNumberGenerator.cpp.s

# Object files for target BubbleShooter
BubbleShooter_OBJECTS = \
"CMakeFiles/BubbleShooter.dir/src/main.cpp.obj" \
"CMakeFiles/BubbleShooter.dir/src/TextureAlpha.cpp.obj" \
"CMakeFiles/BubbleShooter.dir/src/Bubble.cpp.obj" \
"CMakeFiles/BubbleShooter.dir/src/Game.cpp.obj" \
"CMakeFiles/BubbleShooter.dir/src/Arrow.cpp.obj" \
"CMakeFiles/BubbleShooter.dir/src/Point.cpp.obj" \
"CMakeFiles/BubbleShooter.dir/src/Utility.cpp.obj" \
"CMakeFiles/BubbleShooter.dir/src/Cannon.cpp.obj" \
"CMakeFiles/BubbleShooter.dir/src/RandomBubbleColorGenerator.cpp.obj" \
"CMakeFiles/BubbleShooter.dir/src/BubbleColorConverter.cpp.obj" \
"CMakeFiles/BubbleShooter.dir/src/BubbleGridManager.cpp.obj" \
"CMakeFiles/BubbleShooter.dir/src/RandomNumberGenerator.cpp.obj"

# External object files for target BubbleShooter
BubbleShooter_EXTERNAL_OBJECTS =

BubbleShooter.exe: CMakeFiles/BubbleShooter.dir/src/main.cpp.obj
BubbleShooter.exe: CMakeFiles/BubbleShooter.dir/src/TextureAlpha.cpp.obj
BubbleShooter.exe: CMakeFiles/BubbleShooter.dir/src/Bubble.cpp.obj
BubbleShooter.exe: CMakeFiles/BubbleShooter.dir/src/Game.cpp.obj
BubbleShooter.exe: CMakeFiles/BubbleShooter.dir/src/Arrow.cpp.obj
BubbleShooter.exe: CMakeFiles/BubbleShooter.dir/src/Point.cpp.obj
BubbleShooter.exe: CMakeFiles/BubbleShooter.dir/src/Utility.cpp.obj
BubbleShooter.exe: CMakeFiles/BubbleShooter.dir/src/Cannon.cpp.obj
BubbleShooter.exe: CMakeFiles/BubbleShooter.dir/src/RandomBubbleColorGenerator.cpp.obj
BubbleShooter.exe: CMakeFiles/BubbleShooter.dir/src/BubbleColorConverter.cpp.obj
BubbleShooter.exe: CMakeFiles/BubbleShooter.dir/src/BubbleGridManager.cpp.obj
BubbleShooter.exe: CMakeFiles/BubbleShooter.dir/src/RandomNumberGenerator.cpp.obj
BubbleShooter.exe: CMakeFiles/BubbleShooter.dir/build.make
BubbleShooter.exe: CMakeFiles/BubbleShooter.dir/linklibs.rsp
BubbleShooter.exe: CMakeFiles/BubbleShooter.dir/objects1.rsp
BubbleShooter.exe: CMakeFiles/BubbleShooter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Dev\Projects\CLion\BubbleShooter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable BubbleShooter.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BubbleShooter.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BubbleShooter.dir/build: BubbleShooter.exe
.PHONY : CMakeFiles/BubbleShooter.dir/build

CMakeFiles/BubbleShooter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BubbleShooter.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BubbleShooter.dir/clean

CMakeFiles/BubbleShooter.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Dev\Projects\CLion\BubbleShooter C:\Dev\Projects\CLion\BubbleShooter C:\Dev\Projects\CLion\BubbleShooter\cmake-build-debug C:\Dev\Projects\CLion\BubbleShooter\cmake-build-debug C:\Dev\Projects\CLion\BubbleShooter\cmake-build-debug\CMakeFiles\BubbleShooter.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BubbleShooter.dir/depend


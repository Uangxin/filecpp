# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\JetBrains\CLion-2020.3.1.win\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = D:\JetBrains\CLion-2020.3.1.win\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\JetBrains\Clion-files\Experiment\Liberary

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\JetBrains\Clion-files\Experiment\Liberary\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Liberary.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Liberary.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Liberary.dir/flags.make

CMakeFiles/Liberary.dir/main.cpp.obj: CMakeFiles/Liberary.dir/flags.make
CMakeFiles/Liberary.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\JetBrains\Clion-files\Experiment\Liberary\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Liberary.dir/main.cpp.obj"
	"D:\Program Files\CodeBlocks\MinGW\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Liberary.dir\main.cpp.obj -c D:\JetBrains\Clion-files\Experiment\Liberary\main.cpp

CMakeFiles/Liberary.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Liberary.dir/main.cpp.i"
	"D:\Program Files\CodeBlocks\MinGW\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\JetBrains\Clion-files\Experiment\Liberary\main.cpp > CMakeFiles\Liberary.dir\main.cpp.i

CMakeFiles/Liberary.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Liberary.dir/main.cpp.s"
	"D:\Program Files\CodeBlocks\MinGW\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\JetBrains\Clion-files\Experiment\Liberary\main.cpp -o CMakeFiles\Liberary.dir\main.cpp.s

# Object files for target Liberary
Liberary_OBJECTS = \
"CMakeFiles/Liberary.dir/main.cpp.obj"

# External object files for target Liberary
Liberary_EXTERNAL_OBJECTS =

Liberary.exe: CMakeFiles/Liberary.dir/main.cpp.obj
Liberary.exe: CMakeFiles/Liberary.dir/build.make
Liberary.exe: CMakeFiles/Liberary.dir/linklibs.rsp
Liberary.exe: CMakeFiles/Liberary.dir/objects1.rsp
Liberary.exe: CMakeFiles/Liberary.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\JetBrains\Clion-files\Experiment\Liberary\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Liberary.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Liberary.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Liberary.dir/build: Liberary.exe

.PHONY : CMakeFiles/Liberary.dir/build

CMakeFiles/Liberary.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Liberary.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Liberary.dir/clean

CMakeFiles/Liberary.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\JetBrains\Clion-files\Experiment\Liberary D:\JetBrains\Clion-files\Experiment\Liberary D:\JetBrains\Clion-files\Experiment\Liberary\cmake-build-debug D:\JetBrains\Clion-files\Experiment\Liberary\cmake-build-debug D:\JetBrains\Clion-files\Experiment\Liberary\cmake-build-debug\CMakeFiles\Liberary.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Liberary.dir/depend

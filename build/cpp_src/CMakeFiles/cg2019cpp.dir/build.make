# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vertrigo/Desktop/OPENGL/icmc-cg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vertrigo/Desktop/OPENGL/icmc-cg/build

# Include any dependencies generated for this target.
include cpp_src/CMakeFiles/cg2019cpp.dir/depend.make

# Include the progress variables for this target.
include cpp_src/CMakeFiles/cg2019cpp.dir/progress.make

# Include the compile flags for this target's objects.
include cpp_src/CMakeFiles/cg2019cpp.dir/flags.make

cpp_src/CMakeFiles/cg2019cpp.dir/cg_window.cpp.o: cpp_src/CMakeFiles/cg2019cpp.dir/flags.make
cpp_src/CMakeFiles/cg2019cpp.dir/cg_window.cpp.o: ../cpp_src/cg_window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vertrigo/Desktop/OPENGL/icmc-cg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object cpp_src/CMakeFiles/cg2019cpp.dir/cg_window.cpp.o"
	cd /home/vertrigo/Desktop/OPENGL/icmc-cg/build/cpp_src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cg2019cpp.dir/cg_window.cpp.o -c /home/vertrigo/Desktop/OPENGL/icmc-cg/cpp_src/cg_window.cpp

cpp_src/CMakeFiles/cg2019cpp.dir/cg_window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cg2019cpp.dir/cg_window.cpp.i"
	cd /home/vertrigo/Desktop/OPENGL/icmc-cg/build/cpp_src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vertrigo/Desktop/OPENGL/icmc-cg/cpp_src/cg_window.cpp > CMakeFiles/cg2019cpp.dir/cg_window.cpp.i

cpp_src/CMakeFiles/cg2019cpp.dir/cg_window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cg2019cpp.dir/cg_window.cpp.s"
	cd /home/vertrigo/Desktop/OPENGL/icmc-cg/build/cpp_src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vertrigo/Desktop/OPENGL/icmc-cg/cpp_src/cg_window.cpp -o CMakeFiles/cg2019cpp.dir/cg_window.cpp.s

# Object files for target cg2019cpp
cg2019cpp_OBJECTS = \
"CMakeFiles/cg2019cpp.dir/cg_window.cpp.o"

# External object files for target cg2019cpp
cg2019cpp_EXTERNAL_OBJECTS =

cpp_src/libcg2019cpp.a: cpp_src/CMakeFiles/cg2019cpp.dir/cg_window.cpp.o
cpp_src/libcg2019cpp.a: cpp_src/CMakeFiles/cg2019cpp.dir/build.make
cpp_src/libcg2019cpp.a: cpp_src/CMakeFiles/cg2019cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vertrigo/Desktop/OPENGL/icmc-cg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libcg2019cpp.a"
	cd /home/vertrigo/Desktop/OPENGL/icmc-cg/build/cpp_src && $(CMAKE_COMMAND) -P CMakeFiles/cg2019cpp.dir/cmake_clean_target.cmake
	cd /home/vertrigo/Desktop/OPENGL/icmc-cg/build/cpp_src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cg2019cpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
cpp_src/CMakeFiles/cg2019cpp.dir/build: cpp_src/libcg2019cpp.a

.PHONY : cpp_src/CMakeFiles/cg2019cpp.dir/build

cpp_src/CMakeFiles/cg2019cpp.dir/clean:
	cd /home/vertrigo/Desktop/OPENGL/icmc-cg/build/cpp_src && $(CMAKE_COMMAND) -P CMakeFiles/cg2019cpp.dir/cmake_clean.cmake
.PHONY : cpp_src/CMakeFiles/cg2019cpp.dir/clean

cpp_src/CMakeFiles/cg2019cpp.dir/depend:
	cd /home/vertrigo/Desktop/OPENGL/icmc-cg/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vertrigo/Desktop/OPENGL/icmc-cg /home/vertrigo/Desktop/OPENGL/icmc-cg/cpp_src /home/vertrigo/Desktop/OPENGL/icmc-cg/build /home/vertrigo/Desktop/OPENGL/icmc-cg/build/cpp_src /home/vertrigo/Desktop/OPENGL/icmc-cg/build/cpp_src/CMakeFiles/cg2019cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : cpp_src/CMakeFiles/cg2019cpp.dir/depend


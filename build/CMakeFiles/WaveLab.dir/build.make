# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/morcillosanz/Desktop/GitHub/WaveLab

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/morcillosanz/Desktop/GitHub/WaveLab/build

# Include any dependencies generated for this target.
include CMakeFiles/WaveLab.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/WaveLab.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/WaveLab.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WaveLab.dir/flags.make

CMakeFiles/WaveLab.dir/glew/glew.cpp.o: CMakeFiles/WaveLab.dir/flags.make
CMakeFiles/WaveLab.dir/glew/glew.cpp.o: ../glew/glew.cpp
CMakeFiles/WaveLab.dir/glew/glew.cpp.o: CMakeFiles/WaveLab.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/morcillosanz/Desktop/GitHub/WaveLab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WaveLab.dir/glew/glew.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WaveLab.dir/glew/glew.cpp.o -MF CMakeFiles/WaveLab.dir/glew/glew.cpp.o.d -o CMakeFiles/WaveLab.dir/glew/glew.cpp.o -c /home/morcillosanz/Desktop/GitHub/WaveLab/glew/glew.cpp

CMakeFiles/WaveLab.dir/glew/glew.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WaveLab.dir/glew/glew.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/morcillosanz/Desktop/GitHub/WaveLab/glew/glew.cpp > CMakeFiles/WaveLab.dir/glew/glew.cpp.i

CMakeFiles/WaveLab.dir/glew/glew.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WaveLab.dir/glew/glew.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/morcillosanz/Desktop/GitHub/WaveLab/glew/glew.cpp -o CMakeFiles/WaveLab.dir/glew/glew.cpp.s

CMakeFiles/WaveLab.dir/imgui/imgui.cpp.o: CMakeFiles/WaveLab.dir/flags.make
CMakeFiles/WaveLab.dir/imgui/imgui.cpp.o: ../imgui/imgui.cpp
CMakeFiles/WaveLab.dir/imgui/imgui.cpp.o: CMakeFiles/WaveLab.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/morcillosanz/Desktop/GitHub/WaveLab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/WaveLab.dir/imgui/imgui.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WaveLab.dir/imgui/imgui.cpp.o -MF CMakeFiles/WaveLab.dir/imgui/imgui.cpp.o.d -o CMakeFiles/WaveLab.dir/imgui/imgui.cpp.o -c /home/morcillosanz/Desktop/GitHub/WaveLab/imgui/imgui.cpp

CMakeFiles/WaveLab.dir/imgui/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WaveLab.dir/imgui/imgui.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/morcillosanz/Desktop/GitHub/WaveLab/imgui/imgui.cpp > CMakeFiles/WaveLab.dir/imgui/imgui.cpp.i

CMakeFiles/WaveLab.dir/imgui/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WaveLab.dir/imgui/imgui.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/morcillosanz/Desktop/GitHub/WaveLab/imgui/imgui.cpp -o CMakeFiles/WaveLab.dir/imgui/imgui.cpp.s

CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_glfw.cpp.o: CMakeFiles/WaveLab.dir/flags.make
CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_glfw.cpp.o: ../imgui/backends/imgui_impl_glfw.cpp
CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_glfw.cpp.o: CMakeFiles/WaveLab.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/morcillosanz/Desktop/GitHub/WaveLab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_glfw.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_glfw.cpp.o -MF CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_glfw.cpp.o.d -o CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_glfw.cpp.o -c /home/morcillosanz/Desktop/GitHub/WaveLab/imgui/backends/imgui_impl_glfw.cpp

CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_glfw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_glfw.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/morcillosanz/Desktop/GitHub/WaveLab/imgui/backends/imgui_impl_glfw.cpp > CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_glfw.cpp.i

CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_glfw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_glfw.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/morcillosanz/Desktop/GitHub/WaveLab/imgui/backends/imgui_impl_glfw.cpp -o CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_glfw.cpp.s

CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_opengl3.cpp.o: CMakeFiles/WaveLab.dir/flags.make
CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_opengl3.cpp.o: ../imgui/backends/imgui_impl_opengl3.cpp
CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_opengl3.cpp.o: CMakeFiles/WaveLab.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/morcillosanz/Desktop/GitHub/WaveLab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_opengl3.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_opengl3.cpp.o -MF CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_opengl3.cpp.o.d -o CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_opengl3.cpp.o -c /home/morcillosanz/Desktop/GitHub/WaveLab/imgui/backends/imgui_impl_opengl3.cpp

CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_opengl3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_opengl3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/morcillosanz/Desktop/GitHub/WaveLab/imgui/backends/imgui_impl_opengl3.cpp > CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_opengl3.cpp.i

CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_opengl3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_opengl3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/morcillosanz/Desktop/GitHub/WaveLab/imgui/backends/imgui_impl_opengl3.cpp -o CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_opengl3.cpp.s

CMakeFiles/WaveLab.dir/imgui/imgui_demo.cpp.o: CMakeFiles/WaveLab.dir/flags.make
CMakeFiles/WaveLab.dir/imgui/imgui_demo.cpp.o: ../imgui/imgui_demo.cpp
CMakeFiles/WaveLab.dir/imgui/imgui_demo.cpp.o: CMakeFiles/WaveLab.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/morcillosanz/Desktop/GitHub/WaveLab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/WaveLab.dir/imgui/imgui_demo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WaveLab.dir/imgui/imgui_demo.cpp.o -MF CMakeFiles/WaveLab.dir/imgui/imgui_demo.cpp.o.d -o CMakeFiles/WaveLab.dir/imgui/imgui_demo.cpp.o -c /home/morcillosanz/Desktop/GitHub/WaveLab/imgui/imgui_demo.cpp

CMakeFiles/WaveLab.dir/imgui/imgui_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WaveLab.dir/imgui/imgui_demo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/morcillosanz/Desktop/GitHub/WaveLab/imgui/imgui_demo.cpp > CMakeFiles/WaveLab.dir/imgui/imgui_demo.cpp.i

CMakeFiles/WaveLab.dir/imgui/imgui_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WaveLab.dir/imgui/imgui_demo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/morcillosanz/Desktop/GitHub/WaveLab/imgui/imgui_demo.cpp -o CMakeFiles/WaveLab.dir/imgui/imgui_demo.cpp.s

CMakeFiles/WaveLab.dir/imgui/imgui_draw.cpp.o: CMakeFiles/WaveLab.dir/flags.make
CMakeFiles/WaveLab.dir/imgui/imgui_draw.cpp.o: ../imgui/imgui_draw.cpp
CMakeFiles/WaveLab.dir/imgui/imgui_draw.cpp.o: CMakeFiles/WaveLab.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/morcillosanz/Desktop/GitHub/WaveLab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/WaveLab.dir/imgui/imgui_draw.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WaveLab.dir/imgui/imgui_draw.cpp.o -MF CMakeFiles/WaveLab.dir/imgui/imgui_draw.cpp.o.d -o CMakeFiles/WaveLab.dir/imgui/imgui_draw.cpp.o -c /home/morcillosanz/Desktop/GitHub/WaveLab/imgui/imgui_draw.cpp

CMakeFiles/WaveLab.dir/imgui/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WaveLab.dir/imgui/imgui_draw.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/morcillosanz/Desktop/GitHub/WaveLab/imgui/imgui_draw.cpp > CMakeFiles/WaveLab.dir/imgui/imgui_draw.cpp.i

CMakeFiles/WaveLab.dir/imgui/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WaveLab.dir/imgui/imgui_draw.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/morcillosanz/Desktop/GitHub/WaveLab/imgui/imgui_draw.cpp -o CMakeFiles/WaveLab.dir/imgui/imgui_draw.cpp.s

CMakeFiles/WaveLab.dir/imgui/imgui_tables.cpp.o: CMakeFiles/WaveLab.dir/flags.make
CMakeFiles/WaveLab.dir/imgui/imgui_tables.cpp.o: ../imgui/imgui_tables.cpp
CMakeFiles/WaveLab.dir/imgui/imgui_tables.cpp.o: CMakeFiles/WaveLab.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/morcillosanz/Desktop/GitHub/WaveLab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/WaveLab.dir/imgui/imgui_tables.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WaveLab.dir/imgui/imgui_tables.cpp.o -MF CMakeFiles/WaveLab.dir/imgui/imgui_tables.cpp.o.d -o CMakeFiles/WaveLab.dir/imgui/imgui_tables.cpp.o -c /home/morcillosanz/Desktop/GitHub/WaveLab/imgui/imgui_tables.cpp

CMakeFiles/WaveLab.dir/imgui/imgui_tables.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WaveLab.dir/imgui/imgui_tables.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/morcillosanz/Desktop/GitHub/WaveLab/imgui/imgui_tables.cpp > CMakeFiles/WaveLab.dir/imgui/imgui_tables.cpp.i

CMakeFiles/WaveLab.dir/imgui/imgui_tables.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WaveLab.dir/imgui/imgui_tables.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/morcillosanz/Desktop/GitHub/WaveLab/imgui/imgui_tables.cpp -o CMakeFiles/WaveLab.dir/imgui/imgui_tables.cpp.s

CMakeFiles/WaveLab.dir/imgui/imgui_widgets.cpp.o: CMakeFiles/WaveLab.dir/flags.make
CMakeFiles/WaveLab.dir/imgui/imgui_widgets.cpp.o: ../imgui/imgui_widgets.cpp
CMakeFiles/WaveLab.dir/imgui/imgui_widgets.cpp.o: CMakeFiles/WaveLab.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/morcillosanz/Desktop/GitHub/WaveLab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/WaveLab.dir/imgui/imgui_widgets.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WaveLab.dir/imgui/imgui_widgets.cpp.o -MF CMakeFiles/WaveLab.dir/imgui/imgui_widgets.cpp.o.d -o CMakeFiles/WaveLab.dir/imgui/imgui_widgets.cpp.o -c /home/morcillosanz/Desktop/GitHub/WaveLab/imgui/imgui_widgets.cpp

CMakeFiles/WaveLab.dir/imgui/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WaveLab.dir/imgui/imgui_widgets.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/morcillosanz/Desktop/GitHub/WaveLab/imgui/imgui_widgets.cpp > CMakeFiles/WaveLab.dir/imgui/imgui_widgets.cpp.i

CMakeFiles/WaveLab.dir/imgui/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WaveLab.dir/imgui/imgui_widgets.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/morcillosanz/Desktop/GitHub/WaveLab/imgui/imgui_widgets.cpp -o CMakeFiles/WaveLab.dir/imgui/imgui_widgets.cpp.s

CMakeFiles/WaveLab.dir/src/WaveLab.cpp.o: CMakeFiles/WaveLab.dir/flags.make
CMakeFiles/WaveLab.dir/src/WaveLab.cpp.o: ../src/WaveLab.cpp
CMakeFiles/WaveLab.dir/src/WaveLab.cpp.o: CMakeFiles/WaveLab.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/morcillosanz/Desktop/GitHub/WaveLab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/WaveLab.dir/src/WaveLab.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WaveLab.dir/src/WaveLab.cpp.o -MF CMakeFiles/WaveLab.dir/src/WaveLab.cpp.o.d -o CMakeFiles/WaveLab.dir/src/WaveLab.cpp.o -c /home/morcillosanz/Desktop/GitHub/WaveLab/src/WaveLab.cpp

CMakeFiles/WaveLab.dir/src/WaveLab.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WaveLab.dir/src/WaveLab.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/morcillosanz/Desktop/GitHub/WaveLab/src/WaveLab.cpp > CMakeFiles/WaveLab.dir/src/WaveLab.cpp.i

CMakeFiles/WaveLab.dir/src/WaveLab.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WaveLab.dir/src/WaveLab.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/morcillosanz/Desktop/GitHub/WaveLab/src/WaveLab.cpp -o CMakeFiles/WaveLab.dir/src/WaveLab.cpp.s

CMakeFiles/WaveLab.dir/src/window/Window.cpp.o: CMakeFiles/WaveLab.dir/flags.make
CMakeFiles/WaveLab.dir/src/window/Window.cpp.o: ../src/window/Window.cpp
CMakeFiles/WaveLab.dir/src/window/Window.cpp.o: CMakeFiles/WaveLab.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/morcillosanz/Desktop/GitHub/WaveLab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/WaveLab.dir/src/window/Window.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WaveLab.dir/src/window/Window.cpp.o -MF CMakeFiles/WaveLab.dir/src/window/Window.cpp.o.d -o CMakeFiles/WaveLab.dir/src/window/Window.cpp.o -c /home/morcillosanz/Desktop/GitHub/WaveLab/src/window/Window.cpp

CMakeFiles/WaveLab.dir/src/window/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WaveLab.dir/src/window/Window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/morcillosanz/Desktop/GitHub/WaveLab/src/window/Window.cpp > CMakeFiles/WaveLab.dir/src/window/Window.cpp.i

CMakeFiles/WaveLab.dir/src/window/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WaveLab.dir/src/window/Window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/morcillosanz/Desktop/GitHub/WaveLab/src/window/Window.cpp -o CMakeFiles/WaveLab.dir/src/window/Window.cpp.s

CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexArray.cpp.o: CMakeFiles/WaveLab.dir/flags.make
CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexArray.cpp.o: ../src/opengl/buffer/VertexArray.cpp
CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexArray.cpp.o: CMakeFiles/WaveLab.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/morcillosanz/Desktop/GitHub/WaveLab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexArray.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexArray.cpp.o -MF CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexArray.cpp.o.d -o CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexArray.cpp.o -c /home/morcillosanz/Desktop/GitHub/WaveLab/src/opengl/buffer/VertexArray.cpp

CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexArray.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/morcillosanz/Desktop/GitHub/WaveLab/src/opengl/buffer/VertexArray.cpp > CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexArray.cpp.i

CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexArray.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/morcillosanz/Desktop/GitHub/WaveLab/src/opengl/buffer/VertexArray.cpp -o CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexArray.cpp.s

CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexBuffer.cpp.o: CMakeFiles/WaveLab.dir/flags.make
CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexBuffer.cpp.o: ../src/opengl/buffer/VertexBuffer.cpp
CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexBuffer.cpp.o: CMakeFiles/WaveLab.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/morcillosanz/Desktop/GitHub/WaveLab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexBuffer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexBuffer.cpp.o -MF CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexBuffer.cpp.o.d -o CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexBuffer.cpp.o -c /home/morcillosanz/Desktop/GitHub/WaveLab/src/opengl/buffer/VertexBuffer.cpp

CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexBuffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/morcillosanz/Desktop/GitHub/WaveLab/src/opengl/buffer/VertexBuffer.cpp > CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexBuffer.cpp.i

CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexBuffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/morcillosanz/Desktop/GitHub/WaveLab/src/opengl/buffer/VertexBuffer.cpp -o CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexBuffer.cpp.s

CMakeFiles/WaveLab.dir/src/opengl/shader/Shader.cpp.o: CMakeFiles/WaveLab.dir/flags.make
CMakeFiles/WaveLab.dir/src/opengl/shader/Shader.cpp.o: ../src/opengl/shader/Shader.cpp
CMakeFiles/WaveLab.dir/src/opengl/shader/Shader.cpp.o: CMakeFiles/WaveLab.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/morcillosanz/Desktop/GitHub/WaveLab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/WaveLab.dir/src/opengl/shader/Shader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WaveLab.dir/src/opengl/shader/Shader.cpp.o -MF CMakeFiles/WaveLab.dir/src/opengl/shader/Shader.cpp.o.d -o CMakeFiles/WaveLab.dir/src/opengl/shader/Shader.cpp.o -c /home/morcillosanz/Desktop/GitHub/WaveLab/src/opengl/shader/Shader.cpp

CMakeFiles/WaveLab.dir/src/opengl/shader/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WaveLab.dir/src/opengl/shader/Shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/morcillosanz/Desktop/GitHub/WaveLab/src/opengl/shader/Shader.cpp > CMakeFiles/WaveLab.dir/src/opengl/shader/Shader.cpp.i

CMakeFiles/WaveLab.dir/src/opengl/shader/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WaveLab.dir/src/opengl/shader/Shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/morcillosanz/Desktop/GitHub/WaveLab/src/opengl/shader/Shader.cpp -o CMakeFiles/WaveLab.dir/src/opengl/shader/Shader.cpp.s

CMakeFiles/WaveLab.dir/src/group/Polytope.cpp.o: CMakeFiles/WaveLab.dir/flags.make
CMakeFiles/WaveLab.dir/src/group/Polytope.cpp.o: ../src/group/Polytope.cpp
CMakeFiles/WaveLab.dir/src/group/Polytope.cpp.o: CMakeFiles/WaveLab.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/morcillosanz/Desktop/GitHub/WaveLab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/WaveLab.dir/src/group/Polytope.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WaveLab.dir/src/group/Polytope.cpp.o -MF CMakeFiles/WaveLab.dir/src/group/Polytope.cpp.o.d -o CMakeFiles/WaveLab.dir/src/group/Polytope.cpp.o -c /home/morcillosanz/Desktop/GitHub/WaveLab/src/group/Polytope.cpp

CMakeFiles/WaveLab.dir/src/group/Polytope.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WaveLab.dir/src/group/Polytope.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/morcillosanz/Desktop/GitHub/WaveLab/src/group/Polytope.cpp > CMakeFiles/WaveLab.dir/src/group/Polytope.cpp.i

CMakeFiles/WaveLab.dir/src/group/Polytope.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WaveLab.dir/src/group/Polytope.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/morcillosanz/Desktop/GitHub/WaveLab/src/group/Polytope.cpp -o CMakeFiles/WaveLab.dir/src/group/Polytope.cpp.s

CMakeFiles/WaveLab.dir/src/group/Group.cpp.o: CMakeFiles/WaveLab.dir/flags.make
CMakeFiles/WaveLab.dir/src/group/Group.cpp.o: ../src/group/Group.cpp
CMakeFiles/WaveLab.dir/src/group/Group.cpp.o: CMakeFiles/WaveLab.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/morcillosanz/Desktop/GitHub/WaveLab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/WaveLab.dir/src/group/Group.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WaveLab.dir/src/group/Group.cpp.o -MF CMakeFiles/WaveLab.dir/src/group/Group.cpp.o.d -o CMakeFiles/WaveLab.dir/src/group/Group.cpp.o -c /home/morcillosanz/Desktop/GitHub/WaveLab/src/group/Group.cpp

CMakeFiles/WaveLab.dir/src/group/Group.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WaveLab.dir/src/group/Group.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/morcillosanz/Desktop/GitHub/WaveLab/src/group/Group.cpp > CMakeFiles/WaveLab.dir/src/group/Group.cpp.i

CMakeFiles/WaveLab.dir/src/group/Group.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WaveLab.dir/src/group/Group.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/morcillosanz/Desktop/GitHub/WaveLab/src/group/Group.cpp -o CMakeFiles/WaveLab.dir/src/group/Group.cpp.s

# Object files for target WaveLab
WaveLab_OBJECTS = \
"CMakeFiles/WaveLab.dir/glew/glew.cpp.o" \
"CMakeFiles/WaveLab.dir/imgui/imgui.cpp.o" \
"CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_glfw.cpp.o" \
"CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_opengl3.cpp.o" \
"CMakeFiles/WaveLab.dir/imgui/imgui_demo.cpp.o" \
"CMakeFiles/WaveLab.dir/imgui/imgui_draw.cpp.o" \
"CMakeFiles/WaveLab.dir/imgui/imgui_tables.cpp.o" \
"CMakeFiles/WaveLab.dir/imgui/imgui_widgets.cpp.o" \
"CMakeFiles/WaveLab.dir/src/WaveLab.cpp.o" \
"CMakeFiles/WaveLab.dir/src/window/Window.cpp.o" \
"CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexArray.cpp.o" \
"CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexBuffer.cpp.o" \
"CMakeFiles/WaveLab.dir/src/opengl/shader/Shader.cpp.o" \
"CMakeFiles/WaveLab.dir/src/group/Polytope.cpp.o" \
"CMakeFiles/WaveLab.dir/src/group/Group.cpp.o"

# External object files for target WaveLab
WaveLab_EXTERNAL_OBJECTS =

WaveLab: CMakeFiles/WaveLab.dir/glew/glew.cpp.o
WaveLab: CMakeFiles/WaveLab.dir/imgui/imgui.cpp.o
WaveLab: CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_glfw.cpp.o
WaveLab: CMakeFiles/WaveLab.dir/imgui/backends/imgui_impl_opengl3.cpp.o
WaveLab: CMakeFiles/WaveLab.dir/imgui/imgui_demo.cpp.o
WaveLab: CMakeFiles/WaveLab.dir/imgui/imgui_draw.cpp.o
WaveLab: CMakeFiles/WaveLab.dir/imgui/imgui_tables.cpp.o
WaveLab: CMakeFiles/WaveLab.dir/imgui/imgui_widgets.cpp.o
WaveLab: CMakeFiles/WaveLab.dir/src/WaveLab.cpp.o
WaveLab: CMakeFiles/WaveLab.dir/src/window/Window.cpp.o
WaveLab: CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexArray.cpp.o
WaveLab: CMakeFiles/WaveLab.dir/src/opengl/buffer/VertexBuffer.cpp.o
WaveLab: CMakeFiles/WaveLab.dir/src/opengl/shader/Shader.cpp.o
WaveLab: CMakeFiles/WaveLab.dir/src/group/Polytope.cpp.o
WaveLab: CMakeFiles/WaveLab.dir/src/group/Group.cpp.o
WaveLab: CMakeFiles/WaveLab.dir/build.make
WaveLab: CMakeFiles/WaveLab.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/morcillosanz/Desktop/GitHub/WaveLab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Linking CXX executable WaveLab"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WaveLab.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WaveLab.dir/build: WaveLab
.PHONY : CMakeFiles/WaveLab.dir/build

CMakeFiles/WaveLab.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/WaveLab.dir/cmake_clean.cmake
.PHONY : CMakeFiles/WaveLab.dir/clean

CMakeFiles/WaveLab.dir/depend:
	cd /home/morcillosanz/Desktop/GitHub/WaveLab/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/morcillosanz/Desktop/GitHub/WaveLab /home/morcillosanz/Desktop/GitHub/WaveLab /home/morcillosanz/Desktop/GitHub/WaveLab/build /home/morcillosanz/Desktop/GitHub/WaveLab/build /home/morcillosanz/Desktop/GitHub/WaveLab/build/CMakeFiles/WaveLab.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/WaveLab.dir/depend


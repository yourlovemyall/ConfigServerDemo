# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/xuxiaoyu/ClionProjects/commonconfig/Db

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/xuxiaoyu/ClionProjects/commonconfig/Db

# Include any dependencies generated for this target.
include CMakeFiles/Db.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Db.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Db.dir/flags.make

CMakeFiles/Db.dir/ConnectionWorker.o: CMakeFiles/Db.dir/flags.make
CMakeFiles/Db.dir/ConnectionWorker.o: ConnectionWorker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xuxiaoyu/ClionProjects/commonconfig/Db/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Db.dir/ConnectionWorker.o"
	/Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Db.dir/ConnectionWorker.o -c /Users/xuxiaoyu/ClionProjects/commonconfig/Db/ConnectionWorker.cpp

CMakeFiles/Db.dir/ConnectionWorker.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Db.dir/ConnectionWorker.i"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xuxiaoyu/ClionProjects/commonconfig/Db/ConnectionWorker.cpp > CMakeFiles/Db.dir/ConnectionWorker.i

CMakeFiles/Db.dir/ConnectionWorker.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Db.dir/ConnectionWorker.s"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xuxiaoyu/ClionProjects/commonconfig/Db/ConnectionWorker.cpp -o CMakeFiles/Db.dir/ConnectionWorker.s

CMakeFiles/Db.dir/ConnectionWorker.o.requires:

.PHONY : CMakeFiles/Db.dir/ConnectionWorker.o.requires

CMakeFiles/Db.dir/ConnectionWorker.o.provides: CMakeFiles/Db.dir/ConnectionWorker.o.requires
	$(MAKE) -f CMakeFiles/Db.dir/build.make CMakeFiles/Db.dir/ConnectionWorker.o.provides.build
.PHONY : CMakeFiles/Db.dir/ConnectionWorker.o.provides

CMakeFiles/Db.dir/ConnectionWorker.o.provides.build: CMakeFiles/Db.dir/ConnectionWorker.o


CMakeFiles/Db.dir/ConnectionPool.o: CMakeFiles/Db.dir/flags.make
CMakeFiles/Db.dir/ConnectionPool.o: ConnectionPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xuxiaoyu/ClionProjects/commonconfig/Db/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Db.dir/ConnectionPool.o"
	/Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Db.dir/ConnectionPool.o -c /Users/xuxiaoyu/ClionProjects/commonconfig/Db/ConnectionPool.cpp

CMakeFiles/Db.dir/ConnectionPool.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Db.dir/ConnectionPool.i"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xuxiaoyu/ClionProjects/commonconfig/Db/ConnectionPool.cpp > CMakeFiles/Db.dir/ConnectionPool.i

CMakeFiles/Db.dir/ConnectionPool.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Db.dir/ConnectionPool.s"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xuxiaoyu/ClionProjects/commonconfig/Db/ConnectionPool.cpp -o CMakeFiles/Db.dir/ConnectionPool.s

CMakeFiles/Db.dir/ConnectionPool.o.requires:

.PHONY : CMakeFiles/Db.dir/ConnectionPool.o.requires

CMakeFiles/Db.dir/ConnectionPool.o.provides: CMakeFiles/Db.dir/ConnectionPool.o.requires
	$(MAKE) -f CMakeFiles/Db.dir/build.make CMakeFiles/Db.dir/ConnectionPool.o.provides.build
.PHONY : CMakeFiles/Db.dir/ConnectionPool.o.provides

CMakeFiles/Db.dir/ConnectionPool.o.provides.build: CMakeFiles/Db.dir/ConnectionPool.o


CMakeFiles/Db.dir/Connection.o: CMakeFiles/Db.dir/flags.make
CMakeFiles/Db.dir/Connection.o: Connection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xuxiaoyu/ClionProjects/commonconfig/Db/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Db.dir/Connection.o"
	/Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Db.dir/Connection.o -c /Users/xuxiaoyu/ClionProjects/commonconfig/Db/Connection.cpp

CMakeFiles/Db.dir/Connection.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Db.dir/Connection.i"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xuxiaoyu/ClionProjects/commonconfig/Db/Connection.cpp > CMakeFiles/Db.dir/Connection.i

CMakeFiles/Db.dir/Connection.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Db.dir/Connection.s"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xuxiaoyu/ClionProjects/commonconfig/Db/Connection.cpp -o CMakeFiles/Db.dir/Connection.s

CMakeFiles/Db.dir/Connection.o.requires:

.PHONY : CMakeFiles/Db.dir/Connection.o.requires

CMakeFiles/Db.dir/Connection.o.provides: CMakeFiles/Db.dir/Connection.o.requires
	$(MAKE) -f CMakeFiles/Db.dir/build.make CMakeFiles/Db.dir/Connection.o.provides.build
.PHONY : CMakeFiles/Db.dir/Connection.o.provides

CMakeFiles/Db.dir/Connection.o.provides.build: CMakeFiles/Db.dir/Connection.o


# Object files for target Db
Db_OBJECTS = \
"CMakeFiles/Db.dir/ConnectionWorker.o" \
"CMakeFiles/Db.dir/ConnectionPool.o" \
"CMakeFiles/Db.dir/Connection.o"

# External object files for target Db
Db_EXTERNAL_OBJECTS =

/Users/xuxiaoyu/ClionProjects/commonconfig/lib/libDb.a: CMakeFiles/Db.dir/ConnectionWorker.o
/Users/xuxiaoyu/ClionProjects/commonconfig/lib/libDb.a: CMakeFiles/Db.dir/ConnectionPool.o
/Users/xuxiaoyu/ClionProjects/commonconfig/lib/libDb.a: CMakeFiles/Db.dir/Connection.o
/Users/xuxiaoyu/ClionProjects/commonconfig/lib/libDb.a: CMakeFiles/Db.dir/build.make
/Users/xuxiaoyu/ClionProjects/commonconfig/lib/libDb.a: CMakeFiles/Db.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/xuxiaoyu/ClionProjects/commonconfig/Db/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library /Users/xuxiaoyu/ClionProjects/commonconfig/lib/libDb.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Db.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Db.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Db.dir/build: /Users/xuxiaoyu/ClionProjects/commonconfig/lib/libDb.a

.PHONY : CMakeFiles/Db.dir/build

CMakeFiles/Db.dir/requires: CMakeFiles/Db.dir/ConnectionWorker.o.requires
CMakeFiles/Db.dir/requires: CMakeFiles/Db.dir/ConnectionPool.o.requires
CMakeFiles/Db.dir/requires: CMakeFiles/Db.dir/Connection.o.requires

.PHONY : CMakeFiles/Db.dir/requires

CMakeFiles/Db.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Db.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Db.dir/clean

CMakeFiles/Db.dir/depend:
	cd /Users/xuxiaoyu/ClionProjects/commonconfig/Db && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/xuxiaoyu/ClionProjects/commonconfig/Db /Users/xuxiaoyu/ClionProjects/commonconfig/Db /Users/xuxiaoyu/ClionProjects/commonconfig/Db /Users/xuxiaoyu/ClionProjects/commonconfig/Db /Users/xuxiaoyu/ClionProjects/commonconfig/Db/CMakeFiles/Db.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Db.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/abc/桌面/code/chat_tool

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/abc/桌面/code/chat_tool/build

# Include any dependencies generated for this target.
include CMakeFiles/app.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/app.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/app.dir/flags.make

CMakeFiles/app.dir/src/Acceptor.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/Acceptor.cpp.o: /home/abc/桌面/code/chat_tool/src/Acceptor.cpp
CMakeFiles/app.dir/src/Acceptor.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abc/桌面/code/chat_tool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/app.dir/src/Acceptor.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/Acceptor.cpp.o -MF CMakeFiles/app.dir/src/Acceptor.cpp.o.d -o CMakeFiles/app.dir/src/Acceptor.cpp.o -c /home/abc/桌面/code/chat_tool/src/Acceptor.cpp

CMakeFiles/app.dir/src/Acceptor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/Acceptor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abc/桌面/code/chat_tool/src/Acceptor.cpp > CMakeFiles/app.dir/src/Acceptor.cpp.i

CMakeFiles/app.dir/src/Acceptor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/Acceptor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abc/桌面/code/chat_tool/src/Acceptor.cpp -o CMakeFiles/app.dir/src/Acceptor.cpp.s

CMakeFiles/app.dir/src/Buffer.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/Buffer.cpp.o: /home/abc/桌面/code/chat_tool/src/Buffer.cpp
CMakeFiles/app.dir/src/Buffer.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abc/桌面/code/chat_tool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/app.dir/src/Buffer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/Buffer.cpp.o -MF CMakeFiles/app.dir/src/Buffer.cpp.o.d -o CMakeFiles/app.dir/src/Buffer.cpp.o -c /home/abc/桌面/code/chat_tool/src/Buffer.cpp

CMakeFiles/app.dir/src/Buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/Buffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abc/桌面/code/chat_tool/src/Buffer.cpp > CMakeFiles/app.dir/src/Buffer.cpp.i

CMakeFiles/app.dir/src/Buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/Buffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abc/桌面/code/chat_tool/src/Buffer.cpp -o CMakeFiles/app.dir/src/Buffer.cpp.s

CMakeFiles/app.dir/src/Channel.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/Channel.cpp.o: /home/abc/桌面/code/chat_tool/src/Channel.cpp
CMakeFiles/app.dir/src/Channel.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abc/桌面/code/chat_tool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/app.dir/src/Channel.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/Channel.cpp.o -MF CMakeFiles/app.dir/src/Channel.cpp.o.d -o CMakeFiles/app.dir/src/Channel.cpp.o -c /home/abc/桌面/code/chat_tool/src/Channel.cpp

CMakeFiles/app.dir/src/Channel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/Channel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abc/桌面/code/chat_tool/src/Channel.cpp > CMakeFiles/app.dir/src/Channel.cpp.i

CMakeFiles/app.dir/src/Channel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/Channel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abc/桌面/code/chat_tool/src/Channel.cpp -o CMakeFiles/app.dir/src/Channel.cpp.s

CMakeFiles/app.dir/src/Connection.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/Connection.cpp.o: /home/abc/桌面/code/chat_tool/src/Connection.cpp
CMakeFiles/app.dir/src/Connection.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abc/桌面/code/chat_tool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/app.dir/src/Connection.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/Connection.cpp.o -MF CMakeFiles/app.dir/src/Connection.cpp.o.d -o CMakeFiles/app.dir/src/Connection.cpp.o -c /home/abc/桌面/code/chat_tool/src/Connection.cpp

CMakeFiles/app.dir/src/Connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/Connection.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abc/桌面/code/chat_tool/src/Connection.cpp > CMakeFiles/app.dir/src/Connection.cpp.i

CMakeFiles/app.dir/src/Connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/Connection.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abc/桌面/code/chat_tool/src/Connection.cpp -o CMakeFiles/app.dir/src/Connection.cpp.s

CMakeFiles/app.dir/src/Epoll.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/Epoll.cpp.o: /home/abc/桌面/code/chat_tool/src/Epoll.cpp
CMakeFiles/app.dir/src/Epoll.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abc/桌面/code/chat_tool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/app.dir/src/Epoll.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/Epoll.cpp.o -MF CMakeFiles/app.dir/src/Epoll.cpp.o.d -o CMakeFiles/app.dir/src/Epoll.cpp.o -c /home/abc/桌面/code/chat_tool/src/Epoll.cpp

CMakeFiles/app.dir/src/Epoll.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/Epoll.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abc/桌面/code/chat_tool/src/Epoll.cpp > CMakeFiles/app.dir/src/Epoll.cpp.i

CMakeFiles/app.dir/src/Epoll.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/Epoll.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abc/桌面/code/chat_tool/src/Epoll.cpp -o CMakeFiles/app.dir/src/Epoll.cpp.s

CMakeFiles/app.dir/src/EventLoop.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/EventLoop.cpp.o: /home/abc/桌面/code/chat_tool/src/EventLoop.cpp
CMakeFiles/app.dir/src/EventLoop.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abc/桌面/code/chat_tool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/app.dir/src/EventLoop.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/EventLoop.cpp.o -MF CMakeFiles/app.dir/src/EventLoop.cpp.o.d -o CMakeFiles/app.dir/src/EventLoop.cpp.o -c /home/abc/桌面/code/chat_tool/src/EventLoop.cpp

CMakeFiles/app.dir/src/EventLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/EventLoop.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abc/桌面/code/chat_tool/src/EventLoop.cpp > CMakeFiles/app.dir/src/EventLoop.cpp.i

CMakeFiles/app.dir/src/EventLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/EventLoop.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abc/桌面/code/chat_tool/src/EventLoop.cpp -o CMakeFiles/app.dir/src/EventLoop.cpp.s

CMakeFiles/app.dir/src/Mysql.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/Mysql.cpp.o: /home/abc/桌面/code/chat_tool/src/Mysql.cpp
CMakeFiles/app.dir/src/Mysql.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abc/桌面/code/chat_tool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/app.dir/src/Mysql.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/Mysql.cpp.o -MF CMakeFiles/app.dir/src/Mysql.cpp.o.d -o CMakeFiles/app.dir/src/Mysql.cpp.o -c /home/abc/桌面/code/chat_tool/src/Mysql.cpp

CMakeFiles/app.dir/src/Mysql.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/Mysql.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abc/桌面/code/chat_tool/src/Mysql.cpp > CMakeFiles/app.dir/src/Mysql.cpp.i

CMakeFiles/app.dir/src/Mysql.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/Mysql.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abc/桌面/code/chat_tool/src/Mysql.cpp -o CMakeFiles/app.dir/src/Mysql.cpp.s

CMakeFiles/app.dir/src/Server.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/Server.cpp.o: /home/abc/桌面/code/chat_tool/src/Server.cpp
CMakeFiles/app.dir/src/Server.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abc/桌面/code/chat_tool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/app.dir/src/Server.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/Server.cpp.o -MF CMakeFiles/app.dir/src/Server.cpp.o.d -o CMakeFiles/app.dir/src/Server.cpp.o -c /home/abc/桌面/code/chat_tool/src/Server.cpp

CMakeFiles/app.dir/src/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/Server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abc/桌面/code/chat_tool/src/Server.cpp > CMakeFiles/app.dir/src/Server.cpp.i

CMakeFiles/app.dir/src/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/Server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abc/桌面/code/chat_tool/src/Server.cpp -o CMakeFiles/app.dir/src/Server.cpp.s

CMakeFiles/app.dir/src/Socket.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/Socket.cpp.o: /home/abc/桌面/code/chat_tool/src/Socket.cpp
CMakeFiles/app.dir/src/Socket.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abc/桌面/code/chat_tool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/app.dir/src/Socket.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/Socket.cpp.o -MF CMakeFiles/app.dir/src/Socket.cpp.o.d -o CMakeFiles/app.dir/src/Socket.cpp.o -c /home/abc/桌面/code/chat_tool/src/Socket.cpp

CMakeFiles/app.dir/src/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/Socket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abc/桌面/code/chat_tool/src/Socket.cpp > CMakeFiles/app.dir/src/Socket.cpp.i

CMakeFiles/app.dir/src/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/Socket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abc/桌面/code/chat_tool/src/Socket.cpp -o CMakeFiles/app.dir/src/Socket.cpp.s

CMakeFiles/app.dir/src/ThreadPool.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/ThreadPool.cpp.o: /home/abc/桌面/code/chat_tool/src/ThreadPool.cpp
CMakeFiles/app.dir/src/ThreadPool.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abc/桌面/code/chat_tool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/app.dir/src/ThreadPool.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/ThreadPool.cpp.o -MF CMakeFiles/app.dir/src/ThreadPool.cpp.o.d -o CMakeFiles/app.dir/src/ThreadPool.cpp.o -c /home/abc/桌面/code/chat_tool/src/ThreadPool.cpp

CMakeFiles/app.dir/src/ThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/ThreadPool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abc/桌面/code/chat_tool/src/ThreadPool.cpp > CMakeFiles/app.dir/src/ThreadPool.cpp.i

CMakeFiles/app.dir/src/ThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/ThreadPool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abc/桌面/code/chat_tool/src/ThreadPool.cpp -o CMakeFiles/app.dir/src/ThreadPool.cpp.s

CMakeFiles/app.dir/src/util.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/util.cpp.o: /home/abc/桌面/code/chat_tool/src/util.cpp
CMakeFiles/app.dir/src/util.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abc/桌面/code/chat_tool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/app.dir/src/util.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/util.cpp.o -MF CMakeFiles/app.dir/src/util.cpp.o.d -o CMakeFiles/app.dir/src/util.cpp.o -c /home/abc/桌面/code/chat_tool/src/util.cpp

CMakeFiles/app.dir/src/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/util.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abc/桌面/code/chat_tool/src/util.cpp > CMakeFiles/app.dir/src/util.cpp.i

CMakeFiles/app.dir/src/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/util.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abc/桌面/code/chat_tool/src/util.cpp -o CMakeFiles/app.dir/src/util.cpp.s

CMakeFiles/app.dir/test/server.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/test/server.cpp.o: /home/abc/桌面/code/chat_tool/test/server.cpp
CMakeFiles/app.dir/test/server.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abc/桌面/code/chat_tool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/app.dir/test/server.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/test/server.cpp.o -MF CMakeFiles/app.dir/test/server.cpp.o.d -o CMakeFiles/app.dir/test/server.cpp.o -c /home/abc/桌面/code/chat_tool/test/server.cpp

CMakeFiles/app.dir/test/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/test/server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abc/桌面/code/chat_tool/test/server.cpp > CMakeFiles/app.dir/test/server.cpp.i

CMakeFiles/app.dir/test/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/test/server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abc/桌面/code/chat_tool/test/server.cpp -o CMakeFiles/app.dir/test/server.cpp.s

# Object files for target app
app_OBJECTS = \
"CMakeFiles/app.dir/src/Acceptor.cpp.o" \
"CMakeFiles/app.dir/src/Buffer.cpp.o" \
"CMakeFiles/app.dir/src/Channel.cpp.o" \
"CMakeFiles/app.dir/src/Connection.cpp.o" \
"CMakeFiles/app.dir/src/Epoll.cpp.o" \
"CMakeFiles/app.dir/src/EventLoop.cpp.o" \
"CMakeFiles/app.dir/src/Mysql.cpp.o" \
"CMakeFiles/app.dir/src/Server.cpp.o" \
"CMakeFiles/app.dir/src/Socket.cpp.o" \
"CMakeFiles/app.dir/src/ThreadPool.cpp.o" \
"CMakeFiles/app.dir/src/util.cpp.o" \
"CMakeFiles/app.dir/test/server.cpp.o"

# External object files for target app
app_EXTERNAL_OBJECTS =

/home/abc/桌面/code/chat_tool/app: CMakeFiles/app.dir/src/Acceptor.cpp.o
/home/abc/桌面/code/chat_tool/app: CMakeFiles/app.dir/src/Buffer.cpp.o
/home/abc/桌面/code/chat_tool/app: CMakeFiles/app.dir/src/Channel.cpp.o
/home/abc/桌面/code/chat_tool/app: CMakeFiles/app.dir/src/Connection.cpp.o
/home/abc/桌面/code/chat_tool/app: CMakeFiles/app.dir/src/Epoll.cpp.o
/home/abc/桌面/code/chat_tool/app: CMakeFiles/app.dir/src/EventLoop.cpp.o
/home/abc/桌面/code/chat_tool/app: CMakeFiles/app.dir/src/Mysql.cpp.o
/home/abc/桌面/code/chat_tool/app: CMakeFiles/app.dir/src/Server.cpp.o
/home/abc/桌面/code/chat_tool/app: CMakeFiles/app.dir/src/Socket.cpp.o
/home/abc/桌面/code/chat_tool/app: CMakeFiles/app.dir/src/ThreadPool.cpp.o
/home/abc/桌面/code/chat_tool/app: CMakeFiles/app.dir/src/util.cpp.o
/home/abc/桌面/code/chat_tool/app: CMakeFiles/app.dir/test/server.cpp.o
/home/abc/桌面/code/chat_tool/app: CMakeFiles/app.dir/build.make
/home/abc/桌面/code/chat_tool/app: CMakeFiles/app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/abc/桌面/code/chat_tool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable /home/abc/桌面/code/chat_tool/app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/app.dir/build: /home/abc/桌面/code/chat_tool/app
.PHONY : CMakeFiles/app.dir/build

CMakeFiles/app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/app.dir/clean

CMakeFiles/app.dir/depend:
	cd /home/abc/桌面/code/chat_tool/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/abc/桌面/code/chat_tool /home/abc/桌面/code/chat_tool /home/abc/桌面/code/chat_tool/build /home/abc/桌面/code/chat_tool/build /home/abc/桌面/code/chat_tool/build/CMakeFiles/app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/app.dir/depend


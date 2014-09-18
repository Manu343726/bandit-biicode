
# This CMakeLists.txt file helps defining your block building and compiling
#Include the main biicode macros and functions
include(${CMAKE_HOME_DIRECTORY}/biicode.cmake)
# Define block variables
INIT_BIICODE_BLOCK()

# Manipulate here targets files, e.g.: removing or adding files depending on MacOS
# This has to be done BEFORE target definition in ADD_BIICODE_TARGETS
# You can add INCLUDE_DIRECTORIES here too
set(BANDIT_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

# Actually create targets: EXEcutables, STATIC libraries.
ADD_BIICODE_TARGETS()
target_include_directories(${BII_BLOCK_TARGETS} PUBLIC ${BANDIT_INCLUDE_PATH})

target_compile_options(${BII_LIB_TARGET} PUBLIC "-std=c++11")
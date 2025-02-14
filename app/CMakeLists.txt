# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.

project("zdrummachine")

# Check, if arguments are set
if (NOT DEFINED OBOE_HOME)
    message(FATAL_ERROR "OBOE_HOME is not defined")
endif ()

include_directories(src/main/cpp/)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        zdrummachine

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        src/main/cpp/native-lib.cpp
        src/main/cpp/ZDrumMachine.cpp

        # audio engine
        src/main/cpp/audio/AAssetDataSource.cpp
        src/main/cpp/audio/Player.cpp

        # utility functions
        src/main/cpp/utils/logging.h
        src/main/cpp/utils/UtilityFunctions.cpp
        )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

set(TARGET_LIBS ${log-lib} android oboe)

# Set extractors (TODO: add FFMPEG extractor)
target_sources(zdrummachine PRIVATE src/main/cpp/audio/NDKExtractor.cpp)
set(TARGET_LIBS ${TARGET_LIBS} mediandk)

# Build the Oboe library
set(OBOE_DIR ${OBOE_HOME})
add_subdirectory(${OBOE_DIR} ./oboe)

# Make the Oboe public headers available to our app
include_directories(${OBOE_DIR}/include)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        zdrummachine

        # Links the target library to the log library
        # included in the NDK.
        ${TARGET_LIBS})
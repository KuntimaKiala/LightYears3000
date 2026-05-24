cmake_minimum_required( VERSION 3.24 )

project(LightYears 
        VERSION 1.0.0 
        LANGUAGES C CXX) 


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 
set(CMAKE_CXX_EXTENSIONS OFF) # respects iso



# Load FetchContent Module
include(FetchContent)

# setting a variable name for sfml
set(SFML_LIB_NAME SFML)

# to force generating dll files (shared) 
set(BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE)


# Where, how and what to download
FetchContent_Declare(
   ${SFML_LIB_NAME}     
   GIT_REPOSITORY  https://github.com/SFML/SFML 
   GIT_TAG 3.0.2
   GIT_SHALLOW FALSE
)

# Download it and integrate to the project build
FetchContent_MakeAvailable( ${SFML_LIB_NAME} )

# PS: Downloading does not link it 

# creates a variable, the linking happens also there
set(LIGHT_YEARS_GAME_TARGET_NAME LightYearsGame)

# Look and enter the folder LightYears relative to the current folder containing this file, read its CMakeLists and include whatever is there
add_subdirectory(LightYears)


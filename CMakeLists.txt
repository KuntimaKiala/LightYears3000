cmake_minimum_required(VERSION 3.5.0)

project(LightYears 
        VERSION 1.0.0 
        LANGUAGES C CXX) 


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 
set(CMAKE_CXX_EXTENSIONS OFF) # respects iso

# creates a variable
set(LIGHT_YEARS_GAME_TARGET_NAME LightYearsGame)

# Look and enter the folder LightYears relative to the current folder containing this file, read its CMakeLists and include whatever is there
add_subdirectory(LightYears)

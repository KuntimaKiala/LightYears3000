
# add_subdirectory(LightYears) in the CMakeList under LightYears3000 is responsible to this CMakeLists being seen.

add_executable(${LIGHT_YEARS_GAME_TARGET_NAME}
               ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)
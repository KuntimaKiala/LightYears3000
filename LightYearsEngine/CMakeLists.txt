
# add_subdirectory(LightYearsEngine) in the CMakeList under LightYears3000 is responsible to this CMakeLists being seen.

add_library(${LIGHT_YEARS_ENGINE_TARGET_NAME} STATIC
            ${CMAKE_CURRENT_SOURCE_DIR}/src/EntryPoint.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Application.cpp
)

target_include_directories(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


# Linking the Libraries to our project
target_link_libraries( ${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC sfml-graphics )
target_link_libraries( ${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC sfml-window   )
target_link_libraries( ${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC sfml-system   )
target_link_libraries( ${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC sfml-audio    )

function(CopyLibToTarget LIB_NAME TARGET_NAME )

add_custom_command(
    TARGET ${TARGET_NAME} 
    POST_BUILD 
    COMMAND ${CMAKE_COMMAND} 
    ARGS -E copy_if_different 
    $<TARGET_FILE:${LIB_NAME}> 
    $<TARGET_FILE_DIR:${TARGET_NAME}> 
)

endfunction()

CopyLibToTarget( sfml-graphics ${LIGHT_YEARS_ENGINE_TARGET_NAME})
CopyLibToTarget( sfml-window ${LIGHT_YEARS_ENGINE_TARGET_NAME})
CopyLibToTarget( sfml-system ${LIGHT_YEARS_ENGINE_TARGET_NAME})
CopyLibToTarget( sfml-audio ${LIGHT_YEARS_ENGINE_TARGET_NAME})

# add custom command exemple
#add_custom_command
#(
#    TARGET ${LIGHT_YEARS_GAME_TARGET_NAME} POST_BUILD  # Adds a post-build event to ${LIGHT_YEARS_GAME_TARGET_NAME} == LightYearsGame
#    COMMAND 
#    ${CMAKE_COMMAND}
#    ARGS -E copy_if_different # copy if there is difference
#    $<TARGET_FILE:sfml-graphics> #the generator build files for (sfml-graphics/sfml-window/sfml-system/sfml-audio/...etc)
#    $<TARGET_FILE_DIR:${LIGHT_YEARS_GAME_TARGET_NAME}> # to where the executable is [somehow  $<TARGET_FILE_DIR:${LIGHT_YEARS_GAME_TARGET_NAME}> become a path]
#)
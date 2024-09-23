# Define minimal required version of CMake.
cmake_minimum_required(VERSION "3.25")

# Project definition
project(
	zwave_firmware_with_extras
	VERSION 1.0
	LANGUAGES C CXX ASM
)

# Include the definition of the slc_zwave_firmware_with_extras target,
# which contains the content of the SLC project
include(zwave_firmware_with_extras.cmake)

add_executable(zwave_firmware_with_extras
    # Add additional sources here
)

target_include_directories(zwave_firmware_with_extras PUBLIC
    # Add additional include paths here
)

target_compile_definitions(zwave_firmware_with_extras PUBLIC
    # Add additional macros here
)

target_compile_options(zwave_firmware_with_extras PUBLIC
    # Set additional compiler flags here
)

target_link_options(zwave_firmware_with_extras PUBLIC
    # Set additional linker flags here
)

# Link with the content defined in the SLC project
target_link_libraries(zwave_firmware_with_extras PRIVATE
    slc_zwave_firmware_with_extras
)

# Include managed project content if available
include(zwave_firmware_with_extras_project.cmake OPTIONAL RESULT_VARIABLE managed_project)
if(managed_project)
    message(STATUS "Using managed project content from ${managed_project}")
endif()

# Force the gcc linker command
set_target_properties(zwave_firmware_with_extras PROPERTIES LINKER_LANGUAGE C)

# Create .bin, .hex and .s37 artifacts after building the project
add_custom_command(TARGET zwave_firmware_with_extras
    POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O srec "$<TARGET_FILE:zwave_firmware_with_extras>" "$<TARGET_FILE_DIR:zwave_firmware_with_extras>/$<TARGET_FILE_BASE_NAME:zwave_firmware_with_extras>.s37"
    COMMAND ${CMAKE_OBJCOPY} -O ihex "$<TARGET_FILE:zwave_firmware_with_extras>" "$<TARGET_FILE_DIR:zwave_firmware_with_extras>/$<TARGET_FILE_BASE_NAME:zwave_firmware_with_extras>.hex"
    COMMAND ${CMAKE_OBJCOPY} -O binary "$<TARGET_FILE:zwave_firmware_with_extras>" "$<TARGET_FILE_DIR:zwave_firmware_with_extras>/$<TARGET_FILE_BASE_NAME:zwave_firmware_with_extras>.bin" 
)

# Run post-build pipeline to perform additional post-processing
if(post_build_command)
add_custom_command(TARGET zwave_firmware_with_extras
    POST_BUILD
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/..
    COMMAND ${post_build_command}
)
endif()
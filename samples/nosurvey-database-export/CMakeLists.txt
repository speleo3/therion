get_filename_component(SAMPLE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
therion_copy_files(thconfig)
add_custom_target(_samples-${SAMPLE_NAME}
                  COMMAND ${CMAKE_CROSSCOMPILING_EMULATOR} $<TARGET_FILE:therion> --reproducible-output thconfig
                  # COMMAND ${CMAKE_COMMAND} -E compare_files --ignore-eol database.csv ${CMAKE_CURRENT_SOURCE_DIR}/database.csv.ref 
                  COMMAND diff -ub database.csv ${CMAKE_CURRENT_SOURCE_DIR}/database.csv.ref 
                  DEPENDS thconfig
                  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/database.csv.ref
                  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
add_dependencies(_samples-${SAMPLE_NAME} therion)
add_dependencies(samples-build _samples-${SAMPLE_NAME})

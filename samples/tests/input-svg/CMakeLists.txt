get_filename_component(SAMPLE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

therion_add_sample_with_ref(${SAMPLE_NAME} thconfig
    DEPENDS_SRC drawing.svg svg2th2-mock.sh therion.ini
    OUTPUT out.txt
)

RESOURCES_LIBRARY()

IF(USE_SYSTEM_GROOVY_COMPILER)
    MESSAGE(WARNING System groovy $USE_SYSTEM_GROOVY_COMPILER will be used)
ELSEIF(GROOVY_VERSION STREQUAL "3.0.5")
    DECLARE_EXTERNAL_RESOURCE(GROOVY_COMPILER sbr:1710622475)
ELSE()
    MESSAGE(FATAL_ERROR Unexpected groovy version ${GROOVY_VERSION})
ENDIF()
END()

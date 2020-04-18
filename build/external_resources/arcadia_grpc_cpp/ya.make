RESOURCES_LIBRARY()



# Clone this task to rebuild grpc_cpp from trunk:
#
# https://sandbox.yandex-team.ru/task/606999549/view

IF (NOT HOST_OS_DARWIN AND NOT HOST_OS_LINUX AND NOT HOST_OS_WINDOWS)
    MESSAGE(FATAL_ERROR Unsupported host platform for prebuilt arcadia grpc_cpp)
ENDIF()

DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
    ARCADIA_GRPC_CPP
    sbr:1345418132 FOR DARWIN
    sbr:1345418373 FOR LINUX
    sbr:1345418255 FOR WIN32
)

END()

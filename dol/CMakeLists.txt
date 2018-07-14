#set(IDASDK "/Applications/IDA Pro 7.0/idasdk70")

include_directories("${IDASDK}/include")

add_library(dol SHARED dol.cpp)

set_target_properties(dol PROPERTIES PREFIX "")

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set_target_properties(dol PROPERTIES OUTPUT_NAME "dol64")
    target_compile_definitions(dol PRIVATE __EA64__=1 __X64__=1)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
endif()

if(CMAKE_HOST_WIN32)
    target_compile_definitions(dol PRIVATE __NT__=1)
    set(IDA_LIB_DIR "win_vc")
endif()

if(CMAKE_HOST_APPLE)
    target_compile_definitions(dol PRIVATE __MAC__=1)
    set(IDA_LIB_DIR "mac_gcc")
elseif(CMAKE_HOST_UNIX)
    target_compile_definitions(dol PRIVATE __LINUX__=1)
    set(IDA_LIB_DIR "linux_gcc")
endif()


if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    find_library(IDA_LIB NAMES ida64 HINTS "${IDASDK}/lib/x64_${IDA_LIB_DIR}_64")
else()
    find_library(IDA_LIB NAMES ida HINTS "${IDASDK}/lib/x86_${IDA_LIB_DIR}_32")
endif()


target_link_libraries(dol ${IDA_LIB})

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../deos_protocol/include")
    set(DEOS_PROTOCOL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../deos_protocol")
elseif(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../deos-protocol/include")
    set(DEOS_PROTOCOL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../deos-protocol")
else()
    message(FATAL_ERROR "deos_protocol directory not found next to deos_core")
endif()

add_library(deos_core STATIC
    src/deos_core.c
    src/deos_send.c
    src/deos_dispatch.c
    src/deos_network.c
    src/deos_router.c
    src/deos_fault.c
    src/deos_subscription.c
    ${DEOS_PROTOCOL_DIR}/src/deos_codec.c
    ${DEOS_PROTOCOL_DIR}/src/deos_frame.c
    ${DEOS_PROTOCOL_DIR}/src/deos_registry.c
)

target_include_directories(deos_core PUBLIC include "${DEOS_PROTOCOL_DIR}/include")
target_link_libraries(deos_core PRIVATE zephyr_interface)

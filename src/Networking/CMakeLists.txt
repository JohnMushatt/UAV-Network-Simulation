add_subdirectory(Handlers)
add_subdirectory(Server)
link_libraries(Netoworking_Core Handlers_Core Server_Core)
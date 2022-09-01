add_subdirectory(Vendors)
add_subdirectory(Runtime)

if(ENABLE_TAO_APP)
    add_subdirectory(App)
endif()

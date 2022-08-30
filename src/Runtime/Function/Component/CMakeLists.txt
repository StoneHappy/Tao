set(TARGET_NAME Tao_Function_Component)

file(GLOB CPP_HEAD_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
file(GLOB CPP_SOUCE_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${CPP_HEAD_FILES} ${CPP_SOUCE_FILES})

add_library(${TARGET_NAME} SHARED ${CPP_HEAD_FILES} ${CPP_SOUCE_FILES})

set_target_properties(${TARGET_NAME} PROPERTIES CXX_STANDARD 17 OUTPUT_NAME Component)
set_target_properties(${TARGET_NAME} PROPERTIES FOLDER ${PROJECT_NAME})

# being a cross-platform target, we enforce standards conformance on MSVC
target_compile_options(${TARGET_NAME} PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive->")
target_compile_options(${TARGET_NAME} PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/WX->")

# Link dependencies    
target_link_libraries(${TARGET_NAME} PUBLIC
            cpp-utilities::dll
            RTTR::Core
          )


target_include_directories(
  ${TARGET_NAME} 
  PUBLIC 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
)

target_compile_definitions(${TARGET_NAME} PRIVATE "DLL_EXPORT")

add_library(Tao::Function::Component ALIAS ${TARGET_NAME})
cmake_minimum_required(VERSION 2.6)
project(ENGINE)

#set(CMAKE_EXECUTABLE_SUFFIX ".html")
#SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_SDL=2")

include_directories(
	src
)

if(MSVC)
	include_directories(
		contrib/msvc-windows-x86_64/include
	)
	link_directories(
		${PROJECT_SOURCE_DIR}/contrib/msvc-windows-x86_64/lib
	)
endif()

add_definitions(-DSDL_MAIN_HANDLED)

add_library(rend
  src/rend/Exception.cpp
  src/rend/Context.cpp
  src/rend/Texture.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/Buffer.cpp
  src/rend/Mesh.cpp
  src/rend/Util.cpp
)
if(MSVC OR MINGW)
  target_link_libraries(rend glew32 opengl32)
else()
  target_link_libraries(rend GLEW GL)
endif()

add_library(myengine
	src/Engine/Application.cpp
	src/Engine/Application.h
	src/Engine/Screen.h
	src/Engine/Screen.cpp
	src/Engine/ResourceManager.h
	src/Engine/ResourceManager.cpp
	src/Engine/Resource.h
	src/Engine/Resource.cpp
	src/Engine/Texture.h
	src/Engine/Texture.cpp
	src/Engine/Entity.h
	src/Engine/Entity.cpp
	src/Engine/Component.h
	src/Engine/Component.cpp
	src/Engine/Shader.h
	src/Engine/Shader.cpp
	src/Engine/TriangleRenderer.h
	src/Engine/TriangleRenderer.cpp
	src/Engine/Renderer.h
	src/Engine/Renderer.cpp
	src/Engine/Transform.h
	src/Engine/Transform.cpp
	src/Engine/InputManager.h
	src/Engine/InputManager.cpp
	src/Engine/Camera.h
	src/Engine/Camera.cpp
	src/Engine/MegaHeader.h
)


target_link_libraries(myengine rend SDL2)

add_executable(demo
	src/TechDemo/main.cpp
	src/TechDemo/Player.h
	src/TechDemo/Player.cpp
)

target_link_libraries(demo myengine)
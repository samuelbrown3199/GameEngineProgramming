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

add_library(myengine
	src/Engine/Application.cpp
	src/Engine/Application.h
	src/Engine/Screen.h
	src/Engine/Screen.cpp
	src/Engine/ResourceManager.h
	src/Engine/ResourceManager.cpp
	src/Engine/Resource.h
	src/Engine/Resource.cpp
	src/Engine/Model.h
	src/Engine/Model.cpp
	src/Engine/Texture.h
	src/Engine/Texture.cpp
	src/Engine/AudioClip.h
	src/Engine/AudioClip.cpp
	src/Engine/Font.h
	src/Engine/Font.cpp
	src/Engine/Entity.h
	src/Engine/Entity.cpp
	src/Engine/Component.h
	src/Engine/Component.cpp
	src/Engine/UiComponent.h
	src/Engine/UiComponent.cpp
	src/Engine/UiSystem.h
	src/Engine/UiSystem.cpp
	src/Engine/Shader.h
	src/Engine/Shader.cpp
	src/Engine/TriangleRenderer.h
	src/Engine/TriangleRenderer.cpp
	src/Engine/MeshRenderer.h
	src/Engine/MeshRenderer.cpp
	src/Engine/Transform.h
	src/Engine/Transform.cpp
	src/Engine/InputManager.h
	src/Engine/InputManager.cpp
	src/Engine/Camera.h
	src/Engine/Camera.cpp
	src/Engine/Physics.h
	src/Engine/Physics.cpp
	src/Engine/PhysicsBody.h
	src/Engine/PhysicsBody.cpp
	src/Engine/MegaHeader.h
)

target_link_libraries(myengine SDL2 SDL2_ttf glew32 opengl32 openal32)

add_executable(demo
	src/TechDemo/main.cpp
	src/TechDemo/Player.h
	src/TechDemo/Player.cpp
)

target_link_libraries(demo myengine)
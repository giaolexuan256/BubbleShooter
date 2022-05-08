cmake_minimum_required(VERSION 3.21)
project(BubbleShooter)

set(CMAKE_CXX_STANDARD 14)

include_directories(C:/Dev/Cpp/SDL2-devel-2.0.20-VC/SDL2-2.0.20/include)
link_directories(C:/Dev/Cpp/SDL2-devel-2.0.20-VC/SDL2-2.0.20/lib/x64)

include_directories(C:/Dev/Cpp/SDL2_image-2.0.5/include)
link_directories(C:/Dev/Cpp/SDL2_image-2.0.5/lib/x64)

include_directories(C:/Dev/Cpp/SDL2_ttf-devel-2.0.12-VC/SDL2_ttf-2.0.12/include)
link_directories(C:/Dev/Cpp/SDL2_ttf-devel-2.0.12-VC/SDL2_ttf-2.0.12/lib/x64)

include_directories(C:/Dev/Cpp/SDL2_mixer-devel-2.0.4-VC/SDL2_mixer-2.0.4/include)
link_directories(C:/Dev/Cpp/SDL2_mixer-devel-2.0.4-VC/SDL2_mixer-2.0.4/lib/x64)

add_executable(${PROJECT_NAME} src/sources/main.cpp src/sources/TextureAlpha.cpp src/headers/TextureAlpha.h src/sources/Bubble.cpp src/headers/Bubble.h src/sources/Game.cpp src/headers/Game.h src/sources/Arrow.cpp src/headers/Arrow.h src/sources/Point.cpp src/headers/Point.h src/sources/Utility.cpp src/headers/Utility.h src/sources/Cannon.cpp src/headers/Cannon.h src/headers/ScreenSizeCarrier.h src/headers/BubbleColor.h src/headers/RandomBubbleColorGenerator.cpp src/headers/RandomBubbleColorGenerator.h src/headers/BubbleColorConverter.cpp src/headers/BubbleColorConverter.h src/headers/BubbleGridManager.cpp src/headers/BubbleGridManager.h src/headers/RandomNumberGenerator.cpp src/headers/RandomNumberGenerator.h)

target_link_libraries(${PROJECT_NAME} -lSDL2main -lSDL2)
target_link_libraries(${PROJECT_NAME} -lSDL2_image)
target_link_libraries(${PROJECT_NAME} -lSDL2_ttf)
target_link_libraries(${PROJECT_NAME} -lSDL2_mixer)
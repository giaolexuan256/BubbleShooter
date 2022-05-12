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

add_executable(${PROJECT_NAME} src/main.cpp src/TextureAlpha.cpp src/TextureAlpha.h src/CannonBubble.cpp src/CannonBubble.h src/Game.cpp src/Game.h src/Arrow.cpp src/Arrow.h src/Point.cpp src/Point.h src/Utility.cpp src/Utility.h src/Cannon.cpp src/Cannon.h src/ScreenSizeCarrier.h src/BubbleColor.h src/RandomBubbleColorGenerator.cpp src/RandomBubbleColorGenerator.h src/BubbleColorConverter.cpp src/BubbleColorConverter.h src/BubbleGridManager.cpp src/BubbleGridManager.h src/RandomNumberGenerator.cpp src/RandomNumberGenerator.h)

target_link_libraries(${PROJECT_NAME} -lSDL2main -lSDL2)
target_link_libraries(${PROJECT_NAME} -lSDL2_image)
target_link_libraries(${PROJECT_NAME} -lSDL2_ttf)
target_link_libraries(${PROJECT_NAME} -lSDL2_mixer)
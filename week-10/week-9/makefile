
# Target: The name of your executable file
TARGET = runMe

# C++ compiler
CXX = g++

# C++ compiler flags (optimize for speed)
#CXXFLAGS = -O2 -Wall -g -O0
CXXFLAGS = -O2 -g -O0

# Source files (cpp)
SRCS = acceleration.cpp position.cpp angle.cpp velocity.cpp test.cpp simulator.cpp uiDraw.cpp uiInteract.cpp satelliteGPS.cpp physics.cpp entity.cpp

# Object files (created from source files)
OBJS = $(SRCS:.cpp=.o)

# Header files (include for compilation)
HDRS = testPosition.h acceleration.h position.h testVelocity.h testAcceleration.h angle.h testAngle.h velocity.h unitTest.h test.h uiDraw.h uiInteract.h entity.h satelliteGPS.h satallite.h testPhysics.h testEntity.h

# Linker flags (link with OpenGL and GLFW libraries)
LDFLAGS = -lglut -lGL -lGLU -lGLEW

# Rule to compile a source file (.cpp) into an object file (.o)
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Rule to link object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Rule to clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)


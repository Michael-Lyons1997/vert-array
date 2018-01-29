#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <Vector.h>
#include <Matrix.h>

using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();
	void move();
	Vector topLeft;
	Vector topRight;
	Vector bottomLeft;
	Vector bottomRight;
	Matrix mathMatrix;
	Clock clock;
	Time elapsed;

	float rotationAngle = 0.0f;
};
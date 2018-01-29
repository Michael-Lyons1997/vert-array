#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	topLeft.setX(-1.0f);
	topLeft.setY(1.0f);
	topLeft.setZ(-5.0f);

	topRight.setX(1.0f);
	topRight.setY(1.0f);
	topRight.setZ(-5.0f);

	bottomLeft.setX(-1.0f);
	bottomLeft.setY(-1.0f);
	bottomLeft.setZ(-5.0f);

	bottomRight.setX(1.0f);
	bottomRight.setY(-1.0f);
	bottomRight.setZ(-5.0f);

	mathMatrix.setA11(1.0);
	mathMatrix.setA12(1.0);
	mathMatrix.setA13(1.0);
	mathMatrix.setA21(1.0);
	mathMatrix.setA22(1.0);
	mathMatrix.setA23(1.0);
	mathMatrix.setA31(1.0);
	mathMatrix.setA32(1.0);
	mathMatrix.setA33(1.0);
}

Game::~Game()
{

}

float vertices[18];
float colors[] = { 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f };
unsigned int vertex_index[] = { 0, 1, 2, 3, 4, 5 };
void Game::run()
{
	vertices[0] = topRight.getX();
	vertices[1] = topRight.getY();
	vertices[2] = topRight.getZ();
	vertices[3] = topLeft.getX();
	vertices[4] = topLeft.getY();
	vertices[5] = topLeft.getZ();
	vertices[6] = bottomLeft.getX();
	vertices[7] = bottomLeft.getY();
	vertices[8] = bottomLeft.getZ();
	vertices[9] = topRight.getX();
	vertices[10] = topRight.getY();
	vertices[11] = topRight.getZ();
	vertices[12] = bottomLeft.getX();
	vertices[13] = bottomLeft.getY();
	vertices[14] = bottomLeft.getZ();
	vertices[15] = bottomRight.getX();
	vertices[16] = bottomRight.getY();
	vertices[17] = bottomRight.getZ();

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		move();
		render();
	}

}

void Game::initialize()
{
	isRunning = true;

	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		topLeft = mathMatrix.Translate(2,2) * topLeft;
		bottomLeft = mathMatrix.Translate(2,2) * bottomLeft;
		topRight = mathMatrix.Translate(2,2) * topRight;
		bottomRight = mathMatrix.Translate(2,2) * bottomRight;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		topLeft = mathMatrix.Scale3D(1) * topLeft;
		bottomLeft = mathMatrix.Scale3D(1) * bottomLeft;
		topRight = mathMatrix.Scale3D(1) * topRight;
		bottomRight = mathMatrix.Scale3D(1) * bottomRight;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		topLeft = mathMatrix.Rotation(5) * topLeft;
		bottomLeft = mathMatrix.Rotation(5) * bottomLeft;
		topRight = mathMatrix.Rotation(5) * topRight;
		bottomRight = mathMatrix.Rotation(5) * bottomRight;
	}
	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glVertexPointer(3, GL_FLOAT, 0, &vertices);
	glColorPointer(3, GL_FLOAT, 0, &colors);
	//glDrawArrays(GL_TRIANGLES, 0, 3);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, &vertex_index);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

void Game::move()
{
	vertices[0] = topRight.getX();
	vertices[1] = topRight.getY();
	vertices[2] = topRight.getZ();
	vertices[3] = topLeft.getX();
	vertices[4] = topLeft.getY();
	vertices[5] = topLeft.getZ();
	vertices[6] = bottomLeft.getX();
	vertices[7] = bottomLeft.getY();
	vertices[8] = bottomLeft.getZ();
	vertices[9] = topRight.getX();
	vertices[10] = topRight.getY();
	vertices[11] = topRight.getZ();
	vertices[12] = bottomLeft.getX();
	vertices[13] = bottomLeft.getY();
	vertices[14] = bottomLeft.getZ();
	vertices[15] = bottomRight.getX();
	vertices[16] = bottomRight.getY();
	vertices[17] = bottomRight.getZ();
}


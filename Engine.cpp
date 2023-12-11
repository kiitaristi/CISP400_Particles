#include "Engine.h"

// Public functions
Engine::Engine()
{
	m_Window.create(VideoMode::getDesktopMode(), "Particles", Style::Default);
}

void Engine::run()
{
	Clock clock;

	cout << "Starting Particle unit tests..." << endl;
	Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
	p.unitTests();
	cout << "Unit tests complete.  Starting engine..." << endl;

	while (m_Window.isOpen())
	{
		input();
		update(clock.restart().asSeconds());
		draw();
	}
}

// Private helper functions
void Engine::input()
{
	Event event;

	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			m_Window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			m_Window.close();
		}

		if (event.type == Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == Mouse::Left)
			{
				for (int i = 0; i < 5; i++)
				{
					int numPoints = (rand() % (50 - 25 + 1)) + 25;
					
					Vector2i mouseCoords = { event.mouseButton.x, event.mouseButton.y };

					m_particles.push_back(Particle(m_Window, numPoints, mouseCoords));
				}
			}
		}
	}
}

void Engine::update(float dtAsSeconds)
{
	vector<Particle>::iterator it;

	for (it = m_particles.begin(); it != m_particles.end();)
	{
		if (it->getTTL() > 0.0)
		{
			it->update(dtAsSeconds);
			it++;
		}
		else
		{
			it = m_particles.erase(it);
		}
	}

}

void Engine::draw()
{
	m_Window.clear();

	for (int i = 0; i < m_particles.size(); i++)
	{
		m_Window.draw(m_particles.at(i));
	}

	m_Window.display();
}
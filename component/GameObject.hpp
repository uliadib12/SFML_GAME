#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject();
	~GameObject();
	void update();
	sf::Sprite sprite;
};
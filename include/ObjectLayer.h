#ifndef OBJECTLAYER_H_INCLUDED
#define OBJECTLAYER_H_INCLUDED

#include "Layer.h"
#include "GameObject.h"
#include <vector>

class ObjectLayer : public Layer {
	private:
		std::vector<GameObject *> game_objects;

	public:
		virtual ~ObjectLayer();
		virtual void update();
		virtual void render();
		std::vector<GameObject *> * getGameObjects();

};


#endif

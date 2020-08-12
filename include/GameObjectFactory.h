#ifndef GAMEOBJECTFACTORY_H_INCLUDED
#define GAMEOBJECTFACTORY_H_INCLUDED

#include <string>
#include <map>
#include "GameObject.h"

class BaseCreator {
	private:

	public:
		virtual GameObject * createGameObject () const = 0;
		virtual ~BaseCreator() {}

};


class GameObjectFactory {
	private:
		std::map<std::string, BaseCreator *> creators;

		void clean();
		GameObjectFactory();

		static GameObjectFactory * instance;

	public:
		void operator = (const GameObjectFactory & other) = delete;
		GameObjectFactory(const GameObjectFactory & other) = delete;
		static GameObjectFactory * getInstance();

		~GameObjectFactory();
		bool registerType(const std::string type_id,  BaseCreator * creator);
		GameObject * create(const std::string type_id);

};



#endif

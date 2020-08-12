#include "GameObjectFactory.h"
#include <iostream>

GameObjectFactory::~GameObjectFactory() {
	clean();
}

void GameObjectFactory::clean() {

	for ( auto it = creators.begin(); it != creators.end(); ++it ) {
		delete (*it).second;
	}

	creators.clear();
}

bool GameObjectFactory::registerType(const std::string type_id,
												 BaseCreator * creator){
	auto it = creators.find(type_id);

	bool success = true;

	if ( it != creators.end() ) {
		delete creator;
		success = false;
	} else {
		creators[type_id] = creator;
	}

	return success;



}

GameObject * GameObjectFactory::create(const std::string type_id){
	GameObject * created_object = nullptr;

	auto it = creators.find(type_id);

	if ( it == creators.end() ) {
		std::cerr << "ERROR : Could not find type: " << type_id << std::endl;

	} else {
		BaseCreator * new_creator = (*it).second;

		created_object = new_creator->createGameObject();
	}

	return created_object;

}

GameObjectFactory * GameObjectFactory::getInstance() {
	if ( instance == nullptr ) {
		instance = new GameObjectFactory();
	}

	return instance;
}

GameObjectFactory * GameObjectFactory::instance = nullptr;

#ifndef INPUTHANDLER_H_INCLUDED
#define INPUTHANDLER_H_INCLUDED

class InputHandler {
	private:
		InputHandler();
		~InputHandler();

		static InputHandler * instance;

	public:
		static InputHandler * getInstance();
		void update();
		void clean();

};



#endif

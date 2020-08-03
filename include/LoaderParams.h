#ifndef LOADERPARAMS_H_INCLUDED
#define LOADERPARAMS_H_INCLUDED

#include <string>

class LoaderParams {
	private:

		int x_pos;
		int y_pos;


		int width;
		int height;

		std::string texture_id;

	public:
		LoaderParams(const int X, const int Y, const int WIDTH, const int HEIGHT,
						 const std::string id);

		int getX() const;
		int getY() const;
		int getWidth() const;
		int getHeight() const;
		std::string getTextureId() const;

};


#endif

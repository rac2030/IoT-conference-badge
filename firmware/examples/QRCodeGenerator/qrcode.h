#include <GxEPD.h>
#include <GxGDEW0213Z16/GxGDEW0213Z16.h>  // 2.13" b/w/r


class QRcode
{
	private:
		GxEPD_Class *display;
		void render(int x, int y, int color);

	public:
		QRcode(GxEPD_Class *display);
		void debug();
		void generate(String message);
		void writeToDisplayBuffer(int x, int y);
		void create(String message);

};

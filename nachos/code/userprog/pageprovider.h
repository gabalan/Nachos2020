#ifdef CHANGED
#ifndef PAGEPROVIDER_H
#define PAGEPROVIDER_H
#include <strings.h>	
#include "bitmap.h"

class PageProvider:dontcopythis  {
	public:
		PageProvider(int n);
		~PageProvider();
		int GetEmptyPage();
		void ReleasePage(int n);
		int NumAvailPage();
	private:
		BitMap* bitmap;
};
#endif // PAGEPROVIDER_H
#endif// CHANGED
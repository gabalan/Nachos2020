#ifdef CHANGED
#include "bitmap.h"
#include "system.h"
#include <strings.h>	
#include "pageprovider.h"

PageProvider::PageProvider(int n){
    bitmap=new BitMap(n);
}
PageProvider::~PageProvider(){
    delete bitmap;
}
int PageProvider::GetEmptyPage(){
    int pageprovider=bitmap->Find();
    ASSERT(pageprovider!=-1);
    memset(&machine->mainMemory[pageprovider*PageSize],0, PageSize);
    return pageprovider;

}

void PageProvider::ReleasePage(int n){bitmap->Clear(n);}

int PageProvider::NumAvailPage(){return bitmap->NumClear();}

#endif //CHANGED
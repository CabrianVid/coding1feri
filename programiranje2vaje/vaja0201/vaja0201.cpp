#include <iostream>
#include "Artwork.h"

using namespace std;

const Artwork* getExpensier(Artwork* prvi, Artwork* drugi){
  if(prvi->getPrice() > drugi->getPrice()){
      return prvi;
  }
    else if   (drugi->getPrice() > prvi->getPrice()){
        return drugi;
    }
    //else if (drugi->getPrice()==prvi->getPrice()){
    //    return
    //}
}



int main() {
    Artwork a, b;
    a.setTitle("bambi");
    a.setDescription("prelep film z zelo zalostnim koncem");
    a.setYear(2000);
    a.setPrice(12.5);

    b.setTitle("Moj prijatelj Piki Jakob");
    b.setDescription("Zgodba o prijateljstvu");
    b.setYear(1999);
    b.setPrice(8.99);

    Artwork *c = new Artwork;
    c->setPrice(4.15);
    c->setYear(2019);
    c->setTitle("Morska deklica");
    c->setDescription("fascinantna zgodba, ki vkljucuje vse: izgnanstvo, ljubezensko zgodbo, preobrat in se dosti vec");


    Artwork *d = new Artwork;
    d->setPrice(19.12);
    d->setYear(2022);
    d->setTitle("Kralj z slabim zadahom");
    d->setDescription("nova uspesnica o kralju s pomankljivo higieno");

    Artwork *e = new Artwork;
    e->setPrice(0.99);
    e->setYear(2008);
    e->setTitle("Rdeca kapica");
    e->setDescription("Zgodba polna obratov in prevar");

    cout << a.getTitle() << endl;
    cout << a.getYear() << endl;
    cout << a.getPrice() << endl;
    cout << a.getDescription() << endl;

    cout << "\n\n\n";

    b.print();

    cout << "\n\n\n";

    cout << c->toString() << endl;

    cout << "\n\n\n";

    d->print();

    cout << "\n\n\n";

    cout << e->getTitle() << endl;
    cout << e->getYear() << endl;
    cout << e->getPrice() << endl;
    cout << e->getDescription() << endl;

    cout << "\n\n\n";

    if(e->isExpensier(d)==0){
        cout<< "drazji je:\n";
        e->print();
    }
    if(e->isExpensier(d)==1){
        cout<< "drazji je:\n";
        d->print();
    }


    cout << "\n\n\n";

    getExpensier(e,c)->print();

    delete c;
    delete d;
    delete e;

    return 0;
}

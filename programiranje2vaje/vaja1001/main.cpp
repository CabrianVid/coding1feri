#include <iostream>
#include "Gallery.h"
#include"Artwork.h"
#include "Artist.h"
#include "Painting.h"




bool ascendingYear(Artwork *i, Artwork *j) {
    if (i->getYear() < j->getYear()) {
        return true;
    }
    return false;
}

bool descandingYear(Artwork *i, Artwork *j) {
    if (i->getYear() > j->getYear()) {
        return true;
    }
    return false;
}

bool ascendingPrice(Artwork *i, Artwork *j) {
    if (i->getPrice() < j->getPrice()) {
        return true;
    }
    return false;
}




bool isPriceMoreThanTen(Artwork *a) {
    if (10 < a->getPrice() ) {
        return true;
    }
    return false;
}




bool isRenaissanceArt(Artwork *a) {
    if (1400 < a->getYear() && a->getYear() < 1600) {
        return true;
    }
    return false;
}









int main() {
    Date date1(5, 3, 1992), date2(8, 8, 1924), date3(9, 10, 2000), date4(19, 12, 1899), date5(28, 2, 1945);
    Artist artist1a("Bine", "Zivel je pet let v parizu", date1);
    Artist artist2a("Bine", "Zivel je pet let v parizu", date2);
    Artist artist3a("Bine", "Zivel je pet let v parizu", date3);
    Artist artist4a("Bine", "Zivel je pet let v parizu", date4);
    Artist artist5a("Bine", "Zivel je pet let v parizu", date5);

    Artist *artist1 = &artist1a;
    Artist *artist2 = &artist2a;
    Artist *artist3 = &artist3a;
    Artist *artist4 = &artist4a;
    Artist *artist5 = &artist5a;

    Artwork *c = new Artwork;
    c->setPrice(4.15);
    c->setYear(1415);
    c->setTitle("Morska deklica");
    c->setDescription("fascinantna zgodba, ki vkljucuje vse: izgnanstvo, ljubezensko zgodbo, preobrat in se dosti vec");
    c->setArtist(artist3);

    Artwork *d = new Artwork;
    d->setPrice(19.12);
    d->setYear(2022);
    d->setTitle("Kralj z slabim zadahom");
    d->setDescription("nova uspesnica o kralju s pomankljivo higieno");
    d->setArtist(artist4);

    Artwork *e = new Artwork;
    e->setPrice(0.99);
    e->setYear(2008);
    e->setTitle("Rdeca kapica");
    e->setDescription("Zgodba polna obratov in prevar");
    e->setArtist(artist5);

    Gallery gallery;
    gallery.addArtwork(c);
    gallery.addArtwork(d);
    gallery.addArtwork(e);

    cout<<"\n\n\n\n";




    Painting *painting=new Painting("naslov1", "opis ja",12, 1919, artist4, paintingTechnique::Oil);
    gallery.addArtwork(painting);

    cout<<"\n\n\n\n";
    PrintIfPainting paint;
    gallery.printArtworks(paint);
    cout<<"\n\n\n\n";
    cout<<"\n\n\n\n";
    gallery.sort(ascendingYear);
    cout << gallery.toString() << std::endl;
    cout<<"\n\n\n\n";
    gallery.sort(descandingYear);
    cout << gallery.toString() << std::endl;
    cout<<"\n\n\n\n";
    gallery.sort(ascendingPrice);
    cout << gallery.toString() << std::endl;
    cout<<"\n\n\n\n";

    cout << gallery.find(isRenaissanceArt)->toString();
    cout<<"\n\n\n\n";

    for(int i=0; i<gallery.findAll(isPriceMoreThanTen).size();i++){
        cout<<gallery.findAll(isPriceMoreThanTen)[i]->toString()<<endl;
    }
    delete  artist1,artist2,artist3,artist4,artist5,date1,date2,date3,date4,date5,c,d,e, paint,gallery;
    return 0;
}

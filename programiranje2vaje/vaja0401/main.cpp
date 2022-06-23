#include <iostream>
#include<string>
#include "Artwork.h"
#include"Gallery.h"
#include"Artist.h"
#include"Date.h"

using namespace std;

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

    Artwork a, b;
    a.setTitle("bambi");
    a.setDescription("prelep film z zelo zalostnim koncem");
    a.setYear(2000);
    a.setPrice(12.5);
    a.setArtist(artist1);

    b.setTitle("Moj prijatelj Piki Jakob");
    b.setDescription("Zgodba o prijateljstvu");
    b.setYear(1999);
    b.setPrice(8.99);
    b.setArtist(artist2);

    Artwork *c = new Artwork;
    c->setPrice(4.15);
    c->setYear(2019);
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

    Gallery vid;
    vid.addArtwork(e);
    vid.printArtworks();
    cout << "\n\n\n\n";
    vid.removeArtwork(e);
    vid.addArtwork(d);
    vid.addArtwork(c);
    vid.addArtwork(e);
    vid.getArtworkBetweenYear(1950, 2010);
    vid.removeArtwork(c);
    cout << "\n\n\n\n";
    vid.getArtworkBetweenYear(1950, 2010);


    return 0;
}


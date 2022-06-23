#include <iostream>
#include <memory>
#include "Gallery.h"
#include"Artwork.h"
#include "Artist.h"
#include "Painting.h"
#include"PlayerTrainer.h"
#include"Player.h"
#include"Trainer.h"


bool isOlderThan2000(const std::shared_ptr<Artwork> &a) {
    if (a->getYear() > 2000) return true;
    return false;
}

bool ascendingYear(std::shared_ptr<Artwork> i, std::shared_ptr<Artwork> j) {
    if (i->getYear() < j->getYear()) {
        return true;
    }
    return false;
}

bool descandingYear(std::shared_ptr<Artwork> i, std::shared_ptr<Artwork> j) {
    if (i->getYear() > j->getYear()) {
        return true;
    }
    return false;
}

bool ascendingPrice(std::shared_ptr<Artwork> i, std::shared_ptr<Artwork> j) {
    if (i->getPrice() < j->getPrice()) {
        return true;
    }
    return false;
}


bool isPriceMoreThanTen(std::shared_ptr<Artwork> a) {
    if (10 < a->getPrice()) {
        return true;
    }
    return false;
}


bool isRenaissanceArt(std::shared_ptr<Artwork> a) {
    if (1400 < a->getYear() && a->getYear() < 1600) {
        return true;
    }
    return false;
}


int main() {
    std::shared_ptr<Artist> artist1 = std::make_shared<Artist>("Luka", "magicni decek", Date(12, 4, 2010));
    std::shared_ptr<Artist> artist2 = std::make_shared<Artist>("Ziga", "abstraktni umetnik", Date(2, 7, 2000));
    std::shared_ptr<Artist> artist3 = std::make_shared<Artist>("Marko", "mladi pikaso", Date(21, 12, 2010));
    std::shared_ptr<Artist> artist4 = std::make_shared<Artist>("Eva", "najboljs umetnica 21 stoletja",Date(12, 4, 2010));
    std::shared_ptr<Artist> artist5 = std::make_shared<Artist>("Sonja", "čarovnica s čopicem", Date(12, 4, 2010));


    std::shared_ptr<Artwork> a = std::make_shared<Artwork>(2010, 12, "levji kralj", "zlo zanimivo", artist1);
    std::shared_ptr<Artwork> b = std::make_shared<Artwork>(2010, 12, "levji kralj", "zlo zanimivo", artist2);
    std::shared_ptr<Artwork> c = std::make_shared<Artwork>(2010, 12, "levji kralj", "zlo zanimivo", artist3);
    std::shared_ptr<Artwork> d = std::make_shared<Artwork>(2010, 12, "levji kralj", "zlo zanimivo", artist4);
    std::shared_ptr<Artwork> e = std::make_shared<Artwork>(2010, 12, "levji kralj", "zlo zanimivo", artist5);

    Gallery gallery;
    gallery.addArtwork(c);
    gallery.addArtwork(d);
    gallery.addArtwork(e);

    cout << "\n\n\n\n";


    std::shared_ptr<Painting> painting1 = std::make_shared<Painting>("naslov1", "opis ja", 12, 1919, artist4,
                                                                     paintingTechnique::Oil);
    gallery.addArtwork(painting1);

    cout << "\n\n\n\n";
    PrintIfPainting paint;
    gallery.printArtworks(paint);
    cout << "\n\n\n\n";
    cout << "\n\n\n\n";
    gallery.sort(ascendingYear);
    cout << gallery.toString() << std::endl;
    cout << "\n\n\n\n";
    gallery.sort(descandingYear);
    cout << gallery.toString() << std::endl;
    cout << "\n\n\n\n";
    gallery.sort(ascendingPrice);
    cout << gallery.toString() << std::endl;
    cout << "\n\n\n\n";

    cout << gallery.find(isRenaissanceArt)->toString();
    cout << "\n\n\n\n";

    for (int i = 0; i < gallery.findAll(isPriceMoreThanTen).size(); i++) {
        cout << gallery.findAll(isPriceMoreThanTen)[i]->toString() << endl;
    }

    cout << "\n\n\n\n";
    gallery.filterOut(isOlderThan2000);
    std::cout << gallery.toString();
    cout << "\n\n\n\n";
    gallery.filterOut([](const std::shared_ptr<Artwork> &a) {
        if (a->getPrice() < 100) {
            return true;
        }
        return false;
    });

    cout << "\n\n\n\n";
    cout << "\n\n\n\n";
    cout << "\n\n\n\n";
    gallery.filterOut([artist1](const std::shared_ptr<Artwork> &a) {
        if (a->getArtist()==artist1) {
            return true;
        }
        return false;
    });

    std::cout << gallery.toString();
    cout << "\n\n\n\n";

    PlayerTrainer pT1("Ziga", "Olimpija", 12, 23);
    pT1.print();

    return 0;
}

#include <iostream>
#include"Gallery.h"
#include"Painting.h"
#include"Sculpture.h"

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

    Painting *painting1 = new Painting;
    painting1->setTechnique(paintingTechnique::Oil);
    painting1->setArtist(artist1);
    painting1->setTitle("Ostrzek");
    painting1->setYear(1913);
    painting1->setDescription("Zanimiva zgodba o Ostrzku, ki si zeli postati pravi decek");
    painting1->setPrice(17.55);

    Painting *painting2 = new Painting;
    painting2->setTechnique(paintingTechnique::Graphite);
    painting2->setArtist(artist2);
    painting2->setTitle("Kuahrski prirocnik");
    painting2->setYear(1755);
    painting2->setDescription("Same Italijanske specialitete");
    painting2->setPrice(0.99);

    Sculpture *sculpture1 = new Sculpture;
    sculpture1->setPrice(12.87);
    sculpture1->setDescription("Fascinanten kip");
    sculpture1->setYear(1977);
    sculpture1->setTitle("Metalec diska");
    sculpture1->setArtist(artist4);
    sculpture1->setMaterial(Material::Wood);
    sculpture1->setWeight(77);

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
    cout << "\n\n\n\n";
    vid.addArtwork(painting1);
    vid.printArtworks();
    cout << "\n\n\n\n";
    vid.addArtwork(sculpture1);

    cout << "Print artworks" << endl;
    vid.printArtworks();
    cout << "\n\n\n\n";
    sculpture1->print();

    return 0;
}
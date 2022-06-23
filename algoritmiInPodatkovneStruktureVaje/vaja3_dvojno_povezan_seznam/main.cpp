#include <iostream>

using namespace std;


struct node {
    int key;
    node *next, *prev;
};

void menu() {
    cout << "============================" << endl;
    cout << "=========== MENU ===========" << endl;
    cout << "============================" << endl;
    cout << "SKLAD:" << endl;
    cout << "1 ... ISKANJE PODATKA" << endl;
    cout << "2 ... VNOS PODATKA V GLAVO" << endl;
    cout << "3 ... VNOS PODATKA ZA ELEMENTOM" << endl;
    cout << "4... VNOS PODATKA ZA REPOM" << endl;
    cout << "5...BRISANJE PODATKA " << endl;
    cout << "6... IZPIS SEZNAMA OD GLAVE PROTI REPU" << endl;
    cout << "7 ... IZIS SEZNAMA OD REPA PROTI GLAVI" << endl;
    cout << "8...TESTIRAJ HITROST " << endl;
    cout << "9...EXIT " << endl;
    cout << "============================" << endl;
    cout << "Select: ";
}

void insertInHead(node *&head, node *newNode, node *&tail) {
    if (head == NULL) {//ko je prazno
        newNode->prev = NULL;
        newNode->next = NULL;
        tail = newNode;
        head = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        newNode->prev = NULL;
    }
}

void insertInTail(node *&head, node *newNode, node *&tail){
    newNode->next=NULL;
    if (head == NULL && tail==NULL) {//ko je prazno
        newNode->prev = NULL;
        newNode->next = NULL;
        tail = newNode;
        head = newNode;
    }
    else if(head->next==NULL){
        head->next=newNode;
        newNode->prev=head;
        tail=newNode;
    }
    else{
        node* temp= head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
        tail=newNode;
    }
}
/*
void insertBehindElement(node element, node *newNode, node *&tail) {
    newNode->prev = &element;
    newNode->next = element.next;


    if (newNode->next != NULL) {
        element.next->prev = newNode;

    } else {
        tail = newNode;
    }
    element.next = newNode;
}
*/
void Delete(node *&head, node element, node *&tail) {
    if (element.prev == NULL && element.next == NULL) {//edini element
        head = NULL;
        tail = NULL;
    } else if (element.prev == NULL) {//brisemo head
        head = element.next;
        head->prev = NULL;
    } else if (element.next == NULL) { //breisemo rep
        tail = element.prev;
        tail->next = NULL;
    } else {
        element.prev->next = element.next;
        element.next->prev = element.prev;
    }
    delete &element;
}

void printStartToFinish(node *head) {
    cout<<"Seznam od glave do repa\n";
    while(head!=NULL){
        cout<< head->key<< "\t";
        head=head->next;
    }
}

void printFinishToStart (node * tail){

    cout<<"Seznam od repa do glave\n";
    while (tail != NULL) {
        cout << tail->key << "\t";
        tail = tail->prev;
    }

}

node search(node* head, int x)
{
    node* temp = head;

    while (head->key!=x && head->key!=NULL)
    {
        head = head->next;
    }
    if(head->key==x) {
        return *head;
    }
    else{
        temp->key=0;
        return *temp;
    }
}




node *ustvari() {
    node *p;
    p = new node; // Ustvarimo nov element
    // Rezervira svoj del pomnilnika
    cout << "Vpišite podatke(stevilko)" << endl;
    cin >> p->key;
    p->next = NULL;
    p->prev = NULL;
    return p;
}


int main() {
    node *head = NULL;
    node *tail = NULL;
    node *newNode;


    bool running = true;
    int selection;

    do {
        menu();
        cin >> selection;
        switch (selection) {
            case 1:
                int key1;
                cout<< "kateri kljuc zelis najti:\t";
                cin>> key1;
                if(key1 == (search(head, key1)).key){
                    cout<<"Ta vrednost obstaja\n";
                }
                if(0 == (search(head, key1)).key){
                    cout<<"Ta vrednost se ne obstaja\n";//tu bo treba se nekaj popravit
                }
                break;


            case 2:

                newNode = ustvari();
                insertInHead(head, newNode, tail);
                break;
/*
                    case 3:
                        int key2;
                        cout<<"za kateri element zelis vstaviti nov element(vpisi kljuc):\t";
                        cin>>key2;
                        if((search(head, key2)).key == key2){
                            newNode = ustvari();
                            insertBehindElement(search(head, key1), newNode,tail);
                        }
                        else{
                        cout<<"Ta vrednost se ne obstaja\n";//tu bo treba se nekaj popravit
                        }

                         break;

*/
            case 4:
                newNode = ustvari();
                insertInTail(head, newNode, tail);
                break;

            case 5:
                int elementKey;
                cout<<"kateri element bi rad izbrisal(key):\t";
                cin>> elementKey;
                Delete(head, (search(head, elementKey)), tail);
                break;

            case 6:
                printStartToFinish(head);
                break;

            case 7:
                printFinishToStart(tail);
                break;

            case 8:
                running = false;
                break;

            default:
                cout << "Napacna izbira!" << endl;
                break;

        }
        cout << endl;
    } while (running);


    return 0;
}

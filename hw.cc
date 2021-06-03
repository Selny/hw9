#include <iostream>
#include <memory>

using namespace std;

int main() {

    //Shared pointerler
    shared_ptr<int> ptr(new int (200));
    shared_ptr<int> ptr_2;
    ptr_2 = ptr;

    cout << *ptr << endl;
    cout << *ptr_2 << endl;


    //Weak pointerin qurulma sintaksisi. Bir basa ozune adres goturmur. Shared pointerin adresini saxlayir.
    weak_ptr<int> w_ptr;
    w_ptr = ptr_2;

    //Weak pointerin reset edirm
    w_ptr.reset();

    //Yeni adres verilme

    shared_ptr<int> ptr_new(new int (250));
    w_ptr = ptr_new;

    //Lock-un islenmesi. Lock shared pointer deyer saxladiqda isleyir eks halda null qaytarir.
    if(w_ptr.lock()) cout << "code worked\n";
    else cout << "code didn't work\n";


    //Unique pointerler
    unique_ptr<int> u_ptr(new int(400));

    cout << *u_ptr << endl; 


    //Move edilme prosesi

    unique_ptr<int> u_ptr_2;
    u_ptr_2 = move(u_ptr);

    cout << u_ptr << endl;
    cout << *u_ptr_2 << endl; 

    return 0;
}
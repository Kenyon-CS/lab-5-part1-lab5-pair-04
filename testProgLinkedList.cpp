//This program tests various operation of a linked list
//34 62 21 90 66 53 88 24 10 -999

#include <iostream>                                 //Line 1
#include "unorderedLinkedList.h"                    //Line 2

using namespace std;                                //Line 3

int main()                                          //Line 4
{                                                   //Line 5
    unorderedLinkedList<int> list1, list2;          //Line 6
    int num;                                        //Line 7

    cout << "Line 8: Enter integers ending "
         << "with -999" << endl;                    //Line 8
    cin >> num;                                     //Line 9

    while (num != -999)                             //Line 10
    {                                               //Line 11
        list1.insertLast(num);                      //Line 12
        cin >> num;                                 //Line 13
    }                                               //Line 14

    cout << endl;                                   //Line 15

    cout << "Line 16: list1: ";                     //Line 16
    list1.print();                                  //Line 17
    cout << endl;                                   //Line 18
    cout << "Line 19: Length of list1: "
         << list1.length() << endl;                 //Line 19

    list2 = list1;	   //test the assignment operator Line 20

    cout << "Line 21: list2: ";                     //Line 21
    list2.print();                                  //Line 22
    cout << endl;                                   //Line 23
    cout << "Line 24: Length of list2: "
         << list2.length() << endl;                 //Line 24

    cout << "Line 25: Enter the number to be "
         << "deleted: ";                            //Line 25
    cin >> num;                                     //Line 26
    cout << endl;                                   //Line 27

    list2.deleteNode(num);                          //Line 28

    cout << "Line 29: After deleting " << num
         << " list2: " << endl;                     //Line 29
    list2.print();                                  //Line 30
    cout << endl;                                   //Line 31

    cout << "Line 32: Length of list2: "
         << list2.length() << endl;                 //Line 32

    cout << endl << "Line 33: Output list1 "
         << "using an iterator" << endl;            //Line 33

    linkedListIterator<int> it;                     //Line 34

    for (it = list1.begin(); it != list1.end();
                             ++it)                  //Line 35
        cout << *it << " ";                         //Line 36
    cout << endl;                                   //Line 37

    // ===== EXTRA TESTS (rotate, deleteSmallestFirstOccurrence, deleteAll, kthElement, deleteKth) =====
    auto printList = [](const char* label, unorderedLinkedList<int>& L){
        cout << label;
        for (auto it2 = L.begin(); it2 != L.end(); ++it2) cout << *it2 << " ";
        cout << endl;
    };

    cout << "\n--- EXTRA TESTS ---\n";

    
    unorderedLinkedList<int> L;
    L.insertLast(3); L.insertLast(4); L.insertLast(5); L.insertLast(20); L.insertLast(1);
    printList("Start L: ", L);

    
    L.rotate();
    printList("After rotate (expect 4 5 20 1 3): ", L);

    bool removedMin = L.deleteSmallestFirstOccurrence();
    cout << "deleteSmallestFirstOccurrence returned: " << (removedMin ? "true" : "false") << endl;
    printList("After deleteSmallestFirstOccurrence (expect 4 5 20 3): ", L);

    
    int removed5 = L.deleteAll(5);
    cout << "deleteAll(5) removed: " << removed5 << endl;
    printList("After deleteAll(5) (expect 4 20 3): ", L);

    
    cout << "kthElement(2) (expect 20): " << L.kthElement(2) << endl;

    
    L.deleteKth(3);
    printList("After deleteKth(3) (expect 4 20): ", L);

   
    unorderedLinkedList<int> E;    
    E.rotate();                    
    cout << "On empty: deleteSmallestFirstOccurrence -> "
         << (E.deleteSmallestFirstOccurrence() ? "true" : "false")
         << " (expect false)\n";
    cout << "On empty: deleteAll(42) removed -> " << E.deleteAll(42)
         << " (expect 0)\n";
    E.deleteKth(1);                
    cout << "Tried deleteKth(1) on empty list (expect message above)\n";


    return 0;                                       
}                                                   
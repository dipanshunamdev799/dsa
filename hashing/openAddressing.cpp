#include <iostream>
#include <list>
#include <vector>
using namespace std;
// struct LinearProbing
// {
//     // Linear Probing
//     vector<int> hashTable;
//     LinearProbing(int x)
//     {
//         hashTable = vector<int>(x, INT32_MAX);
//         // int32max marks the slot empty
//         // int32max -1 marks the slot deleted
//         printHashTable();
//     }
//     bool search(int x)
//     {
//         // element found : 1
//         int slot = x % hashTable.size();
//         int i = slot;
//         do
//         {
//             if (hashTable[i] == x)
//             {
//                 printHashTable(); return true;
//             }
//             if (hashTable[i] == INT32_MAX)
//             {
//                 printHashTable(); return false;
//             }
//             i++;
//             i = i % hashTable.size();
//         } while (slot != i);
//         printHashTable(); return false;
//     }
//     bool insert(int x)
//     {
//         // element inserted : 1
//         int slot = x % hashTable.size();
//         int i = slot;
//         do
//         {
//             if (hashTable[i] == INT32_MAX || hashTable[i] == INT32_MAX - 1)
//             {
//                 hashTable[i] = x;
//                 printHashTable(); return true;
//             }
//             i++;
//             i = i % hashTable.size();
//         } while (slot != i);
//         printHashTable(); return false;
//     }
//     bool del(int x)
//     {
//         // element deleted : 1
//         int slot = x % hashTable.size();
//         int i = slot;
//         do
//         {
//             if (hashTable[i] == x)
//             {
//                 hashTable[i] = INT32_MAX - 1;
//                 printHashTable(); return true;
//             }
//             if (hashTable[i] == INT32_MAX)
//             {
//                 printHashTable(); return false;
//             }
//             i++;
//             i = i % hashTable.size();
//         } while (slot != i);
//         printHashTable(); return false;
//     }
//     void printHashTable()
//     {
//         cout<<'\n';
//         cout<<"Hash Table: ";
//         for (auto x : hashTable)
//         {
//             cout << x << " ";
//         }
//         cout << "\n\n";
//     }
// };
struct LinearProbing
{
    // Linear Probing
    vector<int *> hashTable;
    int *dummy = new int; // dummy node to keep in check delete operation
    LinearProbing(int x)
    {
        hashTable = vector<int *>(x, nullptr);
        // nullptr : empty slot
        // dummy : deleted slot
        printHashTable();
    }
    bool search(int x)
    {
        // element found : 1
        int slot = x % hashTable.size();
        int i = slot;
        do
        {
            if (hashTable[i] == nullptr)
            {
                printHashTable();
                return false;
            }
            if (*hashTable[i] == x)
            {
                printHashTable();
                return true;
            }
            i++;
            i = i % hashTable.size();
        } while (slot != i);
        printHashTable();
        return false;
    }
    bool insert(int x)
    {
        // element inserted : 1
        int slot = x % hashTable.size();
        int i = slot;
        do
        {
            if (hashTable[i] == INT32_MAX || hashTable[i] == INT32_MAX - 1)
            {
                hashTable[i] = x;
                printHashTable();
                return true;
            }
            i++;
            i = i % hashTable.size();
        } while (slot != i);
        printHashTable();
        return false;
    }
    bool del(int x)
    {
        // element deleted : 1
        int slot = x % hashTable.size();
        int i = slot;
        do
        {
            if (hashTable[i] == x)
            {
                hashTable[i] = INT32_MAX - 1;
                printHashTable();
                return true;
            }
            if (hashTable[i] == INT32_MAX)
            {
                printHashTable();
                return false;
            }
            i++;
            i = i % hashTable.size();
        } while (slot != i);
        printHashTable();
        return false;
    }
    void printHashTable()
    {
        cout << '\n';
        cout << "Hash Table: ";
        for (auto x : hashTable)
        {
            if (x == nullptr || x == dummy)
            {
                cout << "_" << " ";
            }
            else
            {
                cout << *x << " ";
            }
        }
        cout << "\n\n";
    }
};
typedef struct LinearProbing LinearProbing;
int main(int argc, char const *argv[])
{
    LinearProbing linearprobing(7);
    linearprobing.insert(49);
    linearprobing.insert(50);
    linearprobing.insert(63);
    linearprobing.insert(64);
    linearprobing.insert(69);
    linearprobing.insert(68);

    cout << linearprobing.search(63) << "\n";
    linearprobing.del(63);
    cout << linearprobing.search(63) << "\n";

    return 0;
}

#include "BlockChain.h"

int main() {
    int n;
    cin >> n;
    cin.ignore();

    BlockChain bc;
    for (int i = 0; i < n; ++i) {
        string op;
        cin >> op;

        if (op == "A") {
            string id, data, type;
            cin >> id >> data >> type;
            bc.addBlock(id, data, type);
        } else if (op == "D") {
            string id;
            cin >> id;
            bc.deleteBlock(id);
        } else if (op == "P") {
            bc.print();
        } else if (op == "R") {
            bc.printReverse();
        } else if (op == "S") {
            string type;
            cin >> type;
            bc.sort(type);
        } else if (op == "F") {
            string id;
            cin >> id;
            bc.find(id);
        }
        cin.ignore();
    }

    return 0;
}

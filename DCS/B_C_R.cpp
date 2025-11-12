#include <iostream>
#include <vector>
using namespace std;

// ========== BERKELEY ==========
void berkeley() {
    vector<int> clocks = {100, 110, 95, 105};
    int sum = 0;
    for (int c : clocks) sum += c;
    int avg = sum / (int)clocks.size();

    cout << "\n--- Berkeley Algorithm ---\n";
    cout << "Average time = " << avg << "\n";

    for (size_t i = 0; i < clocks.size(); i++) {
        int offset = avg - clocks[i];
        clocks[i] += offset;
        cout << "Node " << i << " adjusted by " << offset << " => " << clocks[i] << "\n";
    }
}

// ========== BULLY ==========
void bully() {
    vector<int> nodes = {1, 2, 3, 4, 5};
    int failed = 5;   // node 5 is down
    int starter = 2;  // node 2 starts election

    cout << "\n--- Bully Algorithm ---\n";
    cout << "Node " << failed << " is down.\n";
    cout << "Node " << starter << " starts election...\n";

    int newLeader = starter;
    for (int n : nodes) {
        if (n > starter && n != failed) {
            cout << "Node " << n << " responds (higher).\n";
            if (n > newLeader) newLeader = n;
        }
    }
    cout << "New leader is Node " << newLeader << "\n";
}

// ========== RING ==========
void ring() {
    vector<int> nodes = {1, 2, 3, 4, 5};
    int failed = 5;   // node 5 is down
    int starter = 2;

    cout << "\n--- Ring Algorithm ---\n";
    cout << "Node " << failed << " is down.\n";
    cout << "Node " << starter << " starts ring election...\n";

    int max = starter;
    for (int n : nodes) {
        if (n != failed) {
            cout << "Node " << n << " passes token.\n";
            if (n > max) max = n;
        }
    }
    cout << "Leader elected: Node " << max << "\n";
}

// ========== MAIN ==========
int main() {
    cout << "Choose an algorithm:\n";
    cout << "1. Berkeley\n";
    cout << "2. Bully\n";
    cout << "3. Ring\n";
    cout << "Enter choice: ";

    int ch;
    cin >> ch;

//       switch (ch) {
//     case 1:
//         berkeley();
//         break;

//     case 2:
//         bully();
//         break;

//     case 3:
//         ring();
//         break;

//     default:
//         cout << "Invalid choice.\n";
//         break;
// }


    if (ch == 1) berkeley();
    else if (ch == 2) bully();
    else if (ch == 3) ring();
    else cout << "Invalid choice.\n";

    return 0;
}

  

// g++ B_C_R.cpp -o B_C_R
// ./B_C_R
// or  B_C_R.exe
#include <iostream>
#include <stack>
using namespace std;

class TowerOfHanoi {
private:
    stack<int> source;
    stack<int> auxiliary;
    stack<int> destination;
    int n;

public:
    TowerOfHanoi(int numDisks) {
        n = numDisks;
        // Initialize source stack
        for (int i = n; i > 0; i--) {
            source.push(i);
        }
    }

    void displayStacks() {
        cout << "Source: ";
        displayStack(source);
        cout << "Auxiliary: ";
        displayStack(auxiliary);
        cout << "Destination: ";
        displayStack(destination);
    }

    void displayStack(stack<int> s) {
        stack<int> temp = s;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }

    void moveDisk(stack<int>& from, stack<int>& to, char fromRod, char toRod) {
        int disk = from.top();
        from.pop();
        to.push(disk);
        cout << "Move disk " << disk << " from rod " << fromRod << " to rod " << toRod << endl;
    }

    void solve() {
        cout << "Initial State:" << endl;
        displayStacks();

        towerOfHanoi(n, source, auxiliary, destination, 'A', 'B', 'C');

        cout << "Final State:" << endl;
        displayStacks();
    }

    void towerOfHanoi(int n, stack<int>& source, stack<int>& auxiliary, stack<int>& destination, char sourceRod, char auxiliaryRod, char destinationRod) {
        if (n == 1) {
            moveDisk(source, destination, sourceRod, destinationRod);
            return;
        }

        towerOfHanoi(n - 1, source, destination, auxiliary, sourceRod, destinationRod, auxiliaryRod);
        moveDisk(source, destination, sourceRod, destinationRod);
        towerOfHanoi(n - 1, auxiliary, source, destination, auxiliaryRod, sourceRod, destinationRod);
    }
};

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    TowerOfHanoi tower(n);
    tower.solve();

    return 0;
}
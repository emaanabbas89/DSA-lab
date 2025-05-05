#include <iostream>
#include <string>
#include <stack>

using namespace std;

class TextEditor {
private:
    string text;
    stack<char> undoStack;
    stack<char> redoStack;

public:
    void addText(const string& newText) {
        for (char c : newText) {
            undoStack.push(c);
        }
        text += newText;
        redoStack = stack<char>(); // Clear redo stack
    }

    void undo() {
        if (!text.empty()) {
            redoStack.push(text.back());
            undoStack.pop(); // Remove the last character from undo stack
            text.pop_back();
        }
        else {
            cout << "Nothing to undo." << endl;
        }
    }

    void redo() {
        if (!redoStack.empty()) {
            text += redoStack.top();
            undoStack.push(redoStack.top());
            redoStack.pop();
        }
        else {
            cout << "Nothing to redo." << endl;
        }
    }

    void deleteText() {
        if (!text.empty()) {
            redoStack = stack<char>(); // Clear redo stack
            undoStack.push(text.back());
            text.pop_back();
        }
        else {
            cout << "Text is empty." << endl;
        }
    }

    void displayText() const {
        cout << text << endl;
    }
};

int main() {
    TextEditor editor;
    int choice;
    string newText;

    while (true) {
        cout << "Text Editor Menu:" << endl;
        cout << "1. Add text" << endl;
        cout << "2. Undo" << endl;
        cout << "3. Redo" << endl;
        cout << "4. Delete character" << endl;
        cout << "5. Display text" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter text to add: ";
            cin.ignore(); // Ignore newline character
            getline(cin, newText);
            editor.addText(newText);
            break;
        case 2:
            editor.undo();
            break;
        case 3:
            editor.redo();
            break;
        case 4:
            editor.deleteText();
            break;
        case 5:
            editor.displayText();
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

